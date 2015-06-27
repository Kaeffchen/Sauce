#include <stdio.h>
#include <stdio.h>
	
int main(int argc, char *argv[])
{
	FILE * fp
	if(argc != 2)
	{
		printf("ERROR\n");
		return EXIT_FAILURE; 
	}
	char dateiname[20], content[135]; 
	strncpy(dateiname, argv[1], 20); 
	fp = fopen("dateiname" "r");
	if(fp==NULL)
	{ 
		printf("ERROR! File could not be opened.\n"); 
		return EXIT_FAILURE; 
	}
	while(feof==0)
	{
		fgets(content, 135, fp); 
		printf("%s", content); 
	}
	return EXIT_SUCCESS; 
}
