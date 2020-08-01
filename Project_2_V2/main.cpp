/* 
 * File:   main.cpp
 * Author: Sarah Shima 
 * Created on July 27, 2020, 8:00 PM 
 * Purpose: Project 2 - Gin Rummy Card Game 
 * Version Details: game played with two users 
 * as the players, computer will be the dealer 
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
void forDeck(string &, int); //reads in deck of cards 
void plyDeal(string &, int); //deals cards to each player 
void trnOpt1(string &, int &);  //choice of discard pile or pass turn 
void trnOpt2(string &, int &); //choices of discard pile or stock pile 
void trnOpt3(string &); //player must draw from stock pile 

//Execution of Code Begins Here 
int main(int argc, char** argv) { 
    //Set the random number seed here 
    srand(static_cast<unsigned int>(time(0))); 

    //*************DECLARE*VARIABLES*************// 

    //Declare all variables for this function 
    char nCards=52,  //52 cards in a deck 
             nPlyrs=2,     //2 players for version 2 
             plyrHnd=10, //10 card plus one extra 
             suit,  //card suit value 
             face; //card face value 
    bool testNum; //tracks output to files 
    int  p1Input, p2Input, //player game choice input 
          p1Rslt, p2Rslt; //player turn option chosen 
    float p1Score, p2Score; //to record player scores 
    string plyr1="Player 1", plyr2="Player 2", //player names 
               discard; //value of discarded card 
    
    //Declare Card Deck Array 
    const int DECK=52; //52 cards in a deck 
    string crdDeck[DECK]; //card deck array 
    
    //Initialize Card Deck Array 
    forDeck(crdDeck[ ], DECK); //read in from card file 
    
    //Declare Player Card Arrays 
    const int CARDS=10; //10 cards plus one extra 
    string p1Hand[CARDS], //Player 1 hand array 
               p2Hand[CARDS]; //Player 2 hand array 

    //*************MAIN*MENU*************// 

    //Main Menu Options 
    cout<<"Main Menu"<<endl; //Title for Main Menu 
    cout<<"Choose one of the following:"<<endl; //Prompt to choose a menu option 
    cout<<"Type 1 to Start New Game"<<endl;     //Option 1 starts a new game 
    cout<<"Type 2 to Close Application"<<endl;   //Option 2 closes the application 
    cin>>p1Input; //main menu Input for player 1 (none for computer player 2) 
    
    //*************START*OF*GAME*************// 
    
    //Option 1, start a new game 
    if (p1Input==1) { 

    //Output message to players 
    cout<<"A new game has started."<<endl; 
        
        //**********ROUND*TURNS**********// 
        
        do { 
            //Output message to players 
            cout<<"The dealer will now draw 10 cards for each player."<<endl; 
            //Deal 10 cards to Player 1 
            plyDeal(p1Hand[ ], CARDS); 
            //Deal 10 cards to Player 2 
            plyDeal(p2Hand[ ], CARDS); 
            //Output message to players 
            cout<<"The dealer will now form the discard pile."<<endl; 
            //Start discard pile 
            cout<<"Discard Pile: "<<endl; 
            cout<<face<<suit<<" "<<endl; 

            //**********INITIAL*TURN**********// 

            //Player 1 will have initial turn 
            cout<<"Player 1 will start the round."<<endl; 
            //Call function "discard/pass" for initial turn 
            trnOpt1(p1Hand, p1Rslt); 

            //**********SECOND*TURN**********// 

            //Player 2 will have second turn 
            cout<<"Player Two, it's now your turn."<<endl; 
            //Call a function for Player Two's turn 
            (p1Input==1)? 
                trnOpt1(p2Hand, p2Rslt): 
                trnOpt2(p2Hand, p2Rslt); 

            //************THIRD*TURN************// 

            //Player 1 will have third turn 
            cout<<"Player One, it is your turn again."<<endl; 
            //Call a function for Player One's turn 
            (p1Input==2 && p2Input==2)? 
                trnOpt2(p2Hand, p2Rslt): 
                trnOpt3(p2Hand, p2Rslt); 

            //********ALL*OTHER*TURNS********// 

            do { 
                //Declare and initialize turn counter 
                int count=1; 
                //Determine which player has turn 
                (count%2!=0)? 
                    trnOpt2(p1Hand, p1Rslt): 
                    trnOpt2(p2Hand, p2Rslt);  
                //Update turn counter 
                count++; 
            } while (p1Rslt!=3 && p1Rslt!=3); //End of round turns 
            
            //********ROUND*SCORING********// 
            
            //Award points for knocking 
            
            //Award points for Gin 
            
            //Award points for Big Gin 
            
            //Store player scores in output files 
            
        } while (p1Score<100 && p2Score<100); //End of game 

        //Output winning score 
        if (p1Score>=100) { 
            cout<<fixed<<setprecision(2)<<showpoint; 
            cout<<"The winning score is "<<p1Score<<endl; 
        } 
        else if (p2Score>=100) { 
            cout<<fixed<<setprecision(2)<<showpoint; 
            cout<<"The winning score is "<<p2Score<<endl; 
        } 
    } //End of Option 1 
    
    //Option 2, close application 
    else if (p1Input==2) { 
        cout<<"You have chosen to exit the game."<<endl; 
    } 

    //Default message, choose one of the options 
    else if (p1Input!=1 && p1Input!=2) { 
        cout<<"Please select an option from the Main Menu."<<endl; 
    } 

    //Clean up the code, close files, deallocate memory, etc....
    //Exit stage right
    return 0; 
} //End of function main 

//***********FUNCTION*DEFINITIONS***********// 

//Function Definition for Reading in Card Deck 
void forDeck(string &deck, int limit) { 
    ofstream getCrds; 
    getCrds.open("Project2_CardDeck.docx"); 
    for (int i=0; i<limit; i++) { 
            getCrds>>deck[i]; 
    } 
    getCrds.close( ); 
} 

//Function Definition for Dealing Cards 
void plyDeal(char &plyrHnd[ ], int size) { 
    //Declare and initialize variables 
    char suit, face; 
    //Deal 10 cards to each player 
    for (int i=0; i<size; i++) { 
        //Use random generator 
        int i=rand( )%10; 
        //Determine suit values 
        if (i<=12) suit='S'; 
        else if (i<=25) suit='D'; 
        else if (i<=38) suit='C'; 
        else suit='H'; 
        //Determine face values 
        switch (i%13+1) {
            case 1: face='A'; break; 
            case 2: face='2'; break; 
            case 3: face='3'; break; 
            case 4: face='4'; break; 
            case 5: face='5'; break; 
            case 6: face='6'; break; 
            case 7: face='7'; break; 
            case 8: face='8'; break; 
            case 9: face='9'; break; 
            case 10: face='T'; break; 
            case 11: face='J'; break; 
            case 12: face='Q'; break; 
            case 13: face='K'; break; 
            default: cout<<"Bad Condition"<<endl; 
        } 
    } 
} //End of function for dealing cards 

//Function Definition for Turn, Discard Pile or Pass 
void trnOpt1(string &hand, int plyInpt) { 
    //Declare and initialize variables 
    int plyInpt; 
    //Choice of discard pile or pass turn 
    cout<<"Type 1 to draw from the discard pile."<<endl; 
    cout<<"Type 2 to draw from the stock pile."<<endl; 
    //Use do-while Loop for input validation 
    do { 
        //Get player input for turn
        cin>>plyInpt; 
        //Update player's hand 
        hand[10]=plyInpt; 
        //If Player chooses Option 1 
        if (plyInpt==1) { 
            //Prompt to draw card 
            cout<<"Draw card from the discard pile."<<endl; 
            cin>>plyInpt; 
            //Prompt to discard card from hand 
            cout<<"Choose a card to discard from your hand."<<endl; 
            //Display player's hand 
            for (int i=0; i<10; i++) { 
            cout<<(i+1)<<". "<<hand[i]<<" "; 
            } 
            //Get player input 
            cin>>plyInpt; 
            //Update player's hand 
            for (int i=0; i<10; i++) { 
                //Delete discarded card from hand 
                if (plyInpt==hand[i]) { 
                    hand[i]=" "; 
                } 
                //Shift all other cards in hand 
                else { 
                    //Check if previous card removed 
                    if (hand[i-1]==" ") { 
                        //Shift cards over one 
                        hand[i-1]=hand[i]; 
                    } 
                } 
            } 
            //Prompt to form melds 
            cout<<"Make any possible melds."<<endl; 
            cout<<"Take note of the matches."<<endl; 
        } 
        //If Player chooses Option 2 
        else if (plyInpt==2) { 
            //Prompt to draw card 
            cout<<"Draw card from the stock pile."<<endl; 
            cin>>plyInpt; 
            //Update player's hand 
            hand[10]=plyInpt; 
            //Prompt to discard card from hand 
            cout<<"Choose a card to discard from your hand."<<endl; 
            //Display player's hand 
            for (int i=0; i<10; i++) { 
                cout<<(i+1)<<". "<<hand[i]<<" "; 
            } 
            //Get player input 
            cin>>plyInpt; 
            //Update player's hand 
            for (int i=0; i<10; i++) { 
                //Delete discarded card from hand 
                if (plyInpt==hand[i]) { 
                    hand[i]=" "; 
                } 
                //Shift all other cards in hand 
                else { 
                    //Check if previous card removed 
                    if (hand[i-1]==" ") { 
                        //Shift cards over one 
                        hand[i-1]=hand[i]; 
                    } 
                } 
            } 
            //Prompt to form melds 
            cout<<"Make any possible melds."<<endl; 
            cout<<"Take note of the matches."<<endl; 
        } 
        //If Player does not choose either option 
        else { 
            cout<<"Please choose one of the options."<<endl; 
        } 
    } while (plyInpt!=1 && plyInpt!=2); 
} //End of function for "discard/pass" turn option 

//Function Definition for Turn, Discard Pile or Stock Pile 
void trnOpt2(string &hand, int plyInpt) { 
    //Declare and initialize variables 
    int plyInpt; 
    //Choice of discard pile or pass turn 
    cout<<"Type 1 to draw from the discard pile."<<endl; 
    cout<<"Type 2 to pass your turn."<<endl; 
    //Use do-while Loop for input validation 
    do { 
        //Get player input for turn
        cin>>plyInpt; 
        //If Player chooses Option 1 
        if (plyInpt==1) { 
            //Prompt to draw card 
            cout<<"Draw card from the discard pile."<<endl; 
            cin>>plyInpt; 
            //Prompt to discard card from hand 
            cout<<"Choose a card to discard from your hand."<<endl; 
            //Display player's hand 
            for (int i=0; i<10; i++) { 
            cout<<(i+1)<<". "<<hand[i]<<" "; 
            } 
            //Get player input 
            cin>>plyInpt; 
            //Prompt to form melds 
            cout<<"Make any possible melds."<<endl; 
            cout<<"Take note of the matches."<<endl; 
        } 
        //If Player chooses Option 2 
        else if (plyInpt==2) { 
            cout<<"You have chosen to pass your turn."<<endl; 
        } 
        //If Player does not choose either option 
        else { 
            cout<<"Please choose one of the options."<<endl; 
        } 
    } while (plyInpt!=1 && plyInpt!=2); 
} //End of function for "discard/stock" turn option 

//Function Definition for Turn, Stock Pile Only 
void trnOpt3(string &hand) { 
    //Declare and initialize variables 
    int plyInpt; 
    //Prompt to draw card 
    cout<<"Draw a card from the stock pile."<<endl; 
    //Get player input 
    cin>>plyInpt; 
    //Prompt to discard card from hand 
    cout<<"Choose a card to discard from your hand."<<endl; 
    //Display player's hand 
    for (int i=0; i<10; i++) { 
        cout<<(i+1)<<". "<<hand[i]<<" "; 
    } 
    //Get player input 
    cin>>plyInpt; 
    //Prompt to form melds 
    cout<<"Make any possible melds."<<endl; 
    cout<<"Take note of the matches."<<endl; 
} //End of function for "stock only" turn option 
                
//*************CODE*TEMPLATES*************// 

//Read in card values from file "Player 1 Hand" 
/*if (j==1) { 
    while (testNum) { 
    ifstream p1Hand; 
    p1Hand.open("Project_1_Player1_Hand.docx"); 
    p1Hand>>p1Crd1>>p1Crd2>>p1Crd3>>p1Crd4>>p1Crd5
          >>p1Crd6>>p1Crd7>>p1Crd8>>p1Crd9>>p1Crd10; 
    p1Hand.close( ); 
    } 
} */ 

//Read card values to Player 2 card variables 
/*if (j==2) { 
    while (testNum) { 
    ifstream p2Hand; 
    p2Hand.open("Project_1_Player2_Hand.docx"); 
    p2Hand>>p2Crd1>>p2Crd2>>p2Crd3>>p2Crd4>>p2Crd5
          >>p2Crd6>>p2Crd7>>p2Crd8>>p2Crd9>>p2Crd10; 
    p2Hand.close( ); 
    } 
} */ 

/* int i=rand()%nCards; 
    char suit; 
    if (i<=12) suit='S'; 
    else if (i<=25) suit='D'; 
    else if (i<=38) suit='C'; 
    else suit='H'; 
    char face; 
    switch (i%13+1) {
        case 1: face='A'; break; 
        case 2: face='2'; break; 
        case 3: face='3'; break; 
        case 4: face='4'; break; 
        case 5: face='5'; break; 
        case 6: face='6'; break; 
        case 7: face='7'; break; 
        case 8: face='8'; break; 
        case 9: face='9'; break; 
        case 10: face='T'; break; 
        case 11: face='J'; break; 
        case 12: face='Q'; break; 
        case 13: face='K'; break; 
        default: cout<<"Bad Condition"<<endl; 
    } */ 


