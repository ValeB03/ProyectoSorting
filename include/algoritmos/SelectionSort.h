#ifndef SELECTIONSORT_H
#define SELECTIONSORT_H

#include "algoritmos/AlgoritmoOrdenamiento.h"

// Clase que implementa el algoritmo Selection Sort
class SelectionSort : public AlgoritmoOrdenamiento {
public: 

    // Constructor que recibe los datos
    explicit SelectionSort(const std::vector<int>& datos);

    // Reinicia el algoritmo con nuevos datos
    void reiniciar(const std::vector<int>& datos) override;

    // Ejecuta un paso del Selection Sort
    void paso() override;

    // Devuelve el nombre del algoritmo
    std::string nombre() const override { 
        return "Selection Sort"; 
    }

private:

    // Guarda el indice del valor minimo
    int m_minIndex;
};

#endif