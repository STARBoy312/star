import numpy as np
import random
import pandas as pd
import matplotlib.pyplot as plt

initial_temperature =1200
cooling_rate = 0.95
min_temperature = 1
plt.rcParams['font.family'] = 'SimHei'

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

def calculate_expected_cost(components, semi_products, final_product, detect_components, detect_semi, detect_final, dismantle):
    total_cost = 0
    total_defective_rate = 1
    for i, (comp_name, comp_data) in enumerate(components.items()):
        cost = comp_data['购买单价']
        defective_rate = comp_data['次品率']
        if detect_components[i]:
            defective_rate *= 0.5
            cost += comp_data['检测成本']
        total_cost += cost
        total_defective_rate *= (1 - defective_rate)
    for i, (semi_name, semi_data) in enumerate(semi_products.items()):
        cost = semi_data['装配成本']
        defective_rate = semi_data['次品率']
        if detect_semi[i]:
            defective_rate *= 0.5
            cost += semi_data['检测成本']
        total_cost += cost
        total_defective_rate *= (1 - defective_rate)
    final_defective_rate = final_product['成品']['次品率'] * (0.5 if detect_final else 1)
    final_cost = final_product['成品']['装配成本']
    if detect_final:
        final_cost += final_product['成品']['检测成本']
    total_cost += final_cost
    total_defective_rate = 1 - (total_defective_rate * (1 - final_defective_rate))
    exchange_loss = final_product['成品']['调换损失'] * total_defective_rate
    total_cost += exchange_loss
    if dismantle:
        total_cost += final_product['成品']['拆解费用']

    total_units = 100  
    total_revenue = total_units * final_product['成品']['售价']
    profit = total_revenue - total_cost

    return total_cost, total_defective_rate, profit
def generate_random_decision():
    detect_components = [random.choice([True, False]) for _ in range(8)]
    detect_semi = [random.choice([True, False]) for _ in range(3)]
    detect_final = random.choice([True, False])
    dismantle = random.choice([True, False])
    return detect_components, detect_semi, detect_final, dismantle
def accept_solution(old_profit, new_profit, temperature):
    if new_profit > old_profit:
        return True
    else:
        probability = np.exp((new_profit - old_profit) / temperature)
        return random.random() < probability
def simulated_annealing():
    current_solution = generate_random_decision()
    current_cost, current_defective_rate, current_profit = calculate_expected_cost(components, semi_products, final_product,
                                                                            *current_solution)
    best_solution = current_solution
    best_profit = current_profit
    temperature = initial_temperature
    results = []
    while temperature > min_temperature:
        new_solution = generate_random_decision()
        new_cost, new_defective_rate, new_profit = calculate_expected_cost(components, semi_products, final_product,
                                                                            *new_solution)
        if accept_solution(current_profit, new_profit, temperature):
            current_solution = new_solution
            current_profit = new_profit
            if new_profit > best_profit:
                best_solution = new_solution
                best_profit = new_profit

        temperature *= cooling_rate

        results.append({
            'Temperature': temperature,
            'Best Profit': best_profit,
            'Current Profit': current_profit
        })

    df_results = pd.DataFrame(results)
    df_results.to_excel('simulated_annealing_results.xlsx', index=False)
    plt.figure(figsize=(10, 6))
    plt.plot(df_results['Temperature'], df_results['Best Profit'], marker='o', label='Best Profit')
    plt.xlabel('Temperature')
    plt.ylabel('Profit')
    plt.title('Simulated Annealing Results')
    plt.legend()
    plt.grid(True)
    plt.savefig('simulated_annealing_plot.png', dpi=300)
    plt.show()
if __name__ == "__main__":
    simulated_annealing()
