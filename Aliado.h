#pragma once
#include "Personajes.h"
#include "laberinto.h"
#include "Jugador.h"

//Los sprites del corrupto solo tienen movimiento hacia la derecha :'v

enum SpriteAliado
{
	Abaj,
	Izq,
	Der,
	Arr,
};

class Aliado : public Entidad
{
private:
	SpriteAliado accion;
public:
	Aliado(Bitmap^ img)
	{
		x = 300; y = 300;
		dx = dy = 0;

		ancho = img->Width / 4;
		alto = img->Height / 4;

		accion = Der;
	}

	void SetAccion(SpriteAliado value)
	{
		accion = value;
	}

	void perseguir(Jugador* jugador) {
		/*Random^ r = gcnew Random;
		short confusion = r->Next(1, 10) > 2 ? 1 : -1;*/

		Point aliado_xy = this->get_ubicacion();
		Point jugador_xy = jugador->get_ubicacion();
		if (jugador_xy.X - aliado_xy.X < 0) {
			x -= 2;/** confusion;*/
			SetAccion(Izq);
		}
		else if (jugador_xy.X - aliado_xy.X > 0) {
			x += 2;
			SetAccion(Der);
		}
		if (jugador_xy.Y - aliado_xy.Y < 0) {
			y -= 2;
			SetAccion(Arr);
		}
		else if (jugador_xy.Y - aliado_xy.Y > 0) {
			y += 2;
			SetAccion(Abaj);
		}

	}
	void Mostrar(Graphics^ g, Bitmap^ img) {
		Rectangle corte = Rectangle(IDx * ancho, accion * alto, ancho, alto);
		g->DrawImage(img, Area(), corte, GraphicsUnit::Pixel);
		++this->IDx %= 4;
	}

};
