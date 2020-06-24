/* 
 * Basic C program to print out hello world! 
 * Author: Adeel Bhutta
*/

#include <stdio.h>

int main(void) 
{
  int myNumber = 001 %1000;
  int count = 0; 
  printf("\"{Welcome to Summer 2020!},\\ This is 'Corona-affected' 6-Week Course @ IU //\"\n");
  while (myNumber > 0)
    {printf("%03d \n", myNumber);
  	while (count <5){
	  printf(".");
	  sleep(1);
	  ++count;
	  fflush(stdout);
	}
	count = 0;
      printf("\n");
      myNumber = myNumber + 1;
    }
return(0); 
}


