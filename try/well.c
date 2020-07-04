// C program for writing 
// struct to file 
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include<assert.h>
// a struct to read and write 
struct person 
{ 
	int id; 
	char fname[20]; 
	char lname[20]; 
}; 

int main () 
{ 
	FILE *outfile,*infile; 
	int i=1;	
	// open file for writing 
	outfile = fopen ("Fuck.txt", "w"); 
	if (outfile == NULL) 
	{ 
		fprintf(stderr, "\nError opend file\n"); 
		exit (1); 
	} 

	struct person *pointer;
//makes structure
	pointer = malloc(sizeof(struct person)*2);	
//fills out each profile
	printf("Enter id: ");
	scanf(" %d",&(pointer->id));
	printf("Enter id: ");
	scanf(" %d",&((pointer+1)->id));
	
	strcpy(pointer->fname,"Elijah");
	strcpy(pointer->lname,"Mitchell");
	(pointer+i)->id=21;
	strcpy((pointer+i)->fname,"Jared");
	strcpy((pointer+i)->lname,"Michalke");
	printf("%s %s\n",pointer->fname,pointer->lname);
// writes to a file
	fwrite (pointer, sizeof(struct person), 2, outfile);
// error checking for writing to file
	if(fwrite != 0) 
		printf("contents to file written successfully !\n"); 
	else
		printf("error writing file !\n"); 

	// close file 
	fclose (outfile);
	struct person input;
	infile = fopen("Fuck.txt","r");
	assert(infile);
	puts("closed writing"); 
	while(fread(&input,sizeof(struct person),1,infile))
	{
		printf("name: %s %s\tage: %d\n",input.fname,input.lname,input.id);
	}
	fclose(infile);
	return 0; 
} 
