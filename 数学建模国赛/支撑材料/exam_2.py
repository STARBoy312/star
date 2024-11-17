import itertools
import matplotlib.pyplot as plt
import numpy as np
import pandas as pd

plt.rcParams['font.sans-serif'] = ['Microsoft YaHei']

cases = [
    {'零配件1次品率': 0.1, '零配件2次品率': 0.100066, '成品次品率': 0.100060, '零配件1检测成本': 2,
     '零配件2检测成本': 3,
     '成品检测成本': 3, '装配成本': 6, '市场售价': 56, '调换损失': 6, '拆解费用': 5},
    {'零配件1次品率': 0.199834, '零配件2次品率': 0.200360, '成品次品率': 0.198670, '零配件1检测成本': 2,
     '零配件2检测成本': 3,
     '成品检测成本': 3, '装配成本': 6, '市场售价': 56, '调换损失': 6, '拆解费用': 5},
    {'零配件1次品率': 0.100140, '零配件2次品率': 0.099458, '成品次品率': 0.101166, '零配件1检测成本': 2,
     '零配件2检测成本': 3,
     '成品检测成本': 3, '装配成本': 6, '市场售价': 56, '调换损失': 30, '拆解费用': 5},
    {'零配件1次品率': 0.199388, '零配件2次品率': 0.199458, '成品次品率': 0.198960, '零配件1检测成本': 1,
     '零配件2检测成本': 1,
     '成品检测成本': 2, '装配成本': 6, '市场售价': 56, '调换损失': 30, '拆解费用': 5},
    {'零配件1次品率': 0.100252, '零配件2次品率': 0.199966, '成品次品率': 0.100342, '零配件1检测成本': 8,
     '零配件2检测成本': 1,
     '成品检测成本': 2, '装配成本': 6, '市场售价': 56, '调换损失': 10, '拆解费用': 5},
    {'零配件1次品率': 0.039728, '零配件2次品率': 0.040098, '成品次品率': 0.039766, '零配件1检测成本': 2,
     '零配件2检测成本': 3,
     '成品检测成本': 3, '装配成本': 6, '市场售价': 56, '调换损失': 10, '拆解费用': 40}
]


def calc_total_cost(case, detect_parts1=True, detect_parts2=True, detect_final=True, dismantle=True):
    n_parts1 = 100
    n_parts2 = 100
    cost_parts1 = n_parts1 * case['零配件1检测成本'] if detect_parts1 else 0
    cost_parts2 = n_parts2 * case['零配件2检测成本'] if detect_parts2 else 0
    loss_parts1 = (n_parts1 * case['零配件1次品率']) * (case['装配成本']) if not detect_parts1 else 0
    loss_parts2 = (n_parts2 * case['零配件2次品率']) * (case['装配成本']) if not detect_parts2 else 0
    n_final_products = 100
    cost_final = n_final_products * case['成品检测成本'] if detect_final else 0
    loss_final = (n_final_products * case['成品次品率']) * case['调换损失'] if not detect_final else 0
    dismantle_cost = n_final_products * case['拆解费用'] if dismantle else 0
    dismantle_revenue = (n_final_products * case['成品次品率']) * case['市场售价'] if dismantle else 0
    total_cost = (cost_parts1 + cost_parts2 + loss_parts1 + loss_parts2 +
                  cost_final + loss_final + dismantle_cost - dismantle_revenue)
    return total_cost
strategies = list(itertools.product([False, True], repeat=4))
strategy_labels = [
    "检测零配件1", "检测零配件2", "检测成品", "拆解不合格成品"
]


def strategy_identifier(strategy):
    return f"({int(strategy[0])}, {int(strategy[1])}, {int(strategy[2])}, {int(strategy[3])})"
all_cases_results = []
for case_index, case in enumerate(cases):
    print(f"案例 {case_index + 1} 的结果:")
    costs = [calc_total_cost(case, *strategy) for strategy in strategies]
    profits = [case['市场售价'] * 100 - cost for cost in costs]
    min_cost = min(costs)
    optimal_strategy = strategies[costs.index(min_cost)]
    all_cases_results.append({
        'case_index': case_index + 1,
        'strategies': strategies,
        'costs': costs,
        'profits': profits,
        'min_cost': min_cost,
        'optimal_strategy': optimal_strategy
    })
    for strategy_index, (strategy, cost, profit) in enumerate(zip(strategies, costs, profits), start=1):
        strategy_desc = ", ".join([f"{strategy_labels[i]}: {'是' if strategy[i] else '否'}" for i in range(4)])
        print(f"策略 {strategy_index}: {strategy_desc}, 总成本: {cost:.2f}, 利润: {profit:.2f}")
    print(f"\n最优策略: {optimal_strategy}, 最小总成本: {min_cost:.2f}, 最大利润: {max(profits):.2f}\n")
fig = plt.figure(figsize=(12, 8))
ax = fig.add_subplot(111, projection='3d')
x = np.arange(1, 17)  
y = np.arange(len(cases))
X, Y = np.meshgrid(x, y)
Z = np.array([case_result['profits'] for case_result in all_cases_results])
Z = np.array(Z).reshape((len(cases), len(strategies)))
ax.plot_surface(X, Y, Z, cmap='viridis', edgecolor='none')
ax.set_xlabel('策略编号')
ax.set_ylabel('案例编号')
ax.set_zlabel('利润')
ax.set_yticks(range(len(cases)))
ax.set_yticklabels([f'案例 {i+1}' for i in range(len(cases))])
plt.title('策略利润的3D图')
plt.show()
strategy_names = [strategy_identifier(strategy) for strategy in strategies]
df_all_cases = pd.DataFrame()
for case_result in all_cases_results:
    case_index = case_result['case_index']
    costs = case_result['costs']
    profits = [cases[case_index - 1]['市场售价'] * 100 - cost for cost in costs]

    df_case = pd.DataFrame({
        '策略': strategy_names,
        '成本': costs,
        '利润': profits,
    })
    df_case['案例'] = f'案例 {case_index}'
    df_all_cases = pd.concat([df_all_cases, df_case], ignore_index=True)
excel_filename = '策略结果.xlsx'
df_all_cases.to_excel(excel_filename, index=False, sheet_name='策略结果')
print(f"策略结果已保存到 '{excel_filename}'")
def monte_carlo_simulation_profit(case, num_simulations=1000):
    results = []
    for _ in range(num_simulations):
        
        case['零配件1次品率'] = np.random.uniform(0, 0.5)
        case['零配件2次品率'] = np.random.uniform(0, 0.5)
        case['成品次品率'] = np.random.uniform(0, 0.5)
        costs = [calc_total_cost(case, *strategy) for strategy in strategies]
        profits = [case['市场售价'] * 100 - cost for cost in costs]
        max_profit = max(profits)
        results.append(max_profit)
    return results

def check_convergence(case, num_simulations=1000, num_repeats=10):
    all_results = []
    for _ in range(num_repeats):
        results = monte_carlo_simulation_profit(case, num_simulations)
        all_results.append(results)
    all_results = np.array(all_results)
    std_devs = np.std(all_results, axis=0)
    return std_devs
case_to_test = cases[0]
std_devs = check_convergence(case_to_test)
print(f"每次模拟的标准差：{std_devs}")
plt.figure(figsize=(8, 6))
plt.plot(std_devs, marker='o', color='green')  
plt.title('收敛检验：模拟结果的标准差')
plt.xlabel('模拟次数')
plt.ylabel('标准差')
plt.grid(True)
plt.show()
