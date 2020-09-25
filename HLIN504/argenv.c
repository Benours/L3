#include <stdlib.h>

int main(int argc,  char* argv[]){
	printf("Le nombre d'argument : %d\n", argc -1);
	for (int i = 1; i < argc; i++){
		printf("%s\n", argv[i]);
	}
}