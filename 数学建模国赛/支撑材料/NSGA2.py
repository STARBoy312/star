import itertools
import numpy as np
import random
import pandas as pd
population_size = 9000
generations = 15
mutation_rate = 0.1
crossover_rate = 0.7
initial_temperature = 1000
cooling_rate = 0.95
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
def calculate_expected_cost(components, semi_products, final_product, detect_components, detect_semi, detect_final,
                            dismantle):
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
def generate_all_possible_decisions():
    decisions = list(itertools.product([True, False], repeat=13))
    return decisions
all_possible_decisions = generate_all_possible_decisions()
def encode_individual(index):
    detect_strategy = all_possible_decisions[index]
    detect_components = detect_strategy[:8]
    detect_semi = detect_strategy[8:11]
    detect_final = detect_strategy[11]
    dismantle = detect_strategy[12]
    return detect_components, detect_semi, detect_final, dismantle
def initialize_population(size, all_decisions):
    population = []
    for i in range(size):
        individual = encode_individual(i % len(all_decisions))
        population.append(individual)
    return population
def fitness(individual):
    detect_components, detect_semi, detect_final, dismantle = individual
    cost, defective_rate, profit = calculate_expected_cost(components, semi_products, final_product,
                                                           detect_components, detect_semi, detect_final, dismantle)
    return profit
def selection(population):
    fitness_values = [1 / fitness(ind) for ind in population]
    total_fitness = sum(fitness_values)
    probabilities = [f / total_fitness for f in fitness_values]
    selected_population = []
    for _ in range(population_size):
        r = random.random()
        cumulative_prob = 0
        for i, individual in enumerate(population):
            cumulative_prob += probabilities[i]
            if r < cumulative_prob:
                selected_population.append(individual)
                break
    return selected_population
def crossover(parent1, parent2):
    if random.random() < crossover_rate:
        point = random.randint(1, len(parent1[0]) - 1)
        parent1_components = list(parent1[0])
        parent2_components = list(parent2[0])
        child1_components = parent1_components[:point] + parent2_components[point:]
        child2_components = parent2_components[:point] + parent1_components[point:]
        parent1_semi = list(parent1[1])
        parent2_semi = list(parent2[1])
        child1_semi = parent1_semi[:1] + parent2_semi[1:]
        child2_semi = parent2_semi[:1] + parent1_semi[1:]
        child1_final = parent1[2]
        child2_final = parent2[2]
        child1_dismantle = parent1[3]
        child2_dismantle = parent2[3]
        child1 = (tuple(child1_components), tuple(child1_semi), child1_final, child1_dismantle)
        child2 = (tuple(child2_components), tuple(child2_semi), child2_final, child2_dismantle)
        return child1, child2
    else:
        return parent1, parent2
def mutate(individual):
    detect_components, detect_semi, detect_final, dismantle = individual
    detect_components = list(detect_components)
    detect_semi = list(detect_semi)
    if random.random() < mutation_rate:
        component_to_mutate = random.randint(0, len(detect_components) - 1)
        detect_components[component_to_mutate] = not detect_components[component_to_mutate]
    if random.random() < mutation_rate:
        semi_to_mutate = random.randint(0, len(detect_semi) - 1)
        detect_semi[semi_to_mutate] = not detect_semi[semi_to_mutate]
    if random.random() < mutation_rate:
        detect_final = not detect_final
    if random.random() < mutation_rate:
        dismantle = not dismantle
    return detect_components, detect_semi, detect_final, dismantle
def accept_solution(old_fitness, new_fitness, temperature):
    if new_fitness < old_fitness:
        return True
    else:
        probability = np.exp(-(new_fitness - old_fitness) / temperature)
        return random.random() < probability
def generate_strategy_description(detect_components, detect_semi, detect_final, dismantle):
    description = ""
    for i, detect in enumerate(detect_components):
        description += f"检测零配件 {i + 1}，" if detect else f"不检测零配件 {i + 1}，"
    for i, detect in enumerate(detect_semi):
        description += f"检测半成品 {i + 1}，" if detect else f"不检测半成品 {i + 1}，"
    if detect_final:
        description += "检测成品，"
    else:
        description += "不检测成品，"
    if dismantle:
        description += "拆解不合格成品"
    else:
        description += "不拆解不合格成品"
    return description
all_possible_decisions = generate_all_possible_decisions()
def genetic_simulated_annealing(all_decisions):
    all_generations_data = []
    seen_strategies = set()
    population = initialize_population(population_size, all_decisions)
    temperature = initial_temperature
    for generation in range(generations):
        new_population = []
        selected_population = selection(population)
        for i in range(0, population_size, 2):
            parent1 = selected_population[i]
            parent2 = selected_population[i+1] if (i+1) < population_size else selected_population[0]
            child1, child2 = crossover(parent1, parent2)
            child1 = mutate(child1)
            child2 = mutate(child2)
            old_fitness1 = fitness(parent1)
            new_fitness1 = fitness(child1)
            if accept_solution(old_fitness1, new_fitness1, temperature):
                new_population.append(child1)
            else:
                new_population.append(parent1)
            old_fitness2 = fitness(parent2)
            new_fitness2 = fitness(child2)
            if accept_solution(old_fitness2, new_fitness2, temperature):
                new_population.append(child2)
            else:
                new_population.append(parent2)
        population = new_population
        temperature *= cooling_rate
        for individual in population:
            strategy_description = generate_strategy_description(*individual)
            if strategy_description not in seen_strategies:
                seen_strategies.add(strategy_description)
                cost, defective_rate, profit = calculate_expected_cost(components, semi_products, final_product, *individual)
                all_generations_data.append({
                    'Generation': generation + 1,
                    'Strategy': strategy_description,
                    'Cost': cost,
                    'Defective Rate': defective_rate,
                    'Profit': profit
                })
        print(f"Generation {generation + 1}: {len(seen_strategies)} unique strategies recorded")
    results = pd.DataFrame(all_generations_data)
    return results
results_df = genetic_simulated_annealing(all_possible_decisions)
results_df.to_excel('strategy_results.xlsx', index=False)
print("结果已保存到 'strategy_results.xlsx'")

