#ifndef MERGESORT_H
#define MERGESORT_H

#include "algoritmos/AlgoritmoOrdenamiento.h"
#include <queue> // Permite usar colas

// Clase que implementa el algoritmo Merge Sort
class MergeSort : public AlgoritmoOrdenamiento {
public: 

    // Constructor que recibe los datos
    explicit MergeSort(const std::vector<int>& datos);

    // Reinicia el algoritmo con nuevos datos
    void reiniciar(const std::vector<int>& datos) override;

    // Ejecuta un paso del Merge Sort
    void paso() override;

    // Devuelve el nombre del algoritmo
    std::string nombre() const override { 
        return "Merge Sort"; 
    }

private:

    // Vector temporal usado para mezclar datos
    std::vector<int> m_temp;

    // Estructura que guarda tareas de mezcla
    struct MergeTask {

        // Limites de las sublistas
        int left, mid, right;

        // Indices usados durante la mezcla
        int i, j, k;

        // Indica si la tarea ya inicio
        bool initialized;

        // Constructor de la tarea
        MergeTask(int l, int m, int r) 
            : left(l), mid(m), right(r),
              i(l), j(m+1), k(l),
              initialized(false) {}
    };

    // Cola de tareas pendientes
    std::queue<MergeTask> m_mergeTasks;

    // Inicializa las tareas del Merge Sort
    void initializeMergeTasks();
};

#endif