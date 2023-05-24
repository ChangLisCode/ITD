using System;

class TextAdventureGame
{
        static int randomNumber(int a, int b)
        {
            Random rnd = new Random();
            int temp = rnd.Next(a, b);
            return temp;
        }
        static void displayMap(int roomRow, int roomCol, int playerRow, int playerCol)
        {
            // set up monster postion ramdomly
            int monsterRow = randomNumber(roomRow, roomCol);
            int monsterCol = randomNumber(roomRow, roomCol);

            // set up treasue postion ramdomly
            int treasureRow = randomNumber(roomRow, roomCol);
            int treasureCol = randomNumber(roomRow, roomCol);

            // code list
            string unknowPosition = " X ";
            string playerPosition = " P ";
            string treasurePosition = " T ";
            string monsterPosition = " M ";

            for (int i = 0; i < roomRow; i++)
            {
                for (int j = 0; j < roomCol; j++)
                {
                    // move player postion
                    if( playerCol == i && playerRow == j ){
                        Console.WriteLine($"{playerPosition}");
                        
                        // random events
                        if( playerCol == treasureCol && playerRow == treasureRow ){
                            Console.WriteLine($"Congratulation! You own one treasure!");
                            Console.WriteLine($"{treasurePosition}");
                        }
                        else if( playerCol == monsterCol && playerRow == monsterRow )
                        {
                            Console.WriteLine("You have encountered a monster!");
                            Console.Write("Do you want to fight or flee? ");
                            string choice = Console.ReadLine().ToLower();
                            if (choice == "fight")
                            {
                                Console.WriteLine("You have won the fight!");
                                Console.WriteLine($"{monsterPosition}");

                            }
                            else if (choice == "flee")
                            {
                                Console.WriteLine("You have fled from the monster.");
                                playerRow = 0;
                                playerCol = 0;
                                break;
                            }
                        }  
                    }
                    else {
                        Console.WriteLine($"{unknowPosition}");
                    }
                }            
            }
        }
    static bool pressDirectionKey(int roomRow, int roomCol, int playerRow, int playerCol)
    {
        bool end = false;
        ConsoleKeyInfo input = Console.ReadKey(true);
        if (input.Key == ConsoleKey.UpArrow)
        {
            playerRow++;
            displayMap(roomRow, roomCol, playerRow, playerCol);
        }
        else if (input.Key == ConsoleKey.DownArrow)
        {
            playerRow--;
            displayMap(roomRow, roomCol, playerRow, playerCol);
        }
        else if (input.Key == ConsoleKey.LeftArrow)
        {
            playerCol++;
            displayMap(roomRow, roomCol, playerRow, playerCol);
        }
        else if (input.Key == ConsoleKey.RightArrow)
        {
            playerCol--;
            displayMap(roomRow, roomCol, playerRow, playerCol);
        }

        while(playerCol == roomCol && playerRow == roomRow)
        {
            Console.WriteLine("You have reached the end of the dungeon. Congratulations!");
            end = true;
            break;
        }
        return end;
    }
    static void Main()
    {
        // set up room size
        int roomRow = 10;
        int roomCol = 10;

        // Initialize the player's starting position
        int playerRow = 0;
        int playerCol = 0;

        // Initialize the dungeon map
        Console.WriteLine("Welcome to your exited adventure travl room! ");
        displayMap(roomRow, roomCol, playerRow, playerCol);

        Console.WriteLine("Dungeon Room is built! \nFollow the instuction to win!\nMove four directions to proceed: \nbutton up -> north\nbutton down -> south\nbutton right -> east\nbutton left -> west\nThere are monster or treasure in your future way!\nWhen you get to right bottom, you will win the adventure!\nNow, start your journey!");
        Console.WriteLine("Now, you have been left upper, Start your journey!");

        bool end = false;
        for(int i=0; i<100; i++){
                end = pressDirectionKey(roomRow, roomCol, playerRow, playerCol);
                while(end){
                break;
            }
        }
    }
}





