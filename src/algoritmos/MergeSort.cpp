#include "algoritmos/MergeSort.h"
#include <algorithm>

MergeSort::MergeSort(const std::vector<int>& datos) 
    : AlgoritmoOrdenamiento(datos), m_temp(datos.size()) {
    initializeMergeTasks();
}

void MergeSort::reiniciar(const std::vector<int>& datos) {
    AlgoritmoOrdenamiento::reiniciar(datos);
    m_temp.resize(datos.size());
    while (!m_mergeTasks.empty()) m_mergeTasks.pop();
    initializeMergeTasks();
}

void MergeSort::initializeMergeTasks() {
    if (m_datos.size() <= 1) {
        m_terminado = true;
        return;
    }
    
    // tareas iniciales (pares de elementos)
    for (int i = 0; i < static_cast<int>(m_datos.size()) - 1; i += 2) {
        int left = i;
        int mid = i;
        int right = std::min(i + 1, static_cast<int>(m_datos.size()) - 1);
        m_mergeTasks.push(MergeTask(left, mid, right));
    }
}

void MergeSort::paso() {
    if (m_terminado) return;

    if (m_mergeTasks.empty()) {
        m_terminado = true;
        return;
    }

    MergeTask& task = m_mergeTasks.front();
    
    if (!task.initialized) {
        task.i = task.left;
        task.j = task.mid + 1;
        task.k = task.left;
        task.initialized = true;
    }

    // una operación de mezcla
    if (task.i <= task.mid && task.j <= task.right) {
        m_comparaciones++;
        if (m_datos[task.i] <= m_datos[task.j]) {
            m_temp[task.k++] = m_datos[task.i++];
        } else {
            m_temp[task.k++] = m_datos[task.j++];
        }
    } else if (task.i <= task.mid) {
        m_temp[task.k++] = m_datos[task.i++];
    } else if (task.j <= task.right) {
        m_temp[task.k++] = m_datos[task.j++];
    } else {
        // copiar resultado final
        for (int idx = task.left; idx <= task.right; idx++) {
            m_datos[idx] = m_temp[idx];
        }

        m_intercambios += (task.right - task.left + 1);
        m_mergeTasks.pop();

        if (m_mergeTasks.empty()) {
            m_terminado = true;
        }
    }
}