#ifndef BUBBLESORT_H
#define BUBBLESORT_H

#include "AlgoritmoOrdenamiento.h"

class BubbleSort : public AlgoritmoOrdenamiento {
public: 
    explicit BubbleSort(const std::vector<int>& datos);
    void reiniciar(const std::vector<int>& datos) override;
    void paso() override;
    std::string nombre() const override { return "Bubble Sort"; }

private: 
    bool m_huboSwap; // optimizacion: sin swaps => arreglo ordenado
};

#endif
