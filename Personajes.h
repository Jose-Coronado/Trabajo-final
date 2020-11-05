#pragma once
#include <iostream>
#include <vector>

using namespace std;
using namespace System;
using namespace System::Windows::Forms;
using namespace System::Drawing;

class Personajes
{
protected:
	int x, y;
	int dx, dy;
	float ancho, alto;
	int IDx;
public:
	Personajes()
	{
		x = y = 0;
		dx = dy = 0;
		ancho = alto = 0;
		IDx = 0;
	}

	int GetAncho() {
		return ancho;
	}
	int GetAlto() {
		return alto;
	}
	int GetX() {
		return x;
	}
	int GetY() {
		return y;
	}


	void SetDX(int value)
	{
		dx = value;
	}
	void SetDY(int value)
	{
		dy = value;
	}

	Rectangle Area()
	{
		return Rectangle(x, y, ancho, alto);
	}
	Rectangle NextArea()
	{
		return Rectangle(x + dx, y + dy, ancho, alto);
	}

	virtual void Mover(Graphics^ g)
	{
		x += dx;
		y += dy;
	}
	virtual void Mostrar(Graphics^ g, Bitmap^ img)
	{
		g->FillRectangle(Brushes::White, Area());
	}
};