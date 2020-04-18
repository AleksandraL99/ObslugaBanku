#include "rachunekosz.h"
#include "rachunekbiez.h"
#include"personalia.h"
#include <iostream>
#include<string>
#include <fstream>
using namespace std;
rachunekosz::rachunekosz(string pesel):rachunekbiez(pesel)
{
	cout << "Podaj procent: " << endl;
	cin >> procent;
}

rachunekosz::rachunekosz(string kwota, string procent, string imie, string nazwisko, string pesel, int numer) : procent(procent), rachunekbiez(kwota,imie, nazwisko, pesel, numer) {};

void rachunekosz::show()
{
	cout << "Imie: "<<imie << endl <<"Nazwisko:"<< nazwisko << endl <<"Pesel: "<< pesel << endl << "Numer klienta: "<<numer << endl << "Oszczędności: "<<kwota <<endl<<"Procent: "<<procent<<endl<< endl;		
}

void rachunekosz::save()
{
	fstream racho;
	racho.open("rachunekosz.txt", ios_base::app);
	racho << ":" << pesel << endl << numer << endl << imie << endl << nazwisko << endl << kwota << endl<<procent<<endl;
	racho.close();
}
