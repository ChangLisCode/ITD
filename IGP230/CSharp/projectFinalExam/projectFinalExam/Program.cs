using System;
using System.Threading;
class Character
{
    public string Name { get; set; }
    public int Health { get; set; }
    public int Damage { get; set; }
    public Character(string name, int health, int damage)
    {
        Name = name;
        Health = health;
        Damage = damage;
    }
    public virtual void Attack(Character target)
    {
        Console.WriteLine($"{Name} attacks {target.Name} for {Damage} damage.");
        target.TakeDamage(Damage);
    }
    public void TakeDamage(int damage)
    {
        Health -= damage;
        if (Health < 0)
            Health = 0;
        Console.WriteLine($"{Name} takes {damage} damage. Health: {Health}");
    }
    public bool IsAlive()
    {
        return Health > 0;
    }
}
class Warrior : Character
{
    public int Armor { get; set; }
    public Warrior(string name, int health, int damage, int armor)
        : base(name, health, damage)
    {
        Armor = armor;
    }
    public override void Attack(Character target)
    {
        Console.WriteLine($"{Name} swings a sword at {target.Name} for {Damage} damage.");
        target.TakeDamage(Damage);
    }
}
class Mage : Character
{
    public int Mana { get; set; }

    public Mage(string name, int health, int damage, int mana)
        : base(name, health, damage)
    {
        Mana = mana;
    }
    public override void Attack(Character target)
    {
        Console.WriteLine($"{Name} casts a spell on {target.Name} for {Damage} damage.");
        target.TakeDamage(Damage);

        if(Damage > 50){
            // critical hits
            Mana -= 100;
        }
        else
        {
            Console.WriteLine($"Woo!, no critical hits. {Name} loses 10 mana. Mana: {Mana}");
            Mana -= 10;
        }
    }

}
class Battle
{
    public void StartBattle(Character character1, Character character2)
    {
        Console.WriteLine($"Battle between {character1.Name} and {character2.Name} starts!");
        Healing healing = new Healing();
        while (character1.IsAlive() && character2.IsAlive())
        {
            character1.Attack(character2);
            if (!character2.IsAlive())
            {
                healing.healingProcess(character2);
                break;
            }

            character2.Attack(character1);
            if (!character1.IsAlive())
            {
                healing.healingProcess(character1);
                break;
            }
            Console.WriteLine();
        }
        Console.WriteLine($"{(character1.IsAlive() ? character1.Name : character2.Name)} wins the battle!");
    }
}

class Healing
{
    public void healingProcess(Character target)
    {
        //  healing potions
        Random randomTime = new Random();
        int delayTime = randomTime.Next(1, 10);
        Thread.Sleep(delayTime);

        Console.WriteLine("I am tired, I need rest...");
        Console.WriteLine($"{delayTime} passed.");
        target.Health += delayTime * 10;
        Console.WriteLine($"Oh, {target.Name} are healing, His health {delayTime} go up to {target.Health}. " );
    }
}
class Program
{
    static void Main(string[] args)
    {
        // generate random damage to let game complex.
        Random random = new Random();
        int damageRandomWarrior = random.Next(0, 101);
        int damageRandomMage = random.Next(0, 101);

        Warrior warrior = new Warrior("Hary Potter", 100, damageRandomWarrior, 10);
        Mage mage = new Mage("Spider Man", 80, damageRandomMage, 50);

        Battle battle = new Battle();
        battle.StartBattle(warrior, mage);       
    }
}

