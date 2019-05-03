#include <bits/stdc++.h>
using namespace std;

struct Node{
  int key;
  Node *left, *right;
  Node(int key) : key(key), left(nullptr), right(nullptr) {}
};

struct BST{
  Node* root = nullptr;
  Node* par = nullptr;
  int sz = 0;

  Node* createCompleteBST(vector<int> &v, int l, int r){
    int mid = (l+r+1)/2;
    if(l > r) return nullptr;
    Node* node = new Node (v[mid]);
    node->left = createCompleteBST(v, l, mid-1);
    node->right = createCompleteBST(v, mid+1, r);
    return node;
  }

  void completeBST(vector<int> &v){
    int mid = v.size()/2;
    root = createCompleteBST(v, 0, v.size() - 1);
  }
  
  //returns last visited node 
  pair<Node*, Node*> search(Node* root, int val, Node *par){
    if(root == nullptr) return { nullptr, nullptr };
    if(root->key > val and root->left) return search(root->left, val, root);
    if(root->key < val and root->right) return search(root->right, val, root);
    return {root, par};
  }

  void insert(int val){
    Node* find = search(root, val, par).first;
    if(find and find->key == val) return;
    sz++;
    Node* in = new Node(val);
    if(root == nullptr) { root = in; return; }
    find->key < val ? find->right = in : find->left = in; 
  }

  Node* findCandidates(int val){
    pair<Node*, Node*> find = search(root, val, par);
    return find.first->left ? search(find.first->left, val, find.second).first : search(find.first->right, val, find.second).first;
  }

  void remove(int val){
    if(root == nullptr) return;
    pair<Node*, Node*> aux = search(root, val, par);
    Node* find = aux.first;
    Node* find_par = aux.second;
    if(find and find->key != val) return;
    sz--;
    
    // leaf
    if(find->left == nullptr and find->right == nullptr){
      if(find_par == nullptr) root = nullptr;
      else if(find_par->key < find->key) find_par->right = nullptr;
      else find_par->left = nullptr;
      delete find;
    }

    if(find->left or find->right){
      Node* subs = findCandidates(val);;
      int newkey = subs->key;
      remove(subs->key);
      find->key = newkey;
      if(find_par == nullptr) root->key = newkey;
    }
  }

  // pre order
  void dfs(Node* root){
    cout << root->key << " ";
    if(root->left) dfs(root->left);
    if(root->right) dfs(root->right);
  }

  // symmetrical order
  void sim(Node* root){
    if(root->left) sim(root->left);
    cout << root->key << " ";
    if(root->right) sim(root->right);
  }

  // post order
  void pos(Node* root){ 
    if(root->left) pos(root->left);
    if(root->right) pos(root->right);
    cout << root->key << " ";
  }

  void print(){
    if(root == nullptr) return;
    queue<pair<Node*, int>> q;
    q.push({root, 0});
    int h = 0;
    while(q.size()){
      Node *nxt = q.front().first;
      if(q.front().second != h) h = q.front().second, cout << endl;
      q.pop();
      cout << nxt->key << " ";
      if(nxt->left) q.push({nxt->left, h + 1});
      if(nxt->right) q.push({nxt->right, h + 1});
    }
    cout << endl;
  }
};

int main(){
  BST a;
  vector<int> v = {1, 2, 3, 4, 5, 6};
  a.completeBST(v);
  a.print();
  a.remove(4);
  a.print();
}
