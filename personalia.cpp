#pragma once
#include "personalia.h"
#include <iostream>
#include<random>
#include <fstream>
#include<sstream>
#include <string>
#include "Lista.h"
using namespace std;

personalia::personalia(string pesel) :pesel(pesel)
{
	cout << "Podaj imie: " << endl;
	cin >> imie;
	cout << "Podaj nazwisko: " << endl;
	cin >> nazwisko;
losuj: random_device rd;	//uruchomienie generatora liczb pseudolosowych
	mt19937 gen(rd());	//o nazwie Mersenne Twister
	uniform_int_distribution<>dist(1000, 9999);	//zawężenie przedziału
	numer = dist(gen);
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
				else if (l % 6 == 1) {
					stringstream ss;
					double liczba;
					ss << numer;
					if (!wskr.compare(ss.str()))goto losuj;
				}
				else ll.add(wskr);
				l++;
			}
		}
		else std::cout << "Dostep do pliku zostal zabroniony!" << std::endl;
		lista.close();
	}
	catch (exception ex) {};
	try {
		lista.open("rachunekbiez.txt", ios_base::in);
		Lista <string> ll;
		int l = 0;
		if (lista.good() == true)
		{

			while (!lista.eof())
			{
				getline(lista, wskr);
				if (wskr.empty())break;
				else if (l % 5 == 1) {
					stringstream ss;
					double liczba;
					ss << numer;
					if (!wskr.compare(ss.str()))goto losuj;
				}
				else ll.add(wskr);
				l++;
			}
		}
		else std::cout << "Dostep do pliku zostal zabroniony!" << std::endl;
		lista.close();
	}
	catch (exception ex) {};
	cout << "Numer klienta to " << numer << endl;

}

personalia::personalia(string imie, string nazwisko, string pesel, int numer) :imie(imie), nazwisko(nazwisko), pesel(pesel), numer(numer) {};	//przeładowanie (przepełnienie) konstruktorów

void personalia::usun()
{
	cout << "Podaj numer klienta do usuniecia: " << endl;
	cin >> numer;
	cout << "W celu weryfikacji podaj PESEL: " << endl;
	cin >> pesel;

}
