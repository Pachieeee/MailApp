#include "Correo.h"
#include "Contenido.h"
#include "Inicializador.h"

class EnviarCorreoQueue{
    private:
        ListaDoble<Contenido*>* enviado;
        Inicializador init;
        int idUsuario;
        Contenido *front;
        Contenido *back;
        Inicializador guardar;
    public:
        EnviarCorreoQueue(int id){
            front = back = nullptr;
            enviado = new ListaDoble<Contenido*>();
            this->idUsuario = id;
        }

        bool isEmpty(){
            if (back == nullptr && front == nullptr) return true;
            else return false;
        }

        void iniciarContenidoEnviado() {
            cout << "\n Cargando correos...";
            string direccion = "BD/" + to_string(idUsuario) + ".txt";
            init.inicializarCorreo(enviado, direccion);
            cout << "Correo enviado cargado!";
        }

        string obtenerFechaActual() {
            time_t t = time(nullptr);
            tm* now = localtime(&t);

            string fechaActual = to_string(now->tm_mday) + "/" + to_string(now->tm_mon + 1) + "/" + to_string(now->tm_year + 1900);

            cout << "Fecha actual: " << fechaActual << endl;
            return fechaActual;
        }

        void enqueue(int IDAutor){
            cout << "Enviar correo con cola!" << endl;
            Contenido *temp = new Contenido();
            char confirmation;
            string tipo, autor, correoAutor, correoDestino, asunto, mensaje;
            string fechaEnvio = obtenerFechaActual();
            
            cout << "\t\t\t\t Correo del Destinatario: ";
            cin >> correoDestino;
            cout << "\t\t\t\t----------" << endl;
            cout << "\t\t\t\t Asunto: ";
            cin >> asunto;
            cout << "\t\t\t\t Mensaje: ";
            cin >> mensaje;
            cout << "\t\t\t\t----------" << endl;
            cout << "\t\t\t\t Presiona 'Y' para enviar, o 'N' para cancelar" << endl;
            cout << "\t\t\t\t ", cin >> confirmation;
            temp->next = NULL;

            if (confirmation == 'y' || confirmation == 'Y'){
                if (isEmpty()){
                    front = back =  new Contenido(tipo, autor, correoAutor, correoDestino, asunto, mensaje, fechaEnvio);;
                }
                else{
                    back->next = new Contenido(tipo, autor, correoAutor, correoDestino, asunto, mensaje, fechaEnvio);
                    back->next->prev = back;
                    back = back->next;
                }
            cout << "\t\t\t\t El mensaje se está enviando..." << endl;                
            guardar.guardarCorreo(
                IDAutor + "," + tipo + "," + autor + "," + correoAutor + "," + correoDestino + "," + asunto + "," + mensaje + "," + fechaEnvio 
                ,
                IDAutor
            );
			cout << "\nEl mensaje fue enviado!\n";
            } else if (confirmation == 'n' || confirmation == 'N'){
                temp = NULL;
                cout << "\t\t\t\t Mensaje cancelado." << endl;
            }
            else{
                cout << "\t\t\t\t Error de caracter." << endl;
                temp = NULL;
            }

            cout << "\t\t\t\t Presiona cualquier tecla para regresar al menu." << endl;
        }

        void dequeue(){
            Contenido *temp = front;
            if (isEmpty())
            {
                cout << "\t\t\t\t No hay ningún mensaje en cola." << endl;
                cout << "\t\t\t\t Presiona cualquier tecla para regresar al menu." << endl;
                return;
            }
            else if (front == back)
            {
                front = back = NULL;
            }
            else
            {
                front = front->next;
            }
            cout <<"\t\t\t\t No hay más mensajes." << endl;
            delete temp;
            cout << "\t\t\t\t Presiona cualquier tecla para regresar al menu." << endl;
        }

        void displayFront(){
            Contenido *temp = front;
            cout << "Mensaje a punto de enviarse:";
            if (isEmpty()){
                cout << "\t\t\t\t Cola de mensajes vacia." << endl;
                cout << "\t\t\t\t Presiona cualquier tecla para regresar al menu." << endl;
                return;
            }
            temp->getContenido();
            // temp = temp->next;
            cout << "\t\t\t\t Presiona cualquier tecla para regresar al menu." << endl;
        }

};