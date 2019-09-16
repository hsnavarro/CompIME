import java.util.*;

public class Panagrama {
    public static void main(String[] args){
        String a, b = "";
        Scanner s = new Scanner(System.in);
        a = s.nextLine();
        Set cara = new HashSet();
        for(int i = 0; i < a.length(); i++) {
            char aux = a.charAt(i);
            if((aux >= 'a' && aux <= 'z') || (aux >= 'A' && aux <= 'Z'))
                cara.add(a.toLowerCase().charAt(i));
        }
        if(cara.size() == 26) System.out.println("É panagrama");
        else System.out.println("Não é panagrama");
    }
}
