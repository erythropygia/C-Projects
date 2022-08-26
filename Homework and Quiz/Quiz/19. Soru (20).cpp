#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int 

main(){
	srand(time(NULL));
	int i,j,k;
	i=rand()%10+1;
	j=rand()%5+i;
	k=i*j;
	printf ("%d\n",k);
	
}
