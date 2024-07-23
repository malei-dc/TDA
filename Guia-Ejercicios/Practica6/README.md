# Práctica 6: Flujo en redes

## Propiedades de los flujos en redes

## 1) Demos
Para cada una de las siguientes sentencias sobre el problema de flujo máximo en una red $N$: demostrar que es verdadera o dar un contraejemplo.

(a) Si la capacidad de cada arista de $N$ es par, entonces el valor del flujo máximo es par.

>Verdadero.
>Usamos el teorema que dice que flujo max = corte min.
>Un corte min es la suma de todas las capacidades de las aristas que cruzan el corte y tiene que ser igual al flujo max, siendo todos los pesos pares, la suma también es par ENTONCES flujo max es par.

(b) Si la capacidad de cada arista de $N$ es par, entonces existe un flujo máximo en el cual el flujo sobre cada arista de $N$ es par.

>Verdadero.
>Lo demostramos por inducción en las iteraciones de ford-fulkerson. Miramos cuello botella en cada iteración:
>
>Caso base: inicialmente el flujo en la red es 0 y por lo tanto todas tienen sus capacidades disponibles que es par y su flujo es 0.
>
>Paso inductivo: el flujo en cada arista es par.
>Si existe camino de aumento, el cuello botella será par.
>Al actualizar las capacidades de las aristas del camino de aumento, éstas son pares pues restamos flujo par a capacidad par. La clave aquí radica en el hecho de que, dado que todas las capacidades son pares, y está incrementando el flujo a través de un camino de aumento según la capacidad más pequeña restante (el cuello de botella), este incremento será par, ya que sería el mínimo de un conjunto de números pares (las capacidades restantes en el camino), y por lo tanto, también par.
>
>Este argumento se basa en el algoritmo de Ford-Fulkerson y cómo el proceso de búsqueda de caminos de aumento y actualización de flujos garantiza que, si empezamos con capacidades pares, cualquier flujo máximo encontrado respetará la condición de que cada flujo sobre cada arista sea par.

(c) Si la capacidad de cada arista de N es impar, entonces el valor del flujo máximo es impar.

>Falso.

![](https://github.com/malei-dc/TDA/blob/main/Guia-Ejercicios/Practica6/Imgs/ej1c.png)

(d) Si la capacidad de cada arista de $N$ es impar, entonces existe un flujo máximo en el cual el flujo sobre cada arista de $N$ es impar.

>Falso.

![](https://github.com/malei-dc/TDA/blob/main/Guia-Ejercicios/Practica6/Imgs/ej1d.png)

>Lo importante es notar que la estructura de la red y la distribución del flujo pueden crear situaciones donde, incluso si todas las capacidades son impares, no necesariamente se requiere que cada flujo en el camino máximo sea impar para alcanzar el flujo máximo.
>
>Las propiedades del flujo máximo dependen de la estructura de la red y cómo las capacidades permiten diferentes configuraciones de flujo, más allá de las individualidades de cada arista.

(e) Si todas las aristas de $N$ tienen capacidades racionales, entonces el flujo máximo es racional.

>Verdadero.
>Todas las capacidades de las aristas son racionales por hipótesis.
>Las operaciones realizadas para calcular el flujo (sumas y restas) no alteran la naturaleza racional de los números involucrados.
>Cualquier valor de flujo calculado, incluido el flujo máximo, conserva la propiedad de ser un número racional.

## 2) Ford-Fulkerson
Para todo $F  \in N$, construir una red con 4 vértices y 5 aristas en la que el método de *Ford y Fulkerson* necesite $F$ iteraciones en peor caso para obtener el flujo de valor máximo (partiendo de un flujo inicial con valor 0).

![](https://github.com/malei-dc/TDA/blob/main/Guia-Ejercicios/Practica6/Imgs/ej2.png)

## 3) Edmonds y Karp
Determinar la complejidad del algoritmo de Edmonds y Karp para encontrar el flujo máximo de una red $N$ cuando:

(a) No hay información acerca de las capacidades de las aristas de $N$.

>$O(m * min (F, nm))$
    
(b) todas las aristas de $N$ tienen capacidad a lo sumo $q \ll n$.

>$O(nm²)$

(c) el flujo máximo de $N$ tiene un valor $F \ll mn$.

>$O(mF)$

## 4) Corte capacidad min
Proponer un algoritmo lineal que dada una red $N$ y un flujo de valor máximo, encuentre un corte de capacidad mínima de $N$.

>- Sabiendo el flujo sobre cada arista, podemos reconstruir el grafo residual en $O(m + n)$, ya que necesito revisar cada arista para determinar su capacidad residual.
>- Corremos BFS desde s en el grafo residual $O(n + m)$.
>- Todos los vértices que son alcanzables desde s están en el corte mínimo. Las aristas que salen del corte mínimo son las que cortan y la suma de sus capacidades es igual al flujo max.