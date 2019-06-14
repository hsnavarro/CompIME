#include <bits/stdc++.h>
using namespace std;

struct Node {
  int key, height;
  Node *left, *right;
  Node(int key) : key(key), height(1), left(nullptr), right(nullptr) {}
};

class AVL {
  Node* root;

  int height(Node* node){ return node != nullptr ? node->height : 0; }
  int balance(Node* node){ return height(node->left) - height(node->right); }

  void update(Node* node){
    int left = height(node->left);
    int right = height(node->right);
    node->height = 1 + max(left, right);
  }

  Node* rightRotate(Node* node){
    Node* x = node->left;
    node->left = x->right;
    x->right = node;
    update(node), update(x);
    return x;
  }

  Node* leftRotate(Node* node){
    Node* y = node->right;
    node->right = y->left;
    y->left = node;
    update(node), update(y);
    return y;
  }

  Node* rebalance(Node* node){
    update(node);
    if(balance(node) == -2){
      if(balance(node->right) == 1) node->right = rightRotate(node->right);
      node = leftRotate(node);
    } else if(balance(node) == 2){
      if(balance(node->left) == -1) node->left = leftRotate(node->left);
      node = rightRotate(node);
    }
    return node;
  }

  Node* insertIn(Node* node, int val){
    if(node == nullptr) return new Node(val);
    if(val > node->key) node->right = insertIn(node->right, val);
    else node->left = insertIn(node->left, val);
    return rebalance(node);
  }

  Node* findMin(Node* node){ return node->left ? findMin(node->left) : node; }

  Node* removeIn(Node* node, int val){
    if(!node) return nullptr;
    if(val > node->key) node->right = removeIn(node->right, val);
    else if(val < node->key) node->left = removeIn(node->left, val);
    else{
      Node* l = node->left;
      Node* r = node->right;
      if(!l or !r) {
        delete node;
        return l ? l : r;
      }
      Node* mn = findMin(r);
      int val = mn->key;
      removeIn(node, val);
      node->key = val;
    }
    return rebalance(node);
  }

  void deleteNode(Node* node){
    if(node == nullptr) return;
    deleteNode(node->left);
    deleteNode(node->right);
    delete node;
  }

  bool searchIn(Node* node, int val){
    if(node == nullptr) return false;
    if(node->key == val) return true;
    if(val > node->key) return searchIn(node->right, val);
    return searchIn(node->left, val);
  }

  public:
    AVL() : root(nullptr) {}
    ~AVL() { deleteNode(root); }
    void insert(int val){ root = insertIn(root, val); }
    void remove(int val){ root = removeIn(root, val); }
    bool search(int val){ return searchIn(root, val); }
    void print() {
      if(root == nullptr) return;
      cout << "Tree:" << endl;
      queue<pair<Node*, int>> q;
      int h = 0;
      q.push({root, h});
      while(q.size()){
        Node* first = q.front().first;
        if(h != q.front().second) cout << endl;
        h = q.front().second;
        q.pop();
        cout << first->key << " ";
        if(first->left)  q.push({first->left, h+1});
        if(first->right) q.push({first->right, h+1});
      }
      cout << "\n\n";
    }
};

int main(){
  int esc, val;
  AVL A;
  while(1){
    cout << "Select Operation:" << endl;
    cout << "1 - Insert" << endl;
    cout << "2 - Remove" << endl;
    cout << "3 - Search" << endl;
    cout << "4 - Print" << endl;
    cout << "Other - Close Program" << endl;
    cin >> esc;
    if(esc == 1) cin >> val, A.insert(val);
    else if(esc == 2) cin >> val, A.remove(val);
    else if(esc == 3) cin >> val, cout << (A.search(val) ? "Found" : "Not found") << endl;
    else if(esc == 4) A.print();
    else return cout << "Closing . . . " << endl, 0;
  }
}
