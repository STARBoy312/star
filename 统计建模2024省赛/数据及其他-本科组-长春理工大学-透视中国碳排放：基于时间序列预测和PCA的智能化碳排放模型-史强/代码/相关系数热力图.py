# 热力图分析
import matplotlib.pyplot as plt
import seaborn as sns
import pandas as pd

# 设置中文字体
plt.rcParams['font.sans-serif'] = ['SimHei']  # 指定使用的字体，这里使用了中文字体“黑体”
plt.rcParams['axes.unicode_minus'] = False  # 解决负号显示为方块的问题

# 从CSV文件中读取数据
df = pd.read_csv('D:\Col2_code\Python\热力图分析.csv')

# 计算相关系数矩阵
corr_matrix = df.corr()

# 创建热图
plt.figure(figsize=(12, 10))  # 设置更大的尺寸
sns.heatmap(corr_matrix, annot=True, fmt=".2f", cmap='Oranges', cbar=True)  # 使用橙色映射

# 设置图表标题和坐标轴标签
plt.title('相关系数矩阵热图')
plt.xlabel('变量')
plt.ylabel('变量')

# 图像的保存与展示
plt.show()