package Ex2;

import java.io.IOException;

public class Secreto extends Documento {
    public Secreto() throws IOException {
        abrir("confidencial.txt");
    }
}
