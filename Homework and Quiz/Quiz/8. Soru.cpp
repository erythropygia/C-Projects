#include <stdio.h>

char *c[]={"quizsinavi", "blm","test","quiz"};
char **cp[]={c+3,c+2,c+1,c};
char ***cpp=cp;

int main(){
	
	printf("%s",**++cpp);
	printf("%s",*--*++cpp+3);
	printf("%s",*cpp[-2]+3);
	printf("%s",cpp[-1][-1]+1);
}
