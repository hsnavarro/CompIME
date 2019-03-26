#include <bits/stdc++.h>
using namespace std;

class node{
  public:
    int val;
    node* next;
    node(int val) : val(val) {}
};

class linkedList{
  public:
    node* start;

    linkedList() : start(nullptr) {}
    ~linkedList(){
      while(start != nullptr){
        node* aux = start -> next;
        delete start;
        start = aux;
      }
    }

    void insert(int val){
      node* newNode = new node(val);
      newNode -> next = start;
      start = newNode;
    }

    bool search(int val){
      node* iterator = start;
      for(; iterator != nullptr; iterator = iterator -> next){
        if(iterator -> val == val) return true;
      }
      return false;
    }

    void remove(int val){
      node* iterator = start;
      node* prev = nullptr;
      for(; iterator != nullptr; prev = iterator, iterator = iterator -> next){
        if(iterator -> val == val) break;
      }
      if(prev == nullptr) start = iterator -> next;
      else prev -> next = iterator -> next;
      
      delete iterator;
    }

    void print(){
      node *iterator = start;
      for(; iterator != nullptr; iterator = iterator -> next) cout << iterator -> val << " ";
      cout << endl;
    }
};

int main(){
  linkedList A;
  A.insert(1);
  A.insert(2);
  A.insert(5);
  cout << A.search(5) << endl;
  A.print();
  A.remove(2);
  cout << A.search(2) << endl;
  A.print();
}
