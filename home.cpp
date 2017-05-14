#include <iostream>
#include <stdlib.h>
#include <fstream>

using namespace std;

const int ARRAY_COUNT = 100;

void readFile()
{
    string toDoList[ARRAY_COUNT][ARRAY_COUNT];

    ifstream fileObject("./ToDoList.vito");

    string tempText;
    int countFirst = -1;
    int countSecond = 0;
    while (fileObject)
    {
        fileObject >> tempText;
        if (tempText == "#")
        {
            countFirst++;
            countSecond = 0;
        }

        toDoList[countFirst][countSecond] = tempText;
        countSecond++;
    }

    // int countObject = 0;
    // for (int i = 0; i < ARRAY_COUNT; i++)
    // {
    //     for (int j = 0; j < ARRAY_COUNT; j++)
    //     {
    //         if (toDoList[i][0] != "#")
    //         {
    //             break;
    //         }

    //         //cout << toDoList[i][j] << " ";
    //     }

    //     if (toDoList[i][0] != "#")
    //     {
    //         break;
    //     }

    //     countObject++;
    //     //cout << endl;
    // }

    // cout << endl
    //      << "Listenizde Bulunan Not Sayısı : " << countObject << endl;

    cout << endl
         << "Listenizde Bulunan Not Sayısı : " << countFirst + 1 << endl;

    string command;
    while (true)
    {
        cout << endl
             << "Komut girin : ";
        cin >> command;

        if (command == "listele")
        {
            for (int i = 0; i < ARRAY_COUNT; i++)
            {
                for (int j = 0; j < ARRAY_COUNT; j++)
                {
                    if (toDoList[i][0] != "#")
                    {
                        break;
                    }

                    cout << toDoList[i][j] << " ";
                }

                if (toDoList[i][0] != "#")
                {
                    break;
                }

                cout << endl;
            }
        }
        else if (command == "exit")
        {
            break;
        }
    }
}

int main()
{
    readFile();
    cin.get();
}