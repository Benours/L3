#include <cstdlib>
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;
typedef struct coord{int abs; int ord;} coord;


void pointRandom(int n, coord point[])
{
  srand(time(NULL));
  for(int i = 0; i < n; i++)
  {
    point[i].abs = rand()%613;
    point[i].ord = rand()%793;
  }
} 
void distances(int n, int m, coord point[], int edge[][3])
{
  printf("\n-- Afficher Distances --\n");
  int p1,p2,k = 0;
  for(int i = 0; i < n; i++)
  {
    for(int j = i+1; j < n; j++)
    {
      //euclidienne
      edge[k][0] = i;
      edge[k][1] = j;
      p1 = point[j].abs-point[i].abs;
      p2 = point[j].ord-point[i].ord;
      edge[k][2] = p1*p1+p2*p2;
      printf("(%d,%d) = %d\n", edge[k][0], edge[k][1], edge[k][2]);

      k++;
      //manhattan
      /*edge[k][0] = i;
      edge[k][1] = j;
      p1 = point[j].abs-point[i].abs;
      p1 = p1<0?-p1:p1;
      p2 = point[j].ord-point[i].ord;
      p2 = p2<0?-p2:p2;
      edge[k][2] = p1*p1+p2*p2;
      k++;*/
    }
  }
}
int compare(const void* a, const void* b)
{
  return ((int*)a)[2]-((int*)b)[2];
}
void tri(int m, int edge[][3])
{
  qsort(edge,m,sizeof(edge[0]),compare);
}
void kruskal(int n,int m, int edge[][3], int arbre[][2])
{
  vector<int> T[n];
  int comp[n];
  for(int i = 0; i < n;i++)
  {
    comp[i] = i;
    T[i].push_back(i);
  }
  int s_a, s_b, k = 0;
  for(int i = 0; i < m; i++)
  {
    if(comp[edge[i][0]] != comp[edge[i][1]])
    {
      
      s_a = comp[edge[i][0]];
      s_b = comp[edge[i][1]];

      arbre[k][0] = edge[i][0];
      arbre[k][1] = edge[i][1];
      k++;
      if(T[s_a].size() <= T[s_b].size())
      {
	s_a = s_b;
	s_b = comp[edge[i][0]];
      }
      for(int k = T[s_b].size()-1; k >= 0; k--)
      {
	T[s_a].push_back(T[s_b][k]);
	T[s_b].pop_back();
	comp[T[s_b][k]] = s_a;
      }
    }
  }
    printf("\n-- Afficher Arbre --\n");
  for (int i = 0; i < n-1; i++)
  {
    printf("%d __ %d\n", arbre[i][0], arbre[i][1]);
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

void afficherEdge(int edge[][3], int n){
  printf("\n-- Afficher Edge --\n");
  for (int i = 0; i < n; i++)
  {
      printf("(%d,%d) = %d\n", edge[i][0], edge[i][1], edge[i][2]);
  }
}

int main()
{
  int n;             //Le nombre de points.
  cout << "Entrer le nombre de points: ";
  cin >> n;
  int m=n*(n-1)/2;   // Le nombre de paires de points.
  coord point[n];    // Les coordonnees des points dans le plan.
  int edge[m][3];    // Les paires de points et le carre de leur longueur.
  int arbre[n-1][2]; // Les aretes de l'arbre de Kruskal. 

  pointRandom(n, point);
  distances(n,m, point, edge);
  tri(m, edge);
  afficherEdge(edge, m);
  kruskal(n,m,edge,arbre);
  affichageGraphique(n,point,arbre);
  return EXIT_SUCCESS;
}
