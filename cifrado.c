char* cifradoCiclico(char* mensaje, int llave){
	char alfabeto[26];
	/* llenando el arreglo alfabeto */
	alfabeto[0] = 'a';
	alfabeto[1] = 'b';
	alfabeto[2] = 'c';
	alfabeto[3] = 'd';
	alfabeto[4] = 'e';
	alfabeto[5] = 'f';
	alfabeto[6] = 'g';
	alfabeto[7] = 'h';
        alfabeto[8] = 'i';
        alfabeto[9] = 'j';
        alfabeto[10] = 'k';
        alfabeto[11] = 'l';
        alfabeto[12] = 'm';
        alfabeto[13] = 'n';
	alfabeto[14] = 'o';
        alfabeto[15] = 'p';
        alfabeto[16] = 'q';
        alfabeto[17] = 'r';
        alfabeto[18] = 's';
        alfabeto[19] = 't';
        alfabeto[20] = 'u';
	alfabeto[21] = 'v';
        alfabeto[22] = 'w';
        alfabeto[23] = 'x';
        alfabeto[24] = 'y';
        alfabeto[25] = 'z';

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
}

char* cifradoAutollave(char* mensaje, char* llave){
	/*CODIGO ALEXIS*/
}

char* cifradoContrasena(char* mensaje, char* llave){
	/*CODIGO ALEXIS*/
}
