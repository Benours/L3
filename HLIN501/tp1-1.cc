#include <cstdlib>
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void afficher(int m, int edge[][2]){
	printf("Arete :\n");
	for (int i = 0; i < m; i++){
		for (int j = 0; j < 2; j++){
			printf(" %i ", edge[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void graphRandom(int n, int m, int edge[][2]){
	srand(time(NULL));
	for (int i = 0; i < m; i++){
		for (int j = 0; j < 2; j++){
			edge[i][j] = rand()%n;
		}
	}
	afficher(m, edge);
}

void composante(int n, int m, int edge[][2], int comp[]){
	int aux;
	for (int i = 0; i < 2 * n; i = i + 2){
		comp[i] = edge[i][0];
		comp[i + 1] = edge[i][0];
	}

	printf("Composante avant :\n");
	for (int i = 0; i < 2*n; i++){
		printf("%i\n", comp[i]);
	}
	
	for (int j = 0; j < 2 * n - 1; j++){
		if (comp[j] != comp[j+1]){
			aux = comp[j+1];
		}
		for (int k = 0; k < n; k++){
			if (comp[k] == aux){
				comp[k] = comp[j+1];
			}
		}
	}
	
	printf("Composante apres :\n");
	for (int i = 0; i < 2*n; i++){
		printf("%i\n", comp[i]);
	}
}

void ecritureTailles(int n, int m, int comp[]){

}

int main()
{ 
  int n;     // Nombre de sommets.	
  int m;     // Nombre d'aretes.	
  cout << "Entrer le nombre de sommets:";
  cin >> n;
  cout << "Entrer le nombre d'aretes:";
  cin >> m;
  int edge[m][2];    // Tableau des aretes.
  int comp[n];       // comp[i] est le numero de la composante contenant i.

  graphRandom(n, m, edge);
  composante(n, m, edge, comp);

  return EXIT_SUCCESS;
}
