//Héctor Eduardo Ayala Gudiño A01638996
//Luis Fernando Rojo Valdes A01640584
#include "Error.h"
#include "Registro.h"

// g++ main.cpp Registro.cpp Error.cpp && ./a.out
// g++ main.cpp Error.cpp Registro.cpp && .\a.exe

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
    Registro r1;
    r1.leerRegistro();
    //r1.ordenar();
    r1.crearArchivo();
    
    while(true){
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
        
        r1.crearArchivoEspecifico(busqI, busqF);
        cout<< "Archivo creado con exito"<<endl;
        cout << "Desea realizar otra busqueda? (s/n)" << endl;
        string respuesta;
        cin >> respuesta;
        if (respuesta != "s") {
            break;
        }
        cin.ignore();
    }

    return 0;
}
