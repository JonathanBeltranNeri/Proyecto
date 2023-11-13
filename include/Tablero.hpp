#pragma once
#include <iostream>

#include <vector>
#include "Dibujo.hpp"

const int TABLERO_ANCHO = 10;
const int TABLERO_ALTO = 20;

class Tablero
{
private:
    std::vector<std::vector<char>> tablero;

public:
    Tablero()
    {
        // Inicializar el tablero
        tablero.resize(TABLERO_ALTO, std::vector<char>(TABLERO_ANCHO, '-'));
    }

    void Dibujar()
    {
        // Dibujar el tablero en la consola
        for (int i = 0; i < TABLERO_ALTO; i++)
        {
            for (int j = 0; j < TABLERO_ANCHO; j++)
            {
                std::cout << tablero[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }

    bool ColocarPieza(int x, int y, const std::vector<std::vector<char>>& pieza)
    {
        // Colocar la pieza en el tablero
        for (size_t i = 0; i < pieza.size(); i++)
        {
            for (size_t j = 0; j < pieza[i].size(); j++)
            {
                if (pieza[i][j] != ' ')
                {
                    if (x + j < 0 || x + j >= TABLERO_ANCHO || y + i >= TABLERO_ALTO || tablero[y + i][x + j] != '-')
                    {
                        return false; // La pieza no se puede colocar en esta posición
                    }
                    tablero[y + i][x + j] = pieza[i][j];
                }
            }
        }
        return true; // La pieza se colocó correctamente
    }

    void LimpiarLineasCompletas()
    {
        // Limpiar líneas completas y desplazar las líneas superiores hacia abajo
        for (int i = TABLERO_ALTO - 1; i >= 0; i--)
        {
            bool lineaCompleta = true;
            for (int j = 0; j < TABLERO_ANCHO; j++)
            {
                if (tablero[i][j] == '-')
                {
                    lineaCompleta = false;
                    break;
                }
            }

            if (lineaCompleta)
            {
                // Eliminar la línea completa
                tablero.erase(tablero.begin() + i);
                // Añadir una nueva línea en la parte superior
                tablero.insert(tablero.begin(), std::vector<char>(TABLERO_ANCHO, '-'));
                i++; // Revisar la nueva línea en la misma posición
            }
        }
    }

    bool Colision(int x, int y, const std::vector<std::vector<char>>& pieza)
    {
        // Verificar si hay colisión entre la pieza y el tablero en la posición (x, y)
        for (size_t i = 0; i < pieza.size(); i++)
        {
            for (size_t j = 0; j < pieza[i].size(); j++)
            {
                if (pieza[i][j] != ' ')
                {
                    if (x + j < 0 || x + j >= TABLERO_ANCHO || y + i >= TABLERO_ALTO)
                    {
                        return true; // Colisión con los bordes del tablero
                    }

                    if (tablero[y + i][x + j] != '-')
                    {
                        return true; // Colisión con otra pieza
                    }
                }
            }
        }

        return false; // No hay colisión
    }
};
