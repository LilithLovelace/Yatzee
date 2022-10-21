
#include "header.h"




int main(void) {
	int  playerNumv=1, choice=0, outterLoop =0, playLoop =0;
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
				for (int i = 0; i < playerArr; i++) {
					*p = playerNames();
					playerArr[i].points = 0;
					playerArr[i].name == *p;
					playerColor(playerArr[i].name);

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