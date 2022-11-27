/**
* \file rozbijanie.h
* \brief zawiera funkcje odpowiadające za rozbicie zmiennej typu string na drzewo w odpowiednej kolejności.
*/
#ifndef ROZBIJANIE_H
#define ROZBIJANIE_H
#include <string>
#include "drzewo.h"
bool dodawanie(string s, drzewo *korzen);
bool odejmowanie(string s, drzewo *korzen);
bool mnozenie(string s, drzewo *korzen);
bool  dzielenie(string s, drzewo *korzen);
bool potegowanie(string s, drzewo *korzen);
bool innefunckje(string s, drzewo *korzen);
string usuwanienawiasowfunkcja(string s);
void rozbijanie(string s, drzewo *korzen);

#endif // ROZBIJANIE_H

