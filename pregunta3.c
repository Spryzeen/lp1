#include <stdio.h>

int main(void) {
	int c;

	int vocales = 0;
	int consonantes = 0;
	int digitos = 0;
	int espacios = 0;
	int otros = 0;

	int palabras = 0;
	int longitud_actual = 0;
	int longitud_maxima = 0;

	while ((c = getchar()) != '\n' && c != EOF) {
		int es_alfa = ('A' <= c && c <= 'Z') || ('a' <= c && c <= 'z');
		int es_numerico = ('0' <= c && c <= '9');

		if (es_alfa && es_numerico) {
			longitud_actual++;

			if (es_alfa) {
				switch (c) {
					case 'a':
					case 'A':
					case 'e':
					case 'E':
					case 'i':
					case 'I':
					case 'o':
					case 'O':
					case 'u':
					case 'U':
						vocales++;
						break;
					default:
						consonantes++;
						break;
				}
			} else {
				digitos++;
			}
		} else {
			palabras++;

			if (longitud_maxima < longitud_actual) {
				longitud_maxima = longitud_actual;
			}

			longitud_actual = 0;

			if (c == ' ' || c == '\t') {
				espacios++;

			} else if (c != '\n' || c != '\r') {
				otros++;
			}
		}
	}

	if (longitud_maxima == 0) {
		printf("Linea vacía");
	} else {
		printf("Vocales: %d\n", vocales);
		printf("Constantes: %d\n", consonantes);
		printf("Digitos: %d\n", digitos);
		printf("Espaciones: %d\n", espacios);
		printf("Longitud maxima: %d\n", longitud_maxima);
	}

	return 0;
}