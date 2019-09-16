package cesarHuffman;

import criptografia.*;

import java.io.FileOutputStream;
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;

public class CesarHuffman {
    public CesarHuffman() {
    }

    public static void main(String[] args) throws IOException {
        // Only work for characters from 'a' to 'z' and 'A' to 'Z'
        BufferedReader buffRead = new BufferedReader(new FileReader("/home/hsnavarro/IdeaProjects/Aula 1/src/input"));
        FileOutputStream output = new FileOutputStream("src/output", true);
        String s = "";
        s = buffRead.readLine().toLowerCase();
        System.out.println(s);
        CifraCesar c = new CifraCesar(0, s, true);
        c.getInfo();
        int[] freq = new int[26];
        for (int i = 0; i < 26; ++i) freq[i] = 0;
        for (int i = 0; i < c.criptografada.length(); i++) {
            freq[c.criptografada.charAt(i) - 97]++;
        }
        Huffman h = new Huffman(freq, c.criptografada);
        h.printHuffman();
        h.descriptografiaHuffman();
        System.out.println("huffman: " + h.descriptoHuffman);
        CifraCesar d = new CifraCesar(h.criptoAnalisis(), h.descriptoHuffman, false);

        System.out.println(d.descriptografada);
        System.out.println(d.descriptografada);

        System.out.println("Comparando:");
        System.out.println("Antes da compressão:" + s.length());

        byte inp = 0;
        int cnt = 0;
        for (int i = 0; i < h.criptografada.length(); i++) {
            int idx = i % 8;
            if (h.criptografada.charAt(i) == '1') inp += (1 << (7 - idx));
            if (idx == 7) {
                cnt++;
                output.write(inp);
                inp = 0;
            }
        }
        if(h.criptografada.length() % 8 != 0){
            cnt++;
            output.write(inp);
        }
        System.out.println("Depois da compressão:" + cnt);
        buffRead.close();
        output.close();
    }
}