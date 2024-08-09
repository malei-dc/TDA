#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

/*The sum of the attacking abilities of the 5 attackers needs to be maximized
 *If there is more than one combination, maximize the sum of the defending abilities of the 5 defenders
 *If there is still more than one combination, pick the attackers that come lexicographically earliest.
 *Quiero todos los casos para poder procesarlos al final de cada test
 */

struct input{
    string name; int atk; int def;
};

struct output{
    vector<string> atks; vector<string> defs;
};

struct resParcial{
    vector<string> atks; int sumAtk; vector<string> defs; int sumDef;
};

vector<output> outputs; //vector de salida para todos los casos
vector<bool> usados;
vector<string> atacantes;
vector<resParcial> esteCaso; //en un caso puede haber varias combinaciones que den max atk y def, los quiero guardar
int maximo = -1; //lo seteo en -1 por que sé que atk y def son enteros de [0,99]

void imprimirOutputs(){
    for (int i = 0; i < outputs.size(); ++i) {
        cout<<"Case "<< i+1<<":"<<endl;
        cout<<"("<<outputs[i].atks[0]<<", "<<outputs[i].atks[1]<<", "<<outputs[i].atks[2]<<", "<<outputs[i].atks[3]<<", "<<outputs[i].atks[4]<<")"<<endl;
        cout<<"("<<outputs[i].defs[0]<<", "<<outputs[i].defs[1]<<", "<<outputs[i].defs[2]<<", "<<outputs[i].defs[3]<<", "<<outputs[i].defs[4]<<")"<<endl;
    }
}

bool compareResParcial(const resParcial& a, const resParcial& b) {
    // comparar por orden lexicográfico en atks
    return a.atks < b.atks;
}

void procesarRes(vector<resParcial> &esteCaso){
    output out;
    //primero busco el max def
    int maximoDef = 0;
    vector<resParcial> aux;
    for (int i = 0; i < esteCaso.size(); ++i) {
        if (maximoDef < esteCaso[i].sumDef){
            maximoDef = esteCaso[i].sumDef;
            aux.clear();
            aux.push_back(esteCaso[i]);
        }
        else if(maximoDef == esteCaso[i].sumDef){
            aux.push_back(esteCaso[i]);
        }
    }//en aux tenemos atk y def maximizados. Ahora hay que ordenar en orden lexicografico.
    if (aux.size()==1){
        sort(aux[0].atks.begin(), aux[0].atks.end());
        sort(aux[0].defs.begin(), aux[0].defs.end());
    }
    else{
        for (int i = 0; i < aux.size(); ++i) {
            sort(aux[i].atks.begin(), aux[i].atks.end());
            sort(aux[i].defs.begin(), aux[i].defs.end());
        }
        sort(aux.begin(), aux.end(), compareResParcial);
    }
    //ya tengo ordenado por lexic, devuelvo el primero
    out.atks = aux[0].atks;
    out.defs = aux[0].defs;
    outputs.push_back(out);
}

void calcularDefs(resParcial &res, vector<input> &players, vector<bool> &usados){
    vector<string> defense; int def = 0;
    for (int i = 0; i < 10; ++i) {
        if (!usados[i]){
            defense.push_back(players[i].name);
            def = def + players[i].def;
        }
    }
    res.defs = defense;
    res.sumDef = def;
}

//caluloPos computa todas las combinaciones de posiciones de los jugadores maximizando atk
void calculoAtk(vector<input> &players, vector<bool> &usados, int sumaActual, vector<string> &atacantes, int indice){
    if (atacantes.size() == 5){
        if (sumaActual > maximo){
            maximo = sumaActual;
            esteCaso.clear();
            resParcial res;
            res.atks = atacantes; res.sumAtk = sumaActual;
            calcularDefs(res, players, usados);
            esteCaso.push_back(res);
            return;
        }else if (sumaActual == maximo){
            resParcial res;
            res.atks = atacantes; res.sumAtk = sumaActual;
            calcularDefs(res, players, usados);
            esteCaso.push_back(res);
            return;
        }
    }
    else{
        if(indice == 10)
            return;
        usados[indice] = true;
        atacantes.push_back(players[indice].name);
        calculoAtk(players, usados, sumaActual+players[indice].atk, atacantes, indice+1);
        usados[indice] = false;
        atacantes.pop_back();
        calculoAtk(players, usados, sumaActual, atacantes,indice+1);
    }
}

int main() {
    int testCases;
    cin>>testCases;
    while(testCases){
        vector<input> players;
        for (int i = 0; i < 10; ++i) {
            input player;
            cin>>player.name>>player.atk>>player.def;
            players.push_back(player);
        }
        usados = vector<bool>(10, false);
        atacantes.clear();
        maximo = -1;
        esteCaso.clear();
        //calculoPos solo va a maximizar atk y va a guardar en un vector todas las combinaciones que sean max
        calculoAtk(players, usados, 0, atacantes,0);
        //procesar esteCaso (si hay mas de una combinacion, elegir el mayor def y ordenarlo lexicof)
        procesarRes(esteCaso);

        testCases--;
    }
    imprimirOutputs();

    return 0;
    //#tiempo invertido: 7 horas
}
