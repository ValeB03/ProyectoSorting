#ifndef MERGESORT_H
#define MERGESORT_H

#include "AlgoritmoOrdenamiento.h"
#include <queue>

class MergeSort : public AlgoritmoOrdenamiento {
public: 
    explicit MergeSort(const std::vector<int>& datos);
    void reiniciar(const std::vector<int>& datos) override;
    void paso() override;
    std::string nombre() const override { return "Merge Sort"; }

private:
    std::vector<int> m_temp;
    struct MergeTask {
        int left, mid, right;
        int i, j, k;
        bool initialized;
        MergeTask(int l, int m, int r) : left(l), mid(m), right(r), i(l), j(m+1), k(l), initialized(false) {}
    };
    std::queue<MergeTask> m_mergeTasks;
    void initializeMergeTasks();
};

#endif
