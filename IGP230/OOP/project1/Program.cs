using System;

class Food
{
    protected string name;
    protected int calories;

    public Food(string n, int c)
    {
        name = n;
        calories = c;
    }

    public void Display()
    {
        Console.WriteLine("Name: " + name);
        Console.WriteLine("Calories: " + calories);
    }
}

class Fruit : Food
{
    protected string color;

    public Fruit(string n, int c, string col) : base(n, c)
    {
        color = col;
    }

    public void Ripen()
    {
        Console.WriteLine("The fruit is ripening.");
    }
}

class CitrusFruit : Fruit
{
    private string citrusType;

    public CitrusFruit(string n, int c, string col, string type) : base(n, c, col)
    {
        citrusType = type;
    }

    public void ExtractJuice()
    {
        Console.WriteLine("Juice is being extracted from the citrus fruit.");
    }
}

class Berry : Fruit
{
    public Berry(string n, int c, string col) : base(n, c, col)
    {
    }

    public void EatWithCream()
    {
        Console.WriteLine("The berry is being eaten with cream.");
    }
}

class Vegetable : Food
{
    public Vegetable(string n, int c) : base(n, c)
    {
    }

    public void Cook()
    {
        Console.WriteLine("The vegetable is being cooked.");
    }
}

class LeafyVegetable : Vegetable
{
    public LeafyVegetable(string n, int c) : base(n, c)
    {
    }

    public void TossSalad()
    {
        Console.WriteLine("The leafy vegetable is being used to toss a salad.");
    }
}

class RootVegetable : Vegetable
{
    public RootVegetable(string n, int c) : base(n, c)
    {
    }

    public void Roast()
    {
        Console.WriteLine("The root vegetable is being roasted.");
    }
}

class Program
{
    static void Main(string[] args)
    {
        Fruit orange = new Fruit("Orange", 62, "Orange");
        Fruit strawberry = new Fruit("Strawberry", 32, "Red");
        Vegetable spinach = new Vegetable("Spinach", 23);
        RootVegetable potato = new RootVegetable("Potato", 77);

        orange.Display();
        orange.Ripen();
        CitrusFruit citrusFruit = new CitrusFruit("Lemon", 29, "Yellow", "Lime");
        citrusFruit.Display();
        citrusFruit.Ripen();
        citrusFruit.ExtractJuice();

        Console.WriteLine();

        strawberry.Display();
        strawberry.Ripen();
        Berry berry = new Berry("Blueberry", 42, "Blue");
        berry.Display();
        berry.Ripen();
        berry.EatWithCream();

        Console.WriteLine();

        spinach.Display();
        spinach.Cook();
        LeafyVegetable leafyVegetable = new LeafyVegetable("Lettuce", 15);
        leafyVegetable.Display();
        leafyVegetable.Cook();
        leafyVegetable.TossSalad();

        Console.WriteLine();

        potato.Display();
        potato.Cook();
        potato.Roast();
        potato.Display();

        Console.ReadLine();
    }
}
