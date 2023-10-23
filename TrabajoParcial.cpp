#include <iostream>
#include <fstream>
#include <string>
#include <functional>
#include <stack>
// #include <conio.h>
#include <sys/stat.h> // Para mkdir en sistemas Unix/Linux
#include <regex>s
#include <sstream>	//stream

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