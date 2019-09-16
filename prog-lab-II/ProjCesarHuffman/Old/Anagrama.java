import java.util.*;

public class Anagrama {
    public int[] jogada;


    public static void main(String[] args){
        Anagrama master = new Anagrama();
        Palindrome teste = new Palindrome();
        master.jogada = new int[12];
        for(int i = 0; i < master.jogada.length; i++){
            master.jogada[i] = i;
        }
    }
}