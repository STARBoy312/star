import matplotlib.pyplot as plt
import pandas as pd
import numpy as np

# 箱型图判断异常点
def box_outlier(data):
    df = data.copy(deep=True)
    out_index = []
    for col in df.columns:  # 对每一列分别用箱型图进行判断
        Q1 = df[col].quantile(q=0.25)  # 下四分位
        Q3 = df[col].quantile(q=0.75)  # 上四分位
        low_whisker = Q1 - 1.5 * (Q3 - Q1)  # 下边缘
        up_whisker = Q3 + 1.5 * (Q3 - Q1)  # 上边缘

        # 寻找异常点,获得异常点索引值，删除索引值所在行数据
        rule = (df[col] > up_whisker) | (df[col] < low_whisker)
        out = df[col].index[rule]
        out_index += out.tolist()

    df.drop(out_index, inplace=True)
    return df

def getFc(data,first_column):
    df = data.copy(deep=True)
    fc = first_column.copy(deep=True)
    out_index = []
    for col in df.columns:  # 对每一列分别用箱型图进行判断
        Q1 = df[col].quantile(q=0.25)  # 下四分位
        Q3 = df[col].quantile(q=0.75)  # 上四分位
        low_whisker = Q1 - 1.5 * (Q3 - Q1)  # 下边缘
        up_whisker = Q3 + 1.5 * (Q3 - Q1)  # 上边缘

        # 寻找异常点,获得异常点索引值，删除索引值所在行数据
        rule = (df[col] > up_whisker) | (df[col] < low_whisker)
        out = df[col].index[rule]
        out_index += out.tolist()

    df.drop(out_index, inplace=True)
    fc.drop(out_index, inplace=True)
    return fc

# 读取数据
data = pd.read_csv("C:/Users/13508/Desktop/无标题.csv").dropna(axis=0)  # 确保删除 NaN 是适当的
numeric_cols = data.iloc[:, 1:].select_dtypes(include=[np.number]).columns
numeric_data = data[numeric_cols]
first_column = data.iloc[:, 0]
# 去除异常值
cleaned_data = box_outlier(numeric_data)
new_first_column = getFc(numeric_data,first_column)
new_data = pd.concat([new_first_column, cleaned_data], axis=1)
new_data.to_csv("C:/Users/13508/Desktop/cleaned_data.csv", index=False,encoding='gbk')
# 绘制箱线图
plt.figure(figsize=(11, 7))
numeric_data.boxplot()
plt.rcParams['font.sans-serif'] = ['Microsoft YaHei']
plt.title('异常值处理前箱型图')
plt.xlabel('Feature')
plt.ylabel('Values')
plt.xticks(rotation=45)
plt.show()

plt.figure(figsize=(11, 7))
cleaned_data.boxplot()
plt.title('异常值处理后箱型图')
plt.xlabel('Feature')
plt.ylabel('Values')
plt.xticks(rotation=45)
plt.show()