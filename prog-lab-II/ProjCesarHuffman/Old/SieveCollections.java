import java.util.*;

public class SieveCollections {
    public static void main(String[] args){
        Scanner in = new Scanner(System.in);
        int MAX_N = in.nextInt();
        TreeSet<Integer> prim = new TreeSet<Integer>();
        for(int i = 2; i < MAX_N; i++) prim.add(i);
        for(int i = 2; i < MAX_N; i++){
            if(prim.contains(i))
                for(int j = i*i; j < MAX_N; j += i) prim.remove(j);
        }
        // printing primes
        for(int prime : prim) System.out.println(prime);
    }
}
