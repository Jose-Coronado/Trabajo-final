#pragma once
#include "Personajes.h"
#include "laberinto.h"

//Los sprites del corrupto solo tienen movimiento hacia la derecha :'v

enum SpriteCorrupto
{
	CaminarIzquierda,
	CaminarDerecha,
	CaminarAbajo,
	CaminarArriba,
};

class Corrupto : public Personajes
{
private:
	SpriteCorrupto accion;
public:
	Corrupto(Bitmap^ img)
	{
		x = 8; y = 8;
		dx = dy = 0;

		ancho = img->Width / 7;
		alto = img->Height / 4;

		accion = CaminarDerecha;
	}

	void SetAccion(SpriteCorrupto value)
	{
		accion = value;
	}

	void Mover(Graphics^ g)
	{
		if (x + dx >= 0 && x + ancho + dx < g->VisibleClipBounds.Width)
			x += dx;
		if (y + dy >= 0 && y + alto + dy < g->VisibleClipBounds.Height)
			y += dy;

	}
	void Mostrar(Graphics^ g, Bitmap^ img)
	{
		Rectangle corte = Rectangle(IDx * ancho, accion * alto, ancho, alto);
		g->DrawImage(img, Area(), corte, GraphicsUnit::Pixel);

		if (dx != 0 || dy != 0) {
			IDx = (IDx + 1) % 4;
		}
	}
};
