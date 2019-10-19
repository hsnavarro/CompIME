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
char msg[MAX_SIZE], msg2[MAX_SIZE];
string in;
struct sockaddr_in servaddr1, servaddr2; 
int len1 = sizeof(servaddr1), len2 = sizeof(servaddr2);

bool verify(string tel){
  int cond = 0;
  for(auto x : tel) if(x >= '0' and x <= '9') cond = 1;
  return cond;
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
      string name, tel;
      cout << "Enter name:" << endl;
      cin >> name;
      if(name[0] != '#'){
        cout << "Enter tel:" << endl;
        cin >> tel;
      }
      if(name[0] != '#' and !verify(tel)){
        cout << "This isn't a valid input!" << endl;
        continue;
      }
      in = name + " " + tel;
      strcpy(msg, in.c_str());
      
      sendto(sockfd, (char*) msg, MAX_SIZE, 0, (struct sockaddr*) &servaddr1, len1);
      sendto(sockfd, (char*) msg, MAX_SIZE, 0, (struct sockaddr*) &servaddr2, len2);
      
      if(msg[0] == '#') break;

      recvfrom(sockfd, (char*) msg, MAX_SIZE, 0, (struct sockaddr*) &servaddr1, (socklen_t *) &len1);
      recvfrom(sockfd, (char*) msg2, MAX_SIZE, 0, (struct sockaddr*) &servaddr2, (socklen_t *) &len2);
      
      string aux1(msg), aux2(msg2);
      cout << aux1 << endl;
      cout << aux2 << endl;
    }

    close(sockfd); 
    return 0; 
} 
