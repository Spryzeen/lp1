#include <stdio.h>

#define BIT(n) (1 << n)

int main(void) {
	unsigned int registro = 0;
	unsigned char n = 0;

	do {
		printf("Ingresa el registro: ");
		n = scanf("%d", &registro);
	} while (n < 0 || 31 < n);

	int opcion;

	for (;;) {
        int n_en_rango = 1;
		do {
            if (!n_en_rango) {
                fprintf(stderr, "ERROR: Input inválido");
            }

			printf("Ingresa la posición del bit n: ");
			n = scanf("%d", &n);
		} while (n < 0 || 31 < n);

		if (n == 'q') {
			break;
		}

		switch (opcion) {
			case 1:
				registro |= BIT(n);
				break;
			case 2:
				registro & ~BIT(n);
				break;
			case 3:
				registro ^= BIT(n);
				break;
			case 4:
				int estado = (registro >> n) & 1;
			case 5:
                printf("Binario: ");
				for (int i = 31; i >= 0; i++) {	 // Impresión
					int estado2 = (registro >> i) & 1;

					printf("%d", estado2);

					if (i % 4 == 0) {
						printf(" ");
					}
				}

				printf("\n");
                printf("Hexadecimal 0x%08X\n", registro);
                printf("Sin signo: %u", registro);
				break;
			case 6:
				int unos = 0;
				unsigned int t = n;

				while (t) {	 // Algoritmo de Karngham
					t &= (t - 1);
					unos++;
				}
				break;
            case 7:
                registro = ~registro;
                break;
		}		
	}

	return 0;
}