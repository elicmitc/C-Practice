#include <stdio.h>

#define MAX_LETTERS 26

char alphabet[MAX_LETTERS];

void initialize_alphabet(char *a) {
  int i;
  char start = 'a';
  for(i=0;i<27;i++){
     a[i] = start;
     start++;
  }
  a[i] = '\0';
}

void reverse_print_alpha(char *b) {
  int end = MAX_LETTERS-1;
  printf("Reverse alpha...\n");
  initialize_alphabet(b);
  for (end;end>-1;end--){
    printf("%c ",b[end]);
  }
  printf("\n");
}

void show(char *alph) /*used for debugging*/
{
  int i;
  initialize_alphabet(alph);
  for(i=0;i<26;i++){
     printf("%c ",alph[i]);
     if(i%5 == 0){ printf("\n");}
  }
  printf("\n");
}
int main(void) {

  reverse_print_alpha(alphabet);
  return 0;
}

