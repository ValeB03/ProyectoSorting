#ifndef QUICKSORT_H
#define QUICKSORT_H

#include "algoritmos/AlgoritmoOrdenamiento.h"
#include <stack>

class QuickSort : public AlgoritmoOrdenamiento {
public: 
    explicit QuickSort(const std::vector<int>& datos);
    void reiniciar(const std::vector<int>& datos) override;
    void paso() override;
    std::string nombre() const override { return "Quick Sort"; }

private:
    std::stack<std::pair<int, int>> m_stack;
    int m_low, m_high, m_pivot, m_i_index, m_j_index;
    bool m_partitionPhase;
};

#endif
