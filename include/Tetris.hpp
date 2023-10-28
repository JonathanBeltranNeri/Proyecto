#pragma once

#include "Dibujo.hpp" // Asumiendo que este es el archivo de encabezado para Dibujo
#include "Actualizable.hpp" // Asumiendo que este es el archivo de encabezado para Actualizable

class Tetris : public Dibujo, public Actualizable
{
public:
    Tetris() : Dibujo("J") {}
    ~Tetris() {}

    void Actualizar() override {
        // Implementa la lógica de actualización aquí
    }
};
