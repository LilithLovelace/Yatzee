
#include "header.h"




int main(void) {
	int  playerNumv = 1, choice = 0, outterLoop = 0, playLoop = 0, roundsLoop = 0, playersLoop =0;
	int player[6];
	char names[32];
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
					startTurn()
					playerCat(playerArr, playersLoop,)
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