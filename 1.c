#include <stdio.h>
#define FOO(a) ((sizeof(a)/sizeof(a[0])))

int main()
{
	int arr[10] = {97, 90, 62, 93, 56, 71,
			    	89, 73, 62, 85};
	size_t count = 0;
			    	
	printf("%d: first element\n", arr[0]);
	for(size_t i= 1; i<FOO(arr); i++){
		printf("%d: ", arr[i]);

		if(arr[i-1] < arr[i]){
			printf("inc\n");
			count++;
		}
		else{
			printf("dec\n");
		}
	}

	printf("-------\n"
			"%ld increments\n", count);

	return (0);
}
