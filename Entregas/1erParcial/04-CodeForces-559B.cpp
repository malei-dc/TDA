    #include <iostream>
    #include <string>
    using namespace std;

    bool sonIguales(string &pala1, string &pala2){
        //primer caso donde son iguales
        if (pala1 == pala2) {
            return true;
        }
        else {
            if (pala1.length()%2) return false; //no se puede partir en dos iguales con tamaño impar
            //caso base donde el tamaño es 1 y ver si son iguales
            if (pala1.length() == 1 && pala2.length() == 1){
                return pala1 == pala2;
            }
            //caso recursivo: corto a la mitad y checkeo condiciones de consigna
            int tamano = pala1.length();

            string a1 = pala1.substr(0, tamano / 2);
            string a2 = pala1.substr(tamano / 2, tamano / 2);
            string b1 = pala2.substr(0, tamano / 2);
            string b2 = pala2.substr(tamano / 2, tamano / 2);

            if (sonIguales(a1, b2) && sonIguales(a2, b1)) {
                return true;
            }
            else {
                if (sonIguales(a1, b1) && sonIguales(a2, b2))
                    return true;
            }
            return false;
        }
    }
    int main() {
        string palabra1, palabra2;
        cin >> palabra1 >> palabra2;

        if(sonIguales(palabra1, palabra2)){
            cout << "YES";
        }
        else
            cout << "NO";
        return 0;
    }
