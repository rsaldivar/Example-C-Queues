#ifndef OPERACIONES_COLA_H_
#define OPERACIONES_COLA_H_
#include <stdio.h>//Lecturas y Escrituras Estandar
#include <stdlib.h>//LLamada Systema
#include <string.h>//Copiar las cadenas caracteres
#include "Estructura_Pelicula.h" //Usar Las estructura de datos "Pelicula"

//CREAMOS NUESTRAS ESTRUCTURAS A MANEJAR, Estrenos y Proximos
ptrPelicula colaEstrenos = NULL;
ptrPelicula colaProximos = NULL;


//---------------------------------------------------------------------------------


void insertarCola(ptrPelicula *ultimoDelaCola , const char *nombre , const char calidad ,const char *clasificacion)
{ ptrPelicula nuevo = malloc(sizeof(Pelicula));  
  
  //SELE ASIGAN LOS VALORES AL NUEVO NODO
  strcpy( nuevo->nombre , nombre);
  nuevo->calidad = calidad;
  strcpy( nuevo->clasificacion , clasificacion);
  //COLOCAMOS EL NUEVO EN LA COLA
  nuevo->enlace = *ultimoDelaCola;
  *ultimoDelaCola = nuevo;//AHORA EL NUEVO ES EL ULTIMO

}

//---------------------------------------------------------------------------------


char borrarCola(ptrPelicula *cola)
{
  ptrPelicula  previo, actual, temporal;/*variables auxiliares*/
	previo = NULL;/*se inicializa el en nulo el previo que es el que contendra la lista*/
	actual = *cola;/*se asigna a actual el inicio y la lista completa*/
	
  if (actual->enlace != NULL) {/*pregunta si no es el ultimo nodo en la lista*/
		while (actual->enlace != NULL ){/*se recorrera la lista sin llegar al ultimo elemento de la lista*/
			previo = actual;/*se asigna la posicion de actual a previo*/
			actual = actual -> enlace;/*se avanza al enlace nodo*/
		}/*se llego hasta un nodo antes del final y se asigna a temporal la lista*/
		temporal=actual;/*para que este sea borrado y asi liberar el espacio ocupado por el elemento*/
		previo->enlace = NULL;/*se le asigna a previo en su posicion enlace nulo, es decir, el fin de la lista*/
		free(temporal);/*se libera el espacio del nodo a borrar*/
		return 'a';/*se regresa un valor para indicar que no era el ultimo nodo*/
	}
	return '\0';/*se regresa este valor para indicar que es el ultimo nodo*/
}


/*funcion para determinar si hay elementos en la lista, recibe como parametro
 por valor la el inicio de la lista*/
int isempty(ptrPelicula cola)
{
 return colaProximos == NULL;/*pregunta si hay elemento en la lista, regresa nulo si no hay*/
}		      /*de lo contrario regresa un valor diferente*/


//---------------------------------------------------------------------------------


void mostrarCola(ptrPelicula cola)
{ if(cola == NULL ){
     fprintf(stdout,"\n\nNo hay peliculas aun...");
     system("pause");
  }
  else { 
  fprintf(stdout,"\t| NOMBRE PELICULA                | CLASIFICACION |\n "); 
  fprintf(stdout,"\t|------------------------------------------------|\n" );
  while(cola != NULL ){
   fprintf(stdout,"\t| %30s |",cola->nombre);
	 fprintf(stdout,"\t  %5s  |" ,cola->clasificacion);
   fprintf(stdout,"\n");
   cola = cola->enlace;
  }fprintf(stdout,"\t|------------------------------------------------|" );
  }
}

//---------------------------------------------------------------------------------


AgregarPeliculaColaProxima()
{
  Pelicula nuevo ;  
  system("cls");
  fprintf(stdout,"\n\n\t INGRESA LOS SUIGUIENTES DATO DE UNA PELICULA ");
  fflush(stdin);
  fprintf(stdout,"\nNombre        : " );
  gets(nuevo.nombre);
  fprintf(stdout,"\nCalidad [1-10]: " );
  nuevo.calidad = getchar();
  fprintf(stdout,"\nClafificacion : " );
  fflush(stdin);
  gets(nuevo.clasificacion);
  insertarCola(&colaProximos , nuevo.nombre , nuevo.calidad, nuevo.clasificacion);
}


//---------------------------------------------------------------------------------


void GenerarColaProximos()
{
 insertarCola(&colaProximos , "Ice Age 4",'8',"A");
 insertarCola(&colaProximos , "Paranormal Activity 4",'3',"C");
 insertarCola(&colaProximos , "El caballero Oscuro : Renace",'7',"B+15");
 insertarCola(&colaProximos , "Residen Evil 5 : Venganza",'8',"B+15");
 insertarCola(&colaProximos , "Silent Hill  : Revelation 3D",'6',"B");
 insertarCola(&colaProximos , "Call of Duty",'4',"B");
 insertarCola(&colaProximos , "Hancock 2",'8',"A");
 insertarCola(&colaProximos , "Iron Man 3",'9',"A");
 insertarCola(&colaProximos , "Piratas de Caribe 5",'8',"A");
 insertarCola(&colaProximos , "Toy Story 4",'9',"A");
 insertarCola(&colaProximos , "Avatar 3",'9',"A");  

}

//---------------------------------------------------------------------------------


void GenerarColaEstrenos()
{    
 insertarCola(&colaEstrenos , "Sherlock Holmes 2",'7',"A");
 insertarCola(&colaEstrenos , "American Pie: El Reencuentro",'6',"B"); 
 insertarCola(&colaEstrenos , "Los juegos del Hambre",'5',"B");
 insertarCola(&colaEstrenos , "Rec 3 Genesis",'4',"A");
 insertarCola(&colaEstrenos , "Los Vengadores",'9',"A");
 insertarCola(&colaEstrenos,  "Battleship",'7',"B");
 insertarCola(&colaEstrenos , "MIB 3",'8',"A");
 insertarCola(&colaEstrenos , "Madgascar 3",'8',"A");

}


//---------------------------------------------------------------------------------

void VerColaEstrenos( )
{ system("cls");
  fprintf(stdout,"\n\n");
  fprintf(stdout,"\t|------------------------------------------------|\n" );    
  fprintf(stdout,"\t|                 ESTRENOS ACTUALES.             |\n" );
  fprintf(stdout,"\t|------------------------------------------------|\n ");
  mostrarCola(colaEstrenos);

}


//---------------------------------------------------------------------------------


void VerColaProximas()
{ system("cls");
  fprintf(stdout,"\n\n");
  fprintf(stdout,"\t|------------------------------------------------|\n" );    
  fprintf(stdout,"\t|              PROXIMAMENTE EN CINES.            |\n" );
  fprintf(stdout,"\t|------------------------------------------------|\n ");
  mostrarCola(colaProximos);
}


//---------------------------------------------------------------------------------

void ActualizarPelicula( )
{ 
 	
  if (!isempty(colaProximos)){

  ptrPelicula  previo, actual, temporal;/*variables auxiliares*/
	previo = NULL;/*se inicializa el en nulo el previo que es el que contendra la lista*/
	actual = colaProximos ;/*se asigna a actual el inicio y la lista completa*/
	
   if (actual->enlace != NULL) {/*pregunta si no es el ultimo nodo en la lista*/
		while (actual->enlace != NULL ){/*se recorrera la lista sin llegar al ultimo elemento de la lista*/
			previo = actual;/*se asigna la posicion de actual a previo*/
			actual = actual -> enlace;/*se avanza al enlace nodo*/
		}/*se llego hasta un nodo antes del final y se asigna a temporal la lista*/
		temporal=actual;/*para que este sea borrado y asi liberar el espacio ocupado por el elemento*/
		previo->enlace = NULL;/*se le asigna a previo en su posicion enlace nulo, es decir, el fin de la lista*/
	
  	//BORRAMOS LA PRIMER PELICULA LOS ESTRENOS 
    borrarCola(&colaEstrenos);
    //INSERTAMOS UNA PELICULA EN LA COLA DE LOS ESTRENOS  
    insertarCola(&colaEstrenos,temporal->nombre,temporal->calidad, temporal->clasificacion);
    free(temporal);/*se libera el espacio del nodo a borrar*/
    }
  
  }
  else{
        fprintf(stdout,"No se puede realizar algo por que no hay estrenos proximos ..");
        system("pause");
        free(colaProximos);
        colaProximos = 0;
      }

} 

#endif
