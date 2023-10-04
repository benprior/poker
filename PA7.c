#include "header.h"

void print_rules(void)
{
	printf("Welcome to Poker!\n");
	printf("You will start off with your first 5 cards, you will then have the option to replace them with new cards\n");
	printf("However, you may only switch 3 cards, so you must choose wisely. Once you like your cards, the dealer will then reveal their cards.\n");
	printf("If the dealer has a hand that is better than yours, then you lose, and vise versa.\n");
	printf("Have fun!!\n");

}

void print_menu(void)
{
	printf("1. Rules\n");
	printf("2. Play\n");
	printf("3. Quit\n");
}

int get_choice(void)
{
	int choice = 0;
	scanf("%d", &choice);
	return choice;
}

void shuffle(int deck[][COLS])
{
	int row = 0, col = 0, card = 0;
	
	for (card = 1; card <= 52; card++)
	{
		do
		{
			row = rand() % 4;
			col = rand() % 13;
		} while (deck[row][col] != 0);

		deck[row][col] = card;
	}
}

void deal_cards(int deck[][COLS], const char* face[], const char* suit[], Hand* hand1, Hand* hand2)
{
	int card = 0;

	for (card = 0; card < 5; card++)
	{
		hand1->hand[card].face = (deck[0][card] % 13);
		hand1->hand[card].suit = (deck[0][card] / 13);
		deck[0][card] = 0;
	}
	for (int i = 0; i < 5; i++)
	{
		hand2->hand[i].face = (deck[0][i + card] % 13);
		hand2->hand[i].suit = (deck[0][i + card] / 13);
		deck[0][i + card] = 0;
	}
}

void print_hand(const char* face[], const char* suit[], Hand* hand1)
{
	for (int i = 0; i < 5; i++)
	{
		printf("Card %d:\n %5s of %-8s\n", i + 1, face[hand1->hand[i].face], suit[hand1->hand[i].suit]);
	}
}

void change_hand(int deck[][COLS], const char* face[], const char* suit[], Hand* hand1, int num_cards)
{
	char option;
	int index = 0, row = 0, col = 0, card = 0;

	for (index = 0; index < num_cards; index++)
	{
		if (card < 3)
		{
			printf("Card %d: %5s of %-8s\n", index + 1, face[hand1->hand[index].face], suit[hand1->hand[index].suit]);
			printf("Would you like to keep this card? (Y/N) \n");
			scanf(" %c", &option);
			if (option == 'N' || option == 'n' && card < 3)
			{
				do
				{
					row = ran_row();
					col = ran_col();

				} while (deck[row][col] == 0);

				hand1->hand[index].face = (deck[row][col] % 13);
				hand1->hand[index].suit = (deck[row][col] / 13);
				deck[row][col] = 0;
				++card;


			}
		}
	}
}

void dealer_redraw(int deck[][COLS], const char* face[], const char* suit[], Hand* hand1, int num_cards)
{	
	char option;
	int index = 0, row = 0, col = 0, card = 0;

	
	for (index = 0; index < num_cards; ++index)
	{
		if (card < 3)
		{




			do
			{
				row = ran_row();
				col = ran_col();

			} while (deck[row][col] == 0);

			hand1->hand[index].face = (deck[row][col] % 13);
			hand1->hand[index].suit = (deck[row][col] / 13);
			deck[row][col] = 0;
			++card;



		}

	}
}

int ran_row(void)
{
	return rand() % 4;
}

int ran_col(void)
{
	return rand() % 13;
}

double compare_hand(Hand* hand1)
{
	int card_suit = 0, card_face = 0;
	int hearts = 0, diamonds = 0, clubs = 0, spades = 0;
	int aces = 0, deuces = 0, threes = 0, fours = 0, fives = 0, sixes = 0, sevens = 0, eights = 0, nines = 0, tens = 0, jacks = 0, queens = 0, kings = 0, firstpair = 0;
	double the_hand = 0;

	for (int i = 0; i < 5; i++)
	{
		card_suit = hand1->hand[i].suit;
		switch (card_suit)
		{
		case 0:
			++hearts;
			break;
		case 1:
			++diamonds;
			break;
		case 2:
			++clubs;
			break;
		case 3:
			++spades;
			break;
		}
		card_face = hand1->hand[i].face;
		switch (card_face)
		{
		case 0:
			++aces;
			break;
		case 1:
			++deuces;
			break;
		case 2:
			++threes;
			break;
		case 3:
			++fours;
			break;
		case 4:
			++fives;
			break;
		case 5:
			++sixes;
			break;
		case 6:
			++sevens;
			break;
		case 7:
			++eights;
			break;
		case 8:
			++nines;
			break;
		case 9:
			++tens;
			break;
		case 10:
			++jacks;
			break;
		case 11:
			++queens;
			break;
		case 12:
			++kings;
			break;
		}
	}

	
	if (aces == 4 || deuces == 4 || threes == 4 || fours == 4 || fives == 4 || sixes == 4 || sevens == 4 || eights == 4 || nines == 4 || tens == 4 || jacks == 4 || queens == 4 || kings == 4)
	{
		printf("Four of a kind\n");

		if (deuces == 4)
		{
			the_hand = 8.0;
		}
		if (threes == 4)
		{
			the_hand = 8.01;
		}
		if (fours == 4)
		{
			the_hand = 8.02;
		}
		if (fives == 4)
		{
			the_hand = 8.03;
		}
		if (sixes == 4)
		{
			the_hand = 8.04;
		}
		if (sevens == 4)
		{
			the_hand = 8.05;
		}
		if (eights == 4)
		{
			the_hand = 8.06;
		}
		if (nines == 4)
		{
			the_hand = 8.07;
		}
		if (tens == 4)
		{
			the_hand = 8.08;
		}
		if (jacks == 4)
		{
			the_hand = 8.09;
		}
		if (queens == 4)
		{
			the_hand = 8.10;
		}
		if (kings == 4)
		{
			the_hand = 8.11;
		}
		if (aces == 4)
		{
			the_hand = 8.12;
		}
	}
	
	else if ((aces == 3 || deuces == 3 || threes == 3 || fours == 3 || fives == 3 || sixes == 3 || sevens == 3 || eights == 3 || nines == 3 || tens == 3 || jacks == 3 || queens == 3 || kings == 3) && (aces == 2 || deuces == 2 || threes == 2 || fours == 2 || fives == 2 || sixes == 2 || sevens == 2 || eights == 2 || nines == 2 || tens == 2 || jacks == 2 || queens == 2 || kings == 2))

	{
		printf("Full house\n");

		if (deuces == 3)
		{
			the_hand = 7.00;
		}
		if (threes == 3)
		{
			the_hand = 7.01;
		}
		if (fours == 3)
		{
			the_hand = 8.02;
		}
		if (fives == 3)
		{
			the_hand = 7.03;
		}
		if (sixes == 3)
		{
			the_hand = 7.04;
		}
		if (sevens == 3)
		{
			the_hand = 7.05;
		}
		if (eights == 3)
		{
			the_hand = 7.06;
		}
		if (nines == 3)
		{
			the_hand = 7.07;
		}
		if (tens == 3)
		{
			the_hand = 7.08;
		}
		if (jacks == 3)
		{
			the_hand = 7.09;
		}
		if (queens == 3)
		{
			the_hand = 7.10;
		}
		if (kings == 3)
		{
			the_hand = 7.11;
		}
		if (aces == 3)
		{
			the_hand = 7.12;
		}

	}
	
	else if (hearts == 5 || diamonds == 5 || clubs == 5 || spades == 5) 
	{
		printf("Flush\n");

		the_hand = 6.00;

		if (aces >= 1)
		{
			the_hand = 6.13;
		}
		else if (kings >= 1)
		{
			the_hand = 6.12;
		}
		else if (queens >= 1)
		{
			the_hand = 6.11;
		}
		else if (jacks >= 1)
		{
			the_hand = 6.10;
		}
		else if (tens >= 1)
		{
			the_hand = 6.09;
		}
		else if (nines >= 1)
		{
			the_hand = 6.08;
		}
		else if (eights >= 1)
		{
			the_hand = 6.07;
		}
		else if (sevens >= 1)
		{
			the_hand = 6.06;
		}
		else if (sixes >= 1)
		{
			the_hand = 6.05;
		}
		else if (fives >= 1)
		{
			the_hand = 6.04;
		}
		else if (fours >= 1)
		{
			the_hand = 6.03;
		}
		else if (threes >= 1)
		{
			the_hand = 6.02;
		}
		else if (deuces >= 1)
		{
			the_hand = 6.01;
		}
	}
	
	else if (aces == 1 && deuces == 1 && threes == 1 && fours == 1 && fives == 1)
	{
		printf("Straight\n");
		the_hand = 5.00;
	}
	else if (deuces == 1 && threes == 1 && fours == 1 && fives == 1 && sixes == 1)
	{
		printf("Straight\n");
		the_hand = 5.01;
	}
	else if (threes == 1 && fours == 1 && fives == 1 && sixes == 1 && sevens == 1)
	{
		printf("Straight\n");
		the_hand = 5.02;
	}
	else if (fours == 1 && fives == 1 && sixes == 1 && sevens == 1 && eights == 1)
	{
		printf("Straight\n");
		the_hand = 5.03;
	}
	else if (fives == 1 && sixes == 1 && sevens == 1 && eights == 1 && nines == 1)
	{
		printf("Straight\n");
		the_hand = 5.04;
	}
	else if (sixes == 1 && sevens == 1 && eights == 1 && nines == 1 && tens == 1)
	{
		printf("Straight\n");
		the_hand = 5.05;
	}
	else if (sevens == 1 && eights == 1 && nines == 1 && tens == 1 && jacks == 1)
	{
		printf("Straight\n");
		the_hand = 5.06;
	}
	else if (eights == 1 && nines == 1 && tens == 1 && jacks == 1 && queens == 1)
	{
		printf("Straight\n");
		the_hand = 5.07;

	}
	else if (nines == 1 && tens == 1 && jacks == 1 && queens == 1 && kings == 1)
	{
		printf("Straight\n");
		the_hand = 5.08;
	}

	else if (tens == 1 && jacks == 1 && queens == 1 && kings == 1 && aces == 1)
	{
		printf("Straight\n");
		the_hand = 5.09;
	}
	
	else if (aces == 3 || deuces == 3 || threes == 3 || fours == 3 || fives == 3 || sixes == 3 || sevens == 3 || eights == 3 || nines == 3 || tens == 3 || jacks == 3 || queens == 3 || kings == 3)
	{
		printf("Three of a kind\n");
		if (deuces == 3)
		{
			the_hand = 4.0;
		}
		if (threes == 3)
		{
			the_hand = 4.01;
		}
		if (fours == 3)
		{
			the_hand = 4.02;
		}
		if (fives == 3)
		{
			the_hand = 4.03;
		}
		if (sixes == 3)
		{
			the_hand = 4.04;
		}
		if (sevens == 3)
		{
			the_hand = 4.05;
		}
		if (eights == 3)
		{
			the_hand = 4.06;
		}
		if (nines == 3)
		{
			the_hand = 4.07;
		}
		if (tens == 3)
		{
			the_hand = 4.08;
		}
		if (jacks == 3)
		{
			the_hand = 4.09;
		}
		if (queens == 3)
		{
			the_hand = 4.10;
		}
		if (kings == 3)
		{
			the_hand = 4.11;
		}
		if (aces == 3)
		{
			the_hand = 4.12;
		}
	}


	else if (aces == 2 || deuces == 2 || threes == 2 || fours == 2 || fives == 2 || sixes == 2 || sevens == 2 || eights == 2 || nines == 2 || tens == 2 || jacks == 2 || queens == 2 || kings == 2)
	{

		if (deuces == 2)
		{
			printf("Pair\n");
			the_hand = 2.0;
			firstpair = 1;
		}
		if (threes == 2)
		{
			printf("Pair\n");
			the_hand = 2.01;
			firstpair = 2;
		}
		if (fours == 2)
		{
			printf("Pair\n");
			the_hand = 2.02;
			firstpair = 3;
		}
		if (fives == 2)
		{
			printf("Pair\n");
			the_hand = 2.03;
			firstpair = 4;
		}
		if (sixes == 2)
		{
			printf("Pair\n");
			the_hand = 2.04;
			firstpair = 5;
		}
		if (sevens == 2)
		{
			printf("Pair\n");
			the_hand = 2.05;
			firstpair = 6;
		}
		if (eights == 2)
		{
			printf("Pair\n");
			the_hand = 2.06;
			firstpair = 7;
		}
		if (nines == 3)
		{
			printf("Pair\n");
			the_hand = 2.07;
			firstpair = 8;
		}
		if (tens == 2)
		{
			printf("Pair\n");
			the_hand = 2.08;
			firstpair = 9;
		}
		if (jacks == 2)
		{
			printf("Pair\n");
			the_hand = 2.09;
			firstpair = 10;
		}
		if (queens == 2)
		{
			printf("Pair\n");
			the_hand = 2.10;
			firstpair = 11;
		}
		if (kings == 2)
		{
			printf("Pair\n");
			the_hand = 2.11;
			firstpair = 12;
		}
		if (aces == 2)
		{
			printf("Pair\n");
			the_hand = 2.12;
			firstpair = 13;
		}

		
		if (deuces == 2 && firstpair != 1)
		{
			printf("Two Pair\n");
			the_hand = 3.01;
		}
		if (threes == 2 && firstpair != 2)
		{
			printf("Two Pair\n");
			the_hand = 3.02;
		}
		if (fours == 2 && firstpair != 3)
		{
			printf("Two Pair\n");
			the_hand = 3.03;
		}
		if (fives == 2 && firstpair != 4)
		{
			printf("Two Pair\n");
			the_hand = 3.04;
		}
		if (sixes == 2 && firstpair != 5)
		{
			printf("Two Pair\n");
			the_hand = 3.05;
		}
		if (sevens == 2 && firstpair != 6)
		{
			printf("Two Pair\n");
			the_hand = 3.06;
		}
		if (eights == 2 && firstpair != 7)
		{
			printf("Two Pair\n");
			the_hand = 3.07;
		}
		if (nines == 2 && firstpair != 8)
		{
			printf("Two Pair\n");
			the_hand = 3.08;
		}
		if (tens == 2 && firstpair != 9)
		{
			printf("Two Pair\n");
			the_hand = 3.09;
		}
		if (jacks == 2 && firstpair != 10)
		{
			printf("Two Pair\n");
			the_hand = 3.10;
		}
		if (queens == 2 && firstpair != 11)
		{
			printf("Two Pair\n");
			the_hand = 3.11;
		}
		if (kings == 2 && firstpair != 12)
		{
			printf("Two Pair\n");
			the_hand = 3.12;
		}
		if (aces == 2 && firstpair != 13)
		{
			printf("Two Pair\n");
			the_hand = 3.13;
		}
	}


	else if (deuces == 1 || threes == 1 || fours == 1 || fives == 1 || sixes == 1 || sevens == 1 || eights == 1 || nines == 1 || tens == 1 || jacks == 1 || queens == 1 || kings == 1 || aces == 1)
	{
		printf("High card\n");
		if (deuces == 1)
		{
			the_hand = 1.00;
		}
		if (threes == 1)
		{
			the_hand = 1.01;
		}
		if (fours == 1)
		{
			the_hand = 1.02;
		}
		if (fives == 1)
		{
			the_hand = 1.03;
		}
		if (sixes == 1)
		{
			the_hand = 1.04;
		}
		if (sevens == 1)
		{
			the_hand = 1.05;
		}
		if (sixes == 1)
		{
			the_hand = 1.06;
		}
		if (eights == 1)
		{
			the_hand = 1.07;
		}
		if (nines == 1)
		{
			the_hand = 1.08;
		}
		if (tens == 1)
		{
			the_hand = 1.09;
		}
		if (jacks == 1)
		{
			the_hand = 1.10;
		}
		if (queens == 1)
		{
			the_hand = 1.11;
		}
		if (kings == 1)
		{
			the_hand = 1.12;
		}
		if (aces == 1)
		{
			the_hand = 1.13;
		}


	}

	return the_hand;
}
