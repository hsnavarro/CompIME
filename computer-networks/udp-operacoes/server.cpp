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
struct sockaddr_in servaddr, cliaddr; 
int len = sizeof(cliaddr);

string process(string in){
  int sum = 0;
  int last_op = 1;
  string last_number;
  for(auto x : in){
    if(x == '-' or x == '+'){
      if(last_number.size()) sum += last_op*stoi(last_number);
      last_op = (x == '-') ? -1 : 1;
      last_number.clear();
    } else if(x >= '0' and x <= '9') last_number += x;
  }
  if(last_number.size()) sum += last_op*stoi(last_number);
  return to_string(sum);
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
      cout << "Calculating..." << endl;
      string ans = process(aux);
      cout << "The result is: " << ans << endl;
      strcpy(msg, ans.c_str());
      cout << "Sending..." << endl;
      sendto(sockfd, (char*) msg,  MAX_SIZE, 0, (struct sockaddr*) &cliaddr, len); 
      cout << "Sended" << endl;
    }
    close(sockfd);
    return 0; 
}
