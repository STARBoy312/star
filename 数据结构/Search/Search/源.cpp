#include <stdio.h>

// ˳����Һ���
int seq_search(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            return i;
        }
    }
    return -1;
}

// ���ֲ��Һ���
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
    printf("��������Ĵ�С");
    scanf("%d", &n);

    int arr[n];
    printf("�����������Ԫ��");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int key;    //�����Ҫ���ҵ�Ԫ��
    printf("������Ҫ��ѯ������");
    scanf("%d", &key);

    //��ʼ����˳���ѯ����
    int index = seq_search(arr, n, key);
    if (index == -1) {
        printf("û���ҵ���Ӧ������\n");
    }
    else {
        printf("�ҵ���,��Ӧ�±���%d\n", index);
    }



    //��ʼ���ö��ֲ�ѯ����
    int index2 = binary_search(arr, n, key);
    if (index2 == -1) {
        printf("δ�ҵ���ѯ��Ԫ��");
    }
    else {
        printf("�ҵ����±�Ϊ %d\n", index2);
    }

    return 0;
}


