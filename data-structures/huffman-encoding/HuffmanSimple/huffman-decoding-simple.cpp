#include <bits/stdc++.h>
using namespace std;

#define notcare '\0' 

typedef uint8_t byte;

map<char, int> freq;

struct Node {
  char value;
  int freqNode;
  Node *left, *right;
  Node(char a) : value(a), left(nullptr), right(nullptr), freqNode(freq[a]) {}
};

bool cmp (Node* a, Node* b) { return a->freqNode > b->freqNode; }

int main(int argc, char** argv){

  //Open File Verification  
  if(argc < 2){
    printf("Error!\n");
    printf("Use: %s <file>\n", argv[0]);
    return -1;
  }

  FILE *pFile = fopen(argv[1], "r");
  if(!pFile){
    printf("Error!\n");
    printf("Could not open file %s\n", argv[1]);
    return -1;
  }
 
  //Retrieving Information from File
  int tam, n, a;
  char l;
  vector<char> lett;
  vector<int> occur;
  
  fscanf(pFile, "%d", &tam);
  //endline
  fscanf(pFile, "%c", &l);
  for(int i = 0; i < tam; i++) fscanf(pFile, "%c", &l), lett.push_back(l);
  //endline
  fscanf(pFile, "%c", &l);
  for(int i = 0; i < tam; i++) fscanf(pFile, "%d", &a), occur.push_back(a);
  for(int i = 0; i < tam; i++) freq[lett[i]] = occur[i];
  fscanf(pFile, "%d", &n);
  vector<bool> out;
  for(int i = 0; i < n; i++) fscanf(pFile, "%d", &a), out.push_back(a);
  fclose(pFile);
  
  //Recreating Huffman Tree
  priority_queue<Node*, vector<Node*>, decltype(&cmp)> pq(cmp);
  for(auto x : freq) pq.push(new Node(x.first));

  while(pq.size() >= 2){
    Node* left = pq.top(); pq.pop();
    Node* right = pq.top(); pq.pop();
    Node* parent = new Node(notcare);
    parent -> left = left;
    parent -> right = right;
    parent -> freqNode = left->freqNode + right->freqNode;
    pq.push(parent);
  }

  string outName = string(argv[1]) + "-decompressed";
  FILE *outFile = fopen(outName.c_str(), "w+");
  Node *ptr = pq.top();
  for(auto x : out){
    if(!(ptr->left) and !(ptr->right)) {
      fprintf(outFile, "%c", ptr->value);
      ptr = pq.top();
    }
    ptr = x ? ptr->right : ptr->left;
  }
  fprintf(outFile, "\n");
  fclose(outFile);
}
