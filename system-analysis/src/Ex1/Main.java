package Ex1;

import Ex1.Incremental;

public class Main {
    public static void main (String[] args) {
        for(int i = 0; i < 10; i++) {
            Incremental inc = Incremental.getIncremental();
            System.out.println(inc);
        }
    }
}
