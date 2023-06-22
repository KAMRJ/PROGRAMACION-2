#include <stdio.h>
#include <math.h>

float calcularDistancias(float x1, float y1, float z1, float x2, float y2, float z2);
float calcularPerimetro(float puntos[4][3], float *a, float *b, float *c, float *d, float *e, float *f);
float calcularArea(float a, float b, float c);
float calcularVolumen (float puntos [4][3]);

int main(int argc, char *argv[])
{
    float puntos[4][3] = {{0, 0, 0}, {3, 0, 0}, {0, 0, 3}, {1, 7, 1}};
    float per, a, b, c, d, e, f, vol;

    float perimetro = calcularPerimetro(puntos, &a, &b, &c, &d, &e, &f);
    float area = calcularArea(a, b, c);
    float area1 = calcularArea(b, d, e);
    float area2 = calcularArea(a, e, f);
    float area3 = calcularArea(e, f, a);

    vol = calcularVolumen (puntos);

    float areaSuperficial = area + area1 + area2 + area3;

    printf("El perimetro es: %f\n", perimetro);
    printf("El area superficial es: %f\n", areaSuperficial);
    printf ("El volumen es: %f", vol);
    return 0;
}

float calcularDistancias(float x1, float y1, float z1, float x2, float y2, float z2)
{
    float distancia = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2) + pow(z1 - z2, 2));
    return distancia;
}

float calcularPerimetro(float puntos[4][3], float *a, float *b, float *c, float *d, float *e, float *f)
{
    *a = calcularDistancias(puntos[0][0], puntos[0][1], puntos[0][2], puntos[1][0], puntos[1][1], puntos[1][2]);
    *b = calcularDistancias(puntos[0][0], puntos[0][1], puntos[0][2], puntos[2][0], puntos[2][1], puntos[2][2]);
    *c = calcularDistancias(puntos[1][0], puntos[1][1], puntos[1][2], puntos[2][0], puntos[2][1], puntos[2][2]);

    *d = calcularDistancias(puntos[2][0], puntos[2][1], puntos[2][2], puntos[3][0], puntos[3][1], puntos[3][2]);
    *e = calcularDistancias(puntos[0][0], puntos[0][1], puntos[0][2], puntos[3][0], puntos[3][1], puntos[3][2]);
    *f = calcularDistancias(puntos[1][0], puntos[1][1], puntos[1][2], puntos[3][0], puntos[3][1], puntos[3][2]);

    float per = *a + *b + *c + *d + *e + *f;
    return per;
}

float calcularArea(float a, float b, float c)
{
    float semiperimetro = (a + b + c) / 2;
    float area = sqrt(semiperimetro * (semiperimetro - a) * (semiperimetro - b) * (semiperimetro - c));
    return area;
}

float calcularVolumen (float puntos [4][3])
{
    float a, b, c, d, e, f;
    float perimetro = calcularPerimetro(puntos, &a, &b, &c, &d, &e, &f);
    float vol = (1.0/6.0) * fabs(a * d *calcularArea(b, c, e));
    return vol;

}
