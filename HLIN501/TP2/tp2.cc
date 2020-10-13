#include <cstdlib>
#include <iostream>
#include <vector>
#include <fstream>
#include <math.h>

using namespace std;
typedef struct coord{int abs; int ord;} coord;

void pointRandom(int n, coord point[]){
	printf("\n-- Afficher Points --\n");
	srand(time(NULL));
	for (int i = 0; i < n; i++){
		point[i].abs = rand()%612;
		point[i].ord = rand()%792;
		printf("(%d, %d)\n", point[i].abs, point[i].ord);
	}
}

void distances(int n, int m, coord point[], int edge[][3]){
	printf("\n-- Afficher Distances --\n");
	int k = m;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			if (i != j && i < j){
				edge[k][0] = i;
				edge[k][1] = j;
				edge[k][2] = sqrt(pow(point[j].abs - point[i].abs, 2) + pow(point[j].ord - point[i].ord, 2));
				printf("(%d,%d) = %d\n", edge[k][0], edge[k][1], edge[k][2]);
				k--;
			}
		}
	}
}


void tri(int m, int edge[][3]){
	int ech;
	for (int i = m; i > 1; i--){
		for (int j = 0 ; j < i; j++){
			if (edge[j+1][2] < edge[j][2]){
				ech = edge[j+1][2];
				edge[j+1][2] = edge[j][2];
				edge[j][2] = ech;
			}
		}
	}
}

void afficherEdge(int edge[][3], int m){
	printf("\n-- Afficher Edge --\n");
	for (int i = 0; i < m; i++)
	{
		printf("%d\n", edge[i][2]);
	}
}

void afficherAbre(int arbre[][2], int n){
	printf("\n-- Afficher Arbre --\n");
	for (int i = 0; i < n-1; i++)
	{
		printf("%d __ %d\n", arbre[i][0], arbre[i][1]);
	}
}

void kruskal(int n, int edge[][3], int arbre[][2]){
	int composantes[n];
	for (int i = 0; i < n; i++)
	{
		composantes[i] = i;
	}
	int aux;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++)
		{
			if (composantes[i] < composantes[j]){
				aux = composantes[i];
				arbre[i][0] = composantes[i];
				arbre[i][1] = composantes[j];
				for (int k = 0; k < n; k++)
				{
					if (composantes[k] == aux){
						composantes[k] = composantes[j];
					}
				}
			}
		}
	}

	printf("\n-- Afficher Composantes --\n");
	for (int i = 0; i < n; i++)
	{
		printf("%d\n", composantes[i]);
	}
}

int 
main()
{
  int n;             //Le nombre de points.
  cout << "Entrer le nombre de points: ";
  cin >> n;
  int m=n*(n-1)/2;   // Le nombre de paires de points.
  coord point[n];    // Les coordonnees des points dans le plan.
  int edge[m][3];    // Les paires de points et le carre de leur longueur.
  int arbre[n-1][2]; // Les aretes de l'arbre de Kruskal. 

  pointRandom(n, point);
  distances(n, m, point, edge);
  tri(m, edge);
  afficherEdge(edge, m);
  kruskal(n, edge, arbre);
  afficherAbre(arbre, n);

  return EXIT_SUCCESS;
}
