//Héctor Eduardo Ayala Gudiño A01638996
#include "Registro.h"
#include "Error.h"

Registro::Registro(){}

void Registro::leerRegistro(){
    ifstream archivoVideos("bitacora.txt");
    string linea;
    stringstream ss(linea);

    string mes;
    string dia;
    string hora;
    string strPIp;
    int pIp;
    string strSIp;
    int sIp;
    string strTIp;
    int tIp;
    string strCIp;
    int cIp;
    string strPuerto;
    int puerto;
    string razon;
    
    while (getline(archivoVideos, linea)){
        stringstream ss(linea);
        
        getline(ss, mes, ' ');
        getline(ss, dia, ' ');
        getline(ss, hora, ' ');
        getline(ss, strPIp, '.');
        pIp = stoi(strPIp);
        getline(ss, strSIp, '.');
        sIp = stoi(strSIp);
        getline(ss, strTIp, '.');
        tIp = stoi(strTIp);
        getline(ss, strCIp, ':');
        cIp = stoi(strCIp);
        getline(ss, strPuerto, ' ');
        puerto = stoi(strPuerto);
        getline(ss, razon, '\0');
        
        this->size++;
        if(this->head == nullptr){
            this->head = this->tail = new MyNodoLL(new Error(mes, dia, hora, pIp, sIp, tIp, cIp, puerto, razon));
        }
        else{
            MyNodoLL* nvo = new MyNodoLL(new Error(mes, dia, hora, pIp, sIp, tIp, cIp, puerto, razon));
            this->tail->next = nvo;
            this->tail = nvo;
        }
    }
    archivoVideos.close();
}

void Registro::ipAInt(string busq, int* pIp, int* sIp, int* tIp, int* cIp){
    istringstream split(busq);
    string strPIp;
    int pIp;
    string strSIp;
    int sIp;
    string strTIp;
    int tIp;
    string strCIp;
    int cIp;

    getline(split, strPIp, '.');
    *pIp = stoi(strPIp);
    getline(split, strSIp, '.');
    *sIp = stoi(strSIp);
    getline(split, strTIp, '.');
    *tIp = stoi(strTIp);
    getline(split, strCIp, ':');//va a terminar en : o en \n
    *cIp = stoi(strCIp);
}

MyNodoLL* Registro::sequentialSearch(string busq){
    int pIp;
    int sIp;
    int tIp;
    int cIp;

    ipAInt(busq, &pIp, &sIp, &tIp, &cIp);

    MyNodoLL* temp = this->head;
    while(temp->next != nullptr){
        if(temp->error->getPIp() >= pIp){
            if(temp->error->getCIp() >= cIp){
                if(temp->error->getTIp() >= tIp){
                    if(temp->error->getSIp() >= sIp){
                        return temp;
                    }
                }
            }
        }
        temp = temp->next;
    }
    return nullptr;
}

MyNodoLL* Registro::sequentialSearchFin(string busq, MyNodoLL* nodo){
    int pIp;
    int sIp;
    int tIp;
    int cIp;
    
    ipAInt(busq, &pIp, &sIp, &tIp, &cIp);

    while((nodo->error->getPIp() == pIp && nodo->error->getSIp() == sIp && nodo->error->getTIp() == tIp && nodo->error->getCIp() == cIp) || nodo->next != nullptr){
        nodo = nodo->next;
    }
    return nodo;
}