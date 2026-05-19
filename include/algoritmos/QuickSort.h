#ifndef QUICKSORT_H
#define QUICKSORT_H

#include "algoritmos/AlgoritmoOrdenamiento.h"
#include <stack> // Permite usar pilas

// Clase que implementa el algoritmo Quick Sort
class QuickSort : public AlgoritmoOrdenamiento {
public: 

    // Constructor que recibe los datos
    explicit QuickSort(const std::vector<int>& datos);

    // Reinicia el algoritmo con nuevos datos
    void reiniciar(const std::vector<int>& datos) override;

    // Ejecuta un paso del Quick Sort
    void paso() override;

    // Devuelve el nombre del algoritmo
    std::string nombre() const override { 
        return "Quick Sort"; 
    }

private:

    // Pila que guarda las particiones pendientes
    std::stack<std::pair<int, int>> m_stack;

    // Variables usadas durante la particion
    int m_low, m_high;

    // Valor pivote
    int m_pivot;

    // Indices usados para comparar elementos
    int m_i_index, m_j_index;

    // Indica si esta en fase de particion
    bool m_partitionPhase;
};

#endif