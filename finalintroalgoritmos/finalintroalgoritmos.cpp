#include "pch.h"
#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "Utilidades.h"
#include "Game.h"
#define FILAS 25
#define COLUMNAS 80

using namespace System;
using namespace std;
int milisegundos = 0;
int segundos = 0;

void gameStart() {
    while (1) {
        drawMap(map);

    }
    

}



int main() {
    Console::SetWindowSize(80, 25);
    srand(time(NULL));
    score(milisegundos, segundos, 0, 0);
    


    system("pause>0");
    return 0;
}
