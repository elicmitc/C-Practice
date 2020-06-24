#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


int main(void){
  char * topics[]{"Depression   ", "Anxiety      ", "PTSD         ", "Dementia     ", "Bipolar      ", "Mood Disorder", "TBI          "};
  int survey[7, 10];
  int responses;
  int totalResponses;
  int totalRespondees; 
  int highLow[7];
  while(1){
    totalRespondees +=1;
    printf("Please rate the following issues from 1 (least) to 10 (most) important.");
    for(int i =0; i<7; ++i){
      printf(topics[i]);
      printf(" "); 
      scanf(" %d", &responses);
      printf("/n");
      survey[i][responses-1] +=1;

    }
  } 
  printf("Ratings:       1 2 3 4 5 6 7 8 9 10 ");
  for( int j=0; j< 7; ++j){
    printf(topics[j]);
    printf( " ");
    for(int k = 0; k<10; ++k){
      printf(survey[j][k];
	     printf( " ");
	     totalResponses += survey[j][k] *(k+1);
	     }
        highLow[j] = totalResponses;
      totalResponses = 0;
      printf("\n");
    }
    int high =highLow[0];
    int low = highLow[0];
    int tempHigh=0;
    int tempLow = 0;

    for(int i = 0; i< 7; ++i){
      if(highLow[i]>tempHigh){
	tempHigh=i;
      }
      if(highLow[i]< tempLow){
	tempLow=i;
      }
    }
    printf("The topic with the most points is %s and it recieved %d points", topics[tempHigh], tempHigh );
    printf("The topic with the fewest points is %s and it recieved %d points", topics[tempLow], tempLow );

    
  }
}
