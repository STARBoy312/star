//#include <iostream>
//#include <queue>
//using namespace std;
//
//// ��������㶨��
//struct TreeNode {
//    int val;    //������
//    TreeNode* left; //����
//    TreeNode* right;    //�Һ���
//    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
//};
//
//// ��ʼ��������
//TreeNode* initTree(int n) {
//    if (n <= 0) 
//        return nullptr; //�жϺϷ���
//
//    queue<TreeNode*> q; //��ʼһ�����ڵ�p
//    int val;
//    cin >> val; //�����Ӧ��������
//    TreeNode* root = new TreeNode(val); //�ŵ�����
//    q.push(root);   //push�����ڵ�
//
//    // ��㹹��������
//    for (int i = 1; i < n; i += 2) {
//        TreeNode* curr = q.front();
//        q.pop();
//        cin >> val;
//        if (val != -1) {
//            curr->left = new TreeNode(val); //��������ݷŵ�������
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
//// ǰ�����
//void preOrder(TreeNode* root) {
//    if (root) {
//        cout << root->val << " ";  // ���ʸ����
//        preOrder(root->left);       // ����������
//        preOrder(root->right);      // ����������
//    }
//}
//
//// �������
//void inOrder(TreeNode* root) {
//    if (root) {
//        inOrder(root->left);        // ����������
//        cout << root->val << " ";   // ���ʸ����
//        inOrder(root->right);       // ����������
//    }
//}
//
//// �������
//void postOrder(TreeNode* root) {
//    if (root) {
//        postOrder(root->left);      // ����������
//        postOrder(root->right);     // ����������
//        cout << root->val << " ";   // ���ʸ����
//    }
//}
//
//int main() {
//    int n;
//    cout << "���������Ľ�������";
//    cin >> n;
//    cout << "������ÿ������ֵ��-1��ʾ�ս�㣩��";
//    TreeNode* root = initTree(n);
//
//    cout << "ǰ����������";
//    preOrder(root);
//    cout << endl;
//
//    cout << "������������";
//    inOrder(root);
//    cout << endl;
//
//    cout << "������������";
//    postOrder(root);
//    cout << endl;
//
//    return 0;
//}
