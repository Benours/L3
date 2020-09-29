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
	int a;
	int b;
	for (int i = 0; i < m; i++){
		do {
		a = rand()%n;
		b = rand()%n;

	} while (a == b);

			edge[i][0] = a;
			edge[i][1] = b;	
	}
	//afficher(m, edge);
}

void composante(int n, int m, int edge[][2], int comp[]){
	int aux;
	vector<int> T[n];
	for (int i = 0; i < n; i++){
		comp[i] = i;
		T[i].push_back(i);
	}

	/*printf("Composante avant :\n");
	for (int i = 0; i < n; i++){
		printf("%i\n", comp[i]);
	}*/
	int a;
	int b;
	int ech;
	for (int j = 0; j < m; j++){
		a = comp[edge[j][0]];
		b = comp[edge[j][1]];
		if (comp[edge[j][0]] != comp[edge[j][1]]){
		int i = 0;	
			if (T[a].size() < T[b].size()){
				while (T[a].size() != 0){
					ech = T[a][i];
					T[b].push_back(ech);
					a = b;
					i++;
					T[a].pop_back();
				}
			}
		}
	}
	
	printf("Composante apres :\n");
	for (int i = 0; i < n; i++){
		printf("%i - ", comp[i]);
	}
	printf("\n");
	
}

void ecritureTailles(int n, int m, int comp[]){
	int T0[n] = {0};
	int T1[n + 1] = {0};

	for (int i = 0; i < n; i++){
		T0[comp[i]]++;
	}
	/*
	for (int i = 0; i < n; i++){
		printf("%i- ", T0[i]);
	}
	printf("\n");
	*/
	for (int i = 0; i < n; i++){
		T1[T0[i]]++;
	}
	/*
	for (int i = 0; i < n+1; i++){
		printf("%i -", T1[i]);
	}
	printf("\n");
	*/
	printf("Il y a %d points isoles.\n", T1[1]);
	for (int i = 2; i <= n; i++){
		if (T1[i] != 0)
		printf("Il y a %d composantes de tailles %d.\n", T1[i], i);
	}
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
  ecritureTailles(n, m, comp);

  return EXIT_SUCCESS;
}
