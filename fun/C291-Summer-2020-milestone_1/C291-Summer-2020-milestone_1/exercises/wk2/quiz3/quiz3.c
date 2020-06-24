/* Instructions:
 *
 *
 1. Write a program to assign a grade to Student. 
	Get the number of assignmnets from user.
  Get the students score out of how many points for each assignmnet.
	Calculate percentage and return the grade associated with a range of marks.
 2. The overall score range and the associated grades are as follows:
     a. [97-100] = A+
     b. [90-97] = A
     c. [80-90] = B
     d. [70-80] = C
     e. less than 70 is a failing grade and should be given an F
     e. greater than 100 or less than 0 is invalid and your code should print "Invalid"
 3. Use the skeleton code provided below to create a new function "printGrade" to assign a grade based on the score ranges.
 4. Use print statements in your function to display the grade. For example, if the input marks is 77, the output should read:
        "Your grade is : C"
 5. Please adhere to standard C syntax conventions and use comments to explain your code. Failure to do so will result in a penalty.
 *
 *
 * */
#include <stdio.h> 

void printGrade(int score){
	//print the students grade based on their score in the class
}
int main(void){
	char ch;
	float assignPoint=0, points=0, assignTot=0, total=0;
	int assignments=0;
	do {
		printf("How many assignmnets did you have ? ");
		scanf(" %d", &assignments); //get number of assignemnts
		int i=0;
		//		while(i<assignments){
		  for(i=0;i<assignments; ++i){ 
		  printf("Enter your points earned for assignment %d: ",i+1 ); //get assignment grades 
		  scanf(" %f", &assignPoint);
		  points = points +assignPoint;
		  assignPoint=0;
		//get the student's score and the max score for each assignment
		}
		int j;
		for(j=0; j<assignments; ++j){
		  printf("Enter the number of points possible for each assignment %d: ", j+1);
		  scanf("% f", &assignTot);
		  total = total +assignTot;
		  assignTot=0;
		}

    //calculate the student's percentage in the class using the information you've gathered.
		int percent;
		percent = points/total;//calculate percent 
		printGrade(percent);
		if(percent<0 || percent >100){ //invalid cases
		  printf("INVALID");
		}
		else{
		  printf("Your grade is: "); //print so it doesn't have to be repeared 
		  if(percent>=97 && percent <=100){ //a+ case
		    printf("A+");
		  }
		  else if(percent<97 && percent >= 90){ //a case
		    printf("A");
		  }
		  else if(percent<90 && percent >= 80){ //b case
		    printf("B"); 
		  }
		  else if(percent<80 && percent >=70){ //c case
		    printf("C");
		  }
		  else if(percent<70 && percent>=0){ //f case 
		    printf("F");
		  }
		  
		}
		printf("\n");
	
		printf(" \n Do you want to continue? (Y/N) ");
		scanf(" %c",&ch);
	} while(ch == 'y'|| ch == 'Y'); //continue?
}
