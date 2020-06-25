#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"main.h"
#include"functions.h"
#include<assert.h>
void save_class(student* point,int size)
{
	FILE *ptr;
	char fname[50];
	int i;
	printf("Filename to save roster: ");
	scanf(" %s", fname);
	strcat(fname,".txt");
	ptr = fopen(fname,"w");
	assert(ptr);
	for(i=0;i<size;i++)
	{
	  fwrite((point+i),sizeof(struct students),1,ptr);
	}
	if(fwrite !=0)
	{
	 printf("Successful Save.\n");
	}
	else
	{
	 printf("Error Saving..\n");
	}
	fclose(ptr);
} 
int main(void)
{
   char input,save;
   student *pointer;
   int c_size=0; 
   while(1)
   {
      printf("Options:\n");
      printf("[1] Add Class\n");
      printf("[2] Print Class\n");
      printf("[3] Save Class\n");
      printf("[4] Exit\n");
      
      scanf(" %c",&input);
      switch(input)
      {
	case '1':
	  printf("Adding Class...\n");
          c_size = add_class(pointer);
	  printf("Would you like to save this class?[Y][N] ");
	  scanf(" %c",&save);
	  if(save == 'Y')
	  {
		save_class(pointer,c_size);
	  }
	  else
	  {
		puts("Your class wont be saved, do you want your roster saved?[Y][N]");
	  	scanf(" %c",&save);
	        if(save == 'Y')
	        {
			save_class(pointer,c_size);
	        }
		else puts("Roster not Saved..");
	  }
	  break;
	case '2':
	  printf("Printing Class...\n");
	  break;
        case '3':
	  printf("Saving Session...\n");
	  break;
        case '4':
          printf("Leaving Session..\n");
	  exit(0);
	  break;
        default:
	  printf("default\n");
	  break;
	
      }
   } 
   return 0;

}
