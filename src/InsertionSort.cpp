#include "InsertionSort.h"

InsertionSort::InsertionSort(const std::vector<int>& datos) 
    : AlgoritmoOrdenamiento(datos) {
    m_i = 1; // Start from second element
}

void InsertionSort::reiniciar(const std::vector<int>& datos) {
    AlgoritmoOrdenamiento::reiniciar(datos);
    m_i = 1;
}

void InsertionSort::paso() {
    if (m_terminado) return;

    if (m_i >= static_cast<int>(m_datos.size())) {
        m_terminado = true;
        return;
    }

    if (m_j <= 0 || m_datos[m_j] >= m_datos[m_j - 1]) {
        m_i++;
        m_j = m_i;
    } else {
        m_comparaciones++;
        std::swap(m_datos[m_j], m_datos[m_j - 1]);
        m_intercambios++;
        m_j--;
    }

    if (m_j == m_i) {
        m_j = m_i;
    }
}
