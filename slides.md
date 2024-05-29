---
theme: seriph
background: https://images.unsplash.com/photo-1541029071515-84cc54f84dc5?q=80&w=1080&auto=format&fit=crop&ixlib=rb-4.0.3&ixid=M3wxMjA3fDB8MHxwaG90by1wYWdlfHx8fGVufDB8fHx8fA%3D%3D
title: Programación Dinámica
info: |
  ## Técnicas avanzadas de optimización
  Explorando estrategias de bottom-up y top-down.
class: text-center
highlighter: shiki
drawings:
  persist: false
lineNumbers: true
transition: fade-out
mdc: true
addons:
  - slidev-addon-asciinema
---

# Programación Dinámica

Trade-offs entre tiempo-espacio.

---
layout: two-cols
---
# ¿Qué es la Programación Dinámica?
Primer acercamiento

La Programación Dinámica (PD) es una técnica para resolver problemas complejos al descomponerlos en subproblemas más manejables.

Trata de evitar la repetición de cálculos resolviendo cada subproblema <span v-mark="{ at: 1, color: 'red', type: 'underline' }">una sola vez</span>.

::right::


<v-switch>
  <template #2>
      Vamos a tranformar esto:
      <img src="/dp_google.jpg" class="absolute top-40 w-120" /> 
  </template>
  <template #3>
      En esto:
      <div class="flex items-center justify-center w-full h-full">
        <Tweet id="1640394252940369923" scale=0.9 />
      </div>
  </template>
</v-switch>


---
layout: image-right

# the image source
image: /bellman.jpeg
---

# Inicios
Bellman y su legado

El término **"Programación Dinámica"** fue acuñado por **Richard Bellman** en los años 50, marcando un hito en el campo de la optimización matemática.

Bellman también es conocido por su trabajo en teoría de juegos y aprendizaje por refuerzo.

---

# Principios Fundamentales
Condiciones presentes en la PD

1. **Subestructura óptima 🛠️** 

La solución de subproblemas más pequeños puede utilizarse para abordar el problema global.

<br>

2. **Subproblemas superpuestos 🔁**

Problemas que pueden descomponerse en partes que se resuelven repetidamente.

---

# Subestructura óptima 🛠️
Deseable en la PD

La subestructura óptima significa que una solución óptima de un problema puede ser construida a partir de soluciones óptimas de sus subproblemas. Este principio es esencial para garantizar que la estrategia de combinar las soluciones de los subproblemas conduce a una solución óptima del problema global.


Ejemplos: 
- Merge Sort: Utiliza la subestructura óptima para combinar dos listas ordenadas.
- Fibonacci: Utiliza los dos elementos anteriores para calcular el siguiente.

<br>

> ¿Dónde hemos visto esto antes?

---

# Subproblemas superpuestos 🔁
Requsito en la PD

Los subproblemas superpuestos se refieren a la situación en la que los subproblemas se repiten varias veces, lo que significa que una solución simple basada en la división del problema en subproblemas y su solución independiente sería ineficiente debido a la repetición del trabajo.

<br>

> Mientras que la subestructura óptima es deseable, la superposición de subproblemas es esencial para la PD. 

<br>

> Pregunta: ¿Qué ocurre si no se cumple la propiedad de subproblemas superpuestos?

---

# Fibonacci
Hola mundo de la PD

$$
F(n) = 
\begin{cases} 
0 & \text{si } n = 0,\\
1 & \text{si } n = 1,\\
F(n-1) + F(n-2) & \text{si } n > 1.
\end{cases}
$$


<v-switch>
  <template #1>
      <div class="flex justify-center">
        <img src="/fibo.png" class="w-100" />
      </div>
  </template>
  <template #2>
      <div class="flex justify-center">
        <img src="/fibo_2.png" class="w-100" />
      </div>
  </template>
</v-switch>

<div v-click="1">
  <p>Preguntas:</p>
    <ul>
        <li>¿Dónde se aprecia la subestructura óptima?</li>
        <li>¿Dónde se repiten los subproblemas?</li>
    </ul>
</div>

---
layout: two-cols
---

<<< @/snippets/fibo_rec.cpp {all|8-11|13-34|16|19|22|25|30-31|all}{maxHeight:'500px'}


::right::

<v-click>
  <Asciinema src="./casts/fibo-rec.cast" :playerProps="{speed: 2, rows: 30}"/>
</v-click>

<v-clicks>

- ¿Qué complejidad tiene la función `fibo`?
- ¿Qué ocurre si se calcula `fibo(50)`?

</v-clicks>

---
layout: intro
---

# ¿Cómo podemos mejorar la eficiencia de Fibonacci? 🤔

---
layout: two-cols-header
---

# Técnicas de Programación Dinámica
Dos enfoques

Existen dos enfoques principales para implementar la Programación Dinámica. Ambos comparten el objetivo de evitar la repetición de cálculos, pero difieren en la forma en que lo hacen.

::left::

# Memoización
(Top-Down)

Se basa en almacenar los resultados de los subproblemas en una estructura de datos, como un diccionario, o arrays (de N dimensiones) para evitar recalcularlos.

::right::

# Tabulación
(Bottom-Up)

Se basa en resolver los subproblemas en un orden específico y almacenar los resultados en una tabla, generalmente un array, para que puedan ser utilizados en la resolución de problemas más grandes.

---

# Memoización (Top-Down)
Fácil de implementar

En caso de tener una función recursiva, se puede utilizar la memoización para almacenar los resultados de los subproblemas en una estructura de datos, como un diccionario u array, para evitar recalcularlos.

Es **top-down** porque se resuelven los subproblemas más grandes primero y se utilizan para resolver los subproblemas más pequeños.

<v-click>
````md magic-move
```cpp
int fibo(int n) {
    if (n <= 1) return n;
    return fibo(n - 1) + fibo(n - 2);
}
```
```cpp {*|1|3|4|*}
int fibo(int n, int* memo) {
    if (n <= 1) return n;
    if (memo[n] != -1) return memo[n];
    memo[n] = fibo(n - 1, memo) + fibo(n - 2, memo);
    return memo[n];
}
```
````

</v-click>

<v-clicks>

- ¿Qué ventajas tiene la memoización sobre la recursión simple?
- ¿Qué desventajas tiene la memoización?
- ¿Qué complejidad tiene la función `fibo` con memoización?
- ¿Cuál es el "costo" de la memoización?
- ¿Qué valores iniciales debería tener el array `memo`?

</v-clicks>

<!-- $O(2^n)$ es el orden sin memo -->

---

# Tabulación (Bottom-Up)
Enfoque imperativo

La tabulación es un enfoque iterativo que implica resolver los subproblemas en un orden específico y almacenar los resultados en una tabla, generalmente un array, para que puedan ser utilizados en la resolución de problemas más grandes.

Es bottom-up porque se resuelven los subproblemas más pequeños primero y se utilizan para resolver los subproblemas más grandes.

<v-click>
````md magic-move
```cpp
int fibo(int n) {
    if (n <= 1) return n;
    return fibo(n - 1) + fibo(n - 2);
}
```
```cpp {*|2|3-4|5-7|8|*}
int fibo(int n) {
    int tab[n + 1];
    tab[0] = 0;
    tab[1] = 1;
    for (int i = 2; i <= n; i++) {
        tab[i] = tab[i - 1] + tab[i - 2];
    }
    return tab[n];
}
```
```cpp
int fibo(int n) {
    if (n <= 1) return n;
    int lastlast = 0, last = 1, current;
    for (int i = 2; i <= n; i++) {
        current = lastlast + last;
        lastlast = last;
        last = current;
    }
    return current;
}
```
```
````
</v-click>

<v-clicks>

- ¿Qué ventajas tiene la tabulación sobre la memoización?
- ¿Qué complejidad tiene la función `fibo` con tabulación?

</v-clicks>

---

# Problema: escaleras
Un problema ya conocido...

Dada una escalera con `n` escalones, se puede subir de a 1 o 2 escalones a la vez. ¿Cuántas formas distintas hay de subir la escalera?

<v-clicks>

- En el escalón 0, ¿cuántas formas hay de subir?
- En el escalón 1, ¿cuántas formas hay de subir?
- En el escalón 2, ¿cuántas formas hay de subir?
- En el escalón 3, ¿cuántas formas hay de subir?
- ¿Cómo se relacionan los subproblemas?

</v-clicks>

<v-click>

Secreto: Dejar de pensar como vamos a subir la escalera y pensar en cómo llegamos al último escalón.

<img src="/blowmind.gif" class="absolute bottom-0 right-0 w-50" />

</v-click>

---

# Problema: escaleras ponderadas
Un problema más complejo

Dada una escalera con `n` escalones, se puede subir de a 1, 2 escalones a la vez. Cada escalón tiene un peso asociado (siempre positivo). ¿Cuál es la suma de los pesos de la secuencia de escalones que minimiza el peso total?


<v-clicks>

- ¿Cómo se relacionan los subproblemas?
- ¿Cómo puedo saber el camino que recorrí?

</v-clicks>

--- 

# Problema: caminos (matriz)
Un problema de combinatorias

Dada una matriz de `m x n`, ¿cuántos caminos distintos hay para llegar de la esquina superior izquierda a la esquina inferior derecha?

Nos movemos hacia abajo o hacia la derecha.

<table style="width:100%; border: 1px solid white; border-collapse: collapse;">
  <tr>
    <td style="border: 1px solid white; padding: 10px;">I</td>
    <td style="border: 1px solid white; padding: 10px;">-</td>
    <td style="border: 1px solid white; padding: 10px;">-</td>
    <td style="border: 1px solid white; padding: 10px;">-</td>
  </tr>
  <tr>
    <td style="border: 1px solid white; padding: 10px;">-</td>
    <td style="border: 1px solid white; padding: 10px;">-</td>
    <td style="border: 1px solid white; padding: 10px;">-</td>
    <td style="border: 1px solid white; padding: 10px;">-</td>
  </tr>
  <tr>
    <td style="border: 1px solid white; padding: 10px;">-</td>
    <td style="border: 1px solid white; padding: 10px;">-</td>
    <td style="border: 1px solid white; padding: 10px;">-</td>
    <td style="border: 1px solid white; padding: 10px;">F</td>
  </tr>
</table>


---

# Problema: caminos con obstáculos
Un problema más complejo

Dada una matriz de `m x n` con obstáculos, ¿cuántos caminos distintos hay para llegar de la esquina superior izquierda a la esquina inferior derecha?

Nos movemos hacia abajo o hacia la derecha.

<table style="width:100%; border: 1px solid white; border-collapse: collapse;">
  <tr>
    <td style="border: 1px solid white; padding: 10px;">I</td>
    <td style="border: 1px solid white; padding: 10px;">-</td>
    <td style="border: 1px solid white; padding: 10px;">-</td>
    <td style="border: 1px solid white; padding: 10px;">-</td>
  </tr>
  <tr>
    <td style="border: 1px solid white; padding: 10px;">-</td>
    <td style="border: 1px solid white; padding: 10px;">-</td>
    <td style="border: 1px solid white; padding: 10px;">💀</td>
    <td style="border: 1px solid white; padding: 10px;">💀</td>
  </tr>
  <tr>
    <td style="border: 1px solid white; padding: 10px;">-</td>
    <td style="border: 1px solid white; padding: 10px;">-</td>
    <td style="border: 1px solid white; padding: 10px;">-</td>
    <td style="border: 1px solid white; padding: 10px;">F</td>
  </tr>
</table>

---

# Problema: problema del cambio
Un problema de optimización

Dada una cantidad `amount` y un conjunto de monedas de denominaciones `coins`, ¿cuál es la menor cantidad de monedas que se necesitan para devolver el cambio?

Ejemplo:
- Monedas: [1, 2, 5, 10, 50]
  - Para cambio de 12 pesos -> 2 monedas (10, 2)
  - Para cambio de 47 pesos -> 6 monedas (10, 10, 10, 10, 5, 2)
- Monedas: [1, 2, 5, 12, 50] 👀
  - Para cambio de 15 pesos -> 2 monedas (10, 5) ✔️

---

# Problema: combinatorias
Triángulo de Pascal



Definición:

$$ \binom{n}{k} = \frac{n!}{k!(n-k)!} $$

De forma recursiva:

$$ 
\begin{cases}
\binom{n}{0} = 1 \\
\binom{n}{n} = 1 \\
\binom{n}{k} = \binom{n-1}{k-1} + \binom{n-1}{k}
\end{cases}
$$


---

# Problema: mochila
Clásico de clásicos

Recordemos la solución de la mochila 0-1 con dividir y conquistar.

```cpp
int knapsack(int W, int wt[], int val[], int n) {
    if (n == 0 || W == 0) return 0;
    if (wt[n - 1] > W) return knapsack(W, wt, val, n - 1);
    return max(val[n - 1] + knapsack(W - wt[n - 1], wt, val, n - 1),
               knapsack(W, wt, val, n - 1));
}
```

<br>

> Pregunta: ¿Existe una subestructura óptima en este problema?


---

# Problema: otras mochila 
Otros tipos

- Mochila 0-INF
- Mochila 0-N
- Mochila de dos o más dimensiones
