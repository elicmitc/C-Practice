#include<stdio.h>
#include<strings.h>
#include<stdlib.h>

int main(void)
{
	int number;
	char s_number[20];
	printf("Enter a number: ");
	fgets(s_number, sizeof(s_number),stdin);
	printf("s_number: %s",s_number);
	sscanf(s_number, "%d",&number);
	printf("number: %d\n",number);
	printf("new number: ");
	scanf("%d",&number);
	printf("well here it is %d\n",number);
	printf("again: ");
	scanf("%d",&number);
	printf("well here it is %d\n",number);

	return;
}
