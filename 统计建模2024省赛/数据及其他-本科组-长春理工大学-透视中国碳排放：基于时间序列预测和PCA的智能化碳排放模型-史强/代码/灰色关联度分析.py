#灰色关联度分析
import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
import seaborn as sns


wine  = pd.read_csv("D:\Col2_code\Python\灰色关联度分析.csv",index_col=0)
# print(wine)

#无量纲化
def dimensionlessProcessing(df_values,df_columns):
    from sklearn.preprocessing import StandardScaler
    scaler = StandardScaler()
    res = scaler.fit_transform(df_values)
    return pd.DataFrame(res,columns=df_columns)


# 求第一列(影响因素)和其它所有列(影响因素)的灰色关联值
def GRA_ONE(data, m=0):  # m为参考列
    # 标准化
    data = dimensionlessProcessing(data.values, data.columns)
    # 参考数列
    std = data.iloc[:, m]
    # 比较数列
    ce = data.copy()

    n = ce.shape[0]
    m = ce.shape[1]

    # 与参考数列比较，相减
    grap = np.zeros([n, m])
    for i in range(m):
        for j in range(n):
            grap[j, i] = abs(ce.iloc[j, i] - std[j])

    # 取出矩阵中的最大值和最小值
    mmax = np.amax(grap)
    mmin = np.amin(grap)
    ρ = 0.5  # 灰色分辨系数

    # 计算值
    grap = pd.DataFrame(grap).apply(lambda x: (mmin + ρ * mmax) / (x + ρ * mmax))


    # 求均值，得到灰色关联值
    RT = grap.mean(axis=0)
    return pd.Series(RT)


# 调用GRA_ONE，求得所有因素之间的灰色关联值
def GRA(data):
    list_columns = np.arange(data.shape[1])
    df_local = pd.DataFrame(columns=list_columns)
    for i in np.arange(data.shape[1]):
        df_local.iloc[:, i] = GRA_ONE(data, m=i)
    return df_local


data_gra = GRA(wine)
data_gra.to_csv('new_data.csv',index=False)
print(data_gra)


def ShowGRAHeatMap(data):
    # 色彩集
    colormap = plt.cm.RdBu
    plt.figure(figsize=(18, 16))
    plt.title('Person Correlation of Features', y=1.05, size=18)
    sns.heatmap(data.astype(float), linewidths=0.1, vmax=1.0, square=True, \
                cmap=colormap, linecolor='white', annot=True)
    plt.show()


ShowGRAHeatMap(data_gra)