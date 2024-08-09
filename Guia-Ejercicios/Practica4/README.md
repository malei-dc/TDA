# Práctica 4: Recorridos y Árboles

## Recorridos en profundidad

### 1) Bipartición y ciclos
Sea $T$ un árbol generador de un grafo (conexo) $G$ con raíz $r$, y sean $V$ y $W$ los vértices que están a distancia par e impar de $r$, respectivamente.

(a) Observar que si existe una arista $vw \in E(G) - E(T)$ tal que $v, w \in V$ o $v, w \in W$ , entonces el único ciclo de $T \cup \{vw\}$ tiene longitud impar.
        
>Si $v$, $w$ están en $V$ donde todos los vértices están a distancia par, entonces el ciclo de incluir $vw$ consiste partiendo desde $r$ hacia $v$ (par) y $r$ hacia $w$ (par), más la arista $vw$ que no está en $T$, formando así un ciclo de longitud impar.
>Análogamente si $v$, $w$ estan en $W$ donde todos los vertices están a distancia impar. Entonces impar + impar + 1 es impar.

(b) Observar también que si toda arista de $E(G) - E(T)$ une un vértice de $V$ con otro de $W$, entonces $(V, W)$ es una bipartición de $G$ y, por lo tanto, $G$ es bipartito.

>En un grafo bipartito no hay aristas que conecten vértices dentro del mismo conjunto. En este caso V y W. Como T  es un árbol generador de G, sabemos que T conecta todos los vértices de G sin formar ciclos. Cumple con la definición de bipartito. Al agregar más aristas que no están en T  pero que siguen conectando con vértices de V con W, simplemente se está reforzando la bipartición sin introducir nuevos ciclos pares ni conexión dentro del mismo conjunto.
>Esto nos indica que el grafo es bipartito.
    
(c) A partir de las observaciones anteriores, diseñar un algoritmo lineal para determinar si un grafo conexo $G$ es bipartito. En caso afirmativo, el algoritmo debe retornar una bipartición de $G$. En caso negativo, el algoritmo debe retornar un ciclo impar de $G$. Explicitar cómo es la implementación del algoritmo; no es necesario incluir el código.
        
> 1. Inicialización: 
>       - inicializar conjuntos $V$ y $W$ que representarán los vértices a distancia par e impar de la raíz $r$. 
>       - Un vector de visitados para marcar los vértices que ya se han explorado durante el DFS indicando el nivel en lugar de un booleano.
> 2. DFS modificado: cada vez que visites un vértice, decide si debe ir al conjunto $V$ o al conjunto $W$ basándose en su profundidad (nivel) en el árbol DFS. Si la profundidad es par, el vértice va al conjunto $V$; si es impar, va al conjunto $W$.
> 3. Verificación de ciclo impar: la clave para verificar si el grafo es bipartito está en observar las aristas $E(G) - E(T)$, es decir, las aristas que no son parte del árbol DFS generado. Cada vez que encuentres una arista que conecte dos vértices en el mismo conjunto $V$ o $W$, habrá encontrado un ciclo impar. Si encuentra tal arista, el algoritmo debería terminar y retornar este ciclo impar reconstruyendolo con el vector padre generado por el DFS para ambos vértices.
> 4. Construcción de la Bipartición o Ciclo Impar: Si después de explorar todo el grafo no encuentra ninguna arista que conecte dos vértices dentro del mismo conjunto, entonces confirmamos que el grafo es bipartito, y los conjuntos $V$ y $W$ representan una bipartición válida del grafo. En este caso, el algoritmo debe retornar esta bipartición.
    
(d) Generalizar el algoritmo del inciso anterior a grafos no necesariamente conexos observando que un grafo G es bipartito si y solo si sus componentes conexas son bipartitas.
        
>Generalización a Grafos No Conexos: Para extender el algoritmo a grafos no necesariamente conexos, simplemente ejecuta el DFS modificado desde cada vértice no visitado del grafo. Esto asegura que explorarás cada componente conexa. Si encuentras un ciclo impar en cualquier componente, el grafo no es bipartito. De lo contrario, el grafo es bipartito, y hay una bipartición válida para cada componente.

### 2) PuentesDFS
Una arista de un grafo $G$ es puente si su remoción aumenta la cantidad de componentes conexas de $G$. Sea T un árbol DFS de un grafo conexo $G$.

(a) Demostrar que $vw$ es un puente de $G \Leftrightarrow vw$ no pertenece a ningún ciclo de $G$.

> $\Rightarrow$) $vw$ es un puente de $G$ entonces $vw$ no pertenece a ningún ciclo de $G$.
>
> Mostramos por el absurdo, supongamos que $vw$ es un puente y pertenece a un ciclo, ahora sacamos vw, por definición de puente se tiene que generar más componentes conexas, en particular $v$ y $w$ tienen que pertenecer a distintas componentes conexas. Pero como la arista $vw$ pertenecía a un ciclo, aún existe camino desde $v$ a $w$, ya que la existencia de un ciclo garantiza que la eliminación de una arista no puede aumentar el número de componentes conexas, porque siempre habrá al menos un camino alternativo que mantiene unidos a todos los vértices del ciclo.
>
> Por lo tanto vw no era puente. ABS! 
>
> $\Leftarrow$) $vw$ no pertenece a ningún ciclo de $G$ entonces $vw$ es puente.
>
> Si $vw$ no pertenece a ningún ciclo, significa que es la única vía de conexión directa entre $v$ y $w$. Por lo tanto, su remoción inevitablemente separa el grafo en al menos dos componentes conexas, ya que no hay ruta alternativa que mantenga unidos a $v$ y $w$, cumpliendo con la definición de puente. La inexistencia de un ciclo implica directamente que la arista es crítica para la conectividad entre $v$ y $w$, y su remoción efectivamente particiona el grafo.
        
(b) Demostrar que si $vw \in E(G) - E(T)$, entonces $v$ es un ancestro de $w$ en $T$ o viceversa.

>Sé que $vw$ pertenece a $G$ pero no a $T$ que es un árbol DFS, por propiedad de la construcción del árbol DFS sabemos que es una backedge, de lo contrario estaría en $T$. Luego $v$ es ancestro de $w$ o viceversa. En un árbol DFS, una backedge siempre conecta un vértice con otro vértice que es su ancestro dentro del árbol, porque el recorrido en profundidad garantiza que antes de explorar un nuevo vértice, se explora completamente cada uno de los vértices descubiertos (incluyendo todos sus descendientes en el árbol). Por lo tanto, cuando encuentras una backedge, esta necesariamente conecta un vértice con otro que ya había sido explorado, y dado el recorrido en profundidad, el vértice previamente explorado tiene que ser un ancestro del más recientemente descubierto.
    
(c) Sea $vw \in E(G)$ una arista tal que el nivel de $v$ en $T$ es menor o igual al nivel de $w$ en $T$. Demostrar que $vw$ es puente $\Leftrightarrow$ $v$ es el padre de $w$ en $T$ y ninguna arista de $G - \{vw\}$ une a un descendiente de $w$ (o a $w$) con un ancestro de $v$ (o con $v$).

>- Esto es basicamente la definición de covertura: Decimos que una backward edge $b$ cubre a una tree edge $(u, v)$ de un árbol DFS $T$ con $u$ padre de $v$ si $b$ conecta un descendiente de $u$ con un ancestro de $v$ en $T$.
>- Entonces traduciendo el ejercicio con la definición de covertura queda:
Una tree edge de un árbol DFS $T$ de un grafo conexo $G$ es un puente $\Leftrightarrow$ no hay ninguna backward edge que la cubra.
>
>(La demo está en el pdf de [puentes](https://github.com/malei-dc/TDA/blob/main/Practicas/07-01puentes.pdf) Lema 3).

(d) Dar un algoritmo lineal basado en DFS para encontrar todas las aristas puente de G.

>(En el pdf de [puentes](https://github.com/malei-dc/TDA/blob/main/Practicas/07-01puentes.pdf))

## Recorridos en anchura

### 5) GeoBFS
Un árbol generador $T$ de un grafo $G$ es $v$-geodésico si la distancia entre $v$ y $w$ en $T$ es igual a la distancia entre $v$ y $w$ en $G$ para todo $w \in V(G)$. Demostrar que todo árbol BFS de $G$ enraizado en $v$ es $v$-geodésico. Dar un contraejemplo para la vuelta, i.e., mostrar un árbol generador $v$-geodésico de un grafo G que no pueda ser obtenido cuando BFS se ejecuta en $G$ desde $v$.

>**Veamos como funciona BFS**: inicia desde un vértice $v$ y explora todos sus vecinos a distancia 1, luego todos los vecinos de estos a distancia 2, y así sucesivamente. Esto significa que cuando un vértice $w$ es visitado y agregado al árbol BFS, la ruta desde $v$ hasta $w$ es la más corta posible en $G$, ya que de haber una más corta, $w$ habría sido visitado antes.
>
>**Su relación con $v$-geodésico**: dado que BFS explora gradualmente los vértices de $G$ en orden de distancia creciente desde $v$, cuando un vértice $w$ se agrega a $T$, la ruta de $v$ a $w$ en $T$ es igual a la distancia más corta de $v$ a $w$ en $G$. Por lo tanto, el árbol BFS enraizado en $v$ es $v$-geodésico, ya que conserva la distancia mínima entre $v$ y todos los demás vértices en $G$.
>
>**Contraejemplo para la vuelta**: la propiedad de ser $v$-geodésico no es exclusiva de los árboles BFS; otros métodos podrían generar un árbol generador $v$-geodésico que no siga el orden específico de un BFS. Considera un grafo $G$ que es un cuadrado con vértices $A, B, C, D$ y aristas $AB, BC, CD$, y $AD$, y una diagonal $AC$. Si elige $A$ como el vértice raíz para un BFS, el árbol resultante podría ser $A-B-C-D$ (asumiendo que el orden de visita es de izquierda a derecha), que es $A$-geodésico. Sin embargo, otro árbol generador $A$-geodésico podría ser simplemente tomar las aristas $AB, AC$ y $AD$, el cual no es obtenible por un BFS desde $A$, ya que BFS siempre producirá un árbol sin la arista $AC$ debido a su naturaleza de exploración en anchura.

### 8) GrillaMágica
Se tiene una grilla con $m \times n$ posiciones, cada una de las cuales tiene un número entero en $[0, k)$, para un $k \in N$ dado. Dado un valor objetivo $w \in N$ y una posición inicial $(x_1 , y_1)$, que tiene un valor inicial $v_1$, queremos determinar la mínima cantidad de movimientos horizontales y verticales que transformen $v_1$ en $w$, teniendo en cuenta que el $i$-ésimo movimiento transforma a $v_i$ por $v_{i+1} = (v_i + z)$ mód $k$, donde $z$ es el valor que se encuentra en la casilla de destino del movimiento. 

Modelar este problema como un problema de grafos que se resuelva usando BFS en $O(kmn)$ tiempo.

>Consideramos cada posición de la grilla como un nodo y para cada nodo consideramos movimiento posible horizontal y vertical. Si el movimiento es válido, siendo $z$ el valor del destino establecemos arista.
>
>Corremos BFS:
>- Nodo inicial $(x_1, y_1)$ con valor $v_1$, cola visitados
>- Mientras cola no vacía: extraer nodo de cola, ver si valor es $w$, si es, encontramos y terminamos. Si no, encolamos los vecinos no visitados y actualizamos valor con la fórmula.
>- Si terminamos BFS sin encontrar $w$, no es posible obtenerlo partiendo de $v_1$.
>
>Obtención de cantidad mínima de movimientos: al obtener $w$ podemos rastrear el nodo objetivo hacia el nodo inicial con un vector de padres. 
>
>La complejidad es $O(kmn)$ ya que en el peor de los caos la ejecución recorre $nm$ nodos y obtención de cant de movimientos también es $O(nm)$.

## Árbol generador mínimo, camino minimax y maximin

### 10) SecuenciasConectadas
Se define la distancia entre dos secuencias de naturales $X = \{x_1 , ..., x_k\}$ e $Y = \{y_1 , ..., y_k\}$ como $d(X, Y) = \sum_{i = 1}^{k} |x_i − y_i|$. Dado un conjunto de secuencias $X_1 , ..., X_n$ , cada una de tamaño $k$, su grafo asociado $G$ tiene un vértice $v_i$ por cada $1 \leq i \leq n$ y una arista $v_i v_j$ de peso $d(X_i , X_j)$ para cada $1 \leq i < j \leq n$. Proponer un algoritmo de complejidad $O(kn²)$ que dado un conjunto de secuencias encuentre el árbol generador mínimo de su grafo asociado.

>Modelamos las secuencias $X_1 , ..., X_n$ como nodos, y para calcular la distancia entre nodos hacemos la sumatoria para el peso de las aristas. Enlazamos todos con todos lo que nos cuesta $O(kn²)$ y luego corremos prim o kruskal que es $O(n²)$. Nos queda complejidad $O(kn²)$.

### 11) AnchoBandMax
Una empresa de comunicaciones modela su red usando un grafo $G$ donde cada arista tiene una capacidad positiva que representa su ancho de banda. El ancho de banda de la red es el máximo $k$ tal que $G_k$ es conexo, donde $G_k$ es el subgrafo generador de $G$ que se obtiene de eliminar las aristas de peso menor a $k$.

(a) Proponer un algoritmo eficiente para determinar el ancho de banda de una red dada.

>1. Ordenar todas las aristas de acuerdo a su peso de forma descendente. Esto dará una lista de posibles valores de $k$. 
>2. Búsqueda binaria sobre la lista de pesos de aristas. Para cada peso $k$ seleccionado por la búsqueda binaria, eliminas todas las aristas de peso menor a $k$ de $G$ y luego verifica si el grafo resultante $G_k$ es conexo con DFS. 
>3. Si $G_k$ es conexo, entonces se puede intentar con un valor de $k$ más alto (hacia la derecha en la lista ordenada). Si $G_k$ no es conexo, hay que probar con un valor más bajo (hacia la izquierda en la lista ordenada). 
>4. El proceso termina cuando la búsqueda binaria no puede encontrar un valor de $k$ más alto que mantenga $G_k$ conexo. El último valor de $k$ encontrado es el ancho de banda de la red.

La empresa está dispuesta a hacer una inversión que consiste en actualizar algunos enlaces (aristas) a un ancho de banda que, para la tecnología existente, es virtualmente infinito. Antes de decidir la inversión, quieren determinar cuál es el ancho de banda que se podría obtener si se reemplazan $i$ aristas para todo $0 \leq i < n$.

(b) Proponer un algoritmo que dado $G$ determine el vector $(a_0 , ..., a_{n−1})$ tal que $a_i$ es el ancho de banda máximo que se puede obtener si se reemplazan $i$ aristas de $G$.

>Reemplazar $i$ aristas por otras con "ancho de banda infinito", estamos, de hecho, asegurando que ciertos caminos dentro del grafo permanecerán siempre conectados, sin importar el valor de $k$ que elijamos para el subgrafo $G_k$. Esto podría mejorar significativamente el ancho de banda de la red al permitir que más nodos permanezcan conectados incluso cuando se eliminan aristas de menor capacidad.
>
>1. **Ordenar las aristas por capacidad**: Primero, necesitamos ordenar todas las aristas del grafo $G$ por su capacidad, de menor a mayor. Esto nos permitirá entender cuáles son los "cuellos de botella" en la red actual.
>2. **Uso de Algoritmos de Conectividad**: Para cada valor de $i$ (desde 0 hasta $n-1$), vamos a simular el reemplazo de las $i$ aristas de menor capacidad por aristas de capacidad infinita. Aquí, podemos usar un algoritmo de conectividad, como el algoritmo de Kruskal o Prim (adaptados para considerar estas nuevas aristas infinitas), para entender cómo cambia la conectividad del grafo.
>3. **Evaluación de Conectividad**: Para cada versión modificada del grafo, evaluamos la conectividad del mismo, determinando el "nuevo" ancho de banda, es decir, el máximo $k$ tal que el grafo modificado sigue siendo conexo.
>4. **Construcción del Vector $a$**: Finalmente, para cada $i$, el valor de $k$ encontrado que mantiene la conectividad del grafo modificado se almacena en el vector $a$, en la posición correspondiente a $a_i$.

### 13) PrioriKruskal
El algoritmo de Kruskal (resp. Prim) con orden de selección es una variante del algoritmo de Kruskal (resp. Prim) donde a cada arista $e$ se le asigna una prioridad $q(e)$ además de su peso $p(e)$. Luego, si en alguna iteración del algoritmo de Kruskal (resp. Prim) hay más de una arista posible para ser agregada, entre esas opciones se elige alguna de mínima prioridad.

(a) Demostrar que para todo árbol generador mínimo $T$ de $G$, si las prioridades de asignación están definidas por la función

![](https://github.com/malei-dc/TDA/blob/main/Guia-Ejercicios/Practica4/imgs/ej13.png)

entonces se obtiene $T$ como resultado del algoritmo de Kruskal (resp. Prim) con orden de selección ejecutado sobre $G$ (resp. cualquiera sea el vértice inicial en el caso de Prim).

>Kruskal o Prim conecta todos los vértices con el menor peso total posible sin formar ciclos.
>Bajo esta función $q_T$, cualquier arista que pertenezca a $T$ tiene prioridad 0 (la más alta), asegurando que, si es posible, será seleccionada antes que las aristas no pertenecientes a $T$.
>Debido a esta asignación de prioridades, en cada paso del algoritmo, cuando se enfrentan a una decisión entre múltiples aristas con el mismo peso, las aristas que forman parte de $T$ siempre serán elegidas primero (si están disponibles), ya que tienen la prioridad más alta. Esto garantiza que el algoritmo "sigue" el árbol $T$ siempre que sea posible. Debido a esta estrategia de selección basada en la prioridad $q_T(e)$, el algoritmo de Kruskal (o Prim, dependiendo del vértice inicial) construirá el árbol $T$ paso a paso, seleccionando siempre aristas que pertenezcan a $T$ sobre las que no, asegurando así que el resultado final sea el árbol generador mínimo $T$.

(b) Usando el inciso anterior, demostrar que si los pesos de $G$ son todos distintos, entonces $G$ tiene un único árbol generador mínimo.

>Si todos los pesos son distintos, no puede haber dos aristas con el mismo peso compitiendo para ser agregadas en el mismo paso, lo que elimina la necesidad de desempate por prioridad y, por ende, garantiza que el árbol generador mínimo generado sea único, ya que no hay ambigüedad en la selección de aristas en ningún paso.
