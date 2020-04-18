#pragma once
#ifndef LISTA_H
#define LISTA_H
#include <iostream>

using namespace std;

class Element;
template <class T>
class Lista
{

public:
	Lista();

	class Element 
	{
	public:
		T value;
		Element* next;
		Element(T wartosc) 
		{
			value = wartosc;
			next = NULL;
		};
	};

	void show();
	void add(T value);
	int length();
	bool empty();

	Element get(int x)	//zwraca element listy o numerze x
	{		
		int l = length(),
			licznik = 0;
		if (x < l && head != NULL) 
		{
			Element* tmp = head;
			while (x != licznik && tmp != NULL) 
			{
				tmp = tmp->next;
				licznik++;
			}
			return *tmp;
		}
	}


private:
	Element* head;
	Element* tail;
};

template <class T>
Lista<T>::Lista() 
{
	head = NULL;
	tail = NULL;
};


template <class T>
void Lista<T>::add(T wartosc) 
{
	if (head != NULL) 
	{
		Element* tmp = new Element(wartosc);
		if (tmp == NULL) throw "Błąd alokacji pamięci.";
		tail->next = tmp;
		tail = tmp;
	}
	else 
	{
		head = new Element(wartosc);
		tail = head;
	}
}

template <class T>
void Lista<T>::show() 
{
	if (head != NULL) 
	{
		Element* tmp = head;
		while (tmp != NULL) 
		{
			cout << tmp->value;
			tmp = tmp->next;
		}
	}
}

template <class T>
int Lista<T>::length() 
{
	int licznik = 0;
	Element* tmp = head;
	while (tmp != NULL) 
	{
		tmp = tmp->next;
		licznik++;
	}
	return licznik;
}

template <class T>
bool Lista<T>::empty() {
	if (head == NULL)
		return 0;
	else
		return 1;
}
#endif 
