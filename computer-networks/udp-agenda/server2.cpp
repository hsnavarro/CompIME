#include <bits/stdc++.h>
#include <unistd.h> 
#include <sys/types.h> 
#include <sys/socket.h> 
#include <arpa/inet.h> 
#include <netinet/in.h> 
using namespace std;
  
#define PORT 8081
#define MAX_SIZE 100

int sockfd;
char msg[MAX_SIZE];
string ok = "Server 2 updated successfully";
struct sockaddr_in servaddr, cliaddr; 
int len = sizeof(cliaddr);
map<string, string> tel_of;
string name, tel;

void take_input(string in){
  name.clear(), tel.clear();
  int cond = 0;
  for(auto x : in){
    if(x == ' ') { cond = 1; continue; }
    cond ? tel += x : name += x;
  }
}

void assemble(){
  tel_of.clear();
  ifstream readFile("agenda2");
  string name, tel;
  while(readFile >> name >> tel){
    tel_of[name] = tel;
  }
  readFile.close();
}

void update(){
  ofstream writeFile("agenda2");
  for(auto x : tel_of){
    writeFile << x.first << " " << x.second << endl;
  }
  writeFile.close();
}


int main() {
    sockfd = socket(AF_INET, SOCK_DGRAM, 0); 
      
    memset(&servaddr, 0, sizeof(servaddr)); 
    memset(&cliaddr, 0, sizeof(cliaddr)); 
      
    servaddr.sin_family = AF_INET; 
    servaddr.sin_addr.s_addr = INADDR_ANY; 
    servaddr.sin_port = htons(PORT); 
      
    bind(sockfd, (const struct sockaddr *)&servaddr, sizeof(servaddr)); 
      
    while(1){
      recvfrom(sockfd, (char*) msg, MAX_SIZE,  0, (struct sockaddr*) &cliaddr, (socklen_t *) &len);
      if(msg[0] == '#') break;
      string aux(msg);
      cout << "Received request: " << aux << endl;
      cout << "Processing..." << endl;
      take_input(aux);
      assemble();
      tel_of[name] = tel;
      update();
      cout << "Updated" << endl;
      sendto(sockfd, ok.c_str(), ok.size(), 0, (struct sockaddr*) &cliaddr, len); 
      cout << "Sended" << endl;
    }
    close(sockfd);
    return 0; 
}
