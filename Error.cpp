//Héctor Eduardo Ayala Gudiño A01638996
//Luis Fernando Rojo Valdes A01640584
// Sebastian Alejandro Veilleux Amaya A01644977
#include "Error.h"

Error::Error():Error("MES","0","00:00:00",0, 0, 0, 0, 0,"Inidentificable"){}

Error::Error(string mes, string dia, string hora, int pIp, int sIp, int tIp, int cIp, int puerto, string razon){
    this->mes = mes;
    this->dia = dia;
    this->hora = hora;
    this->pIp = pIp;
    this->sIp = sIp;
    this->tIp = tIp;
    this->cIp = cIp;
    this->puerto = puerto;
    this->razon = razon;
}

string Error::imprimeError(){
    return this->mes + " " + this->dia + " " + this->hora + " " + to_string(this-> pIp) + "." + to_string(this-> sIp) + "." + to_string(this-> tIp) + "." + to_string(this-> cIp) + ":" + to_string(this-> puerto) + " " + this->razon + "\n";
}

int Error::getPIp(){
    return this->pIp;
}

int Error::getSIp(){
    return this->sIp;
}

int Error::getTIp(){
    return this->tIp;
}

int Error::getCIp(){
    return this->cIp;
}

int Error::getPuerto(){
    return this->puerto;
}