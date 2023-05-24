using System;

public class Flight
{
    private string flightNumber;
    private string departureAirport;
    private string arrivalAirport;
    private DateTime departureTime;
    private DateTime arrivalTime;
    public FlightDetails(string fN, string dA, string aA, DateTime dT, DateTime aT)
    {
        FlightNumber = fN;
        DepartureAirport = dA;
        ArrivalAirport = aA;
        DepartureTime = dT;
        ArrivalTime = aT;
    }
    public string GetFlightNumber()
    {
        return flightNumber;
    }
    public void SetFlightNumber(string v)
    {
        flightNumber = v;
    }
    public string GetDepartureAirport()
    {
        return departureAirport;
    }
    public void SetDepartureAirport(string v)
    {
        departureAirport = v;
    }
    public string GetArrivalAirport()
    {
        return arrivalAirport;
    }
    public void SetArrivalAirport(string v)
    {
        arrivalAirport = v;
    }
    public DateTime GetDepartureTime()
    {
        return departureTime;
    }
    public void SetDepartureTime(DateTime v)
    {
        departureTime = v;
    }
    public DateTime GetArrivalTime()
    {
        return arrivalTime;
    }
    public void SetArrivalTime(DateTime v)
    {
        arrivalTime = v;
    }

    public void FlightDetails(){
        Console.WriteLine("flight number: " + flightNumber);
        Console.WriteLine("departure airport: " + departureAirport);
        Console.WriteLine("arrival airport: " + arrivalAirport);
        Console.WriteLine("dparture time: " + departureTime);        
        Console.WriteLine("arrival time: " + arrivalTime);
        Console.WriteLine(" ");
        }
}


public class DomesticFlight : Flight
{
    public int BaggageAllowance { get; set; }

    public DomesticFlight(string flightNumber, string departureAirport, string arrivalAirport, DateTime departureTime, DateTime arrivalTime, int baggageAllowance)
        : base(flightNumber, departureAirport, arrivalAirport, departureTime, arrivalTime)
    {
        BaggageAllowance = baggageAllowance;
    }
    public decimal CalculateBaggageFee(int numberOfBags)
    {
        decimal baggageFee = 10.0m; // $10 per bag
        Console.WriteLine("your baggage fee is:" + numberOfBags * baggageFee)
        return numberOfBags * baggageFee;
    }
}
public class InternationalFlight : Flight
{
    public bool PassportRequired { get; set; }
    public InternationalFlight(string flightNumber, string departureAirport, string arrivalAirport, DateTime departureTime, DateTime arrivalTime, bool passportRequired)
        : base(flightNumber, departureAirport, arrivalAirport, departureTime, arrivalTime)
    {
        PassportRequired = passportRequired;
    }
    public decimal CalculateBaggageFee(int numberOfBags)
    {
        decimal baggageFee = 20.0m; 
        Console.WriteLine("your baggage fee is:" + numberOfBags * baggageFee)
        return numberOfBags * baggageFee;
    }
    public string GetVisaRequirements(string destinationCountry)
    {
        if (destinationCountry == "United States")
        {
            return "Visa is required for entry.";
        }
        else
        {
            return "Visa is not required for entry.";
        }
    }
}

public class Passenger
{
    private string Name;
    private int Age;
    private string BookingReference;
    public Passenger(string n, int a, string b)
    {
        Name = n;
        Age = a;
        BookingReference = b;
    }
    public string getName(){
        return Name;
    }
    public string setName(string value){
       Name = value;
    }
    public int GetAge()
    {
        return age;
    }
    public void SetAge(int value)
    {
        age = value;
    }

    public string GetBookingReference()
    {
        return bookingReference;
    }

    public void SetBookingReference(string value)
    {
        bookingReference = value;
    }
} 
public class Booking
{
// Passenger passenger1 = new Passenger("ana", 20, 111);
// InternationalFlight internationalFlight1 = new InternationalFlight("ALX", "Vancouver", "Calgary", new DateTime(2023, 5, 15, 12, 0, 0), new DateTime(2023, 5, 15, 14, 0, 0), 25);
    private Flight flight;
    private Passenger passenger;
    private string seatNumber;

    public Flight GetFlight()
    {
        return flight;
    }

    public void SetFlight(Flight value)
    {
        flight = value;
    }

    public Passenger GetPassenger()
    {
        return passenger;
    }

    public void SetPassenger(Passenger value)
    {
        passenger = value;
    }

    public string GetSeatNumber()
    {
        return seatNumber;
    }

    public void SetSeatNumber(string value)
    {
        seatNumber = value;
    }
    public Booking(Flight flight, Passenger passenger, string seatNumber)
    {
        SetFlight(flight);
        SetPassenger(passenger);
        SetSeatNumber(seatNumber);
    }
}
public interface IBookingSystem
{
    public void Welcome()
    {
        Console.WriteLine(" Wecome use ITD Booking System!");
        Console.WriteLine("What can I do for you?");
        Console.WriteLine("1 - making a booking\n2 - canceling a booking\n3 - retrieving booking details");
        int serviceChoice = Console.ReadLine();

        switch(serviceChoice)
        {           
        case 1:
            MakeBooking();
            break;  
        case 2:
            CancelBooking();
            break;  
        case 3:
            GetBookingDetails();
            break;  
        }
        Console.WriteLine("Thanks for using ITD service"); 
    }
    public void MakeBooking()
    {
        Console.WriteLine("Booking has been made successfully.");
    }
    public void CancelBooking()
    {
        Console.WriteLine("Booking has been canceled.");
    }
    public void GetBookingDetails()
    {
        Console.WriteLine("Booking Details:");
        Console.WriteLine("Flight Number: " + flight.GetFlightNumber());
        Console.WriteLine("Passenger Name: " + passenger.GetName());
        Console.WriteLine("Seat Number: " + seatNumber);
    }
}
class Program
{
    static void Main(string[] args)
    {
        IBookingSystem bookingSystem = newIBookingSystem;
        bookingSystem();
        
        
        // Create a domestic flight object
        
        DomesticFlight domesticFlight = new DomesticFlight("XYZ456", "YYR", "SFO", new DateTime(2023, 5, 15, 12, 0, 0), new DateTime(2023, 5, 15, 14, 0, 0), 25);

        // Create an international flight object
        InternationalFlight internationalFlight = new InternationalFlight("PQR789", "JFK", "LHR", new DateTime(2023, 5, 15, 10, 0, 0), new DateTime(2023, 5, 15, 15, 0, 0), true);

        // Create a passenger object
        Passenger passenger = new Passenger("John Doe", 30, "ABC123");

        // Create a booking for the domestic flight
        Booking domesticBooking = new Booking(domesticFlight, passenger, "A12");

        // Create a booking for the international flight
        Booking internationalBooking = new Booking(internationalFlight, passenger, "B10");

        // Make a booking
        MakeBooking(domesticBooking);

        // Cancel a booking
        CancelBooking(internationalBooking);

        // Demonstrate polymorphism
        Console.WriteLine("----Polymorphism----");
        Flight domesticFlightPoly = new DomesticFlight("DEF789", "SFO", "LAS", new DateTime(2023, 5, 16, 8, 0, 0), new DateTime(2023, 5, 16, 10, 0, 0), 20);
        Flight internationalFlightPoly = new InternationalFlight("GHI012", "LAX", "CDG", new DateTime(2023, 5, 17, 14, 0, 0), new DateTime(2023, 5, 17, 20, 0, 0), false);

        // Invoke specific methods using base class reference
        Console.WriteLine("----Domestic Flight----");
        Console.WriteLine("Baggage Allowance: " + ((DomesticFlight)domesticFlightPoly).GetBaggageAllowance());
        Console.WriteLine("Baggage Fee: " + ((DomesticFlight)domesticFlightPoly).CalculateBaggageFee());

        Console.WriteLine("----International Flight----");
        Console.WriteLine("Passport Required: " + ((InternationalFlight)internationalFlightPoly).IsPassportRequired());
        Console.WriteLine("Visa Requirements: " + ((InternationalFlight)internationalFlightPoly).GetVisaRequirements());
    }

    static void MakeBooking(IBookingSystem bookingSystem)
    {
        bookingSystem.MakeBooking();
    }

    static void CancelBooking(IBookingSystem bookingSystem)
    {
        bookingSystem.CancelBooking();
    }
}