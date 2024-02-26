#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void firstOccurrence(char input[], char search);
void occurrenceCount(char input[], char search);
void where(char input[], char search);

int main(){
	
	char input[20];
	char search;
	printf("Please Enter a String Word:");
	gets(input);
    printf("Please Enter the Letter to Search in the String:");
	scanf("%c",&search);
	firstOccurrence(input, search);
	occurrenceCount(input, search);
	where(input, search);
	
	return 0;
}

void firstOccurrence(char input[], char search){
   int i=0;
   int count=0;
   for(i=0;i<20;i++){
   	if(input[i]==search){
   		count++;
   		break;
	   }
   }
   if(count==0){
   	printf("The Searched Letter is Not in the Array");
   	return;
   }
  
   printf("In the String, the Letter %c is First Encountered at Element %d\n", search, i+1);
   return;
}

void occurrenceCount(char input[], char search){
	int i=0;
	int count=0;
	for(i=0;i<20;i++){
		if(input[i]==search){
			count++;
		}
	}
	if(count==0){
		return;
	}
   printf("In the String, the Letter %c Repeats %d Times\n", search, count);
   return;
}	

void where(char input[], char search){
	int i, a=0, count=0;
	int position[20];
    for(i=0;i<20;i++){
    	if(input[i]==search){
    		count++;
    		position[a]=i;
    		a++;
		}
	}
	
	if(count==0){
		return;
	}
	printf("In the String, the Letter %c is Found in Positions:", search);
	for(i=0;i<a;i++){
		printf("%d  ", position[i]+1);
	}
	printf("Numbered Letters\n");
}
