# Practica 2: Dividir y conquistar

## 1) IzquierdaDominante

Escriba un algoritmo con dividir y conquistar que determine si un arreglo de tamaño potencia de 2 es más a la izquierda, donde “más a la izquierda” significa que:

- La suma de los elementos de la mitad izquierda superan los de la mitad derecha.
- Cada una de las mitades es a su vez “más a la izquierda”. Por ejemplo, el arreglo [8, 6, 7, 4, 5, 1, 3, 2] es “más a la izquierda”, pero [8, 4, 7, 6, 5, 1, 3, 2] no lo es.

Intente que su solución aproveche la técnica de modo que complejidad del algoritmo sea estrictamente menor a O(n2 ).

    bool izquierdaDominante(vector &valores, int desde, int hasta)
        if (desde == hasta)     //caso base arreglo de 1 elemento
            return true
        
        int mitad = desde + (hasta - desde)/2

        int sumaizq = 0;
        for (int i = 0; i < mitad; i++)
            sumaizq =+ valores[i];
        
        int sumader = 0;
        for (int i = mitad + 1; i < hasta; i++)
            sumader =+ valores[i];

        if (sumaizq > sumader)
            return izquierdaDominante(valores, desde, mitad) && izquierdaDominante(valores, mitad + 1, hasta);
        else
            return false;

> El algoritmo utiliza un enfoque de dividir y conquistar, donde se divide el arreglo en mitades y se realiza una comparación recursiva de las sumas de las mitades. Los principales pasos del algoritmo:
>
> - Dividir el arreglo en dos partes iguales.
> - Calcular la suma de los elementos de cada mitad.
> - Comparar las sumas de las mitades.
> - Si la suma de la mitad izquierda es mayor que la de la derecha, realizar la misma comparación recursivamente para ambas mitades.
> - Repetir el proceso hasta alcanzar el caso base, que es cuando el arreglo tiene solo un elemento.
>
> Ahora, veamos la complejidad temporal del algoritmo:
>
> - Dividir el arreglo en dos partes iguales requiere $O(1)$ operaciones. (Es una cuenta)
> - Calcular la suma de los elementos de cada mitad requiere $O(n)$ operaciones, donde $n$ es el tamaño del arreglo.
> - Comparar las sumas de las mitades también requiere $O(1)$ operaciones.
> - La recursión se realiza en cada mitad del arreglo hasta alcanzar el caso base.
>
> La recursión se realiza en cada mitad del arreglo hasta alcanzar el caso base, lo que resulta en $O(log(n))$ niveles de recursión.
>
> Por lo tanto, la complejidad temporal total del algoritmo es $O(n*log⁡(n))$, donde $n$ es el tamaño del arreglo. Esto se debe a que el proceso de dividir y conquistar divide el arreglo en mitades en cada nivel de recursión, lo que resulta en $O(log(n))$ niveles de recursión, y cada nivel realiza $O(n)$ operaciones para calcular las sumas de las mitades.
>
>En resumen, la complejidad temporal del algoritmo es $O(n*log⁡(n))$.
------
>
> Usando el teorema del maestro:
>
> Cada llamada recursiva divide el arreglo en dos mitades de tamaño igual, y luego se realizan $O(n)$ operaciones para calcular la suma de los elementos de cada mitad y compararlas. Por lo tanto, la recurrencia se puede expresar como: $T(n)=aT(\frac{n}{b}) + f(n) \Rightarrow T(n)=2T(\frac{n}{2}) + O(n)$
>
> - $a = 2$ es el número de subproblemas generados en cada recursión.
> - $b = 2$ es el factor por el cual el tamaño del problema se reduce en cada recursión.
> - $f(n) = O(n)$ es la cantidad de trabajo realizado en cada nivel de recursión.
>
> El teorema del maestro establece que la complejidad temporal del algoritmo es determinada por el término dominante en la recurrencia. En este caso, $f(n) = O(n)$ y $log⁡_{b}(a) = log_{2}(2) = 1$. Dado que $f(n)=O(n)$ coincide con $n^{log⁡_b(a)} = n¹ = n$ , estamos en el segundo caso del teorema del maestro, donde la complejidad temporal es $O(n*log(n))$.    

## 2) Índice Espejo

Tenemos un arreglo $a = [a_1, a_2, . . . , a_n]$ de $n$ enteros distintos (positivos y negativos) en orden estrictamente creciente. Queremos determinar si existe una posición $i$ tal que $a_i = i$. Por ejemplo, dado el arreglo $a = [−4,−1, 2, 4, 7]$, $i = 4$ es esa posición.

Diseñar un algoritmo dividir y conquistar eficiente (de complejidad de orden estrictamente menor que lineal) que resuelva el problema. Calcule y justifique la complejidad del algoritmo dado.

    int indiceEspejo(int arr[], int izquierda, int derecha) {
        while (izquierda <= derecha) {
            int medio = izquierda + (derecha - izquierda) / 2;

            if (arr[medio] == medio)
                return medio;

            // Si el objetivo es menor, ignorar la mitad derecha
            if (arr[medio] > medio)
                derecha = medio - 1;
            // Si el objetivo es mayor, ignorar la mitad izquierda
            else
                izquierda = medio + 1;
        }
        return -1; //No se encuentra en el arreglo
    }

> Aprovechamos que el arreglo es estrictamente creciente, si en un indice el valor del arreglo es mayor, también será mayor para los elemento posteriores del arreglo; analogamente si es menor. De esta forma podemos usar la busqueda binaria para resolver este problema donde el objetivo es escontrar que la posición del medio en el arreglo tenga el valor del índice, y si no, descartar la mitad correspondiente. Sabemos que la búsqueda binaria tiene complejidad $O(log(n))$ donde $n$ es la longitud del arreglo.

## 4) ComplexityQuest

Calcule la complejidad de un algoritmo que utiliza $T(n)$ pasos para una entrada de tamaño $n$, donde $T$ cumple:

1. $T(n) = T(n − 2) + 5$

    > Expandimos la iteración $k$ veces: 
    >
    > - $T(n)=T(n−2)+5$
    > - $T(n-2)=T(n−4)+5$
    > - $T(n-4)=T(n−6)+5$
    > - ...
    > - $T(n-2k)=T(n−2k)+5k$
    >
    > Asumimos que caso base $T(0)=C$, entonces cuando $n-2k=0$ tenemos que $k = \frac{n}{2}$
    >
    > Reemplazando en la ecuación tenemos que:
    > 
    > $$T(n) = T(0) + 5 * \frac{n}{2}$$
    >
    > $$T(n) = C + \frac{5n}{2}$$
    >
    > La complejidad asitontica depende del término dominante, en este caso es $\frac{5n}{2}$ lo que implica que la complejidad de $T(n)$ es $O(n)$.


2. $T(n) = T(n − 1) + n$
3. $T(n) = T(n − 1) + \sqrt{n}$
4. $T(n) = T(n − 1) + n^2$
5. $T(n) = 2T(n − 1)$
6. $T(n) = T(n/2) + n$
7. $T(n) = T(n/2) + \sqrt{n}$
8. $T(n) = T(n/2) + n^2$