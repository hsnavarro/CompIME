#include <bits/stdc++.h>
#include <unistd.h> 
#include <sys/types.h> 
#include <sys/socket.h> 
#include <arpa/inet.h> 
#include <netinet/in.h> 
using namespace std;
  
#define PORT1 8080
#define PORT2 8081
#define MAX_SIZE 100
  
int sockfd;
char msg[MAX_SIZE];
string in;
struct sockaddr_in servaddr1, servaddr2; 
int len1 = sizeof(servaddr1), len2 = sizeof(servaddr2);

// + -> goes to server 1
// - -> goes to server 2 

bool signal(string in) {
  for(auto x : in) if(x == '+') return 1;
  return 0;
}

int main() { 
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
  
    memset(&servaddr1, 0, sizeof(servaddr1));
    memset(&servaddr2, 0, sizeof(servaddr2));
      
    servaddr1.sin_family = AF_INET; 
    servaddr1.sin_port = htons(PORT1); 
    servaddr1.sin_addr.s_addr = INADDR_ANY; 
      
    servaddr2.sin_family = AF_INET; 
    servaddr2.sin_port = htons(PORT2); 
    servaddr2.sin_addr.s_addr = INADDR_ANY; 
      
    while(1){
      cout << "Enter algebric expression:" << endl;
      getline(cin, in);
      strcpy(msg, in.c_str());
      bool op = signal(in);
      if(msg[0] == '#'){  
        sendto(sockfd, (char*) msg, MAX_SIZE, 0, (struct sockaddr*) &servaddr1, len1); 
        sendto(sockfd, (char*) msg, MAX_SIZE, 0, (struct sockaddr*) &servaddr2, len2);
        break;
      }
      if(op) sendto(sockfd, (char*) msg, MAX_SIZE, 0, (struct sockaddr*) &servaddr1, len1);
      else sendto(sockfd, (char*) msg, MAX_SIZE, 0, (struct sockaddr*) &servaddr2, len2);
      if(op) recvfrom(sockfd, (char*) msg, MAX_SIZE, 0, (struct sockaddr*) &servaddr1, (socklen_t *) &len1);
      else recvfrom(sockfd, (char*) msg, MAX_SIZE, 0, (struct sockaddr*) &servaddr2, (socklen_t *) &len2);
      string aux(msg);
      cout << "Result: " << aux << endl;
    }

    close(sockfd); 
    return 0; 
} 
