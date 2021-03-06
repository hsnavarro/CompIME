#include "server.h"
#include <bits/stdc++.h>
using namespace std;

#define PORT 8000
#define MAXSZ 100

struct sockaddr_in serverAddress;
struct sockaddr_in clientAddress;

unsigned int clientLength;

char msg[MAXSZ];
char grid[3][3];

bool turn = true;
int lin, col;

void init() {
  for(int i = 0; i < 3; i++)
    for(int j = 0; j < 3; j++) grid[i][j] = ' ';
}

bool check_win(int isServer){
  for(int i = 0; i < 3; i++){
    int sum = 0;
    for(int j = 0; j < 3; j++) if(grid[i][j] == (isServer ? 'X' : 'O')) sum++;
    if(sum == 3) return true;
  }
  
  for(int j = 0; j < 3; j++){
    int sum = 0;
    for(int i = 0; i < 3; i++) if(grid[i][j] == (isServer ? 'X' : 'O')) sum++;
    if(sum == 3) return true;
  }

  char x = (isServer ? 'X' : 'O');
  if(grid[0][0] == x and grid[1][1] == x and grid[2][2] == x) return true;
  if(grid[0][2] == x and grid[1][1] == x and grid[2][0] == x) return true;
  return false;


  /*
  int line[3] = {0}, col[3] = {0}, dig[2] = {0};
  for(int i = 0; i < 3; i++)
    for(int j = 0; j < 3; j++){
      if(grid[i][j] != (isClient ? 'O' : 'X')) continue;
      line[i] += (1 << j), col[j] += (1 << i);
      if(i == j) dig[0] += (1 << i);
      if(i != j and i + j == 2) dig[1] += (1 << i);
    }

  for(int i = 0; i < 3; i++){
    if(line[i] == 7 or col[i] == 7) return true;
    if(i < 2 and dig[i] == 7) return true;
  }
  return false;
  */
} 

bool check_full(){
  for(int i = 0; i < 3; i++)
    for(int j = 0; j < 3; j++) if(grid[i][j] == ' ') return false;
  return true;
}

void fill(){
  memset(&serverAddress,0,sizeof(serverAddress));
  serverAddress.sin_family=AF_INET;
  serverAddress.sin_addr.s_addr=htonl(INADDR_ANY);
  serverAddress.sin_port=htons(PORT);
}

bool verify_input(int l, int c){
  if(l < 1 or l > 3 or c < 1 or c > 3) {
    printf("Fora do limite do grid\n");
    return false;
  }
  if(grid[l-1][c-1] == 'X' or grid[l-1][c-1] == 'O'){
    printf("Posição já ocupada\n");
    return false;
  }
  return true;
}

void play(int l, int c){
  grid[l-1][c-1] = 'X';
}

void play(string s){
  string l, c;
  int cond = 0;
  for(auto x : s){
    if(x == ' ') {
      cond = 1;
      continue;
    }
    cond ? c += x : l += x;
  }
  int line = stoi(l), col = stoi(c);
  grid[line-1][col-1] = 'O';
}

void print(){
  printf("\t %c | %c | %c\n", grid[0][0], grid[0][1], grid[0][2]);
  printf("\t-----------\n");
  printf("\t %c | %c | %c\n", grid[1][0], grid[1][1], grid[1][2]);
  printf("\t-----------\n");
  printf("\t %c | %c | %c\n", grid[2][0], grid[2][1], grid[2][2]);
}

int main() {
  int sock_server = socket(AF_INET,SOCK_STREAM,0);

  fill();
  init();

  bind(sock_server,(struct sockaddr*) &serverAddress, sizeof(serverAddress));
  listen(sock_server, 1);

  printf("Esperando o outro jogador ");
  fflush(stdout);
  sleep(1);
  printf(" . ");
  fflush(stdout);
  sleep(1);
  printf(" . ");
  fflush(stdout);
  sleep(1);
  printf(" . \n");


  memset(&clientAddress, 0, sizeof(clientAddress));
  clientLength = sizeof(clientAddress);

  int cl = accept(sock_server, (struct sockaddr*) &clientAddress, &clientLength);

  printf("Jogador conectado\n");
  printf("A partida irá começar\n");
  
  while(1){
    printf("Sua vez\n");
    print();
    printf("Forneça a jogada (linha, coluna)\n");
    do{
      scanf("%d%d", &lin, &col);
    } while(!verify_input(lin, col));
    play(lin, col);
    string s = to_string(lin) + " " + to_string(col);
    strcpy(msg, s.c_str());
    send(cl, msg, MAXSZ, 0);
    if(check_win(1) or check_full()){
      print();
      if(check_win(1)) printf("Você ganhou\n");
      else if(check_full()) printf("Empatou\n");
      printf("Finalizando o jogo\n");
      break;
    }
    printf("Vez do outro jogador\n");
    recv(cl, msg, MAXSZ, 0);
    string aux(msg);
    play(aux);
    if(check_win(0) or check_full()){
      print();
      if(check_win(0)) printf("Você perdeu\n");
      else if(check_full()) printf("Empatou\n");
      printf("Finalizando o jogo\n");
      break;
    }
  } 
  close(cl);
  close(sock_server);
}
