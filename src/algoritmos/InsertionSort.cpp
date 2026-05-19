#include "algoritmos/InsertionSort.h"

// Constructor que inicializa Insertion Sort
InsertionSort::InsertionSort(const std::vector<int>& datos) 
    : AlgoritmoOrdenamiento(datos) {

    // Empieza desde el segundo elemento
    m_i = 1;
}

// Reinicia el algoritmo y variables
void InsertionSort::reiniciar(const std::vector<int>& datos) {

    // Reinicia datos y contadores base
    AlgoritmoOrdenamiento::reiniciar(datos);

    // Reinicia posicion inicial
    m_i = 1;
}

// Ejecuta un paso del Insertion Sort
void InsertionSort::paso() {

    // Verifica si el algoritmo termino
    if (m_terminado) return;

    // Verifica si llego al final del vector
    if (m_i >= static_cast<int>(m_datos.size())) {

        m_terminado = true;

        return;
    }

    // Verifica si el elemento ya esta en posicion correcta
    if (m_j <= 0 || m_datos[m_j] >= m_datos[m_j - 1]) {

        // Avanza al siguiente elemento
        m_i++;

        m_j = m_i;

    } else {

        // Cuenta comparacion
        m_comparaciones++;

        // Intercambia elementos
        std::swap(m_datos[m_j], m_datos[m_j - 1]);

        // Cuenta intercambio
        m_intercambios++;

        // Retrocede posicion
        m_j--;
    }

    // Mantiene actualizado el indice
    if (m_j == m_i) {
        m_j = m_i;
    }
}