# Scape Room OpenGL

Este proyecto es una pequeña demo con fines educativos de un juego de tipo Escape Room desarrollado utilizando **OpenGL**. El objetivo principal es crear una experiencia inmersiva en la que el jugador deba resolver acertijos y encontrar pistas para escapar de una habitación cerrada. El proyecto se centra en la renderización gráfica 3D y la interacción en tiempo real.

## Tecnologías Utilizadas

- **OpenGL**: API de gráficos utilizada para la renderización 3D.
- **C++**: Lenguaje de programación para la lógica del juego y la interacción con OpenGL.
- **GLFW**: Librería para la creación de ventanas y la gestión de eventos.
- **GLM**: Librería para operaciones matemáticas avanzadas en gráficos 3D.
- **SOIL**: Librería para la carga de texturas en OpenGL.

## Estructura del Proyecto

- **`src/`**: Contiene el código fuente en C++.
  - **`shaders/`**: Programas de sombreado (vertex y fragment shaders) utilizados en la renderización.
  - **`textures/`**: Archivos de imagen utilizados como texturas para los objetos 3D.
  - **`models/`**: Archivos que contienen los modelos 3D utilizados en el juego.
  - **`main.cpp`**: Archivo principal donde se inicializa y ejecuta el juego.
- **`CMakeLists.txt`**: Archivo de configuración para la compilación del proyecto con CMake.

## Funcionalidades Principales

- **Renderizado 3D**: El juego presenta un entorno 3D con gráficos renderizados en tiempo real.
- **Interacción del Jugador**: El usuario puede moverse por el entorno, interactuar con objetos y resolver acertijos.
- **Mecánicas de Escape Room**: Incluye acertijos y desafíos que deben ser resueltos para avanzar en el juego.
- **Carga de Modelos y Texturas**: Soporte para la carga y aplicación de texturas a modelos 3D utilizando SOIL.

## Instalación y Ejecución

1. Clona el repositorio: `git clone https://github.com/Vicen9/ScapeRoomOpenGL.git`
2. Accede al directorio del proyecto: `cd ScapeRoomOpenGL`
3. Configura y compila el proyecto utilizando CMake: `cmake .` y luego `make`.
4. Ejecuta el juego: `./ScapeRoomOpenGL`.

## Autor
* Vicente Castellano Gomez, vicentecastellano65@gmail.com - vcg00025@red.ujaen.es

