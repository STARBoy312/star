#include <stdio.h>

// 顺序查找函数
int seq_search(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            return i;
        }
    }
    return -1;
}

// 二分查找函数
int binary_search(int arr[], int n, int key) {
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (arr[mid] == key) {
            return mid;
        }
        else if (arr[mid] < key) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    return -1;
}

int main() {
    int n;
    printf("输入数组的大小");
    scanf("%d", &n);

    int arr[n];
    printf("输入你的数据元素");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int key;    //这个是要查找的元素
    printf("输入你要查询的数字");
    scanf("%d", &key);

    //开始调用顺序查询函数
    int index = seq_search(arr, n, key);
    if (index == -1) {
        printf("没有找到对应的坐标\n");
    }
    else {
        printf("找到了,对应下标是%d\n", index);
    }



    //开始调用二分查询函数
    int index2 = binary_search(arr, n, key);
    if (index2 == -1) {
        printf("未找到查询的元素");
    }
    else {
        printf("找到了下标为 %d\n", index2);
    }

    return 0;
}


