#include <iostream>
#include <vector>
#include <string>
//horas invertidos: 38
using namespace std;

struct input {
    vector<int> alturas; vector<int> anchuras;
};

struct output {
    int valorCrec; int valorDecrec;
};


vector<vector<int>> memoInc; //memo[indice][ultimo]
vector<vector<int>> memoDec;
vector<output> res;


void imprimir(vector<output> salida) {
    for (int i = 0; i < salida.size(); ++i) {
        if (salida[i].valorCrec >= salida[i].valorDecrec){
            cout<<"Case "<< i+1<<". Increasing ("<<salida[i].valorCrec<<"). Decreasing ("<<salida[i].valorDecrec<<")."<<endl;
        }
        else {
            cout<<"Case "<< i+1<<". Decreasing ("<<salida[i].valorDecrec<<"). Increasing ("<<salida[i].valorCrec<<")."<<endl;
        }
    }
}

int maxCreciente(input &valores, int i, int ultCrec) {
    if (i == valores.anchuras.size()) {
        return 0;
    }
    else {
        if (memoInc[i][ultCrec+1] != 0) {
            return memoInc[i][ultCrec+1];
        }
        //calcula creciente
        if (ultCrec == -1) {
            int contar = maxCreciente(valores, i+1, i) + valores.anchuras[i];
            int noContar = maxCreciente(valores, i+1, ultCrec);
            memoInc[i][ultCrec+1] = max(contar, noContar);
            return memoInc[i][ultCrec+1];
        }
        else {
            int alturaUltimoEdificio = valores.alturas[ultCrec];
            int alturaEdActual = valores.alturas[i];
            if (alturaEdActual > alturaUltimoEdificio) {
                int contar = maxCreciente(valores, i+1, i) + valores.anchuras[i];
                int noContar = maxCreciente(valores, i+1, ultCrec);
                memoInc[i][ultCrec+1] = max(contar, noContar);
                return memoInc[i][ultCrec+1];
            }
            else {
                int noContar = maxCreciente(valores, i+1, ultCrec);
                memoInc[i][ultCrec+1] = noContar;
                return memoInc[i][ultCrec+1];
            }
        }
    }
}

int maxDecrec(input &valores, int i, int ultDec) {
    if (i == valores.anchuras.size()) {
        return 0;
    }
    else {
        if (memoDec[i][ultDec+1] != 0) {
            return memoDec[i][ultDec+1];
        }
        //calcula decreciente
        if (ultDec == -1) {
            int contar = maxDecrec(valores, i+1, i) + valores.anchuras[i];
            int noContar = maxDecrec(valores, i+1, ultDec);
            memoDec[i][ultDec+1] = max(contar, noContar);
            return memoDec[i][ultDec+1];
        }
        else {
            int alturaUltimoEdificio = valores.alturas[ultDec];
            int alturaEdActual = valores.alturas[i];
            if (alturaEdActual < alturaUltimoEdificio) {
                int contar = maxDecrec(valores, i+1, i) + valores.anchuras[i];
                int noContar = maxDecrec(valores, i+1, ultDec);
                memoDec[i][ultDec+1] = max(contar, noContar);
                return memoDec[i][ultDec+1];
            }
            else {
                int noContar = maxDecrec(valores, i+1, ultDec);
                memoDec[i][ultDec+1] = noContar;
                return memoDec[i][ultDec+1];
            }
        }
    }
}


int main() {
    int test;
    cin>>test;
    while(test) {
        input esteCaso;
        int cantEdi; cin>>cantEdi;
        //ingreso altura
        for (int i = 0; i < cantEdi; ++i) {
            int n; cin>>n;
            esteCaso.alturas.push_back(n);
        }
        //ingreso anchura
        for (int i = 0; i < cantEdi; ++i) {
            int n; cin>>n;
            esteCaso.anchuras.push_back(n);
        }
        memoDec = vector<vector<int>>(cantEdi, vector<int>(cantEdi, 0));
        memoInc = vector<vector<int>>(cantEdi, vector<int>(cantEdi, 0));


        output este = {maxCreciente(esteCaso, 0, -1) ,maxDecrec(esteCaso, 0, -1)};
        res.push_back(este);
        test--;
    }
    //imprimir output
    imprimir(res);
    return 0;
}
