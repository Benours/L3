#include <stdlib.h>
#include <stdio.h>

double fact(double n){
	double resultat = 1;
	for (int i = 1; i <= n; i++){
		resultat *= i;
	}
	return resultat;
}

int main()
{
	double valeur;
	printf("Entrer une valeur à calculer :\n");
	scanf("%lf", &valeur);
	printf("Le resultat est : %lf\n", fact(valeur));
	return 0;
}

