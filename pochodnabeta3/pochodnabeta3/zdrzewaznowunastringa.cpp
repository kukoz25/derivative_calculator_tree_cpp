#include "zdrzewaznowunastringa.h"
/**
* Funkcja pozwala zapisac nam fukncje bez jej pochodnej, na przyklad przy mnozeniu czy dzieleniu mam kawalki funkcji, ktore zapisujemy po prostu albo wnetrza logarytmu czy funkcji trygonometrycznych
* \param drzewo potrzebny, by je zamienić znowu na zmienną tyu string
*  \return zwraca nam funkcję
*/
string funkcja(drzewo *w)
{
    if(w->dane=="sin" ||w->dane=="cos" || w->dane=="tg" || w->dane=="ctg"||w->dane=="ln")
    {
       string wynik=w->dane + "(" + funkcja(w->lewo) + ")"; /// składa nam drzewo w calość
       return wynik;
    }
    if(w->dane=="+" ||w->dane=="-")
    {
    string wynik=funkcja(w->lewo) + w->dane +funkcja(w->prawo); // składa nam drzewo w calość
    return wynik;
     return wynik;
    }
    if(w->dane=="*"|| w->dane=="/")
    {
         string wynik="";
         if(w->lewo->dane=="+" || w->lewo->dane=="-") ///zachowanie kolejności działań
         {
             wynik=wynik+ "(" + funkcja(w->lewo) + ")";
         }
         else
             wynik+=funkcja(w->lewo);
         wynik+=w->dane;
         if(w->prawo->dane=="+" || w->prawo->dane=="-")
         {
             wynik=wynik+ "(" + funkcja(w->prawo) + ")";
         }
         else
             wynik+=funkcja(w->prawo);
         return wynik;
    }
        if(w->dane=="^")
        {
            string wynik="";
            if(w->lewo->dane=="+" || w->lewo->dane=="-" || w->lewo->dane=="*" || w->lewo->dane=="/") ///zachowanie kolejności działań
            {
                wynik=wynik+ "(" + funkcja(w->lewo) + ")";
            }
            else
                wynik+=funkcja(w->lewo);
            wynik+=w->dane;
            if(w->prawo->dane=="+" || w->prawo->dane=="-" || w->prawo->dane=="*" || w->prawo->dane=="/")
            {
                wynik=wynik+ "(" + funkcja(w->prawo) + ")";
            }
            else
                wynik+=funkcja(w->prawo);
            return wynik;
        }
    return w->dane;
};
/**
* Funkcja potrzebna, by w potegowaniu odjąć i zapisać dobrze do której potegi jest wyrażenie
{
*/
string zamiana(string e) {
    double x;
istringstream isstream(e);
isstream >> x;
if(isstream.fail())
{
    cout << "blad zamiany"<< endl;
}
x=x-1;
ostringstream osstream;
osstream << x;
return osstream.str(); ///tak dziala biblioteka sstream
}

