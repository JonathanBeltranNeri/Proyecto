#pragma once

#include "Dibujo.hpp"
#include "Actualizable.hpp"
#include <string>
class Tetris : public Dibujo, public Actualizable
{
public:
    Tetris(int x, int y, std::string forma) : Dibujo(x, y, forma) {}

    void Actualizar() override
    {
        // Implementa la lógica de actualización aquí
        // Por ejemplo, podrías mover el bloque o hacer cualquier otra operación específica del Tetris
    }
};
