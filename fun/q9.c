#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


int main(void){
    //a Print unsigned integer 1001 right justified in a 10-digit field with 5 digits.
    printf( "%10.5d\n", 1001);

    //b Print 7.350 in a 7-digit field with preceding zeros.
    printf("%07.3f\n", 7.350);

    //c Print 300 with and without a sign.
    /*signed int a = 300;
    unsigned int b = 300;
    printf("%i\t%u\n", a, b);
    */

    printf("%+d\t%d\n", 300, 300);

    //d Print -300 as unsigned number.
    printf("%u\n", -300);

    //e Read a hexadecimal value into variable hex.
    int hex;
    printf("Please enter an hexidecimal number without any prefixes here: ");
    scanf(" %x", &hex);
    printf("\n Here is the decimal conversion: %d \t Here is the original hexidecimal number: %X\n", hex, hex);

    //f Read an octal value into variable octal.
    unsigned int octal;
    printf("Please enter an octal number without any prefixes here (remember 8 and its multiples are an invalid octal number): ");
    scanf(" %o", &octal);
    printf("\nThe octal number is: %o \t Here is the octal number converted to decimal: %d\n", octal, octal);

    //g Print 200 in hexadecimal form preceded by 0x.
    printf("\n %#x\n", 200);

    //h Print 200 in octal form preceded by 0.
    printf("\n %#o\n", 200);

    //i Read characters into array m until the letter z is encountered.
    char m[1000];
    printf("Insert your characters into the array, when done press eneter. Z and any values after z is entered will not be stored. \n");
    scanf(" %[^z,Z]", m);
    printf("The characters you entered are %s \n\n", &m);

    //j Read a time of the form hh-mm-ss, storing the parts of the time in the integer variables hour, minute and second. 
    //Skip the dash (-) in the input stream. Use the assignment suppression character.
    int hour;
    int minute;
    int second;
    printf("Please insert the time in hh-mm-ss format: ");
    scanf(" %d%*c%d%*c%d", &hour, &minute, &second);
    printf("The time entered is %d hours %d minutes and %d seconds\n", hour, minute, second);

    //k Read a time of the form hh:mm:ss, storing the parts of the time in the integer variables hour, minute and second. 
    //Skip the colons (:) in the input stream. Do not use the assignment suppression character.
    printf("Please insert the time in hh:mm:ss format:");
    scanf(" %d:%d:%d", &hour, &minute, &second);
    printf("\nThe time entered is %d hours %d minutes and %d seconds\n", hour, minute, second);

    //l Read a string of the form "characters" from the standard input. Store the string in character array s. Eliminate the
    //quotation marks from the input stream.
    char s[11];
    printf("\nPlease enter the \"Characters\", with the double quotes here: ");

    scanf("\" %[^\"]", s);
    printf("\nThe string inserted is %s\n", s);

    /*    
    //Show what each of the following statements prints. If a statement is incorrect, indicate why.
    printf( "%-10d\n", 30000 );
    printf( "%s\n", "This is a string" ); //What is being printed is a string, therefore if needs to print a string not a char, so it would be %s insted of %c 
    printf( "%*.*lf\n", 8, 3, 7124.921654 );
    printf( "%#o\n%#X\n%#e\n", 17, 17, 1008.83619 );
    printf( "% d\n%+d\n", 1000000, 8000000 ); // the numbers intered are by default decimals, not long intigers so the %ld needs to be replaced with %d. Or a L needs to be added at the end of the two numbers. 
    printf( "%10.3E\n", 854.93738 );
    printf( "%10.3g\n", 264.93738 );
    printf( "%f\n", 10.937 ); // This is a float and therefore needs to be printed as "%f", not "%d"
    */
}

//////////////////////////
//The results from these corrected print statements are:
//a) 30000     
//b) This is a string
//c) 7124.922
//d) 021
//   0X11
//   1.008836e+03
//e)  1000000
//   +8000000
//f)  8.549E+02
//g)        265
//h) 10.937000