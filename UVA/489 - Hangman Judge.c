#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void removeDuplicates(unsigned char *string) {
	unsigned char allCharacters [256] = { 0 };
	int lookAt;
	int writeTo = 0;
	for(lookAt = 0; lookAt < strlen(string); lookAt++){
		if(allCharacters[ string[lookAt] ] == 0) {
			allCharacters[ string[lookAt] ] = 1;
			string[writeTo++] = string[lookAt]; 
		}
	}
	string[writeTo] = '\0';
}


int main(){

	while (1){

		int r;
		scanf("%d",&r);
		if ( r == -1 ) break;

		char solution[2048];
		scanf("%s",solution);

		char sequence[2048];
		scanf("%s",sequence);
		removeDuplicates(sequence);

		int letters = strlen(solution);
		int tentatives = 7;

		int aux = 0;

		for ( aux = 0; aux < strlen(sequence); aux++ ){
			int aux2;
			int fail = 0;
			for ( aux2 = 0; aux2 < strlen(solution); aux2++ ){
				if (sequence[aux] == solution[aux2]){
					letters--;
					fail = 1;
				}
			}
			if (fail == 0){
				tentatives--;
			}
			if (tentatives <= 0) break;
		}

		printf("Round %d\n", r);
		if (letters == 0) {
			printf("You win.\n");
		} else if (tentatives <= 0){
			printf("You lose.\n");
		} else {
			printf("You chickened out.\n");
		}

	}
	
	return 0;
}