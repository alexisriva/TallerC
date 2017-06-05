#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define LARGO 1024

char abc[27] ={'a','b','c','d','e','f','g','h','i','j','k','l','m','n',
'o','p','q','r','s','t','u','v','w','x','y','z',' '};
char morseL[27][13]={{". ---"},{"--- . . ."},{"--- . --- ."},{"--- . ."},{"."},{". . --- ."},
		     {"--- --- ."},{". . . ."},{". ."},{". --- --- ---"},{"--- . ---"},{". --- . ."},   	             {"--- ---"},{"--- ."},{"--- --- ---"},{". --- --- ."},{"--- --- . ---"},
		     {". --- ."},{". . ."},{"---"},{". . ---"},{". . . ---"},{". --- ---"},
		     {"--- . . ---"},{"--- . --- ---"},{"--- --- . ."},{"/"}};
char morseN[10][5] = {{"--- --- --- --- ---"},{". --- --- --- ---"},{". . --- --- ---"},
		      {". . . --- ---"},{". . . . ----"},{". . . . ."},{"--- . . . ."},
{"--- --- . . ."},{"--- --- --- . ."},{"--- --- --- --- ."}};

char* claveMorse(char* mensaje){
	char* outputMorse = (char *) malloc(sizeof(char) * LARGO);
	
	for (int i=0;i<strlen(mensaje);i++) {
		for (int j=0;j<27;j++) {
			if (mensaje[i] == ' '){
				strcat(outputMorse,morseL[i]);
			}			
			else if (tolower(mensaje[i])==abc[j]){
				strcat(outputMorse,morseL[j]);			
			}	
			strcat(outputMorse,"   ");
		}
	}
	return outputMorse;
}
