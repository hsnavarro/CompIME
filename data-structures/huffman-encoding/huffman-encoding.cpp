#include <bits/stdc++.h>
using namespace std;

#define notcare '\0' 

typedef uint8_t byte;

map<char, int> freq;
map<char, vector<bool>> encode;

struct Node {
  char value;
  int freqNode;
  Node *left, *right;
  Node(char a) : value(a), left(nullptr), right(nullptr), freqNode(freq[a]) {}
};

void print(int &n, int size, byte *in, string &name, map<char, int> &freq){
  FILE *pFile = fopen(name.c_str(), "wb");
  vector<char> letter;
  vector<int> occur;
  for(auto x : freq) if(x.second) letter.push_back(x.first), occur.push_back(x.second);
  int freqSize = letter.size();
  fwrite(&freqSize, sizeof(int), 1, pFile);
  fwrite(&letter[0], sizeof(char), freqSize*sizeof(char), pFile);
  fwrite(&occur[0], sizeof(int), freqSize*sizeof(int), pFile);
  fwrite(&n, sizeof(int), 1, pFile);
  fwrite(in, sizeof(byte), size*sizeof(byte), pFile);
  fclose(pFile);
}

bool cmp (Node* a, Node* b) { return a->freqNode > b->freqNode; }

void findCode(Node* root, vector<bool> &res){
  if(!root) return;
  if(!(root->left) and !(root->right)) encode[root->value] = res;
  res.push_back(false), findCode(root->left, res), res.pop_back();
  res.push_back(true), findCode(root->right, res), res.pop_back();
}

int main(int argc, char** argv){

    //Open File Verifications
    if(argc < 2){
      printf("Error!\n");
      printf("Use: %s <file>\n", argv[0]);
      return -1;
    }

    FILE *inFile = fopen(argv[1], "r");
    if(!inFile){
      printf("Error!\n");
      printf("Could not open file %s\n", argv[1]);
      return -1;
    }
    
    //Creating Huffman Tree
    char letter;
    while((letter = fgetc(inFile)) != EOF) freq[letter]++;
    fclose(inFile);
  
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

    //Getting binary representation of the characters
    Node* root = pq.top();
    vector<bool> res;
    findCode(root, res);
 
    
    //Characters Encoding
    for(auto x : encode){
      cout << "character: " << x.first << endl;
      for(auto z : x.second) cout << z;
      cout << endl;
    }
    
    //Creating output file
    string outName = string(argv[1]) + "-compressed";
    
    vector<bool> message;
    inFile = fopen(argv[1], "r");
    while((letter = fgetc(inFile)) != EOF){
      vector<bool> in = encode[letter];
      for(auto x : in) message.push_back(x);
    }
    fclose(inFile);

    int n = message.size();
    message.resize((n+7)/8 * 8);
    vector<byte> inp;

    for(int i = 0; i < message.size(); i += 8){
      byte aux = 0;
      for(int j = i; j < i + 8; j++) if(message[j]) aux += (1 << (7 - j + i));
      inp.push_back(aux);
    }
 
    
    //For debugging
    cout << n << endl;
    cout << freq.size() << endl;
    /*
    int idx = 0;
    for(auto x : message) {
      cout << x;
      idx++;
      if(idx == 8) cout << " ", idx = 0;
    }
    cout << endl;
    */
    

    print(n, inp.size(), &inp[0], outName, freq); 
    inp.clear(), message.clear();
}
