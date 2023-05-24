using System;
using System.Collections.Generic;

// base class of Vehicle
public class Vehicle
{
    public int ID {get; set;}
    public int Capacity {get; set;}
    public Coordinate Destination { get; set; }
    public List<Passenger> Passengers { get; set;}
    public Vehicle(int id, int capacity, Coordinate destination)
    {
        ID = id;
        Capacity = capacity;
        Destination = destination;
        Passengers = new List<Passenger>();
    }

    public virtual void MoveTo(Coordinate destination)
    {
        Console.WriteLine($"Vehicle {ID} is moving to {destination}.");
        Destination = destination;
    }
    public void AddPassenger(Passenger passenger)
    {
        if (Passengers.Count < Capacity)
        {
            Passengers.Add(passenger);
            Console.WriteLine($"Passenger {passenger.Name} boarded Vehicle {ID}.");
        }
        else
        {
            Console.WriteLine($"Vehicle {ID} is already at full capacity.");
        }
    }

    public void RemovePassenger(Passenger passenger)
    {
        Passengers.Remove(passenger);
        Console.WriteLine($"Passenger {passenger.Name} disembarked from Vehicle {ID}.");
    }
}

// derive from base class
public class Bus : Vehicle
{
    public string RouteNumber { get; set; }

    public Bus(int id, int capacity, Coordinate Destination, int routeNumber)
        : base(id, capacity, Destination)
    {
        RouteNumber = routeNumber;
    }

    public override void MoveTo(Coordinate destination)
    {
        Console.WriteLine($"Bus {ID} on Route {RouteNumber} is moving to {destination}.");
        Destination = destination;
    }
    public void PickUpPassenger()
    {
        Console.WriteLine($"Bus {ID} on Route {RouteNumber} is picking up passengers.");
    }
}

public class Train : Vehicle
{
    public string Line { get; set; }
    public double TrainRatePerMile { get; set; }

    public Train(int id, int capacity, Coordinate destination, string line)
        : base(id, capacity, destination)
    {
        Line = line;
    }

    public override void MoveTo(Coordinate destination)
    {
        Console.WriteLine($"Train {ID} on Line {Line} is moving to {destination}.");
        Destination = destination;
    }
    public double CalculateFare(double distance)
    {
        return TrainRatePerMile * distance;
    }
}

public class Taxi : Vehicle
{
    public double TaxiRatePerMile { get; set; }
    public Taxi(int id, int capacity, Coordinate destination, double ratePerMile)
        : base(id, capacity, destination)
    {
        RatePerMile = ratePerMile;
    }
    public override void MoveTo(Coordinate destination)
    {
        Console.WriteLine($"Taxi {ID} is moving to {destination}.");
        Destination = destination;
    }
    public double CalculateFare(double distance)
    {
        return TaxiRatePerMile * distance;
    }
}

public class Coordinate
{
    public int X { get; set; }
    public int Y { get; set; }
    public List<City> city { get; set; }



    public Coordinate(int x, int y)
    {
        X = x;
        Y = y;
    }

    public override string ToString()
    {
        return $"({X}, {Y})";
    }
}

public class Passenger
{
    public int ID { get; private set; }
    public string Name { get; set; }
    public string CityFrom { get; set; }
    public string CityTo { get; set; }


    public Passenger(int id, string name, string ciytFrom, string cityTo)
    {
        ID = id;
        Name = name;
        CityFrom = cityFrom;
        CityTo = cityTo;
    }
}

public class City
{
    public int ID { get; private set; }
    public string CityName { get; set; }
    public Coordinate Location { get; set; }

    public void Passenger(int id, string cityname, Coordinate location)
    {
        ID = id;
        CityName = name;
        Location = location;
    }
}

public class TransportationSystem<T> where T : Vehicle
{
    public TransportationSystem()
    {
        vehicles = new List<T>();
    }

    public void AddVehicle(T vehicle)
    {
        vehicles.Add(vehicle);
        Console.WriteLine($"Added Vehicle {vehicle.ID} to the system.");
    }

    public void RemoveVehicle(T vehicle)
    {
        vehicles.Remove(vehicle);
        Console.WriteLine($"Removed Vehicle {vehicle.ID} from the system.");
    }

    public void UpdateSystemState()
    {
        foreach (var vehicle in vehicles)
        {
            // Perform system updates for each vehicle
            Console.WriteLine($"Updating system state for Vehicle {vehicle.ID}...");
        }
    }
}

public class Program
{
    public static void Main(string[] args)
    {       
     
        Console.WriteLine("Welcome to ITD Transportation System!");
        Console.WriteLine("Please waiting loading system");
      
        TransportationSystem<Vehicle> transportationSystem = new TransportationSystem<Vehicle>();

        // Create vehicles
        Bus bus = new Bus(1, 50, new Coordinate(0, 0), 100);
        Train train = new Train(2, 200, new Coordinate(0, 0), "Line1");
        Taxi taxi = new Taxi(3, 4, new Coordinate(0, 0), 2.5);

        // Add vehicles to the transportation system
        transportationSystem.AddVehicle(bus);
        transportationSystem.AddVehicle(train);
        transportationSystem.AddVehicle(taxi);

        Console.WriteLine("System loading finish successfully!");

        // passeenger UI
        Passenger passenger1 = new Passenger();
        Console.WriteLine("Please input your ID!");
        passenger1.ID = Console.ReadLine();
        Console.WriteLine("Please input your name!");
        passenger1.Name = Console.ReadLine();
        Console.WriteLine("Please input your destination");
        Console.WriteLine("City list");
        passenger1.CityTo = Console.ReadLine();
        Console.WriteLine("Please input your current city");
        Console.WriteLine("City list");
        passenger1.CityFrom = Console.ReadLine();
        Console.WriteLine("Please input your vehicle type");
        Console.WriteLine("1 - train\n2 - bus\n3-Taxi");
        int vehicleType = 0;
        vehicleType = Console.ReadLine();

        Console.WriteLine("Thanks using ITD transportation System, see you next time!");

        // vehicle running process
        switch(vehicleType)
            {
                case 1:
                    List<Vehicle> vehicles = new List<Vehicle>();
                    vehicles.Add(new Train(5, 150, new Coordinate(0, 0), "Line1"));
                    train.MoveTo(new Coordinate(-5, 5));
                    bus.PickUpPassenger();
                    double fare = train.TrainCalculateFare(10.5);
                    Console.WriteLine($"Fare for the taxi ride: {fare}");
                    train.RemovePassenger(new Passenger(1, "Alice", new Coordinate(10, 10)));
                    break;
                case 2:
                    vehicles.Add(new Bus(4, 30, new Coordinate(0, 0), 200));
                    bus.MoveTo(new Coordinate(10, 10));
                    bus.PickUpPassenger();
                    bus.RemovePassenger(new Passenger(1, "Alice", new Coordinate(10, 10)));
                    break;

                case 3:
                    vehicles.Add(new Taxi(6, 2, new Coordinate(0, 0), 3.0));
                    taxi.MoveTo(new Coordinate(3, -3));
                    taxi.PickUpPassenger();
                    double fare = taxi.TaxiCalculateFare(10.5);
                    Console.WriteLine($"Fare for the taxi ride: {fare}");
                    taxi.RemovePassenger(new Passenger(1, "Alice", new Coordinate(10, 10)));
                    break;
            }
        transportationSystem.RemoveVehicle(bus);
        transportationSystem.RemoveVehicle(taxi);   
        transportationSystem.RemoveVehicle(train);
        transportationSystem.UpdateSystemState();
        Console.ReadLine();
    }
}