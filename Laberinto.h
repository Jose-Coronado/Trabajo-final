#pragma once
#define F 5
#define C 17
using namespace System::Drawing;
class Laberinto
{
	
public:
	
	Laberinto() 
	{
		
	};
	~Laberinto() {};
	
	void Graficar(Graphics^ g,int anchocelda,int altocelda, Bitmap^ img)
	{
		int Matriz[F][C] = {
		{ 0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0},
		{ 1,0,1,0,0,1,0,0,0,0,0,0,0,0,0,0,1},
		{ 1,0,0,0,1,1,0,1,1,1,0,1,1,0,1,1,1},
		{ 1,0,1,0,0,0,0,0,1,0,0,0,1,0,0,0,1},
		{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1} };
	
		for (int i = 0; i < F; i++)
			for (int j = 0; j < C; j++)
			{
			
				if (Matriz[i][j] == 1)
					g->DrawImage(img, (j * anchocelda) / 2, i * altocelda, anchocelda, altocelda);//agregue imagen atte david
				else
				g->FillRectangle(Brushes::Maroon, (j * anchocelda)/2, i * altocelda, anchocelda, altocelda);
				

				
				
			}

	};
	

};
