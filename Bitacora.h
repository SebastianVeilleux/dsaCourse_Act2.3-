//Héctor Eduardo Ayala Gudiño A01638996
//Luis Fernando Rojo Valdes A01640584
// Sebastian Alejandro Veilleux Amaya A01644977
#ifndef BITACORA_H
#define BITACORA_H


#include "Error.h"

using namespace std;

struct MyNodoLL{
    Error *error;
    MyNodoLL* next;

    MyNodoLL(Error *error, MyNodoLL* next){
        this->error = error;
        this->next = next;
    }

    MyNodoLL(Error *error):MyNodoLL(error,nullptr){}
};

class Bitacora{
    private:
        int numBusq = 1;
        int size = 0;
        MyNodoLL *head,
        *tail;
    public:
        Bitacora();
        void leerBitacora();
        MyNodoLL* findMiddle(MyNodoLL* head);
        MyNodoLL* Merge(MyNodoLL* first, MyNodoLL* second);
        MyNodoLL* MergeSort(MyNodoLL* head);
        void ordenar();
        // MERGE PASADO
            //void mezcla(int ini, int central, int fin);
            //void ordenar(int ini, int fin);
            //void ordenar();
        //
        void crearArchivo();
        void crearArchivoEspecifico(string busqI, string busqF);//cambiar para listas enlazadas
        void ipAInt(string busq, int* pIp, int* sIp, int* tIp, int* cIp);
        MyNodoLL* sequentialSearch(string busq);
       //MyNodoLL* sequentialSearchFin(string busq, MyNodoLL* nodo);
};

#endif
