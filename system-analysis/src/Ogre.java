abstract class Ogre {
    public abstract void attack();
}

// Ogre básico, sem armas
class OgreBasic extends Ogre {
    public void attack() {
        System.out.println("the ogre strikes you");
    }
}

// Decorator para inserir propriedades no Ogre
abstract class OgreDecorator extends Ogre {
    protected Ogre ogreDecorated;

    public OgreDecorator(Ogre ogreDecorated) {
        this.ogreDecorated = ogreDecorated;
    }
}

// Decorator que adiciona o ataque de espada
class SwordAttack extends OgreDecorator {

    public SwordAttack(Ogre ogreDecorated) {
        super(ogreDecorated);
    }

    public void attack() {
        System.out.println("holding the blade of the sword the ogre strikes you");
    }
}

// Decorator que adiciona o ataque de machado
class AxeAttack extends OgreDecorator {

    public AxeAttack(Ogre ogreDecorated) {
        super(ogreDecorated);
    }

    public void attack() {
        System.out.println("the ogre strikes you with the swing of the mighty axe");
    }
}
