#include <iostream>
#include <ctime>

void PrintIntroduction(int Difficulty) 
{
    std::cout << "You are currently locked in room " << Difficulty << "...\n";
    std::cout << "You need to enter the correct code to get out... \n\n";
}

bool PlayGame(int Difficulty)
{
    PrintIntroduction(Difficulty);

    const int CodeA = rand() % Difficulty + Difficulty;
    const int CodeB = rand() % Difficulty + Difficulty;
    const int CodeC = rand() % Difficulty + Difficulty;

    const int CodeSum = CodeA + CodeB + CodeC;
    const int CodeProduct = CodeA * CodeB * CodeC;

    std::cout << " * There are 3 numbers in the code \n";
    std::cout << " * The codes add-up to: " << CodeSum << std::endl;
    std::cout << " * The codes multiply to give: " << CodeProduct << std::endl;

    //Take in Players guess
    int GuessA, GuessB, GuessC;
    std::cin >> GuessA >> GuessB >> GuessC;

    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;

    if (GuessSum == CodeSum && GuessProduct == CodeProduct)
    {
        std::cout << "\nYou got it. You're out of room " << Difficulty << std::endl;
        return true;
    }
    else
    {
        std::cout << "That didn't seem to work. Try again. \n";
        return false;
    }
}


int main()
{
    srand(time(NULL)); // random seed based on time

    std::cout << "Hello! I'm glad you're awake... \n";

    int LevelDifficulty = 1;
    const int MaxDifficulty = 5;

    //loop until all levels are completed
    while (LevelDifficulty <= MaxDifficulty) 
    {
        bool bLevelComplete = PlayGame(LevelDifficulty);
        std::cin.clear(); //Clears any errors
        std::cin.ignore(); // Discards the buffer

        if (bLevelComplete)
        {
            ++LevelDifficulty;
        }
    }

    std::cout << "You made it out of the building! Go call the police!\n";

    return 0;
}

