/*
    Ejercicio 2:
    Nombre y apellidos: Manuel Rojas Tuyen
    Sección: A
*/

#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

void imprimirMatriz(double ** mat, int n);
void Transpuesta(double **  mat, double ** matT, int n);
void Inercia(double **  mat, double ** matT, double ** matI, int n);
double traza(double ** mat, int n);
double E_Normalizada(double ** matI, int n);

int main(){
    const int MAX = 10;

    double mat[MAX][MAX]={
        {1, 2, 3},
        {0, 1, 4},
        {2, 0, 1}
    };
    int n = 3;

    double matT[MAX][MAX];
    double matI[MAX][MAX];

    double *pMat[n];

    for (int i = 0; i < n; i++)
    {
        *(pMat + i) = *(mat + i);
    }

    double *pMatT[n];

    for (int i = 0; i < n; i++)
    {
        *(pMatT + i) = *(matT + i);
    }

    double *pMatI[n];

    for (int i = 0; i < n; i++)
    {
        *(pMatI + i) = *(matI + i);
    }

    imprimirMatriz(pMat, n);
    Transpuesta(pMat, pMatT, n);
    Inercia(pMat, pMatT, pMatI, n);
    double tr = traza(pMatI, n);
    double E = E_Normalizada(pMatI, n);

    cout<<"matriz A: "<<endl;
    imprimirMatriz(pMat, n);

    cout<<"matriz transpuesta: "<<endl;
    imprimirMatriz(pMatT, n);

    cout<<"matriz de inercia: "<<endl;
    imprimirMatriz(pMatI, n);

    cout<<"traza(I) = "<<tr<<endl;
    cout<<"energia normalizada E = "<<E<<endl;


    return 0;
}

void imprimirMatriz(double ** mat, int n){
    
    cout<< fixed <<setprecision(2);
    for (int i = 0; i < n; i++)
    {
        if (*(*(mat+ 0)+0) >=10)
        {
            for (int j = 0; j < n; j++)
            {
                
                cout<<setw(5)<<setfill('0');
                cout<<*(*(mat + i) + j) <<" ";
            }
        }else
        {
            for (int j = 0; j < n; j++)
            {
                cout<<*(*(mat + i) + j) <<" ";
            }
        }
        cout<<endl;
    }
    cout<<endl;
}

void Transpuesta(double **  mat, double ** matT, int n){
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            *(*(matT + j) + i) = *(*(mat + i) + j);
        }
    }
    
}
void Inercia(double **  mat, double ** matT, double ** matI, int n){
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            double sum = 0;

            for (int k = 0; k < n; k++)
            {
                sum += *(*(mat + i) + k) * *(*(matT + k) + j);
            }
            *(*(matI + i) + j) = sum;
        }
        
    }
    
}
double traza(double ** mat, int n){
    double tr = 0;
    for (int i = 0; i < n; i++)
    {
        tr += *(*(mat + i) + i);
    }
    return tr;
}
double E_Normalizada(double ** matI, int n){
    double E = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            E += pow(*(*(matI + i) + j), 2);
        }
    }
    E = E/(pow(n, 2));

    return E;
}