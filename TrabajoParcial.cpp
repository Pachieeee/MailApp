#include <iostream>
#include <fstream>
#include <string>
#include <functional>
#include <sys/stat.h> // Para mkdir en sistemas Unix/Linux

using namespace std;

#include "MailApp.h"
#include "Cuenta.h"
#include "ListaCuenta.h"
#include "CrearCuenta.h"
#include "Inicializador.h"

int main()
{
    MailApp* start = new MailApp;
    start->Run();
    return 0;    
}