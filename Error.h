//Héctor Eduardo Ayala Gudiño A01638996
//Luis Fernando Rojo Valdes A01640584
#ifndef ERROR_H
#define ERROR_H

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <stdexcept>
#include <ctime>
#include <regex>
#include <algorithm>
using namespace std;

class Error{
    private:
        string mes;
        string dia;
        string hora;
        int pIp;
        int sIp;
        int tIp;
        int cIp;
        int puerto;
        string razon;
    public:
        Error();
        Error(string mes, string dia, string hora, int pIp, int sIp, int tIp, int cIp, int puerto, string razon);
        string imprimeError();
        int getPIp();
        int getSIp();
        int getTIp();
        int getCIp();
        int getPuerto();
        
};

#endif