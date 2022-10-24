#ifndef HEADER_H
#define HEADER_H
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

//This is for the the catorical definitons
#define TOK	7
#define	FOK	8
#define FH	9
#define SS	10
#define	LS  11
#define	YZ  12
#define CH	13

//This is for the switch type
#define RULES 1
#define PLAY 2
#define EXIT 3

//Color definition for the players
#define RED     "\x1b[31m"
#define GRN   "\x1b[32m"
#define YEL  "\x1b[33m"
#define BLU   "\x1b[34m"
#define MAG "\x1b[35m"
#define CYA   "\x1b[36m"
#define RESET   "\x1b[0m"

/**************************************************
*Type: Player
* Description: Holds the vauls for a player
* Data Types: int color, int points, char[32] name
********************************************/
struct player
{
	int catagories[13];
	char color[8];
	int points;
	int rolls;
	char name[32];
};

void initPosArr(int* posArr[], int playerNum);
/**********************************************************
*Function: Roll Dice
* Description: Rolls a set of five dice
* Input Parameters: Void
* Output Parameters: Int Pointer
***********************************************************/
int* rollDice(int *dice[], int number);

/**********************************************************
* Function: New Player
* Description: Creates a new player type with the default data structure
* Input Parameters: Void
* Output Parameters: player newPlayer
**************************************************************/
struct player newPlayer(void);

/**********************************************
*Function: posibilitys
* Descripiton: presents the player with the potential catagories they could choose
* input Parameters: struct player* playerArr, int* diceRolls, int playerNum
* Output: void
***********************************************/
void possibility(int* dice, int* pos);

/************************************************
* Fucntion Player Catagories
* Description: Fills out each catagory used by a player in an int[13]
* Input Parameters: *player[], int playerNumber, int typeUsed
* Output: Void
*************************************************/
playerCat(struct player* currentPlayer,  int posArr[]);
/*************************************************
*Function: Player Color
* Description: Obtains a color for each player in the game 
* Input Parameters: Int* list, int numOfPlay
* Output Conditition: Int*
* Output Parameters: int complete
****************************************************/
int playerColor(char* names);

/*****************************************************
*Function: Print Rules
* Description: Prints the rules for Yatzee
* Input Parameter: Void
* Output Parameters: void
* ****************************************************/
void printRules(void);

/*****************************************************
*Function: Print Menu
* Description: Prints the Menu for Yatzee
* Input Parameter: Void
* Output Parameters: void
* ****************************************************/ 
void printMenu(void);

/*****************************************************
* Function: Num Getter
* Descrition: Prompts and returns an int from a user between vaule start and vaule end
* Input Parameter: int start, int end
* Output Parameter: selection
* ***************************************************/
numGetter( int end);

/*********************************************************
* Function: Player Names
* Descripition: prompts and takes the users anem
* Input Parameters: Void
* Output Parameters: char[32]
************************************************************/
char* playerNames(struct player PlayerArr[], int playerNum);


/**********************************************************
*Function: Set Color
* Descripton: Sets the conssol to the color chossen by the player
* Input Parameters: int color
* Output: Void
***********************************************************/
void setColor(char* color);

/******************************************
*Function: playerScores
* Description: sets the players score based on the choice
* Input Parameters: int choice,
* Output Parameters: int score
* *****************************************/
int playerScore(int choice, int* dice);

/******************************************
*Function: Display Dice
* Discription: Shows the result of the dice rolls
* Input Parameters: int dice[6]
* Output Parameters: void
********************************************/
void displayDice(int* dice);

/*****************************************
*Funtion: endOfGame
* Description: displays the points for the end of the game and who won
* Input Parameters, int playerNumber, struct player[]
* Output Void
* *******************************************/
void endOfGame(int playerNumber, struct player* playerArr);

void bubbleSort(int* list, int size);
#endif 
