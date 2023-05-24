using System;

class Lecturer
{
    public string name;
    public int age;
    public string department;

    private string office;
    private string email;
    private decimal salary;

    protected string researchArea;
    protected int yearsOfExperience;
    
    public Lecturer(string n, int a, string d){
        this.name = n;
        this.age = a;
        this.department = d;
    }
    
    public void introduce(){
        Console.WriteLine($"HI, my namme is {name} and I am a lecturer in the {department} department");
        Console.WriteLine($"I am {age} year old.");
        Console.WriteLine($"HI, my office is {office} and my Email is {email}.");
        Console.WriteLine($"My salary is {salary:C}.");
        Console.WriteLine($"My research area is {researchArea} and I have{yearsOfExperience} years of experience.");
    }
    
   public  void teach(){
        Console.WriteLine("Teachning a class ...");
    }

    public void setDetails(){
        Console.WriteLine("Enter the name:");
        name = Console.ReadLine();

        Console.WriteLine("Enter the age:");
        age = Convert.ToInt32(Console.ReadLine());

        Console.WriteLine("Enter the department:");
        department = Console.ReadLine();

        Console.WriteLine("Enter the office:");
        office = Console.ReadLine();

        Console.WriteLine("Enter the email:");
        email = Console.ReadLine();

        Console.WriteLine("Enter the salary:");
        salary = Convert.ToDecimal(Console.ReadLine());

        Console.WriteLine("Enter the research area:");
        researchArea = Console.ReadLine();

        Console.WriteLine("Enter the research years of experience:");
        yearsOfExperience = Convert.ToInt32(Console.ReadLine());
    }
};

class Program
{    
    static void Main(string[] args)
    {    
        Lecturer lecturer1 = new Lecturer("John Doe", 35, "Compute Science");
        Lecturer lecturer2 = new Lecturer("Jane Smith", 32, "Math");
        Lecturer lecturer3 = new Lecturer("Bob Johnson", 31, "Literture");
        //    Lecturer lecturer4("Amy Lee", 25, "Food Science");
        //    Lecturer lecturer5("David Kim", 28, "Physical Science");
        //    Lecturer lecturer6("Jonanth Hunter", 27, "Chemistry Science");
        Lecturer lecturer4 = new Lecturer("", 0, "");
        Lecturer lecturer5 = new Lecturer("", 0, "");
        Lecturer lecturer6 = new Lecturer("", 0, ""); 
        
        Console.WriteLine("Enter details for lecturer 4: ");
        lecturer4.setDetails();
        Console.WriteLine();
        
        Console.WriteLine("Enter details for lecturer 5: ");
        lecturer5.setDetails();
        Console.WriteLine();

        Console.WriteLine("Enter details for lecturer 6: ");
        lecturer6.setDetails();
        Console.WriteLine();

        Console.WriteLine("Enter details for lecturer 1: ");
        lecturer1.introduce();
        lecturer1.teach();
        Console.WriteLine();

        Console.WriteLine("Enter details for lecturer 2: ");
        lecturer2.introduce();
        lecturer2.teach();
        Console.WriteLine();

        Console.WriteLine("Enter details for lecturer 3: ");
        lecturer3.introduce();
        lecturer3.teach();
        Console.WriteLine();

    }
}