import java.util.*;

public class SieveArray {
    public static void main(String args[]) {
        Scanner in = new Scanner(System.in);
        int MAX_N = in.nextInt();
        int cmp[] = new int[MAX_N];
        Arrays.fill(cmp, 0);
        for(int i = 2; i < MAX_N; i++) if(cmp[i] == 0) {
            for (int j = i * i; j < MAX_N; j += i) cmp[j] = 1;
        }
        // print primes
        for(int i = 2; i < MAX_N; i++) if(cmp[i] == 0) System.out.println(i);
    }
}
