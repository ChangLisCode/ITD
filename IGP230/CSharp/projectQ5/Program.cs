using System;

class TextAdventureGame
{
    static void Main()
    {
        // Initialize the dungeon map
        string[,] map = new string[,] {
            {"X", "X", "X", "X", "X"},
            {"X", ".", ".", ".", "X"},
            {"X", ".", ".", ".", "X"},
            {"X", ".", ".", ".", "X"},
            {"X", "X", "X", "X", "X"}
        };

        // Initialize the player's starting position
        int playerRow = 1;
        int playerCol = 1;

        // Set up random number generator
        Random rand = new Random();

        // Start the game loop
        while (true)
        {
            // Print the current room description
            Console.WriteLine("You are in a dark room. There are doors to the north, south, east, and west.");

            // Print the current map
            for (int i = 0; i < 5; i++)
            {
                for (int j = 0; j < 5; j++)
                {
                    if (i == playerRow && j == playerCol)
                    {
                        Console.Write("P");
                    }
                    else
                    {
                        Console.Write(map[i, j]);
                    }
                }
                Console.WriteLine();
            }

            // Prompt the player for input
            Console.Write("What do you want to do? ");

            // Parse the player's input
            string input = Console.ReadLine().ToLower();
            if (input == "north")
            {
                playerRow--;
            }
            else if (input == "south")
            {
                playerRow++;
            }
            else if (input == "east")
            {
                playerCol++;
            }
            else if (input == "west")
            {
                playerCol--;
            }

            // Check if the player has reached the end of the dungeon
            if (playerRow == 3 && playerCol == 3)
            {
                Console.WriteLine("You have reached the end of the dungeon. Congratulations!");
                break;
            }

            // Random event
            int eventChance = rand.Next(1, 101);
            if (eventChance <= 20)
            {
                Console.WriteLine("You have found a treasure!");
            }
            else if (eventChance <= 40)
            {
                Console.WriteLine("You have encountered a monster!");
                Console.Write("Do you want to fight or flee? ");
                string choice = Console.ReadLine().ToLower();
                if (choice == "fight")
                {
                    Console.WriteLine("You have won the fight!");
                }
                else if (choice == "flee")
                {
                    Console.WriteLine("You have fled from the monster.");
                    playerRow = 1;
                    playerCol = 1;
                }
            }
        }
    }
}
