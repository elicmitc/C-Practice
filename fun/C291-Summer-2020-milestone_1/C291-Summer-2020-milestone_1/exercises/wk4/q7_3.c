//This program uses a function called CharacterScan to read a char from the user
//The function must take an int pointer as a parameter
//The program should print the char and ascii code for each character the user enters
//The program should only exit whe nthe user enters escape

#include <stdio.h>
#include <stdlib.h>
char *  CharacterScan(int*);

int main(void){
    int* iPtr;
    int c;
    char exit;
    char aCode;
    while(0){
      char * c = CharacterScan(*iPtr);
      aCode = *iPtr;
        if(aCode == 27){ //27 is the ASCII for ESC
            printf("Exiting the code!\n");
            break;
        }
        else{  
    
	  // %d displays the integer value of a character
	  // %c displays the actual character
	  printf("ASCII value of %c = %d \n", c, c);
    
        }
    }
    return 0;
}
char * CharacterScan(int* iPtr){
    char c;
    printf("Enter a character: ");
    scanf(" %c", &c);
    return *iPtr;
}
