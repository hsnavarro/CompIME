import java.math.BigInteger;
import java.util.Scanner;

public class SieveSimple {
    public static long gcd(long a, long b) { return (b != 0 ? gcd(b, a%b) : a);}

    public static void main(String[] args){
        Scanner in = new Scanner(System.in);
        // Works for MAX_N up to 50 because of overflow issues, BigInteger class needed
        int MAX_N = in.nextInt();
        long store = 1;
        for(int i = 2 ; i < MAX_N; i++) {
            if(gcd(store, (long) i) == 1) {
                System.out.println(i);
                store *= (long) i;
            }
        }
    }
}
