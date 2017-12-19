// ConvexHullAplication.cpp : Defines the entry point for the console application

#include "stdafx.h"
#include <vector>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <cstdlib>
#include <iostream>
#include <ctime>

#include "QuickHull.h"
#include "ConvexHullAplication.h"

void allegro_inicialize() {

}

int main()
{
	//*********************************************************************
	//************************Inicializando allegro************************
	//*********************************************************************

	ALLEGRO_DISPLAY *display = NULL;
	al_init_primitives_addon();
	al_init_font_addon(); // initialize the font addon
	al_init_ttf_addon();// initialize the ttf (True Type Font) addon

	if (!al_init()) {
		fprintf(stderr, "failed to initialize allegro!\n");
		return -1;
	}

	display = al_create_display(640, 480);
	if (!display) {
		fprintf(stderr, "failed to create display!\n");
		return -1;
	}

	ALLEGRO_FONT *font = al_create_builtin_font();

	if (!font) {
		fprintf(stderr, "Could not load 'arial.ttf'.\n");
		return -1;
	}

	al_clear_to_color(al_map_rgb(0, 0, 0));

	//*********************************************************************
	//************************Dibujando ejes x e y*************************
	//*********************************************************************

	//Eje x

	al_draw_line(0, 
				al_get_display_height(display)/2, 
				al_get_display_width(display), 
				al_get_display_height(display) / 2, 
				al_map_rgb(255, 255, 255), 1
				);

	al_draw_text(font,
		al_map_rgb(255, 255, 255),
		al_get_display_width(display) - 30,
		(al_get_display_height(display) / 2) + 10,
		ALLEGRO_ALIGN_CENTRE, "Eje x"
	);


	//Eje y

	al_draw_line(al_get_display_width(display)/2,
				0,
				al_get_display_width(display) / 2,
				al_get_display_height(display),
				al_map_rgb(255, 255, 255), 1
				);


	al_draw_text(font,
				al_map_rgb(255, 255, 255),
				(al_get_display_width(display)/2) +30 ,
				5,
				ALLEGRO_ALIGN_CENTRE,
				"Eje y"
				);



	//*********************************************************************
	//************************Creando el poligono**************************
	//*********************************************************************

	Polygon* p = new Polygon();
	int NumVertex = 0;
	std::srand(std::time(0));

	//Se rellena el poligono con 10 puntos aleatorios

	while (NumVertex < 10) {

		/* generate secret number between 1 and 10: */
		int randomNumberX = std::rand() % 10 - 5;
		int randomNumberY = rand() % 10 - 5;


		p->addPoint(randomNumberX, randomNumberY);
		NumVertex++;
	}
	

	//Dibujando todos los puntos aleatorios dentro de los nuevos ejes

	int pointwidth = 5;
	float jumpconstant = 40;


	for (std::vector<Point>::iterator it = p->points.begin(); it != p->points.end(); ++it) {
		int finalXPosition=((al_get_display_width(display) / 2) + (jumpconstant*it->x));
		int finalYPosition =((al_get_display_height(display) / 2) - (jumpconstant*it->y));
		al_draw_filled_rectangle(
								finalXPosition	-	pointwidth,
								finalYPosition	-	pointwidth,
								finalXPosition	+	pointwidth,
								finalYPosition	+	pointwidth,
								al_map_rgb(0, 0, 255));
	}

	
	//*********************************************************************
	//************************Calculo del quickHull************************
	//*********************************************************************

	//se crea la clase quickHull y se llama al metodo que crea el vector de puntos solucion
	QuickHull* q = new QuickHull(p);
	std::vector<Point> sol=q->generatePolygonQuickHull();


	//Dibujado del nuevo poligono con los puntos rojos y con lineas

	bool isFirst = true;
	int finalXPosition=0;
	int finalYPosition=0;
	int finalXPositionPrev = ((al_get_display_width(display) / 2) + (jumpconstant*sol.back().x));
	int finalYPositionPrev = ((al_get_display_height(display) / 2) - (jumpconstant*sol.back().y));

	for (std::vector<Point>::iterator it = sol.begin(); it != sol.end(); ++it) {

		//calculo de posiciones en la ventana
		finalXPosition = ((al_get_display_width(display) / 2) + (jumpconstant*it->x));
		finalYPosition = ((al_get_display_height(display) / 2) - (jumpconstant*it->y));

		//dibujado del punto
		al_draw_filled_rectangle(
			finalXPosition - pointwidth,
			finalYPosition - pointwidth,
			finalXPosition + pointwidth,
			finalYPosition + pointwidth,
			al_map_rgb(255, 0, 0));

		//dibujado de la linea
		al_draw_line(finalXPositionPrev, finalYPositionPrev, finalXPosition, finalYPosition, al_map_rgb(255, 0, 0),1);

		finalXPositionPrev = finalXPosition;
		finalYPositionPrev = finalYPosition;
		
	}
	
	al_flip_display();
	system("pause");

	//Limpiando
	al_destroy_display(display);



	
}

