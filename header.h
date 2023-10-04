#ifndef header.h
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

#define DISPLAY 1
#define PLAY 2
#define EXIT 3
#define HEARTS 1
#define DIAMONDS 2
#define CLUBS 3
#define SPADES 4
#define ROWS 4
#define COLS 13

typedef struct Card {
	
	int face, suit;

} Card;

typedef struct Hand {

	Card hand[5];

} Hand;

/****************************************
* Function: print_rules
* Date Created: 4/12/23
* Date Last Modified: 4/20/23
* Description: prints the rules of poker
* Input Parameters: none
* Returns: nothing
* Preconditions: nothing
* Postconditions: nothing
*****************************************/
void print_rules(void);

/*******************************
* Function: print_menu
* Date Created: 4/12/23
* Date Last Modified: 4/20/23
* Description: prints the menu 
* Input Parameters: none
* Returns: none
* Preconditions: nothing
* Postconditions: nothing
*********************************/
void print_menu(void);

/******************************************
* Function: get_choice
* Date Created: 4/12/23
* Date Last Modified: 4/20/23
* Description: gets the choice from user
* Input Parameters: none
* Returns: 1,2,or 3
* Preconditions: menu has been printed
* Postconditions: choice has been made
********************************************/
int get_choice(void);

/**********************************************************************
* Function:shuffle
* Date Created: 4/12/23
* Date Last Modified: 4/20/23
* Description: shuffles the deck of 52 cards
* Input Parameters: deck
* Returns: nothing
* Preconditions: game has been started, user inputted 2 on the menu
* Postconditions: shuffle has been executed.
***********************************************************************/
void shuffle(int deck[][COLS]);

/**********************************************************************
* Function: deal_cards
* Date Created: 4/12/23
* Date Last Modified: 4/20/23
* Description: deals the shuffled deck of cards to user and dealer
* Input Parameters: deck, face, suit, hand1 and 2
* Returns: nothing 
* Preconditions: deck has been shuffled
* Postconditions: each player has a hand of cards
**********************************************************************/
void deal_cards(int deck[][COLS], const char* face[], const char* suit[], Hand* hand1, Hand* hand2);

/****************************************************
* Function: print_hand
* Date Created: 4/12/23
* Date Last Modified: 4/20/23
* Description: prints the hand of the player
* Input Parameters: face, suit, hand
* Returns: nothing
* Preconditions: cards have been shuffled and dealt
* Postconditions: hand is printed to the screen 
*****************************************************/
void print_hand(const char* face[], const char* suit[], Hand* hand1);

/********************************************************************************************
* Function: change_hand
* Date Created: 4/12/23
* Date Last Modified: 4/20/23
* Description: changes the cards that were selected to be re-dealt
* Input Parameters: deck, face, suit, hand 1 and 2
* Returns: nothing
* Preconditions:  hands have been printed to the screen and decided to change some cards
* Postconditions: hand has been changed
*********************************************************************************************/
void change_hand(int deck[][COLS], const char* face[], const char* suit[], Hand* hand1, int num_cards);

/**********************************************************
* Function: dealer_redraw
* Date Created: 4/12/23
* Date Last Modified: 4/20/23
* Description: dealer redraws their hand if they want to
* Input Parameters: deck, face, suit, hand 1 and 2
* Returns: nothing
* Preconditions: cards have been dealt
* Postconditions: dealer has different cards
**********************************************************/
void dealer_redraw(int deck[][COLS], const char* face[], const char* suit[], Hand* hand1, int num_cards);

/***********************************
* Function: ran_row
* Date Created: 4/12/23
* Date Last Modified: 4/20/23
* Description: picks a number 1-4
* Input Parameters: none
* Returns: number 1 - 4
* Preconditions: none
* Postconditions: none
***********************************/
int ran_row(void);

/***************************************
* Function: ran_col
* Date Created: 4/12/23
* Date Last Modified: 4/20/23
* Description: picks a number 1- 13
* Input Parameters: none
* Returns: number 1- 13
* Preconditions: none
* Postconditions: none
***************************************/
int ran_col(void);

/****************************************************************
* Function: compare_hand
* Date Created: 4/12/23
* Date Last Modified: 4/24/23
* Description: compares hand to what kind of scoring you could have
* Input Parameters: hand1
* Returns: a double
* Preconditions: final hands have been chosen
* Postconditions: winner or a draw
*****************************************************************/
double compare_hand(Hand* hand1);


#endif
