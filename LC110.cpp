/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
  int check_balance(TreeNode *root) {
    if (root == nullptr) return 0;
    int left = check_balance(root->left);
    int right = check_balance(root->right);
    if (left == -1 || right == -1) {
      return -1;
    }
    if (abs(left-right) < 2) {
      return max(left, right) + 1;
    }
    return -1;
  }

  bool isBalanced(TreeNode *root) {
    int a = check_balance(root);
    return a >= 0;
  }
};
