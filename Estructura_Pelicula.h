#ifndef ESTRUCTURA_PELICULA_H_
#define ESTRUCTURA_PELICULA_H_
struct pelicula
{ 
  char nombre[35];
  char calidad;
  char clasificacion[5]; 
  struct pelicula *enlace;
};
typedef struct pelicula Pelicula;
typedef Pelicula *ptrPelicula;
#endif
