#include <iostream>
#include <queue>
#include <map>
#include <string>
using namespace std;

// 赫夫曼树结点定义
struct TreeNode {
    char data;  // 字符数据
    int weight; // 权重
    TreeNode* left;
    TreeNode* right;
    TreeNode(char c, int w) : data(c), weight(w), left(nullptr), right(nullptr) {}
};

// 用于比较结点权重的仿函数
struct CompareNodes {
    bool operator()(TreeNode* const& n1, TreeNode* const& n2) {
        return n1->weight > n2->weight;
    }
};

// 构建赫夫曼树
TreeNode* buildHuffmanTree(map<char, int>& frequencies) {
    priority_queue<TreeNode*, vector<TreeNode*>, CompareNodes> minHeap;

    // 将每个字符及其频率转换为叶子结点，并加入最小堆
    for (auto& entry : frequencies) {
        minHeap.push(new TreeNode(entry.first, entry.second));
    }

    // 从最小堆中构建赫夫曼树
    while (minHeap.size() > 1) {
        TreeNode* left = minHeap.top();
        minHeap.pop();
        TreeNode* right = minHeap.top();
        minHeap.pop();
        TreeNode* parent = new TreeNode('$', left->weight + right->weight); // 虚拟字符'$'作为内部结点
        parent->left = left;
        parent->right = right;
        minHeap.push(parent);
    }

    return minHeap.top();
}

// 递归生成赫夫曼编码
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
    string input = "abracadabra"; // 输入字符串
    map<char, int> frequencies;    // 存储字符及其频率
    for (char c : input) {
        frequencies[c]++;
    }

    TreeNode* root = buildHuffmanTree(frequencies); // 构建赫夫曼树

    map<char, string> huffmanCodes; // 存储赫夫曼编码
    generateHuffmanCodes(root, "", huffmanCodes); // 生成赫夫曼编码

    // 输出赫夫曼编码
    cout << "赫夫曼编码：" << endl;
    for (auto& entry : huffmanCodes) {
        cout << entry.first << " : " << entry.second << endl;
    }

    return 0;
}
