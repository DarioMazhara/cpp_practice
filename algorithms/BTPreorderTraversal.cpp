#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#define MAX 1000

using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

vector<int> preorderTraversal(struct TreeNode* root) {
    if (root == NULL)
        return {};

    vector<int> order = {};
    
    stack<TreeNode*> stack;
    stack.push(root);

    while (!stack.empty()) {
        TreeNode* node = stack.top();
        stack.pop();

        order.push_back(node->val);

        if (node->right) {
            stack.push(node->right);
        }
        if (node->left) {
            stack.push(node->left);
        }
    }
    return order;
}.

void recursiveTraversal(struct TreeNode* root) {
    if (root == NULL)
        return;

    cout << root->val << endl;

    recursiveTraversal(root->left);
    recursiveTraversal(root->right);
}