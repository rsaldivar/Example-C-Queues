#ifndef CARTELERAS_H_
#define CARTELERAS_H_
#include "Operaciones_Cola.h"/*Inclusion de las librerias standar y la libreria string*/

/*Apuntadores para el uso de Archivos*/
FILE *Cartelera;
FILE *Reporte;


int CrearArchivos()
{  
//---------------------------------------------------------------------------------
//                              ABRIMOS  ARCHIVOS
//---------------------------------------------------------------------------------


 system("md archivos_administrador"); /*Creamos una carpeta mediante una llamada al sistema md=MakeDir */ 

 if (( Cartelera = fopen ( "archivos_administrador/Cartelera.dat" , "w+b" )) == NULL) //Arbirmos Cartelera en modo Write-Escritura , tipo Binario
 { fprintf (stderr, "Error al crear el archivo Cartelera.dat  ");
	 system("pause"); return(-1);
 }  
 if (( Reporte= fopen ( "archivos_administrador/CarteleraReporte.txt" , "w" )) == NULL) //Arbirmos Reporte en modo Write-Escritura , tipo default=Texto
 { fprintf (stderr, "Error al crear el archivo Reporte ");
   system("pause"); return(-1);
 }



//---------------------------------------------------------------------------------
//                   VALIDADMOS QUE NO ESTE VACIA LA COLA ESTRENOS
//---------------------------------------------------------------------------------

 if(colaEstrenos == NULL )// Si la cola de estrenos esta vacia muestra un mensaje y termina programa 
 { fprintf(Reporte,"\n\nNo hay peliculas aun...");//Escrito En reporte
   system("pause"); return(-1);
 }



//---------------------------------------------------------------------------------
//                        ESCRIBIMOS CABEZERA EN ARCHIVO
//---------------------------------------------------------------------------------


 fprintf(Reporte,"\n\n");
 fprintf(Reporte,"\t --------------------------------------------------\n");    
 fprintf(Reporte,"\t                  ***  ESTRENOS ***                \n");
 fprintf(Reporte,"\t --------------------------------------------------\n");
 fprintf(Reporte,"\n\n %30s            CLASIFICION  \n","NOMBRE PELICULA" ); 
 fprintf(Reporte,"\t --------------------------------------------------\n");
 



//---------------------------------------------------------------------------------
//                            CREAMOS LOS ARCHIVOS DE ESTRENOS
//---------------------------------------------------------------------------------

 while(colaEstrenos != NULL )
 { //Ecribimos en CarteleraReporte.txt
   fprintf(Reporte,"\n");//salto de linea
   fprintf(Reporte,"\t %30s ",colaEstrenos->nombre);//nombre del estreno
   fprintf(Reporte,"  %10s ",colaEstrenos->clasificacion);//clasificaion del estreno
   fwrite( colaEstrenos , sizeof(Pelicula) , 1 , Cartelera );//Escribimos en Cartelera.dat toda la infromacion del nodo
   colaEstrenos = colaEstrenos->enlace;//Nos enlazamos al siguiente nodo 
 }
   

//---------------------------------------------------------------------------------
//                                 CERRAMOS LOS ARCHIVOS
//---------------------------------------------------------------------------------

 fclose(Cartelera);//Cerrarmos los  Archivos   
 fclose(Reporte);
 system("cd archivos_administrador  & CarteleraReporte.txt"); //Antes de finalizar, se abre el CarteleraReporte.txt
 system("cls");


}

#endif
