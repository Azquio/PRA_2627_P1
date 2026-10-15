#include<iostream>
#include<vector>
#include<chrono.h>
#include<algorithm>
using namespace std
template<typename T>

int busquedaBinaria(T val, vector& v, int ini, int fin){
        if(ini > fin){
                cout << "No se encuentra en el array" << endl;
                return -1;
        }
        int medio = (ini + fin)/2;
        if(v[medio] == val){
                return medio;
        }
        else if(v[medio]>val){
                return busquedaBinaria(val,v,ini,medio-1);
        }
        else{
                return busquedaBinaria(val,v,media + 1, fin);
        }
}
void QuickSort(vector& v, int ini, int fin){
        if(ini < fin){
                int pivot = Partition(v, ini, fin);
                QuickSort(v, ini , pivot -1);
                QuickSort(v, pivot + 1, fin);
        }
}
int Partition(vector& v, int ini, int fin){
        T val = v[fin];
        int i = ini;
        for(j=ini, j<= fin -1;j++){
                if(v[j] <= val){
                        swap(v[i],v[j]);
                        i += 1;
                }
        }
        swap(v[i],v[j]);
        return i;
}
