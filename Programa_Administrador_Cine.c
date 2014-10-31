/***************************************************************************
 * PROGRAMA_PUNTO_ADMINISTRADOR_CINE:                                      *
 * AUTOR: ROBERTO CARLOS SALDIVAR                                          *  
 *  : ANGEL DAVID ESCOBEDO CASTILLO                                        *
 * FECHA: 21 /NOVIEMBRE/2011                                               *
 ***************************************************************************/
#include "Crear_Carteleras.h"//Incluimos las funciones de Crear_Carteleras.h
#include <time.h>
time_t start,end; //creamos nuestra variables time_t

//Prototipo de Funciones que usaremos.
void inicio();
void Salir();
int  ValidarAdministrador();
void ControlAdministrador();
void PausarContinuarSalir();
void VerCarteleraActual();
void VerCarteleraProxima();
void TimeActualizar();

/*************************        MAIN     *********************************/
/*     Funcion Que llama A La funcion Inicio que inicia el  Programa        /
/***************************************************************************/
int main( )
{   start=time(NULL);//Iniciamos la variable start de tiempo
    inicio();  
    return 0;
}

/*-------------------------------------------------------------------------------*
 *                          PAUSAR CONTINUAR SALIR                               *  
 *-------------------------------------------------------------------------------*
 * Funcion que carga las colas estrenos y proximos por default,                  *
 * Pregunta si quieres acceder al programa  , manda a llamar ala ValidadcionAdmi *
 *-------------------------------------------------------------------------------*/
void inicio()
{ char entrar='\0';
  system("color f0 & title PROGRAMA ADMINISTRADOR DE CINE ");
  GenerarColaEstrenos();
  GenerarColaProximos();
  while( entrar != 'n')
  { entrar = '\0';
    fprintf(stdout,"\n\n\n\n\n\n\n\t\t %c DESEA INGRESAR AL SISTEMA ?[s/n] : ",168);
    fflush(stdin);
    entrar=getchar();
    if( entrar == 's' )if(ValidarAdministrador() == 0 )ControlAdministrador();
  }
}

/*-------------------------------------------------------------------------------*
 *                          VALIDAR ADMINIRTRADOR                                *  
 *-------------------------------------------------------------------------------*
 * Pregunta el nombre de usuario y la contraseña para asi continuar              *
 *-------------------------------------------------------------------------------*/
int ValidarAdministrador()
{ int i = 0; 
  char user[' '] , pass[' '];  //VARIABLES PARA ALACENAR LOS DATOS LEIDOS
  const char *usuario="usuario" ,   *password="123";//VARIABLES DEL USUARIO VALIDO
  
  system("cls");
  fprintf(stdout,"\n\n\t\t INGRESA LOS DATOS DEL ADMINISTRADOR");
  fprintf(stdout,"\n\n\t\t -----------------------------------");
  fprintf(stdout,"\n\n\t\t NOMBRE  (usuario)default : "); 
  fflush(stdin); gets(user);
  if( strcmp(user,usuario) != 0 ){fprintf(stdout,"USUARIO INCORRECTO");return -1;}
  fprintf(stdout,"\n\n\t\t PASSWORD (123)default    : ");    
  fflush(stdin); gets(pass);
  if( strcmp(pass,password) != 0 ){fprintf(stdout,"CONTRASEÑA INCORRECTA"); return -1; }  
  return 0;
}


/*-------------------------------------------------------------------------------*
 *                          TIEMPO ACTUALIZAR                                    *  
 *-------------------------------------------------------------------------------*
 * Hace un conteo de 3 segundos para actualizar una pelicula en los estrenos     *
 *-------------------------------------------------------------------------------*/
void TimeActualizar()
{ int i = 0 , tiempo = 3;
  for ( i = 0 ; i <= tiempo ; i++){  
   fprintf(stdout," \n\n\n\n\n\n\n\n\t\t\t atualizando pelicula ... %d",tiempo-i);     
   sleep(1000);
   system("cls");
  } 
  ActualizarPelicula();
}

/*-------------------------------------------------------------------------------*
 *                          CONTROL ADMINITRADO                                  *  
 *-------------------------------------------------------------------------------*
 * Funcion que hace todo el ciclo de actualizacion de peliculas y muestra        *
 * las peliculas actuales como estrenos y las peliculas proximas en cartelera    * 
 *-------------------------------------------------------------------------------*/
 void ControlAdministrador()
{ while( 1 ) //Mistras sea verdadero 
  { VerColaProximas();     PausarContinuarSalir();             
    VerColaEstrenos();     PausarContinuarSalir();        
    TimeActualizar();                     
   } 
}

/*-------------------------------------------------------------------------------*
 *                          PAUSAR CONTINUAR SALIR                               *  
 *-------------------------------------------------------------------------------*
 * Funcion que detiene la ejecucion y pregunta si quieres continuar o terminar   *
 *-------------------------------------------------------------------------------*/
void PausarContinuarSalir()
{ fprintf(stdout,"\n\n"
  "\t|------------------------------------------------|\n"
  "\t|                  OPCIONES                      |\n"
  "\t|------------------------------------------------|\n"
  "\t|Terminar  = pulsa la tecla 'n'                  |\n"
  "\t|Continuar = pulsa una otra tecla cualquiera     |\n"
  "\t|------------------------------------------------|\n");
  char continuar = '\0';
  continuar = getch();
  if( continuar == 'n' )Salir(); 
  system("cls");
}

/*-------------------------------------------------------------------------------*
 *                           SALIR                                               *  
 *-------------------------------------------------------------------------------*
 * Funcion que muestra el tiempo que tardo la aplicacion                         *
 * al terminar mustra un archivo con las peliculas que quedaron como estrenos    * 
 *-------------------------------------------------------------------------------*/
void Salir()
{ system("cls");
  end=time(NULL);//Iniciamos la variable start
  fprintf(stdout,"\n\n EL tiempo de ejecicion del programa fue : %.1f \n\n\n",difftime(end,start) );
  system("pause");
  CrearArchivos();//lLamamos ala funcion Crear Archivos, De Crear_Carteleras.h
  exit(1);
}
