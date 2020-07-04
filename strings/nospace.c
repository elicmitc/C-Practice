#include<stdio.h>
#include<string.h>
#include<assert.h>
#include<stdlib.h>
char* nospace(char* word)
{
	int size=0,i,spaces=0;
	char s1[2] = " ";
	size = strlen(word);
	for(i=0;i<size;i++)
	{
		if(word[i] == ' ')
		{
			spaces++;
		}
	}
	if(spaces>=1)
	{
		char *newword;int j=0;
		newword =(char*) malloc(sizeof(char)*(size-spaces));
		assert(newword);
		for(i=0;i<size;i++)
		{
			if(word[i] != ' '){
				newword[j] = word[i];
				j++;
			}
		}
		return newword;
	}
	return NULL;
}

int main(int nargs, char **vargs)
{
	char word[20]="well shit space",*newword;
	newword = nospace(word);
	if(newword == NULL) 
	{
		printf("No spaces in \"%s\"",word);
		return;
	}
	printf("Spaces deleted from \"%s\" to \"%s\"\n",word,newword);
	free(newword);
	
	return;	
}
