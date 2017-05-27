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

	return 0;
}
