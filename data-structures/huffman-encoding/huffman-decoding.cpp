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

  FILE *pFile = fopen(argv[1], "rb");
  if(!pFile){
    printf("Error!\n");
    printf("Could not open file %s\n", argv[1]);
    return -1;
  }
 
  cout << "Conseguiu abrir" << endl;
  //Retrieving Information from File
  int n, tam;
  fread(&tam, sizeof(int), 1, pFile);
  char *letter = (char*) malloc(tam*sizeof(char));
  int *occur = (int*) malloc(tam*sizeof(int));
  fread(letter, sizeof(char), tam*sizeof(char), pFile);
  fread(occur, sizeof(int), tam*sizeof(int), pFile);
  for(int i = 0; i < tam; i++) freq[letter[i]] = occur[i];
  fread(&n, sizeof(int), 1, pFile);
  byte *msg = (byte*) malloc(((n+7)/8)*sizeof(byte));
  cout << "conseguiu alocar" << endl;
  fread(msg, sizeof(byte), ((n+7)/8)*sizeof(byte), pFile);
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

  //Decode
  int aux = n;
  vector<bool> out;
  for(int i = 0; i < ((n+7)/8); i++) {
    for(int j = 0; j < min(8, aux); j++) ((1 << (7 - j)) & msg[i]) ? out.push_back(true) : out.push_back(false);
    aux -= 8;
  }
  
  /*
  // For debugging
  idx = 0;
  for(auto x : out) {
    cout << x;
    idx++;
    if(idx == 8) cout << " ", idx = 0;
  }
  cout << endl;
  */
  
  string outName = string(argv[1]) + "-decompressed";
  //FILE *outFile = fopen(outName.c_str(), "w+");
  Node *ptr = pq.top();
  for(auto x : out){
    if(!(ptr->left) and !(ptr->right)) {
      printf("%c", ptr->value);
      //fprintf(outFile, "%c", aux);
      ptr = pq.top();
    }
    ptr = x ? ptr->right : ptr->left;
  }
  printf("\n");
  //fprintf(outFile, "\n");
  //fclose(outFile);
}
