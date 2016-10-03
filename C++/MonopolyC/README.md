# MonopolyC 

This is monopoly for C++. This was coded for UH Manoa's EE 205 (Object Oriented Programming) class. 

## Programming Approach

When programming the program the following classes were used.

## Classes

* Game (Handles all the intricacies of the Monopoly game)
* Player (Handles all the information for each player)
* Property (Handles the information and manipulation of information of each property)

These classes served as the basis for the game. The player class handled all the information for the player whereas the property class held all the information about each of the tiles on the board. In the property class also holds ID numbers for each of the tiles so the game class will know what type of tile it is interacting with.

## Class:Game 

Specific Highlights in the game class include the following
* Initializing and displaying the monopoly board was done in the Game class
* Also many of the defining features of monopoly such as buying houses, trading properties were defined in the Game class.
* The roll dice function utilized the time library with srand with a delay in order to further randomize the output of the dice.


## Future Development

* A GUI is currently in development with the QTGui library.
* This game did not take into account when Players run out of money... This still needs to be developed. 
* Need to work out how to mortgate properties as well. 

