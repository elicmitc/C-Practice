#include<stdio.h>

void get_input(struct human)
{
	printf("in func\n");
}	


int main(void)
{
struct human{
	int age;
	char name[20];
}Angie;
get_input(Angie);

}
