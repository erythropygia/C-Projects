#include <stdio.h>

int main(){
	char str1[]="quizsinavi";
	char str2[]={'q','u','i','z','s','i','n','a','v','i'};
	int n1=sizeof(str1)/sizeof(str1[0]);
	int n2=sizeof(str2)/sizeof(str2[0]);
	printf("n1=%d    n2=%d ", n1,n2);
	
}
