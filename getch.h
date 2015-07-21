/*getch.h*/

#include <stdio.h>		//for getchar();
#include <termios.h>		//for setting terminal flags
#include <unistd.h>

#define ARROW_LEFT 68
#define ARROW_RIGHT 67

int cbreak(int fd);
int getch(void);
