#include "rozbijanie.h"

/**
* \brief funkcja, która rozbija funckję od użytkownika na drzewo.
* \param korzeń jest potrzebny, by drzewo zostało wypełnione
* \param s jest funkcją wczytaną od użytkownika
*  \return zwraca wartość true jeżeli się wykona
*/
bool dodawanie(string s1,drzewo *korzen)
{
    string s=usuwanienawiasowfunkcja(s1); ///usuwamy nawiasy na samym początku zanim wejdziemy
    for(int i=s.size()-1;i>=0;i--)
    {
          if(s[i]==')')
       {

              int pom=1; /// zmienna, która ma za zadanie liczyć ilość nawiasów, ponieważ chcemy dostać się jak najbardziej wgłąb funkcji
              while(pom>0)
              {
                  i--;
                  if(s[i]==')')
                  {
                      pom++;
                  }
                  if(s[i]=='(')
                  {
                      pom--;
                  }
              }
       }
         if(s[i]=='+') /// dodawanie
       {
              string czesc1="",czesc2=""; ///zmienne pozwalające dobrze rozbić funkcję na części
              for(int j=0;j<i;j++)
              {
                  czesc1+=s[j];
              }
             for(int j=i+1;j<s.size();j++)
             {
               czesc2+=s[j];
             }
             korzen->dane="+"; /// potrzebny by dobrze napisać wzór pochodnej
             korzen->lewo=new drzewo;
             korzen->prawo=new drzewo;
             rozbijanie(czesc1,korzen->lewo); /// rozbijamy kolejne części funkcji
             rozbijanie(czesc2,korzen->prawo);
              return true;
       }

}
    return false;
}
/**
* \brief funkcja, która rozbija funckję od użytkownika na drzewo.
* \param korzeń jest potrzebny, by drzewo zostało wypełnione
* \param s jest funkcją wczytaną od użytkownika
*  \return zwraca wartość true jeżeli się wykona
*/
bool odejmowanie(string s1, drzewo *korzen)
    {
    string s=usuwanienawiasowfunkcja(s1);
        for(int i=s.size()-1;i>=0;i--)
        {
              if(s[i]==')')
           {

                  int pom=1;
                  while(pom>0)
                  {
                      i--;
                      if(s[i]==')')
                      {
                          pom++;
                      }
                      if(s[i]=='(')
                      {
                          pom--;
                      }
                  }
           }
             if(s[i]=='-') /// odejmowanie
           {
                  string czesc1="",czesc2="";
                  for(int j=0;j<i;j++)
                  {
                      czesc1+=s[j];
                  }
                 for(int j=i+1;j<s.size();j++)
                 {
                   czesc2+=s[j];
                 }
                 korzen->dane="-";
                 korzen->lewo=new drzewo;
                 korzen->prawo=new drzewo;
                 rozbijanie(czesc1,korzen->lewo);
                 rozbijanie(czesc2,korzen->prawo);
                  return true;
           }
        }
        return false;
    }
/**
* \brief funkcja, która rozbija funckję od użytkownika na drzewo.
* \param korzeń jest potrzebny, by drzewo zostało wypełnione
* \param s jest funkcją wczytaną od użytkownika
*  \return zwraca wartość true jeżeli się wykona
*/
        bool mnozenie(string s1,drzewo *korzen)
           {
    string s=usuwanienawiasowfunkcja(s1);
               for(int i=s.size()-1;i>=0;i--)
               {
                     if(s[i]==')')
                  {

                         int pom=1;
                         while(pom>0)
                         {
                             i--;
                             if(s[i]==')')
                             {
                                 pom++;
                             }
                             if(s[i]=='(')
                             {
                                 pom--;
                             }
                         }
                  }
                    if(s[i]=='*') /// mnozenie
                  {
                         string czesc1="",czesc2="";
                         for(int j=0;j<i;j++)
                         {
                             czesc1+=s[j];
                         }
                        for(int j=i+1;j<s.size();j++)
                        {
                          czesc2+=s[j];
                        }
                        korzen->dane="*";
                        korzen->lewo=new drzewo;
                        korzen->prawo=new drzewo;
                        rozbijanie(czesc1,korzen->lewo);
                        rozbijanie(czesc2,korzen->prawo);
                         return true;
                  }
               }
               return false;
           }
        /**
        * \brief funkcja, która rozbija funckję od użytkownika na drzewo.
        * \param korzeń jest potrzebny, by drzewo zostało wypełnione
        * \param s jest funkcją wczytaną od użytkownika
        *  \return zwraca wartość true jeżeli się wykona
        */
          bool dzielenie(string s1, drzewo *korzen)
          {
    string s=usuwanienawiasowfunkcja(s1);
              for(int i=s.size()-1;i>=0;i--)
              {
                    if(s[i]==')')
                 {
                        int pom=1;
                        while(pom>0)
                        {
                            i--;
                            if(s[i]==')')
                            {
                                pom++;
                            }
                            if(s[i]=='(')
                            {
                                pom--;
                            }
                        }
                 }
                   if(s[i]=='/') /// dzielenie
                 {
                        string czesc1="",czesc2="";
                        for(int j=0;j<i;j++)
                        {
                            czesc1+=s[j];
                        }
                       for(int j=i+1;j<s.size();j++)
                       {
                         czesc2+=s[j];
                       }
                       korzen->dane="/";
                       korzen->lewo=new drzewo;
                       korzen->prawo=new drzewo;
                       rozbijanie(czesc1,korzen->lewo);
                       rozbijanie(czesc2,korzen->prawo);
                        return true;
                 }
              }
              return false;
          }
          /**
          * \brief funkcja, która rozbija funckję od użytkownika na drzewo.
          * \param korzeń jest potrzebny, by drzewo zostało wypełnione
          * \param s jest funkcją wczytaną od użytkownika
          *  \return zwraca wartość true jeżeli się wykona
          */
          bool potegowanie(string s1, drzewo *korzen)
          {
    string s=usuwanienawiasowfunkcja(s1);
              for(int i=s.size()-1;i>=0;i--)
              {
                    if(s[i]==')')
                 {
                        int pom=1;
                        while(pom>0)
                        {
                            i--;
                            if(s[i]==')')
                            {
                                pom++;
                            }
                            if(s[i]=='(')
                            {
                                pom--;
                            }
                        }
                 }
                    /**
                    * \brief funkcja, która rozbija funckję od użytkownika na drzewo.
                    * \param korzeń jest potrzebny, by drzewo zostało wypełnione
                    * \param s jest funkcją wczytaną od użytkownika
                    *  \return zwraca wartość true jeżeli się wykona
                    */
                   if(s[i]=='^') /// potegowanie
                 {
                        string czesc1="",czesc2="";
                        for(int j=0;j<i;j++)
                        {
                            czesc1+=s[j];
                        }
                       for(int j=i+1;j<s.size();j++)
                       {
                         czesc2+=s[j];
                       }
                       korzen->dane="^";
                       korzen->lewo=new drzewo;
                       korzen->prawo=new drzewo;
                       rozbijanie(czesc1,korzen->lewo);
                       rozbijanie(czesc2,korzen->prawo);
                        return true;
                 }
              }
              return false;
          }
          /**
          * \brief funkcja, która rozbija funckję od użytkownika na drzewo.
          * \param korzeń jest potrzebny, by drzewo zostało wypełnione
          * \param s jest funkcją wczytaną od użytkownika
          *  \return zwraca wartość true jeżeli się wykona
          */
          bool innefunkcje(string s1, drzewo *korzen)
          {
              string s=usuwanienawiasowfunkcja(s1);
              for(int i=0;i<s.size();i++)
              {

                  switch(s[i]) /// tutaj jest trygonometria i logartymy
                  {
                  case 's':
                 {

                      if(s[i+1]=='i'&&s[i+2]=='n') ///sinus
                      {
                          int pom=1;
                        string wnentrze=""; /// wnetrze naszej fukcji typu "ln", "sin", itp.
                        i=i+4;
                        while(pom>0)
                        {
                            if(s[i]=='(')
                            {
                                pom++;
                            }
                            if(s[i]==')')
                            {
                                pom--;
                            }
                            if(pom>0)
                            {
                              wnentrze+=s[i];
                            }
                            i++;
                        }


                       korzen->dane="sin";
                       korzen->lewo=new drzewo;
                      rozbijanie(wnentrze,korzen->lewo); /// wnetrze funkcji leci do lewej galezi drzewa, niepotrzebna jest prawa gałąź
                        return true;
                      }
                 }
                  case 'c': /// cotangens i cosinus zaczynaja sie na "c", wiec trzeba sprawdzic jeszcze reszte literek
                 {
                      if(s[i+1]=='o'&&s[i+2]=='s') ///cosinus
                      {

                          int pom=1;
                        string wnentrze="";
                        i=i+4;
                        while(pom>0)
                        {
                            if(s[i]=='(')
                            {
                                pom++;
                            }
                            if(s[i]==')')
                            {
                                pom--;
                            }
                            if(pom>0)
                            {
                              wnentrze+=s[i];
                            }
                            i++;
                        }


                       korzen->dane="cos";
          korzen->lewo=new drzewo;
                      rozbijanie(wnentrze,korzen->lewo);
                        return true;
                      }
                      else if(s[i+1]=='t'&&s[i+2]=='g') /// cotangens
                      {

                          int pom=1;
                        string wnentrze="";
                        i=i+4;
                        while(pom>0)
                        {
                            if(s[i]=='(')
                            {
                                pom++;
                            }
                            if(s[i]==')')
                            {
                                pom--;
                            }
                            if(pom>0)
                            {
                              wnentrze+=s[i];
                            }
                            i++;
                        }


                       korzen->dane="ctg";
                       korzen->lewo=new drzewo;
                      rozbijanie(wnentrze, korzen->lewo);
                        return true;
                      }
                  }
                  case 't':
                 {
                      if(s[i+1]=='g') /// tangens
                      {

                          int pom=1;
                        string wnentrze="";
                        i=i+3;
                        while(pom>0)
                        {
                            if(s[i]=='(')
                            {
                                pom++;
                            }
                            if(s[i]==')')
                            {
                                pom--;
                            }
                            if(pom>0)
                            {
                              wnentrze+=s[i];
                            }
                            i++;
                        }


                       korzen->dane="tg";
                       korzen->lewo=new drzewo;
                      rozbijanie(wnentrze,korzen->lewo);
                       return true;
                      }
                 }
                  case 'l':
                 {
                      if(s[i+1]=='n') /// logarytm naturalny
                      {
                          int pom=1;
                        string wnentrze="";
                        i=i+3;
                        while(pom>0)
                        {
                            if(s[i]=='(')
                            {
                                pom++;
                            }
                            if(s[i]==')')
                            {
                                pom--;
                            }
                            if(pom>0)
                            {
                              wnentrze+=s[i];
                            }
                            i++;
                        }


                       korzen->dane="ln";
                       korzen->lewo=new drzewo;
                      rozbijanie(wnentrze,korzen->lewo);
                        return true;
                      }
                 }
                  }
              }
              korzen->dane=s;
              return false;
          }

          string usuwanienawiasowfunkcja(string s)
          {
             for(int  i=s.size()-1;i>=0;i--)
             {
                   if(s[i]==')') /// wchodzenie wewnatrz nawiasu, poniewaz chcemy pominac zawartosc nawiasow
                {
                       int poczatek=i;
                       int pom=1; /// zmienna pomocnicza, ktora bedzie pamietala ilosc par nawiasow
                       while(pom>0)
                       {
                           i--; ///przechodzimy po napisie s, by znalezc koniec nawiasu
                           if(s[i]==')') /// napotkanie kolejnej pary nawiasow
                           {
                               pom++;
                           }
                           if(s[i]=='(') /// napotkanie konca jednej pary nawiasow
                           {
                               pom--;
                           }
                       }
                       if(i==0 && poczatek==s.size()-1) /// jezeli cala funkcja jest w nawiasie to zdejmujemy nawias
                       {
                           string usuwanienawiasow=""; /// tutaj bedzie wpisana funkcja bez nawiasow
                           for(int j=1;j<s.size()-1;j++)
                           {
                               usuwanienawiasow+=s[j];
                           }
                            return usuwanienawiasow; /// \return zwraca funckję bez nawiasów na końcu
                       }
                   }
             }
             return s;

          }

          /**
          * \brief funkcja, która łączy w sobie wszystkie wcześniejsze funckje w jedną według zaleceń prowadzącego.
          * Funkcja działa na zasadzie wywoływania w warunkach wszystkich funckji wypisanej wyżej.
          * \param korzeń jest potrzebny, by drzewo zostało wypełnione
          * \param s jest funkcją wczytaną od użytkownika
          */
          void rozbijanie(string s, drzewo *korzen)
          {
              korzen->lewo=NULL;
               korzen->prawo=NULL;
                string s1= usuwanienawiasowfunkcja(s);
              // cout << s1 << endl;

                        if(dodawanie(s1, korzen));
                        else if(odejmowanie(s1, korzen));
                        else if(mnozenie(s1, korzen));
                        else if(dzielenie(s1, korzen));
                        else if(potegowanie(s1, korzen));
                        else if(innefunkcje(s1, korzen));
                       else
                           korzen->dane=s1;
                        return;
          }
