import java.util.*;

public class OrcBase {
    public GreatHall greatHall = null;
    public List<Peon> lista;
    public Peon prototipoPeon = new Peon();

    public void create() throws InterruptedException {
        if(greatHall != null) {
            Peon novoPeon = prototipoPeon.clonar();
            lista.add(novoPeon);
            System.out.println("Aguardando 45 segundos");
            new Thread().sleep(45000);
        }

    }

    public void main(String[] args) throws InterruptedException {
        // Singleton
        greatHall = GreatHall.buildGreatHall();

        while(lista.size() != 15) create();
    }

}
