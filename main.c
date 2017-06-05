#include <stdio.h>
#include <stdlib.h>
#include "cifrado.h"
#include "codificacion.h"
#define TAMANO 1024

void leer(char* mensaje);
void leerArgumento(char* mensaje, char argv[]);
void mostrarMensaje(char* mensaje);

int main(int argc, char *argv[]) {
	int llave = 0;
	char mensaje[TAMANO] = {'\0'};
	char contrasena[TAMANO] = {'\0'};

	if (argc == 1){
		printf("Tipo de cifrado:");
		int cifrado;
		scanf("%d", &cifrado);

		if (cifrado=='c'){
			printf ("Cifrado Ciclico\n");
			printf("Ingrese mensaje a cifrar:");
			leer(mensaje);
			printf("Ingrese la llave numerica:");
			scanf("%d", &llave);

			char* menCifrado = cifradoCiclico(mensaje,llave);
			printf("\nMensaje cifrado: ");
			mostrarMensaje(menCifrado);

			char* menMorse = claveMorse(mensaje);
			printf("\nMensaje cifrado en morse:");
			mostrarMensaje(menMorse);
                }

                else if (cifrado=='a'){
			printf("Cifrado Auto-llave");
			printf("Ingrese mensaje a cifrar:");
			leer(mensaje);
			printf("Ingrese la clave:");
			leer(contrasena);

			char* menAutollave = cifradoAutollave(mensaje, contrasena);
			printf("\nMensaje cifrado: ");
			mostrarMensaje(menAutollave);
                }
                else if (cifrado=='p'){
			printf("Cifrado Contrasena");
			printf("Ingrese mensaje a cifrar:");
			leer(mensaje);
			printf("Ingrese la clave:");
			leer(contrasena);

			char* menContrasena = cifradoContrasena(mensaje, contrasena);
			printf("\nMensaje cifrado: ");
			mostrarMensaje(menContrasena);			
                }
                else{
                        printf("Tipo de cifrado no correcto.");
		}
	}

	else{
		if (argv[3][1]=='c'){
			llave = atoi(argv[1]);
			leerArgumento(mensaje, argv[2]);

			printf ("Cifrado Ciclico\n");
			char* menCifrado = cifradoCiclico(mensaje,llave);
			printf("\nMensaje cifrado: ");
			mostrarMensaje(menCifrado);

			char* menMorse = claveMorse(mensaje);
			printf("\nMensaje cifrado en morse:");
			mostrarMensaje(menMorse);
		}
		else if (argv[3][1]=='a'){
			printf("Cifrado Auto-llave");
			leerArgumento(contrasena, argv[1]);
			leerArgumento(mensaje, argv[2]);

			char* menAutollave = cifradoAutollave(mensaje, contrasena);
			printf("\nMensaje cifrado: ");
			mostrarMensaje(menAutollave);

		}
		else if (argv[3][1]=='p'){
			printf("Cifrado Contrasena");
			leerArgumento(contrasena, argv[1]);
			leerArgumento(mensaje, argv[2]);

			char* menContrasena = cifradoContrasena(mensaje, contrasena);
			printf("\nMensaje cifrado: ");
			mostrarMensaje(menContrasena);	
		}
		else{
			printf("Tipo de cifrado no correcto.");
		}
	}

	return 0;
}

/*FUNCIONES AUXILIARES*/

//Funcion que me permite pasar un char* a un arreglo de char
void leer(char* mensaje){
	int i=0;
        char c;
        while ((c=getchar())!='\n'){
		mensaje[i]=c;
                i++;
        }
	mensaje[i]='\0';
}

//Funcion que me permite pasar el mensaje del argumentos a un arreglo de char
void leerArgumento(char* mensaje, char argv[]){
	int i=0;
	while (argv[i]!='\0'){
		mensaje[i]=argv[i];
		i++;
	}
	mensaje[i]='\0';
}

//Funcion que me permite imprimir un char*
void mostrarMensaje(char* mensaje){
	int i=0;
	while (mensaje[i]!='\0'){
		printf("%c", mensaje[i]);
		i++;
	}
	printf("\n\n");
}
