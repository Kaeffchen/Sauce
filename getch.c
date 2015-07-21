/*getch.c*/

#include "getch.h"

static struct termios new_io;
static struct termios old_io;

/*set terminal to cbreak mode	*
 *set flags ECHO and ICANON to 0*/
int cbreak(int fd)
{
	/*save previous terminal state*/
	if( tcgetattr(fd, &old_io) == -1 )	//check if it worked
	{
		return -1;
	}
	new_io = old_io;			//copy old state to new state

	/*change flags for new state*/
	new_io.c_lflag = new_io.c_lflag & ~(ECHO|ICANON);
	new_io.c_cc[VMIN] = 0;		//minimum 0 bytes, so getch doesn't wait until a key is pressed
	new_io.c_cc[VTIME]= 2;		//2 tenths of a second timeout, after that getch stops listening for key input

	/*set cbreak mode*/
	if( tcsetattr(fd, TCSAFLUSH, &new_io) == -1 )//check if it worked
	{
		return -1;
	}
	return 1;
}

/*the getch() function*/
int getch(void)
{
	int c;

	if( cbreak(STDIN_FILENO) == -1)	//check if cbreak() actually worked
	{
		return -1;
	}
	c = getchar();			//but with terminal in cbreak mode

	/*reset terminal to previous state*/
	tcsetattr( STDIN_FILENO, TCSANOW, &old_io );

	return c;		//if everything worked, return the character that was typed in
}
