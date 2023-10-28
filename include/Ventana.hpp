#pragma once
#include <curses.h>
#include <iostream>
#include <unistd.h>
#include <list>
#include <Dibujo.hpp>
#include <Actualizable.hpp>
using namespace std;

class Ventana
{
private:
    int x;
    int y;
    int velocidad;
    int contador;
    bool ejecucion;

public:
    Ventana()
    {
        initscr();
        getmaxyx(stdscr, this->y, this->x);
        this->ejecucion = false;
        this->velocidad = 10;
        this->contador = 20;
        curs_set(FALSE);
        cbreak();
        timeout(100);
        noecho();
        keypad(stdscr,TRUE);
    }
    void Iniciar(){
        this->ejecucion = true;
    
    }
    void Actualizar(list<Actualizable*> actualizables){
        for (auto &&actualizable : actualizables)
        {
            actualizable->Actualizar();
        }
    }
    void Dibujar(list<Dibujo*> dibujos)
    {
        clear();
        for (auto &&dibujo : dibujos)
        {
            dibujo->Dibujar();
        }
        
        refresh();
        usleep(41000); //24 f/s
    }
    void Cerrar(){
        this->ejecucion = false;
    }
    ~Ventana() {
        endwin();
    }
    
};
