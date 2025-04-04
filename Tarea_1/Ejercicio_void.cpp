#include<iostream>
/* 1ero una variable char
   2do una variable int
   3ero una varibale float
*/
class SuperArreglo {
    private:
        int elem_int;
        char elem_char;
        float elem_float;
        void* superarr[3];
    public:
        SuperArreglo(){
            std::cout<<"Inserte un numero entero: ";
            std::cin>>elem_int;
            std::cout<<"\n";

            std::cout<<"Inserte un caracter: ";
            std::cin>>elem_char;
            std::cout<<"\n";

            std::cout<<"Inserte un flotante: ";
            std::cin>>elem_float;
            std::cout<<"\n";

            superarr[0]=&elem_int;
            superarr[1]=&elem_char;
            superarr[2]=&elem_float;
        }

        void printSuperArreglo(){
            std::cout<<"Elemento entero: "<<*((int*)superarr[0])<<"\n";
            std::cout<<"Elemento caracter: "<<*((char*)superarr[1])<<"\n";
            std::cout<<"Elemento flotante: "<<*((float*)superarr[2])<<"\n";
        }
};
int main(){
    SuperArreglo prueba1;
    prueba1.printSuperArreglo();
    return 0;
}