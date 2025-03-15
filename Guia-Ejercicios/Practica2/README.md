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
    > Asumimos que caso base $T(0)=C$, entonces cuando $n-2k=0$ (abarca todo el $n$) tenemos que $k = \frac{n}{2}$
    >
    > Reemplazando en la ecuación tenemos que:
    > 
    > $$T(n) = T(0) + 5 * \frac{n}{2}$$
    >
    > $$T(n) = C + \frac{5n}{2}$$
    >
    > La complejidad asitontica depende del término dominante, en este caso es $\frac{5n}{2}$ lo que implica que la complejidad de $T(n)$ es $O(n)$.

2. $T(n) = T(n − 1) + n$

    > Suguiendo la misma idea con el ejercicio de arriba, vamos a expandir la iteración.
    >
    > - $T(n) = T(n − 1) + n$
    > - $T(n-1)=T(n−2)+(n-1)$
    > - $T(n-2)=T(n−3)+(n-2)$
    > - ...
    > - $T(n)=T(1) + 2 +3 + ... + (n-1) + 1$
    >
    > Sabemos que la suma de $n$ numeros naturales es:
    >
    >$$\sum_{k=1}^{n}k = \frac{n(n+1)}{2} $$
    >
    > Si asumimos que $T(1)$ es una cte $C$ entonces nos queda que la complejidad de $T(n)$ es $O(n^2)$

3. $T(n) = T(n − 1) + \sqrt{n}$

    > Acá vamos a empezar a ser más "brutos", para no caer con muchas formalidades, pero solo por esta vez lo desarrollo de ambas formas. (como hacen los profes (? )

    > Si extendemos la recurrencia el término promedio de la raíz cuadrada está en el orden de $\sqrt{n}$  y hay aproximadamente $n$ términos. Entonces la aproximación gruesa que podemos hacer es que:
    >
    > $$T(n) \approx n * \sqrt{n} = n^{\frac{3}{2}}$$
    >
    > Conluyendo así que $T(n) = O(n^{\frac{3}{2}})$

    >De la forma más formal como venimos haciendo arriba expandiendo la recursión nos queda:
    >
    > - $T(n) = T(n − 1) + \sqrt{n}$
    > - $T(n-1) = T(n − 2) + \sqrt{n-1}$
    > - ...
    > - $T(n) = T(1) + \sum_{k=2}^{n} \sqrt{n}$
    >
    > Podemos aproximar la sumatoria con una integral:
    >
    > $$\sum_{k=2}^{n} \sqrt{n} \approx \int_{1}^{n}\sqrt{n} = \int_{1}^{n} n^{\frac{1}{2}} = \frac{2}{3} x^{\frac{3}{2}}$$
    >
    > Evaluando de $1$ a $n$:
    >
    > $$\frac{2}{3} n^{\frac{3}{2}} - \frac{2}{3} (1)^{\frac{3}{2}} = \frac{2}{3} n^{\frac{3}{2}} - \frac{2}{3}$$
    >
    > Dado que el término dominante es $O(n^{\frac{3}{2}})$ concluimos que $T(n) = O(n^{\frac{3}{2}})$

4. $T(n) = T(n − 1) + n^2$

    > Si extendemos la recurrencia el término promedio está en el orden de $n^2$  y hay aproximadamente $n$ términos. Entonces la aproximación gruesa que podemos hacer es que:
    >
    > $$T(n) \approx n * n^2 = n^3$$
    >
    > Conluyendo así que $T(n) = O(n^3)$

    > De la forma formal sale usando la fórmula cerrada de suma de cuadrados: $\sum_{k=1}^{n} k^2 = \frac{n(n+1)(2n+1)}{6}$

5. $T(n) = 2T(n − 1)$

    > Si extendemos la recurrencia vemos que va apareciendo un $2$ multiplicando en cada paso recursivo. Lo que nos queda que:
    >
    > $$T(n) \approx 2^{n}$$
    >
    > Así que $T(n) = O(2^n)$

6. $T(n) = T(n/2) + n$

    > ---
    > En estos ejercicios donde tenemos todas las condiciones podemos usar el [teorema del maestro](/Guia-Ejercicios/Practica2/teorema_maestro.pdf), NO se puede usar si:
    >
    > - No hay reducción de tamaño del problema como $T(n) = T(n − 1) + f(n)$
    > - La estructura de la recurrencia no encaja con el patrón $aT(\frac{n}{c})+f(n) $
    > ---
    > Tenemos que $a = 1$, $c = 2$, $f(n) = n$ 
    >
    > - Calculamos $O(n^{log_2(1)}) = O(n^0) = O(1)$.
    > - Comparamos $f(n)$ con $O(1)$, en este caso tenemos que $O(n) > O(1)$ por lo tanto estamos en el caso 3 del teorema del maestro
    > - Para aplicar el caso 3, $f(n)$ tiene que cumplir que:
    > 
    > $$\exists \delta < 1 \diagup a*f(\frac{n}{c}) \leq \delta * f(n)$$ 
    >
    > - Reemplazando con los datos de nuestro caso nos queda:
    >
    > $$1*f(\frac{n}{2}) \leq \delta * f(n) \Rightarrow 1*\frac{n}{2} \leq \delta * n$$
    >
    > Si tomamos $\delta = \frac{1}{2}$ vemos que se cumple esta condición, y como $\frac{1}{2} < 1$ cumple con todo. Concluimos así por el teorema del maestro que $T(n) = O(f(n))= O(n)$ 

7. $T(n) = T(n/2) + \sqrt{n}$

    > Tenemos que $a = 1$, $c = 2$, $f(n) = \sqrt{n}$
    >
    > - Calculamos $O(n^{log_2(1)}) = O(n^0) = O(1)$.
    > - Comparamos $f(n)$ con $O(1)$, en este caso tenemos que $O(\sqrt{n}) > O(1)$ por lo tanto estamos en el caso 3 del teorema del maestro
    > - Para aplicar el caso 3, $f(n)$ tiene que cumplir que:
    > 
    > $$\exists \delta < 1 \diagup a*f(\frac{n}{c}) \leq \delta * f(n)$$ 
    >
    > - Reemplazando con los datos de nuestro caso nos queda:
    >
    > $$1*f(\frac{n}{2}) \leq \delta * f(n) \Rightarrow 1*\sqrt{\frac{n}{2}} \leq \delta * \sqrt{n} \Rightarrow \frac{\sqrt{n}}{\sqrt{2}} \leq \delta * \sqrt{n}$$
    >
    > Si tomamos $\delta = \frac{1}{\sqrt{2}}$ vemos que se cumple esta condición, y como $\frac{1}{\sqrt{2}} < 1$ cumple con todo. Concluimos así por el teorema del maestro que $T(n) = O(f(n))= O(\sqrt{n})$ 

8. $T(n) = T(n/2) + n^2$

    > Tenemos que $a = 1$, $c = 2$, $f(n) = n^2$
    >
    > - Calculamos $O(n^{log_2(1)}) = O(n^0) = O(1)$.
    > - Comparamos $f(n)$ con $O(1)$, en este caso tenemos que $O(n^2) > O(1)$ por lo tanto estamos en el caso 3 del teorema del maestro
    > - Para aplicar el caso 3, $f(n)$ tiene que cumplir que:
    > 
    > $$\exists \delta < 1 \diagup a*f(\frac{n}{c}) \leq \delta * f(n)$$ 
    >
    > - Reemplazando con los datos de nuestro caso nos queda:
    >
    > $$1*f(\frac{n}{2}) \leq \delta * f(n) \Rightarrow 1*\frac{n^2}{4} \leq \delta * n^2 $$
    >
    > Si tomamos $\delta = \frac{1}{4}$ vemos que se cumple esta condición, y como $\frac{1}{4} < 1$ cumple con todo. Concluimos así por el teorema del maestro que $T(n) = O(f(n))= O(n^2)$ 

9. $T(n) = 2T(n-4)$

    > Esto es $O(2^{\frac{n}{4}})$, asumiendo que $n$ es multiplo de 4 permitido por el enunciado. Muy parecido a 5 pero acá se reduce de a 4 por iteración.
 
10. $T(n) = 2T(n/2) + log(n)$
11. $T(n) = 3T(n/4)$
12. $T(n) = 3T(n/4) +n$