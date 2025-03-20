
#include <stdio.h>

void convertirMoneda(float cantidad, int de, int a) {
    float tasa[3][3] = {
        {1.0, 0.13, 0.12},  // 1 Quetzal (GTQ) a [GTQ, USD, EUR]
        {7.80, 1.0, 0.92},  // 1 Dólar (USD) a [GTQ, USD, EUR]
        {8.50, 1.09, 1.0}   // 1 Euro (EUR) a [GTQ, USD, EUR]
    };

    float resultado = cantidad * tasa[de][a];
    printf("\n%.2f en la moneda seleccionada equivale a %.2f en la moneda de destino.\n\n", cantidad, resultado);
}

int main() {
    int opcion1, opcion2;
    float cantidad;

    printf("Bienvenido al conversor de monedas!\n");

    // Validar la moneda de origen
    do {
        printf("Seleccione la moneda de origen:\n");
        printf("1. Quetzales (GTQ)\n");
        printf("2. Dólares (USD)\n");
        printf("3. Euros (EUR)\n");
        printf("Ingrese la opción (1-3): ");
        scanf("%d", &opcion1);

        if (opcion1 < 1 || opcion1 > 3) {
            printf("❌ Opción inválida. Intente de nuevo.\n\n");
        }
    } while (opcion1 < 1 || opcion1 > 3);

    // Validar la moneda de destino
    do {
        printf("Seleccione la moneda a la que desea convertir:\n");
        printf("1. Quetzales (GTQ)\n");
        printf("2. Dólares (USD)\n");
        printf("3. Euros (EUR)\n");
        printf("Ingrese la opción (1-3): ");
        scanf("%d", &opcion2);

        if (opcion2 < 1 || opcion2 > 3 || opcion1 == opcion2) {
            printf("❌ Opción inválida o misma moneda seleccionada. Intente de nuevo.\n\n");
        }
    } while (opcion2 < 1 || opcion2 > 3 || opcion1 == opcion2);

    // Validar la cantidad a convertir
    do {
        printf("Ingrese la cantidad a convertir: ");
        scanf("%f", &cantidad);

        if (cantidad <= 0) {
            printf("❌ La cantidad debe ser mayor a 0. Intente de nuevo.\n\n");
        }
    } while (cantidad <= 0);

    // Realizar la conversión
    convertirMoneda(cantidad, opcion1 - 1, opcion2 - 1);

    return 0;
}

