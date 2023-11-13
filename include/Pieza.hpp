
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
class Pieza {
private:
    char simbolo;
    std::vector<std::vector<char>> shape;

public:
    Pieza(char s, const std::vector<std::vector<char>>& sh) : simbolo(s), shape(sh) {}

    char getSimbolo() const {
        return simbolo;
    }

    const std::vector<std::vector<char>>& getShape() const {
        return shape;
    }
};

int main() {
    std::vector<std::vector<char>> forma = {
        {'X', 'X', 'X'},
        {'X', ' '},
        {'X', ' '},
    };

    Pieza p('T', forma);

    // Ejemplo de uso con printf
    printf("Símbolo de la pieza: %c\n", p.getSimbolo());
    printf("Forma de la pieza:\n");
    const auto& shape = p.getShape();
    for (const auto& row : shape) {
        for (char c : row) {
            printf("%c ", c);
        }
        printf("\n");
    }

    return 0;
}
