/*graphic.c*/

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
