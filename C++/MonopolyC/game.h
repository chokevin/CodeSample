#include <iostream>
#include <vector>
#include <string>
#define MAXSIZE 40

using namespace std;
class Player;
class Property;

class Game{

public:
    
    /* Constructor and Deconstructor for the Monopoly Game */
    Game();
    ~Game();


    /* Game setup functions. These are the functions that serve as the main recurring functions that the monopoly game is played from. It holds the
    interface between the various other functions */
    void menu();   
    void selection(char Action); 

    /* Initializing Functions. These are the functions which initialize various parts of the game including the board, players, and trading */
    void init_trade();
    void init_board();
    void init_game();



    /* Function to buy or sell houses. These functions allow for the menu to access another menu about buying or selling houses
    Currently not developed yet */

    void buyhouse();
    void sellhouse();

    /* Game functions
    These are the functions that are used to do basic move in the game like rolling the dice and such */

    void moveplayer();
    void gotojail();
    void maketrade(int player);
    string findproperty(int input);
    int propertynumber(int input);
    void checkgame();
    /* This function rolls the dice and returns the amount of space the player moves 
       It uses the sleep function in order to offset the random function that uses the
       the time variable for randomness.*/
    int roll_dice();


    /* Display functions
    These functions display various information about the game. 
    Currently the board display needs to still be developed */

    void displaymoney();
    void displayboard();
    void updatepositions();

    /* Tile Functions 
    These functions determine how to interact with property tiles */
    void updatemonopoly();
    bool buyproperty();
    bool buyrailroad();
    bool buyutility();
    void auctionproperty();
    void checkproperties();
    bool bidproperty(int player);
    void jailcheck();
    int checkrailroads();
    int checkutilities();
    
    /* Functions which indicate what actions to take when landing on a specific tile. These were made in supplement to the ID number that can be obtained from 
    the Property class.*/

    void propertytile();
    void railroadtile();
    void utilitytile();
    void jailtile();
    void parkingtile();
    void chancetile();
    void chesttile();
 


    
private: 
    void init_to_empty();
    vector<Player> players;
    vector<Property> board;
    int turn;
    int dice1;
    int dice2; 
    int counter;
    int auctionmoney;
    int tax;
    int numplayers;
    int houses;
    char boardarray[23][45];

};

/* Functions to perform basic housekeeping for the menus */
void makeline();
void fourplayers(int turn);
void threeplayers(int turn);
void twoplayers(int turn);

