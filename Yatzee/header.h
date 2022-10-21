#ifndef HEADER_H
#define HEADER_H
#define _CTR_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <time.h>


#define MAXVAL;
#define RULES 1
#define PLAY 2
#define EXIT 3
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
	int color;
	int points;
	char name[32];
};



/*************************************************
*Function: Player Color
* Description: Obtains a color for each player in the game while
  preventing the same color form being used
* Input Parameters: Int* list, int numOfPlay
* Output Conditition: Int*
* Output Parameters: int complete
****************************************************/
int playerColor(char* names)

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
numGetter(int start, int end);

/*********************************************************
* Function: Player Names
* Descripition: prompts and takes the users anem
* Input Parameters: Void
* Output Parameters: char[32]
************************************************************/
char* playerNames(void);
#endif 
