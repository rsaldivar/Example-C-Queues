/***************************************************************************
 * PROGRAMA PUNTOVENTA:                                                    *
 * AUTOR: ROBERTO CARLOS SALDIVAR                                          *  
 *	: ANGEL DAVID ESCOBEDO CASTILLO                                        *
 * FECHA: 21 /NOVIEMBRE/2011                                               *
 ***************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "Estructura_Pelicula.h"
#define precioPelicula 42
#define CANTPELI 8

//Declaracion global de las peliculas
Pelicula peliculas[CANTPELI];
//Prototipo de funciones que utilizaremos
void MostrarCarteleraPrevia();
void EntrarCine();
void MostrarCarteleraEnCine();
void SeleccionarPelicula();
int VerAsientos(int opcion);
int ComprobarAsientos(int matrix[][],int cantidad);
void CobrarBoletos(int canitdad , int idPelicula);
void GenerarBoletos(int canitdad , int idPelicula);
void pauseClear();

int main()
{   system("cls & title CINE & color f0");
    EntrarCine();
    return 0;
}


/*-------------------------------------------------------------------------------*
 *                           ENTRA CINE                                          *  
 *-------------------------------------------------------------------------------*
 * Mustra la "Cartelera"                                                         *
 * Pregunta si el usuario quiere entrar al cine ,¨                               *
 * Si ingreso 's' entrara a Seleccionar la pelicula.                             *
 * Si ingreso 'n' cierra la aplicacion.                                          *
 *-------------------------------------------------------------------------------*/
void EntrarCine()
{ char entrar = '\0';
  MostrarCarteleraPrevia(); //mostramos una previa de las funciones antes de entra cine
  while(1)
  { fprintf(stdout,"\n\n\n\n\n\n\t\t\t %c Desea Ingresar al Cine ? |s/n|  : ",168);
    fflush(stdin);
    entrar = getchar();
    if( entrar == 's' )SeleccionarPelicula();//Si entrar = s, llamos a SeleccionarPeliucula
    else if( entrar == 'n' )exit(1);
    else { fprintf(stdout,"\n Ingresa solo 's' o 'n' "); pauseClear();}
  }
  pauseClear();
}


/*-------------------------------------------------------------------------------*
 *                              MOSTRAR CARTELERA PREVIA                         *
 *-------------------------------------------------------------------------------*
 * Lee el archivo creado por el Administrador llamado Cartelera.dat              *
 * lo leee y lo alamacena en un arreglo de peliculas, y son mostradas en pantalla*
 * Si no se puede leer, aborta la aplicacion mostrando mensaje .(ConsulteAdmi)   *
 *-------------------------------------------------------------------------------*/
void MostrarCarteleraPrevia()
{ FILE *Cartelera;//Creamos nuestro apuntador tipo FILE Cartelera,
  if (( Cartelera = fopen ( "archivos_administrador/Cartelera.dat" , "r+b" )) == NULL)//Abirmos el archivo en modo Read Binario
  { fprintf (stderr, "Error :\n\t No se encuentra Cartelera.dat  "); 
    fprintf (stderr, "\n\t Favor de consultarlo con el \"Administrador\" .");
    getchar();
    exit (-1); 
  }   
  int i = 0;
  fprintf(stdout,"\n------------------------------------------------------------------");
  fprintf(stdout,"\n                     CINE . EQUIPO 6 ,                            ");
  fprintf(stdout,"\n------------------------------------------------------------------");
  fprintf(stdout,"\n\n\n");
  for(i = 0 ;i  <= CANTPELI-1 ;i++)  //LEEMOS EL ARCHIVO, 
  { if (feof ( Cartelera ))break;//si es fin de archivo detenemos el ciclo
    fread(&peliculas[i],sizeof(Pelicula),1,Cartelera);  //Leemos y guardamos en la estrutura pelicula[i]
    fprintf(stdout," * %s\n",peliculas[i].nombre);//Mostramos en pantalla el nombre de lapelicula leida
  }
  pauseClear();
  fclose(Cartelera);  //Cerramos el archivo de Cartelera.dat
}

/*-------------------------------------------------------------------------------*
 *                           MOSTRAR CARTELERA EN CINE                           *
 *-------------------------------------------------------------------------------*
 *Mostramos la funciones alamacenadas en el arreglo de Peliculas                 *
 *-------------------------------------------------------------------------------*/
void MostrarCarteleraEnCine()
{ int i = 0 , j = 0;
  fprintf(stdout,"\n---------------------------------------------------------------------------");
  fprintf(stdout,"\n                      FUNCIONES DEL DIA DE HOY                             ");
  fprintf(stdout,"\n---------------------------------------------------------------------------");
  fprintf(stdout,"\n   Clave   Nombres                     Clave   Nombres                     ");
  fprintf(stdout,"\n---------------------------------------------------------------------------\n");
  i=0;
  while( i <= CANTPELI-1 )
  { fprintf(stdout," %3i %30s ",i+1,peliculas[i].nombre);
    fprintf(stdout," %3i %30s \n",i+2,peliculas[i+1].nombre);
    i=i+2;
  }     
}

//---------------------------------------------------------------------------------
//                              SELECCION DE PELICULA
//---------------------------------------------------------------------------------
void SeleccionarPelicula()
{ system("cls");
  MostrarCarteleraEnCine();//MOstramos La Cartelera Dentro Del CIne
  int funcion;
  printf("\n\n\t\t Ingrese la clave de la funcion : ");//Pedimos la FUncion
  scanf("%i",&funcion);
  if(funcion >= 1 && funcion <= CANTPELI )VerAsientos( funcion );//Mandamos opcion a Ver Asientos
  else printf(" Esa funcion no existe, concentrate \n");
}


/*-------------------------------------------------------------------------------*
 *                             VER ASIENTOS                                      *
 *-------------------------------------------------------------------------------*
 *Funcion que muestra los asientos disponibles para la pelicula "SELECCIONADA"   *
 *Recibe un id de pelicula, para asi generar asientos aleatoriamente :diponibles *
 * y ocupados , Despues pide la cantidad de boletos a llevar.                    *                                                                              *
 *-------------------------------------------------------------------------------*/
int VerAsientos(int peliculaSeleccionada)
{ int idPelicula = peliculaSeleccionada-1;              //ALAMACENA LA ID PELIULA
  int calidad  =  (peliculas[idPelicula].calidad)-'0';  //ALAMACENA CALIDAD PELICULA
  int i = 0 , j = 0 , X = 0 ,Y = 0 , x = 0;             //VARIBLES AUXILIARES 
  
//---------------------------------------------------------------------------------
//                   MOSTRAMOS TITULO Y ASIENTOS DISPONIBLES
//---------------------------------------------------------------------------------
  system("cls");fprintf(stdout,"\t\t         *** %s ***\n", peliculas[idPelicula].nombre );
//---------------------------------------------------------------------------------
  int pos=0, azar ;                //AUXILIARES PARA CREAR ASIENTOS
  int asientosDisponibles = 100;  //VALOR MAXIMO DE ASITTOS DISPONIBLES
  int Disponible[10][10];         //MATRIZ PARA ASIENTOS
  srand (time(NULL));
  
  for ( i = 0 ; i < 10 ; i++)
  { for ( j = 0 ; j < 10 ; j++)
    {   azar = 1 + rand()%2;
        if( azar == 0  ){   
            fprintf(stdout," [%d,%d]%c",i,j,176);      //IMPIME ASIENTO LIBRE
            Disponible[i][j]=0;    
            pos++;
        }
        if( azar != 0 ){
            fprintf(stdout," [%d,%d]%c",i,j,219);      //IMPRIME ASIENTO OCUPADO
            Disponible[i][j]=1;
            asientosDisponibles--;
            pos++;
        }
     }
     printf("\n\n");     
  }  

//Validar la cantidad de boletos disponibles--------------------------------------  
  if( asientosDisponibles <0  && asientosDisponibles > 100 )
  {fprintf(stdout,"\n\n\t\t La sala de esta funcion esta ocupada "); //VALIDAD QUE EN LA FUNSION ESTEN ASIENTOS DISPONIBLEs
   return -1;
  }
  
//---------------------------------------------------------------------------------
//                   PREGUNTAMOS CUANTOS BOLETOS COMPRARA 
//---------------------------------------------------------------------------------
  int cantidadBoletos = 0;
  fprintf(stdout,"ASIENTOS DISPONIBLES: %i \n",asientosDisponibles); // SI HAY PREGUNTA LO BOLETOS
  fprintf(stdout,"%c Cuantos Boletos llevara ? : ",168); scanf("%d",&cantidadBoletos); 
  if(cantidadBoletos >= 1  && cantidadBoletos < asientosDisponibles)
  {  while(  x != cantidadBoletos )
    { fprintf(stdout,"\nIngresa la posicion de asiento , del boleto %d \n",x+1);
      fprintf(stdout," X : "); scanf("%d",&X);
      fprintf(stdout," Y : "); scanf("%d",&Y);
      if(Disponible[X][Y] == 0 )
        { printf("\t\t\t\tASIENTO ASIGNADO");
             Disponible[X][Y] == 1;
             x++;
         }
      if(Disponible[X][Y] != 0)
        { printf("\t\t\t\tASIENTO OCUPADO "); ; 
        }
    }
  }
  else fprintf(stdout," \n\n Cantidad Invalida de boletos , concentrate!! \n\n  ");
  if( cantidadBoletos > 0 && cantidadBoletos < asientosDisponibles )CobrarBoletos( cantidadBoletos , idPelicula );   
  pauseClear();
  return 0; 
}


/*-------------------------------------------------------------------------------*
 *                               COBRO BOLETOS                                   *
 *-------------------------------------------------------------------------------*
 *Funcion que cobra los boletos segun la cantidad de boletos recibida,           *
 *recibe tambien la idpelicula para mostrar  el nombre de la pelicula            *
 * por la cual pagara dicha cantidad  X precio pelicula la cual es una constante *
 *                                                                               *
 *-------------------------------------------------------------------------------*/
void CobrarBoletos(int cantidad , int idPelicula )
{
  float efectivo = 0 , cambio = 0 ;
  float cantidadPagar = (precioPelicula * cantidad);
  system("cls");
  fprintf(stdout,"\n\n\n\t\t\t COBRO DE BOLETOS ");
  
  while(1)
  { fprintf(stdout,"\n\t\t PELICULA       : %s   " ,peliculas[idPelicula].nombre);     
    fprintf(stdout,"\n\t\t BOLETOS A PAGAR: %i   " ,cantidad);     
    fprintf(stdout,"\n\t\t CANTIDAD PAGAR : %.1f " ,cantidadPagar);     
    fprintf(stdout,"\n\t\t EFECTIVO       : ");  
    fscanf(stdin,"%f",&efectivo);
    if( efectivo >= cantidadPagar )
       {  cambio = efectivo - cantidadPagar;
          fprintf(stdout,"\n\t\t CAMBIO         : %.1f ",cambio);  
          GenerarBoletos(cantidad ,idPelicula );
          break;
       }
    if( efectivo == 0)exit(1);
    else { fprintf(stdout,"\n\nIngrese una cantidad mayor o igual a la cantidad a pagar,\n si , no cuenta con la cantidad ingrese '0' para salir" );         
         }          
    pauseClear();
  } 
}

/*-------------------------------------------------------------------------------*
 *                          GENERACION BOLETOS                                   *
 *-------------------------------------------------------------------------------*
 *Funcion que genera los boletos, en un archivo de texto, recibe la cantidad de  * 
 *boletos pagados y la id de la pelicula para apuntar el detalle                 *                                                                             *
 *-------------------------------------------------------------------------------*/
void GenerarBoletos(int cantidad ,int id )
{  int i = 0;
   FILE *BOLETO;
   system("md boletos");
   if (( BOLETO = fopen ( "boletos/boletos.txt" , "w" )) == NULL)
   { fprintf (stderr, "Error al crear el stream de escritura a  boletos.dat  "); exit (-1); }   
   
   time_t tiempo = time(0);
   struct tm *tlocal = localtime(&tiempo);
   char horaActual[128];
   strftime(horaActual,128,"%d/%m/%y %H:%M:%S",tlocal);
   while ( i < cantidad )
   {  
    fprintf(BOLETO,"\n|===============================|");     
    fprintf(BOLETO,"\n| %30s|",peliculas[id].nombre);
    fprintf(BOLETO,"\n| Class %8s                |",peliculas[id].clasificacion);
    fprintf(BOLETO,"\n| FechHora. %18s  |",horaActual);
    fprintf(BOLETO,"\n| Prec. %d                      |",precioPelicula );
    fprintf(BOLETO,"\n| SanNicolas Garza UANL         |");
    fprintf(BOLETO,"\n| cine Lcc.Equipo6              |");
    fprintf(BOLETO,"\n|_______________________________|");   
    i++;
   }
   fclose(BOLETO);
   system("cd boletos & boletos.txt & cls ");   
}


//FUncion topdown, detiene la ejecucion y limpia pantalla--------------------
void pauseClear()
{ fflush(stdin);
  fprintf(stdout,"\n\n\t\t\t pulsa una tecla para continuar...");
  getchar();
  system("cls");
}
