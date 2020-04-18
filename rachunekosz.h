#pragma once
#include "rachunekbiez.h"
#include"personalia.h"
#include <iostream>
#include<string>
using namespace std;
class rachunekosz :
	public rachunekbiez
{
protected:
	string procent;
public:
	rachunekosz(string pesel);
	rachunekosz(string kwota, string procent, string imie, string nazwisko, string pesel, int numer);
	void show();
	void save();
	friend void zmiana2(rachunekosz& obiekt, double kwota);
	friend void usun2(rachunekosz& obiekt);
};
