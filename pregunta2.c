#include <stdio.h>
#include <math.h>
#define INVALIDO 0
#define NO_FORMAN 1
#define EQUILATERO 2
#define ISOSCELES 3
#define ESCALENO 4

int main(void)
{
    int lado_a = 0, lado_b = 0, lado_c = 0;
    int tipo = 0;
    printf("Ingrese los tres lados del triangulo:");
    if (scanf("%d %d %d", &lado_a, &lado_b, &lado_c) != 3) {
        fprintf(stderr, "No se pudieron leer 3 enteros validos.\n");
        return 1;
    }
    if (!(lado_a > 0 && lado_b > 0 && lado_c > 0)) {
        tipo = INVALIDO;
    } else if (!(lado_a + lado_b > lado_c &&
                lado_a + lado_c > lado_b &&
                lado_b + lado_c > lado_a)) {
        tipo = NO_FORMAN;
    } else if (lado_a == lado_b && lado_b == lado_c) {
        tipo = EQUILATERO;
    } else if (lado_a == lado_b || lado_a == lado_c || lado_b == lado_c) {
        tipo = ISOSCELES;
    } else {
        tipo = ESCALENO;
    }
    int x = lado_a, y = lado_b, z = lado_c;
    if (x > y) { int t = x; x = y; y = t; }
    if (y > z) { int t = y; y = z; z = t; }
    if (x > y) { int t = x; x = y; y = t; }
    long long hip_cuadrado = (long long)z * z;
    long long cat_cuadrados = (long long)x * x + (long long)y * y;
    int es_rectangulo = (hip_cuadrado == cat_cuadrados) ? 1 : 0;
    double area = 0.0;
    if (tipo == ESCALENO) {
        double s = (x + y + z) / 2.0;
        area = sqrt(s * (s - x) * (s - y) * (s - z));
    }
    printf("Lados: %d, %d, %d\n", x, y, z);
    switch (tipo) {
        case INVALIDO:
            printf("Tipo: Invalido\n");
            printf("Rectangulo : No\n");
            break;
        case NO_FORMAN:
            printf("Tipo: No forman triangulo\n");
            printf("Rectangulo : No\n");
            break;
        case EQUILATERO:
            printf("Tipo: Equilatero\n");
            printf("Rectangulo : %s\n", es_rectangulo ? "Si" : "No");
            break;
        case ISOSCELES:
            printf("Tipo: Isosceles\n");
            printf("Rectangulo : %s\n", es_rectangulo ? "Si" : "No");
            break;
        case ESCALENO:
            printf("Tipo: Escaleno\n");
            printf("Rectangulo : %s\n", es_rectangulo ? "Si" : "No");
            printf("Area: %.3f\n", area);
            break;
    }
    return 0;
}