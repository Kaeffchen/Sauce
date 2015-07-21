/*graphic.h*/

#define WIDTH 8
#define HEIGHT 6
#define NO_COIN 'O'
#define COIN_ONE '|'
#define COIN_TWO '-'

#define RED '\e[0;31m'
#define GREEN '\e[0;32m'
#define BLACK '\e[0;30m'

int clear_game_area(void);
int display_game_area(void);
