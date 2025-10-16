/*
    Ejercicio 3:
    Nombre y apellidos: Manuel Rojas Tuyen
    Sección: A
*/

#include<iostream>
#include<iomanip>
using namespace std;

void imprimirLista(int*, float*, int n);
void mergeSort(int * id, float* med, int inicio, int final, int* temp_id, float* temp_med);
void merge(int * id, float* med, int inicio, int medio, int final, int* temp_id, float* temp_med);
void buscarMediciones(int*, float*, int n, int valor);

int main(){

    const int MAX = 100;
    int id[MAX] = {2, 1, 2, 3, 1, 2};

    float med[MAX] = {410.5, 398.2, 409.8, 420.1, 399.5, 410.1};

    int n = 6;

    // Se corrige la logica de 'merge' y 'mergeSort' declarando arreglos auxiliares de tamaño constante  
    int temp_id[MAX];
    float temp_med[MAX];

    cout<<"\nlista original: "<<endl;
    imprimirLista(id, med, n);

    cout<<"\nlista ordenada:"<<endl;
    mergeSort(id, med, 0, n-1, temp_id, temp_med);
    imprimirLista(id, med, n);

    buscarMediciones(id, med, n, 2);

    return 0;
}

void imprimirLista(int* id, float* med, int n){
    cout<<fixed<<setprecision(1);
    for (int i = 0; i < n; i++)
    {
        cout<<"("<<*(id + i)<<", "<<*(med + i)<<")"<<endl;
    }
    cout<<endl;
}
void mergeSort(int* id, float* med, int inicio, int final, int* temp_id, float* temp_med){
    if (inicio>=final)
    {
        return;
    }

    int medio  = inicio + (final - inicio)/2;

    mergeSort(id, med, inicio, medio, temp_id, temp_med);
    mergeSort(id, med, medio+1, final, temp_id, temp_med);
    merge(id, med, inicio, medio, final, temp_id, temp_med);
}
void merge(int* id, float* med, int inicio, int medio, int final, int* temp_id, float* temp_med){
    int n1 = medio - inicio + 1;
    int n2 = final - medio;


    for (int i = 0; i < n1; i++) 
    {
        *(temp_id + i) = *(id + inicio + i);
        *(temp_med + i) = *(med + inicio + i);
    }
    
    for (int j = 0; j < n2; j++) 
    {
        *(temp_id + n1 + j) = *(id + medio + 1 + j);
        *(temp_med + n1 + j) = *(med + medio + 1 + j);
    }
    
    //indices
    int i = 0, d = n1, k = inicio;

    while (i<n1 && d< n1 + n2) {
        if (*(temp_id + i) <= *(temp_id + d)) 
        {
            *(id + k) = *(temp_id + i);
            *(med + k) = *(temp_med + i); 
            i++;
        } else {
            *(id + k) = *(temp_id + d);
            *(med + k) = *(temp_med + d); 
            d++;
        }
        k++;
    }
    
    while (i < n1)
    {
        *(id + k) = *(temp_id + i);
        *(med + k) = *(temp_med + i);
        i++;
        k++;
    }
    while (d < n1+n2)
    {
        *(id + k) = *(temp_id + d);
        *(med + k) = *(temp_med + d);
        d++;
        k++;
    }
    
    
    
}
void buscarMediciones(int* id, float* med, int n, int valor){
    int inicio = 0, fin = n-1;
    int encontrado = -1;

    while (inicio<=fin)
    {
        int medio = inicio + (fin - inicio) / 2;
        if (*(id + medio) == valor)
        {
            encontrado = medio;
            break;
        }
        if (*(id + medio) < valor)
        {
            inicio =  medio +1;
        }else
        {
            fin = medio - 1;
        }
    }
    
    if (encontrado != -1)
    {
        int i = encontrado;
        while (i>=0 && *(id + i)==valor)
        {
            i--;
        }
        int inicio_bloque = i+1;

        int j = encontrado;
        while (j<n && *(id + j)==valor)
        {
            j++;
        }
        int fin_bloque = j-1;

        cout<<"lista con id = "<<valor<<":"<<endl;
        for (int k = inicio_bloque; k <= fin_bloque; k++)
        {
            cout<<"("<<*(id + k)<<", "<<*(med + k)<<")"<<endl;
        }
        cout<<endl;
    }else{
        cout<<"No se econtraron mediciones para el ID solicitado"<<endl;
    }
    
}