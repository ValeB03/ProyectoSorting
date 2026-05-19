#include "algoritmos/AlgoritmoOrdenamiento.h"

// Constructor que inicializa los datos y variables
AlgoritmoOrdenamiento::AlgoritmoOrdenamiento(const std::vector<int>& datos) 
    : m_datos(datos), 
      m_terminado(false), 
      m_i(0), 
      m_j(0), 
      m_comparaciones(0), 
      m_intercambios(0) {
}

// Reinicia el algoritmo con nuevos datos
void AlgoritmoOrdenamiento::reiniciar(const std::vector<int>& datos) {

    // Copia los nuevos datos
    m_datos = datos;

    // Reinicia el estado del algoritmo
    m_terminado = false;

    // Reinicia indices
    m_i = 0;
    m_j = 0;

    // Reinicia contadores
    m_comparaciones = 0;
    m_intercambios = 0;
}