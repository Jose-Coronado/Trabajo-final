#pragma once
#include "Entidad.h"
#include "laberinto.h"
#include "Jugador.h"

//Los sprites del corrupto solo tienen movimiento hacia la derecha :'v

enum SpriteCorrupto
{
	Abajo,
	Izquierda,
	Derecha,
	Arriba,
};

class Corrupto : public Entidad
{
private:
	SpriteCorrupto accion;
public:
	Corrupto(Bitmap^ img)
	{
		x = 300; y = 300;
		dx = dy = 0;

		ancho = img->Width / 4;
		alto = img->Height / 4;

		accion = Derecha;
	}

	void SetAccion(SpriteCorrupto value)
	{
		accion = value;
	}

	void perseguir(Jugador* jugador) {
		/*Random^ r = gcnew Random;
		short confusion = r->Next(1, 10) > 2 ? 1 : -1;*/

		Point corrupto_xy = this->get_ubicacion();
		Point jugador_xy = jugador->get_ubicacion();
		if (jugador_xy.X - corrupto_xy.X < 0) {
			x -= 2;/** confusion;*/
			SetAccion(Izquierda);
		}
		else if (jugador_xy.X - corrupto_xy.X > 0) {
			x += 2;
			SetAccion(Derecha);
		}
		if (jugador_xy.Y - corrupto_xy.Y < 0) {
			y -= 2;
			SetAccion(Arriba);
		}
		else if (jugador_xy.Y - corrupto_xy.Y > 0) {
			y += 2;
			SetAccion(Abajo);
		}
		
	}
	void Mostrar(Graphics^ g, Bitmap^ img)  {
		Rectangle corte = Rectangle(IDx * ancho, accion * alto, ancho, alto);
		g->DrawImage(img, Area(), corte, GraphicsUnit::Pixel);
		++this->IDx %= 4;
	}

};
