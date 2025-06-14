#include <iostream>
#include <cmath>

constexpr double PI = 3.14159265358979323846;

double Acircle(double* dims) {
    return PI * std::pow(dims[0], 2);
}
double Asquare(double* dims) {
    return std::pow(dims[0], 2);
}
double Arectangle(double* dims) {
    return dims[0] * dims[1];
}
double Atriangle(double* dims) {
    return (dims[0] * dims[1]) / 2;
}

void ejecuta(double (*Areas[4])(double*), double parametros[4][2], char nombres[4][15]) {
    for (int i = 0; i < 4; ++i) {
        std::cout << "Area del " << nombres[i]
                  << " con " << parametros[i][0] << " y " << parametros[i][1] << " :\n";
        std::cout << Areas[i](parametros[i]) << std::endl;
    }
}

int main() {
    double (*Areas[4])(double*) = {Acircle, Asquare, Arectangle, Atriangle};
    
    // Para figuras que solo usan un parámetro, el segundo puede ser cero o ignorado
    double parametros[4][2] = {
        {5, 0},  // Círculo
        {4, 0},  // Cuadrado
        {6, 4},  // Rectángulo
        {3, 5}   // Triángulo
    };
    
    char nombres[4][15] = {"Circulo", "Cuadrado", "Rectangulo", "Triangulo"};

    ejecuta(Areas, parametros, nombres);

    return 0;
}
