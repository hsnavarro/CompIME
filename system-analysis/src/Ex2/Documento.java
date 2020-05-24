package Ex2;

import java.io.File;
import java.io.IOException;
import java.util.Scanner;

public abstract class Documento {
    public void abrir (String fileName) throws IOException {
        File file = new File("/home/hsnavarro/Documents/CompIME/system-analysis/src/Ex2/" + fileName);
        Scanner scanner = new Scanner(file);
        while(scanner.hasNextLine()) {
            System.out.println(scanner.nextLine());
        }
    }
}

