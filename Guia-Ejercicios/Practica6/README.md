# Práctica 6: Flujo en redes

## Propiedades de los flujos en redes

### 1) Demos - propiedades
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

### 2) Ford-Fulkerson
Para todo $F \in N$, construir una red con 4 vértices y 5 aristas en la que el método de *Ford y Fulkerson* necesite $F$ iteraciones en peor caso para obtener el flujo de valor máximo (partiendo de un flujo inicial con valor 0).

![](https://github.com/malei-dc/TDA/blob/main/Guia-Ejercicios/Practica6/Imgs/ej2.png)

### 3) Edmonds y Karp
Determinar la complejidad del algoritmo de Edmonds y Karp para encontrar el flujo máximo de una red $N$ cuando:

(a) No hay información acerca de las capacidades de las aristas de $N$.

>$O(m * min (F, nm))$
    
(b) todas las aristas de $N$ tienen capacidad a lo sumo $q \ll n$.

>$O(nm²)$

(c) el flujo máximo de $N$ tiene un valor $F \ll mn$.

>$O(mF)$

### 4) Corte capacidad min
Proponer un algoritmo lineal que dada una red $N$ y un flujo de valor máximo, encuentre un corte de capacidad mínima de $N$.

>- Sabiendo el flujo sobre cada arista, podemos reconstruir el grafo residual en $O(m + n)$, ya que necesito revisar cada arista para determinar su capacidad residual.
>- Corremos BFS desde s en el grafo residual $O(n + m)$.
>- Todos los vértices que son alcanzables desde s están en el corte mínimo. Las aristas que salen del corte mínimo son las que cortan y la suma de sus capacidades es igual al flujo max.

## Problemas de modelado I: caminos disjuntos en un grafo

### 5) FlujosDisjuntos
Sea $G$ un digrafo con dos vértices $s$ y $t$.

(a) Proponer un modelo de flujo para determinar la máxima cantidad de caminos disjuntos en aristas que van de $s$ a $t$.

>Tenemos digrafo $G = (V, E)$ para nuestra red $N = (E_n = E, V_n = V)$

(b) Dar una interpretación a cada unidad de flujo y cada restricción de capacidad.

>En este problema cada unidad de flujo representa un camino, como queremos pasar solo una vez por cada arista, la capacidad es 1. Entonces el flujo $F$ serían los caminos disjuntos que van desde $s$ a $t$.

(c) Demostrar que el modelo es correcto.

> Queremos ver que existe un flujo válido de valor $F$ $\Longleftrightarrow$ existen $F$ caminos disjuntos en aristas de $G$
>
>$\Leftarrow$) Sean $c_1, ..., c_F$ los caminos disjuntos en aristas de $G$. Definimos una función de flujo:

![](https://github.com/malei-dc/TDA/blob/main/Guia-Ejercicios/Practica6/Imgs/ej5FuncionDemo.png)

>Ahora quiero ver que la función $f$ es válido (que cumpla la restricción de capacidad y la conservación de flujo) y que $\sum_{w \in N⁺(s)} f(w)$ = $F$.
>
>- Restricción de capacidad: $f(e) \leq c(e)$ $\forall e \in E(G)$. Se cumple pues $f_e \leq 1$ = $c_e$
>- Restricción de conservación de flujo: para cualquier vértice $v \neq s, t$, el flujo entrante es igual al flujo saliente. Esto se debe a que cada camino que entra a $v$ debe salir de $v$ para continuar hacia $t$, garantizando así la conservación del flujo. Dado que estamos considerando caminos disjuntos en aristas, ningún vértice intermedio $v$ puede recibir más flujo del que envía, excepto $s$ y $t$, precisamente porque cada camino $c_i$ es disjunto en aristas y, por lo tanto, atraviesa cada vértice a lo sumo una vez (exceptuando $s$ y $t$).
>- $\sum_{w \in N⁺(s)} f(w)$ = $F$. Se cumple pues $s$ pertenece a todos los caminos mínimos disjuntos.
>
>$\Rightarrow$) Vamos a ir construyendo caminos disjuntos a partir de flujo $F$. Demostración inductiva:
>$f$ es un flujo de valor $F$, sé que estan conectados $s$ con $t$ por aristas $e$ con $f(e) = 1$ en un camino $P$. Si saco el camino $P$, como $f(e) = 1$ entonces el valor del flujo $f'=f - P=F-1$, $f'$ sigue válido. Luego si repito con otro $P'$, como $c(e) = 1$ para todas las aristas, no compartía camino con $P$, así que repito esto $F$ veces para obtener $F$ caminos disjuntos de $G$.

(d) Determinar la complejidad de resolver el modelo resultante con el algoritmo de Edmonds y Karp.

>$O(VE^2)$, donde $V$ es el número de vértices y $E$ es el número de aristas en el digrafo. La razón de esta complejidad radica en cómo el algoritmo encuentra el camino de aumento más corto en cada iteración usando BFS (Búsqueda en Anchura) y cómo actualiza los flujos a través de la red.

## Problemas de modelado II: asignación

### 6) FiestaSolteres
Las fiestas de casamiento son muy peculiares y extrañamente frecuentes. Cada persona invitada asiste siempre con todes sus familiares solteres, a quienes se les reservan mesas especiales de solteres. Además, hay una regla no escrita que establece un límite $c_{ij}$ a la cantidad de solteres de la familia $i$ que pueden sentarse en la mesa $j$. Asignasonia requiere un algoritmo que resuelva el problema de asignación de les solteres a sus mesas.

(a) Proponer un modelo de flujo que dados los conjuntos 

$$F =\{f_1, ..., f_{|F|}\}, M = \{m_1, ..., m_{|M|}\}, C = \{c_{ij} / 1 \leq i \leq |F|, 1 \leq j \leq |M|\}$$ 

determine una asignación que respete las tradiciones sabiendo que:

- la familia i esta formada por fi personas solteres,
- la mesa j tiene mj lugares disponibles para solteres, y
- en la mesa j solo pueden sentarse cij solteres de la familia i.

![](https://github.com/malei-dc/TDA/blob/main/Guia-Ejercicios/Practica6/Imgs/ej6.png)

(b) Dar una interpretación a cada unidad de flujo y cada restricción de capacidad.

>Cada unidad de flujo representa una asignación de algún familiar a una mesa.
>- Las aristas que salen de $s$ con capacidad $f_i$ restringe que solo asisten $f_i$ familiares solteras de la familia $i$ garantizando con esto no asignar de más a ninguna mesa.
>- Las aristas con capacidad $c_{ij}$ limitan los solteros de cada familia en la misma mesa $m_j$.
>- Las aristas $m_j$ restringen la capacidad max de cada mesa.
>
>Por conservación de flujo $\sum_{j = i}^{|m|} c_{ij}$ = $f_i$, solo asignamos $f_i$ solteros a mesas.  

(c) Determinar la complejidad de resolver el modelo resultante con el algoritmo de Edmonds y Karp.

>Complejidad EK: $O(nm²) = O((F+M)(FM)²)$
>
>$m = |F| + |F||M|+|M| \Rightarrow m = O(FM)$
>
>$n = |F| + |M| = O(F+M)$ 