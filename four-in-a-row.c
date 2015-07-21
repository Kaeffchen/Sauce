#include <stdio.h>
#include <stdlib.h>

#include "getch.h"
#include "four-in-a-row.h"

int main( int argc, char *argv[] )
{
	clear_game_area();
	
	int turn_counter = 0;    					//only for player 1!
	int player = 2;
	int winner = 0;
	int column = 0;
	int row; 	
	do
	{
		switch(player)
		{
			case 1: player++; break;
			case 2: player--; turn_counter++; break; //player-- so player is now 1, turn_counter++ cuz player 1 takes a turn
		}
		display_game_area(column); 
		column = select_column(column); 
		row = add_coin( player, column );
		if( turn_counter >= 4 )
		{
			winner = win(column, row);
		}
		display_game_area(column);
	}
	while( winner == 0 );

	printf("The winner is player %d!\n", winner); 

	return EXIT_SUCCESS;
}

int select_column(int startcolumn)
{
	int column = startcolumn;
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
	int row = i-1;	//HEIGHT would be out of bounds (OOB), and a field with a coin would be too low too
	game_area[column][row] = coin;
	return row;				//the row in which the coin ends up
}

int win( int column, int row )
{
	int winner;
	int counter[4] = {1, 1, 1, 1};		       			//4 directions
	int coin = game_area[column][row];

	int i=1;	//KJELL: das muss vor jeder while passieren (habe ich hinzugefügt), sonst ist i irgendwann so um die 30	
	//up
	while(game_area[column][row-i] == coin)
	{				 	
		i++; 
		counter[0]++;
	}

	i=1;		//guggst du
	//down	
	while(game_area[column][row+i] == coin)
	{				 	
		i++; 
		counter[0]++;
	}

	i=1;		//guggst du
	//right
	while(game_area[column+i][row] == coin)
	{				 	
		i++; 
		counter[1]++; 
	}
	
	i=1;		//guggst du
	//left
		while(game_area[column-i][row] == coin)
	{				 	
		i++; 
		counter[1]++; 
	}

	i=1;		//guggst du
	//down right
	while(game_area[column+i][row+i] == coin)
	{				 	
		i++; 
		counter[2]++; 
	}	

	i=1;		//guggst du	
	//up left
	while(game_area[column-i][row-i] == coin)
	{				 	
		i++; 
		counter[2]++; 
	}

	i=1;		//guggst du	
	//up right
	while(game_area[column+i][row-i] == coin)
	{				 	
		i++;  
		counter[3]++; 
	}

	i=1;		//guggst du
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
		if(counter[i] < 4)
		{
			winner = 0; 
		}
		
		if(counter[i] >= 4) 
		{
			winner = player;
			break;		//IMPORTANT! otherwise next counter[i] could be 0, and the loop will only quit when i has reached 3
		}
	}

	return winner;
}
