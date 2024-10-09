//Héctor Eduardo Ayala Gudiño A01638996
#ifndef REGISTRO_H
#define REGISTRO_H

#include "Error.h"

using namespace std;

struct MyNodoLL{
    Error *error;
    MyNodoLL* next;

    MyNodoLL(Error *error, MyNodoLL* next){
        this->error = error;//?
        this->next = next;
    }

    MyNodoLL(Error *error):MyNodoLL(error,nullptr){}
};

class Registro{
    private:
        int numBusq = 1;
        int size;
        MyNodoLL *head,
        *tail;
    public:
        Registro();
        void leerRegistro();
        void mezcla(int ini, int central, int fin);//cambiar para listas enlazadas
        void ordenar(int ini, int fin);//cambiar para listas enlazadas
        void ordenar();//cambiar para listas enlazadas
        void crearArchivo();
        void crearArchivoEspecifico(string busqI, string busqF);//cambiar para listas enlazadas
        MyNodoLL* sequentialSearch(string busq);
};

#endif