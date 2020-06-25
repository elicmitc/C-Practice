#include<stdio.h>
#include <ncurses.h>
#include <time.h>
#include "zone.h"
#include <stdlib.h>

// Initializes zone position and dimensions
zone_t *init_zone(int upper_left_x, int upper_left_y, int width, int height) {
  zone_t *z;
  z = malloc(sizeof(zone_t));
  z->upper_left_x = upper_left_x + 10;    // added 10 to create some space on the left side of the zone to display messages
  z->upper_left_y = upper_left_y;
  z->width = width-10;
  z->height = height;
  z->draw_char = '#';
  z->color[0] = 0;
  z->color[1] = 0;
  z->color[2] = 0;
  return (z);
}

/*zone_t *init_goalT(int upper_left_x, int upper_left_y, int width, int height) {
  zone_t *g;
  g = malloc(sizeof(zone_t));
  g->upper_left_x = upper_left_x + 350;    // added 10 to create some space on the left side of the zone to display messages                                                                                 
  g->upper_left_y = upper_left_y;
  g->width = width-10;
  g->height = 1;
  g->draw_char = '-';
  g->color[0] = 0;
  g->color[1] = 0;
  g->color[2] = 0;
  return (z);
}

*/



// Renders zone on the screen
void draw_zone(zone_t *z) {
  int row_counter, column_counter;

  // Draw the top side of the zone
  for (row_counter=z->upper_left_x;row_counter<=(z->upper_left_x + z->width);row_counter++) {
    mvprintw(z->upper_left_y,row_counter,"%c",z->draw_char);
  }


  // Draw left side of zone
  for (column_counter=z->upper_left_y;column_counter<=(z->upper_left_y + z->height);column_counter++) {
    mvprintw(column_counter,z->upper_left_x,"%c",z->draw_char);
  }

  // Draw right side of well
  for (column_counter=z->upper_left_y;column_counter<=(z->upper_left_y + z->height);column_counter++) {
    mvprintw(column_counter,(z->upper_left_x + z->width),"%c",z->draw_char);
  }
  
  // Draw Bottom of zone 
  for (row_counter=z->upper_left_x;row_counter<(z->upper_left_x + z->width);row_counter++) {
    // printf("%d\n", row_counter);
    // printf("%d\n", z->upper_left_y + z->height);
    mvprintw((z->upper_left_y + z->height),row_counter,"%c",z->draw_char);
    // printf("*****\n");
  }
}

/*
void draw_goalT(zone_t *g) {
  int row_counter, column_counter;

  // Draw the top side of the zone                                                                                                                                                                          
  for (row_counter=g->upper_left_x;row_counter<=(g->upper_left_x + g->width);row_counter++) {
    mvprintw(g->upper_left_y,row_counter,"%c",g->draw_char);
  }


  // Draw left side of zone                                                                                                                                                                                 
  for (column_counter=z->upper_left_y;column_counter<=(z->upper_left_y + z->height);column_counter++) {
    mvprintw(column_counter,z->upper_left_x,"%c",z->draw_char);
    }

  */





// Replaces the zone boundary with blank spaces
void undraw_zone(zone_t *z) {
  int row_counter, column_counter;

  // Draw the top side of the zone
  for (row_counter=z->upper_left_x;row_counter<=(z->upper_left_x + z->width);row_counter++) {
    mvprintw(z->upper_left_y,row_counter," ",z->draw_char);
  }


  // Draw left side of zone
  for (column_counter=z->upper_left_y;column_counter<=(z->upper_left_y + z->height);column_counter++) {
    mvprintw(column_counter,z->upper_left_x," ",z->draw_char);
  }

  // Draw right side of well
  for (column_counter=z->upper_left_y;column_counter<=(z->upper_left_y + z->height);column_counter++) {
    mvprintw(column_counter,(z->upper_left_x + z->width)," ",z->draw_char);
  }
  
  // Draw Bottom of zone 
  for (row_counter=z->upper_left_x;row_counter<=(z->upper_left_x + z->width);row_counter++) {
    mvprintw(z->upper_left_y + z->height,row_counter," ",z->draw_char);
  }
}
