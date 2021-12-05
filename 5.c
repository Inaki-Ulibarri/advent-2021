#include <stdio.h>
#include <stdlib.h>
#include <tgmath.h>

#define LESSER(foo, bar) ((foo < bar) ? foo : bar)
#define LENGTH 1000

struct vect{
	int x1, y1;
	int x2, y2;
};

void print_vect(struct vect v)
{
	printf("(%d,%d) -> (%d,%d)\n", v.x1, v.y1, v.x2, v.y2);
}

//read vectors from a file, this vector have the format
// x1,y1 -> x2,y2
void get_vects(struct vect *v, FILE *foo)
{
	//ignore commas and the arrow "->"
	char buf[10];
	char **restrict end = NULL;

	fgets(buf, 5, foo);
	sscanf(buf, "%s[^,->\n]", buf);
	v->x1 = strtol(buf, end, 10);

	fgets(buf, 5, foo);
	sscanf(buf, "%s[^,->\n]", buf);
	v->y1 = strtol(buf, end, 10);

	//get the " -> "
	fgets(buf, 4, foo);
	
	fgets(buf, 5, foo);
	sscanf(buf, "%s[^,->\n]", buf);
	v->x2 = strtol(buf, end, 10);

	fgets(buf, 5, foo);
	sscanf(buf, "%s[^,->\n]", buf);
	v->y2 = strtol(buf, end, 10);
}

//# of intersection in a given graph
int intersections(size_t graph[LENGTH][LENGTH])
{
	int count = 0;

		for(int i = 0; i < LENGTH; i++){
		for(int j = 0; j < LENGTH; j++){
			if(2 <= graph[i][j])
				count++;
		}
	}

	return (count);
}

int main()
{
	size_t graph[LENGTH][LENGTH] = {0};

	FILE *f = NULL;
	f = fopen("./input", "r");
	if(f == NULL){
		fprintf(stderr, "Error opening the file.\n");
		exit (1);
	}

	struct vect foo;

	do{
		get_vects(&foo, f);
		print_vect(foo);
		if(foo.x1 == foo.x2){ //is vertical
			int dy = abs(foo.y2 - foo.y1);
			int ly = LESSER(foo.y1, foo.y2);
			for(int i = 0; i < dy+1; i++){
				graph[ly+i][foo.x1]++;
			}
			
		}else if(foo.y1 == foo.y2){ //is horizontal
			int dx = abs(foo.x2 - foo.x1);
			int lx = LESSER(foo.x1, foo.x2);
			for(int i = 0; i < dx+1; i++){
				graph[foo.y1][lx+i]++;
			}
			
		}
	}while(!feof(f));

	//(0,0) always registers as a crossing point,
	//this is a simple workaround
	graph[0][0]--;
	
	size_t answer = intersections(graph);
	printf("There are %ld intersections.\n", answer);
	
	fclose(f);
	return (0);
}
