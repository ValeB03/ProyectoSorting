#include "algoritmos/SelectionSort.h"

SelectionSort::SelectionSort(const std::vector<int>& datos) 
    : AlgoritmoOrdenamiento(datos), m_minIndex(0) {
    m_i = 0;
    m_j = 1;
}

void SelectionSort::reiniciar(const std::vector<int>& datos) {
    AlgoritmoOrdenamiento::reiniciar(datos);
    m_i = 0;
    m_j = 1;
    m_minIndex = 0;
}

void SelectionSort::paso() {
    if (m_terminado) return;

    if (m_i >= static_cast<int>(m_datos.size()) - 1) {
        m_terminado = true;
        return;
    }

    if (m_j == m_i) {
        m_minIndex = m_i;
        m_j = m_i + 1;
    }

    if (m_j < static_cast<int>(m_datos.size())) {
        m_comparaciones++;
        if (m_datos[m_j] < m_datos[m_minIndex]) {
            m_minIndex = m_j;
        }
        m_j++;
    } else {
        if (m_minIndex != m_i) {
            std::swap(m_datos[m_i], m_datos[m_minIndex]);
            m_intercambios++;
        }
        m_i++;
        m_j = m_i + 1;
    }
}