import java.util.Scanner;

public class Fibonacci {
    public static int fib (int x){
        if(x == 1 || x == 2) return 1;
        return fib(x-1) + fib(x-2);
    }

    public static void main(String[] argv){
        Scanner in = new Scanner(System.in);
        int a = in.nextInt();
        System.out.println(fib(a));
    }
}
