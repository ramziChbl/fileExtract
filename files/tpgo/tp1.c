#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int max(int a, int b);
void afficherTableau(int matrice[], int tailleSac, int nbObjets);
void afficherObjets(int poids[], int gains[], int nbObjets);
void afficherObjetsPris(int poids[], int gains[], int pris[],int nbObjets);
void remplirMatrice(int matrice[], int poids[], int gains[], int nbObjets, int tailleSac);



int main(int argc, char* argv[])
{
    int tailleSac, nbObjets, *poids, *gains, *pris, *matrice;
    int saisieManuelle = 1; 
    /* tests */
    

    if(saisieManuelle)
    {
	/* Saisie manuelle */
        printf("Taille du sac a dos : ");
	scanf("%d",&tailleSac);
	printf("Nombre d'objets : ");
	scanf("%d", &nbObjets);

	poids = malloc(sizeof(int) * nbObjets);
	gains = malloc(sizeof(int) * nbObjets);
	pris = malloc(sizeof(int) * nbObjets);
	matrice = malloc(sizeof(int) * (nbObjets+1) * (tailleSac + 1));

	    /* Saise manuelle */
	 for(int i = 0; i<nbObjets; i++)
	{
	    printf("poids objet %d : ", i+1);
	    scanf("%d",&poids[i]);
	    printf("gain objet  %d : ", i+1);
	    scanf("%d", &gains[i]);
	    printf("\n");
	}
	printf("\n");
    }
    else
    {
	tailleSac = 18;
	nbObjets = 5;

       /* tests */
	poids[0] = 5;
        gains[0] = 6;
    
        poids[1] = 4;
	gains[1] = 3;

        poids[2] = 1;
        gains[2] = 1;
    
	poids[3] = 10;
	gains[3] = 9;

	poids[4] = 3;
	gains[4] = 3;
    }
    printf("\n");

//    system("clear");

    afficherObjets(poids, gains, nbObjets);
    remplirMatrice(matrice, poids, gains, nbObjets, tailleSac);


    for(int i = 0; i<=nbObjets; i++)
    {
        for(int j=0; j<=tailleSac; j++)
        {
            if(i == 0 || j == 0)
            {
                matrice[i * (tailleSac+1) + j] = 0;
            }
            else if (j < poids[i-1])
            {
                matrice[ i * (tailleSac+1) + j] = matrice[(i-1) * (tailleSac+1) + j];
            }
            else
            {
                matrice[ i * (tailleSac+1) + j] = max( matrice[(i-1) * (tailleSac+1) + j] , matrice[(i-1) * (tailleSac+1) + j - poids[i-1]] + gains[i-1] );
            }
        }
    }

    afficherTableau(matrice, tailleSac, nbObjets);
    
    int j = tailleSac;
    for(int i = nbObjets + 1; i>0; i--)
    {
        if(matrice[ i * (tailleSac+1) + j] == matrice[ (i-1) * (tailleSac+1) + j])
            pris[i-1] = 0;
        else if (matrice[ i * (tailleSac+1) + j] == matrice[(i-1) * (tailleSac+1) + j - poids[i-1]] + gains[i-1])
        {
            pris[i-1] = 1;
            j -= poids[i-1];
        }
    }
    printf("\n");
    printf("\n");

    afficherObjetsPris(poids, gains, pris, nbObjets);

    return 0;
}


int max(int a, int b)
{
    if(a >= b)
	return a;
    else
	return b;
}

void remplirMatrice(int matrice[], int poids[], int gains[], int nbObjets, int tailleSac)
{
    for(int i = 0; i<=nbObjets; i++)
    {
        for(int j=0; j<=tailleSac; j++)
        {
            if(i == 0 || j == 0)
            {
                matrice[i * (tailleSac+1) + j] = 0;
            }
            else if (j < poids[i-1])
            {
                matrice[ i * (tailleSac+1) + j] = matrice[(i-1) * (tailleSac+1) + j];
            }
            else
            {
                matrice[ i * (tailleSac+1) + j] = max( matrice[(i-1) * (tailleSac+1) + j] , matrice[(i-1) * (tailleSac+1) + j - poids[i-1]] + gains[i-1] );
            }
        }
    }
}

void afficherTableau(int matrice[], int tailleSac, int nbObjets)
{
    for(int i = 0; i<9+5*(tailleSac+1); i++)	printf("-");
    printf("\n");
    printf("| Poids |");
    for(int j = 0; j<=tailleSac; j++)
    {
	printf(" %2d |", j);
    }
    printf("\n");

    //printf("\n--------------------------------------------------------------------------------------\n");
    for(int i = 0; i<9+5*(tailleSac+1); i++)	printf("-");
    printf("\n");

    printf("|    %2d |", 0);
    for(int j = 0; j<=tailleSac; j++)
    {
	printf(" %2d |", 0);
    }
    printf("\n");

    for(int i = 0; i<9+5*(tailleSac+1); i++)	printf("-");
    printf("\n");

    for(int i = 1; i<=nbObjets; i++)
    {
	printf("|    %2d |", i);
	for(int j=0; j<=tailleSac; j++)
	{
	    printf(" %2d |", matrice[i * (tailleSac + 1) + j]);
	}
	printf("\n");    
	for(int i = 0; i<9+5*(tailleSac+1); i++)	printf("-");
	printf("\n");
    }
    printf("\n");

}

void afficherObjets(int poids[], int gains[], int nbObjets)
{
    printf("Objets :\n");

    for(int i = 0 ; i< 9 + 5*nbObjets; i++) printf("-");
    printf("\n");
    printf("| Objet |");
    for(int i = 0; i<nbObjets; i++)
    {
	printf(" %2d |", i+1);
    }
    printf("\n");   
    for(int i = 0 ; i< 9 + 5*nbObjets; i++) printf("-");
    printf("\n");   


    printf("| Poids |");
    for(int i = 0; i<nbObjets; i++)
    {
	printf(" %2d |", poids[i]);
    }
    printf("\n");
    for(int i = 0 ; i< 9 + 5*nbObjets; i++) printf("-");
    printf("\n");   

    printf("| Gain  |");
    for(int i = 0; i<nbObjets; i++)
    {
	printf(" %2d |", gains[i]);
    }
    printf("\n");
    for(int i = 0 ; i< 9 + 5*nbObjets; i++) printf("-");
    printf("\n");
    printf("\n");
}

void afficherObjetsPris(int poids[], int gains[], int pris[],int nbObjets)
{
    printf("Objets pris:\n");

    for(int i = 0 ; i< 9 + 5*nbObjets; i++) printf("-");
    printf("\n");
    printf("| Objet |");
    for(int i = 0; i<nbObjets; i++)
    {
	printf(" %2d |", i+1);
    }
    printf("\n");   
    for(int i = 0 ; i< 9 + 5*nbObjets; i++) printf("-");
    printf("\n");   


    printf("| Poids |");
    for(int i = 0; i<nbObjets; i++)
    {
	printf(" %2d |", poids[i]);
    }
    printf("\n");
    for(int i = 0 ; i< 9 + 5*nbObjets; i++) printf("-");
    printf("\n");   

    printf("| Gain  |");
    for(int i = 0; i<nbObjets; i++)
    {
	printf(" %2d |", gains[i]);
    }
    printf("\n");
    for(int i = 0 ; i< 9 + 5*nbObjets; i++) printf("-");
    printf("\n");

    printf("| Pris  |");
    for(int i = 0; i<nbObjets; i++)
    {
	if(pris[i] == 1)
	    printf(" %2d |", pris[i]);
	else
	    printf("    |");
    }
    printf("\n");
    for(int i = 0 ; i< 9 + 5*nbObjets; i++) printf("-");
    printf("\n");   
}
