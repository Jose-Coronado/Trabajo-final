#pragma once
#include "Jugador.h"
#include "Laberinto.h"
 

ref class ControladorJuego
{
private:
	Jugador* jugador;

	Laberinto* laberinto ;
	Bitmap^ imgLaberinto;
	Bitmap^ imgJugador;
public:
	ControladorJuego()
	{
	 
		imgJugador = gcnew Bitmap("Imagenes\\personaje.png");
		imgLaberinto = gcnew Bitmap("Imagenes\\laberinto1.png");
		imgCorrupto = gcnew Bitmap("Imagenes\\corruptos.png")

		jugador = new Jugador(imgJugador);
		// Se debe añadir a los corruptos como un arreglo no? Revisar Template.h
	 
	}
	~ControladorJuego()
	{
		delete jugador;
	}

	void MovimientoJugador(bool accion, Keys tecla)
	{
		int v = 3;

		if (accion == true)
		{
			if (tecla == Keys::Up)
			{
				jugador->SetDY(-v);
				jugador->SetAccion(CaminarArriba);
			}
			else if (tecla == Keys::Down)
			{
				jugador->SetDY(v);
				jugador->SetAccion(CaminarAbajo);
			}
			else if (tecla == Keys::Left)
			{
				jugador->SetDX(-v);
				jugador->SetAccion(CaminarIzquierda);
			}
			else if (tecla == Keys::Right)
			{
				jugador->SetDX(v);
				jugador->SetAccion(CaminarDerecha);
			}
		}
		else
		{
			if (tecla == Keys::Up)
				jugador->SetDY(0);
			else if (tecla == Keys::Down)
				jugador->SetDY(0);
			else if (tecla == Keys::Left)
				jugador->SetDX(0);
			else if (tecla == Keys::Right)
				jugador->SetDX(0);
		}
	}

	void Mover(Graphics^ g)
	{
		
			jugador->Mover(g);

		
	}
	void Mostrar(Graphics^ g)
	{
		int anchocelda = jugador->GetAncho();
		int altocelda = jugador->GetAlto();
		laberinto->Graficar(g,anchocelda,altocelda,imgLaberinto);//imagen agregada
		jugador->Mostrar(g, imgJugador);
	}
	
};
