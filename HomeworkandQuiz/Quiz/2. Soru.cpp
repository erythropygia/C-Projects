#include <stdio.h>

int main(){
	char *ptr="quiz";
	printf("%c\n",*&*&*ptr);
	
}
