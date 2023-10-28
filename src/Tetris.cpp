#include <Ventana.hpp>
#include <Dibujo.hpp>
#include <curses.h>
#include <unistd.h>
int main(int argc, char const *argv[])
{

    Ventana v;
    v.Iniciar();

    Dibujo d1(2, 1, "B_I");
    Dibujo d2(8, 5, "B_J");

    bool ejecucion = true;
    while (ejecucion)
    {
        // Ciclo de actualizacion
        v.Actualizar();
        if (getch() == 'q')
        {
            ejecucion = false;
        }
        if (getch() == 'd')
        {
            d1.AvanzarX(1);
        }
        if (getch() == 'a')
        {
            d1.RetrocederX(1);
        }
        if (getch() == KEY_RIGHT)
        {
            d2.AvanzarX(1);
        }
        if (getch() == KEY_LEFT)
        {
            d2.RetrocederX(1);
        }

        /// Ciclo de dibujo
        clear();
        d1.Dibujar();
        d2.Dibujar();

        v.Dibujar();

        refresh();
        usleep(41000); // 24 f/s
    }

    return 0;
}