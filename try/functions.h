#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>
void print_class(void)
{
	char filename[20],rostername[20];
	printf("Class name to print: ");
	scanf(" %s",filename);
	strcpy(rostername,filename);
	strcat(filename,".txt");
	FILE *infile;
	struct students input;
	infile = fopen(filename,"r");
	if(infile == NULL)
	{
		puts("Class Roster Not Found.\n");
		return;
	}
	printf("\n\t%s Class Roster\n",rostername);
	while(fread(&input,sizeof(struct students),1,infile))
	{
		printf("name: %s %s\tage: %d\n",input.first_name,input.last_name,input.age);
	}
	printf("End of Reading from file\n\n");
	fclose(infile);


}
void save_class(struct students **pointer,int size)
{
	FILE *ptr;
	char fname[50];
	int i;
	struct students *point;
	point = *pointer;
	printf("Filename to save roster: ");
	scanf(" %s", fname);
	strcat(fname,".txt");
	ptr = fopen(fname,"w");
	assert(ptr);
	fwrite((point),sizeof(struct students),size,ptr);
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
int add_class(struct students **pointer)
{
	int c_size=0,i;
	char name[30];
	struct students *rost_tmp;
	printf("How many students are in your class.\n");
	scanf(" %d",&c_size);
	if(c_size == 0)
	{
		printf("Empty class, returning to menu.\n");
		return;
	}	
	rost_tmp = malloc(sizeof(student)*c_size);
	assert(rost_tmp);
	for(i=0;i<c_size;i++)
	{
		printf("Student %d first name: ",i+1);
		scanf(" %s",name);
		strcpy((rost_tmp+i)->first_name,name);
		printf("%s's last name: ",(rost_tmp+i)->first_name);
		scanf(" %s",name);
		strcpy((rost_tmp+i)->last_name,name);
		printf("%s %s's age: ",(rost_tmp+i)->first_name,(rost_tmp+i)->last_name);
		scanf(" %d",&((rost_tmp+i)->age));

	}
	puts("Class Roster Complete.");
	*pointer = rost_tmp;
	return c_size;
}
