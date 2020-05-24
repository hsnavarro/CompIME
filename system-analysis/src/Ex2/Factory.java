package Ex2;

import java.io.IOException;

public class Factory {
    public Documento darAcesso(String senha) throws IOException {
        if(senha.equals("euseiasenha")) return new Secreto();
        return new Publico();
    }
}
