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

    while(nodo->next != nullptr){
        if(nodo->error->getPIp() == pIp && nodo->error->getSIp() == sIp && nodo->error->getTIp() == tIp && nodo->error->getCIp() == cIp){
            while(nodo->next->error->getPIp() == pIp && nodo->next->error->getSIp() == sIp && nodo->next->error->getTIp() == tIp && nodo->next->error->getCIp() == cIp && nodo != nullptr){
                nodo = nodo->next;
            }
            return nodo;
        }
        nodo = nodo->next;
    }
    return nodo;
}

void Registro::crearArchivo(){
    MyNodoLL* current; 
    current = head;
    ofstream file;
    file.open("bitacoraOrdenada1.3-eq4.txt");
    for (int i =0; i<this->size; i++) {
        file << current->error->imprimeError();
        current=current->next;
    }
    file.close();
}

void Registro::crearArchivoEspecifico(string busqI, string busqF){
    string strNumBusq;
    strNumBusq = to_string(this->numBusq);
    MyNodoLL* current; 
    int num_doc = 1;
    current = sequentialSearch(busqI);
    istringstream split(busqF);
    string strPIpF;
    int pIpF;
    string strSIpF;
    int sIpF;
    string strTIpF;
    int tIpF;
    string strCIpF;
    int cIpF;
    string strPuertoF;
    int puertoF;

    getline(split, strPIpF, '.');
    pIpF = stoi(strPIpF);
    getline(split, strSIpF, '.');
    sIpF = stoi(strSIpF);
    getline(split, strTIpF, '.');
    tIpF = stoi(strTIpF);
    getline(split, strCIpF, ':');
    cIpF = stoi(strCIpF);
    getline(split, strPuertoF, '\n');
    puertoF = stoi(strPuertoF);

    ofstream file;

    file.open("salida" + strNumBusq + "-eq4.txt");
    while(current->error->getPIp() != pIpF && current->error->getSIp() != sIpF && current->error->getTIp() != tIpF && current->error->getCIp() != cIpF){
        file << current->error->imprimeError();
        current=current->next;
    }
    this->numBusq ++;
    file.close();
}
