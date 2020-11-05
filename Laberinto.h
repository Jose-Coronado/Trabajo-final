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
	
	void Graficar(Graphics^ g,int anchocelda,int altocelda)
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
					g->FillRectangle(Brushes::Black, (j * anchocelda)/2, i * altocelda, anchocelda, altocelda);
				else
				g->FillRectangle(Brushes::Yellow, (j * anchocelda)/2, i * altocelda, anchocelda, altocelda);//de amarillo se ve chevere, atte david
				


				
			}

	};
	

};
