// Grupo: Gabriel Bozza, Navarro e Ricardo Silveira

#include <bits/stdc++.h>
using namespace std;

const int tempoLimiteQ1 = 30, tempoIO = 20, quantum = 10;

struct Processo {
  int id, surtoCPU, operacoes_io, tempo_executando, tempo_saida_io, tempo_fila;

  Processo(int id, int surtoCPU, int operacoes_io) : id(id), surtoCPU(surtoCPU), operacoes_io(operacoes_io), tempo_executando(0), tempo_saida_io(-1), 
    tempo_fila(0) {};
};

vector<Processo> q0, q1, IO;
int tempoAtual, totalProcessos, surtoCPU, operacoes_io;;

// diagrama[i] indica o programa que está sendo executado do tempo i até i+1 (0 se não houver processo executando naquele momento);
vector<int> diagrama;

void executarProcesso(int numeroFila) {
  Processo &p = numeroFila ? q1[0] : q0[0];
  p.tempo_executando++;
  numeroFila ? p.tempo_fila = -1 : p.tempo_fila++;
  diagrama.push_back(p.id);

  if(p.tempo_executando == p.surtoCPU) {
    if(p.operacoes_io) {
      p.operacoes_io--;
      p.tempo_executando = 0;
      p.tempo_fila = 0;
      int tempo_saida = tempoIO + (IO.size() ? IO.back().tempo_saida_io : tempoAtual);
      p.tempo_saida_io = tempo_saida;
      IO.push_back(p);
    }
    numeroFila ? q1.erase(q1.begin()) : q0.erase(q0.begin());
    return;
  }

  if(!numeroFila and p.tempo_fila == quantum) {
    p.tempo_fila = -1;
    q1.push_back(p);
    q0.erase(q0.begin());
  }
}

int main() {
  // pegando input
  cout << "No de processos: ";
  cin >> totalProcessos;
  for(int i = 1; i <= totalProcessos; i++) {
    cout << "Processo P" << i-1 << " (Burst de CPU, No de E/S): "; 
    cin >> surtoCPU >> operacoes_io;
    Processo novoProcesso = Processo(i, surtoCPU, operacoes_io);
    q0.push_back(novoProcesso);
  }

  while(q0.size() or q1.size() or IO.size()) {
    // executando processo
    if(q0.size()) executarProcesso(0);
    else if(q1.size()) executarProcesso(1);
    else diagrama.push_back(0);

    // conferindo se processo acabou IO
    if(IO.size() and tempoAtual == IO[0].tempo_saida_io) {
      IO[0].tempo_saida_io = -1;
      q0.push_back(IO[0]);
      IO.erase(IO.begin());
    }

    // conferindo se o processo está 30 ms na fila q1 (será passado para q0)
    vector<Processo> mantido;

    for(auto &processoQ1 : q1) {
      processoQ1.tempo_fila++;
      if(processoQ1.tempo_fila == tempoLimiteQ1) {
        processoQ1.tempo_fila = 0;
        q0.push_back(processoQ1);
      } else mantido.push_back(processoQ1);
    }

    q1 = mantido;

    tempoAtual++;
  }

  // printando diagrama
  cout << "Tempo\tProcesso" << endl;

  for(int i = 0; i <= diagrama.size(); i++) {
    if(!i or i == diagrama.size() or diagrama[i] != diagrama[i-1]) {
      if(i == diagrama.size()) cout << i << "\tFinalizado";
      else if(diagrama[i]) cout << i << "\t" << diagrama[i]-1;
      else cout << i << "\tNenhum processo";
      cout << endl;
    }
  }
}
