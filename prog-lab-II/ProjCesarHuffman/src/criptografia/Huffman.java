package criptografia;

import criptografia.NoHuffman;

import javax.print.attribute.standard.NumberOfDocuments;
import java.awt.*;
import java.util.Collections;
import java.util.Comparator;
import java.util.Vector;

public class Huffman {
    private NoHuffman raiz;
    private String[] seq = new String[26];
    private String descriptografada;
    public String criptografada;
    public String descriptoHuffman;

    public Huffman(int[] freq, String descriptografar) {
        System.out.println("Texto será criptografado em Huffman");
        descriptografada = descriptografar;
        raiz = criarArvore(freq);
        for(int i = 0; i < 26; ++i) seq[i] = "";
        findSeq(raiz, "");
        criptografada = "";
        for(int i = 0; i < descriptografada.length(); ++i) criptografada += seq[descriptografada.charAt(i) - 97];
    }

    private NoHuffman criarArvore(int[] freq) {
        Vector nodes = new Vector();
        NoHuffman newNode;
        for(int i = 0; i < freq.length; ++i) {
            if(freq[i] != 0) {
                newNode = new NoHuffman(freq[i], (char) (97 + i), (NoHuffman)null, (NoHuffman)null);
                nodes.add(newNode);
            }
        }

        while(nodes.size() != 1) {
            Collections.sort(nodes, new Comparator<NoHuffman>() {
                public int compare(NoHuffman node1, NoHuffman node2) {
                    if(node1.freq == node2.freq) return 0;
                    if(node1.freq > node2.freq) return 1;
                    return -1;
                }});

            NoHuffman l = (NoHuffman)nodes.get(0);
            NoHuffman r = (NoHuffman)nodes.get(1);
            nodes.remove(0);
            nodes.remove(0);
            newNode = new NoHuffman(l.freq + r.freq, ' ', l, r);
            nodes.add(newNode);
        }

        // retorna raiz da arvore de criptografia.Huffman
        return (NoHuffman) nodes.get(0);
    }

    private void findSeq(NoHuffman node, String s) {
        String sl = s + '0';
        String sr = s + '1';
        if (node.c != ' ') this.seq[node.c - 97] = s;
        else {
            this.findSeq(node.left, s + '0');
            this.findSeq(node.right, s + '1');
        }

    }

    public void getInfoLetras() {
        for(int i = 0; i < 26; ++i) {
            if(this.seq[i] != "") System.out.println("A sequência da letra " + (char) (i + 97) + " é " + this.seq[i]);
        }
    }

    public void descriptografiaHuffman() {
        System.out.println("Texto será descriptografado em Huffman");
        descriptoHuffman = "";
        NoHuffman pointer = raiz;
        for (int pos = 0; pos < criptografada.length(); pos++) {
            if (pointer.c != ' ') {
                descriptoHuffman += pointer.c;
                pointer = raiz;
            }
            if (criptografada.charAt(pos) == '0') pointer = pointer.left;
            else pointer = pointer.right;
        }
        descriptoHuffman += pointer.c;
    }



    public int criptoAnalisis() {
        // A ideia é, partindo do princípio de que a letra "a" é a que mais aparece na língua portuguesa, supor que
        // a letra de maior frequência será o "a", permitindo calcular o shift
        int mn = 100, esc = 0;
        for(int i = 0; i < 26; i++){
            if(seq[i].length() != 0 && seq[i].length() < mn) {
                mn = seq[i].length();
                esc = i;
            }
        }
        return esc;
    }

    public void printHuffman() {
        System.out.print("O texto criptografado em criptografia Huffman é: ");
        System.out.print(criptografada);
        System.out.print("\n");
        System.out.print("O texto descriptografado em criptografia Huffman é: ");
        System.out.print(descriptografada);
        System.out.print("\n");
    }
}
