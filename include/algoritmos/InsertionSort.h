#ifndef INSERTIONSORT_H
#define INSERTIONSORT_H

#include "algoritmos/AlgoritmoOrdenamiento.h"

// Clase que implementa el algoritmo Insertion Sort
class InsertionSort : public AlgoritmoOrdenamiento {
public: 

    // Constructor que recibe los datos
    explicit InsertionSort(const std::vector<int>& datos);

    // Reinicia el algoritmo con nuevos datos
    void reiniciar(const std::vector<int>& datos) override;

    // Ejecuta un paso del Insertion Sort
    void paso() override;

    // Devuelve el nombre del algoritmo
    std::string nombre() const override { 
        return "Insertion Sort"; 
    }
};

#endif