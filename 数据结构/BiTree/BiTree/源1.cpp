#include <iostream>
#include <queue>
#include <map>
#include <string>
using namespace std;

// �շ�������㶨��
struct TreeNode {
    char data;  // �ַ�����
    int weight; // Ȩ��
    TreeNode* left;
    TreeNode* right;
    TreeNode(char c, int w) : data(c), weight(w), left(nullptr), right(nullptr) {}
};

// ���ڱȽϽ��Ȩ�صķº���
struct CompareNodes {
    bool operator()(TreeNode* const& n1, TreeNode* const& n2) {
        return n1->weight > n2->weight;
    }
};

// �����շ�����
TreeNode* buildHuffmanTree(map<char, int>& frequencies) {
    priority_queue<TreeNode*, vector<TreeNode*>, CompareNodes> minHeap;

    // ��ÿ���ַ�����Ƶ��ת��ΪҶ�ӽ�㣬��������С��
    for (auto& entry : frequencies) {
        minHeap.push(new TreeNode(entry.first, entry.second));
    }

    // ����С���й����շ�����
    while (minHeap.size() > 1) {
        TreeNode* left = minHeap.top();
        minHeap.pop();
        TreeNode* right = minHeap.top();
        minHeap.pop();
        TreeNode* parent = new TreeNode('$', left->weight + right->weight); // �����ַ�'$'��Ϊ�ڲ����
        parent->left = left;
        parent->right = right;
        minHeap.push(parent);
    }

    return minHeap.top();
}

// �ݹ����ɺշ�������
void generateHuffmanCodes(TreeNode* root, string code, map<char, string>& huffmanCodes) {
    if (root) {
        if (root->data != '$') {
            huffmanCodes[root->data] = code;
        }
        generateHuffmanCodes(root->left, code + "0", huffmanCodes);
        generateHuffmanCodes(root->right, code + "1", huffmanCodes);
    }
}

int main() {
    string input = "abracadabra"; // �����ַ���
    map<char, int> frequencies;    // �洢�ַ�����Ƶ��
    for (char c : input) {
        frequencies[c]++;
    }

    TreeNode* root = buildHuffmanTree(frequencies); // �����շ�����

    map<char, string> huffmanCodes; // �洢�շ�������
    generateHuffmanCodes(root, "", huffmanCodes); // ���ɺշ�������

    // ����շ�������
    cout << "�շ������룺" << endl;
    for (auto& entry : huffmanCodes) {
        cout << entry.first << " : " << entry.second << endl;
    }

    return 0;
}
