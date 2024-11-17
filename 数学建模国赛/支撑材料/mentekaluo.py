import numpy as np
import scipy.stats as stats
import matplotlib.pyplot as plt
def calculate_sample_size(p0, E, confidence_level):
    if confidence_level == 0.95:
        Z = 1.96
    elif confidence_level == 0.90:
        Z = 1.645
    else:
        raise ValueError("Unsupported confidence level")
    n = (Z ** 2 * p0 * (1 - p0)) / (E ** 2)
    return int(np.ceil(n))
def monte_carlo_simulation_accuracy(sample_size, true_defect_rate, confidence_level, num_simulations=10000):
    Z_threshold = stats.norm.ppf(confidence_level)  
    correct_predictions = 0
    for _ in range(num_simulations):
        sample = np.random.binomial(1, true_defect_rate, sample_size)
        defect_rate = np.mean(sample)
        Z = (defect_rate - p0) / np.sqrt(p0 * (1 - p0) / sample_size)
        predicted_reject = Z > Z_threshold
        actual_reject = true_defect_rate > p0
        if predicted_reject == actual_reject:
            correct_predictions += 1
    accuracy = correct_predictions / num_simulations
    return accuracy
p0 = 0.1  
E = 0.05  
confidence_levels = [0.95, 0.90]
true_defect_rate = 0.12
sample_sizes = {cl: calculate_sample_size(p0, E, cl) for cl in confidence_levels}
print("样本大小:")
for cl, size in sample_sizes.items():
    print(f"{cl * 100}% 信度下的样本大小: {size}")
accuracies = {cl: monte_carlo_simulation_accuracy(sample_sizes[cl], true_defect_rate, cl) for cl in confidence_levels}
print("\n模型准确度:")
for cl, acc in accuracies.items():
    print(f"{cl * 100}% 信度下的准确度: {acc:.2f}")
confidence_levels_percent = [cl * 100 for cl in confidence_levels]
accuracy_values = list(accuracies.values())
plt.figure(figsize=(8, 6))
plt.bar(confidence_levels_percent, accuracy_values, color='blue', width=5)
plt.xlabel('Confidence Level (%)')
plt.ylabel('Accuracy')
plt.title('Model Accuracy at Different Confidence Levels')
plt.ylim(0, 1)
plt.xticks(confidence_levels_percent)
plt.show()
