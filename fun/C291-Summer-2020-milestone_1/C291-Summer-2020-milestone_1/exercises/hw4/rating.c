#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


int main(void){
  //initialize arrays  
  char * topics[]={"Depression    ", "Anxiety       ", "PTSD          ", "Dementia      ", "Bipolar       ", "Mood Disorder ", "TBI           "}; // set up tabular formating 
  int survey[7][10]={
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
  };
  //variables 
  int responses;
  int totalResponses;
  int totalRespondees = 0; 
  int highLow[7];
  float avg;
  int high =highLow[0];
  int low = highLow[0];
  int tempHigh=0;
  int tempLow = 0;
  int highest = 0;
  int lowest = 0 ; 
    
  while(1){
    //keep track of the number of people who take the survey 
    totalRespondees +=1;
    //tell user what to do 
    printf("Please rate the following issues from 1 (least) to 10 (most) important. \n");
    int i;
    for(i =0; i<7; ++i){
      // print topics 
      printf("%s", topics[i]);
      printf(" "); 
      //get responses and save 
      scanf(" %d", &responses);
      printf("\n");
      survey[i][responses-1] = survey[i][responses-1] + 1;

    }
    //heading for printing 
    printf("Ratings:       1 2 3 4 5 6 7 8 9 10 AVG\n");
    int j;
    int k;

    // loop through and print out topics follows by number of votes for each scoring area 
    for(j=0; j< 7; ++j){
      printf("%s", topics[j]);
      printf( " ");
      for(k = 0; k<10; ++k){
	printf("%d", survey[j][k]);
	printf( " ");
	totalResponses += survey[j][k] * (k+1);
      }
      //determine the average of the responses 
      avg = totalResponses/totalRespondees; 
      printf(" %.2f", avg);

      highLow[j] = totalResponses;
      printf("\n");
      //reset totalResponses 
      totalResponses = 0;
    }
       
    //loop for high and low values 
    for(i = 0; i< 7; ++i){
      //find the high value for comparison
      if(highLow[i]>tempHigh){
	tempHigh=i; //high topic
	highest = highLow[i]; //point value 
                
      }
      //find the low value using comparison 
      if(highLow[i]< tempLow){
	tempLow=i;
	lowest = highLow[i];
      }
    }
    //print high low topics and their scores 
    printf("The topic with the most points is %s and it recieved %d points \n", topics[tempHigh], highest);
    printf("The topic with the fewest points is %s and it recieved %d points \n", topics[tempLow], lowest + totalRespondees);
  }
    
}
