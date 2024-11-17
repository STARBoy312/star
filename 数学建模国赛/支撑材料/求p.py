import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
from matplotlib import rcParams
rcParams['font.sans-serif'] = ['SimHei']
rcParams['axes.unicode_minus'] = False
def monte_carlo_simulation(k, n, num_simulations=10000):
    samples = np.random.binomial(n, k / n, size=num_simulations) / n
    return samples.mean(), samples.std(), samples
def confidence_interval(samples, confidence_level=0.95):
    lower_bound = np.percentile(samples, (1 - confidence_level) / 2 * 100)
    upper_bound = np.percentile(samples, (1 + confidence_level) / 2 * 100)
    return lower_bound, upper_bound
scenarios = {
    '情况1': {'零配件1': {'次品率': 0.1, '购买单价': 4, '检测成本': 2},
              '零配件2': {'次品率': 0.1, '购买单价': 18, '检测成本': 3},
              '成品': {'次品率': 0.1, '装配成本': 6, '检测成本': 3}},
    '情况2': {'零配件1': {'次品率': 0.2, '购买单价': 4, '检测成本': 2},
              '零配件2': {'次品率': 0.2, '购买单价': 18, '检测成本': 3},
              '成品': {'次品率': 0.2, '装配成本': 6, '检测成本': 3}},
    '情况3': {'零配件1': {'次品率': 0.1, '购买单价': 4, '检测成本': 2},
              '零配件2': {'次品率': 0.1, '购买单价': 18, '检测成本': 3},
              '成品': {'次品率': 0.1, '装配成本': 6, '检测成本': 3}},
    '情况4': {'零配件1': {'次品率': 0.2, '购买单价': 4, '检测成本': 1},
              '零配件2': {'次品率': 0.2, '购买单价': 18, '检测成本': 1},
              '成品': {'次品率': 0.2, '装配成本': 6, '检测成本': 2}},
    '情况5': {'零配件1': {'次品率': 0.1, '购买单价': 4, '检测成本': 8},
              '零配件2': {'次品率': 0.2, '购买单价': 18, '检测成本': 1},
              '成品': {'次品率': 0.1, '装配成本': 6, '检测成本': 2}},
    '情况6': {'零配件1': {'次品率': 0.05, '购买单价': 4, '检测成本': 2},
              '零配件2': {'次品率': 0.05, '购买单价': 18, '检测成本': 3},
              '成品': {'次品率': 0.05, '装配成本': 6, '检测成本': 3}},
}
n = 50
num_simulations = 10000
updated_results = []
def adjust_k_for_scenario(scenario_data, n):
    k1 = int(scenario_data['零配件1']['次品率'] * n)
    k2 = int(scenario_data['零配件2']['次品率'] * n)
    k_prod = int(scenario_data['成品']['次品率'] * n)
    return {'零配件1': {'k': k1, 'n': n}, '零配件2': {'k': k2, 'n': n}, '成品': {'k': k_prod, 'n': n}}
for scenario_name, scenario_data in scenarios.items():
    sampling_data_adjusted = adjust_k_for_scenario(scenario_data, n)
    result = {'情况': scenario_name}
    k1 = sampling_data_adjusted['零配件1']['k']
    n1 = sampling_data_adjusted['零配件1']['n']
    mean_defect_rate1, std_defect_rate1, samples1 = monte_carlo_simulation(k1, n1, num_simulations)
    lower_bound1, upper_bound1 = confidence_interval(samples1)
    result['零配件1_模拟次品率'] = mean_defect_rate1
    result['零配件1_置信区间下限'] = lower_bound1
    result['零配件1_置信区间上限'] = upper_bound1
    k2 = sampling_data_adjusted['零配件2']['k']
    n2 = sampling_data_adjusted['零配件2']['n']
    mean_defect_rate2, std_defect_rate2, samples2 = monte_carlo_simulation(k2, n2, num_simulations)
    lower_bound2, upper_bound2 = confidence_interval(samples2)
    result['零配件2_模拟次品率'] = mean_defect_rate2
    result['零配件2_置信区间下限'] = lower_bound2
    result['零配件2_置信区间上限'] = upper_bound2
    k_prod = sampling_data_adjusted['成品']['k']
    n_prod = sampling_data_adjusted['成品']['n']
    mean_defect_rate_prod, std_defect_rate_prod, samples_prod = monte_carlo_simulation(k_prod, n_prod, num_simulations)
    lower_bound_prod, upper_bound_prod = confidence_interval(samples_prod)
    result['成品_模拟次品率'] = mean_defect_rate_prod
    result['成品_置信区间下限'] = lower_bound_prod
    result['成品_置信区间上限'] = upper_bound_prod

    updated_results.append(result)
df = pd.DataFrame(updated_results)
pd.set_option('display.max_rows', None)
pd.set_option('display.max_columns', None)
pd.set_option('display.max_colwidth', None)
print(df)

fig, ax = plt.subplots(figsize=(10, 6))

colors = ['#add8e6', '#90ee90', '#ffb6c1']  
components = ['零配件1', '零配件2', '成品']  

for i, (scenario_name, scenario_data) in enumerate(df.iterrows()):
    scenario_results = scenario_data.to_dict()
    scenario_y_pos = i
    for j, component in enumerate(components):
        mean_defect_rate = scenario_results[f'{component}_模拟次品率']
        lower_bound = scenario_results[f'{component}_置信区间下限']
        upper_bound = scenario_results[f'{component}_置信区间上限']
        ax.barh(scenario_y_pos - j * 0.3, mean_defect_rate, color=colors[j], height=0.2, label=component if i == 0 else "")
        ax.errorbar(mean_defect_rate, scenario_y_pos - j * 0.3,
                    xerr=[[mean_defect_rate - lower_bound], [upper_bound - mean_defect_rate]],
                    fmt='o', color='black', capsize=5)
        ax.scatter(mean_defect_rate, scenario_y_pos - j * 0.3, color='red', zorder=5)
ax.set_yticks(range(len(df)))
ax.set_yticklabels(df['情况'], rotation='vertical')
plt.xlabel('模拟次品率')
plt.ylabel('情况')
plt.legend()
plt.tight_layout()
plt.show()