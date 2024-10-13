//Héctor Eduardo Ayala Gudiño A01638996
//Luis Fernando Rojo Valdes A01640584
// Sebastian Alejandro Veilleux Amaya A01644977
#include "Registro.h"
#include "Error.h"

Registro::Registro() : head(nullptr), tail(nullptr), size(0) {}

/*Registro::~Registro() {
    MyNodoLL* current = head;
    while (current != nullptr) {
        MyNodoLL* next = current->next;
        delete current->error;
        delete current;
        current = next;
    }
}*/

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

MyNodoLL* Registro::Merge(MyNodoLL* left, MyNodoLL* right) {
    if (left == nullptr) return right;
    if (right == nullptr) return left;

    if(left->error->getPIp() < right->error->getPIp()){
        left->next = Merge(left->next, right);
        return left;
    }else if(left->error->getPIp() == right->error->getPIp()){
        if(left->error->getSIp() < right->error->getSIp()){
            left->next = Merge(left->next, right);
            return left;
        }else if(left->error->getSIp() == right->error->getSIp()){
            if(left->error->getTIp() < right->error->getTIp()){
                left->next = Merge(left->next, right);
                return left;
            }else if(left->error->getTIp() == right->error->getTIp()){
                if(left->error->getCIp() < right->error->getCIp()){
                    left->next = Merge(left->next, right);
                    return left;
                }else if(left->error->getCIp() == right->error->getCIp()){
                    if(left->error->getPuerto() < right->error->getPuerto()){
                        left->next = Merge(left->next, right);
                        return left;
                    }else{
                        right->next = Merge(left, right->next);
                        return right;  
                    }
                }else{
                    right->next = Merge(left, right->next);
                    return right;  
                }
            }else{
                right->next = Merge(left, right->next);
                return right;  
            }
        }else{
            right->next = Merge(left, right->next);
            return right;
        }
    }else{
        right->next = Merge(left, right->next);
        return right;
    }
}


MyNodoLL* Registro::findMiddle(MyNodoLL* head){
    if (head == nullptr || head->next == nullptr)
        return head;
    
    MyNodoLL* slow = head;
    MyNodoLL* fast = head->next;

    while(fast != nullptr && fast->next != nullptr){
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

MyNodoLL* Registro::MergeSort(MyNodoLL* head) {
    // caso base: si la lista está vacía o tiene solo un nodo, ya está ordenada
    if (head == nullptr || head->next == nullptr)
        return head;

    MyNodoLL* middle = findMiddle(head);
    MyNodoLL* right = middle->next;
    middle->next = nullptr;

    MyNodoLL* left = MergeSort(head);
    right = MergeSort(right);

    return Merge(left, right);
}

void Registro::ordenar(){
    this-> head = MergeSort(this->head);
}

void Registro::ipAInt(string busq, int* pIp, int* sIp, int* tIp, int* cIp){
    istringstream split(busq);
    string strPIp, strSIp, strTIp, strCIp;

    getline(split, strPIp, '.');
    *pIp = stoi(strPIp);
    getline(split, strSIp, '.');
    *sIp = stoi(strSIp);
    getline(split, strTIp, '.');
    *tIp = stoi(strTIp);
    getline(split, strCIp, '\n');//va a terminar en : o en \n
    *cIp = stoi(strCIp);
}

MyNodoLL* Registro::sequentialSearch(string busq){
    int pIp;
    int sIp;
    int tIp;
    int cIp;

    ipAInt(busq, &pIp, &sIp, &tIp, &cIp);

    MyNodoLL* temp = this->head;
    while(temp != nullptr){
        if(temp->error->getPIp() == pIp){
            if(temp->error->getSIp() >= sIp){
                if(temp->error->getTIp() >= tIp){
                    if(temp->error->getCIp() >= cIp){
                        return temp;
                    }else if(temp->error->getCIp() > cIp){
                        return temp;
                    }
                }else if(temp->error->getTIp() > tIp){
                    return temp;
                }
            }else if(temp->error->getSIp() > sIp){
                return temp;
            }
        }else if(temp->error->getPIp() > pIp){
            return temp;
        }
        temp=temp->next;
    }
    return nullptr;
}

/*MyNodoLL* Registro::sequentialSearchFin(string busq, MyNodoLL* nodo){
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
}*/

void Registro::crearArchivo(){
    MyNodoLL* current; 
    current = head;
    ofstream file;
    file.open("bitacoraOrdenadaIP-Eq4.txt");
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
    current = sequentialSearch(busqI);
    if (current == nullptr){
        current = this->head;
    }

    int pIpF;
    int sIpF;
    int tIpF;
    int cIpF;

    ipAInt(busqF, &pIpF, &sIpF, &tIpF, &cIpF);

    ofstream file;

    file.open("salida" + strNumBusq + "-Eq4.txt");
    while (current != nullptr) { 
        if (current->error->getPIp() < pIpF) { 
            file << current->error->imprimeError(); 
        } else if (current->error->getPIp() == pIpF) { 
            if (current->error->getSIp() < sIpF) { 
                file << current->error->imprimeError(); 
            } else if (current->error->getSIp() == sIpF) { 
                if (current->error->getTIp() < tIpF) { 
                    file << current->error->imprimeError(); 
                } else if (current->error->getTIp() == tIpF) { 
                    if (current->error->getCIp() < cIpF) { 
                        file << current->error->imprimeError(); 
                    } else { 
                        break; 
                    } 
                } else { 
                    break; 
                } 
            } else { 
                break; 
            } 
        } else { 
            break; 
        } 
        current = current->next; 
    } 
    this->numBusq ++;
    file.close();
}
