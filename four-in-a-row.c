#include <stdio.h>
#include <stdlin.h>

#define WIDTH 8
#define HEIGHT 6
#define NO_COIN O
#define COIN_ONE |
#define COIN_TWO -
#define TRUE 1
#define FALSE 0

int game_area[WIDTH][HEIGHT];

int add_coin( int player, int column );
int clear_game_area();
int win();

int main( int argc, char *argv[] )
{
    clear_game_area();

    int player;
    int winner;
    do
    {

    }
    while( !(winner = win()) );

    return EXIT_SUCCESS;
}

int clear_game_area()
{
    for( int x = 0; x < WIDTH; x++ )
    {
        for( int y = 0; y < HEIGHT; y++ )
        {
            game_area[x][y] = NO_COIN;
        }
    }
}

int add_coin( int player, int column )
{

}

int win( void )
{
    int winner;
    return winner;
}
