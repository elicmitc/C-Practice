#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"main.h"
#include"functions.h"
#include<assert.h>
 
int main(void)
{
   char input[2],save;
   student *pointer;
   int c_size=0; 
   while(1)
   {
      printf("Options:\n");
      printf("[1] Add Class\n");
      printf("[2] Print Class\n");
      printf("[3] Exit\n");
      fgets(input, sizeof(input), stdin); 
      clear_stdin();
      //scanf(" %c",&input);
      switch(input[0])
      {
	case '1':
	  printf("Adding Class...\n");
          c_size = add_class(&pointer);
	  printf("Would you like to save this class?[Y][N] ");
	  scanf(" %c",&save);
      	  clear_stdin();
	  if(save == 'Y' || save == 'y')
	  {
		save_class(&pointer,c_size);
	  }
	  else
	  {
		puts("Your class wont be saved, do you want your roster saved?[Y][N]");
	  	scanf(" %c",&save);
      		clear_stdin();
	        if(save == 'Y' || save == 'y')
	        {
			save_class(&pointer,c_size);
	        }
		else puts("Roster not Saved..");
	  }
	  break;
	case '2':
	  printf("Which class would you like to print?\n");
	  print_class();	
	  break;
        case '3':
          printf("Leaving Session..\n");
	  exit(0);
	  break;
        default:
	  printf("No valid input read.\n");
	  input[0] = 'k';
	  break;
	
      }
   } 
   return 0;

}
