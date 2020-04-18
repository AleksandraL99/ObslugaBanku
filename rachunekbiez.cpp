#include "rachunekbiez.h"
#include"personalia.h"
#include <iostream>
#include<string>
#include <fstream>
using namespace std;

rachunekbiez::rachunekbiez(string pesel):personalia(pesel)
{
	cout << "Podaj kwotę: " << endl;

	string ddd;
	cin >> ddd;
	for (int i = 0; i < ddd.length(); i++) {
		if (ddd.at(i) == ',') {
			ddd[i] = '.';
		}
	}
	kwota = ddd;

}

rachunekbiez::rachunekbiez(string kwota, string imie, string nazwisko, string pesel, int numer):kwota(kwota),personalia(imie, nazwisko, pesel, numer) {};

void rachunekbiez::show()
{
	cout << "Imie: " << imie << endl << "Nazwisko:" << nazwisko << endl << "Pesel: " << pesel << endl << "Numer klienta: " << numer << endl <<"Kwota: "<< kwota<<endl<<endl;		//TODO wyedytuj sobie
}

void rachunekbiez::save() 
{
	fstream rachb;
	rachb.open("rachunekbiez.txt", ios_base::app);
	rachb << ":"<<pesel << endl << numer << endl << imie << endl << nazwisko << endl << kwota << endl;
	rachb.close();
}
