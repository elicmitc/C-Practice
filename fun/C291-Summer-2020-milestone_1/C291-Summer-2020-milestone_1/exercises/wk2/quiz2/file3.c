/*Debugging quiz - File No: 3 */
/* This program should perform the duties of a basic calculator and print whether the result is >100 or <100 or equal to 100 */
/* the program should ask for the input until 'q' is enterd */
// Check for possible logical errors and rectify them 

// Total number of bugs: 17


/*Debugging quiz - File No: 3 */
/* This program should perform the duties of a basic calculator and print whether the result is >100 or <100 or equal to 100 */
/* the program should ask for the input until 'q' is enterd */
// Check for possible logical errors and rectify them 

// Total number of bugs: 17


#include<stdio.h>

int main(void){
  char input;
  float num1, num2, result;
   
  while(1)
    {
      printf("Welcome to the Calculator\nOperation choices:\tAddition(A)\n\t\t\tSubtraction(S)\n\t\t\tMultiplication(M)\n\t\t\tDivision(D)\nEnter choice: ");

      scanf(" %c", &input);
      if(input == 'q'){
	break;
      }

     else if(input == 'A' || input == 'S' || input == 'M' || input == 'D'){
	printf("Enter both numbers in required sequence: ");
	scanf(" %f %f", &num1, &num2);
      }
  
      if(input == 'A'){
	result =(num1+num2);
      }  
      else if(input == 'S'){
	result=(num1-num2);
      }
      else if(input == 'M'){
	result=num1*num2;
      }
      else if(input=='D'){
	result=num1/num2;
      }
      else{
	printf("Please choose a valid operation\n");
      }

	if(result > 100){
	  printf("Greater than 100.\n");
	}
	else if(result < 100) {
	  printf("Less than 100\n");
	}
	else if(result==100){
	  printf("Equal to 100\n");
	}

	printf("Quit the menu.\n");
    }
	return(0);
    }
