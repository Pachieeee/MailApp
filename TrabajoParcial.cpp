#include <iostream>
#include <fstream>
#include <string>
#include <functional>
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