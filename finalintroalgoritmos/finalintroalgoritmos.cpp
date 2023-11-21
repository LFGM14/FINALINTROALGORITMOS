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
int rondas = 1;

void gameStart() {
    int scorePositionX = 0; int scorePositionY = 0; int xScoreTimer = 40; int yScoreTimer = 0;
    
    game(milisegundos, segundos, scorePositionX, scorePositionY, xScoreTimer, yScoreTimer, rondas);
   
    

}



int main() {
    Console::SetWindowSize(80, 25);
    srand(time(NULL));
    
    gameStart();

    system("pause>0");
    return 0;
}
