#include<iostream>
#include<iomanip>
using namespace std;

double promedio(double* arr, int n);
void difCentradas(double* arr, double* dif, int n);

int main(){
    const int MAX = 10;

    double arr[MAX]= {2, 5, 3, 7, 6};
    double dif[MAX];

    int n = 5;

    double prom = promedio(arr, n);
    difCentradas(arr, dif, n);

    cout<< left<< setw(8) << "Indice"<< setw(14)
    << "E_original" << setw(14) << "D_centrada"<<endl;
    cout<<"----------------------------------"<<endl;
    cout<<fixed<<setprecision(3);
    for (int i = 0; i < n; i++)
    {
        cout<< setw(8)<< i << setw(14)<< *(arr + i);
        if (i==0 || i==n-1)
        {
            cout<< setw(14) << "--";
        }else
        {
            cout<< setw(14) << *(dif + i);
        }
        cout<<endl;
        
    }
    

    cout<<"\nPromedio de energia: "<<prom<<endl;

    

    return 0;
}

double promedio(double* arr,  int n){
    double sum = 0;
    for ( double *p = arr; p < arr + n; p++)
    {
        sum += *p;
    }
    
    return (sum/n);
    
}
void difCentradas(double* arr, double* dif, int n){
    double *pd = dif + 1;

    for (double* p = arr + 1; p < arr + n - 1; p++, pd++)
    {
        *(pd) = (*(p + 1) - *(p - 1)) / 2.0;
    }

}