/* Print the sum of all multiples of 3 and multiples of 8 from 0 to 100 
*  Print all the characters from 'A' to 'Z' in the reverse order 
*  Total number of bugs : 16
*/

#include <stdio.h>

int main(){

  int limit = 100;
  int i;
  int sum = 0;

  int c;

  printf("The value of limit is %d\n", limit);
  for(i=0; i <= limit; ++i){
    if(i%8 == 0){
      if(i%3==0){
	sum = sum +i;
      }
    }
  }
  printf("\n The Sum = %d\n", sum);

  fflush(stdout);
  for(c = 'Z'; c >='A'; c--){
    printf("%c",c);
  }
  printf("\n");
  return 0;
}
