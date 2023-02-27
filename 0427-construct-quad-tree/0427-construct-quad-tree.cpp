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
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
  Node* construct(vector<vector<int>>& grid) {
    grid_ = move(grid);
    leafNodes_[0] = new Node(false, true, nullptr, nullptr, nullptr, nullptr);
    leafNodes_[1] = new Node(true,  true, nullptr, nullptr, nullptr, nullptr);
    return construct(0, 0, grid_.size());
  }
  
  Node* construct(int r, int c, int s) {
    if (s == 1)
      return leafNodes_[grid_[r][c]];
    s /= 2;
    Node* tl = construct(r,   c,   s);
    Node* tr = construct(r,   c+s, s);
    Node* bl = construct(r+s, c,   s);
    Node* br = construct(r+s, c+s, s);
    if (tl == tr && tl == bl && tl == br)
      return tl;
    return new Node(false, false, tl, tr, bl, br);
  }
  
private:
  vector<vector<int>> grid_;
  array<Node*, 2> leafNodes_;
};