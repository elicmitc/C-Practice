#include<stdio.h>
//Matt Brownlee
//24 May 2020
//Assign 2
int main(void)
{
  //declare variabless 
  char input;
  float w_sal=0, h_sal=0, c_sal=0, p_sal=0, totPay=0, mPay=0, fPay=0, int_pay=0, dom_pay=0;
  int int_count=0, dom_count=0, mCount=0, fCount=0, w_fem=0, w_male=0, h_fem=0, h_male=0, c_male=0, c_fem=0, p_fem=0, p_male=0, w_int=0, w_dom=0, h_int=0, h_dom=0, c_int=0, c_dom=0, p_int=0, p_dom=0, arrSize=0;
  int i;
  char sex, nation;
  float pay, hours, pay_rate;
  //while loop to keep program running 
  while(1) {
    //welcome statement with options 
    printf("Welcome to your Payroll Calculator\nSelect from the following choices:\n\t\t\tWeekly Worker(W)\n\t\t\tHourly Worker(H)\n\t\t\tCommission Worker(C)\n\t\t\tPieceworker(P)\nEnter choice: ");
    //Collect user input 
    scanf(" %c", &input);
  
    //if input is Q/q break the loop and kill the program
    if(input == 'q'|| input =='Q'){
      break;
    }
    //if input matches one of these it is valid and perform switch
    if(input == 'W' || input == 'H' || input == 'C' || input == 'P'||input == 'w' || input == 'h' || input == 'c' || input == 'p'){
      printf("How many employees would you like to enter at this time (must be at least 2)?: ");
      scanf("%d", &arrSize);
      //if the array is less than 2 print error
      if(arrSize <2){
	printf("Please insert valid input of 2 or greater");
	printf("\n\n\n");
      }
      // 2 or greater continue on 
      else{
        //case for w
        if(input=='W' || input == 'w'){
        
	  //ask and collect user input 
	  for(i=0;i<arrSize; i++){

            printf("What is employee%d's weekly salary$?: ", i+1);
            scanf(" %f", &pay);
            printf("Is employee%d male (M) or Female (F)? ", i+1);
            scanf(" %c", &sex);    
            printf("Is employee%d an international student (I) or domestic stuent (D)?", i+1);
            scanf(" %c", &nation);

            //calculate total salary 
            totPay = totPay+pay;
            //calulate total weekly salary 
            w_sal = w_sal+pay;
            //calculate sex based dependancies
        
            if(sex == 'M'){
	      mCount = mCount+1;
	      mPay = mPay+pay;
	      w_male = w_male+1;
            }
            else if(sex== 'F'){
	      fCount = fCount+1;
	      fPay = fPay+pay;
	      w_fem = w_fem+1;
            }
            //calculate nationality based dependencies 
            if(nation == 'I'){
	      int_pay = int_pay+pay; 
	      int_count = int_count+1;
	      w_int = w_int+1;
            }
            else if(nation =='D'){
	      dom_pay = dom_count+pay;
	      dom_count = dom_count+1;
	      w_dom = w_dom+1;
                

            }
	  }
        }

        //case for h
        if(input=='H' || input == 'h'){

	  for(i=0;i<arrSize; i++){
            printf("How many hours did employee%d work this week? ", i+1);
            scanf(" %f", &hours);
            printf("How much does employee%d get payed per hour? $", i+1);
            scanf(" %f", &pay_rate);
            printf("Is employee%d male (M) or Female (F)", i+1);
            scanf(" %c", &sex);
            printf("Is employee%d an international student (I) or domestic (D)?", i+1);
            scanf(" %c", &nation);

            //calculate hourly pay and overtime
            if(hours>10&&nation == 'D'){
                pay = (10*pay_rate)+((pay_rate*1.5)*(hours-10));
            }
            else if(hours>10&&nation == 'I'){
                printf("\n\n\n\n\n\n\nInternational students cannot work more than 10 hours per week\n\n\n\n\n\n\n\n\n\n");
                break;
            }
            // calculate normal hourly rates with no overtime 
            else if(hours<=10){
                pay = hours*pay_rate;
            }

            totPay = totPay+pay;
            h_sal = h_sal+pay;

            if(sex == 'M'){
                mCount = mCount+1;
                mPay = mPay+pay;
                h_male = h_male+1;
            }
            else if(sex== 'F'){
                fCount = fCount+1;
                fPay = fPay+pay;
                h_fem = h_fem+1;
            }
            if(nation == 'I'){
                int_pay = int_pay+pay; 
                int_count = int_count+1;
                h_int = h_int+1;
            }
            else if(nation =='D'){
                dom_pay = dom_count+pay;
                dom_count = dom_count+1;
                h_dom = h_dom+1;

            }
            pay=0;
        }
        }
        
        
        //case for C
        if(input=='C' || input == 'c'){
        for(i=0; i<arrSize; i++){
            printf("What is the employee%d's gross weekly work hours? ", i+1);
            scanf(" %f", &hours);
            printf("Is the employee%d male (M) or Female (F)? ", i+1);
            scanf(" %c", &sex);
            printf("Is the employee%d an international student (I) or domestic (D)? ", i+1);
            scanf(" %c", &nation);
    
            pay = 250 + (7.1 * hours);
            totPay = totPay+pay;
            c_sal = c_sal+pay;
            if(sex == 'M'){
                mCount = mCount+1;
                mPay = mPay+pay;
                c_male = c_male+1;
            }
            else if(sex == 'F'){
                fCount = fCount+1;
                fPay = fPay+pay;
                c_fem = c_fem+1;
            }
            if(nation == 'I'){
                int_pay = int_pay+pay; 
                int_count = int_count+1;
                c_int = c_int+1;
            }
            else if(nation =='D'){
                dom_pay = dom_count+pay;
                dom_count = dom_count+1;
                c_dom = c_dom+1;
            
            }
            pay=0;
        }
    }

        //case for P 
        
      if(input=='P' || input == 'p'){
        for(i=0;i<arrSize; i++){
            printf("What is the amount paid for this piece done by employee%d? $", i+1);
            scanf(" %f", &pay);
            printf("Is  employee%d male (M) or Female (F)? ", i+1);
            scanf(" %c", &sex);
            printf("Is  employee%d an international student (I) or domestic (D)? ", i+1);
            scanf(" %c", &nation);

        
            totPay = totPay+pay;
            p_sal = p_sal+pay; 

            if(sex == 'M'){
                mCount = mCount+1;
                mPay = mPay+pay;
                p_male = p_male+1;
            }
            else if(sex == 'F'){
                fCount = fCount+1;
                fPay = fPay+pay;
                p_fem = p_fem+1;
            }
            if(nation == 'I'){
                int_pay = int_pay+pay; 
                int_count = int_count+1;
                p_int = p_int+1;
            }
            else if(nation =='D'){
                dom_pay = dom_count+pay;
                dom_count = dom_count+1;
                p_dom = p_dom+1;
                

            }
        
        }
        }
    

        //print out all of this information at the end 
        printf("\n\n\n");
        printf("The number of weekly female wokers is: %d, the number of male workers is: %d.\n", w_fem, w_male);
        printf("The number of weekly internations students is %d.\n", w_int);
        printf("The total weekly salary is: $%.2f.\n", w_sal);
        printf("The number of hourly female wokers is: %d, the number of male workers is: %d\n", h_fem, h_male);
        printf("The number of hourly internations students is %d.\n", h_int);
        printf("The total hourly salary is: $%.2f.\n", h_sal);
        printf("The number of commission female wokers is: %d, the number of male workers is: %d\n", c_fem, c_male);
        printf("The number of commission internations students is %d.\n", c_int);
        printf("The total commision salary is: $%.2f.\n", c_sal);
        printf("The number of project female wokers is: %d, the number of male workers is: %d\n", p_fem, p_male);
        printf("The number of project internations students is %d.\n", p_int);
        printf("The total project salary is: $%.2f.\n", p_sal);
        printf("The weekly salary paid to female employees is: $%.2f, the weekly salary for male employees is: $%.2f.\n", fPay, mPay);
        printf("The weekly salary paid to international students is: $%.2f, the weekly salary paid to domestic students is: $%.2f.\n", int_pay, dom_pay);
        printf("The total number of female employees is: %d, the total number of male employees is: %d.\n", fCount, mCount);
        printf("The total number of international student employees is: %d, the total number of domestic student employees is %d.\n", int_count, dom_count);
        printf("This weeks total salary is %.2f.\n", totPay);
        printf("\n\n\n");


        }   // end if statement for <2

    } //end if statement for work type 
    // alt print for less than 2 
    else{
    printf("Please select a valid option for work\n");
    printf("\n\n\n");
    }      
  }//end while loop
return(0);
} // end int function 
  
