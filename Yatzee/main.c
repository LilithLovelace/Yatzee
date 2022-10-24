
#include "header.h"

int main(void) {
	int  playerNumv = 1, playerTurnEnd = 0, rolls = 0, cat = 0,
		choice = 0,// this is the operation choosen by the user 
		outterLoop = 0, // this is a conditional varible for the choice loop
		playLoop = 0, // this is a conditional varible for the play opperation loop
		roundsLoop = 0,// this keeps track of the number of rounds played up to 13
		playersLoop = 1,
		typeOfRoll = 0,
		howManyDice = 0,
		dies[5] = { 0,0,0,0,0 },
		posArr[6][13] = { {0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0} };
	int *diesP = 0;
	diesP =&dies;
	int hI = 0; char anyKey = '\0';
	struct player playerArr[6] = { 0 };
	srand(time(NULL));
	printf("Please enter the number of Player (Max 6).\n");
	scanf(" %d", &playerNumv);

	//initPosArr(posArr, playerNumv);


	outterLoop = TRUE;
	//This loop is the outer one that gives selection as what todo
	do
	{
		printMenu();
		printf("Choice game operation\n");
		choice = numGetter(3);
		//This is the implimentation of the menu choice
		switch (choice) 
		{
			case RULES:
				printRules();
				break;
			case PLAY:
				printf("Please press any key to start the game!\n");
				scanf(" %s", &anyKey);
				for (playersLoop=0; playersLoop < playerNumv; playersLoop++) 
				{
					playerArr[playersLoop] = newPlayer();
				}
				//for 13 rounds
				for (roundsLoop=0; roundsLoop < 13; roundsLoop++) {
				//for all players
					for (playersLoop=0; playersLoop < playerNumv; playersLoop++) 
					{

						struct player CurrentPlayer = playerArr[playersLoop];
						struct player* cPP = &CurrentPlayer;
						setColor(playerArr[playersLoop].color);
						printf("%s, Please press any key to start your turn or press x to exit!\n", CurrentPlayer.name);
						scanf(" %c", &anyKey);
						//This makes the player press any key
						howManyDice = 5;
						rollDice(diesP, howManyDice);
						displayDice(diesP);
						++rolls;
						if (rolls < 3) 
						{
						//for subsequent rolls
							possibility(diesP, posArr[playersLoop]);
							typeOfRoll = playerCat(cPP, posArr);
							printf("Would you like to roll again?\n 1/0\n");
							scanf(" %c", &hI);

							if (hI == 1) 
							{
								printf("Please Select How Many Die: \n");
								scanf("%d", &howManyDice);
								rollDice(diesP, howManyDice);
								possibility(diesP, posArr[playersLoop]);
								typeOfRoll = playerCat(cPP, playerNumv, posArr[playersLoop]);
							}

						}
						CurrentPlayer.points += playerScore(typeOfRoll, dies);
						typeOfRoll = 0,
						howManyDice = 0,
						printf("This round, %d , you scored: %d Points.\n",(roundsLoop+1), CurrentPlayer.points);
						printf(RESET);
					}
				}
				endOfGame(playerNumv, playerArr);
				break;
			case EXIT:
			outterLoop = 0;
			break;
		default:
			break;
			}
	}while (outterLoop);
	
}