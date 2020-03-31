#ifdef _WIN32
#include<windows.h>
#else
#include <unistd.h>
#endif
#include<iostream>
#include <cstdlib>
#include <ctime>


int main(){

    //seeding random number generator
    srand(time(NULL));

    const int SCORE = 10;

    //Variable for stroing random secret number
    int SecretNumber = 0;

    //varables for storing userGess, computer's Guess, user's Score and Computer's Score
    int usersGuess, computersGuess,usersScore,compScore = 0;

    //Generate Random Secret NUmber between 0 and 10
    SecretNumber = (rand() % 10) + 1;

    std::cout << "Guessing game between user and computer " << std::endl;


    //Infinte Loop that runs as long as user's guess is not equal to Secret Number
    while(usersGuess != SecretNumber){
     

        //Prompting user for input 
        std::cout << "\nUsers Guess: ";

        //stroting user's number inside of variable 
        std::cin >> usersGuess;

        //allowing system to sleep for 1secs 
        sleep(1);

        //checking if the user's guess equals secret number generated 
        if(usersGuess == SecretNumber){
            std::cout << "User guessed " << usersGuess << " and was correct " << std:: endl;
            usersScore += SCORE;
            std::cout << "User's Score: " << usersScore << std::endl;
            std::cout << "Computer's Score: " << compScore << std::endl;

            //resetting users score after correct guess so that the loop run's again
            usersGuess = 0;

            //generating new random number after user guessed right
            SecretNumber = (rand() % 10) + 1;
        }else
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
        if(computersGuess == SecretNumber){
            std::cout << "Computer's guessed "<< computersGuess << " and was correct" << std::endl;
            compScore +=10;
            std::cout << "Computer's Score: " << compScore << std::endl;
            std::cout << "User's Score: " << usersScore << std::endl;

            //generating new random number after computer guessed right
            SecretNumber = (rand() % 10) + 1;
         
        }else
        {
            std:: cout << "Computer's guessed " << computersGuess << " and was wrong " << std::endl;
        }

    
    }
   
    
    return 0;
}