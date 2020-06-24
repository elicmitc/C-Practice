//Matt Brownlee

//COMPILE IN C99
//gcc -std=c99 poker_hand.c -o poker
 
// JUNE 2020
// Fig. 10.3: fig10_03.c
// Card shuffling and dealing program using structures

//include statements
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

//define statements 
#define CARDS 52
#define FACES 13
#define HAND 5//draw only 5
#define TRUE 1//positive print condition
#define FALSE 0//negative print condition

// card structure definition                  
struct card {                                 
  const char *face; // define pointer face   
  const char *suit; // define pointer suit  
}; 

typedef struct card Card; // new type name for struct card   

// prototypes
void fillDeck(Card * const wDeck, const char * wFace[], 
	      const char * wSuit[]);
void shuffle(Card * const wDeck);
void deal(const Card * const wDeck);
void myHand(const Card * const wDeck);

int main(void)
{ 
  Card deck[CARDS]; // define array of Cards

  // initialize array of pointers
  const char *face[] = { "Ace", "Deuce", "Three", "Four", "Five",
			 "Six", "Seven", "Eight", "Nine", "Ten",
			 "Jack", "Queen", "King"};

  // initialize array of pointers
  const char *suit[] = { "Hearts", "Diamonds", "Clubs", "Spades"};

  srand(time(NULL)); // randomize

  fillDeck(deck, face, suit); // load the deck with Cards
  shuffle(deck); // put Cards in random order
  deal(deck); // deal all 52 Cards
  myHand(deck);
} 

// place strings into Card structures
void fillDeck(Card * const wDeck, const char * wFace[], 
	      const char * wSuit[])
{ 
  // loop through wDeck
  for (size_t i = 0; i < CARDS; ++i) { 
    wDeck[i].face = wFace[i % FACES];
    wDeck[i].suit = wSuit[i / FACES];
  } 
} 

// shuffle cards
void shuffle(Card * const wDeck)
{ 
  // loop through wDeck randomly swapping Cards
  for (size_t i = 0; i < CARDS; ++i) { 
    size_t j = rand() % CARDS;
    Card temp = wDeck[i];      
    wDeck[i] = wDeck[j];
    wDeck[j] = temp;      
  } 
} 

// deal cards
void deal(const Card * const wDeck)
{ 
  // loop through wDeck
  printf("Here are the cards you were dealt: \n");
  for (size_t i = 0; i < 5; ++i) {
    printf("%5s of %-12s", wDeck[i].face, wDeck[i].suit);
  } 
  printf("\n");
}

   


///**************************************************** 

// start working with the hand you were dealt 
void myHand(const Card * const wDeck)
{

  //variable defitions for function 
  int straight = 0;
  int flush = 0;
  int four = 0;
  int three = 0;
  int pairs = 0;
  int highC = 0;
  int count = 0;
  int flu = 0;
  int jack = 11;
  int queen = 12;
  int king = 13;
  int ace = 14;
  int i;
  int royF = 0;


  //begin evalating hand 
  //1 of a kind, 2 of a kind, 3 of a kind, 4 of a kind

  for(i=1; i<5; ++i){
    if(strcmp(wDeck[0].face, wDeck[i].face) == 0){
      count += 1;
    }
  }
  for(i=2; i<5; ++i){
    if(strcmp(wDeck[1].face, wDeck[i].face) ==0){
      count += 1;
    }
  }
  for(i=3; i<5; ++i){
    if(strcmp(wDeck[2].face, wDeck[i].face)==0){
      count += 1;
    }
  }
  for(i=4; i<5; ++i){
    if(strcmp(wDeck[3].face, wDeck[i].face)==0){
      count += 1;
    }
  }

  // find straight hand
  for(i=0; i<5; ++i){
    if(strcmp(wDeck[i].face, "Ace")==0){
      straight += 1;
    }
    else if(strcmp(wDeck[i].face, "Duece")==0){
      straight += 1;
    }
    else if(strcmp(wDeck[i].face, "Three")==0){
      straight += 1;
    }
    else if(strcmp(wDeck[i].face, "Four")==0){
      straight += 1;
    }
    else if(strcmp(wDeck[i].face, "Five")==0){
      straight += 1;
    }
    if(straight != 5){
      straight = 0;
    }
    else{
      break;
    }


    
    if(strcmp(wDeck[i].face, "Duece")==0){
      straight += 1;
    }
    else if(strcmp(wDeck[i].face, "Three")==0){
      straight += 1;
    }
    else if(strcmp(wDeck[i].face, "Four")==0){
      straight += 1;
    }
    else if(strcmp(wDeck[i].face, "Five")==0){
      straight += 1;
    }
    else if(strcmp(wDeck[i].face, "Six")==0){
      straight += 1;
    }
    if(straight != 5){
      straight = 0;
    }
    else{
      break;
    }


         
    if(strcmp(wDeck[i].face, "Three")==0){
      straight += 1;
    }
    else if(strcmp(wDeck[i].face, "Four")==0){
      straight += 1;
    }
    else if(strcmp(wDeck[i].face, "Five")==0){
      straight += 1;
    }
    else if(strcmp(wDeck[i].face, "Six")==0){
      straight += 1;
    }
    else if(strcmp(wDeck[i].face, "Seven")==0){
      straight += 1;
    }
    if(straight != 5){
      straight = 0;
    }
    else{
      break;
    }



    if(strcmp(wDeck[i].face, "Four")==0){
      straight += 1;
    }
    else if(strcmp(wDeck[i].face, "Five")==0){
      straight += 1;
    }
    else if(strcmp(wDeck[i].face, "Six")==0){
      straight += 1;
    }
    else if(strcmp(wDeck[i].face, "Seven")==0){
      straight += 1;
    }
    else if(strcmp(wDeck[i].face, "Eight")==0){
      straight += 1;
    }
    if(straight != 5){
      straight = 0;
    }
    else{
      break;
    }


    if(strcmp(wDeck[i].face, "Five")==0){
      straight += 1;
    }
    else if(strcmp(wDeck[i].face, "Six")==0){
      straight += 1;
    }
    else if(strcmp(wDeck[i].face, "Seven")==0){
      straight += 1;
    }
    else if(strcmp(wDeck[i].face, "Eight")==0){
      straight += 1;
    }
    else if(strcmp(wDeck[i].face, "Nine")==0){
      straight += 1;
    }
    if(straight != 5){
      straight = 0;
    }
    else{
      break;
    }


    if(strcmp(wDeck[i].face, "Six")==0){
      straight += 1;
    }
    else if(strcmp(wDeck[i].face, "Seven")==0){
      straight += 1;
    }
    else if(strcmp(wDeck[i].face, "Eight")==0){
      straight += 1;
    }
    else if(strcmp(wDeck[i].face, "Nine")==0){
      straight += 1;
    }
    else if(strcmp(wDeck[i].face, "Ten")==0){
      straight += 1;
    }
    if(straight != 5){
      straight = 0;
    }
    else{
      break;
    }



    if(strcmp(wDeck[i].face, "Seven")==0){
      straight += 1;
    }
    else if(strcmp(wDeck[i].face, "Eight")==0){
      straight += 1;
    }
    else if(strcmp(wDeck[i].face, "Nine")==0){
      straight += 1;
    }
    else if(strcmp(wDeck[i].face, "Ten")==0){
      straight += 1;
    }
    else if(strcmp(wDeck[i].face, "Jack")==0){
      straight += 1;
    }
    if(straight != 5){
      straight = 0;
    }
    else{
      break;
    }


    if(strcmp(wDeck[i].face, "Eight")==0){
      straight += 1;
    }
    else if(strcmp(wDeck[i].face, "Nine")==0){
      straight += 1;
    }
    else if(strcmp(wDeck[i].face, "Ten")==0){
      straight += 1;
    }
    else if(strcmp(wDeck[i].face, "Jack")==0){
      straight += 1;
    }
    else if(strcmp(wDeck[i].face, "Queen")==0){
      straight += 1;
    }
    if(straight != 5){
      straight = 0;
    }
    else{
      break;
    }


    if(strcmp(wDeck[i].face, "Nine")==0){
      straight += 1;
    }
    else if(strcmp(wDeck[i].face, "Ten")==0){
      straight += 1;
    }
    else if(strcmp(wDeck[i].face, "Jack")==0){
      straight += 1;
    }
    else if(strcmp(wDeck[i].face, "Queen")==0){
      straight += 1;
    }
    else if(strcmp(wDeck[i].face, "King")==0){
      straight += 1;
    }
    if(straight != 5){
      straight = 0;
    }
    else{
      break;
    }



    if(strcmp(wDeck[i].face, "Ten")==0){
      straight += 1;
    }
    else if(strcmp(wDeck[i].face, "Jack")==0){
      straight += 1;
    }
    else if(strcmp(wDeck[i].face, "Queen")==0){
      straight += 1;
    }
    else if(strcmp(wDeck[i].face, "King")==0){
      straight += 1;
    }
    else if(strcmp(wDeck[i].face, "Ace")==0){
      straight += 1;
    }
    if(straight != 5){
      straight = 0;
      royF = 1; 
    }
    else{
      break;
    }
  }

  // evaluate suits for sameness
  for(i=1; i<5; ++i){
    if(wDeck[0].face != wDeck[i].face){
      flu += 1;
    }
  }

  // evaluate count for the type of hand
  //BEGIN PRINT STATEMENTS 

  //high hand 
  if(count == 0){
    printf("\nYou have a high hand \n");
  }
  //pair
  else if(count == 1){
    printf("\nYou have a pair in your hand \n");
  }
  //2 pair
  else if(count == 2){
    printf("\nYou have two pairs in your hand \n");
  }

  //3 
  else if(count == 3){
    printf("\nYou have 3 of a kind in your hand\n");
  }

  //4
  else if(count == 6){
    printf("\nYou have 4 of a kind hand\n");
  }

  //FH
  else if(count ==4){
    printf("\nYou have a full house in your hand\n");
  }


  //straight flush royal print
  //royal flush top straight && suits match
  if(royF == 0 && flu  ==0){
    printf("You have a Royal Flush");
  }
  //straight flush 
  else if(straight == 5 && flu == 0){
    printf("\nYou have a straight flush\n");
  }

  //flush print 
  if(flu == 0){
    printf("\nYou have a flush in your hand\n");
  }

  //straight print
  else if(straight == 5){
    printf("\nYou have 5 of a kind in your hand\n");
  }

  printf("\n");
  //END EVALUATING HAND
  //end print statements 

  /**************************************************************************
   * (C) Copyright 1992-2015 by Deitel & Associates, Inc. and               *
   * Pearson Education, Inc. All Rights Reserved.                           *
   *                                                                        *
   * DISCLAIMER: The authors and publisher of this book have used their     *
 * best efforts in preparing the book. These efforts include the          *
     * development, research, and testing of the theories and programs        *
 * to determine their effectiveness. The authors and publisher make       *
     * no warranty of any kind, expressed or implied, with regard to these    *
 * programs or to the documentation contained in these books. The authors *
 * and publisher shall not be liable in any event for incidental or       *
								   * consequential damages in connection with, or arising out of, the       *
								   * furnishing, performance, or use of these programs.                     *
 *************************************************************************
 */ 
}
