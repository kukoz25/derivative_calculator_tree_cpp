/**
* \file drzewo.h
* \brief tworzy drzewo i zawiera kilka funkcji dotyczących drzewa.
*/
#ifndef DRZEWO_H
#define DRZEWO_H
#include <string>
#include <iostream>
using namespace std;
/**
* Standardowa struktura drzewa.
*/
struct drzewo{
    string dane;
    drzewo *lewo;
    drzewo *prawo;
};
drzewo *tworzenie();
void usuwanie(drzewo *w);
void usuwaniegalezi(drzewo *w);
#endif // DRZEWO_H
