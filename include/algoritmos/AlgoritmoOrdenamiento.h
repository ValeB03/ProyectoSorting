#ifndef ALGORITMOORDENAMIENTO_H
#define ALGORITMOORDENAMIENTO_H

#include <vector>   // Permite usar vectores
#include <string>   // Permite usar strings

// Clase base abstracta para algoritmos de ordenamiento.
// Todas las clases de ordenamiento heredan de aqui.
class AlgoritmoOrdenamiento {
public: 

    // Constructor que recibe los datos a ordenar
    explicit AlgoritmoOrdenamiento(const std::vector<int>& datos);

    // Destructor virtual para liberar memoria correctamente
    virtual ~AlgoritmoOrdenamiento() = default;

    // Ejecuta un paso del algoritmo
    virtual void paso() = 0;

    // Reinicia el algoritmo con nuevos datos
    virtual void reiniciar(const std::vector<int>& datos);

    // Verifica si el ordenamiento termino
    virtual bool terminado() const { return m_terminado; }

    // Devuelve el nombre del algoritmo
    virtual std::string nombre() const = 0;

    // Devuelve el vector actual
    const std::vector<int>& datos() const { return m_datos; }

    // Retorna el tamaño del vector
    int tamano() const { return static_cast<int>(m_datos.size()); }

    // Retorna el primer indice actual
    int indicePrimero() const { return m_i; }

    // Retorna el segundo indice actual
    int indiceSegundo() const { return m_j; }

    // Retorna cantidad de comparaciones
    int comparaciones() const { return m_comparaciones; }

    // Retorna cantidad de intercambios
    int intercambios() const { return m_intercambios; }

protected: 

    // Vector con los datos a ordenar
    std::vector<int> m_datos;

    // Indica si el algoritmo termino
    bool m_terminado;

    // Indices usados durante el ordenamiento
    int m_i, m_j;

    // Contador de comparaciones
    int m_comparaciones;

    // Contador de intercambios
    int m_intercambios;
};

#endif