#include<stdio.h>
#include <ncurses.h>
#include "key.h"
#include <time.h>
#include "ball.h"
#include "air_hockey.h"
#include <stdlib.h>
#include <string.h>

int n;
char level;
char startC; 
int player_1,read_char;
int player_2;
int rnd = 0;
int games1=0;
int games2=0;
int winner; 
float clock_begin;
float clock_end;
float run_time; 

void info(void){
 printf("How many games do you want to play? ");                                                                                                    
  scanf(" %d", &n);                                                                                                                                   
                                                                                                                                                      
  fflush(stdin);                                                                                                                                                                                                                                                                                 
  //level selection in menu                                                                                                                                                                                                           
  printf("Select the level of difficulty for the game.\nE for Easy \nM for Meium\nH for Hard. ");   
  scanf(" %c", &level);
  start(); 
  fflush(stdin);
}

int start(void){
  printf("Use the arrow keys or AWSD to move your slider. \nKeep the puck from going in the goal \nPress 't' to start the game: ");                    
  //t enter here                                                                                                                                                                                                                                                                                                                                                                                                                     
  while(startC != 't'){                                                                                                                                  
  scanf(" %c", &startC);                                                                                                                             
  }                                                                                                                                                                                                                                                                                                
  //for time to win                                                                                                                                
  clock_begin = clock();
  air_hockey();   
}

void print_score(void){
  mvprintw(5,5,"Scores: Player 1: %d \t Player 2: %d", player_1, player_2);
}

// Main Game function
void air_hockey(){                                                                                                                                                                                                                           
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
    int max_x = z->upper_left_x, max_y = z->upper_left_y;
    ball_t *b = init_ball(zone_width/2, zone_height/2, 1, 1);
    slider_t *top = init_slider(zone_width/2, 5, 'T');
    slider_t *bottom = init_slider(zone_width/2, zone_height-10, 'U');
    slider_t *goalT = init_slider(zone_width/2, 1, 'G');
    slider_t *goalB = init_slider(zone_width/2, zone_height-1, 'H');
    
    /*    
    //level assment and ball speed
    if(level == 'E'){
      tim = {0,200000000};
    }
    else if(level =='M'){
      tim = {0,20000000};
    }
    else{
     tim = {0,200000};
    }
    */
    
 
    draw_slider(goalB);
    draw_slider(goalT);
    draw_slider(top);
    draw_slider(bottom);
    draw_ball(b);
    refresh();
    nodelay(stdscr,TRUE);  // Do not wait for characters using getch.  
    noecho();
    print_score();
  while(1) {
    //printf("Scores: Player 1: %d \t Player 2: %d", player_1, player_2);
       // Move the current piece 
    if ((arrow = read_escape(&c)) != NOCHAR) {
        switch (read_escape(&arrow)) {
          // Functionality for Left Arrow Key that controls the bottom slider
          case LEFT:
            mvprintw(1, 5,"L");
            undraw_slider(bottom);
            moveSlider(bottom, bottom->upper_left_x - 3, bottom->upper_left_y);
            draw_slider(bottom);
            break;
          // Functionality for Rigth Arrow Key that controls the bottom slider
          case RIGHT:
            mvprintw(1, 5,"R");
            undraw_slider(bottom);
            moveSlider(bottom, bottom->upper_left_x + 3, bottom->upper_left_y);
            draw_slider(bottom);
            break;
          // Functionality for Left Arrow Key that controls the bottom slider
          case UP:
            mvprintw(1, 5,"L");
            undraw_slider(bottom);
            moveSlider(bottom, bottom->upper_left_x, bottom->upper_left_y - 1);
            draw_slider(bottom);
            break;
          // Functionality for Rigth Arrow Key that controls the bottom slider
          case DOWN:
            mvprintw(1, 5,"R");
            undraw_slider(bottom);
            moveSlider(bottom, bottom->upper_left_x, bottom->upper_left_y + 1);
            draw_slider(bottom);
            break;
          // Functionality for A Key that controls the top slider
          case A:
            mvprintw(1, 5,"A"); 
            undraw_slider(top);
            moveSlider(top, top->upper_left_x - 3, top->upper_left_y);
            draw_slider(top);
            break; 
          case D:
          // Functionality for D Key that controls the top slider
            mvprintw(1, 5,"D");
            undraw_slider(top);
            moveSlider(top, top->upper_left_x + 3, top->upper_left_y);
            draw_slider(top);
            break;
          case W:
            mvprintw(1, 5,"A"); 
            undraw_slider(top);
            moveSlider(top, top->upper_left_x, top->upper_left_y - 1);
            draw_slider(top);
            break; 
          case S:
          // Functionality for D Key that controls the top slider
            mvprintw(1, 5,"D");
            undraw_slider(top);
            moveSlider(top, top->upper_left_x, top->upper_left_y + 1);
            draw_slider(top);
            break;

          case MAX:
            if (z->upper_left_x != max_x && z->upper_left_y != max_y) {
              undraw_zone(z);
              undraw_slider(top);
              undraw_slider(bottom);
	      undraw_slider(goalT);
	      undraw_slider(goalB);
	      undraw_ball(b);
	      b->upper_left_x -2;
	      b->upper_left_y -2;
	      moveBall(b);
              moveSlider(top, top->upper_left_x - 2, top->upper_left_y - 2);
              moveSlider(bottom, bottom->upper_left_x - 2, bottom->upper_left_y - 2);
              moveSlider(goalT, goalT->upper_left_x - 2, goalT->upper_left_y - 3);
              moveSlider(goalB, goalB->upper_left_x - 2, goalB->upper_left_y - 3);
	      z->upper_left_x -= 2;
              z->upper_left_y -= 2;
              z->width += 4;
              z->height += 2;
	      draw_slider(goalT);
              draw_slider(goalB);
	      draw_ball(b);
              draw_slider(top);
              draw_slider(bottom);
              draw_zone(z);
            }
            break;

          case MIN:
            if (z->upper_left_x != max_x + 8 && z->upper_left_y != max_y + 8) {
              undraw_zone(z);
              undraw_slider(top);
              undraw_slider(bottom);
	      undraw_slider(goalT);
              undraw_slider(goalB);
              undraw_ball(b);
	      b->upper_left_x + 2;
              b->upper_left_y + 2;
              moveBall(b);
              moveSlider(top, top->upper_left_x + 2, top->upper_left_y + 2);
              moveSlider(bottom, bottom->upper_left_x + 2, bottom->upper_left_y + 2);
              moveSlider(goalT, goalT->upper_left_x + 2, goalT->upper_left_y + 3);
              moveSlider(goalB, goalB->upper_left_x + 2, goalB->upper_left_y + 3);
	      z->upper_left_x += 2;
              z->upper_left_y += 2;
              z->width -= 4;
              z->height -= 2;
	      draw_slider(goalT);
              draw_slider(goalB);
	      draw_ball(b);
              draw_slider(top);
              draw_slider(bottom);              
              draw_zone(z);
            }
            break;
	  case REGCHAR:
	     
		/*this creates the pause menu bones*/
		if(arrow == 'p' || arrow == 'P')
		{
		  initscr();
		  init_pair(1,COLOR_MAGENTA, COLOR_RED);
		  attron(COLOR_PAIR(1));
		  mvprintw(7,5,"Paused     ");
		  mvprintw(8,5,"Menu:");
		  refresh();
		  attroff(COLOR_PAIR(1));
		  mvprintw(9,5,"things filled in here..");
		}
		/*lets you scroll through the menu*/
		int where =0;
/*		while(read_char != 'q' && read_char != 'Q')
		{
		
		}
*/
		if(arrow == 'q' || arrow == 'Q')
		{
			initscr();
			start_color();
			init_pair(2,COLOR_MAGENTA,COLOR_RED);
			attron(COLOR_PAIR(2));
			mvprintw(21,40,"GAME OVER");
			mvprintw(22,40,"Press Any Key to Exit Game");
			refresh();
			attroff(COLOR_PAIR(2));
			exit(0);
		}
	    break; 
          default:
            mvprintw(1, 5,"%c", c);
            break;

	    //max score reached per game 
	    if(player_1 == 5 || player_2 == 5){
	      //end game 
	      break;
	    }    

        }
      } 
    refresh();
    undraw_zone(z);
    draw_zone(z);
    undraw_ball(b);
    moveBall(b);
    checkCollisionSlider(bottom, b);
    checkCollisionSlider(top, b);
    if(checkCollisionSlider(goalT, b) == true){
	player_1 +=1;
	undraw_ball(b);
	moveBall(b);
	draw_ball(b);
	print_score();
      }
    if(checkCollisionSlider(goalB, b) == true){
	    player_2 +=1;
	    undraw_ball(b);
	    moveBall(b);
	    draw_ball(b);
	    print_score();
      }

 
    checkCollisionWithZone(b, z);
    draw_ball(b);
    refresh();
    // usleep(200000);
    nanosleep(&tim, &tim_ret);
  }

  //determine who the winner is 
  if(player_1 > player_2){
    winner = 1;
    games1 +=1;
  }
  else{
    winner = 2;
    games2 +=1;
  }
  //game print statement 
  printf("Game over the time taken to win is %d. \nPlayer 1 scored: %d and Player 2 scored: %d. The winner is: Player %d.\n\\n", run_time, player_1, player_2, winner);

  //run for len of the series without killing program 
  if(rnd < n){
    start();
    rnd+=1;
  }
  //win lose senario picker 
  else {
    if(games1> games2){
      printf("Player 1 won the series");
    }
    else{
      printf("Player 2 won the series");
      info();
    }
  }  
}
