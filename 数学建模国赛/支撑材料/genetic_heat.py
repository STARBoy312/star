
import numpy as np
import matplotlib.pyplot as plt
import seaborn as sns
import itertools
import pandas as pd
plt.rcParams['font.sans-serif'] = ['Microsoft YaHei']
cases = [
    {'零配件1次品率': 0.1, '零配件2次品率': 0.100066, '成品次品率': 0.100060, '零配件1检测成本': 2, '零配件2检测成本': 3,
     '成品检测成本': 3, '装配成本': 6, '市场售价': 56, '调换损失': 6, '拆解费用': 5},
    {'零配件1次品率': 0.199834, '零配件2次品率': 0.200360, '成品次品率': 0.198670, '零配件1检测成本': 2, '零配件2检测成本': 3,
     '成品检测成本': 3, '装配成本': 6, '市场售价': 56, '调换损失': 6, '拆解费用': 5},
    {'零配件1次品率': 0.100140, '零配件2次品率': 0.099458, '成品次品率': 0.101166, '零配件1检测成本': 2, '零配件2检测成本': 3,
     '成品检测成本': 3, '装配成本': 6, '市场售价': 56, '调换损失': 30, '拆解费用': 5},
    {'零配件1次品率': 0.199388, '零配件2次品率': 0.199458, '成品次品率': 0.198960, '零配件1检测成本': 1, '零配件2检测成本': 1,
     '成品检测成本': 2, '装配成本': 6, '市场售价': 56, '调换损失': 30, '拆解费用': 5},
    {'零配件1次品率': 0.100252, '零配件2次品率':  0.199966, '成品次品率': 0.100342, '零配件1检测成本': 8, '零配件2检测成本': 1,
     '成品检测成本': 2, '装配成本': 6, '市场售价': 56, '调换损失': 10, '拆解费用': 5},
    {'零配件1次品率': 0.039728, '零配件2次品率': 0.040098, '成品次品率': 0.039766, '零配件1检测成本': 2, '零配件2检测成本': 3,
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
    return ''.join(['1' if x else '0' for x in strategy])
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
plt.figure(figsize=(10, 6))
offsets = [-0.05, 0.05, -0.08, 0.08, -0.10, 0.10]
for idx, case_result in enumerate(all_cases_results):
    profits = case_result['profits']
    plt.plot(range(1, 17), profits, label=f"案例 {case_result['case_index']}")
    max_profit_index = np.argmax(profits) + 1
    max_profit_value = max(profits)
    plt.scatter(max_profit_index, max_profit_value, color='red')
    offset = offsets[idx % len(offsets)]
    if case_result['case_index'] == 3:  
        plt.text(max_profit_index, max_profit_value + offset, f'{max_profit_value:.2f}',
                 horizontalalignment='right', verticalalignment='top', fontsize=10, color='red')
    elif case_result['case_index'] == 2:
        plt.text(max_profit_index, max_profit_value + offset, f'{max_profit_value:.2f}',
                 horizontalalignment='left', verticalalignment='bottom', fontsize=10, color='red')
    elif case_result['case_index'] == 1:
        plt.text(max_profit_index, max_profit_value + offset, f'{max_profit_value:.2f}',
                 horizontalalignment='left', verticalalignment='bottom', fontsize=10, color='red')
    else:
        plt.text(max_profit_index, max_profit_value + offset, f'{max_profit_value:.2f}',
                 horizontalalignment='right', verticalalignment='bottom', fontsize=10, color='red')

plt.xlabel('策略编号')
plt.ylabel('利润')
plt.legend(title='情况')
plt.xticks(range(1, 17))
plt.grid(True)
plt.show()
strategy_names = [strategy_identifier(strategy) for strategy in strategies]
df_all_cases = pd.DataFrame()

for case_result in all_cases_results:
    case_index = case_result['case_index']
    costs = case_result['costs']
    profits = [cases[case_index - 1]['市场售价'] * 100 - cost for cost in costs]
    df_case = pd.DataFrame({
        '策略': strategy_names,
        '利润': profits,  
        '情况': case_index
    })
    df_all_cases = pd.concat([df_all_cases, df_case], ignore_index=True)

heatmap_data = df_all_cases.pivot(index="策略", columns="情况", values="利润")
plt.figure(figsize=(10, 8))
sns.heatmap(heatmap_data, annot=True, cmap="YlGnBu", fmt=".2f", cbar_kws={'label': '利润'})  
plt.title("不同策略的利润热力图")
plt.xlabel("情况")
plt.ylabel("策略")
plt.xticks(ticks=np.arange(len(cases)) + 0.5, labels=[f"情况 {i+1}" for i in range(len(cases))], rotation=45)
plt.yticks(ticks=np.arange(len(strategies)) + 0.5, labels=[f"策略 {i+1}" for i in range(len(strategies))], rotation=0)
plt.tight_layout()
plt.show()
def strategy_identifier(strategy):
    return f"({int(strategy[0])}, {int(strategy[1])}, {int(strategy[2])}, {int(strategy[3])})"
def strategy_identifier(strategy):
    return f"({int(strategy[0])}, {int(strategy[1])}, {int(strategy[2])}, {int(strategy[3])})"
def plot_profits(all_cases_results, strategies, strategy_labels):
    group1 = all_cases_results[:3]
    group2 = all_cases_results[3:]
    plot_group_profits(group1, strategies, strategy_labels, "情况 1-3 各策略总利润")
    plot_group_profits(group2, strategies, strategy_labels, "情况 4-6 各策略总利润")
def plot_group_profits(cases_group, strategies, strategy_labels, title):
    num_cases = len(cases_group)
    fig, axes = plt.subplots(nrows=num_cases, ncols=1, figsize=(15, 3 * num_cases))
    if num_cases == 1:
        axes = [axes]
    for ax, case_result in zip(axes, cases_group):
        case_num = case_result['case_index']
        profits = case_result['profits']
        max_profit = max(profits)
        optimal_strategy = case_result['strategies'][profits.index(max_profit)]
        optimal_index = case_result['strategies'].index(optimal_strategy)
        strategy_ids = [strategy_identifier(s) for s in strategies]
        sns.barplot(x=strategy_ids, y=profits, ax=ax, palette="viridis")
        ax.set_title(f"情况 {case_num} 各策略总利润")
        ax.set_xlabel("策略 (检测零配件1, 检测零配件2, 检测成品, 拆解不合格成品)")
        ax.set_ylabel("总利润")
        ax.bar(strategy_ids[optimal_index], profits[optimal_index], color='red', label='最优策略 (最大利润)')
        ax.legend()
    fig.suptitle(title, fontsize=16)
    fig.tight_layout(rect=[0, 0, 1, 0.96])  
    fig.subplots_adjust(hspace=0.5)  
    plt.show()
plot_profits(all_cases_results, strategies, strategy_labels)
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
simulation_profit_results = monte_carlo_simulation_profit(cases[0])
plt.figure(figsize=(8, 6))
sns.histplot(simulation_profit_results, kde=True)
plt.title('蒙特卡罗模拟: 总利润分布')
plt.xlabel('总利润')
plt.ylabel('频率')
plt.show()
