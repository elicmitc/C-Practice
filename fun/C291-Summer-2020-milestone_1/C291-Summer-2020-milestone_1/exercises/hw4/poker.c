// Fig. 7.24: fig07_24.c
// Card shuffling and dealing.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SUITS 4
#define FACES 13
#define CARDS 52

// establish variable / arrays for values to be stored into 
char * card1Suit[100];
char *card1Face[100];
char *card2Suit[100];
char *card2Face[100];
char *card3Suit[100];
char *card3Face[100];
char *card4Suit[100];
char *card4Face[100];
char *card5Suit[100];
char *card5Face[100];
int four = 0;
int flush= 0;
int three= 0;
int pair = 0;
int straight = 0;
// prototypes
void shuffle(unsigned int wDeck[][FACES]); // shuffling modifies wDeck
void deal(unsigned int wDeck[][FACES], const char *wFace[], 
	  const char *wSuit[]); // dealing doesn't modify the arrays

int main(void)
{
  // initialize deck array
  unsigned int deck[SUITS][FACES] = { 0 };

  srand(time(NULL)); // seed random-number generator

  shuffle(deck); // shuffle the deck

  // initialize suit array                       
   const char *suit[SUITS] =            
     {"Hearts", "Diamonds", "Clubs", "Spades"};
   
   // initialize face array                   
   const char *face[FACES] =
     {"Ace", "Two", "Three", "Four",         
      "Five", "Six", "Seven", "Eight",         
      "Nine", "Ten", "Jack", "Queen", "King"};

   deal(deck, face, suit); // deal the deck
} 

// shuffle cards in deck
void shuffle(unsigned int wDeck[][FACES])
{
  // for each of the cards, choose slot of deck randomly
  for (size_t card = 1; card <= CARDS; ++card) {
    size_t row; // row number
    size_t column; // column number

    // choose new random location until unoccupied slot found
    do {                                                        
      row = rand() % SUITS;                                   
      column = rand() % FACES;                             
    } while(wDeck[row][column] != 0); // end do...while

    // place card number in chosen slot of deck
    wDeck[row][column] = card;
  } 
  /*
   char card1[100];
   strcpy(card1, wDeck[0][0].face);
   char card2[100];
   strcpy(card2, wDeck[1][1]);
   char card3[100]; wDeck[2][2];
   char card4[100]; wDeck[3][3];
   char card5[100]; wDeck[4][4];*/
}

// deal cards in deck
void deal(unsigned int wDeck[][FACES], const char *wFace[],
	  const char *wSuit[])
{
  // deal each of the cards
  for (size_t card = 1; card <= 5; ++card) {
    // loop through rows of wDeck
    for (size_t row = 0; row < SUITS; ++row) {
      // loop through columns of wDeck for current row
      for (size_t column = 0; column < FACES; ++column) {
	// if slot contains current card, display card
            
	if(wDeck[row][column] == card) {
	  printf("%5s of %-8s%c", wFace[column], wSuit[row],
                 card % 2 == 0 ? '\n' : '\t'); // 2-column format
	  //loop through to find correct variables 
	  for(int i =0; i<5; ++i){
	    //find the right varialble 
	    if(i == 0){
	      //copy the correct values for comparison later 
	      strcpy(card1Face, wFace[column]);
	      strcpy(card1Suit, wSuit[row]);
	    }
	    else if(i == 1){
	      strcpy(card2Face, wFace[column]);
	      strcpy(card2Suit, wSuit[row]);
	    }
	    else if(i == 2){
	      strcpy(card3Face, wFace[column]);
	      strcpy(card3Suit, wSuit[row]);
	    }
	    else if(i == 3){
	      strcpy(card4Face, wFace[column]);
	      strcpy(card4Suit, wSuit[row]);
	    }
	    if(i == 4){
	      strcpy(card5Face, wFace[column]);
	      strcpy(card5Suit, wSuit[row]);
	    }
	  }
	  //finding alike cards
	  //if these two cards are the same
	  if(card1Face == card2Face){
	    pair +=1; //add 1 
               
	    //compare against other possible matches
	    if(card1Face == card3Face){
	      pair +=1;

	    }
	    else if(card1Face == card4Face){
	      pair +=1;

	    }

	    else if(card1Face == card5Face){
	      pair+=1;

	    }
	  }
	  else if(card1Face == card3Face){
	    pair +=1;
	    if(card1Face == card2Face){
	      pair +=1;

	    }
	    else if(card1Face == card4Face){
	      pair +=1;

	    }

	    else if(card1Face == card5Face){
	      pair+=1;
	    }
	  }

	}
	else if(card1Face == card4Face){
	  pair +=1;
	  if(card1Face == card2Face){
	    pair +=1;

	  }
	  else if(card1Face == card3Face){
	    pair +=1;

	  }

	  else if(card1Face == card5Face){
	    pair+=1;

	  }
	}

	else if(card1Face == card5Face){
	  pair +=1;
	  if(card1Face == card2Face){
	    pair +=1;

	  }
	  else if(card1Face == card3Face){
	    pair +=1;

	  }

	  else if(card1Face == card4Face){
	    pair+=1;

	  }

	}

	else if(card2Face == card3Face){
	  pair +=1;
	  if(card1Face == card2Face){
	    pair +=1;

	  }
	  else if(card2Face == card4Face){
	    pair +=1;

	  }

	  else if(card2Face == card5Face){
	    pair+=1;

	  }
	}
	else if(card2Face == card4Face){
	  pair +=1;
	  if(card2Face == card1Face){
	    pair +=1;

	  }
	  else if(card2Face == card3Face){
	    pair +=1;

	  }

	  else if(card2Face == card5Face){
	    pair+=1;

	  }
	}
	else if(card2Face == card5Face){
	  pair +=1;
	  if(card1Face == card2Face){
	    pair +=1;

	  }
	  else if(card2Face == card3Face){
	    pair +=1;

	  }

	  else if(card1Face == card4Face){
	    pair+=1;

	  }
	}
	else if(card3Face == card4Face){
	  pair +=1;
	  if(card1Face == card3Face){
	    pair +=1;

	  }
	  else if(card2Face == card3Face){
	    pair +=1;

	  }

	  else if(card3Face == card5Face){
	    pair+=1;

	  }
	}
	else if(card3Face == card5Face){
	  pair +=1;
	  if(card3Face == card1Face){
	    pair +=1;

	  }
	  else if(card3Face == card2Face){
	    pair +=1;

	  }

	  else if(card3Face == card4Face){
	    pair+=1;

	  }
	}
	else if(card4Face == card5Face){
	  pair +=1;
	  if(card4Face == card1Face){
	    pair +=1;

	  }
	  else if(card4Face == card2Face){
	    pair +=1;

	  }

	  else if(card4Face == card3Face){
	    pair+=1;

	  }
	}

          
	/*
            // full house 
            if(three == 1 & pair ==1){
            printf("You have a full house");
            }
            else if(pair>0 & three == 00){
            printf("You have a pair");
      }
            else if(three>0 & four ==0){
	printf("You have three of a kind");
      }
            else if(four ==1){
	printf("You have four of a kind");
      }
            else if(straight ==1){
	printf("You have a straighyt");
      }
            else if(flush == 1){
	printf("You have a royal flush");
      }

      } */
      }
    }  
  }
  //straight
  //flush
  //find the correct values ofr pair and print out the appropriate statement for matches etc.... 
  if(pair == 1){
    printf("\nYou have a pair\n");
  }
  else if(pair ==2){
    printf("\nYou have three of a kind\n");
  }
  else if(pair ==3){
    printf("\nYou have four of a kind\n");
  }
  else{
    printf("\nYou have no cards alike\n");
  }
}
