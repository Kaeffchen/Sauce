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
