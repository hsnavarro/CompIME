#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;
const int INF = 0x3f3f3f3f;

struct Heap{
// Max - Heap
// Could be easily transformed into a Min Heap
  int last = 1, heap[N];

  Heap() {
    // INF for min heap
    memset(heap, -INF, sizeof heap);
  }
  void push(int x){
    if(last == N) return;
    heap[last] = x;
    int pos = last++;
    while(pos/2 and heap[pos] > heap[pos/2]) 
      swap(heap[pos], heap[pos/2]), pos /= 2; 
  }

  void pop(){
    if(last == 1) return;
    last--;
    swap(heap[1], heap[last]);
    // INF for min heap
    heap[last] = -INF;
    int idx = 1;
    int great = heap[2*idx] > heap[2*idx + 1] ? 2*idx : 2*idx+1;
    while(heap[great] > heap[idx]){
      swap(heap[great], heap[idx]);
      idx = great;
      great = heap[2*idx] > heap[2*idx + 1] ? 2*idx : 2*idx+1;
    }
  }

  int top(){ return heap[1]; }

  void print2(){
    for(int i = 1; i < last; i++) cout << heap[i] << " ";
    cout << endl;
  }

  void print(){
    if(last == 1) return;
    int h = 0, idx = 1;
    queue<pair<int, int>> q;
    q.push({idx, h});
    while(q.size()){
      idx = q.front().first;
      if(q.front().second != h) cout << endl;
      cout << heap[idx] << " ";
      h = q.front().second;
      q.pop();
      if(2*idx < last) q.push({2*idx, h+1});
      if(2*idx + 1 < last) q.push({2*idx+1, h+1});
    }
    cout << endl << endl;
  }
};

int main(){
  Heap A;
  A.push(-2), A.push(3), A.push(-4), A.push(7), A.push(1);
  A.print();
  cout << "top: " << A.top() << endl;
  A.pop();
  A.print();
  cout << "top: " << A.top() << endl;
  A.pop();
  A.print();
  cout << "top: " << A.top() << endl;
  A.pop();
  A.print();
  cout << "top: " << A.top() << endl;
  A.pop();
  A.print();
  cout << "top: " << A.top() << endl;
}
