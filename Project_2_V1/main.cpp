/* 
 * File:   main.cpp
 * Author: Sarah Shima 
 * Created on July 27, 2020, 8:00 PM 
 * Purpose: Project 2 - Gin Rummy Card Game 
 * Version Details: game played user vs. computer, 
 * computer will be the dealer 
 */ 

//System Libraries 
#include <iostream> //I/O Library 
#include <iomanip>  //Stream Manipulator Library 
#include <cmath>     //Math Library 
#include <cstdlib>    //Random Generator Library 
#include <fstream>  //File I/O Library 
#include <string>     //String Library 
#include <ctime>     //Time Library 
using namespace std; 

//User Libraries 

//Global Constants Only 
//Well known Science, Mathematical and Laboratory Constants 

//Function Prototypes 
void forDeck(string, int); 
void plyDeal(string, int); //function to deal cards to players 

//*****************START*OF*FUNCTION*MAIN*******************

//Execution of Code Begins Here 
int main(int argc, char** argv) { 
    //Set the random number seed here 
    srand(static_cast<unsigned int>(time(0))); 

//********VARIABLE*DECLARATIONS********
    
    //Declare all variables for this function 
    bool    testNum; //ends writing to a file 
    string plyr1="Player 1",   //Player 1, user 
               plyr2="Player 2", //Player 2, computer 
               discard,  //current card in the discard pile 
               winner;   //game winner 
    int       p1_input, //Player 1 game input 
               p2_input; //Player 2 game input 
    float   p1_score, //Player 1 final score 
               p2_score; //Player 2 final score 
    

//********ARRAY*DECLARATIONS********
    
    //Declare Card Deck Array 
    const int CARDS=52; //max. possible cards in deck 
    string deck[CARDS]; 
    
    //Declare Player 1 Cards Array 
    const int HAND_1=10; //10 cards sub 0-9, plus drawn card sub 10 
    string p1_hand[HAND_1]; 
    
    //Declare Player 2 Cards Array 
    const int HAND_2=10; //10 cards sub 0-9, plus drawn card sub 10 
    string p2_hand[HAND_2]; 
    
    //Declare Stock Pile Array 
    const int LFTOVER=30; //left after cards dealt, discard pile made 
    string stock[LFTOVER]; 
    
//********CARD*DECK********

    //Call Function to create card deck 
    forDeck(deck, CARDS); 

//********MAIN*MENU*OPTIONS********
    
    //Main Menu Options 
    do { 
    cout<<"Main Menu"<<endl; 
    cout<<"Choose one of the following:"<<endl; 
    cout<<"Type 1 to Start New Game"<<endl; 
    cout<<"Type 2 to Close Application"<<endl; 
    cin>>p1_input; 
    } while (p1_input>=1 && p1_input<=4); 

//********MENU*OPTION*ONE********
    
    //Option 1 -> Start a New Game 
    if (p1_input==1) { 
        //Deal cards and form discard pile 
        for (int j=1; j<=3; j++) { 
            //Player 1, output message and deal cards 
            if (j==1) { 
                cout<<"The dealer will draw 10 cards for Player 1."<<endl; 
                for (int k=0; k<HAND_1; k++) { 
                p1_hand[k]=rand( )%deck; 
                } 
            } 
            //Player 2, output message and deal cards 
            else if (j==2) { 
                cout<<"The dealer will draw 10 cards for Player 2."<<endl; 
                for (int m=0; m<HAND_2; m++) { 
                p2_hand[m]=rand( )%deck; 
                } 
            } 
            //Discard pile, output message and choose a card 
            else if (j==3) { 
                cout<<"Discard Pile: "<<endl; 
                discard=rand( )%deck; 
            } 
        } 
    } 

//********MAIN*GAMEPLAY*AREA**********

        //Start a New Round 
        do { 
            //Begin Initial Turn 
            cout<<"Player 1 will start the round."<<endl; 
            cout<<"Type 1 to draw from the discard pile."<<endl; 
            cout<<"Type 2 to pass your turn."<<endl; 
            cin>>p1_input; 
            //If Player 1 chooses the discard pile 
            if (p1_input==1) { 
                //Prompt Player 1 to draw from the discard pile 
                cout<<"Enter the card drawn from the discard pile."<<endl; 
                cin>>p1_input; 
                //Prompt Player 1 to discard a card from their hand 
                cout<<"Enter a card to discard from your hand."<<endl; 
                cin>>p1_input; 
                //Output message for Player 1 to make melds form their hand 
                cout<<"Make any possible melds in your hand and take "
                    <<"note of the matches on your score sheet."<<endl; 
                //Begin Second Turn 
                cout<<"Type 1 to draw from the discard pile."<<endl; 
                cout<<"Type 2 to draw from the stockpile."<<endl; 
                //If Player 2 chooses to draw from discard pile 
                if (p2_input==1) { 
                    //Prompt Player 2 to draw from the discard pile 
                    cout<<"Enter the card drawn from the discard pile."<<endl; 
                    cin>>p2_input; 
                    //Prompt Player 2 to discard a card from their hand 
                    cout<<"You have chosen to draw "<<p2_input<<endl; 
                    cout<<"Enter a card to discard from your hand."<<endl; 
                    cin>>p2_input; 
                    //Output message for Player 1 to make melds from their hand 
                    cout<<"Make any possible melds in your hand and take "
                        <<"note of the matches on your score sheet."<<endl; 
                    } 
                //If Player 2 chooses to pass their turn 
                else if (p2_input==2) {  
                    cout<<"You have chosen to pass your turn."<<endl; 
                } 
                else { 
                cout<<"Please choose one of the above options."<<endl; 
                } 
            }    

            //If Player 1 chooses to pass their turn 
            else if (p1_input==2) { 
                cout<<"You have chosen to pass your turn."<<endl; 
            } 
            else { 
                cout<<"Please choose one of the above options."<<endl; 
            }
            
            //Write points to Player 1 Scoresheet file 
                  
            //Write points to Player 2 Scoresheet file 
            
            } while (p1_score<100 && p2_score<100); 

            //Output winning score 
            if (p1_score>=100 || p2_score>=100) { 
                (p1_score>=100)? winner=plyr1: winner=plyr2; 
                cout<<fixed<<setprecision(2)<<showpoint; 
                cout<<"The winner is "<<winner<<" !"<<endl;  
            } 

//********MENU*OPTION*TWO********
    
    //Option 2 -> EXIT APPLICATION 
    else if (p1_input==2) { 
        cout<<"You have chosen to exit the game."<<endl; 
    } 

//********MENU*ERROR*MESSAGE********
    
    //Output default message if Options 1-4 not selected 
    else 
        cout<<"Please select an option from the Main Menu."<<endl; 
    
    //Clean up the code, close files, deallocate memory, etc....
    //Exit stage right
    return 0;
} 

//*****************END*OF*FUNCTION*MAIN*******************

//Function Definition for Card Deck 
void forDeck(string cards, int size) { 

    //Read in card values from input file 
    ifstream crdFile; 
    crdFile.open("Project2_CardDeck.docx"); 
    for (int i=0; i<size; i++) { 
        crdFile>>cards[i]; 
    } 
    crdFile.close( ); 
} 

//Function Definition for Dealing Cards 
void plyDeal(string toDeck, int limit) { 
    
    //Deal 10 cards to the player's hand 
    string i=rand( )%toDeck; 
    
} 





