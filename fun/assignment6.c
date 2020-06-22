#include <stdio.h>
#include <string.h>

struct student {
char lastName[ 15 ]; 
char firstName[ 15 ]; 
char major[ 10 ]; 
double gpa;
};

int main(void) {
    FILE *cfPtr; //file pointer

    if((cfPtr = fopen("nameage.dat", "wb"))==NULL){
        puts("File could not be opened.");
    }
    else{
        // initiate 20 structrues that are blank
        struct student blankStudent = {"unassigned", "", "n/a", 0};
        // fill in the even structures with data 
        unsigned int i;
        for(i = 1; i < 21; ++i){
            fwrite(&blankStudent, sizeof(struct student), 1, cfPtr);
        }
    
        for(i = 1; i < 21; ++i){
        struct student studentTwo = {"Smith", "James", "Info", 3.80 };
        if(i == 2){
            fwrite(&studentTwo, sizeof(struct student), 1, cfPtr);
        }
        struct student studentFour = {"Garcia", "Mary", "Comp Sci", 3.90};
        if(i == 4){
            fwrite(&studentFour, sizeof(struct student), 1, cfPtr);
        }
        struct student studentSix = {"Lee", "John", "Biology", 3.50};
        if(i == 6){
            fwrite(&studentSix, sizeof(struct student), 1, cfPtr);
        }
        struct student studentEight = {"Williams", "Patricia", "Account", 3.50};
        if(i == 8){
            fwrite(&studentEight, sizeof(struct student), 1, cfPtr);
        }
        struct student studentTen = {"Johnson", "Robert", "Marketing", 3.60};
        if(i == 10){
            fwrite(&studentTen, sizeof(struct student), 1, cfPtr);
        }
        struct student studentTwelve = {"Lopez","Jennifer", "Chemistry", 3.80};
        if(i == 12){
            fwrite(&studentTwelve, sizeof(struct student), 1, cfPtr);
        }
        struct student studentFourteen = {"Jones","Michael", "Engineer", 3.70};
        if(i == 14){
            fwrite(&studentFourteen, sizeof(struct student), 1, cfPtr);
        }
        struct student studentSixteen = {"Anderson", "Linda", "Management", 3.0};
        if(i == 16){
            fwrite(&studentSixteen, sizeof(struct student), 1, cfPtr);
        }
        struct student studentEighteen = {"Miller", "William", "Info", 3.0};
        if(i == 18){
            fwrite(&studentEighteen, sizeof(struct student), 1, cfPtr);
        }
        struct student studentTwenty = {"Brown", "Jessica", "Comp Sci", 3.75};
        if(i == 20){
            fwrite(&studentTwenty, sizeof(struct student), 1, cfPtr);
        }
        }
    
        
        //vars for search 
        char lname[15];
        char qMajor[10];

        //user input of names / major for search
        printf("Enter a lastname: ");
        scanf(" %s", lname);
        printf("and a Major (you can enter one or the other as well) ");
        scanf(" %s", qMajor);
//issues start here 
        //search database for a match 
        while(fread(student ,sizeof(struct student), 1, cfPtr)){}
            for(i=0; i<20; ++i){
                //name & major match 
                if(strcmp(lname, cfPtr->lastName) == 0 && strcmp(qMajor, cfPtr->major)== 0){
                    printf("%s", student.lastName);
                    printf("%s", student.firstName);
                    printf("%s", student.major);
                    printf("%f", student.gpa);
                }
                
                //no match above name match
                else if(strcmp(lname, student[i].lastName) = 0){
                    printf(("%s", student[i]);
                }
                // still no match, string match 
                else if(strcmp(qMajor, student[i].major) = 0){
                    printf(("%s", student[i]);
                }

                //no matches at all 
                else{
                    printf("No info");
                }
            }

            //remove duplicate names in the structures 
            int j;
            for(i= 0; i<sizeof(student); ++i){
                for(i= 0; i<sizeof(student); ++i){
                    if(strcmp(student[i], studdent[j])== 0){
                        student[j] = student[i];

                    }
                }
            }      
        }
    //close file   
    fclose (cfPtr);
    }
//issues end here 

/*
    //open analysis.txt 
    if((cfPtr = fopen("analysis.txt", "r"))==NULL){
        puts("File could not be opened.");
    }
    else{
        //print menu options 
        printf("Please select from the following: Enter \n a to display the nymber of numbers in the file \n b to display he number of characters in the files");
        printf("\n c display the number of characters in a file \n d to dusplay the number of sentences in a file \n display all of the above information for analysis.txt");
        // variables 
        char user;
        char ch;
        char sent[3];
        char word[3];
        int temp;
        int intCount = 0;
        int charCount = 0;
        int wordCount = 0;
        int sentCount = 0;

        //user input

        scanf("%c", user);
        
        //count number of intigers in file 
        while(fscanf(cfPtr, "%d", &temp)==1){
            intCount +=1;
        }

        //count the number of characters in the file 
        for(ch = getc(cfPtr); ch != EOF; ch = getc(cfPtr)){
            charCount += 1;
        }
        
        //count the number of words in the file 
        while(fscanf(cfPtr, " ", word)==1){
            wordCount += 1;
        }

        //count the numbner of sentneces in the file 
        while(fscanf(". ", sent)==1){
            sentCount += 1;
        }

        //based on user input print that appropriate data 
        //could have used CASE 
        switch(user){
            case 'A':
            case 'a':
                printf("The intiger count in the file is: %d", intCount);
                break;

            case 'B':
            case 'b':
                printf("The character count in the file is: %d", charCount);
                break;

            case 'C':
            case 'c':
                printf("The word count in the file is: %d", wordCount);
                break;
            case 'D':
            case 'd':
                printf("The sentence count in the file is: %d", sentCount);
                break;
            case 'E':
            case 'e':
                printf("The intiger count in the file is: %d", intCount);
                printf("The character count in the file is: %d", charCount);
                printf("The word count in the file is: %d", wordCount);
                printf("The sentence count in the file is: %d", sentCount);
                break;
     fclose (cfPtr);

    }
    */


}