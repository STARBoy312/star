import pandas as pd
import statsmodels.tsa.stattools as ts  #adf检验
from matplotlib import pyplot as plt
from sklearn.metrics import mean_squared_error, mean_absolute_error, median_absolute_error
from statsmodels.graphics.tsaplots import plot_acf,plot_pacf #ACF与PACF
from statsmodels.tsa.arima.model import ARIMA #ARIMA模型
import statsmodels.api as sm
from statsmodels.graphics.api import qqplot  #qq图
import numpy as np
from sklearn.svm import SVR
from sklearn.model_selection import train_test_split

df=pd.read_csv("C:/Users/Administrator/Desktop/无标题4.csv",encoding='gbk')
print(df["全国碳排放量"])

# 创建一个DatetimeIndex对象，指定时间范围为2021年1月1日到1月5日
dates = pd.date_range(start='2000-01-01', end='2019-12-31', freq='AS')
print(dates)
# # 创建一个Series对象，将列表作为数据，DatetimeIndex对象作为索引
t_s = pd.Series(data=df["全国碳排放量"].tolist(), index=dates)
t_s.index = t_s.index.strftime('%Y')
# print(t_s.index)
plt.rcParams['font.sans-serif'] = ['Microsoft YaHei']
plt.figure(figsize=(13,7))
plt.plot(t_s.index, t_s)
tick_positions = t_s.index[::2]
plt.xticks(tick_positions,rotation=45)
plt.xlabel("year")
plt.ylabel("emission")
plt.title("全国碳排放趋势分析")
plt.show()

# 进行ADF检验
result = ts.adfuller(df['全国碳排放量'])
# 输出ADF结果
print('-------------------------------------------')
print('ADF检验结果：')
print('ADF Statistic: %f' % result[0])
print('p-value: %f' % result[1])
print('Lags Used: %d' % result[2])
print('Observations Used: %d' % result[3])
print('Critical Values:')
for key, value in result[4].items():
    print('\t%s: %.3f' % (key, value))

##### 差分运算
def diff(timeseries):
    new_df=timeseries.diff(periods=1).dropna()#dropna删除NaN
    # sec_df=new_df.diff(periods=1).dropna()
    new_df.plot(color='orange',title='差分运算')
    plt.show()
    return new_df

#进行一阶差分
ndf=diff(df['全国碳排放量'])

#再次进行ADF检验
result2 = ts.adfuller(ndf)
# 输出ADF结果
print('-------------------------------------------')
print('差分后序列的ADF检验结果:')
print('ADF Statistic: %f' % result2[0])
print('p-value: %f' % result2[1])
print('Lags Used: %d' % result2[2])
print('Observations Used: %d' % result2[3])
print('Critical Values:')
for key, value in result2[4].items():
    print('\t%s: %.3f' % (key, value))

#模型选择：绘制ACF与PACF,即自相关图和偏自相关图
#### 绘制ACF与PACF的图像
def plot_acf_pacf(timeseries): #利用ACF和PACF判断模型阶数
    plot_acf(timeseries,lags=timeseries.shape[0]%2) #延迟数
    plot_pacf(timeseries,lags=timeseries.shape[0]%2)
    plt.show()
plot_acf_pacf(ndf)

#迭代调优
print('-------------------------------------------')
#AIC
timeseries=ndf
AIC=sm.tsa.stattools.arma_order_select_ic(timeseries,max_ar=4,max_ma=4,ic='aic')['aic_min_order']
#BIC
BIC=sm.tsa.stattools.arma_order_select_ic(timeseries,max_ar=4,max_ma=4,ic='bic')['bic_min_order']
print('the AIC is{}\nthe BIC is{}\n'.format(AIC,BIC))

#模型构建
print('-------------------------------------------')
model= ARIMA(ndf, order=(0,1,1)).fit()
print(model.params)
print(model.summary())

#残差图
model.resid.plot(figsize=(10,3))
plt.title("残差图")
plt.show()

#QQ图看正态性
qqplot(model.resid, line="q", fit=True)
plt.show()

#模型预测
print('-------------------------------------------')
predict= model.predict(1,19)#dynamic=True)
# print('模型预测:','\n',predict)
#反向差分运算
# 对差分后的时间序列进行逆差分运算,两个参数：差分数据序列和原始数据序列
def inverse_diff(diff_series, original_series):
    inverted = []
    prev = original_series.iloc[0]
    for val in diff_series:
        current = val + prev
        inverted.append(current)
        prev = current
    return pd.Series(inverted, index=original_series.index[1:])
n_predict=inverse_diff(predict,t_s)
print('模型预测:','\n',n_predict)


# #画图
plt.figure(figsize=(10,4))
plt.plot(t_s.index,t_s,label='actual', linestyle='-',marker='*')
plt.plot(predict.index,n_predict,label='predict')

plt.xticks(t_s.index,rotation=45)
plt.legend(['actual','arima'])
plt.xlabel('time(year)')
plt.ylabel('emission')
plt.show()

print('-------------------------------------------')
# 进行三步预测，并输出95%置信区间
steps=11   #未来三期预测
forecast= model.get_forecast(steps=steps)
table=pd.DataFrame(forecast.summary_frame())
# print(table.iloc[1])
table.iloc[0]=table.iloc[0]+t_s[-1]
# print(table.iloc[0, 0])
for i in range(steps-1):
    table.iloc[i+1]=table.iloc[i+1]+table.iloc[i, 0]
print(table)


