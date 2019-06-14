#include <bits/stdc++.h>
using namespace std;

#define notcare '\0' 

map<char, int> freq;
map<char, vector<bool>> encode;

struct Node {
  char value;
  int freqNode;
  Node *left, *right;
  Node(char a) : value(a), left(nullptr), right(nullptr), freqNode(freq[a]) {}
};

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
 
    /*
    //Characters Encoding
    for(auto x : encode){
      cout << "character: " << x.first << endl;
      for(auto z : x.second) cout << z;
      cout << endl;
    }
    */
    
    //Creating output file
    string outName = string(argv[1]) + "-compressed";
    
    vector<bool> message;
    inFile = fopen(argv[1], "r");
    while((letter = fgetc(inFile)) != EOF){
      vector<bool> in = encode[letter];
      for(auto x : in) message.push_back(x);
    }
    fclose(inFile);
    FILE *outFile = fopen(outName.c_str(), "w");
    vector<int> occur;
    vector<char> lett;
    for(auto x : freq) if(x.second) occur.push_back(x.second), lett.push_back(x.first);
    fprintf(outFile, "%d\n", int(occur.size()));
    for(auto x : lett) fprintf(outFile, "%c", x);
    fprintf(outFile, "\n");
    for(auto x : occur) fprintf(outFile, "%d ", x);
    fprintf(outFile, "\n");
    fprintf(outFile, "%d\n", int(message.size()));
    for(auto x : message) fprintf(outFile, "%d ", int(x));
    fprintf(outFile, "\n");
    fclose(outFile);
    message.clear();
}
