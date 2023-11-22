#pragma once

#include "pch.h"
#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define FILAS 25
#define COLUMNAS 80
#define PAISES 10

using namespace System;
using namespace std;

typedef struct {
    string countryName;
    int score;
    bool active;
} country;
country c[PAISES];

string countries[PAISES] = { "PER","BRA","ARG","CHI","COL","VEN","ECU","URU","CUB","MEX" };

void bubbleSort(country arr[]) {
    for (int i = 0; i < PAISES - 1; i++) {
        for (int j = 0; j < PAISES - i - 1; j++) {
            if (arr[j].score > arr[j + 1].score) {
                // cambiar los elementos si estan en el orden incorrecto
                country temp = arr[j]; //estamos asignando todos los valores de la estructura al valor temporal
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void mapInfoAssigner(int rondas) {
       
    switch (rondas) {
    case 0: {
        for (int i = 0; i < PAISES; i++) {
            c[i].active = 1;
            c[i].countryName = countries[i];
        }
        //corremos el indice desde 1 porque el indice 0 es de nuestro jugador
        for (int i = 1; i < PAISES; i++) {

            c[i].score = rand() % 11 + 45;
        }
        
        break;
    }

    case 1: {
        
        // al perder el estado de activo ya no seran impresos en las pantallas de transicion
        for (int i = 0; i < 5; i++) {
            c[i].active = false;
        }
        for (int i = 1; i < PAISES; i++) {
            if (c[i].active == true) {
                c[i].score = rand() % 11 + 50;
            }
        }
       
        
        break;
    }

    case 2: {
        
        // al perder el estado de activo ya no seran impresos en las pantallas de transicion
        
        for (int i = 0; i < 2; i++) {
            c[i].active = false;
        }
        
        for (int i = 1; i < PAISES; i++) {
            if (c[i].active == true) {
                c[i].score = rand() % 11 + 55;
            }
        }
        break;
        }
    case 3: {
        for (int i = 0; i < PAISES; i++) {
            if (c[i].active == true) {
                c[i].score = rand() % 11 + 60;
            }
        }

    }
    case 4: {

    }
    }
}

//matriz e impresión del mapa
int map[FILAS][COLUMNAS]{ {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
{2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,0,0,0,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2},
{2,2,2,2,2,0,0,0,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,0,0,0,3,3,3,2,2,1,1,1,1,1,1,1,1,2,2,3,3,3,2,2,2,2,2,2,2,2,2,2,2,0,0,0,0,0,0,0,0,0,2,2,2,2,2,2,2,2,2,2,2,2},
{2,2,0,0,0,0,0,0,0,0,0,2,2,2,2,2,2,2,2,2,2,2,2,2,0,0,0,0,0,0,3,3,3,2,2,1,1,1,1,1,1,1,1,2,2,3,3,3,2,2,2,2,2,2,2,2,2,2,0,0,0,0,0,0,0,0,0,0,0,2,2,2,2,0,0,0,2,2,2,2},
{2,0,0,0,0,0,0,0,0,0,0,0,2,2,2,2,2,2,2,2,2,2,2,0,0,0,0,0,0,4,4,4,4,4,2,2,2,2,2,2,2,2,2,2,4,4,4,4,4,2,0,0,0,2,2,2,2,2,2,0,0,0,0,0,0,0,0,0,2,2,0,0,0,0,0,0,0,0,0,2},
{2,2,0,0,0,0,0,0,0,0,0,2,2,2,2,2,2,0,0,0,2,2,2,2,0,0,0,0,4,0,4,4,4,2,4,2,2,0,0,0,2,2,2,4,2,4,4,4,0,4,0,0,0,0,0,0,2,2,2,2,2,2,0,0,0,2,2,2,2,0,0,0,0,0,0,0,0,0,0,0},
{2,2,2,2,2,0,0,0,2,2,2,2,2,2,0,0,0,0,0,0,0,0,0,2,2,2,2,3,0,0,4,4,4,2,0,3,0,0,0,0,0,0,3,2,2,4,4,4,0,0,3,0,0,0,0,0,0,2,2,2,2,2,2,2,2,2,2,2,2,2,0,0,0,0,0,0,0,0,0,2},
{2,2,2,2,2,2,2,2,2,2,2,2,2,0,0,0,0,0,0,0,0,0,0,0,2,2,2,2,2,2,5,5,5,0,0,0,0,0,0,0,0,0,0,0,2,5,5,5,0,0,0,0,0,0,0,0,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,0,0,0,2,2,2,2},
{2,2,2,2,2,2,2,2,2,2,2,2,2,2,0,0,0,0,0,0,0,0,0,2,2,2,2,2,2,2,5,2,5,2,0,0,0,0,0,0,0,0,0,2,2,5,2,5,2,2,0,0,0,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2},
{2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,0,0,0,2,2,2,2,2,2,2,2,2,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,0,0,0,0,0,0,0,0,0,2,2,2,2,2,2},
{2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,0,1,1,1,1,1,1,1,0,2,2,2,2,2,2},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,2,2,2,2,2,1,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,2,9,9,9,2,1,0,0,0,0,0,0,0},
{0,0,0,0,3,3,3,0,8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,2,9,3,9,2,1,0,0,0,0,0,0,0},
{0,0,0,0,3,3,3,0,0,8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,2,9,9,9,2,1,0,0,0,0,0,0,0},
{0,0,0,9,9,9,9,9,0,0,8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,2,2,2,2,2,1,0,0,0,0,0,0,0},
{0,0,0,0,3,9,9,0,3,0,8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,0,0,0,0,0,0,0},
{0,0,0,0,9,3,1,1,1,3,8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,7,7,7,0,0,0,8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,10,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,7,2,7,0,0,8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,10,0,10,0,0,0,0,0,0,0,0,0},
{11,0,0,0,7,2,7,0,8,0,0,0,0,11,0,0,0,11,0,0,0,0,0,0,0,0,0,0,0,0,0,0,11,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,11,0,0,11,0,0,0,0,0,0,0,11,0,11,0,0,0,0,10,0,0,0,10,0,0,0,0,0,11,0,0},
{0,11,0,1,1,0,1,1,0,0,0,11,0,11,0,0,11,0,0,0,11,0,0,0,0,11,0,0,0,11,0,0,0,11,0,0,0,0,0,11,0,0,11,0,0,11,0,0,0,11,0,11,0,0,0,11,0,0,11,0,11,0,0,11,0,0,10,0,0,0,0,0,10,0,0,0,11,0,0,11},
{11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11},
{11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11},
{11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11}
};

void drawMap(int map[FILAS][COLUMNAS], int rondas)
{
    for (int i = 0; i < FILAS; i++)
    {
        for (int j = 0; j < COLUMNAS; j++)
        {
            setxy(j, i);
            if (map[i][j] == 0) changeColor(0);
            if (map[i][j] == 1) changeColor(15);
            if (map[i][j] == 2) changeColor(2);
            if (map[i][j] == 3) changeColor(1);
            if (map[i][j] == 4) changeColor(13);
            if (map[i][j] == 5) changeColor(14);
            if (map[i][j] == 7) changeColor(5);
            if (map[i][j] == 8) changeColor(10);
            if (map[i][j] == 9) changeColor(8);
            if (map[i][j] == 10) changeColor(10);
            if (map[i][j] == 11) changeColor(4);

            cout << (char)219;
        }
    }
    setxy(80, 0);
    cout << "Ronda " << rondas;
}

//matriz y pantalla de transiciones
int transition[FILAS][COLUMNAS]{ {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
{2,2,2,2,2,1,1,2,2,2,2,1,1,2,2,2,2,1,1,2,2,2,2,1,1,2,2,2,2,1,1,2,2,2,2,1,1,1,1,2,2,2,2,1,1,2,2,2,2,1,1,2,2,2,2,1,1,2,2,2,2,1,1,2,2,2,2,1,1,2,2,2,2,1,1,2,2,2,2,1},
{2,0,0,0,0,2,2,0,0,0,0,2,2,0,0,0,0,2,2,0,0,0,0,2,2,0,0,0,0,2,2,0,0,0,0,2,1,1,2,0,0,0,0,2,2,0,0,0,0,2,2,0,0,0,0,2,2,0,0,0,0,2,2,0,0,0,0,2,2,0,0,0,0,2,2,0,0,0,0,2},
{2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2},
{2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,2},
{2,1,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,2,2,1},
{2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,2},
{2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2},
{2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,2},
{2,1,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,2,2,1},
{2,1,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,2,2,1},
{2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,2},
{2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2},
{2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,2},
{2,1,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,2,2,1},
{2,1,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,2,2,1},
{2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,2},
{2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2},
{2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,2},
{2,1,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,2,2,1},
{2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,2},
{2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,1,1,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2},
{2,2,2,2,2,0,0,2,2,2,2,0,0,2,2,2,2,0,0,2,2,2,2,0,0,2,2,2,2,0,0,2,2,2,2,1,1,1,1,2,2,2,2,0,0,2,2,2,2,0,0,2,2,2,2,0,0,2,2,2,2,0,0,2,2,2,2,0,0,2,2,2,2,0,0,2,2,2,2,2},
{2,1,1,1,1,2,2,1,1,1,1,2,2,1,1,1,1,2,2,1,1,1,1,2,2,1,1,1,1,2,2,1,1,1,1,1,1,1,1,1,1,1,1,2,2,1,1,1,1,2,2,1,1,1,1,2,2,1,1,1,1,2,2,1,1,1,1,2,2,1,1,1,1,2,2,1,1,1,1,2},
{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1} };


void transitionScreen(int transition[FILAS][COLUMNAS], int rondas,int milisegundos, int segundos, int xScore, int yScore,
int xScoreTimer, int yScoreTimer) {
    

    for (int i = 0; i < FILAS; i++)
    {
        for (int j = 0; j < COLUMNAS; j++)
        {
            setxy(j, i);
            if (transition[i][j] == 0) changeColor(15);
            if (transition[i][j] == 1) changeColor(1);
            if (transition[i][j] == 2) changeColor(5);
            

            cout << (char)219;
        }
    }
    
    for (int i = 0; i < PAISES; i++) {
            changeColor(3);
            if (c[i].active == true) {
                setxy(25, 4 + i);
                cout << c[i].countryName << " - - - > " << c[i].score;
            }
    }
    
    system("pause");
      
}


void game(int xScore, int yScore, int xScoreTimer , int yScoreTimer, int xCountdown, int yCountdown, int rondas) {
    char tecla;
    int keyPress = 0;
    int milisegundos = 0;
    int segundos = 0;
    drawMap(map, rondas);
    mapInfoAssigner(rondas);
    setxy(60, 0);
    cout << "Ronda: " << rondas+1;
    while (1) {
        milisegundos++;
        if (milisegundos == 100) {
            setxy(xCountdown, yCountdown);
            switch (segundos) {
            case 0: {cout << "Ready?"; break; }
            case 1: {cout << "Set?!?"; break; }
            case 2: {cout << "GOOOOO"; break; }
            case 3: {cout << "PRESS X!"; break; }
            }
            segundos++;
            milisegundos = 0;
        }

        if (segundos == 4) break;
        _sleep(10);
    }
    segundos = 0;
    while (1) {
        
        if (_kbhit()) {
            tecla = _getch();

            if (tecla == 'X') keyPress++;
        }
        setxy(xScore, yScore);
        cout << "Puntaje: " << keyPress;
        milisegundos++;
        if (milisegundos == 90) {
            setxy(xScoreTimer, yScoreTimer);
            segundos++;
            cout << "Tiempo: " << segundos;
            milisegundos = 0;
        }
        
        if (segundos == 10) break;
        _sleep(10);
    }
    c[0].score = keyPress;
    bubbleSort(c);
    
    transitionScreen(transition, rondas,milisegundos, segundos,  xScore, yScore, xScoreTimer, yScoreTimer);
    rondas++;
    game( xScore, yScore, xScoreTimer, yScoreTimer, xCountdown, yCountdown, rondas);

}

