// ferz_one.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;
int a[8]; //вертикаль
int b[8]; //горизонталь
int c1[15]; //Диагональ 1
int c2[15]; ////Диагональ 2
int map[8][8]; ////Диагональ 2
bool quit = false; // индикатор , что решение найдено
int arr[10];




int getPairXYDiagonal(int i, int j)
{
    // 
    if (i == 0 && j == 0) return 1407;
    if (i == 0 && j == 1) return 1306;
    if (i == 0 && j == 2) return 1205;
    if (i == 0 && j == 3) return 1104;
    if (i == 0 && j == 4)  return 1003;
    if (i == 0 && j == 5)  return 902;
    if (i == 0 && j == 6)  return 801;
    if (i == 0 && j == 7) {
        return 700;
    }

    if (i == 1 && j == 0) return 1308;
    if (i == 1 && j == 1) return 1207;
    if (i == 1 && j == 2) return 1106;
    if (i == 1 && j == 3) return 1005;
    if (i == 1 && j == 4)  return 904;
    if (i == 1 && j == 5)  return 803;
    if (i == 1 && j == 6) {
        return 702;
    }
    if (i == 1 && j == 7)  return 601;

    if (i == 2 && j == 0) return 1209;
    if (i == 2 && j == 1) return 1108;
    if (i == 2 && j == 2) return 1007;
    if (i == 2 && j == 3) return 906;
    if (i == 2 && j == 4) return 805;
    if (i == 2 && j == 5) return 704;
    if (i == 2 && j == 6) return 603;
    if (i == 2 && j == 7) return 502;

    if (i == 3 && j == 0) return 1110;
    if (i == 3 && j == 1) return 1009;
    if (i == 3 && j == 2) return 908;
    if (i == 3 && j == 3) return 807;
    if (i == 3 && j == 4) return 706;
    if (i == 3 && j == 5) return 605;
    if (i == 3 && j == 6) return 504;
    if (i == 3 && j == 7) return 403;

    if (i == 4 && j == 0) return 1011;
    if (i == 4 && j == 1) return 910;
    if (i == 4 && j == 2) return 809;
    if (i == 4 && j == 3) return 708;
    if (i == 4 && j == 4) return 607;
    if (i == 4 && j == 5) return 506;
    if (i == 4 && j == 6) return 405;
    if (i == 4 && j == 7) return 304;

    if (i == 5 && j == 0) return 912;
    if (i == 5 && j == 1) return 811;
    if (i == 5 && j == 2) return 710;
    if (i == 5 && j == 3) return 609;
    if (i == 5 && j == 4) return 508;
    if (i == 5 && j == 5) return 407;
    if (i == 5 && j == 6) return 306;
    if (i == 5 && j == 7) return 205;

    if (i == 6 && j == 1) return 813;
    if (i == 6 && j == 0) return 712;
    if (i == 6 && j == 2) return 611;
    if (i == 6 && j == 3) return 510;
    if (i == 6 && j == 4) return 409;
    if (i == 6 && j == 5) return 308;
    if (i == 6 && j == 6) return 207;
    if (i == 6 && j == 7) return 106;

    if (i == 7 && j == 1) return 714;
    if (i == 7 && j == 0) return 613;
    if (i == 7 && j == 2) return 512;
    if (i == 7 && j == 3) return 411;
    if (i == 7 && j == 4) return 310;
    if (i == 7 && j == 5) return 209;
    if (i == 7 && j == 6) return 108;
    if (i == 7 && j == 7) return 7;


}

void printField()
{
    for (int i = 0; i <= 7; i++)
    {
        for (int j = 0; j <= 7; j++) {
            if (map[i][j] == 100) { std::cout << "F"; }
            else { std::cout << "0"; }

        }
        std::cout << endl;
    }
    std::cout << endl;
}
bool dropFerz(int i, int j, bool del) // пытаемся поставить ферзя . если можно , то ставим , закрашивая битые клетки , либо убираем ферзя если del истина
{
    double diagonalXY = getPairXYDiagonal(i, j);
    int a1 = (int)(diagonalXY / 100);
    int b1 = ((diagonalXY / 100) - a1) * 100;

    if (del) {
        map[i][j] = 0;
        a[i]--;
        b[j]--;
        c1[a1]--;
        c2[b1]--;
        //cout << "Delete ferz" << endl;
        //printField();

    }
    else
        if (a[i] == 0 && b[j] == 0 and c1[a1] == 0 && c2[b1] == 0)
        {
            map[i][j] = 100;
            a[i]++;
            b[j]++;
            c1[a1]++;
            c2[b1]++;
            //cout << "Add ferz" << endl;
            if (i == 7) {
                // printField();

            }
            return true;
        }
        else return false;



}
bool tryFerz(int i) {
    int j = 0;
    bool result = false;
    bool tryF;


    /*if (i >= 8) {
        quit = true;
        return true;
    }*/
    if (quit != true) {
        do {
            tryF = dropFerz(i, j, false);

            if (i == 7 && tryF) {
                quit = true;
                return true;
            }

            if (tryF) {

                result = tryFerz(i + 1);
                if (!result && !quit) {
                    dropFerz(i, j, true); //удаляем ферзя

                } // убираем ферзя
            }
            j++;
        } while (j <= 7 && quit == false);

    }
    return false;



}


int main()
{
    tryFerz(0);
    printField();


}

