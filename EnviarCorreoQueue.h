#include "Correo.h"
#include "Contenido.h"
#include <fstream>
#include <sstream>
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

        string obtenerFechaActual() {
            time_t t = time(nullptr);
            tm* now = localtime(&t);

            string fechaActual = to_string(now->tm_mday) + "/" + to_string(now->tm_mon + 1) + "/" + to_string(now->tm_year + 1900);

            cout << "Fecha actual: " << fechaActual << endl;
            return fechaActual;
        }

        // void iniciarContenidoEnviado() {
        //     cout << "\n Cargando correos...";
        //     string direccion = "BD/" + to_string(idUsuario) + ".txt";
        //     init.inicializarCorreo(enviado, direccion);
        //     cout << "Correo enviado cargado!";
        // }

        string obtenerTipoCorreo(string esAliadoPalestino){
            if (esAliadoPalestino == "NO") return "S";
            else return "P";
        }

        void enqueue(int idAutor, string esAliadoPalestino, string correoAutor, string apellidoAutor){
            cout << "Enviar correo con cola!" << endl;
            Contenido *temp = new Contenido();
            string correoDestino, asunto, mensaje, confirmation;
            string fechaEnvio = obtenerFechaActual();
            string tipo = obtenerTipoCorreo(esAliadoPalestino);

            cout << "\t\t\t\t Correo del Destinatario: ";
            cin.ignore(); // Ignorar el carácter de nueva línea pendiente en el búfer
            getline(cin, correoDestino); // Utilizar getline para leer toda la línea, incluyendo espacios
            cout << "\t\t\t\t----------" << endl;

            cout << "\t\t\t\t Asunto: ";
            //cin.ignore(); // Ignorar el carácter de nueva línea pendiente en el búfer
            getline(cin, asunto); // Utilizar getline para leer toda la línea, incluyendo espacios

            cout << "\t\t\t\t Mensaje: ";
            //cin.ignore(); // Ignorar el carácter de nueva línea pendiente en el búfer
            getline(cin, mensaje); // Utilizar getline para leer toda la línea, incluyendo espacios
            cout << "\t\t\t\t----------" << endl;
            cout << "\t\t\t\t Presiona 'Y' para enviar, o 'N' para cancelar" << endl;
            //cin.ignore(); // Ignorar el carácter de nueva línea pendiente en el búfer
            getline(cin, confirmation); // Utilizar getline para leer toda la línea, incluyendo espacios            temp->next = NULL;
            confirmation.erase(confirmation.find_last_not_of(" \n\r\t") + 1); // Eliminar espacios y nueva línea al final

            cout << " OK : " << correoDestino << " / " << asunto << " / " << mensaje << endl;
            
            // if (isEmpty()){
            //     front = back =  new Contenido(tipo, autor, correoAutor, correoDestino, asunto, mensaje, fechaEnvio);;
            // }
            // else{
            //     back->next = new Contenido(tipo, autor, correoAutor, correoDestino, asunto, mensaje, fechaEnvio);
            //     back->next->prev = back;
            //     back = back->next;
            // }
            ifstream buscarID;
            int idDestino;
            buscarID.open("BD/Cuentas.csv", ios::in);
            if (buscarID.is_open()) {
                string linea;
                string id, cargo, apellido, correo;

                while (getline(buscarID, linea)) {
                    stringstream stream(linea);
                    getline(stream, id, ',');
                    getline(stream, cargo, ',');
                    getline(stream, apellido, ',');
                    getline(stream, correo, ',');

                    if (correo == correoDestino) {
                        idDestino = stoi(id);
                        break;
                    }
                }
            }
            cout << "\t\t\t\t El mensaje se está enviando..." << endl;
            string line = to_string(idDestino) + "|" + tipo + "|" + apellidoAutor + "|" + correoAutor + "|" + correoDestino + "|" + asunto + "|" + mensaje + "|" + fechaEnvio;
            cout << line;

            ofstream test;
            test.open("BD/Correos.csv", ios::app);
            //! doesnt work u.u
            test << line << endl;
            test.close();
            //guardar.guardarCorreo(line,IDAutor);
            cout << "\nEl mensaje fue enviado!\n";

            // if (confirmation == "y" || confirmation == "Y"){
            //     cout << "OK"<<endl;
            //     if (isEmpty()){
            //         front = back =  new Contenido(tipo, autor, correoAutor, correoDestino, asunto, mensaje, fechaEnvio);;
            //     }
            //     else{
            //         back->next = new Contenido(tipo, autor, correoAutor, correoDestino, asunto, mensaje, fechaEnvio);
            //         back->next->prev = back;
            //         back = back->next;
            //     }
            //     cout << "\t\t\t\t El mensaje se está enviando..." << endl;                
            //     guardar.guardarCorreo(
            //         IDAutor + "," + tipo + "," + autor + "," + correoAutor + "," + correoDestino + "," + asunto + "," + mensaje + "," + fechaEnvio 
            //         ,
            //         IDAutor
            //     );
            //     cout << "\nEl mensaje fue enviado!\n";
            // } 
            // else if (confirmation == "n" || confirmation == "N"){
            //     temp = NULL;
            //     cout << "\t\t\t\t Mensaje cancelado." << endl;
            // }
            // else{
            //     cout << "\t\t\t\t Error de caracter." << endl;
            //     temp = NULL;
            // }
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