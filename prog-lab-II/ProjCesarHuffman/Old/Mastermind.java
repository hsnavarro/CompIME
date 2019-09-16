import java.util.Scanner;

public class Mastermind {
    public final int NrTentativas = 10, DigitosPossiveis = 6;
    public int jogada[], vez;
    public boolean vitoria;
    public int posicaoCorreta[], posicaoErrada[];
    public int[] solucao;
    public Scanner leitura = new Scanner(System.in);

    public void vezJogador(int step){
        do {
            System.out.print("Vez " + vez + ": Entre com a sua sugestão:");
            jogada[step] = leitura.nextInt();
            if(jogada[step] == 0){
                System.exit(0);
            }
        } while(!verificaEntrada(converteRespostaRecebida(jogada[step]), "Entrada Inválida"));
        return;
    }

    public void verificaResposta(int[] ans){
        boolean[] estaPosicaoCorreta = new boolean[4];
        boolean[] estaPosicaoIncorreta = new boolean[4];
        boolean[] estaPosicaoEstaCorreta = new boolean[4];

        for(int i = 0; i < ans.length; i++){
            if(ans[i] == solucao[i]){
                estaPosicaoCorreta[i] = true;
                posicaoCorreta[vez-1]++; // Q 03
                estaPosicaoEstaCorreta[i] = true;
            }
        }

        for(int i = 0; i < ans.length; i++){
            for(int j = 0; j < ans.length; j++){
                if((ans[i] == solucao[j]) && (!estaPosicaoEstaCorreta[j]) && (!estaPosicaoCorreta[i]) &&
                        (!estaPosicaoIncorreta[i])){
                    estaPosicaoIncorreta[i] = true;
                    posicaoErrada[vez-1]++; // Q 04
                    estaPosicaoEstaCorreta[j] = true;

                }
            }
        }

        if(posicaoCorreta[vez - 1] == 4){
            vitoria = true;
        }
        return;
    }

    public void exibirResultados(){
        for(int i = 1; i <= vez; i++){
            System.out.println("Tentativa " + i + ": " + jogada[i-1] + " Pretas:" + posicaoCorreta[i-1] + " Brancas:" +
                    posicaoErrada[i-1]);
        }
        if(!vitoria){
            System.out.println("=========================\n\n");
        }
        vez++;
        return;
    }

    public boolean fimJogo() {
        int userCon;
        if(vitoria){
            System.out.println("Você venceu!");
        } else {
            System.out.println("Você perdeu! A resposta certa é " + solucao[0] + solucao[1] + solucao[2] + solucao[3]);
        }
        do {
            System.out.print("Você deseja continuar (0-Sim / 1-Não) ?");
            userCon = leitura.nextInt();
        } while (!verificaEntrada(userCon, "Por favor entre com 0 ou 1 (0-Sim / 1-Não)!"));
        if(userCon == 0){ // Q 05
            return true;
        } else {
            return false;
        }
    }

    public int[] converteRespostaRecebida(int ansRecieved){
        int ans[] = new int[4];
        ans[0] = ansRecieved / 1000;
        ans[1] = ansRecieved % 1000 / 100;
        ans[2] = ansRecieved % 1000 % 100 / 10;
        ans[3] = ansRecieved % 1000 % 100 % 10; // Q 06
        return ans;
    }

    public void configuraValoresIniciais(){
        jogada = new int[NrTentativas];
        posicaoCorreta = new int[NrTentativas];
        posicaoErrada = new int[NrTentativas];
        solucao = new int[4];
        vez = 1; // Q 07
        vitoria = false;
    }

    public boolean verificaEntrada(int[] ansRecieved, String errorMessage) { // Q 08
        for(int i = 0; i < ansRecieved.length; i++){
            if(ansRecieved[i] < 1 || ansRecieved[i] > DigitosPossiveis) {
                System.out.println(errorMessage);
                return false;
            }
        }
        return true; // Q 09
    }

    public static boolean verificaEntrada(int numRecieved, String errorMessage){
        if(numRecieved != 0 && numRecieved != 1){
            System.out.println(errorMessage);
            return false;
        } else { // Q 10
            return true;
        }
    }
}
