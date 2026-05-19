#include "algoritmos/BubbleSort.h"

// Constructor que inicializa Bubble Sort
BubbleSort::BubbleSort(const std::vector<int>& datos) 
    : AlgoritmoOrdenamiento(datos), m_huboSwap(false) {
}

// Reinicia el algoritmo y variables
void BubbleSort::reiniciar(const std::vector<int>& datos) {

    // Reinicia datos y contadores base
    AlgoritmoOrdenamiento::reiniciar(datos);

    // Reinicia indicador de intercambio
    m_huboSwap = false;
}

// Ejecuta un paso del Bubble Sort
void BubbleSort::paso() {

    // Verifica si el algoritmo ya termino
    if (m_terminado) return;

    // Inicia nueva pasada
    if (m_i == 0) {
        m_huboSwap = false;
    }

    // Verifica si llego al final
    if (m_i >= static_cast<int>(m_datos.size()) - 1) {

        // Si no hubo intercambios, ya esta ordenado
        if (!m_huboSwap) {
            m_terminado = true;

        } else {

            // Reinicia otra pasada
            m_i = 0;
            m_huboSwap = false;
        }

        return;
    }

    // Siguiente posicion a comparar
    m_j = m_i + 1;

    // Cuenta comparacion
    m_comparaciones++;

    // Intercambia si estan desordenados
    if (m_datos[m_i] > m_datos[m_j]) {

        std::swap(m_datos[m_i], m_datos[m_j]);

        m_intercambios++;

        m_huboSwap = true;
    }

    // Avanza al siguiente elemento
    m_i++;
}