#include <stdio.h>
#include "cifrado.h"
#include "codificacion.h"
#define TAMANO 1024

int main(int argc, char *argv[]) {
	int llave = 0;
	char mensaje[TAMANO] = {'\0'};

	if (argc == 1){
		printf("Tipo de cifrado:");
		char cifrado;
		scanf("%c", cifrado);
		if (cifrado=='c'){
			printf ("Cifrado Ciclico\n");
			printf("Ingrese mensaje a cifrar:");
			leer(mensaje);
			printf("Ingrese la llave numerica:");
			scanf("%d", &llave);

			char* menCifrado = cifradoCiclico(mensaje,llave);
			printf("\nMensaje cifrado: ");
			mostrarMensaje(menCifrado);

                }
                else if (cifrado=='a'){
			
                }
                else if (cifrado=='p'){
			
                }
                else{
                        printf("Tipo de cifrado no correcto.");
		}
	}

	else{
		llave = atoi(argv[1]);
		if (argv[3][2]=='c'){
			
		}
		else if (argv[3][2]=='a'){
			
		}
		else if (argv[3][2]=='p'){
			
		}
		else{
			printf("Tipo de cifrado no correcto.");
		}
	}

	return 0;
}

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

//Funcion que me permite imprimir un char*
void mostrarMensaje(char* mensaje){
	int i=0;
	while (mensaje[i]!='\0'){
		printf("%c", mensaje[i]);
		i++;
	}
	printf("\n\n");
}
