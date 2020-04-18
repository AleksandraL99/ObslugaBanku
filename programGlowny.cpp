#include <cstdlib>
#include <iostream>
#include <typeinfo>
#include <locale.h>
#include <string>
#include <fstream>
#include <typeinfo>
#include <sstream>
#include <iomanip>
#include "personalia.h"
#include "rachunekbiez.h"
#include "rachunekosz.h"
#include<random>
#include "Lista.h"



using namespace std;
int obj;		//liczba obiektów w pliku, obliczana podczas ściągania danych z rach bieżacego
int obj2;		//liczba obiektów w pliku, obliczana podczas ściągania danych z rach oszczędnosciowego
void zapis(string** dd);
void zapis2(string** dd);
double operator-(string str) {
	stringstream ss;
	double liczba;
	ss << str;
	ss >> liczba;
	return liczba;
}

string** dane()
{
	fstream lista;
	string wskr;
	try {
		lista.open("rachunekbiez.txt", ios_base::in);
		Lista <string> ll;
		int l = 0;
		if (lista.good() == true)
		{

			while (!lista.eof())
			{
				getline(lista, wskr);
				if (wskr.empty())break;		//jeśli jest koniec pliku to ominie error
				else if (l % 5 == 0) {
					ll.add(wskr.substr(1));
				}
				else ll.add(wskr);
				l++;
			}
			string** dane = NULL;
			if (ll.empty()) {
				obj = ll.length() / 5;
				dane = new string * [obj];
				int l = -1;

				for (int i = 0; i < ll.length(); i++) {
					if (i % 5 == 0) {
						l++;
						dane[l] = new string[5];
					}
					dane[l][i % 5] = ll.get(i).value;
				}
			}
			else {
				cout << "lista pusta" << endl;
				return dane;
			}

			return dane;
		}
		else std::cout << "Dostep do pliku zostal zabroniony!" << std::endl;
		lista.close();

	}
	catch (exception ex) { cout << "Błąd " << ex.what(); };
};
string** dane2()
{
	fstream lista;
	string wskr;
	try {
		lista.open("rachunekosz.txt", ios_base::in);
		Lista <string> ll;
		int l = 0;
		if (lista.good() == true)
		{

			while (!lista.eof())
			{
				getline(lista, wskr);
				if (wskr.empty())break;
				else if (l % 6 == 0) {
					ll.add(wskr.substr(1));
				}
				else ll.add(wskr);
				l++;
			}
			string** dane2 = NULL;
			if (ll.empty()) {
				obj2 = ll.length() / 6;
				dane2 = new string * [obj2];
				int l = -1;

				for (int i = 0; i < ll.length(); i++) {
					if (i % 6 == 0) {
						l++;
						dane2[l] = new string[6];
					}
					dane2[l][i % 6] = ll.get(i).value;

				}
			}
			else {
				cout << "lista pusta" << endl;
				return dane2;
			}

			return dane2;
		}
		else std::cout << "Dostep do pliku zostal zabroniony!" << std::endl;
		lista.close();
	}
	catch (exception ex) { cout << "Błąd " << ex.what(); };

};
void zmiana(rachunekbiez& obiekt, double kwota) {
	double x = -obiekt.kwota;
	x += kwota;
	stringstream ss;
	ss << x;
	obiekt.kwota = ss.str();
	string** dd = dane();
	for (int i = 0; i < obj; i++) {
		if (!dd[i][0].compare(obiekt.pesel)) {
			dd[i][4] = obiekt.kwota;
			break;
		}
	}

	zapis(dd);
}
void zmiana2(rachunekosz& obiekt, double kwota) {
	double x = -obiekt.kwota;
	x += kwota;
	stringstream ss;
	ss << x;
	obiekt.kwota = ss.str();
	string** dd = dane2();
	for (int i = 0; i < obj2; i++) {
		if (!dd[i][0].compare(obiekt.pesel)) {
			dd[i][4] = obiekt.kwota;
			break;
		}
	}

	zapis2(dd);
}
void usun(rachunekbiez& obiekt)
{
	fstream lista;
	int k;
	string** dd = dane();		//dane to tablica dwuwymiarowa ściągnięta z pliku
	try {
		for (int i = 0; i < obj; i++) {
			if (!dd[i][0].compare(obiekt.pesel)) {
				k = i;
				break;
			}
		}

		lista.open("rachunekbiez.txt", ios_base::out);
		for (int i = 0; i < obj; i++) {
			for (int j = 0; j < 5; j++) {
				if (i != k)
				{
					if (!j % 5)
						lista << ":" << dd[i][j] << endl;
					else
						lista << dd[i][j] << endl;
				}
			}
		}
		lista.close();
	}
	catch (exception ex) { cout << "Błąd usuwania: " << ex.what(); };

};
void usun2(rachunekosz& obiekt)
{
	fstream lista;
	int k;
	string** dd = dane2();		//dane to tablica dwuwymiarowa ściągnięta z pliku
	try {
		for (int i = 0; i < obj2; i++) {
			if (!dd[i][0].compare(obiekt.pesel)) {
				k = i;
				break;
			}
		}
		lista.open("rachunekosz.txt", ios_base::out);
		for (int i = 0; i < obj2; i++) {
			for (int j = 0; j < 6; j++) {
				if (i != k)
				{
					if (!j % 6)
						lista << ":" << dd[i][j] << endl;
					else
						lista << dd[i][j] << endl;
				}
			}
		}

		lista.close();
	}
	catch (exception ex) { cout << "Błąd usuwania: " << ex.what(); };
};
void zapis(string** dd) {
	fstream lista;
	try {
		lista.open("rachunekbiez.txt", ios_base::out);

		for (int i = 0; i < obj; i++) {
			for (int j = 0; j < 5; j++) {
				if (!j % 5)
					lista << ":" << dd[i][j] << endl;
				else
					lista << dd[i][j] << endl;
			}
		}

		lista.close();
	}
	catch (exception ex) { cout << "Błąd usuwania: " << ex.what(); };
}
void zapis2(string** dd) {
	fstream lista;
	try {
		lista.open("rachunekosz.txt", ios_base::out);

		for (int i = 0; i < obj2; i++) {
			for (int j = 0; j < 6; j++) {
				if (!j % 6)
					lista << ":" << dd[i][j] << endl;
				else
					lista << dd[i][j] << endl;
			}
		}

		lista.close();
	}
	catch (exception ex) { cout << "Błąd usuwania: " << ex.what(); };
}
int main()
{
	setlocale(LC_ALL, "polish");
	char i = '0';
	cout << "Witaj." << endl << endl;
	string ii;
	while (i != '3')
	{
	skok:	cout << "Wybierz opcję: " << endl;
		cout << "1) Wyświetl skrócone dane wszystkich klientów" << endl;				//tworzony obiekt typu personalia
		cout << "2) Sprawdź pesel klienta" << endl;
		cout << "3) Zakończ wizytę" << endl << endl;
		int spr = 1;
		while (spr) {
			getline(cin, ii);
			if (ii.length() == 1)
				spr = 0;

			
		}
		i = ii.at(0);
		if (i < 58 && i>48)
		{
			switch (i)
			{
			case '1':
			{
				string** biez = dane();
				cout << endl << fixed << setw(50) << "Rachunki bieżące" << endl << endl;
				for (int i = 0; i < obj; i++) //wypisanie danych z tablicy obiekty
				{
					for (int j = 0; j < 5; j++)
					{
						if (j == 0)cout << "Pesel: " << fixed << setw(10) << biez[i][j] << " \t";
						else if (j == 1)cout << "Numer: " << fixed << setw(10) << biez[i][j] << " \t";
						else if (j == 2)cout << "Imie: " << fixed << setw(10) << biez[i][j] << " \t";
						else if (j == 3)cout << "Nazwisko: " << fixed << setw(10) << biez[i][j] << " \t";
						if (j == 4)cout << endl;
					}
				}
				cout << endl;

				string** osz = dane2();
				cout << endl << fixed << setw(50) << "Rachunki oszczędnościowe" << endl << endl;
				for (int i = 0; i < obj2; i++) //wypisanie danych z tablicy obiekty
				{
					for (int j = 0; j < 6; j++)
					{
						if (j == 0)cout << "Pesel: " << fixed << setw(10) << osz[i][j] << " \t";
						else if (j == 1)cout << "Numer: " << fixed << setw(10) << osz[i][j] << " \t";
						else if (j == 2)cout << "Imie: " << fixed << setw(10) << osz[i][j] << " \t";
						else if (j == 3)cout << "Nazwisko: " << fixed << setw(10) << osz[i][j] << " \t";
						if (j == 4)cout << endl;
					}
				}
				cout << endl;
			};
			break;
			case '2':
			{
				fstream lista;
				string sprawdz;
				string wypisz;
				stringstream a;
				rachunekbiez* b = NULL;
				rachunekosz* o = NULL;
				cout << "Wprowadź pesel: " << endl;
			
				int spr = 1;
				while (spr) {
					cin >> sprawdz;
					if (sprawdz.length() == 9) {
						int l = 0;
						for (int i = 0; i < 9; i++) {
							if (sprawdz.at(i) > 47 && sprawdz.at(i) < 58) {

							}
							else
								l++;
						}
						if (!l)
							spr = 0;
					}
					else {
						cout << "Podano zły pesel" << endl;

					}
				}
				string pom = sprawdz;
				a << ":" << sprawdz;
				sprawdz = a.str();
			
				lista.open("rachunekbiez.txt", ios_base::in);
				string tek[5];
				int l = 0;
				if (lista.good() == true)
				{

					while (!lista.eof())
					{

						getline(lista, wypisz);

						if (!wypisz.empty() && wypisz.at(0) == ':')
						{
							if (wypisz.compare(sprawdz) == 0) {
								tek[0] = wypisz;
								for (int i = 1; i < 5; i++) {
									getline(lista, wypisz);
									tek[i] = wypisz;
								}
								b = new rachunekbiez(tek[4], tek[2], tek[3], tek[0].substr(1), (int)-(tek[1]));		//substr do wypisania znaków od pozycji 1
								break;
							}

							l = 0;
						}
						l++;
					}
				}
				else std::cout << "Dostep do pliku zostal zabroniony!" << std::endl;
				lista.close();

				lista.open("rachunekosz.txt", ios_base::in);
				string tek2[7];
				l = 0;
				if (lista.good() == true)
				{

					while (!lista.eof())
					{

						getline(lista, wypisz);

						if (!wypisz.empty() && wypisz.at(0) == ':')
						{
							if (wypisz.compare(sprawdz) == 0) {
								tek2[0] = wypisz;
								for (int i = 1; i < 7; i++) {
									getline(lista, wypisz);
									tek2[i] = wypisz;
								}
								o = new rachunekosz(tek2[4], tek2[5], tek2[2], tek2[3], tek2[0].substr(1), (int)-(tek2[1]));		//substr do wypisania znaków od pozycji 1
								break;
							}
							l = 0;
						}
						l++;
					}

				}
				else std::cout << "Dostep do pliku zostal zabroniony!" << std::endl;
				lista.close();

				if (b != NULL && o != NULL)
				{
					cout << endl << "Rachunek bieżący: " << endl;
					b->show();
					cout << endl << "Rachunek oszczędnościowy: " << endl;
					o->show();
					char s;
					cout << "1) Wpłać pieniądze na rachunek oszczędnościowy \n2) Wybierz pieniądze z rachunku oszczędnościowego\n3) Wpłać pieniądze na rachunek bieżący \n4) Wybierz pieniądze z rachunku bieżącego \n5) Usuń rachunki \n6) Wróć do głównego menu" << endl;
					cin >> s;
					if (s == '1')
					{
						double w;
						cout << "Podaj kwotę jaka chcesz wplacić: " << endl;
						cin >> w;
						cout << endl;
						zmiana2(*o, w);
						o->show();
					}
					else if (s == '2')
					{
						double w;
						cout << "Podaj kwotę jaka chcesz wplacić: " << endl;
						cin >> w;
						cout << endl;
						zmiana2(*o, -w);
						o->show();
					}
					else if (s == '3')
					{
						double kwota;
						cout << "Podaj kwotę jaka chcesz wplacić: " << endl;
						cin >> kwota;
						cout << endl;
						zmiana(*b, kwota);
						b->show();
					}
					else if (s == '4')
					{
						double kwota;
						cout << "Podaj kwotę jaka chcesz wyplacić: " << endl;
						cin >> kwota;
						cout << endl;
						zmiana(*b, -kwota);
						b->show();
					}
					else if (s == '5')
					{
						usun(*b);
						usun2(*o);
					}
					else
					{
						cin.ignore();
						goto skok;
					};
				}
				else if (b == NULL && o == NULL)
				{
					char s;
					cout << "Dodaj nowy rachunek " << endl << "1) bieżący " << endl << "2) oszczędnościowy" << endl << "3) Wróć do głównego menu" << endl;
					cin >> s;
					if (s == '1')
					{
						rachunekbiez k1(pom);

						k1.save();
					};
					if (s == '2')
					{
						rachunekosz k2(pom);
						k2.save();
					}
					else
					{
						cin.ignore();
						goto skok;
					};
				}
				else if (b != NULL && o == NULL)
				{

					b->show();
					char s;
					cout << "1) Dodaj nowy rachunek  oszczędnościowy \n2) Wpłać pieniądze na rachunek bieżący \n3) Wybierz pieniądze z rachunku bieżącego \n4) Usuń rachunek bieżący \n5) Wróć do głównego menu" << endl;
					cin >> s;
					if (s == '1')
					{
						rachunekosz k1(pom);
						k1.save();
					}
					else if (s == '2')
					{
						double kwota;
						cout << "Podaj kwotę jaka chcesz wplacić: " << endl;
						cin >> kwota;
						cout << endl;
						zmiana(*b, kwota);
						b->show();
					}
					else if (s == '3')
					{
						double kwota;
						cout << "Podaj kwotę jaka chcesz wyplacić: " << endl;
						cin >> kwota;
						cout << endl;
						zmiana(*b, -kwota);
						b->show();
					}
					else if (s == '4')
					{
						usun(*b);
					}
					else
					{
						cin.ignore();
						goto skok;
					};
				}
				else if (b == NULL && o != NULL)
				{
					char s;
					o->show();
					cout << "1) Dodaj nowy rachunek  bieżący \n2) Wpłać pieniądze na rachunek oszczędnościowy \n3) Wybierz pieniądze z rachunku oszczędnościowego \n4) Usuń rachunek oszczędnościowy \n5) Wróć do głównego menu" << endl;
					cin >> s;
					if (s == '1')
					{
						rachunekbiez k1(pom);
						k1.save();
					}
					else if (s == '2')
					{
						double w;
						cout << "Podaj kwotę jaka chcesz wplacić: " << endl;
						cin >> w;
						cout << endl;
						zmiana2(*o, w);
						o->show();
					}
					else if (s == '3')
					{
						double w;
						cout << "Podaj kwotę jaka chcesz wplacić: " << endl;
						cin >> w;
						cout << endl;
						zmiana2(*o, -w);
						o->show();
					}
					else if (s == '4')
					{
						usun2(*o);
					}
					else
					{
						cin.ignore();
						goto skok;
					};
				}

			};
			break;
			case '3':
			{
				break;
			};
			default:
			{
				cout << "Niepoprawny numer opcji, spróbuj ponownie." << endl;

				goto skok;
			};
			};
		}
		else
		{
			cout << "Niepoprawny numer opcji, spróbuj ponownie." << endl;
			goto skok;
		};
		
	};
	return 0;
}
