#ifndef INSERTIONSORT_H
#define INSERTIONSORT_H

#include "algoritmos/AlgoritmoOrdenamiento.h"

class InsertionSort : public AlgoritmoOrdenamiento {
public: 
    explicit InsertionSort(const std::vector<int>& datos);
    void reiniciar(const std::vector<int>& datos) override;
    void paso() override;
    std::string nombre() const override { return "Insertion Sort"; }
};

#endif
