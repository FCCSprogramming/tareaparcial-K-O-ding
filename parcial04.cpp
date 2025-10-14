#include<iostream>
#include<cstring>
using namespace std;

int contar_apariciones(const char * str, const char* clave, int n1, int n2);
bool esDelimitador(char c);
int mas_coincidencias(int * arr, int n);
void imprimir_frase(const char * str, int n);

int main(){
    const char* str1 = "El ;agua, limpia es esencial para la vida, aguacate, aguacate";
    const char* str2 = "Cuidar el agua, es cuidar la vida, el agua es vida";
    const char* str3 = "El aire y el agua son vitales";

    const char *frases[] = {str1, str2, str3};
    int N=3;

    int size_1 = strlen(str1);
    int size_2 = strlen(str2);
    int size_3 = strlen(str3);

    int tamanios_frases[] = {size_1, size_2, size_3};

    const char* clave = "agua";
    int tamanio_clave = strlen(clave);

    int apar_str1 = contar_apariciones(str1, clave, size_1, tamanio_clave);
    int apar_str2 = contar_apariciones(str2, clave, size_2, tamanio_clave);
    int apar_str3 = contar_apariciones(str3, clave, size_3, tamanio_clave);

    int arr_apariciones[] = {apar_str1, apar_str2, apar_str3};
    int n = sizeof(arr_apariciones)/sizeof(arr_apariciones[0]);
    int frase_mas_coincidencias = mas_coincidencias(arr_apariciones, n);

    cout<<endl;
    for (int i = 0; i < N; i++)
    {
        cout<<"frase "<<i+1<<" -> "<<arr_apariciones[i]<<" aparicion(es)"<<endl;
    }

    cout<<"la clave aparece mas veces en la frase "<<frase_mas_coincidencias+1<<":"<<endl;
    imprimir_frase(frases[frase_mas_coincidencias], tamanios_frases[frase_mas_coincidencias]);

    cout<<"longitud de la frase: "<<tamanios_frases[frase_mas_coincidencias]<<endl;
    
    return 0;
}

int contar_apariciones(const char * str, const char* clave, int n1, int n2){
    int ctr1 = 0;
    int ctr2 = 0;
    for (int i = 0; i < n1; i++)
    {
        for (int j = 0; j < n2; j++)
        {
            if (*(str+ i +j)==*(clave+j))
            {
                ctr1++;
            }else
            {
                ctr1=0;
                break;
            }
        }
        if (ctr1 == n2 && (i==0 && esDelimitador(*(str+n2)) || (i== n1-n2 && esDelimitador(*(str+n1-n2-1))) || ( esDelimitador(*(str+i-1)) && esDelimitador(*(str+i + n2)) ) ) ) 
        {
            ctr2++;
        }
        ctr1=0;
        
    }
    return ctr2;
    
}
bool esDelimitador(char c){
    const char* delim = " ,.;:!?";
    return strchr(delim, c) != nullptr;
}

int mas_coincidencias(int * arr, int n){
    int max = *(arr+0);
    int indice = 0;
    for (int i = 0; i < n; i++)
    {
        if (*(arr+i) > max)
        {
            max = *(arr+i);
            indice = i;
        }
    }
    return indice;
}
void imprimir_frase(const char * str, int n){
    for (int i = 0; i < n; i++)
    {
        cout<<*(str+i);
    }
    cout<<endl;
}