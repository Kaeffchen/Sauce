/*getch.h*/

#include <stdio.h>		//for getchar();
#include <termios.h>		//for setting terminal flags
#include <unistd.h>

int cbreak(int fd);
int getch(void);
