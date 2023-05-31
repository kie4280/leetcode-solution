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
  string helper(TreeNode *n) {
    if (n == nullptr) return "";
    string left = helper(n->left);
    string right = helper(n->right);
    string builder;
    builder += to_string(n->val);
    if (n->left || n->right) builder += "(" + left + ")";
    if (n->right) builder += "(" + right + ")";
    return builder;
  }

  string tree2str(TreeNode *root) {
    return helper(root);
  }
};
