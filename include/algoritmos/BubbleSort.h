#ifndef BUBBLESORT_H
#define BUBBLESORT_H

#include "algoritmos/AlgoritmoOrdenamiento.h"

// Clase que implementa el algoritmo Bubble Sort
class BubbleSort : public AlgoritmoOrdenamiento {
public: 

    // Constructor que recibe los datos
    explicit BubbleSort(const std::vector<int>& datos);

    // Reinicia el algoritmo con nuevos datos
    void reiniciar(const std::vector<int>& datos) override;

    // Ejecuta un paso del Bubble Sort
    void paso() override;

    // Devuelve el nombre del algoritmo
    std::string nombre() const override { 
        return "Bubble Sort"; 
    }

private: 

    // Verifica si hubo intercambio
    bool m_huboSwap;
};

#endif