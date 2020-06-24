#include<stdio.h>
#include <ncurses.h>
#include "key.h"
#include <time.h>
#include "ball.h"
#include "air_hockey.h"
#include <stdlib.h>
#include <string.h>

int status = 0;
char startC;
//int player_1 = 0;  
//int player_2 = 0;
int start(void){
  printf("Use the arrow keys or AWSD to move your slider. \n Keep the puck from going in the goal \n Press 't' to start the game: ");
  scanf("% c", &startC);
  if(&startC == "t"){
    air_hockey();
}
  fflush(stdin);
}

void pause(){
  fflush(stdin); 
 while(&startC != "p" || &startC!= "P"){
    scanf(" %c", &startC);
  }
}


// Main Game function
void air_hockey(){
  //printf("\n\n Scores: Player 1: %d \t Player 2: %d", player_1, player_2);
    int zone_height, zone_width;
    struct timespec tim = {0,200000000};
    struct timespec tim_ret;
    int arrow, c;
    int slider_x_speed = 5, slider_y_speed = 5;
    initscr();
    getmaxyx(stdscr,zone_height, zone_width);
    zone_height-=1;
    zone_width-=1;
    zone_t *z = init_zone(0, 0, zone_width, zone_height);
    ball_t *b = init_ball(zone_width/2, zone_height/2, 1, 1);
    slider_t *top = init_slider(zone_width/2, 5, 'T');
    slider_t *bottom = init_slider(zone_width/2, zone_height-5, 'U');
    draw_zone(z);
    draw_slider(top);
    draw_slider(bottom);
    draw_ball(b);
    refresh();
    nodelay(stdscr,TRUE);  // Do not wait for characters using getch.  
    noecho();
  while(1) {
       //change the size of the game with +/- 
    if ((arrow = read_escape(&c)) != NOCHAR) {
      if(arrow ==43){
	z+=1;
	air_hockey();
      }
      else if( arrow == 45){
	z-=1;
	air_hockey();
      }
      // move sliders 
      else{
	  switch (arrow) {

          // Functionality for Left Arrow Key that controls the bottom slider
	  //pause the game
	  case 'P':
	  case 'p':
	    pause();
	    break;
	    //quit the game 
	  case 'q':
	  case 'Q':
	    exit(0);
	  case LEFT:
            mvprintw(1, 5,"L");
            break;
          // Functionality for Rigth Arrow Key that controls the bottom slider
          case RIGHT:
            mvprintw(1, 5,"R");
            break;
          // Functionality for A Key that controls the top slider
          case A:
            mvprintw(1, 5,"A"); 
            break; 
          case D:
          // Functionality for D Key that controls the top slider
            mvprintw(1, 5,"D");
            break;
          default:
            mvprintw(1, 5,"%c", c);
            break;

        }
      } 
    }
    refresh();
    undraw_zone(z);
    draw_zone(z);
    undraw_ball(b);
    moveBall(b);

    //where are these made
    checkCollisionSlider(bottom, b);
    checkCollisionSlider(top, b);
    //mine for goal
    // checkCollisionGoal(a);
    checkCollisionWithZone(b, z);
    draw_ball(b);
    refresh();
    // usleep(200000);
    nanosleep(&tim, &tim_ret);
  }

    
}
