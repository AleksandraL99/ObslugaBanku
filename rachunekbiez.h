#pragma once
#include"personalia.h"
class rachunekbiez: public personalia
{
protected:
	string kwota;
public:
	rachunekbiez(string pesel);
	rachunekbiez(string kwota, string imie, string nazwisko, string pesel, int numer);
	void show();
	void save();
	friend void zmiana(rachunekbiez&,double);
	friend void usun(rachunekbiez&);
};
