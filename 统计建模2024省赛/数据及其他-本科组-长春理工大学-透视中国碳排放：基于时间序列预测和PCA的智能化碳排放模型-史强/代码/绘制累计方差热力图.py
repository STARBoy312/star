#绘制pca图像
import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
from sklearn.decomposition import PCA
from sklearn.preprocessing import StandardScaler

# 从CSV文件中读取数据
df = pd.read_csv('D:\Col2_code\Python\加上总和进行主成分分析.csv')

# 填充缺失值
df.fillna(0, inplace=True)

# 数据预处理：将非数值型数据转换为数值型数据
df = df.apply(pd.to_numeric, errors='coerce')

# 填充转换后可能产生的缺失值
df.fillna(0, inplace=True)

# 标准化数据
scaler = StandardScaler()
scaled_data = scaler.fit_transform(df.iloc[:, 1:])

# 应用PCA
pca = PCA()
pca.fit(scaled_data)

# 计算累积方差贡献率
cumulative_variance_ratio = np.cumsum(pca.explained_variance_ratio_)

# 绘制累积方差贡献率随主成分数量变化的折线图
plt.figure(figsize=(10, 6))
plt.plot(range(1, len(cumulative_variance_ratio) + 1), cumulative_variance_ratio, marker='o', linestyle='-')
plt.xlabel('Number of Principal Components')
plt.ylabel('Cumulative Variance Explained')
plt.title('Cumulative Variance Explained by Principal Components')
plt.grid(True)
plt.show()
