#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char buff[10];
	size_t depth, x; x = depth = 0;
	FILE *f;

	//file handling shenanigans
	f = fopen("./input", "r");
	if(f == NULL){
		fprintf(stderr, "Error reading the file\n");
		exit (1);
	}
	
	while(fscanf(f, "%9s[^ ]", buff) != EOF){
		//Yanderedev moment
		if(!(strcmp(buff, "forward"))){
			fscanf(f, "%9s[^\n]", buff);
			if(feof(f))
				break;
			x += atoi(buff);
			
		}else if(!(strcmp(buff, "up"))){
			fscanf(f, "%9s[^\n]", buff);
			if(feof(f))
				break;
			depth -= atoi(buff);
			
		}else if(!(strcmp(buff, "down"))){
			fscanf(f, "%9s[^\n]", buff);
			if(feof(f))
				break;
			depth += atoi(buff);
		}
		
		if(feof(f))
			break;
	}

	printf( "depth: %ld\n"
			"x pos: %ld\n"
			"values multiplied: %ld\n",
			depth, x, depth*x);
			 
	return (0);
}
