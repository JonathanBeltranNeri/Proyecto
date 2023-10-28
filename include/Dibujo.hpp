#pragma once
#include <fstream>
#include <string>
#include <iostream>
#include <curses.h>
using namespace std;

class Dibujo
{
private:
    int x;
    int y;
    fstream archivo;
    string recurso;

public:
    Dibujo(int x, int y,string recurso){
        this->recurso = recurso;
        archivo.open("./data/"+ this->recurso +".txt");
        this->x=x;
        this->y=y;

    }
    Dibujo(string recurso)
    {
        Dibujo(0,0,recurso);
    }
    void Mover(int x, int y){
        this->x = x;
        this->y = y;
    }
    void AvanzarX(int x){
        this->x += x;
    }
    void RetrocederX(int x){
        this->x -= x;
    }
    void Dibujar()
    {
        string linea;

        move(this->y,this->x);
        while (getline(archivo,linea))
        {
            int y_linea = getcury(stdscr);
            mvaddstr(y_linea + 1,
             this->x,
              linea.c_str()
            );
        }
        archivo.clear();
        archivo.seekg(0);
     


    }
    ~Dibujo()  
    {  
        archivo.close();  
    }
};

