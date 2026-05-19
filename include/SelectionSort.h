#ifndef SELECTIONSORT_H
#define SELECTIONSORT_H

#include "AlgoritmoOrdenamiento.h"

class SelectionSort : public AlgoritmoOrdenamiento {
public: 
    explicit SelectionSort(const std::vector<int>& datos);
    void reiniciar(const std::vector<int>& datos) override;
    void paso() override;
    std::string nombre() const override { return "Selection Sort"; }

private:
    int m_minIndex;
};

#endif
