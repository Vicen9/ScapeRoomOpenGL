#ifndef __IGVINTERFAZ
#define __IGVINTERFAZ

#if defined(__APPLE__) && defined(__MACH__)
#include <GLUT/glut.h>
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#else
#include <GL/glut.h>
#endif

#include <string>

#include "igvEscena3D.h"
#include "igvCamara.h"
#include <list>

using namespace std;

class igvInterfaz {

	protected:
		// Atributos
		int ancho_ventana; // ancho inicial de la ventana de visualizacion
		int alto_ventana;  // alto inicial de la ventana de visualizacion

		igvEscena3D escena; // escena que se visualiza en la ventana definida por igvInterfaz

		igvCamara camara; // Cámara en 1º persona.
		igvCamara camaraTecho; // Cámara con vista hacia el techo.
		igvCamara camaraSeguridad1; // Cámara de seguridad 1.
		igvCamara camaraSeguridad2; // Cámara de seguridad 2.
		igvCamara camaraSuelo; // Cámara con vista hacia el suelo.
		igvCamara multiCamara; // Todas las cámaras

		igvCamara camaraModoSeleccion; // Cámara modo seleccion
		igvCamara camaraRec; // Cámara rec
		igvCamara camaraOrbita; // Cámara orbita

		enum camaras
		{
			CP,
			CS1,
			CS2,
			CT,
			CSu,
			MC,
			MS,
			REC,
			ORB,

		} cam;

		// Valores de la cámara principal
		igvPunto3D p0, r, V;

		// Valores de la cámara de seguridad
		igvPunto3D p1, r1, V1;

		// Valores de la cámara hacia el techo
		igvPunto3D p2, r2, V2;

		// Valores de la cámara hacia el suelo
		igvPunto3D p3, r3, V3;

		// Valores de la cámara hacia el suelo
		igvPunto3D p4, r4, V4;

		// Valores de la cámara de seguridad 2
		igvPunto3D p5, r5, V5;

		// Valores de la cámara de modo seleccion
		igvPunto3D p6, r6, V6;

		// Valores de la cámara REC
		igvPunto3D p7, r7, V7;

		// Valores de la cámara orbita
		igvPunto3D p8, r8, V8;

		double angulo;
		double anguloORB;

		bool NORTE;
		bool SUR;
		bool ESTE;
		bool OESTE;

		int velocidad;

		typedef enum {
			IGV_VISUALIZAR,
			IGV_SELECCIONAR,
		} modoInterfaz;

		modoInterfaz modo; // IGV_VISUALIZAR: en la ventana se va a visualizar de manera normal la escena, 
						   // IGV_SELECCIONAR: se ha pulsado sobre la ventana de visualización, la escena se debe
						   // visualizar en modo selección

		int cursorX, cursorY; // pixel de la pantalla sobre el que está situado el ratón, por pulsar o arrastrar

		int objeto_seleccionado; // código del objeto seleccionado, -1 si no hay ninguno

		bool boton_retenido; // indica si el botón está pulsado (true) o se ha soltado (false)

	public:

		double XMAXIMA = 90;
		double XMINIMA = -90;
		double ZMAXIMA = 200;
		double ZMINIMA = -100;

		double LIMITEXMINMESA = -9;
		double LIMITEXMAXMESA = 9;
		double LIMITEZMINMESA = -9;
		double LIMITEZMAXMESA = 9;

		list<int> codigo;
		int codCorrecto[4];

		bool ACCEPTED;

		// Constructores por defecto y destructor
		igvInterfaz();
		~igvInterfaz();

		// Metodos estáticos
		// callbacks de eventos
		static void set_glutKeyboardFunc(unsigned char key, int x, int y); // metodo para control de eventos del teclado
		static void set_glutSpecialFunc(int key, int x, int y); // metodo para control de eventos del teclado (teclas especiales)
		static void set_glutReshapeFunc(int w, int h); // método que define la camara de vision y el viewport
		                                               // se llama automáticamente cuano se camba el tamaño de la ventana
		static void set_glutDisplayFunc(); // método para visualizar la escena


		// Metodos
		// crea el mundo que se visualiza en la ventana
		void crear_mundo(void);

		// inicializa todos los parámetros para crear una ventana de visualización
		void configura_entorno(int argc, char** argv, // parametros del main
			                     int _ancho_ventana, int _alto_ventana, // ancho y alto de la ventana de visualización
			                     int _pos_X, int _pos_Y, // posicion inicial de la ventana de visualización
													 string _titulo // título de la ventan de visualización
													 );
		void inicializa_callbacks(); // inicializa todas los callbacks

		void inicia_bucle_visualizacion(); // visualiza la escena y espera a eventos sobre la interfaz

		// Métodos para el control de la pulsación y el arrastre del ratón

		static void  set_glutMouseFunc(GLint boton, GLint estado, GLint x, GLint y); // control de pulsacion del raton
		static void  set_glutMotionFunc(GLint x, GLint y); // control del desplazamiento del raton con boton pulsado
		static void set_glutIdleFunc();

		// métodos get_ y set_ de acceso a los atributos
		int get_ancho_ventana(){return ancho_ventana;};
		int get_alto_ventana(){return alto_ventana;};

		void set_ancho_ventana(int _ancho_ventana){ancho_ventana = _ancho_ventana;};
		void set_alto_ventana(int _alto_ventana){alto_ventana = _alto_ventana;};

		void movimientoAdelante();
		void movimientoAtras();
		void movimientoDerecha();
		void movimientoIzquierda();

		void movimiento(int dir);

		void rotacionIzquierda();
		void rotacionDerecha();

		void mirarArriba();
		void mirarAbajo();

		void rotacionIzquierdaCS1();
		void rotacionDerechaCS1();
		void rotacionIzquierdaCS2();
		void rotacionDerechaCS2();

		void creacionCamaras();
		void creacionViewports();
};

#endif
