#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>
int add_class(struct students *pointer)
{
	int c_size=0,i;
	char name[30];
	printf("How many students are in your class.\n");
	scanf(" %d",&c_size);
	if(c_size == 0)
	{
		printf("Empty class, returning to menu.\n");
		return;
	}	
	pointer = malloc(sizeof(student)*c_size);
	assert(pointer);
	for(i=0;i<c_size;i++)
	{
		printf("Student %d first name: ",i+1);
		fflush(stdin);
		scanf(" %s",name);
		strcpy((pointer+i)->first_name,name);
		printf("%s's last name: ",(pointer+i)->first_name);
		scanf(" %s",name);
		strcpy((pointer+i)->last_name,name);
		printf("%s %s's age: ",(pointer+i)->first_name,(pointer+i)->last_name);
		scanf(" %d",&((pointer+i)->age));

	}
	puts("Class Roster Complete.");
	return c_size;
}
