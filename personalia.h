#pragma once
#ifndef PERSONALIA_H
#define PERSONALIA_H
#include<iostream>
#include<string>
using namespace std;
class personalia {
protected:
	string imie;
	string nazwisko;
	string pesel;
	int numer;
public:
	personalia(string pesel);
	personalia(string imie, string nazwisko, string pesel, int numer);
	void usun();
	virtual void show()=0;
	virtual void save() = 0;
};

#endif
