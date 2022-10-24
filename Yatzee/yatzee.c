#include "header.h"

int numGetter(int end) {
	int selection = 0, loop = FALSE;
	do {
		printf("Please make select an option");
		scanf("%d", &selection);
		if (selection > end) {
			printf("Invalid Selection");
			loop = TRUE;
		}
	} while (loop = TRUE);
	return selection;
}

void printMenu(void) {
	printf(RESET);
	printf("1.		PRINT RULES.");
	printf("2.		PLAY GAME.");
	printf("3.		EXIT");
}

void printRules(void) {
	printf("1. Players will Play 13 rounds.\n");
	printf("2. Players will attempt to get 1 of 13 round catagories.\n");
	printf("3. Each Catagory can only be used once, with the exectpion of the Yahtzee.\n");
	printf("5. Players will roll 5 dice up to three times, the first roll is requied.\n");
	printf("6. For 2 subsequent roles, any or no dice may be rolled\n");
	printf("9. If a player is unable to use a catagory for a round, they get a zero and must choose a catagory mark.\n");
	printf("7. The point vaules for the lower order catagories are as follows:\n");
	printf("	1. Ones:	A point for every die with the face vaule of one, \n");
	printf("	2. Twoes:	A point for every die with a face vaule of two,  \n");
	printf("	3. Threes: A point for every die with a face vaule of three,\n");
	printf("	4. Fours:	A point for every die with a face vaule of four, \n");
	printf("	5. Fives:	A point for every die with a face vaule of five, \n");
	printf("	6.Sixes:	A point for every die with a face vaule of six, \n");
	printf("8. The pont vaules for the higher order catagories are as follows: \n");
	printf("	1. Three-of-A-Kind: The sum of all 5 dice.\n");
	printf("	2. Four-of-a-Kind: The sum of all 5 dice.\n");
	printf("	3. Full House: Three-of-A-Kind with 2 of a kind of another number; 25 Points.\n");
	printf("	4 .Small Stright: Four consecutive numbers; 30 points.\n");
	printf("	5. Large Stright: Five consecutive number; 40 points.\n");
	printf("	6. Yahtzee: Five dice of the same vaule; 50 points.");
	printf("8. Once a Yahtzee has been rolled, each subsequent Yahtzee has potential 100 point bonus, unless it has been mark as a zero.\n");
	printf("9. When additianl Yahtzee are used, if possible the higher order catagory corasponding to the face vaule of a die shall be used.\n  ");
	printf("10. When a high order catagoy has alrady been marked, the player may use an the corrosponding lower catagory. Or score zero points.\n");
	printf("11. At the end of 13 rounds the player with the most points wins.\ n");
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
		if (strcmp("red", color) == 0) {
			temp.color = RED;
		}
		else if (strcmp("green", color) == 0) {
			temp.color == GRN;
		}
		else if (strcmp("blue", color) == 0) {
			temp.color == BLU;
		}
		else if (strcmp("cyan", color) == 0) {
			temp.color == CYA;
		}
		else if (strcpy("magenta", color) == 0) {
			color == MAG;
		}
		else if (strcpy("yellow", color) == 0) {
			color == YEL;
		}
		else {
			printf("Error: Please enter your vaule again./n");
			entryLoop = TRUE;
		}
	} while (entryLoop == TRUE);
	temp.color = color;
	printf("Please enter your name: \n");
	scanf("%s", &name);
	strcpy(temp.name, name);
	temp.points = 0;
	temp.rolls = 0;
	return temp;
}
