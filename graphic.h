/*graphic.h*/

#define WIDTH 8
#define HEIGHT 6
#define NO_COIN 'O'
#define COIN_ONE '|'
#define COIN_TWO '-'

#define RED "\e[1;31m"			//player 1
#define GREEN "\e[1;32m"		//player 2
#define BLACK "\e[0;30m"

void clear_game_area(void);
void display_game_area(int column_selected);
