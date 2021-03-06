#pragma once

using namespace System::Drawing;

namespace FinalFantasy {

	public ref class IMAGENES abstract sealed {
	public:
		static void mostarFondo(Image ^imagen, Graphics ^graphics);

		static Image ^MARCO_SPRITE;
		static Image ^ENEMIGO_SPRITE_0;
		static Image ^ENEMIGO_SPRITE_1;
		static Image ^ENEMIGO_SPRITE_2;
		static Image ^ENEMIGO_SPRITE_3;
		static Image ^MONEDA_SPRITE;
		static Image ^PUERTA;

		static Image ^LOCETA;
		static Image ^AGUA;
		static Image ^ARENA;
		static Image ^GRANITO;
		static Image ^HIELO;
		static Image ^LAVA;
		static Image ^LODO;
		static Image ^MACETA;
		static Image ^PASTO;
		static Image ^ROCA;
		static Image ^TEJADO;
		static Image ^TIERRA;

		static Image^ INTRODUCCION_FONDO;
		static Image^ BATALLA_FONDO;
	};
}