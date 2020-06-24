/* get user input
ask if user wants a window seat, a aisle  up to 3 time  
    if input == F 
    if there are seats available in first class 
        assign to first class rows 1-3
        remove that seat from the seats remaining in first class
     else ask them if they would like to selectyBusiness or Econom
    if input == B
    if there are seats available in business class 
        assign to bus clas rows 4-6
        remove that seat from the seats remaining inbusiness
    else ask them if they would like to select first or Economy
    if input == E
    if there are seats available in economy
    ask the user if they want priority economy
    if yes && there are seats available 
        assign to row 7
        remvoe aval. seats in row 7 
    elseif yes && no seats available then ask if they want regular economoy or to upgrade 
        if reg. econ. 
         assign to first class rows 8-15
         emove that seat from the seats remaining in econ class
        else ask if they want bus or first class
    else if no && seats in econ
        assign to econ. row 8-15
        remove that seat from the seats remaining in econ class
    else
     ask them if they would like to select first or bus
        if no
         printf("Next flight leaves in 3 hours")
print seating chard as an array 
print boarding pass
print flight manifest 
*/ 
//imports
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define SIZE 80
//functions 
void firstClass(void);
void busClass(void);
void ecoClass(void);
void specialSeat(void);
void goodSeat(void);
void map(void);
void ticket(void);
void manifest(void);
void seatDets(void);
char class, upgrade, specs, happy;
int row, seat, count = 1, i=0, j=0, k=0;

//arrays and pointers 
char sClass[SIZE];
char *pClass = sClass;
char passengers[SIZE];
char *pPass=passengers; 
char seats[4];
char *pSeats = seats;
char fname[SIZE];  
char lname[SIZE];
char * pFname = fname;
char * pLname = lname; 
//char print[1200];
//char pPrint = print; 
/*
//arrays and multipointers 
char ** manFN;
char ** manLN;
char ** manSeat;
char ** manClass;
//char ** manRow;
char ** manNSeat;
char ** manCount; 
int * manRow; 


manFN[count] = malloc(90);
manLN[count]=malloc(90);
manSeat[count] =malloc(90);  
/*
int ** manCount;
manRow[count] = malloc(90);
manNSeat[count] = malloc(90);
manSeat[count] = malloc(90);
*/




//array initialized
int seatsAv[15][6]={
  {0,0,0,0,0,0},
  {0,0,0,0,0,0},
  {0,0,0,0,0,0},
  {0,0,0,0,0,0},
  {0,0,0,0,0,0},
  {0,0,0,0,0,0},
  {0,0,0,0,0,0},
  {0,0,0,0,0,0},
  {0,0,0,0,0,0},
  {0,0,0,0,0,0},
  {0,0,0,0,0,0},
  {0,0,0,0,0,0},
  {0,0,0,0,0,0},
  {0,0,0,0,0,0},
  {0,0,0,0,0,0},
} ;

int seatsT[15][6]={
  {0,0,0,0,0,0},
  {0,0,0,0,0,0},
  {0,0,0,0,0,0},
  {0,0,0,0,0,0},
  {0,0,0,0,0,0},
  {0,0,0,0,0,0},
  {0,0,0,0,0,0},
  {0,0,0,0,0,0},
  {0,0,0,0,0,0},
  {0,0,0,0,0,0},
  {0,0,0,0,0,0},
  {0,0,0,0,0,0},
  {0,0,0,0,0,0},
  {0,0,0,0,0,0},
  {0,0,0,0,0,0},
} ;
//---------------------------------------------------------------------------------------
int main(void){  
  //run until killed 
  while(1){
    //get input for which class 
    printf("Please select a class you would like your ticket to be in: \n'F' for first class, \n'B' for business class, \n'E' for economy class \n Here: ");
    scanf(" %c", &class);

    //evaluate which class and call appropriate function 
    switch(class){                 
    case'F':
      printf("First Class: ");
      firstClass();
      break;
    case 'B':
      printf("Business Class: ");
      busClass();
      break;
    case 'E':
      printf("Economy Class: ");
      ecoClass();
      break;
      //if there is no valid input 
    default:
      printf("Invalid Choice. Please Restart the Program.\n");
      return(0);
    }
  }
}
//---------------------------------------------------------------------------------------
void firstClass(void){ // first class function  
  printf("Welcome to your first class selections\n");
  //check for an empty seat 
  for(i=0;i<2;i++){
    for (j=0;j<6;j++){
      // if there is an empy seat  in 1st cless do  this 
      if(seatsAv[i][j] == 0){
	seatDets();
	k+=1;
      }
      //if all seats are full as about upgrate 
      else if(seatsAv[i][j] == 1){
	printf("There is no more room in this class, do you want to change classes to business or economy?");
	scanf(" %c", &upgrade);
	//if upgrade is yest do this 
	if(upgrade == 'y' || upgrade == 'Y'){
	  int main();
	}
	else{
	  //inform of next flights and return to main menu 
	  printf("The next flight leaves in 3 hours\n");
	  main();
                          
	}
      }        
    }
  }
}


void busClass(void){ //bus class selectios 
  printf("Welcome to your business class selections\n");
  // empty seat 
  for(i=2;i<7;i++){
    for(j=0;j<6;j++){
      //if seats available 
      if(seatsAv[i][j] == 0){
	seatDets();
	k+=1;
      }
      //if seats aren't available 
      else if(seatsAv[i][j] == 1) {
	printf("There is no more room in this class, do you want to upgrade classes?");
	scanf(" %c", &upgrade);
	if(upgrade == 'y' || upgrade == 'Y'){
	  int main();
	}
	else{
	  printf("The next flight leaves in 3 hours\n");
	  main();
	}            
      }
    }
  }
}


//---------------------------------------------------------------------------------------
void ecoClass(void){ // eco class options 
  printf("Welcome to your economy class selections\n");
  //prefered seating 
  printf("Would you like to sit in the prefered economy seating section? Y/N? ");
  char prefered;
  scanf(" %c", &prefered);
  // if user wants prefered seating 
  if(prefered == 'y' || prefered =='Y'){
    //see if preferetd seating is available 
    for(j=0;j<=6; j++){
      //if yes pick a seat 
      if(seatsAv[6][j]==0){
	row =6;
	seatDets();
	k+=1;           
      }
      // if not return to main and tell user user no seats left 
      else if(seatsAv[i][j] == 1){
	printf("Sorry no more prefered seats are left");
	main();
      }
    }
  }
  //if no prefered seating is wanted 
  else if(prefered == 'N' || prefered == 'n'){
    //open seats 
    for(i=8;i<=15;i++){
      for (j=0;j<6;j++){\
	//if seats available 
	if(seatsAv[i][j] == 0){
	  seatDets();
	  k+=1;
	  //randomly assign row 
	  srand(time(NULL));
	  row = rand() % 7;
	  row+=8;
	  seatDets();
	  k+=1;
	}  
	//if no seats available                            
	else if(seatsAv[i][j] == 1){
	  printf("There is no more room in this class, do you want to upgrade classes?");
	  scanf(" %c", &upgrade);
	  if(upgrade == 'y' || upgrade =='Y'){
	    int main();
	  }
	  else{
	    printf("The next flight leaves in 3 hours\n");
	    main();
	  }
	}
      }
    }
  }
}

//---------------------------------------------------------------------------------------
//assign seat based on preferences 
void specialSeat(void){
  //aisle seat assignment  at random 
  if(specs == 'A'){
    int aisle[2]={2,3};
    srand(time(NULL));
    int s = rand() % 2;
    seat = aisle[s];
  }
  // window seat preferneces 
  else if(specs == 'W'){
    int window[2]={0,5};
    srand(time(NULL));
    int s = rand() % 2;
    seat = window[s];
  }
  // no preference
  else{
    srand(time(NULL));
    seat = rand() % 6;
  }
  //change seat from num to str 
  for(i=0;i<15;++i){
    for(j=0;j<6;++j){
      if(seat == 0){
	strcpy(seats, "AA");
      }
      else if(seat == 1){
	strcpy(seats, "BB");
      }
      else if(seat == 2){
	strcpy(seats, "CC");
      }
      else if(seat == 3){
	strcpy(seats, "DD");
      } 
      else if(seat == 4){
	strcpy(seats, "EE");
      }
      else if(seat == 5){
	strcpy(seats, "FF");
      }
           
    }
  }
}
//---------------------------------------------------------------------------------------
// as what kind of seat they want 
void seatDets(void){
  printf("Do you want a window seat (W) or Aisle Seat(A) or don't care (D)?");
  scanf(" %c", &specs);
  //rows at random 
  //assign first class row
  if(class == 'F'){
    row = rand() % 3;
  }
  //bus class rows 
  else if(class == 'B'){
    row = rand()%3;
    row += 3 ;
  }
  //call function 
  specialSeat();
  //verify seat is emppt 
  if(seatsAv[row][seat]== 1){ // if seat isn't empty try to get a new one 
    specialSeat(); 
  }
  else if(seatsAv[row][seat]== 0){ //if seat is empy 
    seatsAv[row][seat]= 1;

  }
  //call next function 
  goodSeat();
}
//---------------------------------------------------------------------------------------
//verify user likes the seat assigned 
void goodSeat(void){
  while(k<=2){
    //print seat info 
    printf("Your seat is in Row: %d Seat: %s\n", row+1, seats);
    printf("Are you happy with this seat? Y/N "); //see if user likes seat 
    scanf(" %c", &happy);
    if(happy == 'n' || happy == 'N'){ //if user doesn't like seat 
      seatsAv[row][seat]= 0; // make it empy 
      //call function for the appropriate class
      if(class == 'F'){ 
	firstClass();
      }
      else if(class == 'B'){
	busClass();
      }
      else if(class == 'E'){
	ecoClass();
      }
      else{
	printf("Not a valid option");
	main();
      }
      k+=1;
    }
    //oif user is happy 
    else if(happy == 'y' || happy == 'Y'){
      //printf("Congrats on your reservations! ");
      if(class == 'F'){
	strcpy(sClass, "First Class");
      }
      else if(class == 'B'){
	strcpy(sClass, "Business Class");
      }
      else if(class == 'E'){
	strcpy(sClass, "Economy Class");
      }
      //call next function 
      map();
      break;
    }
    break;
  }
}
//---------------------------------------------------------------------------------------
void map(void){
  printf("The seats with a 1 are taken\n");
  //print map of open seats 
  for(i=0;i<15;++i){
    printf("Row %d, Seats:", i+1);
    for(j=0;j<6;++j){
      printf(" %d ", seatsAv[i][j]);
      if(j==2){
	printf("AISLE");
      }
      else if(j==5){
	printf("\n");
      }
    }
  }
  ticket();
}
//---------------------------------------------------------------------------------------
void ticket(void){
  //insert name
  printf("Plese enter your first name: ");
  scanf(" %s", fname);
  printf("Please enter your last name: ");
  scanf(" %s", lname);
  //print boarding pass
  printf("\n\n\nHere is your boarding pass: \n\n\n");

    
  /*strcpy(manFN[count], fname);
    strcpy(manLN[count], lname);
    strcpy(manSeat[count], seats);
    strcpy(manClass[count], sClass);
   
    //copying string 
    strcpy(manRow[count], row);
    strcpy(manNSeat[count], seat);
    strcpy(manSeat[count]), seats);
    manCount[count]=count;
    manRow[count] = &row;
  */


  count+=1;

  printf("%s %s, Seat: %d%s, Level: %s \n\n\n\n\n\n", fname, lname, row, seats, sClass);
    char uSeat;
    int uRow=0; 
    int uNum=0; 
  //get search information 
  /*printf("Please insert the row:");
    scanf(" %d", &uRow);
    printf("Please insert the seat number:");
    scanf(" %c", &uSeat);
    if(uSeat == 'A'){
        uNum = 0;
    }
    if(uSeat == 'B'){
        uNum = 1;
    }
    if(uSeat == 'C'){
        uNum = 2;
    }
    if(uSeat == 'D'){
        uNum = 3;
    }
    if(uSeat == 'E'){
        uNum = 4;
    }
    if(uSeat == 'F'){
        uNum = 5;
    }
    // run comparison 
    if(seatsAv[uRow-1][uNum]== 1){ // if seat isn't empty try to get a new one 
        for(i=0, i<count, ++i){
            if(uRow == manRow[i] && uNum == manSeat[i]seat){
                printf("%s %s, Seat: %d%s, Level: %s \n\n\n\n\n\n", manFN[i], manLN[i], manRow[i], manSeat[i], manClass[i]);
            }
        }
    }
    if(seatsAv[uRow-1][uNum]== 0){
        printf("This seat is open!- No boarding pass available")
    }
        
    }
  */
  manifest();
  main();
   
}
//---------------------------------------------------------------------------------------

void manifest(void){
  char ** manFN = NULL;
  char ** manLN = NULL;
  char ** manSeat= NULL;
  char ** manClass= NULL;
  //char ** manRow;
  char ** manNSeat= NULL;
  char ** manCount= NULL; 
  int * manRow= NULL; 


  // manFN[count] = malloc(90);
  //  manLN[count]=malloc(90);
  // manSeat[count] =malloc(90);


  for(j=0; j<count;++i){
    printf("Name: %s", manFN[i]);

    
    printf(" %s", manLN[i]);
        
    printf(" \t\t Row: %d \t ", manRow[i]);
    
    printf("Seat: %s", manSeat[i]);
        
    printf("\n\n\n\n\n");
    k=0;
  }
}
