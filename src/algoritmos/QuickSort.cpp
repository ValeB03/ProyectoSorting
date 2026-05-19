#include "algoritmos/QuickSort.h"

QuickSort::QuickSort(const std::vector<int>& datos) 
    : AlgoritmoOrdenamiento(datos) {
    if (m_datos.size() > 1) {
        m_stack.push({0, static_cast<int>(m_datos.size()) - 1});
    } else {
        m_terminado = true;
    }
    m_partitionPhase = false;
}

void QuickSort::reiniciar(const std::vector<int>& datos) {
    AlgoritmoOrdenamiento::reiniciar(datos);
    while (!m_stack.empty()) m_stack.pop();

    if (m_datos.size() > 1) {
        m_stack.push({0, static_cast<int>(m_datos.size()) - 1});
    } else {
        m_terminado = true;
    }
    m_partitionPhase = false;
}

void QuickSort::paso() {
    if (m_terminado) return;

    if (m_stack.empty()) {
        m_terminado = true;
        return;
    }

    auto range = m_stack.top();
    m_low = range.first;
    m_high = range.second;

    if (m_low >= m_high) {
        m_stack.pop();
        return;
    }

    if (!m_partitionPhase) {
        // iniciar partición
        m_pivot = m_datos[m_high];
        m_i_index = m_low - 1;
        m_j_index = m_low;
        m_partitionPhase = true;
    }

    if (m_j_index < m_high) {
        m_comparaciones++;
        if (m_datos[m_j_index] <= m_pivot) {
            m_i_index++;
            if (m_i_index != m_j_index) {
                std::swap(m_datos[m_i_index], m_datos[m_j_index]);
                m_intercambios++;
            }
        }
        m_j_index++;
    } else {
        // finalizar partición
        if (m_i_index + 1 != m_high) {
            std::swap(m_datos[m_i_index + 1], m_datos[m_high]);
            m_intercambios++;
        }

        int pivotIndex = m_i_index + 1;
        m_stack.pop();

        // subarreglos restantes
        if (pivotIndex - 1 > m_low) {
            m_stack.push({m_low, pivotIndex - 1});
        }
        if (pivotIndex + 1 < m_high) {
            m_stack.push({pivotIndex + 1, m_high});
        }

        m_partitionPhase = false;
    }

    if (m_stack.empty()) {
        m_terminado = true;
    }
}