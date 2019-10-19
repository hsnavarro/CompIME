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
string in;
struct sockaddr_in servaddr; 
int len = sizeof(servaddr);

int main() { 
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
  
    memset(&servaddr, 0, sizeof(servaddr));
      
    servaddr.sin_family = AF_INET; 
    servaddr.sin_port = htons(PORT1); 
    servaddr.sin_addr.s_addr = INADDR_ANY; 
      
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
      bool op = signal(in);
      
      sendto(sockfd, (char*) msg, MAX_SIZE, 0, (struct sockaddr*) &servaddr, len);
      
      if(msg[0] == '#') break;

      recvfrom(sockfd, (char*) msg, MAX_SIZE, 0, (struct sockaddr*) &servaddr1, (socklen_t *) &len1);
      
      string aux1(msg), aux2(msg2);
      cout << aux1 << endl;
      cout << aux2 << endl;
    }

    close(sockfd); 
    return 0; 
} 
