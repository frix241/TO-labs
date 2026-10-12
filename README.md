# Universidad Nacional de San Agustín
## Escuela Profesional de Ingeniería de Sistemas

### Curso: Tecnología de Objetos - Laboratorio 01
**Tema:** Conocer el lenguaje de programación Scala y resolver el problema del vuelto.

**Docente:** Ing. Edith Giovanna Cano Mamani
**Integrantes:** 
- Emanuel David Hilacondo Begazo
- Alberth Edward Riveros Vilca

---

## Descripción del Proyecto
Este repositorio contiene la solución implementada en Scala para el problema clásico del cambio de monedas. El objetivo es calcular de cuántas maneras diferentes se puede dar el cambio para una determinada cantidad de dinero utilizando una lista de denominaciones de monedas específicas, haciendo uso del paradigma de programación funcional y la recursividad.

---

## Explicación del Código

El código implementa la solución utilizando un enfoque de árbol de decisión recursivo apoyado en la inmutabilidad propia de Scala. 

### Función `countChange(money: Int, coins: List[Int]): 
Esta función divide el problema principal en dos subproblemas más pequeños en cada paso de la recursividad haciendo uso de las funciones de listas `head` y `tail`
*   **La rama de Usar la moned":** Expresada como `countChange(money - coins.head, coins)`. Decide tomar la primera moneda disponible en la lista y restarla al monto total. El segundo parámetro vuelve a ser la lista completa, lo que permite usar la misma denominación repetidas veces.
*   **La rama de No usar la moneda:** Expresada como `countChange(money, coins.tail)`. Decide ignorar la primera moneda de la lista. Conserva el monto intacto, pero reduce las opciones al resto de monedas (descartando la primera).

### Función `getCombinations(money: Int, coins: List[Int]): List[List[Int]]`
Sigue exactamente la misma lógica estructural, pero rastrea y almacena las rutas exactas:
*   Si decide **usar la moneda**, emplea `.map` para inyectar (`::`) esa moneda al inicio de las combinaciones.
*   Si decide **no usar la moneda**, arrastra las combinaciones formadas por el resto del arreglo.
*   El operador `++` une todas las rutas válidas formadas.

---

## Resolución del Cuestionario

**1. Explique el caso base implementado.**
El caso base es el mecanismo que detiene la recursividad y consta de dos reglas:
*   **Éxito `(money == 0)`:** Si tras las restas sucesivas el monto llega exactamente a 0, significa que la ruta analizada da el cambio exacto. Retorna `1` para validar y sumar ese camino al contador.
*   **Fallo `(money < 0 || coins.isEmpty)`[cite: 1]:** Si el monto baja de 0 (la moneda restada era muy grande) o la lista de monedas se queda vacía sin que el monto sea 0 (sin opciones restantes), se retorna `0` y la rama es descartada por ser inválida.

**2. ¿Este problema se resuelve mejor en el modelo de programación funcional?**
A nivel de declaratividad y diseño, **sí**. La programación funcional prioriza la inmutabilidad y las funciones puras. Este algoritmo matemáticamente es una relación de recurrencia, por lo que su modelado como árbol de decisiones en Scala representa la fórmula de manera directa y transparente, sin mutar estados externos. No obstante, en un entorno de producción, un enfoque puramente recursivo requiere optimizaciones para manejar problemas de rendimiento por recálculo.

**3. ¿Qué beneficios se podrían obtener para este problema utilizando memoización?**
El beneficio principal es una drástica optimización de la **complejidad temporal**. El algoritmo puramente recursivo recalcula repetidas veces subproblemas idénticos a lo largo del árbol, lo que genera un deficiente tiempo exponencial de $O(2^n)$. Al aplicar memoización (guardando en caché los resultados de los subcálculos ya resueltos), la complejidad se reduce a un tiempo polinomial o pseudo-polinomial $O(N \times S)$, siendo $N$ el número de denominaciones y $S$ el monto total.

---

## Referencias 

[1] S. Gupta, B. Huang, and R. Impagliazzo, "The Greedy Coin Change Problem," *arXiv preprint arXiv:2411.18137*, Nov. 2024. Available: https://arxiv.org/abs/2411.18137

[2] F. P. Hargreaves and D. Merkle, "FooPar: A Functional Object Oriented Parallel Framework in Scala," in *Lecture Notes in Computer Science*, vol. 8488, 2014, pp. 118–129, doi: 10.1007/978-3-642-55195-6_11.
