#include<iostream>
#include <ctime>
#include <cstdlib>

char (*createMatrizRandom())[3] {
    char (*matriz)[3] = new char[3][3]; // Reservamos memoria dinámica para 3x3 caracteres
    int* numeros = new int[8];

    // Inicializar números del 1 al 8 usando punteros
    int* p = numeros;
    int valor = 1;
    while (p < numeros + 8) {
        *p = valor;
        ++p;
        ++valor;
    }

    // Mezclar los números usando punteros
    srand(time(0));
    for (int* end = numeros + 7; end > numeros; --end) {
        int* randomPos = numeros + (rand() % (end - numeros + 1));
        int temp = *end;
        *end = *randomPos;
        *randomPos = temp;
    }

    // Copiar los números a la matriz (solo con punteros)
    char* m = &matriz[0][0]; // Apuntamos al primer char de la matriz
    for (p = numeros; p < numeros + 8; ++p, ++m) {
        *m = *p + '0'; // Convertimos número a carácter
    }

    *m = ' '; // Última posición: espacio

    delete[] numeros; // Liberamos memoria
    return matriz; // Retornamos el puntero a la matriz
}

char* searchEspacio( char (*k)[3]){
    char *espacio;
    for(char(*p)[3]=k;p<k+3;p++){
        for(char*q=*p;q<*(p+1);q++){
            if(*q==' '){
                espacio=q;
                break;
            };
        }
    }
    return espacio;
}
void printMatriz(char (*k)[3]){
    for(char(*p)[3]=k;p<k+3;p++){
        for(char*q=*p;q<*(p+1);q++){
            std::cout<<*q<<"\t";
        }
        std::cout<<std::endl;
    }
}
void swap(char &a, char &b){
    char temp;
    temp=a;
    a=b;
    b=temp;
}
int fil(char *temp,  char (*k)[3]){
    int fila;
    if(temp<*(k+1)) fila=0;
    else if(temp<*(k+2)&&temp>=*(k+1)) fila=1;
    else if(temp<*(k+3)&&temp>=*(k+2)) fila=2;
    else fila=101;
    return fila;
}
bool verificarSubida(char *espacio,  char (*k)[3]){
    if(espacio-3>=*k) return true;
    else return false;
}
bool verificarBajada(char *espacio,  char (*k)[3]){
    if(espacio+3<*(k+3)) return true;
    else return false;
}
bool verificarRight(char *espacio,  char (*k)[3]){
    if(fil(espacio,k)==fil(espacio+1,k)) return true;
    else return false;
}
bool verificarLeft(char *espacio,  char (*k)[3]){
    if(fil(espacio,k)==fil(espacio-1,k)) return true;
    else return false;
}
bool verificarWin(char (*k)[3]){
    if(
        *(*(k+0)+0)=='1' &&  *(*(k+0)+1)=='2' && *(*(k+0)+2)=='3' &&
        *(*(k+1)+0)=='4' && *(*(k+1)+1)=='5' && *(*(k+1)+2)=='6' &&
        *(*(k+2)+0)=='7' && *(*(k+2)+1)=='8' && *(*(k+2)+2)==' '
    ){
        return true;
    }
    else return false;
}
void Game(char (*k)[3]){
    bool Win{false}, Rindes{false};
    char mov;
    std::cout<<"Se inicia el juego!\n";
    printMatriz(k);
    while(Win==false){
        //Buscar el espacio
        char*e=searchEspacio(k);
        //Pedir movimiento
        std::cout<<"Escoga hacia donde quiere mover el espacio(W para mover arriba,\nS para mover abajo, A para mover hacia la izquierda y D para la derecha)\n";
        std::cin>>mov;
        if(mov=='W'||mov=='w'){
            if(verificarSubida(e,k)){
                swap(*e,*(e-3));
            }
            else{
                std::cout<<"Movimiento invalido\n";
                continue;
            }
        }
        else if(mov=='S'||mov=='s'){
            if(verificarBajada(e,k)){
                swap(*e,*(e+3));
            }
            else{
                std::cout<<"Movimiento invalido\n";
                continue;
            }
        }
        else if(mov=='A'||mov=='a'){
            if(verificarLeft(e,k)){
                swap(*e,*(e-1));
            }
            else{
                std::cout<<"Movimiento invalido\n";
                continue;
            }
        }
        else if(mov=='D'||mov=='d'){
            if (verificarRight(e,k)){
                swap(*e,*(e+1));
            }
            else{
                std::cout<<"Movimiento invalido\n";
                continue;
            }
        }
        else{
            std::cout<<"Movimiento invalido\n";
            continue;
        }
        printMatriz(k);
        Win=verificarWin(k);
    }
}

int main(){
    char matriz[3][3]={{'1','2','3'},{'4','5','6'},{'7',' ','8'}};
    char (*k)[3]=matriz;
    char (*q)[3]=createMatrizRandom();
    Game(q);
    //Game(k);
    return 0;
}
