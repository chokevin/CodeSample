#include <iostream>
#include <string>

#define MAXSIZE 40
using namespace std;

class Player{

public:
   
/* Constructor and Deconstructor */
    
    Player();
    ~Player();

/* Accessor Functions 
 * 
 * These are the functions that are used to access the private information
 * that the Player class stores.
 *
*/ 
    string getName();
    int getNumber();
    int getCash();
    int getPosition();
    bool getJail();
    int getproperties();
/* Manipulator Functions
 *
 * These are the functions that are used to manipulate the private variables stored
 * by the player class 
 *
*/
   
    void editName(string Name);
    void editNumber(int Number);
    void editCash(int Cash);
    void editPosition(int Position);
    void addCash(int addedcash);
    void minusCash(int minuscash);
    void addproperties();
    void minusproperties();
    void editJail( bool inJail);
    void changePosition(int Position);

   

private:
    void init_to_empty(); 
    string name;
    int number;
    int cash;
    int position;
    bool jailtime;
    int properties;
    
};

