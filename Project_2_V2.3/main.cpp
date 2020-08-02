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
void plyDeal(string [ ], string [ ], int); //deals cards 
int trnOpt1(string [ ]);  //discard pile or pass turn 
int trnOpt2(string [ ]); //discard pile or stock pile 
int trnOpt3(string [ ]); //draws from stock pile 
bool chckAns(string[ ], int); //validate player input values 
void update(string [ ], int, int); //updates card arrays 

//Execution of Code Begins Here 
int main(int argc, char** argv) { 
    //Set the random number seed here 
    srand(static_cast<unsigned int>(time(0))); 

    
    //*************DECLARE*VARIABLES*************// 

    //Declare all variables for this function 
    const int DECK=52, //52 cards in a deck 
                    CARDS=10; //10 cards in each player's hand 
    int    p1Input, p2Input, nStock;    
    float p1Score, p2Score; 
    string plyr1="Player 1",  
               plyr2="Player 2", 
               discard; //discarded card value 
    
    //Declare arrays 
    string crdDeck[DECK],   //card deck array 
               stckPle[DECK],    //stock pile array 
               p1Hand[CARDS],  //Player 1 hand array 
               p2Hand[CARDS]; //Player 2 hand array 
    
    //Initialize card deck 
    ifstream getCrds; //input file 
    //Open input file 
    getCrds.open("Project2_CardDeck.docx"); 
    //Read in card values 
    for (int i=0; i<DECK; i++) { 
        getCrds>>crdDeck[i]; 
    } //End of reading in values 
    //Close input file 
    getCrds.close( ); 
    
    //Initialize Stock Pile Array 
    for (int j=0; j<DECK; j++) { 
        //Copy card deck values to stock pile values 
        stckPle[j]=crdDeck[j]; 
    } //End of initializing stock pile array 

    //*************MAIN*MENU*************// 

    //Main Menu Options 
    cout<<"Main Menu"<<endl; //Title for Main Menu 
    cout<<"Choose one of the following:"<<endl; //Prompt to choose a menu option 
    cout<<"Type 1 to Start New Game"<<endl;     //Option 1 starts a new game 
    cout<<"Type 2 to Close Application"<<endl;   //Option 2 closes the application 
    cin>>p1Input; //main menu, player 1 only (player 2 is computer) 
    
    //*************START*OF*GAME*************// 
    
    //Option 1, start a new game 
    if (p1Input==1) { 
        //Output message to players 
        cout<<"A new game has started."<<endl; 
        
        //**********ROUND*TURNS**********// 
        
        //Start of round turns 
        do { 
            //Output message to players 
            cout<<"The dealer will now draw 10 cards for each player."<<endl; 
            //Call function to deal cards to Player 1 
            plyDeal(p1Hand, stckPle, CARDS); 
            //Call function to deal cards to Player 2 
            plyDeal(p2Hand, stckPle, CARDS); 
            //Output message to players 
            cout<<"The dealer will now form the discard pile."<<endl; 
            //Output message to start discard pile 
            cout<<"Discard Pile: "<<endl; 
            //Choose a card from the stock pile 
            discard=rand( )%nStock; 
            //Find location of discarded card in the stock pile 
            int index; 
            for (int k=0; k<DECK; k++) { 
                if (discard==stckPle[k]) { 
                    index=k; 
                } 
            } 
            //Call function to update the stock pile 
            update(stckPle, index, DECK); 

            //**********INITIAL*TURN**********// 

            //Player 1 will have initial turn 
            cout<<"Player 1 will start the round."<<endl; 
            //Call function "discard/pass" for initial turn 
            p1Input=trnOpt1(p1Hand); 

            //**********SECOND*TURN**********// 

            //Player 2 will have second turn 
            cout<<"Player Two, it's now your turn."<<endl; 
            //Call a function for second turn 
            (p1Input==1)? 
                //p1Input is 1, call function "discard/pass" 
                trnOpt1(p2Hand): 
                //p1Input is 2, call function "discard/stock" 
                trnOpt2(p2Hand); 

            //************THIRD*TURN************// 

            //Player 1 will have third turn 
            cout<<"Player One, it is your turn again."<<endl; 
            //Call a function for third turn 
            (p1Input==2 && p2Input==2)? 
                //both input values 2, call function "stock pile" 
                trnOpt3(p2Hand): 
                //neither input value 2, call function "discard/stock" 
                trnOpt2(p2Hand); 

            //********ALL*OTHER*TURNS********// 

            do { 
                //Declare and initialize turn counter 
                int count=1; 
                //Determine which player has turn 
                (count%2!=0)? 
                    p1Input=trnOpt2(p1Hand): 
                    p2Input=trnOpt2(p2Hand);  
                //Update turn counter 
                count++; 
            } while (p1Input!=3 && p2Input!=3); //End of round 
            
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

//Function Definition for Dealing Cards 
void plyDeal(string plyrHnd[ ], string stock[ ], int hand) { 
    //Deal 10 cards to the player  
    for (int i=0; i<hand; i++) { 
        //Use rand gen to pick a card from the stock pile 
        int nElmnt=rand( )%52; 
        //Add element's value to player's hand 
        plyrHnd[i]=stock[nElmnt]; 
        //Call function to update stock pile 
        update(stock, nElmnt, hand); 
    } //End of dealing 10 cards 
} //End of function for dealing cards 

//Function Definition for Discard Pile or Pass 
int trnOpt1(string hand[ ]) { 
    //Declare and initialize variables 
    int plyInpt; 
    //Choice of discard pile or pass turn 
    cout<<"Type 1 to draw from the discard pile."<<endl; 
    cout<<"Type 2 to pass your turn."<<endl; 
    //Use do-while Loop for input validation 
    do { 
        //Get player input for turn
        cin>>plyInpt; 
        //If Player does not choose either option 
        if (plyInpt!=1 && plyInpt!=2) { 
            cout<<"Please choose from one of the options."<<endl; 
        } 
    } while (plyInpt!=1 && plyInpt!=2); //End of do-while Loop 
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
    //Return player input value 
    return plyInpt; 
} //End of function for "discard/pass" turn option 

//Function Definition for Choosing Discard or Stock Pile 
int trnOpt2(string plyrHnd[ ]) { 
    //Declare and initialize variables 
    int plyInpt; 
    //Choice of discard pile or pass turn 
    cout<<"Type 1 to draw from the discard pile."<<endl; 
    cout<<"Type 2 to draw from the stock pile."<<endl; 
    //Use do-while Loop for input validation 
    do { 
        //Get player input for turn
        cin>>plyInpt; 
        //Validate player input 
        if (plyInpt!=1 && plyInpt!=2) { 
            cout<<"Please choose from one of the options."<<endl; 
        } 
    } while (plyInpt!=1 && plyInpt!=2); //End of do-while Loop 
    //Option 1, draw from discard pile 
    if (plyInpt==1) { 
        //Prompt to draw card 
        cout<<"Draw a card from the discard pile."<<endl; 
        cin>>plyInpt; 
        //Update player's hand 
        plyrHnd[10]=plyInpt; 
        //Display player's hand 
        for (int i=0; i<=10; i++) { 
            cout<<(i+1)<<". "<<plyrHnd[i]<<" "; 
        } //End of for Loop 
        //Prompt to discard card from hand 
        cout<<"Choose a card to discard from your hand."<<endl; 
        cout<<"Note: You cannot choose the card you just drew."<<endl; 
        //Declare and initialize input validation variable 
        bool valid=false; 
        //Use do-while Loop for input validation 
        do { 
            //Get player input 
            cin>>plyInpt; 
            //Call function to validate input 
            valid=chckAns(plyrHnd, plyInpt); 
        } while (valid==false); //End of input validation 
        //Update player's hand 
        for (int i=0; i<10; i++) { 
            //Delete discarded card from hand 
            if (plyInpt==(i+1)) plyrHnd[i]=" "; 
            //Shift cards following the discarded card 
            if (plyrHnd[i-1]==" ") plyrHnd[i-1]=plyrHnd[i]; 
        } //End of updating player's hand  
        //Prompt to form melds 
        cout<<"Make any possible melds."<<endl; 
        cout<<"Take note of the matches."<<endl; 
    } //End of Option 1 game play 
    //Option 2, draw from stock pile 
    else if (plyInpt==2) trnOpt3(plyrHnd); 
    //Return player input value 
    return plyInpt; 
} //End of function for "discard/stock" turn option 

//Function Definition for Drawing from Stock Pile 
int trnOpt3(string plyrHnd[ ]) { 
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
        cout<<(i+1)<<". "<<plyrHnd[i]<<" "; 
    } 
    //Get player input 
    cin>>plyInpt; 
    //Prompt to form melds 
    cout<<"Make any possible melds."<<endl; 
    cout<<"Take note of the matches."<<endl; 
    //Return player input value 
    return plyInpt; 
} //End of function for "stock pile" turn option 
                
//Function Definition for Input Validation 
bool chckAns(string plyrHnd[ ], int input) { 
    //Declare and initialize variables 
    bool inptVld=false; 
    int match=0; 
    //Check input against player hand 
    for (int check=0; check<10; check++) { 
        if (input==check) match++; 
    } 
    //Update input validation variable 
    (match==1)? inptVld=true: inptVld=false; 
    //Output message if invalid input 
    if (inptVld==false) { 
        //Output message for input of drawn card 
        if (input==11) { 
        cout<<"Please select a card from your hand"; 
        cout<<"other than the card you just drew."<<endl; 
        } 
        //Output message for any other invalid input 
        else { 
        cout<<"Please select one card from your hand."<<endl; 
        cout<<"You cannot choose the card you just drew."<<endl; 
        }  
    } //End of "error messages" if statement 
    //Return validation result 
    return inptVld; 
} //End of function for input validation 

//Function Definition for Updating Card Arrays 
void update(string array[ ], int arrElem, int crdLmt) { 
    //Delete element's value from the array 
    array[arrElem]=" "; 
    //Update all other element values 
    for (int i=0; i<crdLmt; i++) { 
        //Shift element values following changed element 
        (array[i-1]==" ")? array[i-1]=array[i]: array[i-1]; 
    } //End of updating element values 
} //End of function for updating card arrays 







