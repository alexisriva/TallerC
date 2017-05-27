#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <ctype.h>
#define LARGO 1024

//Se usan los codigos ASCII de las letras para la resolucion de este problema

void cifrado(char mensaje[], int n);
int getIndice(char letra);

char abc[27] ={'a','b','c','d','e','f','g','h','i','j','k','l','m','n',
		       'o','p','q','r','s','t','u','v','w','x','y','z',' '};
char morseL[27][13]={{". ---"},{"--- . . ."},{"--- . --- ."},{"--- . ."},{"."},{". . --- ."},
		     {"--- --- ."},{". . . ."},{". ."},{". --- --- ---"},{"--- . ---"},{". --- . ."},   	             {"--- ---"},{"--- ."},{"--- --- ---"},{". --- --- ."},{"--- --- . ---"},
		     {". --- ."},{". . ."},{"---"},{". . ---"},{". . . ---"},{". --- ---"},
		     {"--- . . ---"},{"--- . --- ---"},{"--- --- . ."},{"/"}};
char morseN[10][5] = {{"--- --- --- --- ---"},{". --- --- --- ---"},{". . --- --- ---"},
		      {". . . --- ---"},{". . . . ----"},{". . . . ."},{"--- . . . ."},
		      {"--- --- . . ."},{"--- --- --- . ."},{"--- --- --- --- ."}};

int main(int argc, char *argv[]) {
	
	if (argc == 1) {	
		char mensaje[LARGO] = {0};
		int num,n;

        	printf("Ingrese mensaje a cifrar: ");
        	scanf("%1024[^\n]s",mensaje);
	
        	printf("Ingrese la llave numerica: ");
        	n = scanf("%d", &num);

		if (!n)
			printf("Solo se permiten caracteres numericos\n");
		else {
			while (!(num>=-26&&num<=26)) {
				printf("Debe ingresar un valor valido, intente nuevamente: ");
				scanf("%d", &num);
			}
			cifrado(mensaje,num);
		}
	} else
		cifrado(argv[2],atoi(argv[1]));

	return 0;
}

void cifrado(char mensaje[], int n) {

        char output[LARGO] = {0};
	char outputMorse[LARGO] = {0};
        int ascii;
        int nuevo_ascii;

        for (int i=0;i<strlen(mensaje);i++) {

                ascii = (int)mensaje[i];
                nuevo_ascii = ascii+n;
	        if ((ascii>=97&&ascii<=122)||(ascii>=65&&ascii<=90)) {
	                if (n>0) {
	                        if (ascii>=97 && ascii<=122) {
	                                if (nuevo_ascii>122)
	                                        output[i] = nuevo_ascii - 26;
	                                else
	                                        output[i] = nuevo_ascii;
	                        } else {
	                                if (nuevo_ascii>90)
	                                        output[i] = nuevo_ascii - 26;
	                                else
	                                        output[i] = nuevo_ascii;
	                        }
	                } else {
	                        if (ascii>=97 && ascii<=122) {
	                                if (nuevo_ascii<97)
	                                        output[i] = nuevo_ascii + 26;
	                                else
	                                        output[i] = nuevo_ascii;
	                        } else {
	                                if (nuevo_ascii<65)
	                                        output[i] = nuevo_ascii + 26;
	                                else
	                                        output[i] = nuevo_ascii;
	                        }
	                }
			strcat(outputMorse,morseL[getIndice(tolower(output[i]))]);
	        } else if (mensaje[i] == ' ') {
			output[i] = mensaje[i];
			strcat(outputMorse,morseL[getIndice(output[i])]);
		} else
			output[i] = mensaje[i];
		strcat(outputMorse,"   ");
        }

        printf("Tu mensaje cifrado es: %s\n",output);
	printf("El mensaje en Morse es: %s\n",outputMorse);

}

int getIndice(char letra) {
	int indice = -1;
	for (int i=0;i<27;i++) {
		if (abc[i]==letra)
			indice = i;
	}
	return indice;
}
