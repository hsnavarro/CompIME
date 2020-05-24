public class GreatHall {
    private static GreatHall construcao;

    private GreatHall() {

    }

    public static synchronized GreatHall buildGreatHall() {
        if(construcao == null)
            construcao = new GreatHall();

        return construcao;
    }

}
