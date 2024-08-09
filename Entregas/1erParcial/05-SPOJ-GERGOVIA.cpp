#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<long long int> outputs; //como voy a sumar valores abolutos declaro long long int por si overflow

int main() {

    while (true) {
        int n; cin >> n;
        if (n == 0)
            break;
        else {
            //ingreso n valores
            vector<int> valores;
            for (int i = 0; i < n; ++i) {
                int valor; cin >> valor;
                valores.push_back(valor);
            }
            /*calculo unidades de trabajo, como los valores positivos son compras y negativo son ventas, aprovecho de que la suma de todo
             * es 0 y sumo el trabajo de ir desde la casa 0 a la n-esima.*/
            long long int compra_ventas = 0;
            long long int trabajo = 0;
            for (int i = 0; i < n; ++i) {
                compra_ventas = compra_ventas + valores[i];
                trabajo = trabajo + abs(compra_ventas);
            }
            outputs.push_back(trabajo);
        }
    }

    //imprimo outputs
    for (int i = 0; i < outputs.size(); ++i) {
        cout << outputs[i] << endl;
    }

    return 0;
}
