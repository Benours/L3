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
	int k = 0;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			if (i < j){
				edge[k][0] = i;
				edge[k][1] = j;
				edge[k][2] = sqrt(pow(point[j].abs - point[i].abs, 2) + pow(point[j].ord - point[i].ord, 2));
				printf("(%d,%d) = %d\n", edge[k][0], edge[k][1], edge[k][2]);
				k++;
			}
		}
	}
}


void tri(int m, int edge[][3]){
	int ech_x = 0;
	int ech_y = 0;
	int ech_z = 0;
	for (int i = m - 1; i >= 0; i--){
		for (int j = 0 ; j < i; j++){
			if (edge[j+1][2] < edge[j][2]){
				ech_x = edge[j+1][0];
				ech_y = edge[j+1][1];
				ech_z = edge[j+1][2];
				edge[j+1][0] = edge[j][0];
				edge[j+1][1] = edge[j][1];
				edge[j+1][2] = edge[j][2];
				edge[j][0] = ech_x;
				edge[j][1] = ech_y;
				edge[j][2] = ech_z;
			}
		}
	}
}

void fusion(int edge[][3], int n, int m){
	int i, j, k;
	int x[n][3];
	for(i = 0, j = m, k = 0; k < n; k++){
		if (j == n){
			x[k][2] = edge[i++][2];
		}
		else if (i == m) {
			x[k][2] = edge[j++][2];
		}
		else if (edge[j][2] < edge[i][2]){
			x[k][2] = edge[j++][2];
		}
		else {
			x[k][2] = edge[i++][2];
		}



/*
		x[k][2] = j == n ? edge[i++][2]
		: i == m ? edge[j++][2]
		: edge[j][2] < edge[i][2] ? edge[j++][2]
		: edge[i++][2];
*/
	}
	for (i = 0; i < n; i++){
		edge[i][2] = x[i][2];
	}
}

void triFusion(int m, int edge[][3]){
	if (m < 2){
		return;
	}
	int milieu = m/2;
	int bedge[milieu][3];
	for (int i = 0; i < m-milieu; i++){
		bedge[i][0] = edge[i+milieu][0];
		bedge[i][1] = edge[i+milieu][1];
		bedge[i][2] = edge[i+milieu][2];
	}
	triFusion(milieu, edge);
	triFusion(m - milieu, bedge);
	fusion(edge, m, milieu);
}

void afficherEdge(int edge[][3], int n){
	printf("\n-- Afficher Edge --\n");
	for (int i = 0; i < n; i++)
	{
      printf("(%d,%d) = %d\n", edge[i][0], edge[i][1], edge[i][2]);
	}
}

void afficherAbre(int arbre[][2], int n){
	printf("\n-- Afficher Arbre --\n");
	for (int i = 0; i < n-1; i++)
	{
		printf("%d __ %d\n", arbre[i][0], arbre[i][1]);
	}
}

void kruskal(int n, int m, int edge[][3], int arbre[][2]){
	std::vector<int> V[n];
	int composantes[n];
	for(int i = 0; i < n;i++)
	{
		composantes[i] = i;
		V[i].push_back(i);
	}

	int a, b;
	int k = 0;

	for(int i = 0; i < m; i++)
	{
		if(composantes[edge[i][0]] != composantes[edge[i][1]])
		{

			a = composantes[edge[i][0]];
			b = composantes[edge[i][1]];

			arbre[k][0] = edge[i][0];
			arbre[k][1] = edge[i][1];

			k++;
			
			if(V[a].size() <= V[b].size())
			{
				a = b;
				b = composantes[edge[i][0]];
			}

			for(int k = V[b].size()-1; k >= 0; k--)
			{
				V[a].push_back(V[b][k]);
				V[b].pop_back();
				composantes[V[b][k]] = a;
			}
		}
	}
	printf("\n-- Afficher Composantes --\n");
	for (int i = 0; i < n; i++)
	{
		printf("%d\n", composantes[i]);
	}
}

void affichageGraphique(int n, coord point[], int arbre[][2])
// Cree le fichier Exemple.ps qui affiche
// les points et l'arbre de Kruskal.
{
  ofstream output;                           
  output.open("Exemple.ps",ios::out);
  output << "%!PS-Adobe-3.0" << endl;
  output << "%%BoundingBox: 0 0 612 792" << endl;
  output << endl;  
  for(int i=0;i<n;i++)
    {
      output << point[i].abs << " " << point[i].ord << " 3 0 360 arc" <<endl;
      output << "0 setgray" <<endl;
      output << "fill" <<endl;
      output << "stroke"<<endl;
      output << endl;
    }
  output << endl;
  for(int i=0;i<n-1;i++)
   {
     output << point[arbre[i][0]].abs << " " << point[arbre[i][0]].ord 
	    << " moveto" << endl;
     output << point[arbre[i][1]].abs << " " << point[arbre[i][1]].ord
	    << " lineto" << endl;
     output << "stroke" << endl;
     output << endl;
   }
  output << "showpage";
  output << endl;
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
  kruskal(n, m, edge, arbre);
  afficherAbre(arbre, n);
  affichageGraphique(n, point, arbre);

  return EXIT_SUCCESS;
}
