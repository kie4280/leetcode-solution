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
  TreeNode *helper(vector<int> &inorder, vector<int> &postorder, int in_start,
                   int post_start, int nums) {
    if (nums == 1)
      return new TreeNode(inorder[in_start]);
    int pivot = post_start + nums - 1;
    int left_num = 0;
    for (int a = in_start; a < inorder.size(); ++a) {
      if (inorder[a] == postorder[pivot]) {
        break;
      }
      ++left_num;
    }
    int right_num = nums - left_num - 1;
    TreeNode *left = nullptr;
    TreeNode *right = nullptr;
    if (left_num > 0)
      left = helper(inorder, postorder, in_start, post_start, left_num);
    if (right_num > 0)
      right = helper(inorder, postorder, in_start + left_num + 1, post_start + left_num, right_num);
    TreeNode *root = new TreeNode(postorder[pivot]);
    root->left = left;
    root->right = right;
    return root;

  }
  TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
    return helper(inorder, postorder, 0, 0, inorder.size());
  }
};
