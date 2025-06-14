#include <iostream>
#include <cmath>

constexpr double PI = 3.14159265358979323846;

double Acircle(double* dims) {
    return PI * std::pow(*(dims), 2);
}
double Asquare(double* dims) {
    return std::pow(*(dims), 2);
}
double Arectangle(double* dims) {
    return *(dims) * *(dims+1);
}
double Atriangle(double* dims) {
    return (*(dims) * *(dims+1)) / 2;
}

void ejecuta(double (*Areas[4])(double*), double parametros[4][2], char nombres[4][15]) {
    for (
        double (**pArea)(double*) = Areas;
        pArea != Areas + 4;
        ++pArea, ++parametros, ++nombres
    ) {
        std::cout << "Area del " << *nombres
                  << " con " << *(*parametros) << " y " << *((*parametros)+1) << " :\n";
        std::cout << (*pArea)(*parametros) << std::endl;
    }
}


int main() {
    double (*Areas[4])(double*) = { Acircle, Asquare, Arectangle, Atriangle };

    double parametros[4][2] = {
        {5, 0},  // Círculo
        {4, 0},  // Cuadrado
        {6, 4},  // Rectángulo
        {3, 5}   // Triángulo
    };

    char nombres[4][15] = { "Circulo", "Cuadrado", "Rectangulo", "Triangulo" };

    ejecuta(Areas, parametros, nombres);

    return 0;
}
