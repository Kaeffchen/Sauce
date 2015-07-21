/*graphic.c*/

#include "four-in-a-row.h"
#include "graphic.h"

int display_game_area( int column_selected )
{
	system("clear");
	puts("\n\n");

	//put the column selector into the right position
	for( int i = 0; i < column_selected-1; i++ )
	{
		putchar(' ');
	}
	putchar('v');
	for( int i = 0; i < WIDTH-column_selected; i++ )
	{
		putchar(' ');
	}
	putchar('\n');

	for( int x = 0; x < WIDTH; x++ )
	{
		putchar('\t');
		for( int y = 0; y < HEIGHT; y++ )
		{
			if( game_area[x][y] == COIN_ONE )
			{
				printf(RED);
				printf( "%c ", game_area[x][y] );
			}
			else if( game_area[x][y] == COIN_TWO )
			{
				printf(GREEN);
				printf( "%c ", game_area[x][y] );
			}
			else
			{
				printf(BLACK);
				printf( "%c ", game_area[x][y] );
			}
		}
		printf( "%s\n", BLACK );
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
