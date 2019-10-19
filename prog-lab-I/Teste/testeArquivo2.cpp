#include <bits/stdc++.h>
using namespace std;

int main(){
  streambuf *ptr;
  ofstream arq("saida.txt");
  ptr = arq.rdbuf();
  cout.rdbuf(ptr);
  cout << "oi" << endl;
  cout << "teste" << endl;
}
