#加上总和的主成分分析结果
import pandas as pd
import numpy as np
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

# 获取主成分的贡献度
explained_variance = pca.explained_variance_ratio_

# 设置NumPy打印选项
np.set_printoptions(suppress=True, precision=6)

# 输出主成分的贡献度
print(explained_variance)
