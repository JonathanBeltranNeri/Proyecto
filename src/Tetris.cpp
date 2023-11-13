#include "Ventana.hpp"
#include "Tablero.hpp"
#include "Dibujo.hpp"
#include <thread>
#include <iostream>

int main()
{
    Ventana v;
    v.Iniciar();

    Tablero tablero;
    Dibujo d1(2, 1, "B_I"); // Cargar la pieza B_I desde el archivo "B_I.txt"

    bool ejecucion = true;

    while (ejecucion)
    {
        v.Actualizar();

        int input = getch();

        if (input == 'q')
        {
            ejecucion = false;
        }
        else if (input == 'd')
        {
            d1.AvanzarX(1);
            std::vector<std::vector<char>> shape;
            for (const std::string& row : d1.getShape()) {
                std::vector<char> tempRow(row.begin(), row.end());
                shape.push_back(tempRow);
            }
            if (tablero.Colision(d1.getX(), d1.getY(), shape))
            {
                d1.RetrocederX(1);
            }
        }
        else if (input == 'a')
        {
            d1.RetrocederX(1);
            std::vector<std::vector<char>> shape;
            for (const std::string& row : d1.getShape()) {
                std::vector<char> tempRow(row.begin(), row.end());
                shape.push_back(tempRow);
            }
            if (tablero.Colision(d1.getX(), d1.getY(), shape))
            {
                d1.AvanzarX(1);
            }
        }

        // Ciclo de dibujo
        clear();

        // Dibujar el tablero y la pieza
        tablero.Dibujar();
        d1.Dibujar();

        refresh();
        std::this_thread::sleep_for(std::chrono::milliseconds(41)); // 24 f/s
    }

    return 0;
}
