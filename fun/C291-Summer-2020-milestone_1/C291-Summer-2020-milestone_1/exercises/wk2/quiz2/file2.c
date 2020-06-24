// Automatic dialing machine
// Delivers a sales message
/* Needs to print all possible combinations of areacode and exchangecode with the last 4 digits
Example : If areacode = 812, exchange = 424
Output : 
812-424-0001
812-424-0002
812-424-0003
.
.
812-424-9998
812-424-9999

Number of bugs: Primarily 9 (Breaking them down makes it 21)

 */

#include<stdio.h>
  
int main(void){
  int areaCode, exchange, i;
   printf( "Hello, I am a telemarketing calling making program.\n");
   printf(" Enter a three-digit area code ");
   scanf(" %d", &areaCode);
   printf( "Enter a three-digit exchange to call ");
   scanf(" %d", &exchange);
   for(i=0; i <= 9999; ++i){
     printf( "Dialing (%d) %d - %04d", areaCode , exchange, i);
     printf( "\n I am calling to tell you to buy a subscription to Dogs Monthly!\n");
   }      
     
   
	    printf( "\nCalls completed\n");
     return(0);
}
