#include "pochodna.h"
#include "zdrzewaznowunastringa.h"
/**
* \brief funkcja zamieniajaca nam drzewo na pochodną zwracaną w zmiennej typu string.
* Funkcja działa na zasadzie rekurencji i konstruuje pochodne według zaimplementowanych wzórów
* \param w jest to drzewo, na które została rozbita wpisana funckja przez użytkownika
* \return wynik zmienna typu string, funckja została zamieniona na pochodną jej
*/
string pochodna(drzewo *w)
{
    string wynik;
    if(w->dane=="+") ///pochodna sumy to suma pochodnych
    {
        wynik+= "(";
        wynik+=pochodna(w->lewo);
        wynik+="+";
        wynik+=pochodna(w->prawo);
        wynik+=")";
        return wynik;
    }
    if(w->dane=="-") ///pochodna róznicy to roznica pochodnych
    {
       wynik+= "(";
        wynik+=pochodna(w->lewo);
        wynik+="-";
        wynik+=pochodna(w->prawo);
        wynik+=")";
        return wynik;

    }
    if(w->dane=="*") ///pochodna iloczynu to pochodna1*funkcja2 + funkcja1*pochodna2
    {
        wynik="((" + pochodna(w->lewo)+ ")" + "*" +"("+ funkcja(w->prawo)+")"+"+"+"(" +pochodna(w->prawo)+ ")" + "*" +"("+funkcja(w->lewo)+ ")" + ")";

        return wynik;
    }
    if(w->dane=="/") ///pochodna ilorazu to (pochodna1*funkcja2-pochodna2*funkcja1)/(funkcja2)^2
    {
         wynik= "(("  + pochodna(w->lewo) + ")" + "*" + "("+ funkcja(w->prawo) + ")" + "-" + "(" + pochodna(w->prawo) + ")" + "*" + "(" + funkcja(w->lewo) + ")" +")" + "/" + "(" + "(" + funkcja(w->prawo) +")" + "^2)";
        return wynik;
    }


    if(w->dane=="^") ///pochodna potegowania to funkcja pomnożnona przez liczbę w potędze do potęgi zmniejszonej o 1 i pomnożona potem jeszcze przez pochodną wnętrza
    {
     wynik= "("+ funkcja(w->prawo) +  ")" + "*" + "(" +funkcja(w->lewo) + ")" + "^" + "("+ zamiana(funkcja(w->prawo)) + ")" + "*" + "(" +pochodna(w->lewo) + ")";
        return wynik;
    }
    if(w->dane=="sin") ///pochodne trygonometryczne + logarytmu naturalnego to wzór z wnętrzem * pochodna wnętrza
    {
        wynik = "cos(" + funkcja(w->lewo) + ")" + "*" + "(" + pochodna(w->lewo) + ")";
         return wynik;
    }
    if(w->dane=="cos")
    {
        wynik = "(-sin(" + funkcja(w->lewo) + ")" + "*" + "(" + pochodna(w->lewo) + "))";
         return wynik;
    }
    if(w->dane=="tg")
    {
        wynik = "(1/(cos(" + funkcja(w->lewo) + "))^2)" + "*" + "(" + pochodna(w->lewo) + ")";
         return wynik;
    }
    if(w->dane=="ctg")
    {
        wynik = "(-1/(sin(" + funkcja(w->lewo) + "))^2)" + "*" + "(" + pochodna(w->lewo) + ")";
         return wynik;
    }
    if(w->dane=="ln")
    {
        wynik = "(1/(" + funkcja(w->lewo) + "))" + "*" + "(" + pochodna(w->lewo) + ")";
         return wynik;
    }
    if(w->dane=="x")
     {
         return "1";
     }
     return "0";
     return w->dane;
}
