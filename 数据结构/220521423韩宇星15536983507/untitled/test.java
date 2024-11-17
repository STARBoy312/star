//import java.util.Scanner;
//
//public class test {
//
//    public static void main(String[] args) {
//        Scanner scanner = new Scanner(System.in);
//        // 读入矩阵的行数和列数
//        int n = scanner.nextInt();
//        int m = scanner.nextInt();
//        scanner.nextLine(); // 读取换行符
//
//        // 读入矩阵
//        char[][] matrix = new char[n][m];
//        for (int i = 0; i < n; i++) {
//            matrix[i] = scanner.nextLine().toCharArray();
//        }
//
//        // 计算最少需要的操作次数
//        int operations = minOperations(matrix);
//        System.out.println(operations);
//
//        scanner.close();
//    }
//
//    private static int minOperations(char[][] matrix) {
//        int n = matrix.length;
//        int m = matrix[0].length;
//        int operations = 0;
//
//        // 从左上角开始逐行扫描
//        for (int i = 0; i < n; i++) {
//            for (int j = 0; j < m; j++) {
//                // 如果遇到0，则将其所在的一行二列区域变成1
//                if (matrix[i][j] == '0') {
//                    operations++;
//                    // 变更当前位置和右边相邻位置
//                    matrix[i][j] = '1';
//                    if (j + 1 < m) {
//                        matrix[i][j + 1] = '1';
//                    }
//                }
//            }
//        }
//
//        return operations;
//    }
//}

//import java.util.Scanner;
//
//public class test {
//    public static void main(String[] args) {
//        Scanner input = new Scanner(System.in);
//        int n = input.nextInt();
//        int[] arr = new int[n];
//
//        for (int i = 0; i < n; i++) {
//            arr[i] = input.nextInt();
//        }
//
//        // 计算初始总和
//        int totalSum = 0;
//        for (int num : arr) {
//            totalSum += num;
//        }
//
//        // 寻找全是偶数的最大区间，并计算除以2后的总和
//        int maxIntervalSum = 0;
//        int intervalSum = 0;
//        for (int num : arr) {
//            if (num % 2 == 0) {
//                intervalSum += num / 2; // 累加偶数区间的和
//            } else {
//                intervalSum = 0; // 遇到奇数，重置区间和
//            }
//            maxIntervalSum = Math.max(maxIntervalSum, intervalSum); // 更新最大区间和
//        }
//
//        // 输出最大总和
//        System.out.println(Math.max(totalSum, totalSum - maxIntervalSum));
//        input.close();
//    }
//}

//import java.util.Scanner;
//
//public class test {
//    public static void main(String[] args) {
//        Scanner input = new Scanner(System.in);
//        int n = input.nextInt();
//        long[] nums = new long[n];
//
//        for (int i = 0; i < n; i++) {
//            nums[i] = input.nextLong();
//        }
//
//        long mod = 1000000007;
//        long result = 1;
//
//        for (int i = 0; i < n; i++) {
//            result = (result * factorial(nums[i])) % mod;
//        }
//
//        long factorCount = countFactors(result);
//
//        System.out.println(factorCount);
//    }
//
//    public static long factorial(long num) {
//        long result = 1;
//        for (int i = 1; i <= num; i++) {
//            result = (result * i) % 1000000007;
//        }
//        return result;
//    }
//
//    public static long countFactors(long num) {
//        long count = 0;
//        for (long i = 1; i <= Math.sqrt(num); i++) {
//            if (num % i == 0) {
//                if (num / i == i) {
//                    count++;
//                } else {
//                    count += 2;
//                }
//            }
//        }
//        return count;
//    }
//}

//import java.util.Scanner;
//
//public class test {
//    private static final int MOD = 1000000007;
//
//    public static void main(String[] args) {
//        Scanner input = new Scanner(System.in);
//        int n = input.nextInt();
//        int[] numbers = new int[n];
//        for (int i = 0; i < n; i++) {
//            numbers[i] = input.nextInt();
//        }
//        input.close();
//
//        long result = findFactorialFactors(numbers);
//        System.out.println(result);
//    }
//
//    private static long findFactorialFactors(int[] numbers) {
//        long[] factorCounts = new long[11]; // Since ai <= 10
//        for (int number : numbers) {
//            for (int i = 2; i <= number; i++) {
//                factorizeAndCount(i, factorCounts);
//            }
//        }
//
//        long totalFactors = 1;
//        for (long count : factorCounts) {
//            totalFactors = (totalFactors * (count + 1)) % MOD;
//        }
//
//        return totalFactors;
//    }
//
//    private static void factorizeAndCount(int number, long[] factorCounts) {
//        for (int i = 2; i <= number; i++) {
//            while (number % i == 0) {
//                factorCounts[i]++;
//                number /= i;
//            }
//        }
//    }
//}

//import java.util.Scanner;5
//
//public class test {
//    public static void main(String[] args) {
//        Scanner input = new Scanner(System.in);
//        int n = input.nextInt();
//        int[] arr = new int[n];
//        for (int i = 0; i < n; i++) {
//            arr[i] = input.nextInt();
//        }
//        input.close();
//
//        // 计算初始总和
//        int totalSum = 0;
//        for (int num : arr) {
//            totalSum += num;
//        }
//
//        // 寻找全是偶数的最大区间，并计算除以2后的总和
//        int maxIntervalSum = 0;
//        int intervalSum = 0;
//        for (int num : arr) {
//            if (num % 2 == 0) {
//                intervalSum += num / 2; // 累加偶数区间的和
//            } else {
//                intervalSum = 0; // 遇到奇数，重置区间和
//            }
//            maxIntervalSum = Math.max(maxIntervalSum, intervalSum); // 更新最大区间和
//        }
//
//        // 输出最大总和
//        int finalSum = totalSum - maxIntervalSum;
//        System.out.println(finalSum > totalSum ? finalSum : -1);
//    }
//}

//import java.util.Scanner;
//
//public class test {
//    public static void main(String[] args) {
//        Scanner scanner = new Scanner(System.in);
//        int n = scanner.nextInt(); // 数组的大小
//        int[] arr = new int[n]; // 数组
//
//        // 读取数组元素
//        for (int i = 0; i < n; i++) {
//            arr[i] = scanner.nextInt();
//        }
//        scanner.close();
//
//        // 计算初始总和
//        int totalSum = 0;
//        for (int num : arr) {
//            totalSum += num;
//        }
//
//        // 寻找全是偶数的最大区间，并计算除以2后的总和
//        int maxIntervalSum = 0;
//        int intervalSum = 0;
//        int currentSum = 0;
//
//        for (int num : arr) {
//            if (num % 2 == 0) {
//                currentSum += num;
//                intervalSum = Math.max(intervalSum, currentSum);
//            } else {
//                currentSum = 0;
//            }
//        }
//
//        // 计算最大区间除以2的增益
//        maxIntervalSum = intervalSum / 2;
//
//        // 输出最大总和
//        int finalSum = totalSum - maxIntervalSum;
//        System.out.println(finalSum > totalSum ? finalSum : -1);
//    }
//}

//import java.util.Scanner;
//
//public class test {
//    public static void main(String[] args) {
//        Scanner scanner = new Scanner(System.in);
//        int n = scanner.nextInt(); // 数组的大小
//        int[] arr = new int[n]; // 数组
//
//        // 读取数组元素
//        for (int i = 0; i < n; i++) {
//            arr[i] = scanner.nextInt();
//        }
//        scanner.close();
//
//        // 计算初始总和
//        int totalSum = 0;
//        for (int num : arr) {
//            totalSum += num;
//        }
//
//        // 寻找全是偶数的最大区间，并计算除以2后的总和
//        int maxGain = 0;
//        int currentGain = 0;
//        int currentSum = 0;
//
//        for (int num : arr) {
//            if (num % 2 == 0) {
//                currentSum += num;
//                currentGain = currentSum - (currentSum / 2);
//                maxGain = Math.max(maxGain, currentGain);
//            } else {
//                currentSum = 0;
//                currentGain = 0;
//            }
//        }
//
//        // 输出最大总和
//        int finalSum = totalSum - maxGain;
//        System.out.println(finalSum > totalSum ? finalSum : -1);
//    }
//}

//import java.util.Scanner;
//
//public class test {
//    public static void main(String[] args) {
//        Scanner scanner = new Scanner(System.in);
//        int n = scanner.nextInt(); // 数组大小
//        long[] arr = new long[n];
//        long sum = 0; // 所有元素的和
//        long maxDiff = 0; // 最大差值
//
//        // 读取数组元素
//        for (int i = 0; i < n; i++) {
//            arr[i] = scanner.nextLong();
//            if (arr[i] % 2 == 0) {
//                // 计算如果这个偶数除以2，可以增加多少和
//                long diff = arr[i] / 2;
//                maxDiff = Math.max(maxDiff, diff);
//            }
//            sum += arr[i];
//        }
//
//        // 输出最终的最大和
//        System.out.println(sum + maxDiff);
//        scanner.close();
//    }
//}
//
//import java.util.Scanner;
//
//public class test3 {
//    private static final int MOD = 1000000007;
//
//    public static void main(String[] args) {
//        Scanner scanner = new Scanner(System.in);
//        int n = scanner.nextInt();
//        long result = 1;
//
//        // 计算所有数的阶乘的质因数分解
//        int[] primeCounts = new int[11]; // 因为 1 ≤ ai ≤ 10
//        for (int i = 0; i < n; i++) {
//            int number = scanner.nextInt();
//            factorizeAndAdd(number, primeCounts);
//        }
//
//        // 计算因子总数
//        for (int count : primeCounts) {
//            result = (result * (count + 1)) % MOD;
//        }
//
//        System.out.println(result);
//        scanner.close();
//    }
//
//    private static void factorizeAndAdd(int number, int[] primeCounts) {
//        for (int i = 2; i <= number; i++) {
//            int temp = i;
//            for (int j = 2; j <= temp; j++) {
//                while (temp % j == 0) {
//                    primeCounts[j]++;
//                    temp /= j;
//                }
//            }
//        }
//    }
//}
5
import java.util.Map;
import java.util.Scanner;

public class test {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt(); // 数组大小
        long[] arr = new long[n];
        long totalSum = 0; // 所有元素的和
        long maxIncrease = 0; // 最大增加值

        // 读取数组元素并计算总和
        for (int i = 0; i < n; i++) {
            arr[i] = scanner.nextLong();
            totalSum += arr[i];
        }

        // 寻找全是偶数的区间，并计算除以2后的增加值
        long currentIncrease = 0;
        for (int i = 0; i < n; i++) {
            if (arr[i] % 2 == 0) {
                currentIncrease += arr[i] / 2;
            } else {
                maxIncrease = Math.max(maxIncrease, currentIncrease);
                currentIncrease = 0;
            }
        }
        maxIncrease = Math.max(maxIncrease, currentIncrease); // 检查最后一个区间

        // 输出最终的最大和
        System.out.println(totalSum + maxIncrease);
        scanner.close();
    }
}


import java.util.*;

public class FactorialFactors {

    private static final int MOD = 1000000007;

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        scanner.nextLine(); // Skip to the next line
        int[] numbers = new int[n];
        for (int i = 0; i < n; i++) {
            numbers[i] = scanner.nextInt();
        }
        scanner.close();

        long result = countTotalFactors(numbers);
        System.out.println(result);
    }

    private static long countTotalFactors(int[] numbers) {
        Map<Integer, Integer> primeFactorsMap = new HashMap<>();
        for (int number : numbers) {
            Map<Integer, Integer> factors = primeFactorsOfFactorial(number);
            for (Map.Entry<Integer, Integer> entry : factors.entrySet()) {
                primeFactorsMap.merge(entry.getKey(), entry.getValue(), Integer::sum);
            }
        }

        long totalCount = 1;
        for (int count : primeFactorsMap.values()) {
            totalCount = (totalCount * (count + 1)) % MOD;
        }
        return totalCount;
    }

    private static Map<Integer, Integer> primeFactorsOfFactorial(int number) {
        Map<Integer, Integer> factors = new HashMap<>();
        for (int i = 2; i <= number; i++) {
            int temp = i;
            for (int j = 2; j * j <= temp; j++) {
                while (temp % j == 0) {
                    factors.merge(j, 1, Integer::sum);
                    temp /= j;
                }
            }
            if (temp > 1) {
                factors.merge(temp, 1, Integer::sum);
            }
        }
        return factors;
    }
}








