#include "upraszczanie.h"
/**
* Funkcja przesuwa gałęzie drzewa i w rezultacie je uprosic, potrzebna w skracaniu
* \param korzeń jest potrzebny, by drzewo zostało wypełnione
* \param s jest funkcją wczytaną od użytkownika
*/
void przesuwanie(drzewo *w, char d)
{
    drzewo *pom;
    if(d=='l') /// przesuwa lewa galaz do gory
    {
     w->dane=w->lewo->dane;
     pom=w->lewo;
     usuwanie(w->prawo);
     w->prawo=w->lewo->prawo;
     w->lewo=w->lewo->lewo;
     delete pom;

    }
    else /// przesuwa prawa galaz do gory
    {
        w->dane=w->prawo->dane;
        pom=w->prawo;
        usuwanie(w->lewo);
        w->lewo=w->prawo->lewo;
        w->prawo=w->prawo->prawo;
        delete pom;
    }
}
/**
* Funkcja upraszcza drzewo gałęzie drzewa
* \param drzewo potrzebne jest w ogóle drzewo by je można było skrócić
* \return zwaraca funckje maksymalnie skróconą
*/

string upraszczanie(drzewo *w)
{
    if(w->dane=="sin" ||w->dane=="cos" || w->dane=="tg" || w->dane=="ctg"||w->dane=="ln")
    {
       string wynik=w->dane + "(" + upraszczanie(w->lewo) + ")";
       return wynik;
    }
    if(w->dane=="+" )
    {
        string wynik="";
        if(w->lewo->dane=="0") /// jeśli część z lewej strony jest zerem to zapisuje tylko prawą część
        {
           wynik="(" + upraszczanie(w->prawo) + ")" ;
           return wynik;
        }
        if(w->prawo->dane=="0")/// jeśli część z prawej strony jest zerem to zapisuje tylko lewą część
        {
             wynik= "(" + upraszczanie(w->lewo)+ ")";
             return wynik;
        }
              wynik="("  + upraszczanie(w->lewo) + w->dane + upraszczanie(w->prawo) + ")";
              return wynik;

    }
    if(w->dane=="-")
    {
        string wynik="";
        if(w->lewo->dane=="0") /// jeśli część z lewej strony jest zerem to zapisuje tylko prawą część z minusem
        {
           wynik=w->dane + "(" + upraszczanie(w->prawo) + ")" ;
           return wynik;
        }
        if(w->prawo->dane=="0") /// jeśli część z prawej strony jest zerem to zapisuje tylko lewą część
        {
             wynik= "(" + upraszczanie(w->lewo)+ ")";
             return wynik;
        }
              wynik="("  + upraszczanie(w->lewo) + w->dane + upraszczanie(w->prawo) + ")";
              return wynik;
    }
    if(w->dane=="*")
    {
         string wynik="";
         if(w->lewo->dane=="0" || w->prawo->dane=="0") /// jeśli którekolwiek jest 0 to wynik jest 0
         {
             wynik="0";
             return wynik;
         }
         if(w->lewo->dane=="1") /// jesli ktoraś galaz jest jedynka to zapisujemy tylko lewą/prawą część
         {
            wynik= upraszczanie(w->prawo);
         }
         if(w->prawo->dane=="1")
         {
              wynik=upraszczanie(w->lewo);
              return wynik;
         }
         if(w->lewo->dane=="+" || w->lewo->dane=="-")
         {
             wynik=wynik+ "(" + upraszczanie(w->lewo) + ")";
         }
         else
             wynik+=upraszczanie(w->lewo);
         wynik+=w->dane;
         if(w->prawo->dane=="+" || w->prawo->dane=="-")
         {
             wynik=wynik+ "(" + upraszczanie(w->prawo) + ")";
         }
         else
             wynik+= "(" + upraszczanie(w->prawo) + ")";
         return wynik;
    }
    if(w->dane=="/")
    {
        string wynik="";
        if(w->lewo->dane=="0") /// jeśli licznik jest 0 to calość jest 0
        {
            wynik="0";
            return wynik;
        }
        if(w->prawo->dane=="1") ///jesli mianownik jest 1 to wypisz tylko licznik
        {
            wynik=upraszczanie(w->lewo);
            return wynik;
        }
        if(w->lewo->dane=="+" || w->lewo->dane=="-")
        {
            wynik=wynik+ "(" + upraszczanie(w->lewo) + ")";
        }
        else
            wynik+=upraszczanie(w->lewo);
        wynik+=w->dane;
        if(w->prawo->dane=="+" || w->prawo->dane=="-")
        {
            wynik=wynik+ "(" + upraszczanie(w->prawo) + ")";
        }
        else
            wynik+= "(" + upraszczanie(w->prawo) + ")";
        return wynik;
    }

        if(w->dane=="^")
        {
            string wynik="";
            if(w->lewo->dane=="+" || w->lewo->dane=="-" || w->lewo->dane=="*" || w->lewo->dane=="/")
            {
                wynik=wynik+ "(" + upraszczanie(w->lewo) + ")";
            }
            else
                wynik+=upraszczanie(w->lewo);
            wynik+=w->dane;
            if(w->prawo->dane=="+" || w->prawo->dane=="-" || w->prawo->dane=="*" || w->prawo->dane=="/")
            {
                wynik=wynik+ "(" + upraszczanie(w->prawo) + ")";
            }
            else
                wynik+= "(" + upraszczanie(w->prawo) + ")";
            return wynik;
        }
    return w->dane;

};
/**
* Funkcja zamienia dodaje, odejmuje, mnoży wartoścli liczbowe oraz przesuwa niektóre gałęzie drzewa
* \param drzewo potrzebne jest w ogóle drzewo by je można było skrócić
*/


void skracanie(drzewo *w)
{

     if(w->lewo!=NULL)
    {
    if(w->lewo->dane=="sin" || w->lewo->dane=="cos" || w->lewo->dane=="tg" || w->lewo->dane=="ctg" || w->lewo->dane=="ln" || w->lewo->dane=="^" || w->lewo->dane=="*" || w->lewo->dane=="/" || w->lewo->dane=="+" || w->lewo->dane=="-")
    {
        skracanie(w->lewo);
    }
    }
    if(w->prawo!=NULL)
    {

    if(w->prawo->dane=="sin" || w->prawo->dane=="cos" || w->prawo->dane=="tg" || w->prawo->dane=="ctg" || w->prawo->dane=="ln" || w->prawo->dane=="^" || w->prawo->dane=="*" || w->prawo->dane=="/" || w->prawo->dane=="+" || w->prawo->dane=="-")
    {
        skracanie(w->prawo);
    }
    }
    if(w->lewo!=NULL && w->prawo!=NULL) ///jeśli dane są liczbą to możemy na nich wykonać standardowe obliczenia matematyczne
    {
    if(w->lewo->dane!="x" && w->prawo->dane!="x"&& w->prawo->dane!="sin" && w->prawo->dane!="cos" && w->prawo->dane!="tg" && w->prawo->dane!="ctg" && w->prawo->dane!="ln" && w->lewo->dane!="sin" && w->lewo->dane!="cos" && w->lewo->dane!="tg" && w->lewo->dane!="ctg" && w->lewo->dane!="ln" && w->prawo->dane!="^" && w->prawo->dane!="*" && w->prawo->dane!="/" && w->prawo->dane!="+" && w->prawo->dane!="-" && w->lewo->dane!="^" && w->lewo->dane!="*" && w->lewo->dane!="/" && w->lewo->dane!="+" && w->lewo->dane!="-" )
    {
        double a, b, c;
        istringstream isstream(w->lewo->dane);
        istringstream isstream2(w->prawo->dane);
        isstream >> a;
        isstream2 >> b;
        if(w->dane=="+")
        {
            c=a+b;
        }
        if(w->dane=="-")
        {
            c=a-b;
        }
        if(w->dane=="*")
        {
            c=a*b;
        }
        if(w->dane=="/")
        {
            c=a/b;
        }
        if(w->dane=="^")
        {
            c=pow(a,b);
        }
        ostringstream osstream;
        osstream << c;
        w->dane=osstream.str();
        usuwaniegalezi(w);
    }
  else if(w->dane=="+")
    {
     if(w->lewo->dane=="0") /// jeżeli któraś z danych jest 0 przesuwamy drzewo o jedno w górę
     {
      przesuwanie(w,'p');
     }
    else if(w->prawo->dane=="0")
     {
      przesuwanie(w,'l');
     }
    }
    else if(w->dane=="-" && w->prawo->dane=="0")
    {
        przesuwanie(w,'l');
    }
    else if(w->dane=="*")
    {
        if(w->lewo->dane=="0" || w->prawo->dane=="0")
        {
            w->dane="0";
           usuwaniegalezi(w);
        }
       else if(w->lewo->dane=="1")
        {
          przesuwanie(w,'p');
        }
       else if(w->prawo->dane=="1")
        {
           przesuwanie(w,'l');
        }

    }
    else if(w->dane=="/")
    {
        if(w->lewo->dane=="0")
        {
            w->dane="0";
            usuwaniegalezi(w);
        }
       else if(w->prawo->dane=="1")
        {
           przesuwanie(w,'l');
        }

    }
    else if(w->dane=="^")
    {
        if(w->prawo->dane=="1")
        {
            przesuwanie(w,'l');
        }
       else if(w->prawo->dane=="0")
        {
            w->dane="1";
            usuwaniegalezi(w);
        }
    }
    }
}
/**
* \brief funkcja, która w pewnych wypadkach upraszcza podany wcześniej wzór pochodnej.
* Funkcja działa na zasadzie wywoływania wszystkich funckji wypisanej wyżej.
* \param s jest pochodną "surową"
* \return zwracana jest "uproszczona" funkcja
*/
string calosc(drzewo *w)
{
    skracanie(w);
  return upraszczanie(w);

}
