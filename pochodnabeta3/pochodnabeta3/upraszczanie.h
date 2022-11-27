/**
* \file upraszczanie.h
* \brief zawiera szereg funkcji pozwalających uprościć w pewnych przypadkach zwracaną pochodną.
*/
#ifndef UPRASZCZANIE_H
#define UPRASZCZANIE_H
#include <string>
#include "drzewo.h"
#include <sstream>
#include <cmath>
string upraszczanie(drzewo *w);
void  skracanie(drzewo *w);
string calosc(drzewo *w);

#endif // UPRASZCZANIE_H
