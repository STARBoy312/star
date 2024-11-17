//#include <iostream>
//#include <queue>
//using namespace std;
//
//// 二叉树结点定义
//struct TreeNode {
//    int val;    //数据域
//    TreeNode* left; //左孩子
//    TreeNode* right;    //右孩子
//    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
//};
//
//// 初始化二叉树
//TreeNode* initTree(int n) {
//    if (n <= 0) 
//        return nullptr; //判断合法性
//
//    queue<TreeNode*> q; //初始一个根节点p
//    int val;
//    cin >> val; //输入对应的数据域
//    TreeNode* root = new TreeNode(val); //放到树中
//    q.push(root);   //push到根节点
//
//    // 逐层构建二叉树
//    for (int i = 1; i < n; i += 2) {
//        TreeNode* curr = q.front();
//        q.pop();
//        cin >> val;
//        if (val != -1) {
//            curr->left = new TreeNode(val); //输入的数据放到左孩子中
//            q.push(curr->left);
//        }
//        cin >> val;
//        if (val != -1) {
//            curr->right = new TreeNode(val);
//            q.push(curr->right);
//        }
//    }
//
//    return root;
//}
//
//// 前序遍历
//void preOrder(TreeNode* root) {
//    if (root) {
//        cout << root->val << " ";  // 访问根结点
//        preOrder(root->left);       // 遍历左子树
//        preOrder(root->right);      // 遍历右子树
//    }
//}
//
//// 中序遍历
//void inOrder(TreeNode* root) {
//    if (root) {
//        inOrder(root->left);        // 遍历左子树
//        cout << root->val << " ";   // 访问根结点
//        inOrder(root->right);       // 遍历右子树
//    }
//}
//
//// 后序遍历
//void postOrder(TreeNode* root) {
//    if (root) {
//        postOrder(root->left);      // 遍历左子树
//        postOrder(root->right);     // 遍历右子树
//        cout << root->val << " ";   // 访问根结点
//    }
//}
//
//int main() {
//    int n;
//    cout << "请输入树的结点个数：";
//    cin >> n;
//    cout << "请输入每个结点的值（-1表示空结点）：";
//    TreeNode* root = initTree(n);
//
//    cout << "前序遍历结果：";
//    preOrder(root);
//    cout << endl;
//
//    cout << "中序遍历结果：";
//    inOrder(root);
//    cout << endl;
//
//    cout << "后序遍历结果：";
//    postOrder(root);
//    cout << endl;
//
//    return 0;
//}
