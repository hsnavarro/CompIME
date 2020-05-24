public abstract class Prototype {
    public int hitPoints, armor, sight, movementSpeed;

    public abstract Prototype clonar();

    public int getHitPoints() {
        return hitPoints;
    }

    public int getArmor() {
        return armor;
    }

    public int getSight() {
        return sight;
    }

    public int getMovementSpeed() {
        return movementSpeed;
    }
}
