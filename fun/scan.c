#include <stdio.h> 
int main() 
{ 
    char m[1000],name[100];
    printf("Insert your characters\n");
    scanf(" %[^\n,z]s",&m);
    printf("characters entered: %s\n", m);
    printf("Enter your name: ");
    scanf(" %[^\n]s",&name);
    printf("name: %s\n",name); 
   return 0; 
} 
