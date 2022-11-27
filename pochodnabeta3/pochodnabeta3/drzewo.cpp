#include "drzewo.h"
using namespace std;
/**
* \brief Standardowa funkcja tworząca korzeń drzewa.
*/
drzewo *tworzenie(){
    drzewo *element= new drzewo;
    element->lewo=NULL;
    element->prawo=NULL;
    return element;
};
/**
*  \brief Standardowa funkcja usuwająca drzewo.
*/
void usuwanie(drzewo *w)
    {
    if(w->lewo!=NULL)
    {
        usuwanie(w->lewo);
    }
    if(w->prawo!=NULL)
    {
        usuwanie(w->prawo);
    }
    delete  w;
}
/**
* \brief Funkcja potrzebna do usuwania potrzególnych gałęzi drzewa.
* Potrzebna do "upraszczania", usuwa niepotrzebne części drzewa
*/
void usuwaniegalezi(drzewo *w)
{
    if(w->lewo!=NULL)
    {
        usuwanie(w->lewo);
        w->lewo=NULL;
    }
    if(w->prawo!=NULL)
    {
        usuwanie(w->prawo);
        w->prawo=NULL;
    }
}

