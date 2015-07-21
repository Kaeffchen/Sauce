/*four-in-a-row.h*/

#include "graphic.h"

#define ARROW_LEFT 68
#define ARROW_RIGHT 67

char game_area[WIDTH][HEIGHT];

int select_column(void); 

int add_coin( int player, int column );

int win(int column, int row);
