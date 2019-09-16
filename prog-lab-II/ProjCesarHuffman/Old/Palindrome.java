import java.util.*;

public class Palindrome {
    public static void main (String[] args){
        Scanner in = new Scanner(System.in);
        String s = in.nextLine();
        StringBuilder ax = new StringBuilder(s);
        String b = ax.reverse().toString();
        s.replace(" ", "");
        s.replace(",", "");
        b.replace(" ", "");
        b.replace(",", "");
        if(b.equals(s)) {
            System.out.println("É Palíndromo");
        } else {
            System.out.println("Não é palíndromo");
        }
    }
}
