# EvaluacionHito2_EDA_2026037_PabloMedina
# Sistema de Gestión de Turnos de Estudiantes

## Descripción
Este programa en C++ implementa un sistema en consola para la gestión de turnos de atención de estudiantes.  
Permite registrar, atender, mostrar y buscar estudiantes en una lista de espera, siguiendo el orden de llegada (FIFO).

El sistema presenta un menú con las siguientes opciones:
1. Registrar estudiante  
2. Atender estudiante  
3. Mostrar estudiantes en espera  
4. Buscar estudiante por nombre  
5. Salir  

---

## Estructura de Datos Usada
Se utilizó una **lista enlazada simple implementada manualmente**.  
Cada nodo contiene:
- Nombre del estudiante  
- Código del estudiante  
- Puntero al siguiente nodo  

### Justificación
- La lista enlazada simple permite manejar dinámicamente la cantidad de estudiantes sin necesidad de definir un tamaño fijo.  
- La inserción al final y eliminación al inicio cumplen con la lógica FIFO (First In, First Out).  
- Es más flexible que un arreglo estático, ya que no requiere conocer de antemano el número máximo de estudiantes.

---

## Complejidad
- **Inserción (registrar estudiante):** O(1) si se mantiene puntero al final.  
- **Eliminación (atender estudiante):** O(1) eliminando desde el inicio.  
- **Búsqueda por nombre:** O(n), ya que se recorre la lista secuencialmente.  
- **Mostrar estudiantes:** O(n), recorriendo todos los nodos.

---

## Instrucciones de Compilación y Ejecución
1. Compilar el programa con:
   ```bash
   g++ SistemaGestionEstudiantes.cpp -o SistemaGestionEstudiantes
   ./SistemaGestionEstudiantes

