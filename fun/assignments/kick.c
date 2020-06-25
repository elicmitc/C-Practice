#include <stdio.h>
#include <string.h>

struct student {
char lastName[15]; 
char firstName[15]; 
char major[10]; 
double gpa;
}individual[20];


int main(void) {
    int i,j=0;
    char fnames[][15] = {"Smith","Garcia","Lee","Williams","Johnson","Lopez","Jones","Anderson","Miller","Brown"};
    char lnames[][15] = {"James","Mary","John","Patricia","Robert","Jennifer","Micheal","Linda","William","Jessica"};
    char major[][10] = {"Info","Comp Sci","Biology","Account","Marketing","Chemistry","Engineer","Management","Info","Comp Sci"};
    double GPA[] = {3.5,3.8,3.9,3.5,3.6,3.8,3.7,3.0,3.0,3.75};
 
    for(i=0;i<20;i++)
    {

       // individual[i] =  {"unassigned", "", "n/a", 0};
        strcpy(individual[i].firstName,fnames[i]);
        strcpy(individual[i].lastName,lnames[i]);
        strcpy(individual[i].major, major[i]);
        individual[i].gpa = GPA[i];
    }
    for(i=0;i<20;i++)
    {
      if((i%2)== 0){
        printf("Person %d name: %s %s\n",i,individual[j].firstName,individual[j].lastName);
        j++;
      }
    }    
    return 0;
}
