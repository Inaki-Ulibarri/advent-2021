#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	//file handling shenanigans
	FILE *f;
	f = fopen("./input", "r");
	if(f == NULL){
		fprintf(stderr,"Error opening the file.\n");
		exit (1);
	}

	//get the size of the string being inputed
	char buff[20];
	fscanf(f, "%19s[^\n]", buff);
	size_t foo = strlen(buff);

	struct bit{
		size_t ones;
		size_t zero;
	};
	struct bit colum[foo];
	//initialize the the thing to zeros
	for(size_t i = 0; i<foo; i++){
		colum[i].ones = 0;
		colum[i].zero = 0;
	}

	fseek(f, 0, SEEK_SET);

	char ch = 0;
	while(1){
		for(size_t i = 0;  i < foo+1; i++){
			ch = getc(f);
			switch(ch){
				case '1':
					colum[i].ones++;
					break;
				case '0':
					colum[i].zero++;
					break;
				case'\n':
					break;
				default:
					break;
			}
		}

		if(feof(f))
			break;
	}
	fclose(f);

	printf("gamma rate: ");
	for(size_t i = 0; i < foo; i++){
		if(colum[i].ones < colum[i].zero)
			printf("0"); 
		else
			printf("1");
	}
	printf("\n");

	printf("epsilon rate: ");
	for(size_t i = 0; i < foo; i++){
		if(colum[i].ones > colum[i].zero)
			printf("0"); 
		else
			printf("1");
	}
	printf("\n");
	
	return (0);
}
