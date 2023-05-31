/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
  int maxDepth(Node *root) {
    stack<Node *> st;
    st.push(root);
    while (st.size() > 0) {
      Node *n = st.top();
      st.pop();
      for (int a = 0; a < root->children.size(); ++a) {
        st.push(root->children[a]);
      }
    }
  }
};
