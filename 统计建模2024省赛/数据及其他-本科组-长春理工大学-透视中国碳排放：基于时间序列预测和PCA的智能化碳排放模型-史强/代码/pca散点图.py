#pca散点图
import numpy as np
import pandas as pd
from sklearn.decomposition import PCA
from sklearn.preprocessing import StandardScaler
import matplotlib.pyplot as plt

# 加载数据集
data = pd.read_csv('D:\\Col2_code\\Python\\最新的数据.csv')

# 将空字符串替换为NaN
data = data.replace(' ', np.nan)

# 填充NaN值为0
data = data.fillna(0)

# 提取年份列和最后一行数据作为计算因子
years = data['Emission_Inventory']
data_factors = data.iloc[-1:, 1:].T

# 标准化数据
scaler = StandardScaler()
data_factors_scaled = scaler.fit_transform(data_factors)

# 将年份列与因子列合并
data_scaled = pd.concat([pd.DataFrame(years), pd.DataFrame(data_factors_scaled, columns=data_factors.columns)], axis=1)

# 转换特征名为字符串类型
data_scaled.columns = data_scaled.columns.astype(str)

# 实例化PCA对象
pca = PCA()

# 对数据进行主成分分析
data_pca = pca.fit_transform(data_scaled)

# 创建二维散点图
plt.figure(figsize=(8, 6))
plt.scatter(data_pca[:, 0], data_pca[:, 1])
plt.xlabel('Principal Component 1')
plt.ylabel('Principal Component 2')
plt.title('PCA Scatter Plot')
plt.show()