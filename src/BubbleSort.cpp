#include "BubbleSort.h"

BubbleSort::BubbleSort(const std::vector<int>& datos) 
    : AlgoritmoOrdenamiento(datos), m_huboSwap(false) {
}

void BubbleSort::reiniciar(const std::vector<int>& datos) {
    AlgoritmoOrdenamiento::reiniciar(datos);
    m_huboSwap = false;
}

void BubbleSort::paso() {
    if (m_terminado) return;

    if (m_i == 0) {
        m_huboSwap = false;
    }

    if (m_i >= static_cast<int>(m_datos.size()) - 1) {
        if (!m_huboSwap) {
            m_terminado = true;
        } else {
            m_i = 0;
            m_huboSwap = false;
        }
        return;
    }

    m_j = m_i + 1;
    m_comparaciones++;

    if (m_datos[m_i] > m_datos[m_j]) {
        std::swap(m_datos[m_i], m_datos[m_j]);
        m_intercambios++;
        m_huboSwap = true;
    }

    m_i++;
}
