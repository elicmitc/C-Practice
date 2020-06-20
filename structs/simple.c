#include<stdio.h>
#include<string.h>
struct human
{
	int age;
	char name[20];
}general;

void get_input(struct human general)
{
	general.age = 1;
	printf("age: %d\n",general.age);
}	


int main(void)
{
struct human Angie;
struct human Not;
get_input(Angie);
get_input(Not);
}
