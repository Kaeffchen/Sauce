#include <stdio.h>
#include <stdlib.h>

#include "getch.h"
#include "four-in-a-row.h"

int main( int argc, char *argv[] )
{
	clear_game_area();
	
	int turn_counter = 0;    					//only for player 1!
	int player = 2;
	int winner;
	int column;
	int row; 	
	do
	{
		switch(player)
		{
			case 1: player++; break; 
			case 2: player--; break; 
		}
		display_game_area(0); 
		column = select_column(); 
		row = add_coin( player, column ); 
		display_game_area(column);
		if(turn_counter >= 4)
		{
			winner  = win(column, row);
		}
	}
	while( getch()!= 'q' || winner != 0 );

	printf("The winner is player %d!\n", winner); 

	return EXIT_SUCCESS;
}

int select_column(void)
{
	int column = 0;
	char selection;
	while( (selection=getch()) != '\n' )
	{
		switch(selection)
		{
			case ARROW_LEFT:
			{
				if( column > 0 )
				{
					column--;
					display_game_area(column);
				}
				break;
			}
			case ARROW_RIGHT:
			{
				if( column < WIDTH-1 )
				{
					column++;		//column will be at most WIDTH-1 (WIDTH would be OOB (out of bounds) )
					display_game_area(column);
				}
				break;
			}
			default:
			{
				break;
			}
		}
	}

	return column;
}

int add_coin( int player, int column )
{	
	char coin; 	

	if(player == 1)
	{
		coin = COIN_ONE; 
	}
	else
	{
		coin = COIN_TWO; 
	}

	int y = 0; 							//Top row
	if(game_area[column][y] != NO_COIN)
	{
		printf("Impossible\n"); 
	}

	int i = 0;
	while( i < HEIGHT && game_area[column][i]==NO_COIN )
	{
		i++;
	}
	game_area[column][i-1] = coin;
	return i-1;				//the row in which the coin ends up
}

int win( int column, int row )
{
	int winner;
	int counter[4] = {1, 1, 1, 1};		       			//4 directions
	int coin = game_area[column][row];
	int i=1;
	
	//up
	while(game_area[column][row-i] == coin)
	{				 	
		i++; 
		counter[0]++; 
	}

	//down	
	while(game_area[column][row+i] == coin)
	{				 	
		i++; 
		counter[0]++; 
	}

	//right
	while(game_area[column+i][row] == coin)
	{				 	
		i++; 
		counter[1]++; 
	}
	
	//left
		while(game_area[column-i][row] == coin)
	{				 	
		i++; 
		counter[1]++; 
	}

	//down right
	while(game_area[column+i][row+i] == coin)
	{				 	
		i++; 
		counter[2]++; 
	}	
	
	//up left
	while(game_area[column-i][row-i] == coin)
	{				 	
		i++; 
		counter[2]++; 
	}
	
	//up right
	while(game_area[column+i][row-i] == coin)
	{				 	
		i++;  
		counter[3]++; 
	}

	//down left
	while(game_area[column-i][row-+i] == coin)
	{				 	
		i++;  
		counter[3]++; 
	}

	int player; 
	switch(game_area[column][row])
	{
		case COIN_ONE: player = 1; break; 
		case COIN_TWO: player = 2; break;
	}
	
	for(i=0; i<4; i++)
	{
		if(counter[i]<4)
		{
			winner = 0; 
		}
		
		if(counter[i]>=4) 
		{
			winner = player; 
		}
	}

	return winner;
}
