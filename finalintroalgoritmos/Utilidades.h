#pragma once

#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;
using namespace System;

void setxy(float x, float y)
{
    Console::SetCursorPosition(x, y);
}

void clear_screen() {
    system("cls");
}

void changeColor(int x) {

    switch (x) {

    case 0:

        Console::ForegroundColor = ConsoleColor::White;

        break;

    case 1:

        Console::ForegroundColor = ConsoleColor::Yellow;

        break;

    case 2:

        Console::ForegroundColor = ConsoleColor::Blue;

        break;

    case 3:

        Console::ForegroundColor = ConsoleColor::Red;

        break;

    case 4:

        Console::ForegroundColor = ConsoleColor::Green;

        break;

    case 5:

        Console::ForegroundColor = ConsoleColor::DarkBlue;

        break;

    case 6:

        Console::ForegroundColor = ConsoleColor::DarkGreen;

        break;

    case 7:

        Console::ForegroundColor = ConsoleColor::DarkCyan;

        break;

    case 8:

        Console::ForegroundColor = ConsoleColor::DarkRed;

        break;

    case 9:

        Console::ForegroundColor = ConsoleColor::DarkMagenta;

        break;

    case 10:

        Console::ForegroundColor = ConsoleColor::DarkYellow;

        break;

    case 11:

        Console::ForegroundColor = ConsoleColor::Gray;

        break;

    case 12:

        Console::ForegroundColor = ConsoleColor::DarkGray;

        break;

    case 13:

        Console::ForegroundColor = ConsoleColor::Cyan;

        break;

    case 14:

        Console::ForegroundColor = ConsoleColor::Magenta;

        break;

    case 15:
        Console::ForegroundColor = ConsoleColor::Black;

    }
}
