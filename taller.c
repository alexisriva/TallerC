#include <stdio.h>
#include <string.h>
#define LARGO 50

int main(int argc, char *argv[]) {

	char mensaje[LARGO];
	int num;

        printf("Ingrese mensaje a cifrar: ");
        scanf("%s", mensaje);

        printf("Ingrese la llave numerica: ");
        scanf("%d", &num);

	printf("%s %d",mensaje,&num);

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
                                                output[i] = 91 + nuevo_ascii -61;
                                        else
                                                output[i] = nuevo_ascii;
                                }
                        }
                } else
                        output[i] = ascii;

        }
        printf("%s\n",output);

	return 0;
}


