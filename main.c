#include "header.h"

int main(void)
{
	srand((unsigned int)time(NULL));
	srand((unsigned)time(NULL));

	int choice = 0, point = 0;
	char option = ' ';

	do
	{
		
		do
		{
			print_menu();
			choice = get_choice();
		} while (choice < DISPLAY || choice > EXIT);
		system("cls");

		switch (choice)
		{
		case DISPLAY: print_rules();
			break;
		case PLAY:
			system("cls");
			const char* suit[4] = { "Hearts", "Diamonds", "Clubs", "Spades" }; //initalize suits 
			const char* face[13] = { "Ace", "Two", "Three", "Four", "Five", "Six",
									"Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King" }; //initialize value

			int deck[4][13] = { 0 };
			Hand hand_1 = { 0 };
			Hand hand_2 = { 0 };
			double player1 = 0, player2 = 0;

			shuffle(deck); //shuffles the deck
			deal_cards(deck, face, suit, &hand_1, &hand_2); //deals the shuffled cards to both players
			printf("YOUR HAND IS: \n");
			printf("======================\n");
			print_hand(face, suit, &hand_1); //hand is printed to the screen
			player1 = compare_hand(&hand_1); //see what your hand has
			printf("======================\n"); 
			printf("Do you want to change your hand? (Y/N)\n"); // y or n if you want to change certain cards in your hand
			scanf(" %c", &option);
			if (option == 'Y' || option == 'y')
			{
				printf("You may only choose 3 cards.\n");
				system("pause");
				change_hand(deck, face, suit, &hand_1, 5);
				printf("YOUR NEW HAND IS\n");
				print_hand(face, suit, &hand_1); //prints the new hand to the screen
				player1 = compare_hand(&hand_1); // see what your new and hopefully improved hand has
				system("pause");
			}


			system("cls");


			printf("YOUR HAND IS:\n");
			print_hand(face, suit, &hand_1);
			player1 = compare_hand(&hand_1);
			printf("==================\n");
			system("pause");
			player2 = compare_hand(&hand_2);
			system("cls");
			if (player2 < 2.05) //redraws the dealers hand is bad
			{
				printf("The dealer is now redrawing\n");
				dealer_redraw(deck, face, suit, &hand_2, 5);
				system("pause");


			}
			printf("Final Hands!\n");
			printf("Your hand is\n");
			print_hand(face, suit, &hand_1); //final hand is printed
			player1 = compare_hand(&hand_1); // final hand is scored 
			printf("=================\n");
			printf("The dealers hand\n");
			print_hand(face, suit, &hand_2); //final hand is printed for dealer
			player2 = compare_hand(&hand_2); //final hand is scored for dealer
			printf("=================\n");

			if (player2 > player1)
			{
				printf("THE DEALER HAS WON! GOOD LUCK NEXT TIME!\n");
			}
			if (player2 < player1)
			{
				printf("YOU WIN!! NICE JOB!\n");
			}
			if (player2 == player1)
			{
				printf("YOU TIED! TRY AGAIN!\n");
			}
			break;

		case EXIT: printf("bye.\n");
			break;
		}
	} while (!(choice == EXIT));


	return 0;
}