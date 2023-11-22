#include <iostream>
#include <fstream>
#include <string>
#include <functional>
#include <stack>
// #include <conio.h>
#include <sys/stat.h> // Para mkdir en sistemas Unix/Linux
#include <regex>
#include <sstream>	//stream
#include <ctime>

using namespace std;
using namespace System;

#include "MailApp.h"
#include "Cuenta.h"
#include "ListaCuenta.h"
#include "CrearCuenta.h"
#include "Inicializador.h"

int main()
{
    Console::SetWindowSize(170, 45);
    MailApp* start = new MailApp;
    start->Run();
    return 0;    
}