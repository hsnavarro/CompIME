package Ex2;

import java.io.IOException;
import java.util.Scanner;

public class Usuario {
    public static void main (String[] args) throws IOException {
        Scanner input = new Scanner(System.in);
        Factory acesso = new Factory();
        Documento resposta = null;
        System.out.println("Forneça a senha:");
        if(input.hasNextLine()) {
            String in = input.nextLine();
            resposta = acesso.darAcesso(in);
        }
    }
}
