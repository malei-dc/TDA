#include <iostream>
#include <vector>
#include<tuple>
#include <cmath>
using namespace std;
#define inf 1e9

vector<vector<tuple<int, int>>> memoria;

tuple<int, int> minTuple(const tuple<int, int>& a, const tuple<int, int>& b) {
    // Comparar primero los primeros elementos
    if (get<0>(a) < get<0>(b)) {
        return a;
    } else if (get<0>(a) > get<0>(b)) {
        return b;
    }
    // Si los primeros elementos son iguales, comparar los segundos elementos
    if (get<1>(a) < get<1>(b)) {
        return a;
    }
    return b;
}

tuple<int, int> optiPago (vector<int> &billetes, int indice, int costo){
    if (costo < 0) {
        return {abs(costo), 0};
    }
    else {
        if (indice == 0 && costo > 0) {
            return {inf, inf};
        }
        //2° checkeo si ya calcule este resultado previamente
        if (get<1>(memoria[indice][costo]) != -1) {
            return memoria[indice][costo];
        }
        tuple<int, int> contarBillete = {get<0>(optiPago(billetes, indice - 1, costo - billetes[indice])), 
                                            1 + get<1>(optiPago(billetes, indice - 1, costo - billetes[indice]))};
        tuple<int, int> noContarBillete = optiPago(billetes, indice - 1, costo);
        
        //3° guardo el resultado que calculé en este paso en la memoria
        memoria[indice][costo] = minTuple(contarBillete,noContarBillete);
        return minTuple(contarBillete,noContarBillete);
    }
}

int main() {
    int costo, size;
    vector<int> billetes;
    cout<<"Ingrese costo y  cant billetes: ";
    cin>>costo>>size;
    cout<<"Ingrese "<<size<<" billetes:"<<endl;
    while (size){
        int valor; cin>>valor; billetes.push_back(valor);
        size --;
    }
    //1° inicializo memoria
    memoria = vector(billetes.size(), vector(costo + 1, make_tuple(-1, -1)));

    tuple<int, int> costo_cantUsados = optiPago(billetes, billetes.size()-1, costo);

    cout<<"El minimo encontrado fue con costo excedente ";
    cout<<get<0>(costo_cantUsados)<<" usando "<<get<1>(costo_cantUsados)<<" billetes.";
    return 0;
}
