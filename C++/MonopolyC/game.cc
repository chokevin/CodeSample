#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "game.h"
#include "property.h"
#include "player.h"

using namespace std;

#define MAXSIZE 40 


/* As a general rule... the n variable is used find the correct index of which player's turn it is. 
   n+1 is used because although players[0] refers to player 1 we need to display +1 to get the actual player number. index goes from 0-3 | player number goes from 1-4
   */

/* Constructor and Deconstructor for the game class */
//  This the constructor and deconstructor of the   //
//  Game class. Utilizes private function to init   //
//////////////////////////////////////////////////////   
Game::Game(){
    init_to_empty();
}

Game::~Game(){
    init_to_empty();
}

/* ///////////////Initializing Functions/////////////////*/
//   These are the functions that realize the beginning  //                      
//   of the game. They initialize the board and the game //
///////////////////////////////////////////////////////////
void Game::init_game(){
    board.resize(MAXSIZE);
    cout << "\033[2J\033[1;1H";
    cout << "Initializing Game" << endl;
    makeline();


    // ID 1 = Property
    // ID 2 = Railroad
    // ID 3 = Utility
    // ID 4 = Go
    // ID 5 = Jail
    // ID 6 = Free Parking
    // ID 7 = Chance
    // ID 8 = Community Chest
    // ID 9 = Tax
    // ID 10 = Go to Jail


    init_board();
    cout << "How many players will be playing? (1-4 players):";
    cin >> numplayers;
    players.resize(numplayers);
    for(int i = 0; i < numplayers; i++){
        players[i].editCash(1500);
    }
    cout << "\033[2J\033[1;1H";
    while(1){
        menu();
    }

}

void Game::init_board(){

    board[0].init(4, 0, 0, "Go");
    board[1].init(1, 60, 2, "Mediterranean Ave"); 
    board[2].init(8, 0, 0, "Community Chest");
    board[3].init(1, 60, 4, "Baltic Ave");
    board[4].init(9, 200, 0, "Income Tax");
    board[5].init(2, 200, 0, "Reading Railroad");
    board[6].init(1, 100, 6, "Oriental Ave");
    board[7].init(7, 0, 0, "Chance");
    board[8].init(1, 100, 6, "Vermont Ave");
    board[9].init(1, 120, 8, "Connecticut Ave");
    board[10].init(5, 0, 0, "Jail");
    board[11].init(1, 140, 10, "St. Charles Pl");
    board[12].init(3, 150, 0, "Electric Company");
    board[13].init(1, 140, 10, "States Ave");
    board[14].init(1, 160, 12, "Virginia Ave");
    board[15].init(2, 200, 0, "Pennsylvania Railroad");
    board[16].init(1, 180, 14, "St. James Pl");
    board[17].init(8, 0, 0, "Community Chest");
    board[18].init(1, 180, 14, "Tennessee Ave");
    board[19].init(1, 200, 16, "New York Ave");
    board[20].init(6, 0, 0, "Free Parking");
    board[21].init(1, 220, 18, "Kentucky Ave");
    board[22].init(7, 0, 0, "Chance");
    board[23].init(1, 220, 18, "Indiana Ave");
    board[24].init(1, 240, 20, "Illinois Ave");
    board[25].init(2, 200, 0, "B. & O. Railroad");
    board[26].init(1, 260, 22, "Atlantic Ave");
    board[27].init(1, 260, 22, "Ventnor Ave");
    board[28].init(3, 150, 0, "Water Works");
    board[29].init(1, 280, 24, "Marvin Gardens");
    board[30].init(10, 0, 0, "Go to Jail");
    board[31].init(1, 300, 26, "Pacific Ave");
    board[32].init(1, 300, 26, "North Carolina Ave");
    board[33].init(8, 0, 0, "Community Chest");
    board[34].init(1, 320, 28, "Pennsylvania Ave");
    board[35].init(2, 200, 0, "Short Line Railroad");
    board[36].init(7, 0, 0, "Chance");
    board[37].init(1, 350, 35, "Park Place");
    board[38].init(9, 100, 0, "Luxury Tax");
    board[39].init(1, 400, 50, "Boardwalk");

}

/* /////////////////Game Functions///////////////// */
// These are the functions that set the Functions   //
// of the Game                                      //
//////////////////////////////////////////////////////



// Menu is used when you want to call the main game menu

void Game::menu(){
    char Action;
    int n = (turn%players.size());

    displayboard();
    jailcheck();

    /* this function checks whether the game is still in play or not */
    checkgame();

    cout << "It is Player " << (turn%players.size())+1 << "'s turn" << endl;    
    displaymoney();

    cout << "You are at position " << players[n].getPosition() << " which is " << board[players[n].getPosition()].getName() << endl;
    makeline();
    cout << "What actions would you like to take?" << endl;
    cout << "(R)oll the dice" << endl;	
    cout << "(C)heck owned properties" << endl;
    cout << "(T)rade a property" << endl;    
    cout << "(B)uy a house" << endl;    
    cout << "(S)ell a house" << endl;    	
    cout << "(Q)uit" << endl;
    cin >> Action;
    selection(Action);
}


void Game::selection(char Action){
    while(true){
        switch(Action){
            case 'r':
                cout << "Rolling the Dice" << endl;
                moveplayer();
                menu();
                break;
            case 't':
                cout << "Trading a Property" << endl;
                init_trade();
                menu();
                break;
            case 'b':
                cout << "Buying a House" << endl;
                buyhouse();
                menu();
                break;
            case 's': 
                cout << "Selling a House" << endl;
                sellhouse();
                menu();
                break;
            case 'c':
                cout << "Owned Properties" << endl;
                checkproperties();
                menu();
                break;
            case 'q':
                exit(1);
                break;
            default : 
                cin >> Action;
                break;
        }
    }

}


void Game::moveplayer(){
    int move;
    cout << "\033[2J\033[1;1H";
    move = roll_dice();
    int n = turn%players.size();
    players[n].editPosition(move);
    int check = board[players[n].getPosition()].getID();
    cout << "Player " << n+1 << " landed on " << board[players[n].getPosition()].getName() << endl;
    if(check == 1){

        propertytile();
    }
    else if(check == 2){
        /* This is the code that handles when the player lands on a railroad tile */
        railroadtile();

    }
    else if(check == 3){
        /* This is the code that handles when the player lands on a utility tile */
        utilitytile();
    }
    // else if(check == 4){
    /* This is the code that handles when the player lands on the Go title...?*/
    //   gotile();
    //}
    //else if(check == 5){
    /* This is the code that handles when the player lands on the Jail tile */
    //  jailtile();
    // }
    else if(check == 6){
        /* this is the code that handles when the player lands on the free parking tile */
        parkingtile();
    }
    else if(check == 7){
        /* this is the code that handles when the player lands on the chance tile */
        chancetile();
    }
    else if(check == 8){   
        /* this is the code that handles when the player lands on the community chest tile */
        chesttile();

    }
    else if(check == 9){
        cout << "Lol you landed on some tax bro, but since its the free version of Monopoly just pay us $200" << endl;
        players[n].minusCash(200);

        /* Puts money into the middle for the free parking */
        tax += 200;

    }
    else if(check == 10){
        gotojail();
    } 
    turn++;
}

void Game::init_trade(){

    int n = turn%players.size();
    int input;
    cout << "Initializing Trade" << endl;
    makeline();
    cout << "Who would you like to trade with?" << endl;
    switch(numplayers){
        case 1:
            cout << "Wait what the hell are you doing playing with one player... This isn't Monopoly" << endl;
            break;
        case 2:
            twoplayers(n);
            break;
        case 3:
            threeplayers(n);
            break;
        case 4:
            fourplayers(n);
            break;
    }
    cout << "Player ";
    cin >> input;
    if(input > numplayers){
        cout << "There isn't that many players... Who are you trading with?" << endl;
        init_trade();
    }
    cout << "Trading with Player " << input << endl;
    maketrade(input);
    updatemonopoly();
}

void Game::buyhouse(){
    int n = (turn%players.size()); //get turn player
    int m = 0;
    int number;
    int input;
    int input2;
    string name;
    if(players[n].getproperties()==0) cout << "You don't have any properties" <<endl;
    else{
        for(int b=0;b<39;b++)
        {
            if(board[b].getOwner()==n+1 && board[b].getMonopoly()) m++;
        }
        if(m==0) cout << "You don't have any monopolies" <<endl;
        else if(houses==0) cout << "There are no houses left" <<endl;
        else{
            cout << "Which property would you like to buy a house for? (Choose from 1 - " << players[turn%players.size()].getproperties() << ")" << endl;
            makeline();
            checkproperties();
            cin >> input;
            name = findproperty(input);
            number = propertynumber(input);
            if(board[number].getHouse()!=4 && board[number].getMonopoly()) //if less than 4 houses and monopoly
            {
                players[n].minusCash(150);
                board[number].editHouse(board[number].getHouse()+1);
                cout << "A house was bought on" << name;
                houses--;
            }
        }
    }
}

void Game::sellhouse(){
    int n = (turn%players.size()); //get turn player
    int m = 0;
    int number;
    int input;
    int input2;
    string name;
    if(players[n].getproperties()==0) cout << "You don't have any properties" <<endl;
    else{
        for(int b=0;b<39;b++)
        {
            if(board[b].getOwner()==n+1 && board[b].getHouse()!=0) m++;
        }
        if(m==0) cout << "You don't have any properties with houses" <<endl;
        else{
            cout << "Which property would you like to sell a house for? (Choose from 1 - " << players[turn%players.size()].getproperties() << ")" << endl;
            makeline();
            checkproperties();
            cin >> input;
            name = findproperty(input);
            number = propertynumber(input);
            if(board[number].getHouse()!=0) //if more than 0 houses
            {
                players[n].addCash(150);
                board[number].editHouse(board[number].getHouse()-1);
                cout << "A house was sold on" << name;
                houses++;
            }
        }
    }
}

int Game::roll_dice(){
    srand(time(0));
    dice1 = rand()%6+1;
    cout << "Dice 1 roll:" << dice1 << endl;
    sleep(1);
    dice2 = rand()%6+1;
    cout << "Dice 2 roll:" << dice2 << endl;
    if(dice1 == dice2){
        counter += 1;
    }
    else{
        counter = 0;
    }
    return dice1+dice2;
}    

void Game::updatemonopoly(){
    for(int b=0;b<39;b++) //for all board spaces
    {
        if(board[b].getID()==1)  //if property tile
        {
            if(board[b].getOwner()>0) //and if Property is owned by a player)
            {
                //
                
                if(b==1 || b==3)
                {
                    if(board[1].getOwner() == board[3].getOwner())
                    {
                        board[1].setMonopoly(true);
                        board[3].setMonopoly(true);
                    }
                    else
                    {
                        board[1].setMonopoly(false);
                        board[3].setMonopoly(false);
                    }
                }
                
                if(b==6 || b==8 || b==9)
                {
                    if(board[6].getOwner() == board[8].getOwner() && board[8].getOwner() == board[9].getOwner())
                    {
                        board[6].setMonopoly(true);
                        board[8].setMonopoly(true);
                        board[9].setMonopoly(true);
                    }
                    else
                    {
                        board[6].setMonopoly(false);
                        board[8].setMonopoly(false);
                        board[9].setMonopoly(false);
                    }
                }
                
                if(b==11 || b==13 || b==14)
                {
                    if(board[11].getOwner() == board[13].getOwner() && board[13].getOwner() == board[14].getOwner())
                    {
                        board[11].setMonopoly(true);
                        board[13].setMonopoly(true);
                        board[14].setMonopoly(true);
                    }
                    else
                    {
                        board[11].setMonopoly(false);
                        board[13].setMonopoly(false);
                        board[14].setMonopoly(false);
                    }
                }
                
                if(b==16 || b==18 || b==19)
                {
                    if(board[16].getOwner() == board[18].getOwner() && board[18].getOwner() == board[19].getOwner())
                    {
                        board[16].setMonopoly(true);
                        board[18].setMonopoly(true);
                        board[19].setMonopoly(true);
                    }
                    else
                    {
                        board[16].setMonopoly(false);
                        board[18].setMonopoly(false);
                        board[19].setMonopoly(false);
                    }
                }
                
                if(b==21 || b==23 || b==24)
                {
                    if(board[21].getOwner() == board[23].getOwner() && board[23].getOwner() == board[24].getOwner())
                    {
                        board[21].setMonopoly(true);
                        board[23].setMonopoly(true);
                        board[24].setMonopoly(true);
                    }
                    else
                    {
                        board[21].setMonopoly(false);
                        board[23].setMonopoly(false);
                        board[24].setMonopoly(false);
                    }
                }
                
                if(b==26 || b==27 || b==29)
                {
                    if(board[26].getOwner() == board[27].getOwner() && board[27].getOwner() == board[29].getOwner())
                    {
                        board[26].setMonopoly(true);
                        board[27].setMonopoly(true);
                        board[29].setMonopoly(true);
                    }
                    else
                    {
                        board[26].setMonopoly(false);
                        board[27].setMonopoly(false);
                        board[29].setMonopoly(false);
                    }
                }
                
                if(b==31 || b==32 || b==34)
                {
                    if(board[31].getOwner() == board[32].getOwner() && board[32].getOwner() == board[34].getOwner())
                    {
                        board[31].setMonopoly(true);
                        board[32].setMonopoly(true);
                        board[34].setMonopoly(true);
                    }
                    else
                    {
                        board[31].setMonopoly(false);
                        board[32].setMonopoly(false);
                        board[34].setMonopoly(false);
                    }
                }
                
                if(b==37 || b==39)
                {
                    if(board[37].getOwner()== board[39].getOwner())
                    {
                        board[37].setMonopoly(true);
                        board[39].setMonopoly(true);
                    }
                    else
                    {
                        board[37].setMonopoly(false);
                        board[39].setMonopoly(false);
                    }
                }
                
            }
        }
    }
    
    
    
    
}

bool Game::buyproperty(){
    char input;
    int n = (turn%players.size());
    cout << "Buying the property" << endl;
    cout << "Would you like to buy " << board[players[n].getPosition()].getName() << "? (y or n):";
    cin >> input; 
    if( input == 'y'){
        players[n].minusCash(board[players[n].getPosition()].getPrice());
        board[players[n].getPosition()].editOwner(n+1);
        cout << board[players[n].getPosition()].getName() << " was bought by Player " << n+1 << "!" << endl;
        players[n].addproperties();
        updatemonopoly();
        return true;
    }
    else if ( input == 'n'){
        return false;
    }
    buyproperty();
    return false;
}

bool Game::buyrailroad(){
    char input;
    int n = (turn%players.size());
    cout << "Buying the railroad" << endl;
    cout << "Would you like to buy " << board[players[n].getPosition()].getName() << "? (y or n):";
    cin >> input; 
    if( input == 'y'){
        players[n].minusCash(board[players[n].getPosition()].getPrice());
        board[players[n].getPosition()].editOwner(n+1);
        cout << board[players[n].getPosition()].getName() << " was bought by Player " << n+1 << "!" << endl;
        players[n].addproperties();
        return true;
    }
    else if ( input == 'n'){
        return false;
    }
    buyrailroad();
    return false;
}

bool Game::buyutility(){
    char input;
    int n = (turn%players.size());
    cout << "Buying the utility" << endl;
    cout << "Would you like to buy " << board[players[n].getPosition()].getName() << "? (y or n):";
    cin >> input; 
    if( input == 'y'){
        players[n].minusCash(board[players[n].getPosition()].getPrice());
        board[players[n].getPosition()].editOwner(n+1);
        cout << board[players[n].getPosition()].getName() << " was bought by Player " << n+1 << "!" << endl;
        players[n].addproperties();
        return true;
    }
    else if ( input == 'n'){
        return false;
    }
    buyutility();
    return false;
}

void Game::auctionproperty(){

    /* This still needs to be worked on */

    bool flag = false;
    vector<bool> check;
    char choice;
    int i = 0;
    int n = turn%players.size();
    check.resize((players.size()), false);
    cout << "Welcome to the Auction!" << endl;
    makeline();
    while(!flag){
        check[i] = bidproperty(n+i);
        i++;
        if(i == 4){
            i = 0;
        }
        if(check[0] == true && check[1] == true && check[2] == true && check[3] == true){
            flag = true;
        }
    }
    cout << "Winner of this auction is Player " << n+i << "for $" << auctionmoney << endl;
    players[n+i].minusCash(auctionmoney);
    board[players[n].getPosition()].editOwner(n);
    auctionmoney = 0;
    updatemonopoly();
}

bool Game::bidproperty(int player){

    return true;

}

void Game::checkproperties(){
    int owner;
    int counter = 1;
    int n = turn%players.size();
    cout << "Checking Properties:" << endl;
    makeline();
    for(int i = 0; i < board.size(); i++){
        owner = board[i].getOwner();
        if(owner == n+1){
            if(board[i].getID()==1){
                cout << "You own: " << counter << ". " << board[i].getName() << " - It has " << board[i].getHouse() << " houses." <<endl;
            }
            else{
                cout << "You own: " << counter << ". " << board[i].getName() <<endl;
            }
            counter++;
        }
    }
}

string Game::findproperty(int input){
    int owner;
    int counter = 1;
    int n = turn%players.size();
    for(int i = 0; i < board.size(); i++){
        owner = board[i].getOwner();
        if(owner == n+1){
            counter++;
        }
        if(counter == input){
            return board[i].getName();
        }

    }  
    return "You don't have a property?";  
}

void Game::propertytile(){
    int n = turn%players.size();
    /* This is the code to handle when the player lands on a property tile */
    if(board[players[(turn%players.size())].getPosition()].getOwner() == 0){
        bool flag = buyproperty();
        if(!flag){
            //auctionproperty();
        }
    }
    else if(board[players[n].getPosition()].getOwner() != n+1){
        int money = board[players[n].getPosition()].getRent();
        cout << "Player " << board[players[n].getPosition()].getOwner() << " owns this property, you pay him $" << money << endl;     
        players[(board[players[n].getPosition()].getOwner())-1].addCash(money);
        players[n].minusCash(money);
    }
}

void Game::railroadtile(){
    int n = turn%players.size();
    /* This is the code to handle when the player lands on a property tile */
    if(board[players[(turn%players.size())].getPosition()].getOwner() == 0){
        bool flag = buyrailroad();
        if(!flag){
            //auctionproperty();
        }
    }

    else if(board[players[n].getPosition()].getOwner() != n+1){
        int check = checkrailroads();
        int money;
        if(check == 1){
            money = 25;
        }
        if(check == 2){
            money = 50;
        }
        if(check == 3){
            money = 100;
        }
        if(check == 4){
            money = 200;
        }
        players[board[players[n].getPosition()].getOwner()].addCash(money);
        players[n].minusCash(money);
    }
}

void Game::chancetile(){

    /* Currently this is the function for chance... new updates have been added to increase the amount of options for chance. 
       The switch statement allows for an easy way to increase the amount of chance cards... */

    int choice;
    srand(time(0));
    choice = rand()%10;
    int n = turn%players.size();
    /* This switch statement chooses at random the chance card that is selected for the player that lands on it. This can be either increased
       or decreased very simply by adding more case choices. Currently can be further developed.
       */\

    switch(choice){
        case 0:
            cout << "You landed on Chance!... You get $200!" << endl;
            players[n].addCash(200);
            break;
        case 1:
            cout << "You landed on Chance!... You get sent to Jail!" << endl;
            players[n].changePosition(19);
            players[n].editJail(true);
            break;
        case 2:
            cout << "You landed on Chance!... You get a free pass to Go! (also $200)" << endl;
            players[n].changePosition(0);
            players[n].addCash(200);
            break;
        case 3:
            cout << "You landed on Chance!... move to Reading Railroad" << endl;
            if(players[n].getPosition() > 5){
                players[n].addCash(200);
                players[n].changePosition(5);
            }
            break;

        case 4:
            cout << "You landed on Chance!... Nothing happens... Better support the developers for more updates!" << endl;
            break;
        case 5:
            cout << "You landed on Chance!... You get $50!" << endl;
            players[n].addCash(50);
            break;
        case 6:
            cout << "You landed on Chance!... You get $10!" << endl;
            players[n].addCash(10);
            break;
        case 7:
            cout << "You landed on Chance!... Move to Broadway!" << endl;
            players[n].changePosition(39);
            break;
        case 8:
            cout << "You landed on Chance!... Move to Income Tax!" << endl;
            players[n].changePosition(4);
            cout << "Lol Bro you landed on chance!... But since this is the free version give us $200!" << endl;
            players[n].minusCash(200);
            break;
        case 9:
            cout << "You landed on Chance!... You pay $5 to support the developers!... It would be nice if that was true..." << endl;
            players[n].minusCash(5);
            break;
    }


}

void Game::parkingtile(){

    cout << "You landed on Free Parking!... You can collect the money that has been taken as tax: $" << tax << "!'" << endl;
    players[turn%players.size()].addCash(tax);
    tax = 0;

}

void Game::utilitytile(){
    int n = turn%players.size();
    /* This is the code to handle when the player lands on a property tile */
    if(board[players[(turn%players.size())].getPosition()].getOwner() == 0){
        bool flag = buyutility();
        if(!flag){
            //auctionproperty();
        }
    }

    /* Currently this other half of the conditional is wrong as well... the cash distribution for the utilities have not been factored in yet */
    else if(board[players[n].getPosition()].getOwner() != n+1){
        int roll = roll_dice();
        int check = checkutilities();
        if(check == 1){
            players[n].minusCash(roll*4);
            players[board[players[n].getPosition()].getOwner()].addCash(roll*4);
        }
        if(check == 2){
            players[n].minusCash(roll*10);
            players[board[players[n].getPosition()].getOwner()].addCash(roll*10);            
        }
    }

}

void Game::gotojail(){
    int n = turn%players.size();
    cout << "Why you breaking the law for! GO TO JAIL PLAYER " << (n+1) << endl;
    players[n].editPosition(10);
    players[n].editJail(true);


}

void Game::jailtile(){
    int n = turn%players.size();
    cout << "It is Player " << (turn%players.size())+1 << "'s turn" << endl;
    cout << "You are on the jail tile" << endl;
    if(players[n].getJail()){
        cout << "You are currently a prisoner... skipping your turn" << endl;
        turn++;
        players[n].editJail(false);
    }
}

void Game::chesttile(){

    /*This can be updated to include many other chest cards if we like */

    cout << "You landed on Community Chest!... There's only one Community Chest card for now... You get $20!" << endl;
    players[turn%players.size()].addCash(20);

}

void Game::init_to_empty(){
    houses=32;
    auctionmoney = 0;
    tax = 0;
    counter = 0;
    for(int i = 0; i < 23; i++){
        for(int j = 0; j < 45; j++){
            boardarray[i][j] = ' ';
        }
    }
}

void Game::displaymoney(){
    for(int i = 0 ; i < players.size() ; i++){
        cout << "Player " << 1+i << " has $" << players[i].getCash() << " at his disposal" << endl; 
    }
}

void Game::jailcheck(){
    int n = turn%players.size();
    int check = board[players[n].getPosition()].getID();
    if(check == 5){
        jailtile();
    }
}

void Game::maketrade(int player){ 

    string name;
    int number;
    int input;
    int input2;
    cout << "Which property would you like to trade? (Choose from 1 - " << players[turn%players.size()].getproperties() << ")" << endl;
    makeline();
    checkproperties();
    cin >> input;
    name = findproperty(input);
    number = propertynumber(input);
    cout << "How much are you trading it for?" << endl;
    cin >> input2;
    cout << "\033[2J\033[1;1H";
    cout << "Traded " << name <<" to Player " << player << " for $" << input2 << endl;
    board[number].editOwner(player);
    players[turn%players.size()].addCash(input2);
    players[player-1].minusCash(input2);
    updatemonopoly();
}

int Game::checkrailroads(){
    int check = 0;
    int x = 0;
    int n = turn%players.size();
    for(int i = 0; i < 4; i++){ 
        int owner = board[5+x].getOwner();
        if(owner == n+1){
            check++;
        }
        x+=10;
    }
    return check;
}

int Game::checkutilities(){
    int check = 0;
    int n = turn%players.size();
    if(board[12].getOwner() == n+1){
        check++;
    }
    if(board[28].getOwner() == n+1){
        check++;
    }
    return check;
}

int Game::propertynumber(int input){
    int owner;
    int counter = 1;
    int n = turn%players.size();
    for(int i = 0; i < board.size(); i++){
        owner = board[i].getOwner();
        if(owner == n+1){
            counter++;
        }
        if(counter == input){
            return i;
        }

    }  
    return -1;
}

void Game::displayboard(){
   /* Display function is sorta working sorta */
    int i;
    /* resets array */
    for(int i = 0; i < 23; i++){
        for(int j = 0; j < 45; j++){
            boardarray[i][j] = ' ';
        }
    }
    cout << "\033[1;31mMonopoly\033[0m\n";
    for(i = 0; i<23; i++){
        boardarray[i][0] = '|';
        boardarray[i][44] = '|';
        boardarray[i][4] = '|';
        boardarray[i][40] = '|';
    }
    for(i = 1; i <44; i++){
        boardarray[0][i] = '_';
        boardarray[2][i] = '_';
        boardarray[20][i] = '_';
        boardarray[22][i] = '_';
    }
    

    for(i = 1; i<4; i++){
        boardarray[4][i] = '_';
        boardarray[6][i] = '_';
        boardarray[8][i] = '_';
        boardarray[10][i] = '_';
        boardarray[12][i] = '_';
        boardarray[14][i] = '_';
        boardarray[16][i] = '_';
        boardarray[18][i] = '_';
        boardarray[20][i] = '_';
        boardarray[22][i] = '_';
    }
    for(int i = 41; i < 44; i++){
        boardarray[4][i] = '_';
        boardarray[6][i] = '_';
        boardarray[8][i] = '_';
        boardarray[10][i] = '_';
        boardarray[12][i] = '_';
        boardarray[14][i] = '_';
        boardarray[16][i] = '_';
        boardarray[18][i] = '_';
        boardarray[20][i] = '_';
        boardarray[22][i] = '_';        
    }
    for(i = 8; i < 40; i+=4){ 
        boardarray[1][i] = '|';
        boardarray[21][i] = '|';
    }
    boardarray[0][44] = ' ';
    boardarray[0][0] = ' ';
  

    updatepositions();

    for(int j = 0; j<23; j++){
        for(int k = 0; k < 45; k++){
            if( (j == 3 || j == 4 || j == 5 || j == 6) && k == 40){
                cout << "\033[1;31m" << boardarray[j][k] << "\033[0m"; 
            }
            else if((j == 7 || j == 8) && k == 40){
                cout << "\033[1;37m" << boardarray[j][k] << "\033[0m";
            }
            else if((j == 9 || j == 10) && k == 40){
                cout << "\033[1;31m" << boardarray[j][k] << "\033[0m";
            }
            else if((j == 11 || j == 12) && k == 40){
                cout << "\033[1;37m" << boardarray[j][k] << "\033[0m";
            }
            else if((j == 13 || j == 14) && k == 40){
                cout << "\033[1;33m" << boardarray[j][k] << "\033[0m";
            }
            else if((j == 15 || j == 16) && k == 40){
                cout << "\033[1;33m" << boardarray[j][k] << "\033[0m";
            }
            else if((j == 17 || j == 18) && k == 40){
                 cout << "\033[1;37m" << boardarray[j][k] << "\033[0m";   
            }
            else if(j == 19  && k == 40){
                cout << "\033[1;33m" << boardarray[j][k] << "\033[0m";
            }
            else if(j == 20 && (k == 40 || k == 39 || k == 38 || k ==37 || k == 36 || k == 35 || k == 34 || k == 33 || k == 32 || k == 28 || k == 27 || k == 26 || k == 25)){
                cout << "\033[1;32m" << boardarray[j][k] << "\033[0m";
            }
            else if(j == 20 && (k == 31 || k == 30 || k == 29 )){
                cout << "\033[1;37m" << boardarray[j][k] << "\033[0m";
            }
            else if(j == 20 && (k == 24 || k == 23 || k == 22 || k == 21 || k == 20 || k == 19 || k == 18 || k == 17 || k == 16 || k == 11 || k == 10 || k == 9 || k == 8)){
                cout << "\033[1;37m" << boardarray[j][k] << "\033[0m"; 
            }
            else if( j == 20 && (k == 15 || k == 14 || k == 13 || k == 12 || k == 7 || k == 6 || k == 5 || k == 4)){
                cout << "\033[1;34m" << boardarray[j][k] << "\033[0m";
            }
            else if( (j == 19 || j == 16 || j == 15)&& k == 4 ){
                cout << "\033[1;39m" << boardarray[j][k] << "\033[0m";
            }
            else if( (j == 18 || j == 17 || j == 14 || j == 13 || j == 12 || j == 11 || j == 8 || j == 7) && k == 4){
                cout << "\033[1;37m" << boardarray[j][k] << "\033[0m";
            }
            else if( (j == 10 || j == 9 || j == 6 || j == 5 || j == 4|| j == 3 ) && k == 4){
                cout << "\033[1;36m" << boardarray[j][k] << "\033[0m";
            }
            else if( j == 2 && (k == 4 || k == 5 || k == 6 || k == 7 || k == 8 || k == 13 || k == 14 || k == 15 ||k == 16 || k == 17 || k== 18 || k == 19 || k == 20)){
                cout << "\033[1;35m" << boardarray[j][k] << "\033[0m";
            }
            else if ( j == 2 && (k == 9 || k == 10 || k == 11 || k == 12 || k == 21 || k == 22 || k == 23 || k == 29 || k == 30 || k == 31)){
                cout << "\033[1;37m" << boardarray[j][k] << "\033[0m";
            }
            else if ( j == 2 && (k == 24 || k == 25 || k == 26 || k == 27 || k == 28 || k == 32 || k == 33 || k == 34 || k == 35 || k == 36 || k == 37 || k == 38 || k == 39 || k == 40)){
                cout << "\033[1;39m" << boardarray[j][k] << "\033[0m";
            }
            else{
                cout << boardarray[j][k];
            }
        }
        cout << endl;
    }

}

void Game::updatepositions(){

    /* Finished Player 1, Player 2, and Player 3 update position lol jesus this is hard */
    int position;

    /* Update on Player 1 Position */
    position = players[0].getPosition();
    switch(position){
        case 0:
            boardarray[21][1] = '1';
            break;
        case 1:
            boardarray[19][1] = '1';
            break;
        case 2:
            boardarray[17][1] = '1';
            break;
        case 3:
            boardarray[15][1] = '1';
            break;
        case 4:
            boardarray[13][1] = '1';
            break;
        case 5:
            boardarray[11][1] = '1';
            break;
        case 6:
            boardarray[9][1] = '1'; 
            break;
        case 7:
            boardarray[7][1] = '1'; 
            break;
        case 8:
            boardarray[5][1] = '1'; 
            break;
        case 9:
            boardarray[3][1] = '1'; 
            break;
        case 10:
            boardarray[1][1] = '1'; 
            break;
        case 11:
            boardarray[1][5] = '1'; 
            break;
        case 12:
            boardarray[1][9] = '1'; 
            break;
        case 13:
            boardarray[1][13] = '1'; 
            break;
        case 14:
            boardarray[1][17] = '1'; 
            break;
        case 15:
            boardarray[1][21] = '1'; 
            break;
        case 16:
            boardarray[1][25] = '1'; 
            break;
        case 17:
            boardarray[1][29] = '1'; 
            break;
        case 18:
            boardarray[1][33] = '1'; 
            break;
        case 19:
            boardarray[1][37] = '1'; 
            break;
        case 20:
            boardarray[1][41] = '1'; 
            break;
        case 21:
            boardarray[3][41] = '1'; 
            break;
        case 22:
            boardarray[5][41] = '1'; 
            break;
        case 23:
            boardarray[7][41] = '1'; 
            break;
        case 24:
            boardarray[9][41] = '1'; 
            break;
        case 25:
            boardarray[11][41] = '1'; 
            break;
        case 26:
            boardarray[13][41] = '1'; 
            break;
        case 27:
            boardarray[15][41] = '1'; 
            break;
        case 28:
            boardarray[17][41] = '1'; 
            break;
        case 29:
            boardarray[19][41] = '1'; 
            break;
        case 30:
            boardarray[21][41] = '1'; 
            break;
        case 31:
            boardarray[21][37] = '1'; 
            break;
        case 32:
            boardarray[21][33] = '1'; 
            break;
        case 33:
            boardarray[21][29] = '1'; 
            break;
        case 34:
            boardarray[21][25] = '1'; 
            break;
        case 35:
            boardarray[21][21] = '1'; 
            break;
        case 36:
            boardarray[21][17] = '1'; 
            break;
        case 37:
            boardarray[21][13] = '1'; 
            break;
        case 38:
            boardarray[21][9] = '1'; 
            break;
        case 39:
            boardarray[21][5] = '1'; 
            break;
    }
    /* Update on Player 2 Position */
    if(numplayers >= 2){
        position = players[1].getPosition();
        switch(position){
            case 0:
                boardarray[21][2] = '2';
                break;
            case 1:
                boardarray[19][2] = '2';
                break;
            case 2:
                boardarray[17][2] = '2';
                break;
            case 3:
                boardarray[15][2] = '2';
                break;
            case 4:
                boardarray[13][2] = '2';
                break;
            case 5:
                boardarray[11][2] = '2';
                break;
            case 6:
                boardarray[9][2] = '2'; 
                break;
            case 7:
                boardarray[7][2] = '2'; 
                break;
            case 8:
                boardarray[5][2] = '2'; 
                break;
            case 9:
                boardarray[3][2] = '2'; 
                break;
            case 10:
                boardarray[1][2] = '2'; 
                break;
            case 11:
                boardarray[1][6] = '2'; 
                break;
            case 12:
                boardarray[1][10] = '2'; 
                break;
            case 13:
                boardarray[1][14] = '2'; 
                break;
            case 14:
                boardarray[1][18] = '2'; 
                break;
            case 15:
                boardarray[1][22] = '2'; 
                break;
            case 16:
                boardarray[1][26] = '2'; 
                break;
            case 17:
                boardarray[1][30] = '2'; 
                break;
            case 18:
                boardarray[1][34] = '2'; 
                break;
            case 19:
                boardarray[1][38] = '2'; 
                break;
            case 20:
                boardarray[1][42] = '2'; 
                break;
            case 21:
                boardarray[3][42] = '2'; 
                break;
            case 22:
                boardarray[5][42] = '2'; 
                break;
            case 23:
                boardarray[7][42] = '2'; 
                break;
            case 24:
                boardarray[9][42] = '2'; 
                break;
            case 25:
                boardarray[11][42] = '2'; 
                break;
            case 26:
                boardarray[13][42] = '2'; 
                break;
            case 27:
                boardarray[15][42] = '2'; 
                break;
            case 28:
                boardarray[17][42] = '2'; 
                break;
            case 29:
                boardarray[19][42] = '2'; 
                break;
            case 30:
                boardarray[21][42] = '2'; 
                break;
            case 31:
                boardarray[21][38] = '2'; 
                break;
            case 32:
                boardarray[21][34] = '2'; 
                break;
            case 33:
                boardarray[21][30] = '2'; 
                break;
            case 34:
                boardarray[21][26] = '2'; 
                break;
            case 35:
                boardarray[21][22] = '2'; 
                break;
            case 36:
                boardarray[21][18] = '2'; 
                break;
            case 37:
                boardarray[21][14] = '2'; 
                break;
            case 38:
                boardarray[21][10] = '2'; 
                break;
            case 39:
                boardarray[21][6] = '2'; 
                break;
        }    
    }
    /* Update on Player 3 Position */
    if(numplayers >= 3){
        position = players[2].getPosition();
        switch(position){
            case 0:
                boardarray[22][1] = '3';
                break;
            case 1:
                boardarray[20][1] = '3';
                break;
            case 2:
                boardarray[18][1] = '3';
                break;
            case 3:
                boardarray[16][1] = '3';
                break;
            case 4:
                boardarray[14][1] = '3';
                break;
            case 5:
                boardarray[12][1] = '3';
                break;
            case 6:
                boardarray[10][1] = '3'; 
                break;
            case 7:
                boardarray[8][1] = '3'; 
                break;
            case 8:
                boardarray[6][1] = '3'; 
                break;
            case 9:
                boardarray[4][1] = '3'; 
                break;
            case 10:
                boardarray[2][1] = '3'; 
                break;
            case 11:
                boardarray[2][5] = '3'; 
                break;
            case 12:
                boardarray[2][9] = '3'; 
                break;
            case 13:
                boardarray[2][13] = '3'; 
                break;
            case 14:
                boardarray[2][17] = '3'; 
                break;
            case 15:
                boardarray[2][21] = '3'; 
                break;
            case 16:
                boardarray[2][25] = '3'; 
                break;
            case 17:
                boardarray[2][29] = '3'; 
                break;
            case 18:
                boardarray[2][33] = '3'; 
                break;
            case 19:
                boardarray[2][37] = '3'; 
                break;
            case 20:
                boardarray[2][41] = '3'; 
                break;
            case 21:
                boardarray[4][41] = '3'; 
                break;
            case 22:
                boardarray[6][41] = '3'; 
                break;
            case 23:
                boardarray[8][41] = '3'; 
                break;
            case 24:
                boardarray[10][41] = '3'; 
                break;
            case 25:
                boardarray[12][41] = '3'; 
                break;
            case 26:
                boardarray[14][41] = '3'; 
                break;
            case 27:
                boardarray[16][41] = '3'; 
                break;
            case 28:
                boardarray[18][41] = '3'; 
                break;
            case 29:
                boardarray[20][41] = '3'; 
                break;
            case 30:
                boardarray[22][41] = '3'; 
                break;
            case 31:
                boardarray[22][37] = '3'; 
                break;
            case 32:
                boardarray[22][33] = '3'; 
                break;
            case 33:
                boardarray[22][29] = '3'; 
                break;
            case 34:
                boardarray[22][25] = '3'; 
                break;
            case 35:
                boardarray[22][21] = '3'; 
                break;
            case 36:
                boardarray[22][17] = '3'; 
                break;
            case 37:
                boardarray[22][13] = '3'; 
                break;
            case 38:
                boardarray[22][9] = '3'; 
                break;
            case 39:
                boardarray[22][5] = '3'; 
                break;
        }
    }


    /* Update on Player 4  Position */
    if(numplayers == 4){
        position = players[3].getPosition();
        switch(position){
            case 0:
                boardarray[21][1] = '4';
                break;
            case 1:
                boardarray[19][1] = '4';
                break;
            case 2:
                boardarray[17][1] = '4';
                break;
            case 3:
                boardarray[15][1] = '4';
                break;
            case 4:
                boardarray[13][1] = '4';
                break;
            case 5:
                boardarray[11][1] = '4';
                break;
            case 6:
                boardarray[9][1] = '4'; 
                break;
            case 7:
                boardarray[7][1] = '4'; 
                break;
            case 8:
                boardarray[5][1] = '4'; 
                break;
            case 9:
                boardarray[3][1] = '4'; 
                break;
            case 10:
                boardarray[1][1] = '4'; 
                break;
            case 11:
                boardarray[1][5] = '4'; 
                break;
            case 12:
                boardarray[1][9] = '4'; 
                break;
            case 13:
                boardarray[1][13] = '4'; 
                break;
            case 14:
                boardarray[1][17] = '4'; 
                break;
            case 15:
                boardarray[1][21] = '4'; 
                break;
            case 16:
                boardarray[1][25] = '4'; 
                break;
            case 17:
                boardarray[1][29] = '4'; 
                break;
            case 18:
                boardarray[1][33] = '4'; 
                break;
            case 19:
                boardarray[1][37] = '4'; 
                break;
            case 20:
                boardarray[1][41] = '4'; 
                break;
            case 21:
                boardarray[3][41] = '4'; 
                break;
            case 22:
                boardarray[5][41] = '4'; 
                break;
            case 23:
                boardarray[7][41] = '4'; 
                break;
            case 24:
                boardarray[9][41] = '4'; 
                break;
            case 25:
                boardarray[11][41] = '4'; 
                break;
            case 26:
                boardarray[13][41] = '4'; 
                break;
            case 27:
                boardarray[15][41] = '4'; 
                break;
            case 28:
                boardarray[17][41] = '4'; 
                break;
            case 29:
                boardarray[19][41] = '4'; 
                break;
            case 30:
                boardarray[21][41] = '4'; 
                break;
            case 31:
                boardarray[21][37] = '4'; 
                break;
            case 32:
                boardarray[21][33] = '4'; 
                break;
            case 33:
                boardarray[21][29] = '4'; 
                break;
            case 34:
                boardarray[21][25] = '4'; 
                break;
            case 35:
                boardarray[21][21] = '4'; 
                break;
            case 36:
                boardarray[21][17] = '4'; 
                break;
            case 37:
                boardarray[21][13] = '4'; 
                break;
            case 38:
                boardarray[21][9] = '4'; 
                break;
            case 39:
                boardarray[21][5] = '4'; 
                break;
        }
    }
}

void Game::checkgame(){
    /* Need to make a function that checks for game over... */

}

/* Assistor functions to the Game Class */

void makeline(){
    cout << "--------------------------------------------------------------------" << endl;
}

void twoplayers(int turn){
    if(turn){
        cout << "Player 1" << endl;
    }
    else{
        cout << "Player 2" << endl;
    }
}

void threeplayers(int turn){
    if(turn == 1){       
        cout << "Player 1" << endl;
        cout << "Player 3" << endl;
    }
    else if(turn == 2){
        cout << "Player 1" << endl;
        cout << "Player 2" << endl;
    }
    else{
        cout << "Player 2" << endl;
        cout << "Player 3" << endl;
    }
}

void fourplayers(int turn){
    if(turn == 1){       
        cout << "Player 1" << endl;
        cout << "Player 3" << endl;
        cout << "Player 4" << endl;
    }
    else if(turn == 2){
        cout << "Player 1" << endl;
        cout << "Player 2" << endl;
        cout << "Player 4" << endl;
    }
    else if(turn== 3){
        cout << "Player 1" << endl;
        cout << "Player 2" << endl;
        cout << "Player 3" << endl;
    }
    else{
        cout << "Player 2" << endl;
        cout << "Player 3" << endl;
        cout << "Player 4" << endl;
    }
}
