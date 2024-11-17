import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
from matplotlib import rcParams
rcParams['font.sans-serif'] = ['SimHei']
rcParams['axes.unicode_minus'] = False
def monte_carlo_simulation(k, n, num_simulations=10000):
    samples = np.random.binomial(n, k/n, size=num_simulations) / n
    return samples.mean(), samples.std(), samples
def confidence_interval(samples, confidence_level=0.95):
    lower_bound = np.percentile(samples, (1 - confidence_level) / 2 * 100)
    upper_bound = np.percentile(samples, (1 + confidence_level) / 2 * 100)
    return lower_bound, upper_bound
components = {
    '零配件1': {'次品率': 0.1, '购买单价': 2, '检测成本': 1},
    '零配件2': {'次品率': 0.1, '购买单价': 8, '检测成本': 1},
    '零配件3': {'次品率': 0.1, '购买单价': 12, '检测成本': 2},
    '零配件4': {'次品率': 0.1, '购买单价': 2, '检测成本': 1},
    '零配件5': {'次品率': 0.1, '购买单价': 8, '检测成本': 1},
    '零配件6': {'次品率': 0.1, '购买单价': 12, '检测成本': 2},
    '零配件7': {'次品率': 0.1, '购买单价': 8, '检测成本': 1},
    '零配件8': {'次品率': 0.1, '购买单价': 12, '检测成本': 2},
}
semi_products = {
    '半成品1': {'次品率': 0.1, '装配成本': 8, '检测成本': 4, '拆解费用': 6},
    '半成品2': {'次品率': 0.1, '装配成本': 8, '检测成本': 4, '拆解费用': 6},
    '半成品3': {'次品率': 0.1, '装配成本': 8, '检测成本': 4, '拆解费用': 6},
}
final_product = {
    '成品': {'次品率': 0.1, '装配成本': 8, '检测成本': 6, '拆解费用': 10, '售价': 200, '调换损失': 40}
}
sampling_data = {
    '零配件1': {'k': 5, 'n': 50},
    '零配件2': {'k': 10, 'n': 50},
    '零配件3': {'k': 8, 'n': 50},
    '零配件4': {'k': 3, 'n': 50},
    '零配件5': {'k': 7, 'n': 50},
    '零配件6': {'k': 2, 'n': 50},
    '零配件7': {'k': 6, 'n': 50},
    '零配件8': {'k': 4, 'n': 50},
    '半成品1': {'k': 6, 'n': 50},
    '半成品2': {'k': 9, 'n': 50},
    '半成品3': {'k': 5, 'n': 50},
    '成品': {'k': 7, 'n': 50},
}
updated_results = []
num_simulations = 10000
for item_name, data in {**components, **semi_products, '成品': final_product}.items():
    k = sampling_data[item_name]['k']
    n = sampling_data[item_name]['n']
    mean_defect_rate, std_defect_rate, samples = monte_carlo_simulation(k, n, num_simulations)
    lower_bound, upper_bound = confidence_interval(samples)
    updated_results.append({
        '项目': item_name,
        '实际次品率': k / n,
        '蒙特卡洛模拟次品率均值': mean_defect_rate,
        '蒙特卡洛模拟次品率标准差': std_defect_rate,
        '95% 置信区间下限': lower_bound,
        '95% 置信区间上限': upper_bound,
        '是否在置信区间内': lower_bound <= k / n <= upper_bound
    })
df = pd.DataFrame(updated_results)
print(df)
df.to_excel('蒙特卡洛模拟次品率和置信区间结果.xlsx', index=False)
plt.figure(figsize=(12, 8))
plt.barh(df['项目'], df['蒙特卡洛模拟次品率均值'], xerr=[df['蒙特卡洛模拟次品率均值'] - df['95% 置信区间下限'],
                   df['95% 置信区间上限'] - df['蒙特卡洛模拟次品率均值']], capsize=5, label='置信区间', alpha=0.6, color='lightblue')
plt.scatter(df['实际次品率'], df['项目'], color='r', label='实际次品率', zorder=5)
plt.title("各项目次品率与置信区间对比", fontsize=16)
plt.xlabel('估计次品率', fontsize=14)
plt.ylabel('项目', fontsize=14)
plt.xticks(fontsize=12)
plt.yticks(fontsize=12)
plt.legend()
plt.tight_layout()
plt.show()