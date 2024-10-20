//Héctor Eduardo Ayala Gudiño A01638996
//Luis Fernando Rojo Valdes A01640584
// Sebastian Alejandro Veilleux Amaya A01644977
#include "Error.h"
#include "Bitacora.h"

// g++ main.cpp Bitacora.cpp Error.cpp && ./a.out
// g++ main.cpp Error.cpp Bitacora.cpp && .\a.exe

//Funcion para validar el input de la IP
bool isValidIP(string busq) {

    regex datePattern("^\\d{1,3}\\.\\d{1,3}\\.\\d{1,3}\\.\\d{1,3}$");
    if (!regex_match(busq, datePattern)) {
        return false;
    }
    
    return true;
}

int main()
{
    Bitacora b1;
    b1.leerBitacora();
    b1.ordenar();
    b1.crearArchivo();
    string respuesta;
    
    while(respuesta != "s"){
        string busqI, busqF;
        do {
            std::cout << "Teclee la IP de inicio de la busqueda (###.###.###.###): " << std::endl;
            std::getline(cin, busqI);
            if (!isValidIP(busqI)) {
                std::cout << "IP no válida. Por favor, intente de nuevo." << std::endl;
            }
        } while (!isValidIP(busqI));
        do {
            std::cout << "Teclee la IP de fin de la busqueda (###.###.###.###): " << std::endl;
            std::getline(cin, busqF);
            if (!isValidIP(busqF)) {
                std::cout << "IP no válida. Por favor, intente de nuevo." << std::endl;
            }
        } while (!isValidIP(busqF));
        
        b1.crearArchivoEspecifico(busqI, busqF);
        cout<< "Archivo creado con exito"<<endl;
        cout << "Desea realizar otra busqueda? (s/n)" << endl;
        cin >> respuesta;
        cin.ignore();
    }

    return 0;
}
