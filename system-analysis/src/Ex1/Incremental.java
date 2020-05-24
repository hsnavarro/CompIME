package Ex1;

public class Incremental {
    private static int count = 0;
    private int numero;
    private static Incremental instance = null;

    private Incremental() { numero = ++count; }
    public String toString() { return "Incremental " + numero; }
    public static Incremental getIncremental() {
        if(instance != null) return instance;
        return instance = new Incremental();
    }
}