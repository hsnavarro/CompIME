#include <bits/stdc++.h>
#include <unistd.h> 
#include <sys/types.h> 
#include <sys/socket.h> 
#include <arpa/inet.h> 
#include <netinet/in.h> 
using namespace std;
  
#define PORT 8080 
#define MAX_SIZE 100

int sockfd;
char msg[MAX_SIZE];
string login = "280d44ab1e9f79b5cce2dd4f58f5fe91f0fbacdac9f7447dffc318ceb79f2d02";
string logout = "b49f425a7e1f9cff3856329ada223f2f9d368f15a00cf48df16ca95986137fe8";
struct sockaddr_in servaddr, cliaddr; 
int len = sizeof(cliaddr);

set<sockaddr_in> clients;
map<sockaddr_in, string> name;

bool operator< (sockaddr_in a, sockaddr_in b){
  return a.sin_addr.s_addr < b.sin_addr.s_addr;
}

bool operator== (sockaddr_in a, sockaddr_in b){
  return a.sin_addr.s_addr == b.sin_addr.s_addr;
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
      string aux(msg);
      if(aux == logout) {
        clients.erase(cliaddr);
        continue;
      }
      if(aux == login) {
        clients.insert(cliaddr);
        continue;
      }
      
      cout << "Received message: " << aux << endl;
      
      for(auto &x : clients){
        if(x == cliaddr) continue;
        sendto(sockfd, msg, MAX_SIZE, 0, (struct sockaddr*) &x, sizeof(x)); 
        cout << "Sended" << endl;
      }
    }
    close(sockfd);
    return 0; 
}
