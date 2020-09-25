#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int** Matrice(int n){
	int** M = (int **)malloc(n*sizeof(int*));
	for (int i = 0; i <= n; i++){
		M[i] = (int *) malloc(i*sizeof(int));
		for (int j = 0; j < i; j++){
			M[i][j] = 1;
		}
	}
	return M;
}

int main(int argc, char* argv[]){
	int ** matrice = Matrice(atoi(argv[1]) + 1);
	for (int i = 0; i < atoi(argv[1]) + 1; i++){
		for (int j = 0; j < i; j++){
			if (matrice[i - 1][j - 1] && matrice[i - 1][j]){
				matrice[i][j] = matrice[i - 1][j - 1] + matrice[i - 1][j];
			}
			else {
				matrice[i][j] = 1;
			}
			printf("%d ", matrice[i][j]);
		}
		printf("\n");
	}
	printf("La valeur est : %d\n", matrice[atoi(argv[1])][atoi(argv[2]) - 1]);
}