#include "opengreeting.h"


opengreeting::opengreeting()
{

}

void opengreeting::greetingPost()
{
    infoDisplay display;
    char input = ' ';
    fillarray(ascii, input);
    art(ascii);
}

void opengreeting::fillarray (char ascii [][80], char input)
{
    for (int i = 0; i < 20; i++)
    {
        for (int y = 0; y < 80; y++)
        {
            ascii[i][y] = input;
        }
    }

    ascii[10][40] = 'X';
}

void opengreeting::printscreen (char ascii [][80])
{
    usleep(50000);
    system("cls");

    for (int i = 0; i < 20; i++)
    {
        for (int y = 0; y < 80; y++)
        {
            cout<<ascii[i][y];
        }
    }
}

void opengreeting::art (char ascii [][80])
{
    for (int i = 0; i < 10; i++)
    {
        ascii[i+10][40] = 'X';
        ascii[10-i][40] = 'X';
        printscreen(ascii);
    }

    for (int i = 0; i < 20; i++)
    {
        ascii[10][40+i] = 'X';
        ascii[10][40-i] = 'X';
        printscreen(ascii);
    }

    fillarray(ascii, ' ');
    printscreen(ascii);

    char welcome[7] = {'W', 'E', 'L', 'C', 'O', 'M', 'E'};

    for (int i = 0; i < 7; i++)
    {
        ascii[11][37+i] = welcome[i];
        printscreen(ascii);
    }

    for (int i = 0; i < 7; i++)
    {
        ascii[12][37+i] = '.';
        printscreen(ascii);
    }
    sleep(1);
}
