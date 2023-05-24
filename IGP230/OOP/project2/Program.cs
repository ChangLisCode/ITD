using System;

public class Instrument
{
    public virtual void Play()
    {
        Console.WriteLine("Play an instrument.");
    }
}

public class Piano : Instrument
{
    public override void Play()
    {
        Console.WriteLine("Play the piano.");
    }
}

public class Guitar : Instrument
{
    public override void Play()
    {
        Console.WriteLine("Play the guitar.");
    }
}

public class Program
{
public static void Main()
{
    Instrument instrument1 = new Piano();
    Instrument instrument2 = new Guitar();
    instrument1.Play();
    instrument2.Play();

    instrument1 = null;
    instrument2 = null;
    }
}