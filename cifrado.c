#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define FILAS 26
#define COLS 26
#define LARGO 1024

char alfabeto[26]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','w','x','y','z'};
int getIndice(char letra); //Funcion auxiliar

char* cifradoCiclico(char* mensaje, int llave){
	int lenMen;
	char caracter = '\0';	
		
	lenMen = 0;
	while(mensaje[lenMen]!='\0'){
		lenMen++;
	}
	/*For que cifra el mensaje*/
	for(int i=0;i<lenMen;i++){
		llave = llave%26;
		for(int j=0;j<26;j++){
			if (mensaje[i]==alfabeto[j]){
				if (j+llave>25){
					caracter = alfabeto[llave-1];
				}else{
					caracter=alfabeto[j+llave];
				}
			}
		}
		if (((int)mensaje[i]>=65 && (int)mensaje[i]<=90) || ((int)mensaje[i]>=97 && (int)mensaje[i]<=122)){
			mensaje[i]=caracter;
		}
	}
	return mensaje;
} //FIN CIFRADO CICLICO

char* cifradoAutollave(char* mensaje, char* llave){
	char tabula_recta[FILAS][COLS];
	int pos,row,col;
	char* cifrado = (char *) malloc(sizeof(char) * LARGO);
	char mensajec[LARGO] = {0};
	char psw[LARGO] = {0};
	
	strcpy(psw,llave);
	
	for (row=0;row<FILAS;row++) {
		pos=0;
		for (col=0;col<COLS;col++) {
			if ('A'+row+col>'Z' && row>0) {
				tabula_recta[row][col]='A'+pos;
				pos++;
			}
			else if ('A'+row+col=='Z')
				tabula_recta[row][col]='Z';
			else
				tabula_recta[row][col]='A'+row+col;
		}
	}
	
	for (int i=0;i<strlen(mensaje);i++) {
		if (mensaje[i]==' ')
			continue;
		mensajec[i]=mensaje[i];
	}
	
	strcat(psw,mensajec);
	
	for (int i=0;i<strlen(mensajec);i++) {
		int imensajec = getIndice(mensajec[i]);
		int ipsw = getIndice(psw[i]);
		cifrado[i] = tabula_recta[imensajec][ipsw];
	}
	
	return cifrado;
} //FIN CIFRADO AUTOLLAVE

//Metodo auxiliar usado en cifrado autollave
int getIndice(char letra) {
	int indice = -1;
	for (int i=0;i<27;i++) {
		if (alfabeto[i]==letra)
			indice = i;
	}
	return indice;
}

char* cifradoContrasena(char* mensaje, char* llave){
	char* cifrado = (char *) malloc(sizeof(char) * LARGO);
	char psw[LARGO] = {0};
	
	strcpy(psw,llave);
	strcat(psw,alfabeto);
	
	for (int i=0;i<strlen(mensaje);i++) {
		for (int j=0;j<26;j++) {
			if (tolower(mensaje[i])==alfabeto[j])
				cifrado[i]=psw[j];
			else
				cifrado[i]=mensaje[i];
		}
	}
	return cifrado;
} //FIN CIFRADO CONTRASENA
