#include "algoritmos/AlgoritmoOrdenamiento.h"

AlgoritmoOrdenamiento::AlgoritmoOrdenamiento(const std::vector<int>& datos) 
    : m_datos(datos), m_terminado(false), m_i(0), m_j(0), 
      m_comparaciones(0), m_intercambios(0) {
}

void AlgoritmoOrdenamiento::reiniciar(const std::vector<int>& datos) {
    m_datos = datos;
    m_terminado = false;
    m_i = 0;
    m_j = 0;
    m_comparaciones = 0;
    m_intercambios = 0;
}
