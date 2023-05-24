using System;

public class Flight
{
    private string flightNumber;
    private string departureAirport;
    private string arrivalAirport;
    private DateTime departureTime;
    private DateTime arrivalTime;

    public string GetFlightNumber()
    {
        return flightNumber;
    }

    public void SetFlightNumber(string value)
    {
        flightNumber = value;
    }

    public string GetDepartureAirport()
    {
        return departureAirport;
    }

    public void SetDepartureAirport(string value)
    {
        departureAirport = value;
    }

    public string GetArrivalAirport()
    {
        return arrivalAirport;
    }

    public void SetArrivalAirport(string value)
    {
        arrivalAirport = value;
    }

    public DateTime GetDepartureTime()
    {
        return departureTime;
    }

    public void SetDepartureTime(DateTime value)
    {
        departureTime = value;
    }

    public DateTime GetArrivalTime()
    {
        return arrivalTime;
    }

    public void SetArrivalTime(DateTime value)
    {
        arrivalTime = value;
    }

    // Constructor
    public Flight(string flightNumber, string departureAirport, string arrivalAirport, DateTime departureTime, DateTime arrivalTime)
    {
        SetFlightNumber(flightNumber);
        SetDepartureAirport(departureAirport);
        SetArrivalAirport(arrivalAirport);
        SetDepartureTime(departureTime);
        SetArrivalTime(arrivalTime);
    }

    // Additional methods or properties can be added here
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
        // Logic to calculate the baggage fee based on the number of bags and the airline's policy
        // Assume a fixed fee per bag for simplicity
        decimal baggageFee = 10.0m; // $10 per bag
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

    public string GetVisaRequirements(string destinationCountry)
    {
        // Logic to determine the visa requirements for the destination country
        // Assume a simplified implementation for demonstration purposes
        if (destinationCountry == "United States")
        {
            return "Visa is required for entry.";
        }
        else
        {
            return "Visa is not required for entry.";
        }
    }
}public class Passenger
{
    public string Name { get; set; }
    public int Age { get; set; }
    public string BookingReference { get; set; }

    // Constructor
    public Passenger(string name, int age, string bookingReference)
    {
        Name = name;
        Age = age;
        BookingReference = bookingReference;
    }

    // Additional methods or properties can be added here
}

public class Booking
{
    public Flight Flight { get; set; }
    public Passenger Passenger { get; set; }
    public string SeatNumber { get; set; }

    // Constructor
    public Booking(Flight flight, Passenger passenger, string seatNumber)
    {
        Flight = flight;
        Passenger = passenger;
        SeatNumber = seatNumber;
    }

    // Additional methods or properties can be added here
}

public interface IBookingSystem
{
    void MakeBooking();
    void CancelBooking();
    void GetBookingDetails();
}

public class Booking : IBookingSystem
{
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

    // Constructor
    public Booking(Flight flight, Passenger passenger, string seatNumber)
    {
        SetFlight(flight);
        SetPassenger(passenger);
        SetSeatNumber(seatNumber);
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
        // Create a domestic flight object
        DomesticFlight domesticFlight = new DomesticFlight("XYZ456", "LAX", "SFO", new DateTime(2023, 5, 15, 12, 0, 0), new DateTime(2023, 5, 15, 14, 0, 0), 25);

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
