#include<bits/stdc++.h>
using namespace std;

class Node{
  public:
    int val;
    Node* left;
    Node* right;
};

class Tree{
  public:
    Node* root;
  
   void print(Node *root){
     queue<Node*> q;
     cout << root->val << endl;
     q.push(root);
     while(q.size()){
       Node* aux = q.back();
       q.pop();
       cout << aux->val << endl;
       q.push(aux->left);
       q.push(aux->right);
     }
    }
};

int main(){
  


}
