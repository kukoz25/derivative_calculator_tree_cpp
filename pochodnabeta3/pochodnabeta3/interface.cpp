#include "interface.h"
/**
* \brief Funkcja zbiera wszystkie wywołania funckji oraz tworzenie struktur, które wcześniej były w mainie.
*/
void interface()
{
    drzewo *korzen=tworzenie(); ///potrzebny by w ogóle rozbić funkcję i napisać jej pochodną
    drzewo *korzen2=tworzenie(); ///potrzebne do upraszczania
    drzewo *korzen3=tworzenie(); ///potrzebne do upraszczania
    string funkcjauzytkownika;
    cout << "Podaj funkcje" << endl;
    cin >> funkcjauzytkownika;
    rozbijanie(funkcjauzytkownika,korzen);
    cout << "Oto pochodna Twojej funkcji" << endl;
    cout << pochodna(korzen) << endl;
    cout << "Oto pochodna po uproszczeniu" << endl;
    rozbijanie(pochodna(korzen),korzen2);
   //cout << calosc(korzen2) << endl;
   rozbijanie(calosc(korzen2),korzen3);
    cout << calosc(korzen3) << endl;
    usuwanie(korzen);
    usuwanie(korzen2);
      usuwanie(korzen3);
    return;

};
