
#include "header.h"




int main(void) {
	int  playerNumv = 1,
		choice = 0,// this is the operation choosen by the user 
		outterLoop = 0, // this is a conditional varible for the choice loop
		playLoop = 0, // this is a conditional varible for the play opperation loop
		roundsLoop = 0,// this keeps track of the number of rounds played up to 13
		playersLoop = 0, //this keeps track of the player currently playing
		typeOfRoll = 0,  
		dies[5] = 0; //This holds the vaule of the die for each roll
	char names[32]="";
	char* p = names;
	printf("Please enter the number of Player(Max 6).");
	scanf("%d", &playerNumv);
	struct player playerArr[6];

	
	
	printMenu();
	
	//This loop is the outer one that gives selection as what todo
	do
	{
		choice = numGetter(1, 3);
		//This is the implimentation of the menu choice
		switch (choice) {
		case RULES:
			printRules();
			break;
		case PLAY:
			printf("Please press any key to start the game!");
			//This makes the player press any key
			scanf("");
			//Sets vauls for player Stuct
			for (int i = 0; i < playerNumv; i++) {
				
				*p = playerNames();
				playerArr[i].points = 0;
				playerArr[i].name == *p;
				
				playerColor(playerArr[i].name);
			}
			for (; roundsLoop < 13; roundsLoop++) {
				for (; playersLoop < playerNumv; playersLoop++) {
					startTurn();
					printf("Please press any key to start your turn!");
					//This makes the player press any key
					scanf("");
					while (playersTurn)
					typeOfRoll = possibility(dies);
					playerCat(playerArr, typeOfRoll, playersLoop)
				}
			}



			while (playLoop);
			break;
		case EXIT:
			outterLoop = 0;
			break;
		default:
			break;
		}
	}
		while (outterLoop);

}