/*graphic.c*/

#include <stdio.h>
#include <stdlib.h>

#include "fiar.h"
#include "graphic.h"

void display_game_area(int column_selected, int player)
{
	system("clear");
	printf("\n\n");

	//put the column selector into the right position
	if( player == 1 )
	{
		printf(RED);
	}
	else if( player == 2 )
	{
		printf(GREEN);
	}
	if( player != -1 )
	{
		printf("Player %d's turn\n\n", player);
	}
	else
	{
		printf("\n\n");
	}
	printf(BLACK);

	putchar('\t');
	for( int i = 0; i < column_selected; i++ )
	{
		printf("  ");
	}
	printf("v");
	printf("\n");

	for( int y = 0; y < HEIGHT; y++ )
	{
		putchar('\t');
		/*only NO_COIN will be printed, but in different colors to show which player it is*/
		for( int x = 0; x < WIDTH; x++ )
		{
			if( game_area[x][y] == COIN_ONE )
			{
				printf(RED);
				printf( "%c ", NO_COIN );
			}
			else if( game_area[x][y] == COIN_TWO )
			{
				printf(GREEN);
				printf( "%c ", NO_COIN );
			}
			else
			{
				printf(BLACK);
				printf( "%c ", NO_COIN );
			}
		}
		printf(BLACK);
		printf("\n");
	}
}

void clear_game_area(void)
{
    for( int x = 0; x < WIDTH; x++ )
    {
        for( int y = 0; y < HEIGHT; y++ )
        {
            game_area[x][y] = NO_COIN;
        }
    }
}
