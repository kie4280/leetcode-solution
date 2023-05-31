/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;

    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node*
_bottomLeft, Node* _bottomRight) { val = _val; isLeaf = _isLeaf; topLeft =
_topLeft; topRight = _topRight; bottomLeft = _bottomLeft; bottomRight =
_bottomRight;
    }
};
*/

class Solution {
public:
  Node *helper(const vector<vector<int>> &grid, int i, int j, int size) {
    array<Node *, 4> children;
    if (size == 1) {
      return new Node(grid[i][j], true);
    }
    int half = size / 2;
    children[0] = helper(grid, i, j, half);
    children[1] = helper(grid, i, j+half, half);
    children[2] = helper(grid, i+half, j, half);
    children[3] = helper(grid, i+half, j+half, half);
    Node *root = new Node(grid[i][j], true, children[0], children[1],
                          children[2], children[3]);
    int sum = 0;
    for (auto i : children) {
      sum += i->val;
      if (!i->isLeaf) {
        root->isLeaf = false;
        break;
      }
    }
    if (sum != 4 && sum != 0) {
      root->isLeaf = false;
    }
    if (root->isLeaf) {
      for (int a = 0; a < 4; ++a) {
        delete root;
        root = new Node(grid[i][j], true);
        delete children[a];
      }
    }
    return root;
  }
  Node *construct(vector<vector<int>> &grid) {

    return helper(grid, 0, 0, grid.size());
  }
};
