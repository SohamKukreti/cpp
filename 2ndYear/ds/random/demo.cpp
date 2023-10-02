#include <iostream>
using namespace std;
struct TreeNode {
int val;
TreeNode* left;
TreeNode* right;
TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
TreeNode* insert(TreeNode* root, int key) {
if (root == NULL) {
return new TreeNode(key);
}
if (key < root->val) {
root->left = insert(root->left, key);
} else {
root->right = insert(root->right, key);
}
return root;
}
TreeNode* findMin(TreeNode* node) {
while (node->left != NULL) {
node = node->left;
}
return node;
}
TreeNode* deleteNode(TreeNode* root, int key) {
if (root == NULL) {
return root;
}
if (key < root->val) {
root->left = deleteNode(root->left, key);
} else if (key > root->val) {
root->right = deleteNode(root->right, key);
} else {
if (root->left == NULL) {
TreeNode* temp = root->right;
delete root;
return temp;
} else if (root->right == NULL) {
TreeNode* temp = root->left;
delete root;
return temp;
}
TreeNode* temp = findMin(root->right);
root->val = temp->val;
root->right = deleteNode(root->right, temp->val);
}
return root;
}
void inorderTraversal(TreeNode* root) {
if (root != NULL) {
inorderTraversal(root->left);
cout << root->val << " ";
inorderTraversal(root->right);
}
}
int main() {
TreeNode* root = NULL;
int keys[] = {10, 5, 15, 3, 8, 12, 18, 2, 4, 7, 9, 11, 14, 17, 20};
for (int key : keys) {
root = insert(root, key);
}
cout << "Inorder traversal before deletion: ";
inorderTraversal(root);
cout << endl;
root = deleteNode(root, 2);
cout << "Inorder traversal after deleting a leaf node: ";
inorderTraversal(root);
cout << endl;
root = deleteNode(root, 15);
cout << "Inorder traversal after deleting a node with one child: ";
inorderTraversal(root);
cout << endl;
root = deleteNode(root, 10);
cout << "Inorder traversal after deleting a node with two children: ";
inorderTraversal(root);
cout << endl;
return 0;
}