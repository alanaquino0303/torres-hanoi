# Torres de Hanói en C++

Implementación interactiva de las **Torres de Hanói** en C++ para consola. El programa utiliza pilas para representar las torres, muestra los discos en formato ASCII y valida los movimientos según las reglas clásicas del juego.

---

## Características principales

- Interfaz de consola amigable y clara.
- Representación visual en ASCII de las torres y discos.
- Validación completa de movimientos.
- Control de turnos entre dos jugadores.
- Conteo de movimientos realizados.
- Modularidad en funciones: Entrada, validación, visualización y lógica del juego.
- Código 100% portable a sistemas Linux, macOS y Windows.

---

## Estructura del proyecto

```
/ torres-hanoi
├── torres_hanoi.cpp      # Código fuente principal.
├── README.md             # Documentación del proyecto.
```

---

## Requisitos

- **Linux/macOS**: `g++`, `clang++`.
- **Windows**: MinGW (`g++`).
- Terminal o consola de comandos para ejecutar el programa.

---

## Ejecución del programa

### En Linux o macOS
1. Compilar el código:

   ```bash
   g++ -std=c++17 torres_hanoi.cpp -o torres_hanoi
   ```
   
2. Ejecutar el programa:

   ```bash
   ./torres_hanoi
   ```

### En Windows
1. Compilar el código:

   ```bash
   g++ -std=c++17 torres_hanoi.cpp -o torres_hanoi.exe
   ```
   
2. Ejecutar el programa:

   ```bash
   torres_hanoi.exe
   ```

---

## Autor

Alan Aquino.
