#include <iostream>
#include <vector>
#include <algorithm> // Para std::max
using namespace std;

const int menosInf = -1e8;
int maximoActual = menosInf;

int maxGanancia(const vector<int> &precios, int asteroides, int dia) {
    if (dia == precios.size()) {
        // Caso base: se ha alcanzado el final de los días
        return 0;
    } else {
        int comprar = menosInf; int vender = menosInf; int noHacerNada = menosInf;
        if (asteroides == 0) {
            //no se pude vender si no hay asteroides
            comprar = maxGanancia(precios, asteroides + 1, dia + 1) - precios[dia];
            noHacerNada = maxGanancia(precios, asteroides, dia + 1);
        } else{
            comprar = maxGanancia(precios, asteroides + 1, dia + 1) - precios[dia];
            vender = maxGanancia(precios, asteroides - 1, dia + 1) + precios[dia];
            noHacerNada = maxGanancia(precios, asteroides, dia + 1);
        }
        maximoActual = max({comprar, vender, noHacerNada});
        return maximoActual;
    }
}

int main() {
    int dias;
    cout << "Ingresa cantidad de dias: ";
    cin >> dias;

    vector<int> precios(dias);
    cout << "Ingresa " << dias << " precios:" << endl;
    for (int i = 0; i < dias; ++i) {
        std::cin >> precios[i];
    }
    int res = maxGanancia(precios, 0, 0);
    cout << "La máxima ganancia neta es: " << res << endl;

    return 0;
}
