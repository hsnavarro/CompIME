public class Peon extends Prototype {
    public Peon() {
        hitPoints = 30;
        armor = 0;
        sight = 4;
        movementSpeed = 10;
    }

    protected Peon(Peon prototype) {
        this.hitPoints = prototype.getHitPoints();
        this.armor = prototype.getArmor();
        this.sight = prototype.getSight();
        this.movementSpeed = prototype.getMovementSpeed();
    }

    @Override
    public Peon clonar() {
        return new Peon(this);
    }

}
