# Práctica 3: Introducción a la teoría algorítmica de grafos

## Demostración de propiedades simples sobre grafos

### 1) Equilibrio Digrafo
Demostrar, usando inducción en la cantidad de aristas, que todo digrafo $D$ satisface: 

$$ \sum_{v \in V(D)}d_{in}(v) = \sum_{v \in V(D)} d_{out}(v) = |E(D)| $$

>d/ Hacemos inducción en la cantidad de aristas $|E(D)|$ 
>
>Caso base: si $|E(D)| = 0$ nuestro digrafo no tiene aristas, todos los nodos tiene grado de entrada/salida 0. *Vale*.
>
>Caso recursivo: qvq $P(|E(D)|) \Rightarrow P(|E(D)| + 1)$. 
>- La HI es que vale $\sum_{v \in V(D)} d_{in}(v) = \sum_{v \in V(D)} d_{out}(v) = |E(D)|$. 
>- Llamemos $(s,t)$ a la nueva arista y sin perdida de generalidad nombremos a $s$ como su nodo de salida y a $t$ como su nodo de entrada. Y tenemos $D'$ al nuevo grafo, es decir $D' = (V(D), E(D) + (s,t))$.
> Por renombre, probar que vale $P(|E(D)| + 1)$ es lo mismo que: $\sum_{v \in V(D')} d_{in}(v) = \sum_{v \in V(D')} d_{out}(v) = |E(D')|$
>   - $|E(D')| = |E(D) \cup (s,t)| = |E(D)| + 1$
>   - $\sum_{v \in V(D')} d_{in}(v) = d_{in}(t_{D'}) + \sum_{v \in V(D'-t_{D'})}d_{in}(v) = 1 + [d_{in}(t_D) + \sum_{v \in V(D-t_{D})}d_{in}(v)] = 1 + \sum_{v \in V(D)} d_{in}(v) $
>   - $\sum_{v \in V(D')} d_{out}(v) = d_{out}(t_{D'}) + \sum_{v \in V(D'-t_{D'})}d_{out}(v) = 1 + [d_{out}(t_D) + \sum_{v \in V(D-t_{D})}d_{out}(v)] = 1 + \sum_{v \in V(D)} d_{out}(v) $
>- Por HI sabemos que $\sum_{v \in V(D)} d_{in}(v) = \sum_{v \in V(D)} d_{out} = |E(D)|$
>- Sumamos 1 en cada lado: $\sum_{v \in V(D)} d_{in}(v) + 1 = \sum_{v \in V(D)} d_{out} +1 = |E(D)|$
>- Reemplazamos y nos queda que: $\sum_{v \in V(D')} d_{in}(v) = \sum_{v \in V(D')} d_{out} = |E(D')|$
>- Luego vale $P(|E| + 1)$.
> $\square$

### 2) Doble Grado
Demostrar, usando la técnica de reducción al absurdo, que todo grafo no trivial tiene al menos dos vértices del mismo grado. 

>d/ Suponemos que en todo grafo no trivial no hay 2 vértices del mismo grado. Ordenamos el grado de todos los nodos, sean $V = \{v_0, v_1, ..., v_n\}$ con $d(v_0) = 0, d(v_1) = 1, d(v_2) = 2, ..., d(v_n) = n$ ya que no existe 2 vértices con el mismo grado, tenemos que $v_0$ no tiene aristas y como no es un multigrafo, se contradice con $v_n$ que tiene $n$ atistas, lo que significa que conecta con todos los vértices, *ABS*!

### 3) Unicidad Digrafo
Un grafo orientado se obtiene a partir de un grafo no orientado dando una dirección a cada arista.
Demostrar en forma constructiva que para cada n existe un único grafo orientado cuyos vértices tienen todos grados de salida distintos.

>d/ Notamos que el absurdo en el ej2 no se produce para un grafo orientado ya que a pesar de tener grado de entrada un nodo puede no tener grado de salida. Entonces contruimos $n$ grafos según la cantidad de vértices. Observamos que para:
>
>Vértice = 1: tiene grado de salida 0 ya que no hay vértice con quien unir la arista, sad :(
>  
>Vértices = 2: en este caso hay un vértice extra en comparación al grafo anterior. Tenemos dos opciones válidas que se repite (uno) hasta $n$:
>- (a) Agregamos un vértice con grado de salida 0 y hacemos que desde los vértices restantes se agreguen una arista que apunte al nuevo.
>- (b) Dejamos los vertices restantes con el mismo grado de salida y desde el nuevo vértice le sacamos 1 arista apuntando a todos los vértices restantes.
>- . . . 
>- Vértices = $n$: si fuimos por la opción (a), agregamos un vértice de grado de salida 0 y de todos los vértices restantes agregamos una arista que apunte hacia el nuevo nodo. Como la temporalidad del agregado de nodos es diferente en cada nodo (voy agregando 1 arista a todos c/vez que ingreso un vértice), el vértice "mas antiguo" tendrá $n - 1$ grado de salida, el vértice "mas antiguo + 1" tendrá $n - 2$ grado de salida, y así cada uno tiene un grado de salida diferente.
>
>si fuimos por la opción (b), agregamos un vértice con grado $n - 1$ apuntando al resto de los vértices. De esta forma el grado de salida de cada vértice es diferente por la razón explicado en (a).
>
>Siguiendo esta construcción queda demostrado que para cada $n$ existe un único grafo orientado cuyos vértices tienen todos grados de salida distintos.

### 4) ArteConexo
Un vértice $v$ de un grafo $G$ es un punto de articulación si $G − v$ tiene más componentes conexas que $G$. Por otro lado, un grafo es biconexo si es conexo y no tiene puntos de articulación.

(a) Demostrar, usando inducción en la cantidad de vértices, que todo grafo de $n$ vértices que tiene más de $\frac{(n − 1)(n − 2)}{2}$ aristas es conexo.

>Sea el grafo $G = (V, E)$, tenemos $|V| = n$ cantidad de vértices y $|E| = m$ cantidad de aristas. Usamos inducción en la cantidad de vértices.
>
>Casos bases:
>- $n = 1$ que tiene más de $\frac{(1 − 1)(1 − 2)}{2}$ = 0 aristas es conexo. Se cumple ya que tengo solo 1 vértice.
>- $n = 2$ que tiene más de $\frac{(2 − 1)(2 − 2)}{2}$ = 0 aristas es conexo. Se cumple ya que con solo 1 arista el grafo es conexo.
>
>Caso recursivo: 
>Supongamos que vale $P(n)$: grafo de $n$ vértices que tiene más de $\frac{(n − 1)(n − 2)}{2}$ aristas es conexo.
>
>Queremos ver que vale $P(n + 1):$ grafo de $n + 1$ vértices que tiene más de $\frac{(n * (n - 1))}{2}$ aristas es conexo.
>    
>Vamos a considerar el grafo $G$ con $n + 1$ vértices, y para usar la HI vamos a sacar un vértice cualquiera junto con todas las aristas que los une. Este nuevo grafo $G'$ con $n$ vertice, si tiene más de $\frac{(n − 1)(n − 2)}{2}$ aristas entonces sabemos que es conexo según la HI.
>
>Para agregar de nuevo el vértice en $G'$ tiene que estar conectado con al menos 1 vértice para no aumentar la cantidad de componentes conexas, ya que queremos que sea conexa. Entonces le sumamo uno a la fórmula, $\frac{(n − 1)(n − 2)}{2} + 1 = \frac{(n² - 3n + 2)}{2} + 1 = \frac{1}{2}n² - \frac{3}{2}n + 1 + 1 =  \frac{1}{2}n² - \frac{3}{2}n + 2$ $^{(1)}$ por otro lado si desarrollamos la formula de $P(n + 1)$ tenemos $\frac{n * (n - 1)}{2} = \frac{n² - n}{2} = \frac{1}{2}n² - \frac{1}{2}n$ $^{(2)}$
>
>Se cumple que (1) > (2) para todo $n$ natural. Por lo tanto es equivalente decir que un grafo de $n + 1$ vértices que tiene más de $\frac{n * (n - 1)}{2}$ aristas es conexo. Probando así que vale para todo $n$ vértices.

Opcionalmente, puede demostrar la misma propiedad usando otras técnicas de demostración.
>   -nel- ლ(ಠ益ಠლ)

(b) Demostrar por medio de una reducción al absurdo que todo grafo de n vértices que tenga al menos 2 + $\frac{(n − 1)(n − 2)}{2}$ aristas es biconexo.

>- Comenzaremos suponiendo que el grafo no es biconexo a pesar de tener al menos esa cantidad de aristas. Que el grafo no es biconexo implica que o bien no es conexo o bien tiene al menos un punto de articulación.
>
>   - (1) Supongamos primero que el grafo no es conexo: Esto entraría en contradicción directamente con el punto (a) que dice que cualquier grafo con más de $\frac{(n-1)(n-2)}{2}$ aristas es necesariamente conexo. *ABS*! 
>   - (2) Supongamos ahora que el grafo es conexo pero tiene al menos un punto de articulación:
>       - Si eliminamos un punto de articulación de un grafo de $n$ vértices que tenga al menos 2 + $\frac{(n − 1)(n − 2)}{2}$ aristas, el grafo resultante con $n - 1$ vértices que debería tener al menos $\frac{(n − 2)(n − 3)}{2}$ aristas para seguir siendo conexo. Restamos la cantidad de aristas en ambos estados: 
>
$$2 + \frac{(n − 1)(n − 2)}{2} - \frac{(n − 2)(n − 3)}{2} = 2 + \frac{n² - 3n + 2}{2} - \frac{n² - 5n + 6}{2} = 2 + \frac{n² - 3n + 2 - n² - 5n + 6}{2} = 2 + \frac{2n - 4}{2} = 2 + n - 2 = n $$
>
>- Esto quiere decir que como inicialmente se tiene esa cantidad de aristas, sacando el punto de articulación (aunque éste esté conectado con todos los demás vértices con $n-1$ aristas) se sigue cumpliendo que el grafo resultante tiene más de $\frac{(n − 2)(n − 3)}{2}$ aristas cumpliendo así como un grafo conexo por (a) *ABS*! 
>
>- Con esto queda demostrado que todo grafo de n vértices que tenga al menos $2 + \frac{(n − 1)(n − 2)}{2} aristas es biconexo

(c) ¿Se pueden dar cotas mejores que funcionen a partir de algún $n_0$? Es decir, ¿existe $c(n) < 1 + \frac{(n − 1)(n − 2)}{2}$ (resp. $c(n) < 2 + \frac{(n − 1)(n − 2)
}{2}$) tal que todo grafo de $n >= n_0$ vértices que tenga al menos $c(n)$ aristas sea conexo (resp. biconexo)?

 > -Te la debo- 

### 5) CicloCompartido
Sean $P$ y $Q$ dos caminos distintos de un grafo $G$ que unen un vértice $v$ con otro $w$. Demostrar en forma directa que $G$ tiene un ciclo cuyas aristas pertenecen a $P$ o $Q$. Ayuda: denotar $P = v_0 , ..., v_p$ y $Q = w_0 , ..., w_q$ con $v_0 = w_0 = v$ y $v_p = w_q = w$. Definir explícitamente cuáles son los subcaminos de $P$ y $Q$ cuya unión forman un ciclo.

>- $P = v_0 , ... , v_p$
>- $Q = w_0 , ... , w_q$
>- $v_0 = w_0 = v$ y $v_p = w_q = w$.
>
>Supongamos sin pérdida de generalidad que hay un vértice $u$ que es el último vértice en común entre los caminos de $P$ y $Q$ que no sea $w$. Notar que si los caminos no tienen vértices en común entonces $u = v$ pues ambos caminos comienzan en $v$ y terminan en $w$. Con esto dicho podemos definir subcaminos: $P_1$ que va desde $v_0$ a $v_u$ $(v$ a $u)$, $P2$ que va desde $v_u$ a $v_p$ $(u$ a $w)$. $Q_1$ que va desde $w_0$ a $w_u$ $(v$ a $u)$, $Q_2$ que va desde $w_u$ a $w_q$ $(u$ a $w)$. Debido a que $u$ es el último punto en común antes de llegar a $w$ en ambos caminos, para ambos caminos no tienen vértices en común aparte de $u$ y $w$. Así que la unión entre los subcaminos de $P_2$ y $Q_2$ se obtiene un recorrido de $v_u, ..., v_p = w_q = w, ..., w_u$ donde $w_u = v_u = u$ y salvo por $u$ no repiten vértices cumpliendo así la definición de ciclo.
>
>Se puede hacer el mismo argumento analoga con $P_1$ y $Q_1$ definiendo un vértice $s$ como el primero que comparten entre ambos caminos que no sea $v$. 
>
>Con esto queda demostrado que $G$ tiene un ciclo cuyas aristas pertenecen a $P$ o $Q$.

### 6) Intersección Máxima
Sea $G$ un grafo conexo. Demostrar por el contrarrecíproco que todo par de caminos simples de longitud máxima de $G$ tienen un vértice en común. Ayuda: suponer que hay dos caminos disjuntos en vértices de igual longitud y definir explícitamente un camino que sea más largo que ellos.

>Demostrar: si dos caminos simples en $G$ tienen la longitud máxima, entonces tienen un vértice en común.
>
>Contrarrecíproco: si dos caminos simples en $G$ no tienen un vértice en común, entonces al menos uno no tienen la longitud máxima.
>
>- Suponemos que hay dos caminos disjuntos en vértices de igual longitud. Llememoslo caminos $P$ y $Q$ en $G$ donde tienen longitud $m$ y ambos tienen la longitud máxima.
>- Dado que $G$ es un grafo conexo, debe haber al menos un camino en $G$ que conecte un vértice del final de $P$ con un vértice del inicio (o final) de $Q$ sin pasar por los vértices que ya están en $P$ o $Q$ (ya que son disjuntos). Llamamos a este camino $R$.
>- El camino $R$ puede no ser simple si conecta directamente el final de $P$ con el inicio de $Q$, pero su existencia permite formar un camino $P + R + Q$ (o alguna variación de este, dependiendo de cómo se conecten exactamente). Importante, la longitud de $R$ debe ser al menos 1 porque conecta dos caminos disjuntos, lo que significa que el nuevo camino $P + R + Q$ tiene una longitud $(> m)$, lo cual es una contradicción porque hemos supuesto que $m$ es la longitud máxima para un camino en $G$.
>- Por lo tanto, nuestra suposición inicial de que $P$ y $Q$ pueden ser disjuntos y ambos de longitud máxima es falsa. Esto implica que cualquier par de caminos simples de longitud máxima en $G$ debe tener al menos un vértice en común, completando la demostración por contrarrecíproco. $\square$

## Representación de grafos y digrafos

### 11) RepresentaGrafos
Discutir (brevemente) las ventajas y desventajas en cuanto a la complejidad temporal y espacial de las siguientes implementaciones de un conjunto de vecindarios para un grafo $G$.

**Operaciones**
1. Inicializar la estructura a partir de un conjunto de aristas de $G$.

>- Lista de adyacencias: $O(n + m)$  Se necesita crear una lista de cada vértice $O(n)$ y para llenar los vecindario en cada nodo hay que recorrer aristas $O(m)$.
>- Lista de adyacencias con indice en vecindario: $O(n + m)$ idem arriba.
>- Matriz de adyacencias: $O(n²)$ Crear una matriz con n filas y n columnas cuesta $O(n²)$ y rellenar tiene un costo lineal con respecto al número total de elementos de la matriz.
>- Vecindad con tabla de hash: $O(n + m)$ porque necesitas insertar cada vértice y después cada arista en la tabla de hash de cada vértice.

2. Determinar si dos vértices $v$ y $w$ son adyacentes.

>- Lista de adyacencias: $O(|N(v)|)$ Hay que recorrer alguna lista de adyacencia de $v$ o $w$ en tiempo lineal $O(|N(v)|)$.
>- Lista de adyacencias con indice en vecindario: $O(1)$ Tengo las posiciones de $v$ y $w$, puedo acceder en $O(1)$.
>- Matriz de adyacencias: $O(1)$ parecido arriba.
>- Vecindad con tabla de hash: $O(1)$ en promedio, ya que se puede verificar directamente si $w$ está en la tabla de hash de los vecinos de $v$.

3. Recorrer y/o procesar el vecindario $N(v)$ de un vértice $v$ dado.

>- Lista de adyacencias: $O(|N(v)|)$ hay que recorrer cada vecino.
>- Lista de adyacencias con indice en vecindario: $O(|N(v)|)$ idem.
>- Matriz de adyacencias: $O(n)$ necesito verificar cada posible vértice para saber si es vecino o no.
>- Vecindad con tabla de hash: $O(|N(v)|)$ en promedio, porque aunque el acceso es directo, procesar cada vecino implica recorrer todos los elementos en la tabla.

4. Insertar un vértice $v$ con su conjunto de vecinos $N(v)$.

>- Lista de adyacencias: $O(|N(v)|)$ hay que actualizar en todos sus vecinos.
>- Lista de adyacencias con indice en vecindario: $O(|N(v)|)$ necesito actualizar cada vecino con la información del nuevo vértice.
>- Matriz de adyacencias: $O(|N(v)|)$ similar arriba.
>- Vecindad con tabla de hash: $O(|N(v)|)$ en promedio necesitas recorrer todos los vecinos para actualizar sus tablas.

5. Insertar una arista $vw$.

>- Lista de adyacencias: $O(1)$ no necesito mantener orden.
>- Lista de adyacencias con indice en vecindario: $O(1)$ tengo que actualizar info, confio que se hace en $O(1)$.
>- Matriz de adyacencias: $O(1)$.
>- Vecindad con tabla de hash: $O(1)$ en promedio.

6. Remover un vértice $v$ con todas sus adyacencias.

>- Lista de adyacencias: $O(|N(v)|* n + n)$ tengo que recorrer cada lista de adj de los vecinos y sacar $v$, ademas manejar el espacio de la lista principal de vértices.
>- Lista de adyacencias con indice en vecindario: $O(|N(v)|)$ tengo los indices, solo tengo que actualizar las listas de cada vecino.
>- Matriz de adyacencias: $O(|N(v)|)$ parecido arriba, actualizo valores en la matriz.
>- Vecindad con tabla de hash: $O(|N(v)|)$ necesitas recorrer todos los vecinos para actualizar sus tablas.

7. Remover una arista $vw$.

>- Lista de adyacencias: $O(|N(v)|)$ tengo que buscar en la lista de adj en $v$ y $w$ para sacarlos mutuamente.
>- Lista de adyacencias con indice en vecindario: $O(1)$ solo actualizo datos.
>- Matriz de adyacencias: $O(1)$ idem.
>- Vecindad con tabla de hash: $O(1)$ en promedio.

8. Mantener un orden de $N(v)$ de acuerdo a algún invariante que permita recorrer cada vecindario en un orden dado.

>- Lista de adyacencias: $O(|N(v)|/log|N(v)|)$ requeriría, en general, una operación de ordenamiento cada vez que se inserta o elimina un vértice o una arista.
>- Lista de adyacencias con indice en vecindario: $O(|N(v)|/log|N(v)|)$ idem arriba.
>- Matriz de adyacencias: no hay un "orden" más allá del de los índices mismos. 
>- Vecindad con tabla de hash: necesitaría estructuras adicionales o convertir la tabla en una lista y ordenarla antes de cada recorrido, lo cual afectaría la eficiencia.

### 12) Adyacencia Eficiente
Demostrar que las representaciones por listas de adyacencias de un grafo (ejercicio anterior) se pueden construir en $O(n+m)$ tiempo. 

>Sea $n$ el número de vértices y $m$ el número de aristas de un grafo. La lista de adyacencia consiste en hacer $n$ listas donde los elementos son los vecinos del $n$-esimo nodo en cuestión.
>
>- Inicializamos: por cada nodo del grafo inicializamos una lista vacía en $O(1)$. Como recorremos cada nodo es $O(n)$.
>- Ingresamos aristas: por cada arista $(u, v)$, insertamos $u$ en la lista de adyacencia de $u$ e insertamos $v$ en la lista de adyacencia de $u$ en caso de que no sea dirigido, si es dirigido solo lo hacemos en el sentido que indique. La inserción se hace en $O(1)$ pero como recorremos cada arista es $O(m)$.
>- Sumando los tiempos obtenemos $O(n + m)$.

¿Qué ocurre si se usa una tabla de hash? 
  
>El tiempo de inserción promedio sigue siendo $O(1)$, asumiendo que las colisiones se manejan eficientemente. Esto significa que la complejidad temporal global sigue siendo $O(n+m)$. El uso de tablas de hash puede mejorar el tiempo de consulta para verificar si dos vértices son adyacentes.

¿Y si se construye una matriz de adyacencias?

>La inicialización requiere establecer a 0 o a un valor especial todos los elementos de una matriz $n \times n$, lo cual tiene un tiempo de $O(n²)$. Aunque la inserción de cada arista es $O(1)$, la complejidad temporal total está dominada por la inicialización, resultando en $O(n^2)$, que es menos eficiente para grafos dispersos.

## Algoritmos sobre grafos y digrafos

### 14) Cazador de Ciclos
En este ejercicio diseñamos un algoritmo para encontrar ciclos en un digrafo. Decimos que un digrafo es acíclico cuando no tiene ciclos dirigidos. Recordar que un (di)grafo es trivial cuando tiene un sólo vértice.

(a) Demostrar con un argumento constructivo que si todos los vértices de un digrafo $D$ tienen grado de salida mayor a 0, entonces $D$ tiene un ciclo.

>- Comenzamos en cualquier vértice v en D, dado que el grado de salida de v en mayor a 0, existe al menos una arista dirigida que parte de v a otro vértice.
>- Ya que el grafo tiene finito vértices n y no se puede agregar infinitamente vértices, cuando se llegue a tener mas aristas que nodos se va a tener que repetir algún nodo. 
>- En el momento en el que se vuelve a un nodo ya visitado tenemos el ciclo.

(b) Diseñar un algoritmo que permita encontrar un ciclo en un digrafo D cuyos vértices tengan todos grado de salida mayor a 0.

    vector<bool> visitados                 <- vector tamaño n inicializado todo false 
    vector<bool> enPila                    <- vector tamaño n inicializado todo false para mantener registro del recorrido actual.
    bool hayCiclo(vector<list<int>> &lista_adyacencias, int vertice, vector<bool> &visitados, vector<bool> &enPila) {
      visitados[vertice] = true; 
      enPila[vertice] = true; 
      for (int hijo : lista_adyacencias[vertice]) { 
        if (!visitados[hijo]) { 
          if (hayCiclo(lista_adyacencias, hijo, visitados, enPila)) 
            return true; 
        } 
        else if (enPila[hijo]) { 
          return true; 
        } 
      } 
      enPila[vertice] = false; 
      return false; 
    }

(c) Explicar detalladamente (sin usar código) cómo se implementa el algoritmo del inciso anterior. El algoritmo resultante tiene que tener complejidad temporal $O(n + m)$.

>Para usar el algoritmo anterior necesito recorrer el vector de visitados y volver a correr hayCiclo para algun nodo que no haya estado visitado.
>Esto es debido a que si el grafo dirigido no resulta conexo, hay que recorrer todas las componentes conexas.
>
>La complejidad temporal de este algoritmo es $O(n + m)$, donde $n$ es el número de vértices y $m$ el número de aristas. 
>Esto se debe a que cada vértice y cada arista se exploran exactamente una vez en el proceso de búsqueda. 
>La eficiencia del algoritmo proviene de evitar revisitar vértices y aristas ya examinados, lo cual es asegurado por los vectores de control visitados y enPila.

(d) Demostrar que un digrafo $D$ es acíclico si y solo si $D$ es trivial o $D$ tiene un vértice con $d_{out}(v) = 0$ tal que $D - \{v\}$ es acíclico.

>Vamos a dividir en dos partes:
> 
>$\Rightarrow$) un digrafo $D$ es acíclico entonces $D$ es trivial o $D$ tiene un vértice con $d_{out}(v) = 0$ tal que $D - \{v\}$ es acíclico.

>Vamos a verlo por el absurdo, supongamos que tengo un digrafo $D$ acíclico no trivial, quiero ver que no tiene ningún vértice con $d_{out}(v) = 0$ tal que $D - \{v\}$ es acíclico. Si no tengo ningún ningún vértice con $d_{out}(v) = 0$ quiere decir que todos tiene grado de salida más de 0, luego por (a) es ciclico *ABS*. 
>
>Si en un digrafo no trivial (con más de un vértice) todos los vértices tienen un grado de salida mayor a 0, por el argumento constructivo que se pide demostrar en el primer ítem, este digrafo necesariamente contiene un ciclo, lo cual contradice nuestra suposición inicial de que el digrafo es acíclico. Por lo tanto, en un digrafo acíclico no trivial debe existir al menos un vértice con $d_{out}(v) = 0$.
>
>$\Leftarrow$) Si $D$ es trivial o $D$ tiene un vértice con $d_{out}(v) = 0$ tal que $D - {v}$ es acíclico entonces $D$ es acíclico.
>
>Si tenemos un digrafo no trivial $D - {v}$ que es acíclico puedo empezar el camino en cualquier nodo y cuando llego a $v$ no tengo mas vecinos que explorar, al remover sucesivamente vértices con grado de salida 0 (empezando por el último vértice sin sucesores y siguiendo en orden inverso hasta que no queden más vértices por remover o hasta llegar a un digrafo trivial), estamos asegurando que no podemos formar un camino cerrado que constituya un ciclo. Esto se debe a que, en cualquier etapa de este proceso, el vértice removido no puede ser parte de un ciclo por definición (ya que no tiene sucesores). Esto garantiza que el digrafo original $D$ es acíclico si cumple con la condición dada.

(e) A partir del inciso anterior, diseñar un algoritmo que permita determinar si un grafo $D$ tiene ciclos. En caso negativo, el algoritmo debe retornar una lista $v_1 , ... , v_n$ de vértices tales que $d_{out}(v_i) = 0$ en $D - \{v_1 , ... , v_{i−1}\} \forall i$. En caso afirmativo, el algoritmo debe retornar un ciclo.

    vector<bool> noSucesores               <- vector tamaño n inicializado todo false
    vector<bool> visitados                 <- vector tamaño n inicializado todo false 
    vector<bool> enPila                    <- vector tamaño n inicializado todo false para mantener registro del recorrido actual.
    bool hayCiclo(vector<list<int>> &lista_adyacencias, int vertice, vector<bool> &visitados, vector<bool> &enPila) {
      visitados[vertice] = true; 
      if (lista_adyacencias[vertice].size() == 0)
        noSucesores[vertice] = true
      else{
        enPila[vertice] = true; 
        for (int hijo : lista_adyacencias[vertice]) { 
          if (!visitados[hijo]) { 
            if (hayCiclo(lista_adyacencias, hijo, visitados, enPila)) 
              return true; 
          } 
          else if (enPila[hijo]) { 
            return true; 
          } 
        } 
        enPila[vertice] = false; 
        return false; 
      }
    }

(f) Explicar detalladamente (sin usar código) cómo se implementa el algoritmo del inciso anterior. El algoritmo resultante tiene que tener complejidad temporal $O(n + m)$.

>Para usar el algoritmo anterior necesito recorrer el vector de $visitados$ y volver a correr $hayCiclo$ para algun nodo que no haya estado visitado.
>Esto es debido a que si el grafo dirigido no resulta conexo, hay que recorrer todas las componentes conexas.
>
>A medida que va recorriendo las componente conexas voy actualizando un checkeador, si aparece un ciclo corto la búsqueda y devuelvo el ciclo que se registra $enPila$, si no encuentro ciclo recorro noSucesores que van a estar registrados todos los nodos de grado de salida 0.
>
>La complejidad temporal de este algoritmo es $O(n + m)$, donde $n$ es el número de vértices y $m$ el número de aristas. Esto se debe a que cada vértice y cada arista se exploran exactamente una vez en el proceso de búsqueda. La eficiencia del algoritmo proviene de evitar revisitar vértices y aristas ya examinados, lo cual es asegurado por los vectores de control $visitados$ y $enPila$.

