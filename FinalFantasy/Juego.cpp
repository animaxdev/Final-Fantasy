#include "Juego.h"

#include <algorithm>
#include <iterator>

#include "MonedaObjeto.h"
#include "Juego.h"
#include "Constantes.h"
#include "Controles.h"
#include "Fuentes.h"
#include "Imagenes.h"
#include "Escenas.h"
#include "Mapa.h"

namespace FinalFantasy {

	//Definicion de las constantes
	const int MYFORM_WIDTH = 16;
	const int MYFORM_HEIGHT = 10;
	const int RESOLUCION_X = 56;
	const int RESOLUCION_Y = 56;
	const int MYFORM_SIZE_WIDTH = MYFORM_WIDTH * RESOLUCION_X;
	const int MYFORM_SIZE_HEIGHT = MYFORM_HEIGHT * RESOLUCION_Y;
	const float TAMANIO_LETRAS = 20.0f;
	const int VELOCIDAD_TIMER = 50;

	Terreno TERRENOS_COLISIONANTES[] = { Maceta, Agua };

	void inicializarMapas() {
		Mapa ^nuevo_mapa;

		nuevo_mapa = Mapa::crearMapa(Juego::cabeza);
		Juego::cabeza->matriz_terreno = gcnew array<Terreno, 2> {
			{ Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta},
			{ Maceta, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Maceta },
			{ Maceta, Pasto, Granito, Granito, Granito, Granito, Granito, Granito, Granito, Granito, Granito, Granito, Granito, Granito, Pasto, Maceta },
			{ Maceta, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Maceta },
			{ Maceta, Pasto, Pasto, Pasto, Pasto, Pasto, Agua, Agua, Agua, Agua, Pasto, Pasto, Pasto, Pasto, Pasto, Maceta },
			{ Maceta, Pasto, Granito, Pasto, Pasto, Pasto, Agua, Agua, Agua, Agua, Pasto, Pasto, Pasto, Granito, Pasto, Maceta },
			{ Maceta, Pasto, Granito, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Granito, Pasto, Maceta },
			{ Maceta, Pasto, Granito, Granito, Granito, Granito, Pasto, Pasto, Pasto, Pasto, Granito, Granito, Granito, Granito, Pasto, Maceta },
			{ Maceta, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Maceta },
			{ Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta }
		};
		Juego::cabeza->objetos = gcnew List<Objeto ^>();
		Juego::cabeza->generarCapaTerreno();

		nuevo_mapa = Mapa::crearMapa(Juego::cabeza);
		nuevo_mapa->matriz_terreno = gcnew array<Terreno, 2> {
			{ Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta},
			{ Maceta, Pasto, Roca, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Maceta },
			{ Maceta, Pasto, Pasto, Pasto, Pasto, Pasto, Roca, Pasto, Pasto, Pasto, Tierra, Tierra, Tierra, Tierra, Pasto, Maceta },
			{ Maceta, Pasto, Pasto, Pasto, Granito, Granito, Granito, Granito, Granito, Pasto, Tierra, Tierra, Tierra, Tierra, Pasto, Maceta },
			{ Maceta, Pasto, Pasto, Pasto, Granito, Agua, Agua, Agua, Granito, Pasto, Tierra, Tierra, Tierra, Tierra, Pasto, Maceta },
			{ Maceta, Pasto, Pasto, Pasto, Granito, Granito, Granito, Granito, Granito, Pasto, Tierra, Tierra, Tierra, Tierra, Pasto, Maceta },
			{ Maceta, Pasto, Roca, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Tierra, Tierra, Tierra, Tierra, Pasto, Maceta },
			{ Maceta, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Roca, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Maceta },
			{ Maceta, Pasto, Pasto, Pasto, Pasto, Roca, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Maceta },
			{ Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta }
		};
		nuevo_mapa->objetos = gcnew List<Objeto ^>();
		nuevo_mapa->generarCapaTerreno();

		nuevo_mapa = Mapa::crearMapa(Juego::cabeza);
		nuevo_mapa->matriz_terreno = gcnew array<Terreno, 2> {
			{ Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta},
			{ Maceta, Pasto, Pasto, Hielo, Pasto, Pasto, Pasto, Pasto, Arena, Arena, Pasto, Pasto, Pasto, Pasto, Pasto, Maceta },
			{ Maceta, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Hielo, Hielo, Pasto, Pasto, Maceta },
			{ Maceta, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Hielo, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Maceta },
			{ Maceta, Pasto, Hielo, Pasto, Pasto, Hielo, Hielo, Hielo, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Maceta },
			{ Maceta, Pasto, Hielo, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Hielo, Pasto, Pasto, Hielo, Pasto, Maceta },
			{ Maceta, Pasto, Pasto, Pasto, Pasto, Pasto, Hielo, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Hielo, Pasto, Maceta },
			{ Maceta, Pasto, Pasto, Pasto, Hielo, Pasto, Pasto, Pasto, Hielo, Hielo, Pasto, Pasto, Pasto, Pasto, Pasto, Maceta },
			{ Maceta, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Maceta },
			{ Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta }
		};
		nuevo_mapa->objetos = gcnew List<Objeto ^>();
		nuevo_mapa->generarCapaTerreno();

		nuevo_mapa = Mapa::crearMapa(Juego::cabeza);
		nuevo_mapa->matriz_terreno = gcnew array<Terreno, 2> {
			{ Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta},
			{ Maceta, Tierra, Tierra, Tierra, Granito, Arena, Arena, Arena, Granito, Agua, Tierra, Tierra, Tierra, Tierra, Tierra, Maceta },
			{ Maceta, Tierra, Tierra, Tierra, Granito, Arena, Arena, Arena, Granito, Agua, Agua, Tierra, Tierra, Tierra, Tierra, Maceta },
			{ Maceta, Tierra, Granito, Granito, Granito, Arena, Arena, Arena, Granito, Granito, Agua, Tierra, Tierra, Tierra, Tierra, Maceta },
			{ Maceta, Tierra, Granito, Arena, Arena, Arena, Arena, Arena, Arena, Granito, Agua, Tierra, Tierra, Tierra, Tierra, Maceta },
			{ Maceta, Tierra, Granito, Arena, Tierra, Tierra, Tierra, Tierra, Arena, Granito, Agua, Tierra, Tierra, Tierra, Tierra, Maceta },
			{ Maceta, Tierra, Agua, Agua, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Agua, Tierra, Tierra, Tierra, Tierra, Maceta },
			{ Maceta, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Maceta },
			{ Maceta, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Maceta },
			{ Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta }
		};
		nuevo_mapa->objetos = gcnew List<Objeto ^>();
		nuevo_mapa->generarCapaTerreno();

		nuevo_mapa = Mapa::crearMapa(Juego::cabeza);
		nuevo_mapa->matriz_terreno = gcnew array<Terreno, 2> {
			{ Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta},
			{ Maceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Maceta },
			{ Maceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Maceta },
			{ Maceta, Tierra, Tierra, Agua, Roca, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Roca, Agua, Tierra, Tierra, Maceta },
			{ Maceta, Tierra, Tierra, Agua, Roca, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Roca, Agua, Tierra, Tierra, Maceta },
			{ Maceta, Tierra, Tierra, Agua, Roca, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Roca, Agua, Tierra, Tierra, Maceta },
			{ Maceta, Tierra, Tierra, Agua, Roca, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Roca, Agua, Tierra, Tierra, Maceta },
			{ Maceta, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Maceta },
			{ Maceta, Tierra, Tierra, Tierra, Tierra, Tierra, Arena, Arena, Arena, Arena, Tierra, Tierra, Tierra, Tierra, Tierra, Maceta },
			{ Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta }
		};
		nuevo_mapa->objetos = gcnew List<Objeto ^>();
		nuevo_mapa->generarCapaTerreno();

		nuevo_mapa = Mapa::crearMapa(Juego::cabeza);
		nuevo_mapa->matriz_terreno = gcnew array<Terreno, 2> {
			{ Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta },
			{ Maceta, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Maceta },
			{ Maceta, Pasto, Granito, Granito, Granito, Granito, Granito, Granito, Granito, Granito, Granito, Granito, Granito, Granito, Pasto, Maceta },
			{ Maceta, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Maceta },
			{ Maceta, Pasto, Pasto, Pasto, Pasto, Pasto, Agua, Agua, Agua, Agua, Pasto, Pasto, Pasto, Pasto, Pasto, Maceta },
			{ Maceta, Pasto, Granito, Pasto, Pasto, Pasto, Agua, Agua, Agua, Agua, Pasto, Pasto, Pasto, Granito, Pasto, Maceta },
			{ Maceta, Pasto, Granito, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Granito, Pasto, Maceta },
			{ Maceta, Pasto, Granito, Granito, Granito, Granito, Pasto, Pasto, Pasto, Pasto, Granito, Granito, Granito, Granito, Pasto, Maceta },
			{ Maceta, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Maceta },
			{ Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta }
		};
		nuevo_mapa->objetos = gcnew List<Objeto ^>();
		nuevo_mapa->generarCapaTerreno();

		nuevo_mapa = Mapa::crearMapa(Juego::cabeza);
		nuevo_mapa->matriz_terreno = gcnew array<Terreno, 2> {
			{ Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta },
			{ Maceta, Pasto, Roca, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Maceta },
			{ Maceta, Pasto, Pasto, Pasto, Pasto, Pasto, Roca, Pasto, Pasto, Pasto, Tierra, Tierra, Tierra, Tierra, Pasto, Maceta },
			{ Maceta, Pasto, Pasto, Pasto, Granito, Granito, Granito, Granito, Granito, Pasto, Tierra, Tierra, Tierra, Tierra, Pasto, Maceta },
			{ Maceta, Pasto, Pasto, Pasto, Granito, Agua, Agua, Agua, Granito, Pasto, Tierra, Tierra, Tierra, Tierra, Pasto, Maceta },
			{ Maceta, Pasto, Pasto, Pasto, Granito, Granito, Granito, Granito, Granito, Pasto, Tierra, Tierra, Tierra, Tierra, Pasto, Maceta },
			{ Maceta, Pasto, Roca, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Tierra, Tierra, Tierra, Tierra, Pasto, Maceta },
			{ Maceta, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Roca, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Maceta },
			{ Maceta, Pasto, Pasto, Pasto, Pasto, Roca, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Maceta },
			{ Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta }
		};
		nuevo_mapa->objetos = gcnew List<Objeto ^>();
		nuevo_mapa->generarCapaTerreno();


		nuevo_mapa = Mapa::crearMapa(Juego::cabeza);
		nuevo_mapa->matriz_terreno = gcnew array<Terreno, 2> {
			{ Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta },
			{ Maceta, Pasto, Pasto, Hielo, Pasto, Pasto, Pasto, Pasto, Arena, Arena, Pasto, Pasto, Pasto, Pasto, Pasto, Maceta },
			{ Maceta, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Hielo, Hielo, Pasto, Pasto, Maceta },
			{ Maceta, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Hielo, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Maceta },
			{ Maceta, Pasto, Hielo, Pasto, Pasto, Hielo, Hielo, Hielo, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Maceta },
			{ Maceta, Pasto, Hielo, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Hielo, Pasto, Pasto, Hielo, Pasto, Maceta },
			{ Maceta, Pasto, Pasto, Pasto, Pasto, Pasto, Hielo, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Hielo, Pasto, Maceta },
			{ Maceta, Pasto, Pasto, Pasto, Hielo, Pasto, Pasto, Pasto, Hielo, Hielo, Pasto, Pasto, Pasto, Pasto, Pasto, Maceta },
			{ Maceta, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Maceta },
			{ Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta }
		};
		nuevo_mapa->objetos = gcnew List<Objeto ^>();
		nuevo_mapa->generarCapaTerreno();

		nuevo_mapa = Mapa::crearMapa(Juego::cabeza);
		nuevo_mapa->matriz_terreno = gcnew array<Terreno, 2> {
			{ Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta },
			{ Maceta, Tierra, Tierra, Tierra, Granito, Arena, Arena, Arena, Granito, Agua, Tierra, Tierra, Tierra, Tierra, Tierra, Maceta },
			{ Maceta, Tierra, Tierra, Tierra, Granito, Arena, Arena, Arena, Granito, Agua, Agua, Tierra, Tierra, Tierra, Tierra, Maceta },
			{ Maceta, Tierra, Granito, Granito, Granito, Arena, Arena, Arena, Granito, Granito, Agua, Tierra, Tierra, Tierra, Tierra, Maceta },
			{ Maceta, Tierra, Granito, Arena, Arena, Arena, Arena, Arena, Arena, Granito, Agua, Tierra, Tierra, Tierra, Tierra, Maceta },
			{ Maceta, Tierra, Granito, Arena, Tierra, Tierra, Tierra, Tierra, Arena, Granito, Agua, Tierra, Tierra, Tierra, Tierra, Maceta },
			{ Maceta, Tierra, Agua, Agua, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Agua, Tierra, Tierra, Tierra, Tierra, Maceta },
			{ Maceta, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Maceta },
			{ Maceta, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Maceta },
			{ Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta }
		};
		nuevo_mapa->objetos = gcnew List<Objeto ^>();
		nuevo_mapa->generarCapaTerreno();

		nuevo_mapa = Mapa::crearMapa(Juego::cabeza);
		nuevo_mapa->matriz_terreno = gcnew array<Terreno, 2> {
			{ Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta },
			{ Maceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Maceta },
			{ Maceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Maceta },
			{ Maceta, Tierra, Tierra, Agua, Roca, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Roca, Agua, Tierra, Tierra, Maceta },
			{ Maceta, Tierra, Tierra, Agua, Roca, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Roca, Agua, Tierra, Tierra, Maceta },
			{ Maceta, Tierra, Tierra, Agua, Roca, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Roca, Agua, Tierra, Tierra, Maceta },
			{ Maceta, Tierra, Tierra, Agua, Roca, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Roca, Agua, Tierra, Tierra, Maceta },
			{ Maceta, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Maceta },
			{ Maceta, Tierra, Tierra, Tierra, Tierra, Tierra, Arena, Arena, Arena, Arena, Tierra, Tierra, Tierra, Tierra, Tierra, Maceta },
			{ Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta }
		};
		nuevo_mapa->objetos = gcnew List<Objeto ^>();
		nuevo_mapa->generarCapaTerreno();


		nuevo_mapa = Mapa::crearMapa(Juego::cabeza);
		nuevo_mapa->matriz_terreno = gcnew array<Terreno, 2> {
			{ Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta },
			{ Maceta, Tierra, Lava, Tierra, Tierra, Tierra, Tierra, Tierra, Granito, Lava, Lava, Lava, Lava, Lava, Tierra, Maceta },
			{ Maceta, Tierra, Lava, Tierra, Tierra, Tierra, Tierra, Tierra, Granito, Granito, Granito, Granito, Granito, Lava, Tierra, Maceta },
			{ Maceta, Tierra, Lava, Tierra, Tierra, Pasto, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Granito, Lava, Tierra, Maceta },
			{ Maceta, Tierra, Lava, Lava, Tierra, Loceta, Loceta, Loceta, Tierra, Granito, Granito, Granito, Granito, Lava, Tierra, Maceta },
			{ Maceta, Tierra, Lava, Lava, Tierra, Loceta, Loceta, Loceta, Tierra, Granito, Lava, Lava, Lava, Lava, Tierra, Maceta },
			{ Maceta, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Granito, Lava, Tierra, Tierra, Tierra, Tierra, Maceta },
			{ Maceta, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Granito, Lava, Tierra, Tierra, Tierra, Tierra, Maceta },
			{ Maceta, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Maceta },
			{ Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta } };
		nuevo_mapa->objetos = gcnew List<Objeto ^>();
		nuevo_mapa->generarCapaTerreno();

		nuevo_mapa = Mapa::crearMapa(Juego::cabeza);
		nuevo_mapa->matriz_terreno = gcnew array<Terreno, 2> {
			{ Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta },
			{ Maceta, Hielo, Hielo, Roca, Roca, Roca, Roca, Roca, Hielo, Hielo, Hielo, Hielo, Hielo, Hielo, Hielo, Maceta },
			{ Maceta, Hielo, Hielo, Roca, Hielo, Hielo, Hielo, Roca, Hielo, Hielo, Hielo, Hielo, Hielo, Roca, Hielo, Maceta },
			{ Maceta, Hielo, Hielo, Roca, Hielo, Roca, Roca, Roca, Hielo, Hielo, Roca, Roca, Roca, Roca, Hielo, Maceta },
			{ Maceta, Hielo, Roca, Roca, Hielo, Roca, Hielo, Hielo, Hielo, Hielo, Roca, Hielo, Hielo, Hielo, Hielo, Maceta },
			{ Maceta, Hielo, Hielo, Hielo, Hielo, Roca, Hielo, Agua, Agua, Hielo, Roca, Hielo, Hielo, Hielo, Hielo, Maceta },
			{ Maceta, Hielo, Hielo, Hielo, Hielo, Roca, Hielo, Agua, Agua, Hielo, Roca, Roca, Roca, Roca, Hielo, Maceta },
			{ Maceta, Hielo, Roca, Roca, Roca, Roca, Hielo, Agua, Agua, Hielo, Hielo, Hielo, Hielo, Hielo, Hielo, Maceta },
			{ Maceta, Hielo, Hielo, Hielo, Hielo, Hielo, Hielo, Hielo, Hielo, Hielo, Hielo, Hielo, Hielo, Hielo, Hielo, Maceta },
			{ Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta } };
		nuevo_mapa->objetos = gcnew List<Objeto ^>();
		nuevo_mapa->generarCapaTerreno();


		nuevo_mapa = Mapa::crearMapa(Juego::cabeza);
		nuevo_mapa->matriz_terreno = gcnew array<Terreno, 2> {
			{ Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta },
			{ Maceta, Hielo, Hielo, Hielo, Hielo, Hielo, Hielo, Hielo, Tejado, Tejado, Hielo, Pasto, Hielo, Hielo, Hielo, Maceta },
			{ Maceta, Hielo, Agua, Agua, Agua, Agua, Agua, Agua, Tejado, Tejado, Hielo, Pasto, Pasto, Hielo, Hielo, Maceta },
			{ Maceta, Hielo, Agua, Agua, Agua, Agua, Agua, Agua, Hielo, Hielo, Hielo, Hielo, Hielo, Hielo, Hielo, Maceta },
			{ Maceta, Hielo, Hielo, Pasto, Hielo, Hielo, Hielo, Hielo, Hielo, Pasto, Hielo, Hielo, Pasto, Pasto, Hielo, Maceta },
			{ Maceta, Hielo, Hielo, Pasto, Pasto, Pasto, Hielo, Hielo, Pasto, Pasto, Hielo, Hielo, Hielo, Pasto, Hielo, Maceta },
			{ Maceta, Hielo, Hielo, Hielo, Hielo, Pasto, Hielo, Hielo, Pasto, Hielo, Hielo, Pasto, Hielo, Hielo, Hielo, Maceta },
			{ Maceta, Hielo, Hielo, Hielo, Hielo, Hielo, Hielo, Hielo, Hielo, Hielo, Pasto, Pasto, Hielo, Hielo, Hielo, Maceta },
			{ Maceta, Hielo, Hielo, Hielo, Hielo, Hielo, Hielo, Hielo, Hielo, Hielo, Hielo, Hielo, Hielo, Hielo, Hielo, Maceta },
			{ Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta } };
		nuevo_mapa->objetos = gcnew List<Objeto ^>();
		nuevo_mapa->generarCapaTerreno();


		nuevo_mapa = Mapa::crearMapa(Juego::cabeza);
		nuevo_mapa->matriz_terreno = gcnew array<Terreno, 2> {
			{ Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta },
			{ Maceta, Hielo, Hielo, Hielo, Hielo, Hielo, Hielo, Hielo, Hielo, Hielo, Hielo, Hielo, Hielo, Hielo, Hielo, Maceta },
			{ Maceta, Hielo, Lava, Lava, Lava, Lava, Lava, Hielo, Hielo, Lava, Hielo, Lava, Lava, Lava, Lava, Maceta },
			{ Maceta, Hielo, Hielo, Hielo, Lava, Hielo, Hielo, Hielo, Hielo, Lava, Hielo, Hielo, Hielo, Hielo, Lava, Maceta },
			{ Maceta, Hielo, Lava, Lava, Lava, Lava, Lava, Hielo, Hielo, Lava, Lava, Lava, Lava, Lava, Lava, Maceta },
			{ Maceta, Hielo, Hielo, Hielo, Hielo, Hielo, Hielo, Hielo, Hielo, Hielo, Hielo, Hielo, Hielo, Hielo, Hielo, Maceta },
			{ Maceta, Hielo, Hielo, Hielo, Hielo, Hielo, Hielo, Hielo, Hielo, Hielo, Lava, Lava, Lava, Hielo, Hielo, Maceta },
			{ Maceta, Tejado, Tejado, Hielo, Hielo, Hielo, Hielo, Lava, Lava, Lava, Lava, Hielo, Hielo, Hielo, Hielo, Maceta },
			{ Maceta, Tejado, Tejado, Hielo, Hielo, Hielo, Hielo, Hielo, Hielo, Hielo, Hielo, Hielo, Hielo, Hielo, Hielo, Maceta },
			{ Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta } };
		nuevo_mapa->objetos = gcnew List<Objeto ^>();
		nuevo_mapa->generarCapaTerreno();


		nuevo_mapa = Mapa::crearMapa(Juego::cabeza);
		nuevo_mapa->matriz_terreno = gcnew array<Terreno, 2> {
			{ Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta },
			{ Maceta, Tierra, Tejado, Tejado, Tejado, Tejado, Tejado, Tejado, Tejado, Tejado, Tejado, Tejado, Tejado, Tejado, Tejado, Maceta },
			{ Maceta, Tierra, Tejado, Tejado, Tejado, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Tejado, Tejado, Maceta },
			{ Maceta, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Maceta },
			{ Maceta, Pasto, Pasto, Tierra, Arena, Arena, Arena, Arena, Arena, Arena, Arena, Arena, Tierra, Pasto, Pasto, Maceta },
			{ Maceta, Pasto, Pasto, Tierra, Arena, Arena, Arena, Arena, Arena, Arena, Arena, Arena, Tierra, Pasto, Pasto, Maceta },
			{ Maceta, Pasto, Pasto, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Pasto, Pasto, Maceta },
			{ Maceta, Pasto, Pasto, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Maceta },
			{ Maceta, Pasto, Pasto, Agua, Agua, Agua, Tierra, Tierra, Tierra, Agua, Agua, Agua, Agua, Agua, Agua, Maceta },
			{ Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta } };
		nuevo_mapa->objetos = gcnew List<Objeto ^>();
		nuevo_mapa->generarCapaTerreno();


		nuevo_mapa = Mapa::crearMapa(Juego::cabeza);
		nuevo_mapa->matriz_terreno = gcnew array<Terreno, 2> {
			{ Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta },
			{ Maceta, Tejado, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Maceta },
			{ Maceta, Tejado, Lava, Lava, Lava, Lava, Lava, Tierra, Tierra, Lava, Lava, Lava, Lava, Lava, Tierra, Maceta },
			{ Maceta, Tejado, Tierra, Tierra, Lava, Tierra, Tierra, Tierra, Tierra, Tierra, Lava, Tierra, Tierra, Tierra, Tierra, Maceta },
			{ Maceta, Tejado, Tierra, Tierra, Lava, Tierra, Tierra, Tierra, Tierra, Tierra, Lava, Lava, Lava, Tierra, Tierra, Maceta },
			{ Maceta, Tejado, Tierra, Tierra, Lava, Lava, Lava, Tierra, Tierra, Tierra, Tierra, Tierra, Lava, Tierra, Tierra, Maceta },
			{ Maceta, Tejado, Tierra, Tierra, Tierra, Lava, Tierra, Tierra, Loceta, Loceta, Loceta, Tierra, Lava, Lava, Tierra, Maceta },
			{ Maceta, Tejado, Tejado, Tierra, Tierra, Lava, Tierra, Loceta, Loceta, Loceta, Loceta, Tierra, Tierra, Tierra, Tierra, Maceta },
			{ Maceta, Tejado, Tejado, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Tejado, Tejado, Maceta },
			{ Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta } };
		nuevo_mapa->objetos = gcnew List<Objeto ^>();
		nuevo_mapa->generarCapaTerreno();


		nuevo_mapa = Mapa::crearMapa(Juego::cabeza);
		nuevo_mapa->matriz_terreno = gcnew array<Terreno, 2> {
			{ Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta },
			{ Maceta, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Maceta },
			{ Maceta, Tierra, Arena, Arena, Tierra, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Tierra, Arena, Arena, Tierra, Maceta },
			{ Maceta, Tierra, Arena, Arena, Tierra, Tierra, Tierra, Loceta, Loceta, Tierra, Tierra, Tierra, Arena, Arena, Tierra, Maceta },
			{ Maceta, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Loceta, Loceta, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Maceta },
			{ Maceta, Tierra, Agua, Agua, Agua, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Agua, Agua, Agua, Tierra, Maceta },
			{ Maceta, Tierra, Arena, Arena, Agua, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Agua, Arena, Arena, Tierra, Maceta },
			{ Maceta, Tierra, Arena, Arena, Agua, Tierra, Pasto, Pasto, Pasto, Pasto, Tierra, Agua, Arena, Arena, Tierra, Maceta },
			{ Maceta, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Maceta },
			{ Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta } };
		nuevo_mapa->objetos = gcnew List<Objeto ^>();
		nuevo_mapa->generarCapaTerreno();


		nuevo_mapa = Mapa::crearMapa(Juego::cabeza);
		nuevo_mapa->matriz_terreno = gcnew array<Terreno, 2> {
			{ Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta },
			{ Maceta, Pasto, Pasto, Arena, Arena, Arena, Arena, Arena, Arena, Arena, Arena, Arena, Arena, Tejado, Tejado, Maceta },
			{ Maceta, Pasto, Pasto, Arena, Granito, Granito, Granito, Granito, Arena, Arena, Arena, Granito, Arena, Arena, Arena, Maceta },
			{ Maceta, Arena, Arena, Arena, Arena, Arena, Arena, Granito, Arena, Arena, Arena, Granito, Arena, Granito, Arena, Maceta },
			{ Maceta, Arena, Granito, Arena, Arena, Arena, Arena, Granito, Granito, Granito, Granito, Granito, Granito, Granito, Arena, Maceta },
			{ Maceta, Arena, Granito, Granito, Granito, Arena, Arena, Arena, Granito, Arena, Arena, Granito, Arena, Granito, Arena, Maceta },
			{ Maceta, Arena, Granito, Arena, Arena, Arena, Arena, Granito, Granito, Arena, Arena, Granito, Arena, Arena, Arena, Maceta },
			{ Maceta, Arena, Arena, Arena, Arena, Arena, Arena, Arena, Arena, Arena, Arena, Arena, Arena, Arena, Arena, Maceta },
			{ Maceta, Tejado, Tejado, Tejado, Tejado, Arena, Arena, Arena, Arena, Arena, Arena, Tejado, Tejado, Tejado, Tejado, Maceta },
			{ Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta } };
		nuevo_mapa->objetos = gcnew List<Objeto ^>();
		nuevo_mapa->generarCapaTerreno();


		nuevo_mapa = Mapa::crearMapa(Juego::cabeza);
		nuevo_mapa->matriz_terreno = gcnew array<Terreno, 2> {
			{ Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta },
			{ Maceta, Roca, Roca, Roca, Roca, Roca, Lodo, Lodo, Agua, Agua, Agua, Lodo, Lodo, Lodo, Lodo, Maceta },
			{ Maceta, Roca, Granito, Granito, Granito, Granito, Lodo, Lodo, Agua, Agua, Agua, Lodo, Tejado, Roca, Lodo, Maceta },
			{ Maceta, Lodo, Tejado, Tejado, Granito, Tejado, Tejado, Lodo, Lodo, Lodo, Lodo, Lodo, Tejado, Granito, Lodo, Maceta },
			{ Maceta, Lodo, Tejado, Tejado, Granito, Tejado, Tejado, Granito, Lodo, Lodo, Lodo, Lodo, Tejado, Roca, Lodo, Maceta },
			{ Maceta, Lodo, Lodo, Granito, Granito, Granito, Granito, Granito, Lodo, Lodo, Lodo, Lodo, Tejado, Roca, Lodo, Maceta },
			{ Maceta, Lodo, Lodo, Roca, Granito, Roca, Roca, Roca, Lodo, Lodo, Lodo, Lodo, Tejado, Granito, Lodo, Maceta },
			{ Maceta, Lodo, Lodo, Lodo, Lodo, Lodo, Lodo, Lodo, Lodo, Lodo, Lodo, Lodo, Tejado, Roca, Lodo, Maceta },
			{ Maceta, Lodo, Lodo, Lodo, Lodo, Lodo, Lodo, Lodo, Lodo, Lodo, Lodo, Lodo, Lodo, Lodo, Lodo, Maceta },
			{ Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta } };
		nuevo_mapa->objetos = gcnew List<Objeto ^>();
		nuevo_mapa->generarCapaTerreno();


		nuevo_mapa = Mapa::crearMapa(Juego::cabeza);
		nuevo_mapa->matriz_terreno = gcnew array<Terreno, 2> {
			{ Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta },
			{ Maceta, Lodo, Lodo, Lodo, Lodo, Lodo, Lodo, Lodo, Lodo, Lodo, Lodo, Lodo, Tejado, Tejado, Tejado, Maceta },
			{ Maceta, Lodo, Roca, Roca, Agua, Agua, Agua, Agua, Agua, Lodo, Lodo, Lodo, Roca, Roca, Roca, Maceta },
			{ Maceta, Lodo, Roca, Roca, Agua, Agua, Agua, Agua, Agua, Lodo, Lodo, Lodo, Roca, Agua, Roca, Maceta },
			{ Maceta, Lodo, Lodo, Lodo, Agua, Agua, Lodo, Lodo, Lodo, Lodo, Lodo, Lodo, Roca, Agua, Roca, Maceta },
			{ Maceta, Lodo, Lodo, Lodo, Agua, Agua, Lodo, Lodo, Pasto, Pasto, Pasto, Lodo, Roca, Agua, Roca, Maceta },
			{ Maceta, Lodo, Lodo, Lodo, Lodo, Lodo, Lodo, Lodo, Pasto, Pasto, Pasto, Lodo, Roca, Agua, Roca, Maceta },
			{ Maceta, Lodo, Lodo, Lodo, Lodo, Lodo, Lodo, Lodo, Pasto, Pasto, Pasto, Lodo, Roca, Roca, Roca, Maceta },
			{ Maceta, Lodo, Lodo, Lodo, Lodo, Lodo, Lodo, Lodo, Lodo, Lodo, Lodo, Lodo, Lodo, Lodo, Lodo, Maceta },
			{ Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta } };
		nuevo_mapa->objetos = gcnew List<Objeto ^>();
		nuevo_mapa->generarCapaTerreno();


		nuevo_mapa = Mapa::crearMapa(Juego::cabeza);
		nuevo_mapa->matriz_terreno = gcnew array<Terreno, 2> {
			{ Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta },
			{ Maceta, Arena, Arena, Arena, Roca, Lava, Lava, Lava, Lava, Lava, Lava, Roca, Arena, Arena, Arena, Maceta },
			{ Maceta, Arena, Granito, Granito, Roca, Lava, Lava, Lava, Lava, Lava, Lava, Roca, Granito, Granito, Arena, Maceta },
			{ Maceta, Arena, Granito, Granito, Roca, Roca, Roca, Roca, Roca, Roca, Roca, Roca, Granito, Granito, Arena, Maceta },
			{ Maceta, Arena, Arena, Arena, Arena, Arena, Arena, Arena, Arena, Arena, Arena, Arena, Arena, Arena, Arena, Maceta },
			{ Maceta, Arena, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Arena, Maceta },
			{ Maceta, Arena, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Arena, Maceta },
			{ Maceta, Arena, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Arena, Maceta },
			{ Maceta, Arena, Arena, Arena, Arena, Arena, Arena, Arena, Arena, Arena, Arena, Arena, Arena, Arena, Arena, Maceta },
			{ Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta } };
		nuevo_mapa->objetos = gcnew List<Objeto ^>();
		nuevo_mapa->generarCapaTerreno();


		nuevo_mapa = Mapa::crearMapa(Juego::cabeza);
		nuevo_mapa->matriz_terreno = gcnew array<Terreno, 2> {
			{ Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta },
			{ Maceta, Lodo, Lodo, Lodo, Lodo, Lodo, Tejado, Tejado, Tejado, Tejado, Tejado, Lodo, Lodo, Pasto, Pasto, Maceta },
			{ Maceta, Lodo, Lodo, Lodo, Lodo, Lodo, Lodo, Lodo, Lodo, Lodo, Lodo, Lodo, Lodo, Pasto, Pasto, Maceta },
			{ Maceta, Lodo, Roca, Roca, Roca, Roca, Lodo, Lodo, Lodo, Lodo, Lodo, Lodo, Lodo, Pasto, Pasto, Maceta },
			{ Maceta, Lodo, Lodo, Roca, Lodo, Roca, Lodo, Lodo, Lodo, Lodo, Loceta, Loceta, Loceta, Pasto, Pasto, Maceta },
			{ Maceta, Lodo, Lodo, Roca, Lodo, Roca, Lodo, Lodo, Lodo, Lodo, Loceta, Agua, Agua, Agua, Agua, Maceta },
			{ Maceta, Lodo, Lodo, Roca, Lodo, Lodo, Lodo, Lodo, Lodo, Lodo, Loceta, Agua, Agua, Agua, Agua, Maceta },
			{ Maceta, Lodo, Lodo, Roca, Lodo, Lodo, Lodo, Lodo, Lodo, Lodo, Loceta, Loceta, Loceta, Loceta, Loceta, Maceta },
			{ Maceta, Lodo, Lodo, Roca, Lodo, Lodo, Arena, Arena, Arena, Lodo, Lodo, Lodo, Lodo, Lodo, Lodo, Maceta },
			{ Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta } };
		nuevo_mapa->objetos = gcnew List<Objeto ^>();
		nuevo_mapa->generarCapaTerreno();


		nuevo_mapa = Mapa::crearMapa(Juego::cabeza);
		nuevo_mapa->matriz_terreno = gcnew array<Terreno, 2> {
			{ Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta },
			{ Maceta, Lava, Lava, Lava, Lodo, Arena, Tierra, Tierra, Tierra, Tierra, Arena, Lodo, Lava, Lava, Lava, Maceta },
			{ Maceta, Lava, Lava, Lava, Lodo, Arena, Tierra, Tierra, Tierra, Tierra, Arena, Lodo, Lava, Lava, Lava, Maceta },
			{ Maceta, Lodo, Lodo, Lodo, Lodo, Arena, Tierra, Tierra, Tierra, Tierra, Arena, Lodo, Lodo, Lodo, Lodo, Maceta },
			{ Maceta, Arena, Arena, Arena, Arena, Arena, Arena, Arena, Arena, Arena, Arena, Arena, Arena, Arena, Arena, Maceta },
			{ Maceta, Lodo, Lodo, Lodo, Arena, Arena, Arena, Arena, Arena, Arena, Arena, Arena, Lodo, Lodo, Lodo, Maceta },
			{ Maceta, Lava, Lava, Lodo, Arena, Arena, Arena, Arena, Arena, Arena, Arena, Arena, Lodo, Lava, Lava, Maceta },
			{ Maceta, Lava, Lava, Lodo, Arena, Arena, Arena, Arena, Arena, Arena, Arena, Arena, Lodo, Lava, Lava, Maceta },
			{ Maceta, Lava, Lava, Lodo, Arena, Arena, Arena, Arena, Arena, Arena, Arena, Arena, Lodo, Lava, Lava, Maceta },
			{ Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta } };
		nuevo_mapa->objetos = gcnew List<Objeto ^>();
		nuevo_mapa->generarCapaTerreno();


		nuevo_mapa = Mapa::crearMapa(Juego::cabeza);
		nuevo_mapa->matriz_terreno = gcnew array<Terreno, 2> {
			{ Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta },
			{ Maceta, Tejado, Tejado, Tejado, Tejado, Tejado, Tejado, Tejado, Tejado, Tejado, Tejado, Tejado, Tejado, Tejado, Tejado, Maceta },
			{ Maceta, Arena, Arena, Arena, Arena, Arena, Arena, Arena, Arena, Arena, Arena, Arena, Arena, Arena, Arena, Maceta },
			{ Maceta, Arena, Arena, Agua, Agua, Agua, Agua, Agua, Agua, Agua, Agua, Agua, Agua, Arena, Arena, Maceta },
			{ Maceta, Arena, Arena, Arena, Arena, Arena, Arena, Arena, Arena, Arena, Arena, Arena, Arena, Arena, Arena, Maceta },
			{ Maceta, Arena, Arena, Arena, Arena, Arena, Arena, Agua, Agua, Arena, Arena, Arena, Arena, Arena, Arena, Maceta },
			{ Maceta, Granito, Granito, Granito, Arena, Arena, Arena, Agua, Agua, Arena, Arena, Arena, Granito, Granito, Granito, Maceta },
			{ Maceta, Granito, Granito, Granito, Arena, Arena, Arena, Arena, Arena, Arena, Arena, Arena, Granito, Granito, Granito, Maceta },
			{ Maceta, Arena, Arena, Arena, Arena, Arena, Arena, Arena, Arena, Arena, Arena, Arena, Arena, Arena, Arena, Maceta },
			{ Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta } };
		nuevo_mapa->objetos = gcnew List<Objeto ^>();
		nuevo_mapa->generarCapaTerreno();


		nuevo_mapa = Mapa::crearMapa(Juego::cabeza);
		nuevo_mapa->matriz_terreno = gcnew array<Terreno, 2> {
			{ Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta },
			{ Maceta, Hielo, Hielo, Hielo, Hielo, Hielo, Lava, Lava, Lava, Lava, Hielo, Hielo, Hielo, Hielo, Hielo, Maceta },
			{ Maceta, Hielo, Tejado, Hielo, Hielo, Hielo, Lava, Loceta, Loceta, Lava, Hielo, Hielo, Hielo, Tejado, Hielo, Maceta },
			{ Maceta, Hielo, Tejado, Hielo, Hielo, Hielo, Lava, Loceta, Loceta, Lava, Hielo, Hielo, Hielo, Tejado, Hielo, Maceta },
			{ Maceta, Hielo, Tejado, Tejado, Hielo, Hielo, Hielo, Hielo, Hielo, Hielo, Hielo, Hielo, Tejado, Tejado, Hielo, Maceta },
			{ Maceta, Hielo, Tejado, Tejado, Hielo, Pasto, Pasto, Hielo, Hielo, Pasto, Pasto, Hielo, Tejado, Tejado, Hielo, Maceta },
			{ Maceta, Hielo, Tejado, Tejado, Hielo, Pasto, Pasto, Hielo, Hielo, Pasto, Pasto, Hielo, Tejado, Tejado, Hielo, Maceta },
			{ Maceta, Hielo, Hielo, Hielo, Hielo, Hielo, Hielo, Hielo, Hielo, Hielo, Hielo, Hielo, Hielo, Hielo, Hielo, Maceta },
			{ Maceta, Loceta, Loceta, Loceta, Hielo, Hielo, Hielo, Arena, Arena, Hielo, Hielo, Loceta, Loceta, Loceta, Loceta, Maceta },
			{ Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta } };
		nuevo_mapa->objetos = gcnew List<Objeto ^>();
		nuevo_mapa->generarCapaTerreno();

		nuevo_mapa = Mapa::crearMapa(Juego::cabeza);
		Juego::cabeza->matriz_terreno = gcnew array<Terreno, 2> {
			{ Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta},
			{ Maceta, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Maceta },
			{ Maceta, Pasto, Granito, Granito, Granito, Granito, Granito, Granito, Granito, Granito, Granito, Granito, Granito, Granito, Pasto, Maceta },
			{ Maceta, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Maceta },
			{ Maceta, Pasto, Pasto, Pasto, Pasto, Pasto, Agua, Agua, Agua, Agua, Pasto, Pasto, Pasto, Pasto, Pasto, Maceta },
			{ Maceta, Pasto, Granito, Pasto, Pasto, Pasto, Agua, Agua, Agua, Agua, Pasto, Pasto, Pasto, Granito, Pasto, Maceta },
			{ Maceta, Pasto, Granito, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Granito, Pasto, Maceta },
			{ Maceta, Pasto, Granito, Granito, Granito, Granito, Pasto, Pasto, Pasto, Pasto, Granito, Granito, Granito, Granito, Pasto, Maceta },
			{ Maceta, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Maceta },
			{ Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta }
		};
		Juego::cabeza->objetos = gcnew List<Objeto ^>();
		Juego::cabeza->generarCapaTerreno();

		nuevo_mapa = Mapa::crearMapa(Juego::cabeza);
		nuevo_mapa->matriz_terreno = gcnew array<Terreno, 2> {
			{ Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta},
			{ Maceta, Pasto, Roca, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Maceta },
			{ Maceta, Pasto, Pasto, Pasto, Pasto, Pasto, Roca, Pasto, Pasto, Pasto, Tierra, Tierra, Tierra, Tierra, Pasto, Maceta },
			{ Maceta, Pasto, Pasto, Pasto, Granito, Granito, Granito, Granito, Granito, Pasto, Tierra, Tierra, Tierra, Tierra, Pasto, Maceta },
			{ Maceta, Pasto, Pasto, Pasto, Granito, Agua, Agua, Agua, Granito, Pasto, Tierra, Tierra, Tierra, Tierra, Pasto, Maceta },
			{ Maceta, Pasto, Pasto, Pasto, Granito, Granito, Granito, Granito, Granito, Pasto, Tierra, Tierra, Tierra, Tierra, Pasto, Maceta },
			{ Maceta, Pasto, Roca, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Tierra, Tierra, Tierra, Tierra, Pasto, Maceta },
			{ Maceta, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Roca, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Maceta },
			{ Maceta, Pasto, Pasto, Pasto, Pasto, Roca, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Maceta },
			{ Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta }
		};
		nuevo_mapa->objetos = gcnew List<Objeto ^>();
		nuevo_mapa->generarCapaTerreno();

		nuevo_mapa = Mapa::crearMapa(Juego::cabeza);
		nuevo_mapa->matriz_terreno = gcnew array<Terreno, 2> {
			{ Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta},
			{ Maceta, Pasto, Pasto, Hielo, Pasto, Pasto, Pasto, Pasto, Arena, Arena, Pasto, Pasto, Pasto, Pasto, Pasto, Maceta },
			{ Maceta, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Hielo, Hielo, Pasto, Pasto, Maceta },
			{ Maceta, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Hielo, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Maceta },
			{ Maceta, Pasto, Hielo, Pasto, Pasto, Hielo, Hielo, Hielo, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Maceta },
			{ Maceta, Pasto, Hielo, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Hielo, Pasto, Pasto, Hielo, Pasto, Maceta },
			{ Maceta, Pasto, Pasto, Pasto, Pasto, Pasto, Hielo, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Hielo, Pasto, Maceta },
			{ Maceta, Pasto, Pasto, Pasto, Hielo, Pasto, Pasto, Pasto, Hielo, Hielo, Pasto, Pasto, Pasto, Pasto, Pasto, Maceta },
			{ Maceta, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Maceta },
			{ Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta }
		};
		nuevo_mapa->objetos = gcnew List<Objeto ^>();
		nuevo_mapa->generarCapaTerreno();

		nuevo_mapa = Mapa::crearMapa(Juego::cabeza);
		nuevo_mapa->matriz_terreno = gcnew array<Terreno, 2> {
			{ Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta},
			{ Maceta, Tierra, Tierra, Tierra, Granito, Arena, Arena, Arena, Granito, Agua, Tierra, Tierra, Tierra, Tierra, Tierra, Maceta },
			{ Maceta, Tierra, Tierra, Tierra, Granito, Arena, Arena, Arena, Granito, Agua, Agua, Tierra, Tierra, Tierra, Tierra, Maceta },
			{ Maceta, Tierra, Granito, Granito, Granito, Arena, Arena, Arena, Granito, Granito, Agua, Tierra, Tierra, Tierra, Tierra, Maceta },
			{ Maceta, Tierra, Granito, Arena, Arena, Arena, Arena, Arena, Arena, Granito, Agua, Tierra, Tierra, Tierra, Tierra, Maceta },
			{ Maceta, Tierra, Granito, Arena, Tierra, Tierra, Tierra, Tierra, Arena, Granito, Agua, Tierra, Tierra, Tierra, Tierra, Maceta },
			{ Maceta, Tierra, Agua, Agua, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Agua, Tierra, Tierra, Tierra, Tierra, Maceta },
			{ Maceta, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Maceta },
			{ Maceta, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Maceta },
			{ Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta }
		};
		nuevo_mapa->objetos = gcnew List<Objeto ^>();
		nuevo_mapa->generarCapaTerreno();

		nuevo_mapa = Mapa::crearMapa(Juego::cabeza);
		nuevo_mapa->matriz_terreno = gcnew array<Terreno, 2> {
			{ Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta},
			{ Maceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Maceta },
			{ Maceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Maceta },
			{ Maceta, Tierra, Tierra, Agua, Roca, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Roca, Agua, Tierra, Tierra, Maceta },
			{ Maceta, Tierra, Tierra, Agua, Roca, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Roca, Agua, Tierra, Tierra, Maceta },
			{ Maceta, Tierra, Tierra, Agua, Roca, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Roca, Agua, Tierra, Tierra, Maceta },
			{ Maceta, Tierra, Tierra, Agua, Roca, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Roca, Agua, Tierra, Tierra, Maceta },
			{ Maceta, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Maceta },
			{ Maceta, Tierra, Tierra, Tierra, Tierra, Tierra, Arena, Arena, Arena, Arena, Tierra, Tierra, Tierra, Tierra, Tierra, Maceta },
			{ Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta }
		};
		nuevo_mapa->objetos = gcnew List<Objeto ^>();
		nuevo_mapa->generarCapaTerreno();

		nuevo_mapa = Mapa::crearMapa(Juego::cabeza);
		nuevo_mapa->matriz_terreno = gcnew array<Terreno, 2> {
			{ Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta },
			{ Maceta, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Maceta },
			{ Maceta, Pasto, Granito, Granito, Granito, Granito, Granito, Granito, Granito, Granito, Granito, Granito, Granito, Granito, Pasto, Maceta },
			{ Maceta, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Maceta },
			{ Maceta, Pasto, Pasto, Pasto, Pasto, Pasto, Agua, Agua, Agua, Agua, Pasto, Pasto, Pasto, Pasto, Pasto, Maceta },
			{ Maceta, Pasto, Granito, Pasto, Pasto, Pasto, Agua, Agua, Agua, Agua, Pasto, Pasto, Pasto, Granito, Pasto, Maceta },
			{ Maceta, Pasto, Granito, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Granito, Pasto, Maceta },
			{ Maceta, Pasto, Granito, Granito, Granito, Granito, Pasto, Pasto, Pasto, Pasto, Granito, Granito, Granito, Granito, Pasto, Maceta },
			{ Maceta, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Maceta },
			{ Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta }
		};
		nuevo_mapa->objetos = gcnew List<Objeto ^>();
		nuevo_mapa->generarCapaTerreno();

		nuevo_mapa = Mapa::crearMapa(Juego::cabeza);
		nuevo_mapa->matriz_terreno = gcnew array<Terreno, 2> {
			{ Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta },
			{ Maceta, Pasto, Roca, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Maceta },
			{ Maceta, Pasto, Pasto, Pasto, Pasto, Pasto, Roca, Pasto, Pasto, Pasto, Tierra, Tierra, Tierra, Tierra, Pasto, Maceta },
			{ Maceta, Pasto, Pasto, Pasto, Granito, Granito, Granito, Granito, Granito, Pasto, Tierra, Tierra, Tierra, Tierra, Pasto, Maceta },
			{ Maceta, Pasto, Pasto, Pasto, Granito, Agua, Agua, Agua, Granito, Pasto, Tierra, Tierra, Tierra, Tierra, Pasto, Maceta },
			{ Maceta, Pasto, Pasto, Pasto, Granito, Granito, Granito, Granito, Granito, Pasto, Tierra, Tierra, Tierra, Tierra, Pasto, Maceta },
			{ Maceta, Pasto, Roca, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Tierra, Tierra, Tierra, Tierra, Pasto, Maceta },
			{ Maceta, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Roca, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Maceta },
			{ Maceta, Pasto, Pasto, Pasto, Pasto, Roca, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Maceta },
			{ Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta }
		};
		nuevo_mapa->objetos = gcnew List<Objeto ^>();
		nuevo_mapa->generarCapaTerreno();


		nuevo_mapa = Mapa::crearMapa(Juego::cabeza);
		nuevo_mapa->matriz_terreno = gcnew array<Terreno, 2> {
			{ Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta },
			{ Maceta, Pasto, Pasto, Hielo, Pasto, Pasto, Pasto, Pasto, Arena, Arena, Pasto, Pasto, Pasto, Pasto, Pasto, Maceta },
			{ Maceta, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Hielo, Hielo, Pasto, Pasto, Maceta },
			{ Maceta, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Hielo, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Maceta },
			{ Maceta, Pasto, Hielo, Pasto, Pasto, Hielo, Hielo, Hielo, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Maceta },
			{ Maceta, Pasto, Hielo, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Hielo, Pasto, Pasto, Hielo, Pasto, Maceta },
			{ Maceta, Pasto, Pasto, Pasto, Pasto, Pasto, Hielo, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Hielo, Pasto, Maceta },
			{ Maceta, Pasto, Pasto, Pasto, Hielo, Pasto, Pasto, Pasto, Hielo, Hielo, Pasto, Pasto, Pasto, Pasto, Pasto, Maceta },
			{ Maceta, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Maceta },
			{ Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta }
		};
		nuevo_mapa->objetos = gcnew List<Objeto ^>();
		nuevo_mapa->generarCapaTerreno();

		nuevo_mapa = Mapa::crearMapa(Juego::cabeza);
		nuevo_mapa->matriz_terreno = gcnew array<Terreno, 2> {
			{ Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta },
			{ Maceta, Tierra, Tierra, Tierra, Granito, Arena, Arena, Arena, Granito, Agua, Tierra, Tierra, Tierra, Tierra, Tierra, Maceta },
			{ Maceta, Tierra, Tierra, Tierra, Granito, Arena, Arena, Arena, Granito, Agua, Agua, Tierra, Tierra, Tierra, Tierra, Maceta },
			{ Maceta, Tierra, Granito, Granito, Granito, Arena, Arena, Arena, Granito, Granito, Agua, Tierra, Tierra, Tierra, Tierra, Maceta },
			{ Maceta, Tierra, Granito, Arena, Arena, Arena, Arena, Arena, Arena, Granito, Agua, Tierra, Tierra, Tierra, Tierra, Maceta },
			{ Maceta, Tierra, Granito, Arena, Tierra, Tierra, Tierra, Tierra, Arena, Granito, Agua, Tierra, Tierra, Tierra, Tierra, Maceta },
			{ Maceta, Tierra, Agua, Agua, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Agua, Tierra, Tierra, Tierra, Tierra, Maceta },
			{ Maceta, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Maceta },
			{ Maceta, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Maceta },
			{ Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta }
		};
		nuevo_mapa->objetos = gcnew List<Objeto ^>();
		nuevo_mapa->generarCapaTerreno();

		nuevo_mapa = Mapa::crearMapa(Juego::cabeza);
		nuevo_mapa->matriz_terreno = gcnew array<Terreno, 2> {
			{ Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta },
			{ Maceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Maceta },
			{ Maceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Maceta },
			{ Maceta, Tierra, Tierra, Agua, Roca, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Roca, Agua, Tierra, Tierra, Maceta },
			{ Maceta, Tierra, Tierra, Agua, Roca, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Roca, Agua, Tierra, Tierra, Maceta },
			{ Maceta, Tierra, Tierra, Agua, Roca, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Roca, Agua, Tierra, Tierra, Maceta },
			{ Maceta, Tierra, Tierra, Agua, Roca, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Roca, Agua, Tierra, Tierra, Maceta },
			{ Maceta, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Maceta },
			{ Maceta, Tierra, Tierra, Tierra, Tierra, Tierra, Arena, Arena, Arena, Arena, Tierra, Tierra, Tierra, Tierra, Tierra, Maceta },
			{ Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta }
		};
		nuevo_mapa->objetos = gcnew List<Objeto ^>();
		nuevo_mapa->generarCapaTerreno();


		nuevo_mapa = Mapa::crearMapa(Juego::cabeza);
		nuevo_mapa->matriz_terreno = gcnew array<Terreno, 2> {
			{ Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta },
			{ Maceta, Tierra, Lava, Tierra, Tierra, Tierra, Tierra, Tierra, Granito, Lava, Lava, Lava, Lava, Lava, Tierra, Maceta },
			{ Maceta, Tierra, Lava, Tierra, Tierra, Tierra, Tierra, Tierra, Granito, Granito, Granito, Granito, Granito, Lava, Tierra, Maceta },
			{ Maceta, Tierra, Lava, Tierra, Tierra, Pasto, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Granito, Lava, Tierra, Maceta },
			{ Maceta, Tierra, Lava, Lava, Tierra, Loceta, Loceta, Loceta, Tierra, Granito, Granito, Granito, Granito, Lava, Tierra, Maceta },
			{ Maceta, Tierra, Lava, Lava, Tierra, Loceta, Loceta, Loceta, Tierra, Granito, Lava, Lava, Lava, Lava, Tierra, Maceta },
			{ Maceta, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Granito, Lava, Tierra, Tierra, Tierra, Tierra, Maceta },
			{ Maceta, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Granito, Lava, Tierra, Tierra, Tierra, Tierra, Maceta },
			{ Maceta, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Maceta },
			{ Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta } };
		nuevo_mapa->objetos = gcnew List<Objeto ^>();
		nuevo_mapa->generarCapaTerreno();

		nuevo_mapa = Mapa::crearMapa(Juego::cabeza);
		nuevo_mapa->matriz_terreno = gcnew array<Terreno, 2> {
			{ Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta },
			{ Maceta, Hielo, Hielo, Roca, Roca, Roca, Roca, Roca, Hielo, Hielo, Hielo, Hielo, Hielo, Hielo, Hielo, Maceta },
			{ Maceta, Hielo, Hielo, Roca, Hielo, Hielo, Hielo, Roca, Hielo, Hielo, Hielo, Hielo, Hielo, Roca, Hielo, Maceta },
			{ Maceta, Hielo, Hielo, Roca, Hielo, Roca, Roca, Roca, Hielo, Hielo, Roca, Roca, Roca, Roca, Hielo, Maceta },
			{ Maceta, Hielo, Roca, Roca, Hielo, Roca, Hielo, Hielo, Hielo, Hielo, Roca, Hielo, Hielo, Hielo, Hielo, Maceta },
			{ Maceta, Hielo, Hielo, Hielo, Hielo, Roca, Hielo, Agua, Agua, Hielo, Roca, Hielo, Hielo, Hielo, Hielo, Maceta },
			{ Maceta, Hielo, Hielo, Hielo, Hielo, Roca, Hielo, Agua, Agua, Hielo, Roca, Roca, Roca, Roca, Hielo, Maceta },
			{ Maceta, Hielo, Roca, Roca, Roca, Roca, Hielo, Agua, Agua, Hielo, Hielo, Hielo, Hielo, Hielo, Hielo, Maceta },
			{ Maceta, Hielo, Hielo, Hielo, Hielo, Hielo, Hielo, Hielo, Hielo, Hielo, Hielo, Hielo, Hielo, Hielo, Hielo, Maceta },
			{ Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta } };
		nuevo_mapa->objetos = gcnew List<Objeto ^>();
		nuevo_mapa->generarCapaTerreno();


		nuevo_mapa = Mapa::crearMapa(Juego::cabeza);
		nuevo_mapa->matriz_terreno = gcnew array<Terreno, 2> {
			{ Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta },
			{ Maceta, Hielo, Hielo, Hielo, Hielo, Hielo, Hielo, Hielo, Tejado, Tejado, Hielo, Pasto, Hielo, Hielo, Hielo, Maceta },
			{ Maceta, Hielo, Agua, Agua, Agua, Agua, Agua, Agua, Tejado, Tejado, Hielo, Pasto, Pasto, Hielo, Hielo, Maceta },
			{ Maceta, Hielo, Agua, Agua, Agua, Agua, Agua, Agua, Hielo, Hielo, Hielo, Hielo, Hielo, Hielo, Hielo, Maceta },
			{ Maceta, Hielo, Hielo, Pasto, Hielo, Hielo, Hielo, Hielo, Hielo, Pasto, Hielo, Hielo, Pasto, Pasto, Hielo, Maceta },
			{ Maceta, Hielo, Hielo, Pasto, Pasto, Pasto, Hielo, Hielo, Pasto, Pasto, Hielo, Hielo, Hielo, Pasto, Hielo, Maceta },
			{ Maceta, Hielo, Hielo, Hielo, Hielo, Pasto, Hielo, Hielo, Pasto, Hielo, Hielo, Pasto, Hielo, Hielo, Hielo, Maceta },
			{ Maceta, Hielo, Hielo, Hielo, Hielo, Hielo, Hielo, Hielo, Hielo, Hielo, Pasto, Pasto, Hielo, Hielo, Hielo, Maceta },
			{ Maceta, Hielo, Hielo, Hielo, Hielo, Hielo, Hielo, Hielo, Hielo, Hielo, Hielo, Hielo, Hielo, Hielo, Hielo, Maceta },
			{ Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta } };
		nuevo_mapa->objetos = gcnew List<Objeto ^>();
		nuevo_mapa->generarCapaTerreno();


		nuevo_mapa = Mapa::crearMapa(Juego::cabeza);
		nuevo_mapa->matriz_terreno = gcnew array<Terreno, 2> {
			{ Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta },
			{ Maceta, Hielo, Hielo, Hielo, Hielo, Hielo, Hielo, Hielo, Hielo, Hielo, Hielo, Hielo, Hielo, Hielo, Hielo, Maceta },
			{ Maceta, Hielo, Lava, Lava, Lava, Lava, Lava, Hielo, Hielo, Lava, Hielo, Lava, Lava, Lava, Lava, Maceta },
			{ Maceta, Hielo, Hielo, Hielo, Lava, Hielo, Hielo, Hielo, Hielo, Lava, Hielo, Hielo, Hielo, Hielo, Lava, Maceta },
			{ Maceta, Hielo, Lava, Lava, Lava, Lava, Lava, Hielo, Hielo, Lava, Lava, Lava, Lava, Lava, Lava, Maceta },
			{ Maceta, Hielo, Hielo, Hielo, Hielo, Hielo, Hielo, Hielo, Hielo, Hielo, Hielo, Hielo, Hielo, Hielo, Hielo, Maceta },
			{ Maceta, Hielo, Hielo, Hielo, Hielo, Hielo, Hielo, Hielo, Hielo, Hielo, Lava, Lava, Lava, Hielo, Hielo, Maceta },
			{ Maceta, Tejado, Tejado, Hielo, Hielo, Hielo, Hielo, Lava, Lava, Lava, Lava, Hielo, Hielo, Hielo, Hielo, Maceta },
			{ Maceta, Tejado, Tejado, Hielo, Hielo, Hielo, Hielo, Hielo, Hielo, Hielo, Hielo, Hielo, Hielo, Hielo, Hielo, Maceta },
			{ Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta } };
		nuevo_mapa->objetos = gcnew List<Objeto ^>();
		nuevo_mapa->generarCapaTerreno();


		nuevo_mapa = Mapa::crearMapa(Juego::cabeza);
		nuevo_mapa->matriz_terreno = gcnew array<Terreno, 2> {
			{ Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta },
			{ Maceta, Tierra, Tejado, Tejado, Tejado, Tejado, Tejado, Tejado, Tejado, Tejado, Tejado, Tejado, Tejado, Tejado, Tejado, Maceta },
			{ Maceta, Tierra, Tejado, Tejado, Tejado, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Tejado, Tejado, Maceta },
			{ Maceta, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Maceta },
			{ Maceta, Pasto, Pasto, Tierra, Arena, Arena, Arena, Arena, Arena, Arena, Arena, Arena, Tierra, Pasto, Pasto, Maceta },
			{ Maceta, Pasto, Pasto, Tierra, Arena, Arena, Arena, Arena, Arena, Arena, Arena, Arena, Tierra, Pasto, Pasto, Maceta },
			{ Maceta, Pasto, Pasto, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Pasto, Pasto, Maceta },
			{ Maceta, Pasto, Pasto, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Maceta },
			{ Maceta, Pasto, Pasto, Agua, Agua, Agua, Tierra, Tierra, Tierra, Agua, Agua, Agua, Agua, Agua, Agua, Maceta },
			{ Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta } };
		nuevo_mapa->objetos = gcnew List<Objeto ^>();
		nuevo_mapa->generarCapaTerreno();


		nuevo_mapa = Mapa::crearMapa(Juego::cabeza);
		nuevo_mapa->matriz_terreno = gcnew array<Terreno, 2> {
			{ Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta },
			{ Maceta, Tejado, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Maceta },
			{ Maceta, Tejado, Lava, Lava, Lava, Lava, Lava, Tierra, Tierra, Lava, Lava, Lava, Lava, Lava, Tierra, Maceta },
			{ Maceta, Tejado, Tierra, Tierra, Lava, Tierra, Tierra, Tierra, Tierra, Tierra, Lava, Tierra, Tierra, Tierra, Tierra, Maceta },
			{ Maceta, Tejado, Tierra, Tierra, Lava, Tierra, Tierra, Tierra, Tierra, Tierra, Lava, Lava, Lava, Tierra, Tierra, Maceta },
			{ Maceta, Tejado, Tierra, Tierra, Lava, Lava, Lava, Tierra, Tierra, Tierra, Tierra, Tierra, Lava, Tierra, Tierra, Maceta },
			{ Maceta, Tejado, Tierra, Tierra, Tierra, Lava, Tierra, Tierra, Loceta, Loceta, Loceta, Tierra, Lava, Lava, Tierra, Maceta },
			{ Maceta, Tejado, Tejado, Tierra, Tierra, Lava, Tierra, Loceta, Loceta, Loceta, Loceta, Tierra, Tierra, Tierra, Tierra, Maceta },
			{ Maceta, Tejado, Tejado, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Tejado, Tejado, Maceta },
			{ Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta } };
		nuevo_mapa->objetos = gcnew List<Objeto ^>();
		nuevo_mapa->generarCapaTerreno();


		nuevo_mapa = Mapa::crearMapa(Juego::cabeza);
		nuevo_mapa->matriz_terreno = gcnew array<Terreno, 2> {
			{ Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta },
			{ Maceta, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Maceta },
			{ Maceta, Tierra, Arena, Arena, Tierra, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Tierra, Arena, Arena, Tierra, Maceta },
			{ Maceta, Tierra, Arena, Arena, Tierra, Tierra, Tierra, Loceta, Loceta, Tierra, Tierra, Tierra, Arena, Arena, Tierra, Maceta },
			{ Maceta, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Loceta, Loceta, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Maceta },
			{ Maceta, Tierra, Agua, Agua, Agua, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Agua, Agua, Agua, Tierra, Maceta },
			{ Maceta, Tierra, Arena, Arena, Agua, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Agua, Arena, Arena, Tierra, Maceta },
			{ Maceta, Tierra, Arena, Arena, Agua, Tierra, Pasto, Pasto, Pasto, Pasto, Tierra, Agua, Arena, Arena, Tierra, Maceta },
			{ Maceta, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Maceta },
			{ Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta } };
		nuevo_mapa->objetos = gcnew List<Objeto ^>();
		nuevo_mapa->generarCapaTerreno();


		nuevo_mapa = Mapa::crearMapa(Juego::cabeza);
		nuevo_mapa->matriz_terreno = gcnew array<Terreno, 2> {
			{ Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta },
			{ Maceta, Pasto, Pasto, Arena, Arena, Arena, Arena, Arena, Arena, Arena, Arena, Arena, Arena, Tejado, Tejado, Maceta },
			{ Maceta, Pasto, Pasto, Arena, Granito, Granito, Granito, Granito, Arena, Arena, Arena, Granito, Arena, Arena, Arena, Maceta },
			{ Maceta, Arena, Arena, Arena, Arena, Arena, Arena, Granito, Arena, Arena, Arena, Granito, Arena, Granito, Arena, Maceta },
			{ Maceta, Arena, Granito, Arena, Arena, Arena, Arena, Granito, Granito, Granito, Granito, Granito, Granito, Granito, Arena, Maceta },
			{ Maceta, Arena, Granito, Granito, Granito, Arena, Arena, Arena, Granito, Arena, Arena, Granito, Arena, Granito, Arena, Maceta },
			{ Maceta, Arena, Granito, Arena, Arena, Arena, Arena, Granito, Granito, Arena, Arena, Granito, Arena, Arena, Arena, Maceta },
			{ Maceta, Arena, Arena, Arena, Arena, Arena, Arena, Arena, Arena, Arena, Arena, Arena, Arena, Arena, Arena, Maceta },
			{ Maceta, Tejado, Tejado, Tejado, Tejado, Arena, Arena, Arena, Arena, Arena, Arena, Tejado, Tejado, Tejado, Tejado, Maceta },
			{ Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta } };
		nuevo_mapa->objetos = gcnew List<Objeto ^>();
		nuevo_mapa->generarCapaTerreno();


		nuevo_mapa = Mapa::crearMapa(Juego::cabeza);
		nuevo_mapa->matriz_terreno = gcnew array<Terreno, 2> {
			{ Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta },
			{ Maceta, Roca, Roca, Roca, Roca, Roca, Lodo, Lodo, Agua, Agua, Agua, Lodo, Lodo, Lodo, Lodo, Maceta },
			{ Maceta, Roca, Granito, Granito, Granito, Granito, Lodo, Lodo, Agua, Agua, Agua, Lodo, Tejado, Roca, Lodo, Maceta },
			{ Maceta, Lodo, Tejado, Tejado, Granito, Tejado, Tejado, Lodo, Lodo, Lodo, Lodo, Lodo, Tejado, Granito, Lodo, Maceta },
			{ Maceta, Lodo, Tejado, Tejado, Granito, Tejado, Tejado, Granito, Lodo, Lodo, Lodo, Lodo, Tejado, Roca, Lodo, Maceta },
			{ Maceta, Lodo, Lodo, Granito, Granito, Granito, Granito, Granito, Lodo, Lodo, Lodo, Lodo, Tejado, Roca, Lodo, Maceta },
			{ Maceta, Lodo, Lodo, Roca, Granito, Roca, Roca, Roca, Lodo, Lodo, Lodo, Lodo, Tejado, Granito, Lodo, Maceta },
			{ Maceta, Lodo, Lodo, Lodo, Lodo, Lodo, Lodo, Lodo, Lodo, Lodo, Lodo, Lodo, Tejado, Roca, Lodo, Maceta },
			{ Maceta, Lodo, Lodo, Lodo, Lodo, Lodo, Lodo, Lodo, Lodo, Lodo, Lodo, Lodo, Lodo, Lodo, Lodo, Maceta },
			{ Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta } };
		nuevo_mapa->objetos = gcnew List<Objeto ^>();
		nuevo_mapa->generarCapaTerreno();


		nuevo_mapa = Mapa::crearMapa(Juego::cabeza);
		nuevo_mapa->matriz_terreno = gcnew array<Terreno, 2> {
			{ Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta },
			{ Maceta, Lodo, Lodo, Lodo, Lodo, Lodo, Lodo, Lodo, Lodo, Lodo, Lodo, Lodo, Tejado, Tejado, Tejado, Maceta },
			{ Maceta, Lodo, Roca, Roca, Agua, Agua, Agua, Agua, Agua, Lodo, Lodo, Lodo, Roca, Roca, Roca, Maceta },
			{ Maceta, Lodo, Roca, Roca, Agua, Agua, Agua, Agua, Agua, Lodo, Lodo, Lodo, Roca, Agua, Roca, Maceta },
			{ Maceta, Lodo, Lodo, Lodo, Agua, Agua, Lodo, Lodo, Lodo, Lodo, Lodo, Lodo, Roca, Agua, Roca, Maceta },
			{ Maceta, Lodo, Lodo, Lodo, Agua, Agua, Lodo, Lodo, Pasto, Pasto, Pasto, Lodo, Roca, Agua, Roca, Maceta },
			{ Maceta, Lodo, Lodo, Lodo, Lodo, Lodo, Lodo, Lodo, Pasto, Pasto, Pasto, Lodo, Roca, Agua, Roca, Maceta },
			{ Maceta, Lodo, Lodo, Lodo, Lodo, Lodo, Lodo, Lodo, Pasto, Pasto, Pasto, Lodo, Roca, Roca, Roca, Maceta },
			{ Maceta, Lodo, Lodo, Lodo, Lodo, Lodo, Lodo, Lodo, Lodo, Lodo, Lodo, Lodo, Lodo, Lodo, Lodo, Maceta },
			{ Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta } };
		nuevo_mapa->objetos = gcnew List<Objeto ^>();
		nuevo_mapa->generarCapaTerreno();


		nuevo_mapa = Mapa::crearMapa(Juego::cabeza);
		nuevo_mapa->matriz_terreno = gcnew array<Terreno, 2> {
			{ Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta },
			{ Maceta, Arena, Arena, Arena, Roca, Lava, Lava, Lava, Lava, Lava, Lava, Roca, Arena, Arena, Arena, Maceta },
			{ Maceta, Arena, Granito, Granito, Roca, Lava, Lava, Lava, Lava, Lava, Lava, Roca, Granito, Granito, Arena, Maceta },
			{ Maceta, Arena, Granito, Granito, Roca, Roca, Roca, Roca, Roca, Roca, Roca, Roca, Granito, Granito, Arena, Maceta },
			{ Maceta, Arena, Arena, Arena, Arena, Arena, Arena, Arena, Arena, Arena, Arena, Arena, Arena, Arena, Arena, Maceta },
			{ Maceta, Arena, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Arena, Maceta },
			{ Maceta, Arena, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Arena, Maceta },
			{ Maceta, Arena, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Arena, Maceta },
			{ Maceta, Arena, Arena, Arena, Arena, Arena, Arena, Arena, Arena, Arena, Arena, Arena, Arena, Arena, Arena, Maceta },
			{ Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta } };
		nuevo_mapa->objetos = gcnew List<Objeto ^>();
		nuevo_mapa->generarCapaTerreno();


		nuevo_mapa = Mapa::crearMapa(Juego::cabeza);
		nuevo_mapa->matriz_terreno = gcnew array<Terreno, 2> {
			{ Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta },
			{ Maceta, Lodo, Lodo, Lodo, Lodo, Lodo, Tejado, Tejado, Tejado, Tejado, Tejado, Lodo, Lodo, Pasto, Pasto, Maceta },
			{ Maceta, Lodo, Lodo, Lodo, Lodo, Lodo, Lodo, Lodo, Lodo, Lodo, Lodo, Lodo, Lodo, Pasto, Pasto, Maceta },
			{ Maceta, Lodo, Roca, Roca, Roca, Roca, Lodo, Lodo, Lodo, Lodo, Lodo, Lodo, Lodo, Pasto, Pasto, Maceta },
			{ Maceta, Lodo, Lodo, Roca, Lodo, Roca, Lodo, Lodo, Lodo, Lodo, Loceta, Loceta, Loceta, Pasto, Pasto, Maceta },
			{ Maceta, Lodo, Lodo, Roca, Lodo, Roca, Lodo, Lodo, Lodo, Lodo, Loceta, Agua, Agua, Agua, Agua, Maceta },
			{ Maceta, Lodo, Lodo, Roca, Lodo, Lodo, Lodo, Lodo, Lodo, Lodo, Loceta, Agua, Agua, Agua, Agua, Maceta },
			{ Maceta, Lodo, Lodo, Roca, Lodo, Lodo, Lodo, Lodo, Lodo, Lodo, Loceta, Loceta, Loceta, Loceta, Loceta, Maceta },
			{ Maceta, Lodo, Lodo, Roca, Lodo, Lodo, Arena, Arena, Arena, Lodo, Lodo, Lodo, Lodo, Lodo, Lodo, Maceta },
			{ Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta } };
		nuevo_mapa->objetos = gcnew List<Objeto ^>();
		nuevo_mapa->generarCapaTerreno();


		nuevo_mapa = Mapa::crearMapa(Juego::cabeza);
		nuevo_mapa->matriz_terreno = gcnew array<Terreno, 2> {
			{ Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta },
			{ Maceta, Lava, Lava, Lava, Lodo, Arena, Tierra, Tierra, Tierra, Tierra, Arena, Lodo, Lava, Lava, Lava, Maceta },
			{ Maceta, Lava, Lava, Lava, Lodo, Arena, Tierra, Tierra, Tierra, Tierra, Arena, Lodo, Lava, Lava, Lava, Maceta },
			{ Maceta, Lodo, Lodo, Lodo, Lodo, Arena, Tierra, Tierra, Tierra, Tierra, Arena, Lodo, Lodo, Lodo, Lodo, Maceta },
			{ Maceta, Arena, Arena, Arena, Arena, Arena, Arena, Arena, Arena, Arena, Arena, Arena, Arena, Arena, Arena, Maceta },
			{ Maceta, Lodo, Lodo, Lodo, Arena, Arena, Arena, Arena, Arena, Arena, Arena, Arena, Lodo, Lodo, Lodo, Maceta },
			{ Maceta, Lava, Lava, Lodo, Arena, Arena, Arena, Arena, Arena, Arena, Arena, Arena, Lodo, Lava, Lava, Maceta },
			{ Maceta, Lava, Lava, Lodo, Arena, Arena, Arena, Arena, Arena, Arena, Arena, Arena, Lodo, Lava, Lava, Maceta },
			{ Maceta, Lava, Lava, Lodo, Arena, Arena, Arena, Arena, Arena, Arena, Arena, Arena, Lodo, Lava, Lava, Maceta },
			{ Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta } };
		nuevo_mapa->objetos = gcnew List<Objeto ^>();
		nuevo_mapa->generarCapaTerreno();


		nuevo_mapa = Mapa::crearMapa(Juego::cabeza);
		nuevo_mapa->matriz_terreno = gcnew array<Terreno, 2> {
			{ Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta },
			{ Maceta, Tejado, Tejado, Tejado, Tejado, Tejado, Tejado, Tejado, Tejado, Tejado, Tejado, Tejado, Tejado, Tejado, Tejado, Maceta },
			{ Maceta, Arena, Arena, Arena, Arena, Arena, Arena, Arena, Arena, Arena, Arena, Arena, Arena, Arena, Arena, Maceta },
			{ Maceta, Arena, Arena, Agua, Agua, Agua, Agua, Agua, Agua, Agua, Agua, Agua, Agua, Arena, Arena, Maceta },
			{ Maceta, Arena, Arena, Arena, Arena, Arena, Arena, Arena, Arena, Arena, Arena, Arena, Arena, Arena, Arena, Maceta },
			{ Maceta, Arena, Arena, Arena, Arena, Arena, Arena, Agua, Agua, Arena, Arena, Arena, Arena, Arena, Arena, Maceta },
			{ Maceta, Granito, Granito, Granito, Arena, Arena, Arena, Agua, Agua, Arena, Arena, Arena, Granito, Granito, Granito, Maceta },
			{ Maceta, Granito, Granito, Granito, Arena, Arena, Arena, Arena, Arena, Arena, Arena, Arena, Granito, Granito, Granito, Maceta },
			{ Maceta, Arena, Arena, Arena, Arena, Arena, Arena, Arena, Arena, Arena, Arena, Arena, Arena, Arena, Arena, Maceta },
			{ Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta } };
		nuevo_mapa->objetos = gcnew List<Objeto ^>();
		nuevo_mapa->generarCapaTerreno();


		nuevo_mapa = Mapa::crearMapa(Juego::cabeza);
		nuevo_mapa->matriz_terreno = gcnew array<Terreno, 2> {
			{ Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta },
			{ Maceta, Hielo, Hielo, Hielo, Hielo, Hielo, Lava, Lava, Lava, Lava, Hielo, Hielo, Hielo, Hielo, Hielo, Maceta },
			{ Maceta, Hielo, Tejado, Hielo, Hielo, Hielo, Lava, Loceta, Loceta, Lava, Hielo, Hielo, Hielo, Tejado, Hielo, Maceta },
			{ Maceta, Hielo, Tejado, Hielo, Hielo, Hielo, Lava, Loceta, Loceta, Lava, Hielo, Hielo, Hielo, Tejado, Hielo, Maceta },
			{ Maceta, Hielo, Tejado, Tejado, Hielo, Hielo, Hielo, Hielo, Hielo, Hielo, Hielo, Hielo, Tejado, Tejado, Hielo, Maceta },
			{ Maceta, Hielo, Tejado, Tejado, Hielo, Pasto, Pasto, Hielo, Hielo, Pasto, Pasto, Hielo, Tejado, Tejado, Hielo, Maceta },
			{ Maceta, Hielo, Tejado, Tejado, Hielo, Pasto, Pasto, Hielo, Hielo, Pasto, Pasto, Hielo, Tejado, Tejado, Hielo, Maceta },
			{ Maceta, Hielo, Hielo, Hielo, Hielo, Hielo, Hielo, Hielo, Hielo, Hielo, Hielo, Hielo, Hielo, Hielo, Hielo, Maceta },
			{ Maceta, Loceta, Loceta, Loceta, Hielo, Hielo, Hielo, Arena, Arena, Hielo, Hielo, Loceta, Loceta, Loceta, Loceta, Maceta },
			{ Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta } };
		nuevo_mapa->objetos = gcnew List<Objeto ^>();
		nuevo_mapa->generarCapaTerreno();
	}

	Juego::Juego(void) {
		
		aleatorio = gcnew Random();
		Mapa::puerta1 = gcnew Posicion(0, 4, true);
		Mapa::puerta2 = gcnew Posicion(15, 2, true);
		Mapa::puerta3 = gcnew Posicion(15, 7, true);

		inicializarComponentes();
		InitializeComponent();
		myform = this;

		graphics = this->CreateGraphics();
		context = BufferedGraphicsManager::Current;

		Juego::cabeza = gcnew Mapa();
		inicializarMapas();

		//Inicializamos las escenas
		ESCENAS::introduccion = gcnew IntroduccionEscena();
		ESCENAS::mapa = gcnew MapaEscena();

		//Empezar el juego
		Escena::EmpezarConEscena(ESCENAS::introduccion);
	}

	Juego::~Juego() {
		if (components)	{
			delete components;
		}
	}

	void Juego::InitializeComponent(void) {
		this->components = (gcnew System::ComponentModel::Container());
		System::ComponentModel::ComponentResourceManager ^resources = (gcnew System::ComponentModel::ComponentResourceManager(Juego::typeid));
		this->timer = (gcnew System::Windows::Forms::Timer(this->components));
		this->SuspendLayout();
		// 
		// timer
		// 
		this->timer->Enabled = true;
		this->timer->Interval = VELOCIDAD_TIMER;
		// 
		// Myform
		// 
		this->DoubleBuffered = true;
		this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
		this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
		this->ClientSize = System::Drawing::Size(MYFORM_WIDTH * RESOLUCION_X, MYFORM_HEIGHT * RESOLUCION_Y);
		this->MaximumSize = System::Drawing::Size(MYFORM_WIDTH * RESOLUCION_X + 16, MYFORM_HEIGHT * RESOLUCION_Y + 39);
		this->MinimumSize = System::Drawing::Size(MYFORM_WIDTH * RESOLUCION_X + 16, MYFORM_HEIGHT * RESOLUCION_Y + 39);
		this->Name = L"Final Fantasy";
		this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
		this->Text = L"Final Fantasy";
		this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Juego::Juego_KeyDown);
		this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &Juego::Juego_KeyUp);
		this->ResumeLayout(false);

	}

	System::Void Juego::Juego_KeyDown(System::Object ^sender, System::Windows::Forms::KeyEventArgs ^e) {
		;
	}

	System::Void Juego::Juego_KeyUp(System::Object ^sender, System::Windows::Forms::KeyEventArgs ^e) {
		;
	}

	void Juego::inicializarComponentes() {
		// Sprites
		IMAGENES::MARCO_SPRITE = Image::FromFile("Imagenes\\Personajes\\MARCO_SPRITE.png");
		IMAGENES::ENEMIGO_SPRITE_0 = Image::FromFile("Imagenes\\Personajes\\ENEMIGO_SPRITE_0.png");
		IMAGENES::ENEMIGO_SPRITE_1 = Image::FromFile("Imagenes\\Personajes\\ENEMIGO_SPRITE_1.png");
		IMAGENES::ENEMIGO_SPRITE_2 = Image::FromFile("Imagenes\\Personajes\\ENEMIGO_SPRITE_2.png");
		IMAGENES::ENEMIGO_SPRITE_3 = Image::FromFile("Imagenes\\Personajes\\ENEMIGO_SPRITE_3.png");
		IMAGENES::MONEDA_SPRITE = Image::FromFile("Imagenes\\Objetos\\Moneda_Sprite.png");

		// Fondos
		IMAGENES::INTRODUCCION_FONDO = Image::FromFile("Imagenes\\Interfaces\\INTRODUCCION_0.png");
		IMAGENES::BATALLA_FONDO = Image::FromFile("Imagenes\\Interfaces\\BATALLA_FONDO.png");
		IMAGENES::PUERTA = Image::FromFile("Imagenes\\Objetos\\PUERTA.png");

		// Objetos
		IMAGENES::LOCETA = Image::FromFile("Imagenes\\Objetos\\LOCETA.png");
		IMAGENES::AGUA = Image::FromFile("Imagenes\\Objetos\\AGUA.png");
		IMAGENES::ARENA = Image::FromFile("Imagenes\\Objetos\\ARENA.png");
		IMAGENES::GRANITO = Image::FromFile("Imagenes\\Objetos\\GRANITO.png");
		IMAGENES::HIELO = Image::FromFile("Imagenes\\Objetos\\HIELO.png");
		IMAGENES::LAVA = Image::FromFile("Imagenes\\Objetos\\LAVA.png");
		IMAGENES::LODO = Image::FromFile("Imagenes\\Objetos\\LODO.png");
		IMAGENES::MACETA = Image::FromFile("Imagenes\\Objetos\\MACETA.png");
		IMAGENES::PASTO = Image::FromFile("Imagenes\\Objetos\\PASTO.png");
		IMAGENES::ROCA = Image::FromFile("Imagenes\\Objetos\\ROCA.png");
		IMAGENES::TEJADO = Image::FromFile("Imagenes\\Objetos\\TEJADO.png");
		IMAGENES::TIERRA = Image::FromFile("Imagenes\\Objetos\\TIERRA.png");

		// Controles
		CONTROLES::CAMBIO_ESCENA = Keys::E;
		CONTROLES::SALIR = Keys::Escape;
		CONTROLES::MOVER_ARRIBA_1 = Keys::W;
		CONTROLES::MOVER_ABAJO_1 = Keys::S;
		CONTROLES::MOVER_IZQUIERDA_1 = Keys::A;
		CONTROLES::MOVER_DERECHA_1 = Keys::D;
		CONTROLES::MOVER_ARRIBA_2 = Keys::Up;
		CONTROLES::MOVER_ABAJO_2 = Keys::Down;
		CONTROLES::MOVER_IZQUIERDA_2 = Keys::Left;
		CONTROLES::MOVER_DERECHA_2 = Keys::Right;

		FUENTES::SUBTITULOS = gcnew System::Drawing::Font("ARIAL", TAMANIO_LETRAS - 2, FontStyle::Regular, GraphicsUnit::Point);
		FUENTES::DIALOGOS = gcnew System::Drawing::Font("Lucida Console", TAMANIO_LETRAS, FontStyle::Regular, GraphicsUnit::Point);
		FUENTES::DINERO = gcnew System::Drawing::Font("Lucida Console", TAMANIO_LETRAS - 8, FontStyle::Regular, GraphicsUnit::Point);
	}

	void IMAGENES::mostarFondo(Image ^imagen, Graphics ^graphics) {
		graphics->DrawImage(imagen, Rectangle(0, 0, MYFORM_SIZE_WIDTH, MYFORM_SIZE_HEIGHT));
	}

	Direccion obtenerDireccionInvertida(Direccion direccion) {
		switch (direccion) {
		case Arriba:
			return Abajo;
			break;
		case Abajo:
			return Arriba;
			break;
		case Izquierda:
			return Derecha;
			break;
		case Derecha:
			return Izquierda;
			break;
		default:
			return Abajo;
		}
	}

	bool noHayONoExsite(Object ^objeto) {
		if (objeto == nullptr)
			return true;
		else
			return false;
	}

	bool Colisiona(Terreno terreno) {
		Terreno* indice_terreno = std::find(
			std::begin(TERRENOS_COLISIONANTES),
			std::end(TERRENOS_COLISIONANTES),
			terreno
		);

		bool impide = indice_terreno != std::end(TERRENOS_COLISIONANTES);

		return impide;
	}



}