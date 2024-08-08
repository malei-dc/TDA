# Practica 1: tecnicas algoritmicas

## Bactracking

### 1) SumaSubconjuntosBT
Dado un multiconjunto $C = \{c_1 , ... , c_n \}$ de números naturales y un natural $k$, queremos determinar si existe un subconjunto de $C$ cuya sumatoria sea $k$. Vamos a suponer fuertemente que $C$ está ordenado de alguna forma arbitraria pero conocida (i.e., $C$ está implementado como
la secuencia $c_1 , ... , c_n$ o, análogamente, tenemos un iterador de $C$).Las soluciones (candidatas) son los vectores $a = (a_1 , ... , a_n)$ de valores binarios; el subconjunto de $C$ representado por $a$ contiene a $c_i$ si y sólo si $a_i = 1$. Luego, a es una solución válida cuando $\sum_{i=1}^n a_i c_i = k$. Asimismo, una solución parcial es un vector $p = (a_1 , ... , a_i)$ de números binarios con $0 \leq i \leq n$. Si $i < n$, las soluciones sucesoras de $p$ son $p \oplus 0$ y $p \oplus 1$, donde $\oplus$ indica la concatenación.

(a) Escribir el conjunto de soluciones candidatas para $C = \{6, 12, 6\}$ y $k = 12$.

>Soluciones candidatas: 
>- $a_1 = (0, 0, 0)$
>- $a_2 = (1, 0, 0)$
>- $a_3 = (1, 1, 0)$
>- $a_4 = (1, 0, 1)$
>- $a_5 = (1, 1, 1)$
>- $a_6 = (0, 1, 1)$
>- $a_7 = (0, 0, 1)$
>- $a_8 = (0, 1, 0)$    

(b) Escribir el conjunto de soluciones válidas para $C = \{6, 12, 6\}$ y $k = 12$.

>Soluciones validas: $a_1 = (0, 1, 0)$ y $a_2 = (1, 0, 1)$

(c) Escribir el conjunto de soluciones parciales para $C = \{6, 12, 6\}$ y $k = 12$.

![](https://github.com/malei-dc/TDA/blob/main/Guia-Ejercicios/Practica1/imgs/ej1parciales.png)
      

(d) Dibujar el árbol de backtracking correspondiente al algoritmo descrito arriba para $C = \{6, 12, 6\}$ y $k = 12$, indicando claramente la relación entre las distintas componentes del árbol y los conjuntos de los incisos anteriores.

>El arbol de backtracking es similar a las soluciones parciales, se empieza con la solucion vacia y se van agregando o no agregando elemntos al subconjunto, los nodos intermedios son soluciones parciales, y la hojas son soluciones candidatas. Las soluciones candidatas que sumen 12 seran las soluciones validas.

(e) Convencerse de que $ss(C, k) = V$ si y sólo si el problema de subconjuntos tiene una solución válida para la entrada $C$, $k$ (ver [enunciado](https://github.com/malei-dc/TDA/blob/main/Guia-Ejercicios/Practica1/Pr%C3%A1ctica%201%20-%20Backtracking%2C%20Programaci%C3%B3n%20Din%C3%A1mica%2C%20Algoritmos%20Greedy.pdf) )

>Me convence :)

(f) Convencerse de que la siguiente es una implementación recursiva de ss en un lenguaje imperativo y de que retorna la solución para $C$, $k$ cuando se llama con $C$, $|C|$, $k$. ¿Cuál es su complejidad?

1. $subset\_ sum(C, i, j)$:  // implementa $ss(\{c_1 ,... , c_i\}, j)$
2. Si $i = 0$, retornar $(j = 0)$
3. Si no, retornar $subset\_ sum(C, i − 1, j) \lor subset\_ sum(C, i − 1, j − C[i])$

>Me convence también :)

(g) Dibujar el árbol de llamadas recursivas para la entrada $C = \{6, 12, 6\}$ y $k = 12$, y compararlo con el árbol de backtracking. 

>Árbol de llamadas recursivas: Llamada: $ss(C, |C|, k)$
>
    Llamada recursiva: ss(C, i - 1, j) V ss(C, i - 1, j - C[i])

    ss(C, 3, 12)-> ss(C, 2, 12)                                                  
                -> ss(C, 1, 12)                   V                       ss(C, 1, 0)
                    -> ss(C, 0, 12) V ss(C, 0, 6)                             -> ss(C, 0, 0)   V ss(C, 0, -6)
                        false       V     false                                   true (0,1,0) V  false
                V
                -> ss(C, 2, 6)
                -> ss(C, 1, 6)                    V                       ss(C, 1, -6)
                    -> ss(C, 0, 6) V ss(C, 0, 0)                             -> ss(C, 0, -6) V ss(C, 0, -12)
                        false      V true (1,0,1)                                 false      V  false


(h) Considerar la siguiente regla de factibilidad: $p = (a_1 , ... , a_i)$ se puede extender a una solución válida sólo si $\sum_{q=1}^i a_q c_q \leq k$. Convencerse de que la siguiente implementación incluye la regla de factibilidad.
1. $subset\_ sum(C, i, j):$ // implementa $ss(\{c_1 , ... , c_i\}, j)$
2. Si $j < 0$, retornar $falso$ // regla de factibilidad
3. Si $i = 0$, retornar $(j = 0)$
4. Si no, retornar $subset\_ sum(C, i − 1, j) ∨ subset\_ sum(C, i − 1, j − C[i])$

>Me convence x3 :)

(i) Definir otra regla de factibilidad, mostrando que la misma es correcta; no es necesario implementarla.

>- Factibilidad: detener la exploración si la suma parcial supera T.
>- Optimalidad: si alcanzamos T antes de considerar todos los elementos, detenemos esa rama.
>
>Poda de factibilidad: la suma de lo actual mas los restantes sean menor que k

(j) Modificar la implementación para imprimir el subconjunto de C que suma k, si existe.

>[Codeado](https://github.com/malei-dc/TDA/blob/main/Guia-Ejercicios/Practica1/codes/P1Ej1-SumaSubconjuntosBT.cpp)

### 2) MagiCuadrados

Un cuadrado mágico de orden $n$, es un cuadrado con los números $\{1, . . . , n^2\}$, tal que todas sus filas, columnas y las dos diagonales suman lo mismo. El número que suma cada fila es llamado número mágico. El objetivo de este ejercicio es contar cuántos cuadrados mágicos de orden n existen.

(a) ¿Cuántos cuadrados habría que generar para encontrar todos los cuadrados mágicos si se utiliza una solución de fuerza bruta?

>Habría que generar $n²!$ cuadrados para encontrar todos los cuadrados magicos con fuerza bruta.

(b) Enunciar un algoritmo que use backtracking para resolver este problema que se base en la siguientes ideas:
- La solución parcial tiene los valores de las primeras $i − 1$ filas establecidos, al igual que los valores de las primeras $j$ columnas de la fila $i$.
- Para establecer el valor de la posición $(i, j +1)$ (o $(i+1, 1)$ si $j = n$ e $i \neq n$) se consideran todos los valores que aún no se encuentran en el cuadrado. Para cada valor posible, se establece dicho valor en la posición y se cuentan todos los cuadrados mágicos con esta
nueva solución parcial.

Mostrar los primeros dos niveles del árbol de backtracking para n = 3.

![](https://github.com/malei-dc/TDA/blob/main/Guia-Ejercicios/Practica1/imgs/ej2b.png)

(c) Demostrar que el árbol de backtracking tiene $O((n^2)!)$ nodos en peor caso.

>El primer nivel tiene $n$² nodos, cada nodo del primer nivel tiene $n²-1$ hijos, por lo que el segundo nivel tiene $n²*(n²-1)$ nodos y asi... $n²*(n²-1)*(n²-2)*(n²-3)* ... *1$ , luego el arbol de backtracking queda $n²!$ nodos el peor caso.

(d) Considere la siguiente poda al árbol de backtracking: al momento de elegir el valor de una nueva posición, verificar que la suma parcial de la fila no supere el número mágico. Verificar también que la suma parcial de los valores de las columnas no supere el número mágico. Introducir estas podas al algoritmo e implementarlo en la computadora. ¿Puede mejorar estas podas?

>Se puede hacer para las columnas si se supiera el numero magico de forma precalculado.

(e) Demostrar que el número mágico de un cuadrado mágico de orden $n$ es siempre $\frac{(n³ + n)}{2}$.

>d/ Vamos a sumar de distinta forma todos los numeros de $1$ a $n²$.
>1. Sumar todos los numeros de $1$ a $n²$ se puede hacer con la suma de gauss: $sumaTotal = \frac{n²(n²+1)}{2}$.
>2. Como un cuadrado magico de orden $n$ tiene $n$ filas, entonces se puede: $sumaTotal = Nro\_magico * n$
>
>Igualamos ambas formulas y dividimos ambos lados $n$, queda $\frac{n³+n}{2} \square$ 
>
>>[Codigo](https://github.com/malei-dc/TDA/blob/main/Guia-Ejercicios/Practica1/codes/P1Ej2-MagiCuadrados.cpp)

### 3) MaxiSubconjunto
Dada una matriz simétrica $M$ de $n \times n$ números naturales y un número $k$, queremos encontrar un subconjunto $I$ de $\{1, . . . , n\}$ con $|I| = k$ que maximice $\sum_{i,j \in I} M_{ij}$.

(a) Diseñar un algoritmo de backtracking para resolver el problema, indicando claramente cómo se codifica una solución candidata, cuáles soluciones son válidas y qué valor tienen, qué es una solución parcial y cómo se extiende cada solución parcial.

>Si tenemos orden $4$, $k = 3:$ 
>- Las soluciones candidatas son: $(1, 1, 1, 0), (1, 1, 0, 1), (1, 0, 1, 1), (0, 1, 1, 1)$ cada elem representa si el indice de su posicion esta o no esta.
>- Las solucion/es validas son el conjunto de indices que maximice evaluando a la matriz
>- Las soluciones parciales son los conjuntos de indices que tienen menos que $k$ elementos y aun hay para agregar
>
>[Codigo](https://github.com/malei-dc/TDA/blob/main/Guia-Ejercicios/Practica1/codes/P1Ej3-MaxiSubconjunto.cpp)

(b) Calcular la complejidad temporal y espacial del mismo.

>- Complejidad temporal: cada indice puede estar o no estar $O(2^k)$ y cuando llego a una hoja calculo la sumatoria en $O(n²)$ un total del $\binom{n}{k}$ veces. Luego en total queda: $O(2^k * \binom{n}{k} * n²)$ //esto no se si esta bien
>
>Complejidad espacial: uso solo un vector de booleanos de tamaño $k$, y una matriz de tamaño $n*n$. Queda $O(k + n²)$

(c) Proponer una poda por optimalidad y mostrar que es correcta.

>Poda de Optimalidad: si agregando todos los indices restantes no llego a $k$, detengo esa rama. Eso quiere decir que siguiendo por esa rama no se llega a tener un conjunto de indices de tamaño $k$. 
>        
>(edit+) Esta poda es correcta porque se basa en una cota superior del valor que podría alcanzar una solución parcial. Si esta cota no es mejor que la mejor solución encontrada hasta el momento, entonces sabemos que no necesitamos seguir explorando esa rama del espacio de soluciones.

### 4) RutaMinima
Dada una matriz $D$ de $n \times n$ números naturales, queremos encontrar una permutación $\pi$ de $\{1, . . . , n\}$ que minimice $D_{\pi (n)\pi (1)}+ \sum_{i=1}^{n-1} D_{\pi (i)\pi (i+1)}$

(a) Diseñar un algoritmo de backtracking para resolver el problema, indicando claramente cómo se codifica una solución candidata, cuáles soluciones son válidas y qué valor tienen, qué es una solución parcial y cómo se extiende cada solución parcial.

>- Una solucion candidata es un vector de tamaño n que contiene indices.
>- La solucion valida es la que minimiza la formula del ejercicio evaluando los indices del vector en la matriz. 
>- Una solucion parcial es cuando aun tengo indices para agregar cuando el tamaño del vector solucion no llega a $n$.
>
>>[Codigo](https://github.com/malei-dc/TDA/blob/main/Guia-Ejercicios/Practica1/codes/P1Ej4-RutaMinima.cpp)

(b) Calcular la complejidad temporal y espacial del mismo.

>- La complejidad temporal es $O(n!)$ en el peor caso ya que exploramos todas las permutaciones posibles de $n$ elem.
>- La complejidad espacial es $O(n)$ ya que almaceno solo una permutacion a la vez.

(c) Proponer una poda por optimalidad y mostrar que es correcta.

>Una poda por optimalidad podría ser descartar cualquier solución parcial cuyo valor ya exceda el valor de la mejor solución encontrada hasta el momento. Esto es correcto porque estamos buscando minimizar el valor, así que cualquier solución parcial que ya sea peor que una solución completa encontrada anteriormente no puede llevar a una solución óptima.

## Programación dinámica

### 5) SumaDinámica
En este ejercicio vamos a resolver el problema de suma de subconjuntos usando la técnica de programación dinámica.

(a) Me convence ;)

(b) Si tenemos {1, 2, 5, 5, 5} los elementos 5+1 se suman minimo 3 veces. 

(c) Considerado ;)

(d) La complejidad con enfoque dinamico tiene complejidad O(n*k) mientras que con backtracking es de O(2^n).
        Si k<<2^n es mejor con dinamica, cuando k>>2^n es mejor con backtraking.

(e) :)

(f) No vimos bottom up aun :)

(g) Demostrar que la función recursiva del inciso a) es correcta.
                      _
                     |  j == 0                                  si i = 0
        ss’C(i,j) = <   ss’C(i-1, j)                            si i!=0 && c[i]>j
                     |_ ss’C(i-1, j) || ss’C(i-1, j-c[i])       si no

        d/ inducción en i que existe algún subconjunto de {c1 , . . . , ci } que suma j si y solo si ss’C (i, j) = V
            
            caso base: i = 0 ss’C(i, j) = j==0 es true si y solo si j==0 cumple.
            paso inductivo: supongamos que la función ss’C es correcta para i desde 0 hasta k-1, qvq es correcta para i = k.
                -Si HI es ciertam tenemos que para cualquier j y 0<=i<=k-1, ss’C(i, j) es V si existe un subconjunto {c_1, ..., c_n}
                que sume j.
                - suponemos 2 casos para ss’C(k, j):
                    1) si c[k]>j: debe ser F ya que ningún subconjunto que la suma se igual a j, agregando el elemento k puede sumar j
                    2) si c[k]<=j: segun la definicion de la función ss’C(k,j) = ss’C(k-1, j) || ss’C(k-1, j-c[k])

                    Por HI sabemos que ss’C(k-1, j) es V sii hay un subconjunto que sume j y que ss’C(k-1, j-c[k]) es V si existe un 
                    subconjunto que sume j-c[k].

                    Si ss’C(k,j) es V uno de los dos casos de arriba es V, si tomamos ambos subconjuntos alguno suma j.
                    Si ss’C(k,j) es F entonces no hay un subconjunto que sume j.

### 6) OptiPago

    (a)función recursiva cc(B, c) para resolver el problema, donde cc(B, c) = (c′ , q) cuando el mínimo costo mayor o igual a c 
    que es posible pagar con los billetes de B es c′ y la cantidad de billetes mínima es q
                 _
                |   <|c|,0>           si c<0                           //devuelvo el exceso
    cc(B, c)=  <    <inf, inf>        si vacio?(B) & c>0               //cuando me quedo sin billetes
                |_  min[(1), (2)]     si no

                (1) En esta llamada recursiva uso un billete y sumo la cantidad de billetes usados. Como es una tupla de costo y cantidad 
                de billetes usados, necesito actualizar ambas partes de la tupla.

                    <(cc(B-dameUno(B), c-dameUno(B)))_0, (cc(B-dameUno(B), c-dameUno(B)))_1 +1 >
                        1° parte de la tupla (_0)               2° parte de la tupla (_1)

                (2) En esta parte de billete elijo no usar el billete en cuestion, no hace falta actualizar nada ya que la funcion como tal
                devuelve una tupla.

                    cc(B- dameUno(b), c)
                
                (*) El B-dameUno(B) es de cjto, c-dameUno(B) es resta enteros, min de tuplas (minimiza 1° elem de la tupla -> 2° elem)

    (b) La complejidad es O(2^|B|). -codeado-

    (c) cc’B (i, j) = cc({b1 , . . . , bi }, j) que implemente la idea anterior dejando fijo el parámetro B

                     _
                    |   <|e|,0>           si e < 0                       //devuelvo el exceso
    cc’B(i, e)=    <    <inf, inf>        si i < 0 & e > 0              //cuando me quedo sin billetes y tengo costo que cubrir
                    |_  min[(1), (2)]     si no

                (1) Usar el billete: <cc’B(i - 1, e - B[i])_0, 1 + cc’B(i -1, e - B[i])_1> 
                                        1° parte de la tupla     2° parte de la tupla

                (2) No usar billete: cc’B(i - 1, e)

    Explicado con palabras: la funcion cc’B(i, e) calcula el minimo exceso posible usando los billetes del multiconjunto B, minimizando
        también la cantidad de billetes, el resutado se representa como una tupla <exceso, cantBilletes>

        Parámetros: i representa el i-esimo billete de B y e representa el costo que debe cubrir.

        Casos base: explicado en comentarios

        Caso recursivo: calcula el minimo entre contar el i-esimo billete o no. 
                        (*) Si cuenta el i-esimo billete en la tupla_1 le resto a e el valor del i-esimo billete y a tupla_2 sumo uno la cantidad
                        de billetes, y a ambos le resto el indice para seguir iterando.
                        (*) Si no cuenta el i-esimo billete simplemente le resto un indice.

    cc’B tiene la propiedad de superposición de subproblemas cuando tenemos que calcular valores de billetes repetidos para un mismo estado
    de e, ya que como estamos viendo el caso de usar o no usar tal billete, con los billetes del mismo valor, voy a estar calculando
    lo mismo varias veces. En el peor caso es que sean |B| cantidad de billetes diferentes con un estado e diferente. La cantidad de 
    estados en el peor caso es |B|*e <<< 2^(|B|/2). Conviene dinamica :)

    (d) Estructura de memoización para cc’B: matriz[i][j] con i = |B| y j = costo inicial a cubrir.

    (e) -codeado-

    (f) La llamada para resolver es cc’B(|B|-1, costo) y la complejidad del nuevo algoritmo es O(|B| * costo)

### 7) AstroTrade

    (a) Quiero maximizar ganancia. Empezar y terminar sin asteroides.
        si Astro Void tiene c asteroides al fin del día j, es:
            indefinido (i.e., −∞) si c < 0 o c > j, o
            el máximo entre:
                la m.g.n. de finalizar el día j − 1 con c − 1 asteroides y comprar uno en el día j,
                la m.g.n. de finalizar el día j − 1 con c + 1 asteroides y vender uno en el día j,
                la m.g.n. de finalizar el día j − 1 con c asteroides y no operar el día j.

    (b) Función recursiva:
                          _
                         |                -Inf                                                      si c < 0 || c > j
            mgn(c, j) = <                   0                                                       si j == 0 y c == 0
                         |_ max(mgn(c - 1, j - 1) - P[j], mgn(c + 1, j - 1) + P[j], mgn(c, j-1))    si no

    (c) Llamada para resolver el problema con esa funcion recursiva es: mgn(c, n).

    (d) -codeado-
        Como se puede tener a lo sumo n asteroides (en realidad menos) los estados del problemas son en el peor caso
        n * n y por eso la complejidad temporal es de O(n²).
        Como uso una matriz de n² para la memorizacion, la complejidad espacial es de O(n²)

        La eleccion de la estructura se basa en que nunca puede haber mas asteroides que dias, por eso usamos la cota
        del dia para los asteroides, en realidad vendria a ser n/2 ya que si tiene n/2+1 de asteroides en cualquier momento,
        no se llegaria a vender (es imposible tener (n/2)+1 en los primeros (n/2)-1 dias)

        Otro cambio que hice en el código fue que la la llamada de recursion es de: MGN(0, 0) empezando en dia 0 con 0 asteroides.
        No me salio hacerlo como en la recursion de arriba.

### 8) CortesEconomicos

    (a) Queremos encontrar el mínimo costo posible de cortar una vara de longitud ℓ. Me convence :)

    (b) Función recursiva:
                          _
                         |       0       si |C| = 0
    corteMin(C, i, j) = <   
                         |_     min     (corteMin(C - C[k], i, C[k]), corteMin(C - C[k], C[k], j)) + (j-i)     si no
                   0 <= k < |C| && i <= C[k] < j

    La semántica de esta formulación es que encontramos el mínimo costo de cortar la vara desde i hasta j considerando todos 
    los posibles lugares de corte en el conjunto C. Para cada lugar de corte k, calculamos el costo total como la suma del costo de 
    cortar desde i hasta k y el costo de cortar desde k hasta j, más el costo del corte en k.

    (c) -Codeado funciona mal-
        El algoritmo de programación dinámica basado en esta formulación tendría una complejidad temporal de O(n³), donde n es la longitud de 
        la vara, y una complejidad espacial auxiliar de O(n²). En un enfoque top-down, podríamos usar memoización para evitar recalcular 
        subproblemas. Enfoque Bottom up ...  

    (d) ...

### 9) Travesía vital

    (a) Un algoritmo backtracking seria recorrer todos los posibles caminos y al llegar a la meta checkear si la solucion es menor al menor actual.
        En cada paso recursivo iría hacia abajo o hacia la derecha, si esta al extremo solo tiene una posibilidad, abajo o derecha.
    
    (b) Me convence :)

    (c) Función recursiva para una matriz nxm
                             _
                            |   A[i][j]                             si i = n && j = m 
                            |   minVida(A, i, j + 1) + A[i][j]      si i = n && j < m
        minVida(A, i, j) = <    minVida(A, i + 1, j) + A[i][j]      si j = m && i < n
                            |   min(minVida(A, i, j + 1),           si no
                            |_      minVida(A, i + 1, j)) + A[i][j] 

                       _
                      |     1               si minVida(A, i, j) <= 0
        f(A, i, j) = <
                      |_minVida(A, i, j)    si no

        La semantica de esta formulacion es que encontramos el minimo valor de recorrer todos los caminos desde la posicion (0,0) hasta (n, m) 
        sumando los valores en cada posición que va recorriendo. Luego terminando de calcular eso, observa si el valor es negativo, si lo es, 
        devuelve 1, si no el valor correspondiente al cálculo.
        La solucion se resuelve llamando a f(A, 0, 0) con A la matriz de entrada. 

    (d) -pendiente codigo-
        Top-down: empiezo desde la posicion (0,0) y voy recorriendo recursivamente hasta (n,m) guardando los valores que ya recorrí.
                  Complejidad temporal: O(n*m) ya que solo puedo ir abajo o izq
                  Complejidad espacial: O(n*m) ya que guardo en memoria toda la matriz con el valor que fui recorriendo

        Bottom-up: empiezo en (n,m) subiendo siempre por el minimo entre el valor de arriba o derecha. Si se encuentra en algun extremo solo tiene
                   un valor posible.
                   Complejidad temporal: O(n*m)
                   Complejidad espacial: O(n*m)

    (e) -pendiente-

## Golosos

### 13) ParejasdeBaile
    Tenemos dos conjuntos de personas y para cada persona sabemos su habilidad de baile. Queremos
    armar la máxima cantidad de parejas de baile, sabiendo que para cada pareja debemos elegir
    exactamente una persona de cada conjunto de modo que la diferencia de habilidad sea menor o
    igual a 1 (en módulo). Además, cada persona puede pertenecer a lo sumo a una pareja de baile.
    Por ejemplo, si tenemos un multiconjunto con habilidades {1, 2, 4, 6} y otro con {1, 5, 5, 7, 9}, la
    máxima cantidad de parejas es 3. Si los multiconjuntos de habilidades son {1, 1, 1, 1, 1} y {1, 2, 3},
    la máxima cantidad es 2.

    (a) Considerando que ambos multiconjuntos de habilidades estan ordenados en forma creciente, observar que la solución se puede obtener 
    recorriendo los multiconjuntos en orden para realizar los emparejamientos.
    -yep- :)

    (b) Diseñar un algoritmo goloso basado en a) que recorra una única vez cada multiconjunto. Explicitar la complejidad temporal y espacial 
    auxiliar.

    sort(multi1), sort(multi2)              //ordeno los multiconj
    int long1 = len(multi1)
    int long2 = len(multi2)
    int i, j = 0;
    int res = 0;
    while (i < long1 and j < long2)
        valor1 = multi1[i]
        valor2 = multi2[j]
        if (valor1 < valor2 - 1)
            i ++;
        else if (valor2 < valor1 - 1)
            j ++;
        else
            i ++; 
            j ++;
            res ++;
    return res;

    Complejidades: recorre cada vector exactamente una sola vez, sea n = len(multi1) y m = len(multi2) la complejidad temporal es de O(min(n,m)) 
                    al igual que complejidad espacial ya que no usa estructuras extras más que variables acumuladores.


    (c) Demostrar que el algoritmo dado en b) es correcto.
        - Primero ordenamos los multiconjuntos, esto no afecta el resultado, solo permuta los valores de entrada.
        - Luego iteramos hasta que algún multiconjunto se recorra en su totalidad (no hay potencial pareja si no hay personas).
          En cada iteración tenemos 3 casos, sea i la variable que recorre multi1 y j la variable que recorre multi2:
            *Si el i-esimo valor del multi1 es menor (diferencia más de 1) al j-esimo valor de multi2, tenemos que explorar valores mas grandes de multi1,
            como el arreglo está ordenado, simplemente sigo recorriendo multi1 haciendo i++.
            *Si el j-esimo valor de multi2 es menor (diferencia más de 1) al i-esimo velor de multi1, tenemos que hacer lo mismo para multi2 haciendo j++.
            *Si no, es decir, cuando no tienen una diferencia de más de 1, se puede formar pareja, sumamos 1 al resultado y seguimos recorriendo los vectores.
          El ciclo termina ya se avanza el iterador correspondiente en cada caso de a 1 y en algún momento terminará de recorrer algun vector cuando la guarda
          no se cumpla.

### 14) SumaSelectiva
    Dado un conjunto X con |X| = n y un entero k ≤ n queremos encontrar el máximo valor que pueden sumar los elementos de un subconjunto S de X 
    de tamaño k.

    (a) Proponer un algoritmo greedy que resuelva el problema, demostrando su correctitud.
        1. Ordenar el conjunto X en orden decreciente.
        2. Seleccionar k elementos mas grandes para formar el sulconjunto S

        Correctitud: Sea X={x1,x2,…,xn} el conjunto ordenado no decreciente. 
                     Supongamos que S={xi1,xi2,…,xik} es el subconjunto de tamaño k con la suma máxima.
                     Si S′={xi1,xi2,…,xik−1} es un subconjunto de tamaño k−1, entonces necesariamente xik​ es el mayor elemento de X que no está en S′.
                     Por lo tanto, la suma de S′ será menor que la suma de S.
                     Entonces, seleccionar los k elementos más grandes de X garantiza obtener la suma máxima para un subconjunto de tamaño k.

    Extender el algoritmo para que también devuelva uno de los subconjuntos S que maximiza la suma.
        -Guardo los valores en un vector-

    (b) Dar una implementación del algoritmo del inciso a) con complejidad temporal O(n log n).

    Podemos utilizar la estructura de datos binary heap. Utilizaremos un min-heap para mantener los k elementos más grandes del conjunto X.
    int maxSubsetSum(vector<int>& X, int k) {
        priority_queue<int, vector<int>, greater<int>> min_heap;
        for (int i = 0; i < X.size(); ++i) {
            if (min_heap.size() < k) {
                min_heap.push(X[i]);
            } else if (X[i] > min_heap.top()) {
                min_heap.pop();
                min_heap.push(X[i]);
            }
        }
        int sum = 0;
        while (!min_heap.empty()) {
            sum += min_heap.top();
            min_heap.pop();
        }
        return sum;
    }
    Mantenemos los k elementos más grandes del conjunto X. 
    Primero, llenamos el min-heap con los primeros k elementos de X. Luego, para cada elemento restante en X, si el elemento es mayor que el 
    elemento mínimo del min-heap, lo eliminamos del min-heap y agregamos el nuevo elemento. 
    Finalmente, sumamos los elementos en el min-heap para obtener la suma máxima de un subconjunto de tamaño k.

    Complejidad: la complejidad temporal de esta implementación es O(nlog⁡k), donde n es el tamaño del conjunto X y k es el tamaño del subconjunto 
                    requerido. Como k puede ser menor que n, la complejidad resultante es O(nlogn).

    (c) Dar una implementación del algoritmo del inciso a) con complejidad temporal O(n log k).
    -Te la debo- :(
        
### 15) SumaGolosa
    Queremos encontrar la suma de los elementos de un multiconjunto de números naturales. Cada suma se realiza exactamente entre
    dos números x e y y tiene costo x + y.
    Por ejemplo, si queremos encontrar la suma de {1, 2, 5} tenemos 3 opciones:
        1 + 2 (con costo 3) y luego 3 + 5 (con costo 8), resultando en un costo total de 11;
        1 + 5 (con costo 6) y luego 6 + 2 (con costo 8), resultando en un costo total de 14;
        2 + 5 (con costo 7) y luego 7 + 1 (con costo 8), resultando en un costo total de 15.
    Queremos encontrar la forma de sumar que tenga costo mínimo, por lo que en nuestro ejemplo la mejor forma sería la primera.

    (a) Explicitar una estrategia golosa para resolver el problema.
        La estrategia consiste en ordenar el multiconjunto de forma creciente, e ir sumando desde el principio hasta el final.

    (b) Demostrar que la estrategia propuesta resuelve el problema.
        Al ordenar el multiconjunto de manera no decreciente, siempre tomaremos los dos números más pequeños para sumarlos. 
        Esto garantiza que la suma actual sea la más pequeña posible en comparación con otras posibles sumas con los mismos dos números.
        Al sumar los dos números más pequeños, obtenemos una nueva suma que es la suma de los dos números originales. 
        Este proceso continúa hasta que solo queda un número en el multiconjunto.
        Por lo tanto, la estrategia golosa propuesta resuelve el problema al garantizar que cada suma parcial sea la más pequeña posible en comparación 
        con otras posibles sumas parciales.

    (c) Implementar esta estrategia en un algoritmo iterativo.

        Creamos un min-heap a partir del multiconjunto dado y luego itera hasta que solo quede un elemento en el min-heap. 
        En cada iteración, toma los dos elementos más pequeños del min-heap, los suma, y suma el costo de la operación al costo total. 
        La complejidad temporal de esta implementación es O(nlog⁡n) debido a la construcción inicial del min-heap y a las operaciones de extracción
        e inserción en el min-heap en cada iteración del bucle.

        int minSum(vector<int>& nums) {
            // Crear un min-heap para mantener el multiconjunto ordenado
            priority_queue<int, vector<int>, greater<int>> min_heap(nums.begin(), nums.end());

            int total_cost = 0;
            while (min_heap.size() > 1) {
                // Tomar los dos elementos más pequeños del min-heap
                int x = min_heap.top();
                min_heap.pop();
                int y = min_heap.top();
                min_heap.pop();

                // Sumar los dos elementos y agregar el resultado al costo total
                int sum = x + y;
                total_cost += sum;
            }

            return total_cost;
        }

### 16) RutaEficiente
    Tomás quiere viajar de Buenos Aires a Mar del Plata en su flamante Renault 12. Como está
    preocupado por la autonomía de su vehículo, se tomó el tiempo de anotar las distintas estaciones
    de servicio que se encuentran en el camino. Modeló el mismo como un segmento de 0 a M , donde
    Buenos aires está en el kilómetro 0, Mar del Plata en el M , y las distintas estaciones de servicio
    están ubicadas en los kilómetros 0 = x1 ≤ x2 ≤ . . . xn ≤ M .
    Razonablemente, Tomás quiere minimizar la cantidad de paradas para cargar nafta. Él sabe que
    su auto es capaz de hacer hasta C kilómetros con el tanque lleno, y que al comenzar el viaje este
    está vacío.

    (a) Proponer un algoritmo greedy que indique cuál es la cantidad mínima de paradas para cargar nafta que debe hacer Tomás, y que aparte 
    devuelva el conjunto de estaciones en las que hay que detenerse. Probar su correctitud.

    La idea es agarrar siempre la máxima estación alcanzable en C kilómetros, luego repetir lo mismo desde la estación en la que estamos hasta 
    llegar al final. El algoritmo entonces queda:

    int idx = 0;
    vector<int> estaciones = {E[0]}; // Suponiendo que E es un vector de enteros que contiene las distancias entre estaciones
    for (int i = 1; i < n; ++i) {
        if (E[i] - E[idx] > C) {
            idx = i - 1;
            estaciones.push_back(E[i - 1]);
        }
    }

    -Demo en handout.pdf-

    (b) Dar una implementación de complejidad temporal O(n) del algoritmo del inciso a).
    -Está arriba-
