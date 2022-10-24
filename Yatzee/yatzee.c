#include "header.h"

void initPosArr(int *posArr[], int playerNum) {
	for (int i = 0; i < playerNum; i++) {
		for (int j = 0; j < 13; i++) {
			posArr[i][j] = 0;
		}
	}
}

int numGetter(int end) {
	int selection = 0, loop = FALSE;
	do {
		printf("Please make select an option\n");
		scanf("%d", &selection);
		if (selection > end) {
			printf("Invalid Selection");
			loop = TRUE;
		}
		else {
			loop = -1;
		}
	} while ((loop != -1));
	return selection;
}

void printMenu(void) {
	printf(RESET);
	printf("1.		PRINT RULES.\n");
	printf("2.		PLAY GAME.\n");
	printf("3.		EXIT.\n");
}

void printRules(void) {
	printf("1. Players will Play 13 rounds.\n");
	printf("2. Players will attempt to get 1 of 13 round catagories.\n");
	printf("3. Each Catagory can only be used once, with the exectpion of the Yahtzee.\n");
	printf("5. Players will roll 5 dice up to three times, the first roll is requied.\n");
	printf("6. For 2 subsequent roles, any or no dice may be rolled\n");
	printf("9. If a player is unable to use a catagory for a round, they get a zero and must choose a catagory mark.\n");
	printf("7. The point vaules for the lower order catagories are as follows:\n");
	printf("	i.		Ones:	A point for every die with the face vaule of one, \n");
	printf("	ii.		Twoes:	A point for every die with a face vaule of two,  \n");
	printf("	iii.	Threes: A point for every die with a face vaule of three,\n");
	printf("	iv.		Fours:	A point for every die with a face vaule of four, \n");
	printf("	v.		Fives:	A point for every die with a face vaule of five, \n");
	printf("	vi.		Sixes:	A point for every die with a face vaule of six, \n");
	printf("8. The pont vaules for the higher order catagories are as follows: \n");
	printf("	i.		Three-of-A-Kind: The sum of all 5 dice.\n");
	printf("	ii.		Four-of-a-Kind: The sum of all 5 dice.\n");
	printf("	iii.	Full House: Three-of-A-Kind with 2 of a kind of another number; 25 Points.\n");
	printf("	iv.		Small Stright: Four consecutive numbers; 30 points.\n");
	printf("	v.		Large Stright: Five consecutive number; 40 points.\n");
	printf("	vi.		Yahtzee: Five dice of the same vaule; 50 points.\n");
	printf("8. Once a Yahtzee has been rolled, each subsequent Yahtzee has potential 100 point bonus, unless it has been mark as a zero.\n");
	printf("9. When additianl Yahtzee are used, if possible the higher order catagory corasponding to the face vaule of a die shall be used.\n  ");
	printf("10. When a high order catagoy has alrady been marked, the player may use an the corrosponding lower catagory. Or score zero points.\n");
	printf("11. At the end of 13 rounds the player with the most points wins.\n");
}

struct player newPlayer() {
	char color[8] = "", name[32]="";
	struct player temp;
	int entryLoop = FALSE;
	for (int i = 0; i < 13; i++) {
		temp.catagories[i] = 0;
	}
do {
	printf("Please select a color: red, green ,blue, cyan, magenta, yellow. Ensure it is lowercase\n");
	scanf("%s", &color);

	if (strcmp(color,"red" ) == 0) {
		strcpy(temp.color, "red");
	}
	else if (strcmp(color,"green") == 0) {
		strcpy(temp.color , "green");
	}
	else if (strcmp("blue", color) == 0) {
		strcpy(temp.color, "blue");
	}
	else if (strcmp("cyan", color) == 0) {
		strcpy(temp.color, "cyan");
	}
	else if (strcmp("magenta", color) == 0) {
		strcpy(temp.color, "magenta");
	}
	else if (strcmp("yellow", color) == 0) {
		strcpy(temp.color, "yellow");
	}
	else {
		printf("Error: Please enter your vaule again./n");
		entryLoop = TRUE;
	}
} while (entryLoop == TRUE);

printf("Please enter your name: \n");
scanf("%s", &name);
strcpy(temp.name, name);
temp.points = 0;
temp.rolls = 0;
return temp;
}

int* rollDice(int arr[], int number) {
	int start = 5 - number;
	for (int i = start; i < 5; i++) {
		arr[i] = ((rand() % 6) + 1);
	}
	return  arr;
}

void possibility(int dice[], int* pos) {
	
	int freq[] = { 0,0,0,0,0,0 };

	int flag = 0;
	for (int i = 0; i < 6; i++) {

		//This determines the lower order
		if (dice[i] == 1) {
			pos[0] == TRUE;
			freq[0]++;
		}
		if (dice[i] == 2) {
			pos[1] == TRUE;
			freq[1]++;
		}
		if (dice[i] == 3) {
			pos[2] == TRUE;
			freq[2]++;
		}
		if (dice[i] == 4) {
			pos[3] == TRUE;
			freq[3]++;
		}
		if (dice[i] == 5) {
			pos[4] == TRUE;
			freq[4]++;
		}
		if (dice[i] == 6) {
			pos[5] = TRUE;
			freq[5]++;
		}
	}
	//for (int equal1 = 0; equal1 < 6; equal1++) {
		//int flag = dice[equal1];
		//for (int equal2 = 1; equal2 < 6; equal2++) {
			//if (dice[equal1] = dice[equal2]) {
				//freq[equal1]++;
			//}
		//}
	//}
	//3/4/5 in a row
	for (int hO = 0; hO < 6; hO++) {
		if (freq[hO] == 3) {
			pos[6] = TRUE;
		}
		if (freq[hO] == 4) {
			pos[7] = TRUE;
		}
		if (freq == 5) {
			pos[11] = TRUE;
		}
	}
	//Full  House
	if (pos[7] || pos[8] || pos[9]) {
		for (int equal1 = 0; equal1 < 6; equal1++) {
			for (int equal2 = 1; equal2 < 6; equal2++) {
				if (freq[equal1] == 3 && freq[equal2]) {
					pos[8] = TRUE;
				}
			}
		}
	}


	bubbleSort(dice, 6);
	//small Stright{
	if ((dice[1] - 1 == dice[0]) && (dice[2] - 1 == dice[3]) && (dice[3] - 1 == dice[2])) {
		pos[9] = TRUE;
	}
	else if ((dice[2] - 1 == dice[1]) && (dice[3] - 1 == dice[2]) && (dice[4] - 1 == dice[3])) {
		pos[9] = TRUE;
	}
	else if ((dice[3] - 1 == dice[2]) && (dice[4] - 1 == dice[3]) && (dice[5] - 1 == dice[4])) {
	}
	//large stright
	if ((dice[1] - 1 == dice[0]) && (dice[2] - 1 == dice[3]) && (dice[3] - 1 == dice[2]) && (dice[4] - 1 == dice[3])) {
		pos[10] = TRUE;
	}
	if ((dice[2] - 1 == dice[1]) && (dice[3] - 1 == dice[2]) && (dice[4] - 1 == dice[3]) && (dice[5] - 1 == dice[4])) {
		pos[10] = TRUE;
	}
	pos[12] = TRUE;
}

void bubbleSort(int* list, int size)
{
	int index = 0, passes = 0, temp = 0;

	for (passes = 0; passes < size; ++passes)
	{
		for (index = 0; index < size - passes; ++index)
			if (list[index] > list[index])
			{
				temp = list[index];
				list[index] = list[index + 1];
				list[index + 1] = temp;
			}
	}
}
		
void setColor(char* color) {
	if (strcmp( "red", color) == 0) {
		printf(RED);
	}
	else if (strcmp( "green", color) == 0) {
		printf(GRN);
	}
	else if (strcmp("blue", color) == 0) {
		printf(BLU);
	}
	else if (strcmp("cyan", color) == 0) {
		printf(CYA);
	}
	else if (strcmp("magenta", color) == 0) {
		printf(MAG);
	}
	else if (strcmp("yellow", color) == 0) {
		printf(YEL);
	}

}

int playerCat(struct player* currentPlayer, int possability[] ) {
	int choice = 0,  validLoop=FALSE;
	for (int i = 0; i < 13; i++) {
		if ((possability[i]) == (currentPlayer->catagories[i])) {
			if(i!=11){
			possability[i] = 0;
			}
		}
	}

	printf("The possible operations for this round are: \n");
	if (possability[0] == 1) {
		printf("Ones: 1\n");
	}
	if (possability[1] == 1) {
		printf("Twos: 2\n");
	}
	if (possability[2] == 1) {
			printf("Threes: 3\n");
		}
	if (possability[3] == 1) {
			printf("Fours: 4\n");
		}
	if (possability[4] == 1) {
			printf("Fives: 5\n");
		}
	if (possability[5] == 1) {
			printf("Sixes: 6\n");
		}
	if (possability[6] == 1) {
			printf("Three-in-A-Row: 7\n");
		}
	if (possability[7] == 1) {
			printf("Four-in-A-Row: 8\n");
		}
	if (possability[8] == 1) {
			printf("Full House: 9\n");
		}
	if (possability[9] == 1) {
			printf("Small Stright: 10\n");
		}
	if (possability[10] == 1) {
			printf("Large Stright: 11\n");
		}
	if (possability[11] == 1) {
			printf("YATZEE!: 12");
		}
	if (possability[12] == 1) {
			printf("Chance: 13\n");
		}
	
	do {
		printf("Please make your selection now...\n");
			scanf("%d", &choice);
			--choice;
			for (int kappa = 0; kappa < 13; kappa++) {
				if (possability[kappa] == 1) {
					validLoop = TRUE;
					break;
				}
			
			}
		} while (!validLoop);
		currentPlayer->catagories[choice]++;
		if (choice == 11 & currentPlayer->catagories[11] > 0) {
			choice = 13;
		}
		return choice;
}

int playerScore(int choice, int *dice) {
	int score = 0;
	if (choice == 0) {
		for (int i = 0; i < 5; i++) {
			if (dice[i] == 1) {
				score++;
			}
		}
	}
	if (choice ==1 ) {
		for (int i = 0; i < 5; i++) {
			if (dice[i] == 2) {
				score++;
			}
		}
	}
	if (choice == 2) {
		for (int i = 0; i < 5; i++) {
			if (dice[i] == 3) {
				score++;
			}
		}
	}
	if (choice == 3) {
		for (int i = 0; i < 5; i++) {
			if (dice[i] == 4) {
				score++;
			}
		}
	}
	if (choice == 4) {
		for (int i = 0; i < 5; i++) {
			if (dice[i] == 5) {
				score++;
			}
		}
	}
	if (choice == 5) {
		for (int i = 0; i < 5; i++) {
			if (dice[i] == 6) {
				score++;
			}
		}
	}
	if (choice == 6) {
		for (int i = 0; i < 5; i++) {
			score += dice[i];
		}
	}
	if (choice == 7) {
		for (int i = 0; i < 5; i++) {
			score += dice[i];
		}
	}
	if (choice == 8) {
		score += 25;
	}
	if (choice == 9) {
		score += 30;
	}
	if (choice == 10) {
		score += 40;
	}
	if (choice == 11) {
		score += 50;
	}
	if (choice == 12) {
		for (int i = 0; i < 5; i++) {
			score += dice[i];
		}
	}
		if (choice == 13) {
			score += 100;
		}
		return score;
	}

void displayDice(int *dice) {
	printf("The Rolls for this round are...\n");
	for (int i = 0; i < 5; i++) {
		printf("%d\n", dice[i]);
	}
	}

void endOfGame(int playerNumber, struct player* playerArr) {
	int flag = 0, points = 0;
	for (int i=0; i < playerNumber; i++) {
		printf("Player:%s had %d points", playerArr[i].name, playerArr[i].points);
		if (playerArr[i].points > points) {
			flag = i;
			points = playerArr[i].points;
		}
	}
	printf("Player: %s, won with %d points");
}
