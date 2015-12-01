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

void opengreeting::printscreen (char ascii [][80], int largeNumber)
{
    pause(largeNumber);
    system("cls");

    for (int i = 0; i < 20; i++)
    {
        cout<<endl<<"\t";
        for (int y = 0; y < 80; y++)
        {
            cout<<ascii[i][y];
        }
    }
}

void opengreeting::art (char ascii [][80])
{
    int greetingSpeed = 175;

    for (int i = 0; i < 10; i++)
    {
        ascii[i+10][40] = 'X';
        ascii[10-i][40] = 'X';
        printscreen(ascii, (0.75 * greetingSpeed));
    }

    for (int i = 0; i < 20; i++)
    {
        ascii[10][40+i] = 'X';
        ascii[10][40-i] = 'X';
        printscreen(ascii, (0.75 * greetingSpeed));
    }

    fillarray(ascii, ' ');
    printscreen(ascii, 0);

    char welcome[7] = {'W', 'E', 'L', 'C', 'O', 'M', 'E'};

    for (int i = 0; i < 7; i++)
    {
        ascii[11][37+i] = welcome[i];
        printscreen(ascii, (0.75 * greetingSpeed));
    }

    for (int i = 0; i < 7; i++)
    {
        ascii[12][37+i] = '.';
        printscreen(ascii, greetingSpeed);
    }
}

void opengreeting::pause(int largeNumber)
{
    for (int i = 0; i < largeNumber/10; i++)
    {
        //cout<<"tick ";
        for (int y = 0; y < largeNumber; y++)
        {
            for (int x = 0; x < largeNumber; x++)
            {
                for (int z = 0; z < largeNumber; z++)
                {
                    (y * x * i * z);
                }
            }
        }
    }
}
