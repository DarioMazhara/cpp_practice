#include <iostream>
#include <string>
#include <queue>

using namespace std;

struct ListNode {
    int data;
    ListNode* next;
};

struct BTNode {
    int data;
    BTNode *left, *right;
};

//insert node at start of linked list
void push(struct ListNode** head_ref, int new_data) {
    ListNode* node = new ListNode;
    node->data = new_data;
    node->next = *head_ref;
    *head_ref = node;
}

//creates binary tree node from parameter
struct BTNode* BTNode(int data) {
    struct BTNode* bt_node = new struct BTNode;
    bt_node->data = data;
    bt_node->left = bt_node->right = NULL;
    return bt_node;
}

//creqates the binary tree represented by the linked list
void convertLL_BT(ListNode *head, struct BTNode* &root) {
    queue<struct BTNode*> q;
    if (head == NULL) {
        root = NULL;
        return;
    }
    root = BTNode(head->data);
    q.push(root);

    head = head->next;

    while (head) {
        struct BTNode* parent = q.front();
        q.pop();

        struct BTNode* left = NULL, *right = NULL;
        left = BTNode(head->data);
        q.push(left);
        head = head->next;
        if(head) {
            right = BTNode(head->data);
            q.push(right);
            head = head->next;
        }

        parent->left = left;
        parent->right = right;
    }
}

//utility function to traverse tree after conversion
void inorderTraversal(struct BTNode* root) {
    if (root) {
        inorderTraversal(root->left);
        cout << root->data << " ";
        inorderTraversal(root->right);
    }
}

int main() {
    struct ListNode* head = NULL;
    push(&head, 36);
    push(&head, 30);
    push(&head, 25);
    push(&head, 15);
    push(&head, 12);
    push(&head, 10);

    struct BTNode* root;
    convertLL_BT(head, root);

    inorderTraversal(root);

    return 0;
}