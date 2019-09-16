package criptografia;
import java.util.*;

public class CifraCesar {
    private int shift;
    public String criptografada;
    public String descriptografada;

    public CifraCesar(int x, String texto, boolean encriptar) {
        this.shift = x;
        if (encriptar) {
            System.out.println("Texto será criptografado em Cesar");
            descriptografada = texto.toLowerCase();
            criptografada = "";
            int sz = texto.length();
            for(int i = 0; i < sz; i++){
                int a = descriptografada.charAt(i) - 97 + shift;
                if(a > 26) a -= 26;
                criptografada += (char) (a + 97);
            }
        } else {
            System.out.println("Texto será descriptografado em Cesar");
            criptografada = texto.toLowerCase();
            descriptografada = "";
            int sz = texto.length();
            for(int i = 0; i < sz; i++){
                int a = criptografada.charAt(i) - 97 - shift;
                if(a < 0) a += 26;
                descriptografada = descriptografada + (char)(a + 97);
            }
        }
    }

    public void getInfo() {
        System.out.print("Texto criptografado Cesar: ");
        System.out.println(criptografada);
        System.out.print("Texto descriptografado em Cesar: ");
        System.out.println(descriptografada);
    }
}
