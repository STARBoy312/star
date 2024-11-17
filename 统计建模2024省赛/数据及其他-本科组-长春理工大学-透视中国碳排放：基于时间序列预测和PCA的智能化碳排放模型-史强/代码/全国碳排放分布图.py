import pandas as pd
import geopandas as gpd

import numpy as np
import matplotlib.pyplot as plt

# 指定中文字体路径
plt.rcParams['font.sans-serif'] = ['SimHei']  # 指定中文字体为黑体
plt.rcParams['axes.unicode_minus'] = False    # 解决负号显示问题

# 然后绘制图像
# 读取地理数据
gdf = gpd.read_file("C:\\Users\\13508\\Desktop\\中华人民共和国", encoding='utf-8')
sales_data = pd.read_excel("C:\\Users\\13508\\Desktop\\新建 XLSX 工作表.xlsx")
ind = sales_data['name']
sales_data = sales_data.drop(columns='name')
gdf.to_excel("C:\\Users\\13508\\Desktop\\工作簿2.xlsx")
df = pd.DataFrame()
df['name'] = ind.values
df['value'] = np.floor(sales_data.sum(axis=1).values)

# 合并销量数据到地理数据中
merged_data = gdf.merge(df, how='left', left_on='name', right_on='name')

# 绘制地图
fig, ax = plt.subplots(figsize=(12, 10))
ax.set_title('全国排放量分布图', fontproperties='SimHei')

# 更改地图背景颜色
ax.set_facecolor('lightblue')

merged_data.plot(column='value', cmap='YlGnBu', linewidth=0.8, ax=ax, edgecolor='0.8', legend=True,
                  legend_kwds={'label': '排放量', 'orientation': "vertical", 'shrink': 0.6})

# 在地图上添加省份碳排放量标签
for idx, row in merged_data.iterrows():
    plt.annotate(text=row['value'], xy=(row['geometry'].centroid.x, row['geometry'].centroid.y),
                 horizontalalignment='center', fontproperties='SimHei')

ax.set_axis_off()
plt.show()
