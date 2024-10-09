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

MyNodoLL* Registro::sequentialSearch(string busq){
    istringstream split(busq);
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

    getline(split, strPIp, '.');
    pIp = stoi(strPIp);
    getline(split, strSIp, '.');
    sIp = stoi(strSIp);
    getline(split, strTIp, '.');
    tIp = stoi(strTIp);
    getline(split, strCIp, ':');
    cIp = stoi(strCIp);
    getline(split, strPuerto, '\n');
    puerto = stoi(strPuerto);

    MyNodoLL* temp = this->head;
    while(temp->next == nullptr){
        if(temp->error->getPIp() >= pIp && temp->error->getSIp() >= sIp && temp->error->getTIp() >= tIp && temp->error->getCIp() >= cIp && temp->error->getPuerto() >= puerto){
            return temp;
        }else{
            temp = temp->next;
        }
    }
    return nullptr;
}

void Registro::crearArchivo(){
    ofstream file;
    file.open("bitacoraOrdenada1.3-eq4.txt");
    for (int i =0; i<this->size; i++) {
        file << head->error->imprimeError();
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
        file << head->error->imprimeError();
        current=current->next;
    }
    this->numBusq ++;
    file.close();
}