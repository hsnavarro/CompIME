package criptografia;
import java.lang.*;

public class NoHuffman {
    public int freq;
    public char c;
    public NoHuffman left;
    public NoHuffman right;

    public NoHuffman(int frequency, char character, NoHuffman l, NoHuffman r) {
        freq = frequency;
        c = character;
        right = r;
        left = l;
    }

    public void getNodeInfo() {
        System.out.println(freq + " " + c);
    }
}