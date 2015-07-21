/*graphic.c*/

#include "graphic.h"

int display_game_area(void)
{
	system("clear");
	puts("\n\n");
	for( int x = 0; x < WIDTH; x++ )
	{
		for( int y = 0; y < HEIGHT; y++ )
		{
			printf( "%c", game_area[x][y] );
		}
		putchar('\n');
	}
}

int clear_game_area(void)
{
    for( int x = 0; x < WIDTH; x++ )
    {
        for( int y = 0; y < HEIGHT; y++ )
        {
            game_area[x][y] = NO_COIN;
        }
    }
}
