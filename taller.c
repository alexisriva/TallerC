#include <stdio.h>
#include <string.h>
#define LARGO 50

//Se usan los codigos ASCII de las letras para la resolucion de este problema

void cifrado(char mensaje[], int n);

int main(int argc, char *argv[]) {

	char mensaje[LARGO];
	int num,n;

        printf("Ingrese mensaje a cifrar: ");
        scanf("%s", mensaje);

        printf("Ingrese la llave numerica: ");
        n = scanf("%d", &num);
	if (!n) {
		printf("Solo se permiten caracteres numericos");
	} else {
		while (!(num>=-26&&num<=26)) {
			printf("Debe ingresar un valor valido, intente nuevamente: ");
			scanf("%d", &num);
		}
		cifrado(mensaje,num);
	}

	return 0;
}

void cifrado(char mensaje[], int n) {

        char output[LARGO];
        int ascii;
        int nuevo_ascii;

        for (int i=0;i<strlen(mensaje);i++) {

                ascii = (int)mensaje[i];
                nuevo_ascii = ascii+n;
                if ((ascii>=97&&ascii<=122)||(ascii>=65&&ascii<=90)) {
                        if (n>0) {
                                if (ascii>=97 && ascii<=122) {
                                        if (nuevo_ascii>122)
                                                output[i] = 96 + nuevo_ascii - 122;
                                        else
                                                output[i] = nuevo_ascii;
                                } else {
                                        if (nuevo_ascii>90)
                                                output[i] = 64 + nuevo_ascii - 90;
                                        else
                                                output[i] = nuevo_ascii;
                                }
                        } else {
                                if (ascii>=97 && ascii<=122) {
                                        if (nuevo_ascii<97)
                                                output[i] = 123 + nuevo_ascii - 97;
                                        else
                                                output[i] = nuevo_ascii;
                                } else {
                                        if (nuevo_ascii<65)
                                                output[i] = 91 + nuevo_ascii -65;
                                        else
                                                output[i] = nuevo_ascii;
                                }
                        }
                } else
                        output[i] = ascii;

        }
        printf("%s\n",output);

}



