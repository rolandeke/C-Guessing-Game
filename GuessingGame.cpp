#ifdef _WIN32
#include<windows.h>
#else
#include <unistd.h>
#endif
#include<iostream>
#include <cstdlib>
#include <ctime>
#include<fstream>


void playGame();
int viewHighScore();
void displayGreeting();
void saveScore(int& score);

int main(){

   
    std::cout << "Welcome to console guessing game\n\nPress:\n1.Play\n2.View High Score\n";
    int userOption;
    std::cin >> userOption;
    switch (userOption)
    {
    case 1:
        playGame();
        break;
    case 2:
        viewHighScore();
        break;
    
    default:
        std::cout << "That Option is invalid. Please try again." << std::endl;
        main();
        break;
    }

    
    return 0;
}

void displayGreeting(){
    system("clear");
    std::cout << "Guessing game between user and computer " << std::endl;
    std::cout << "Guess a number between 1 and 10 " << std::endl;
}

void playGame(){

    displayGreeting();

    //seeding random number generator
    srand(time(NULL));

    int SCORE = 10;

    //Variable for stroing random secret number
    int SecretNumber = 0;

    //varables for storing userGess, computer's Guess, user's Score and Computer's Score
    int usersGuess, computersGuess, usersScore, compScore = 0;

    //Generate Random Secret NUmber between 0 and 10
    SecretNumber = (rand() % 10) + 1;

    //Infinte Loop that runs as long as user's guess is not equal to Secret Number
    while (usersGuess != SecretNumber)
    {

        //Prompting user for input
        std::cout << "\nUsers Guess: ";

        //stroting user's number inside of variable
        std::cin >> usersGuess;

        //allowing system to sleep for 1secs
        sleep(1);

        //checking if the user's guess equals secret number generated
        if (usersGuess == SecretNumber)
        {
            std::cout << "User guessed " << usersGuess << " and was correct " << std::endl;
            usersScore += SCORE;
            std::cout << "User's Score: " << usersScore << std::endl;

            std::cout << "Want to play again(y/n): ";
            char* playAgainOpt;
            std::cin>> playAgainOpt;
            switch (playAgainOpt)
            {
            case 'Y'||'y':
                playGame()
                break;
            case 'N' || 'n':
                saveScore();
                system("exit");
            default:
                break;
            }
            //resetting users score after correct guess so that the loop run's again
            usersGuess = 0;
            //generating new random number after user guessed right
            SecretNumber = (rand() % 10) + 1;
        }
        else
        {
            std::cout << "User Guessed " << usersGuess << " and was wrong " << std::endl;
        }
        std::cout << std::endl;

        //generating random guesses for the computer
        int rnd = (rand() % 10) + 1;

        std::cout << "Computer's Turn:" << std::endl;
        computersGuess = rnd;

        //allowing system to sleep for 1 sec
        sleep(1);

        //checking if computer's guess is equal to secret number
        if (computersGuess == SecretNumber)
        {
            std::cout << "Computer's guessed " << computersGuess << " and was correct" << std::endl;
            compScore += SCORE;
            std::cout << "Computer's Score: " << compScore << std::endl;

            //generating new random number after computer guessed right
            SecretNumber = (rand() % 10) + 1;
        }
        else
        {
            std::cout << "Computer's guessed " << computersGuess << " and was wrong " << std::endl;
        }
    }
}


int viewHighScore(){

    return 0;
}

void saveScore(int& score){
    
   
    
}