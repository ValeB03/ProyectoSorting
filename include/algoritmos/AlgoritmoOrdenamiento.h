#ifndef ALGORITMOORDENAMIENTO_H
#define ALGORITMOORDENAMIENTO_H

#include <vector>
#include <string>

// Clase base abstracta para algoritmos de ordenamiento.
// paso() es virtual puro: cada subclase DEBE implementarlo.
// El destructor virtual garantiza que al hacer: 
// AlgoritmoOrdenamiento* a = new BubbleSort(datos);
// delete a; <-- llama ~BubbleSort(), no ~AlgoritmoOrdenamiento()
class AlgoritmoOrdenamiento {
public: 
    explicit AlgoritmoOrdenamiento(const std::vector<int>& datos);
    virtual ~AlgoritmoOrdenamiento() = default;

    // Avanza EXACTAMENTE una comparacion del algoritmo.
    // Llamar paso() repetidamente hasta que terminado()==true
    // equivale a ejecutar el algoritmo completo.
    virtual void paso() = 0;

    // Reinicia con nuevos datos
    virtual void reiniciar(const std::vector<int>& datos);

    virtual bool terminado() const { return m_terminado; }
    virtual std::string nombre() const = 0;

    // Estado actual (para dibujar en el canvas)
    const std::vector<int>& datos() const { return m_datos; }
    int tamano() const { return static_cast<int>(m_datos.size()); }
    int indicePrimero() const { return m_i; }
    int indiceSegundo() const { return m_j; }
    int comparaciones() const { return m_comparaciones; }
    int intercambios() const { return m_intercambios; }

protected: 
    std::vector<int> m_datos;
    bool m_terminado;
    int m_i, m_j;
    int m_comparaciones;
    int m_intercambios;
};

#endif