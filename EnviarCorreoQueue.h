#include "Correo.h"


class EnviarCorreoQueue{
    private:
        Correo *front;
        Correo *back;
    public:
        EnviarCorreoQueue(){
            front = back = nullptr;
        }

        bool isEmpty(){
            if (back == nullptr && front == nullptr) return true;
            else return false;
        }
        void enqueue(){
            cout << "Enviar correo con cola!" << endl;
            Correo *temp = new Correo();
            char confirmation;
            

        }
        void dequeue(){
            
        }
};