/* key.c --- 
 * 
 * Filename: key.c
 * Description: 
 * Author: Bryce Himebaugh
 * Maintainer: 
 * Created: Thu Sep 15 16:35:07 2016
 * Last-Updated: 
 *           By: 
 *     Update #: 0
 * Keywords: 
 * Compatibility: 
 * 
 */

/* Commentary: 
 * 
 * 
 * 
 */

/* Change log:
 * 
 * 
 */

/* Copyright (c) 2016 The Trustees of Indiana University and 
 * Indiana University Research and Technology Corporation.  
 * 
 * All rights reserved. 
 * 
 * Additional copyrights may follow 
 */

/* Code: */
#include <ncurses.h> 
#include "key.h"

int read_escape(int *read_char) {
  int c; 
  if ((c = getch()) == ERR) {
    return (NOCHAR);
  }
  else if (c==0x1b) {
    if ((c = getch()) == '[') {
      c=getch();
      if (c == 'a')
        return (A);
      else if( c=='s')
        return (S);
      else if( c=='d')
        return (D);
      else if( c=='w')
        return (W);
      else if( c=='+')
        return (MAX);
      else if( c=='-')
        return (MIN);
      
      switch (c) {
        case 'A':
          return (UP);
          break;
        case 'B':
          return (DOWN);
          break;
        case 'C':
          return (RIGHT);
          break;
        case 'D':
          return (LEFT);
          break;
        default: 
          return (BADESC);
      }
    }
  }
  else {
    *read_char = c;
    switch(c){
      case 'a':
      case 'A': 
        return A;

      case 'w':
      case 'W': 
        return W;
        
      case 's':
      case 'S': 
        return S;
        
      case 'd':
      case 'D': 
        return D;

      case '+':
        return MAX;
      case '-':
        return MIN;

      default:
        return (REGCHAR);
    }
    
  }
}

/* key.c ends here */
