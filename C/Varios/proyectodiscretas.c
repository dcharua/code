/*
	"Proyecto Final de Matematicas Discretas"
	Integrantes:
		-Daniel Charua García	A01017419
		-Mauricio Rico Zavala 	A01370874
		-Jose García Mendizabal A01023616
*/

#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Inicia declaracion de funciones

void ejecutarPrograma(void);
int leerCardinalidad(void);
void leerElemento(int cardinalidad, char *conjunto);
void imprimirArreglo(int cardinalidad, char *conjunto);
void juntarDosArreglos(int cardinalidadUno, int cardinalidadDos, char *conjuntoUno, char *conjuntoDos, char *conjuntoTres);
int eliminarRepetidos(int cardinalidad, char *conjunto);
int eliminarNoRepetidos(int cardinalidad, char *conjunto, char *conjuntoFinal);
void eliminarRepetidosSinPiedad(int cardinalidad, char *conjunto);
void unionOp(int cardinalidadA, int cardinalidadB, int cardinalidadU, char *conjuntoA, char *conjuntoB, char *conjuntoU);
void interseccionOp(int cardinalidadA, int cardinalidadB, int cardinalidadU, char *conjuntoA, char *conjuntoB, char *conjuntoU);
void diferenciaOp(int cardinalidadA, int cardinalidadB, int cardinalidadU, char *conjuntoA, char *conjuntoB, char *conjuntoU);
void complementoOp(int cardinalidadA, int cardinalidadB, int cardinalidadU, char *conjuntoA, char *conjuntoB, char *conjuntoU);

char *convertirBinario(int decimal, int cardinalidad);
void imprimirBits(char *bits, int cardinalidad, char *conjunto);
char **hacerPotencia(char *conjunto);

void potenciaOp(int cardinalidadA, int cardinalidadB, int cardinalidadU, char *conjuntoA, char *conjuntoB, char *conjuntoU);

//Termina declaracion de funciones

int main() {
	printf("\n\t==========================================================");
	printf("\n\t|   ¡Bienvenido al programa de operacion de conjuntos!   |");
	printf("\n\t==========================================================");
	char menu = '0';
	while ( menu != '2' ) {
		printf("\n");
		printf("\n\t-------------------------------------");
		printf("\n\t|           Menu Principal          |");
		printf("\n\t-------------------------------------");
		printf("\n\t|  1)  Introducir conjuntos         |");
		printf("\n\t|  2)  Salir del programa           |");
		printf("\n\t-------------------------------------");
		printf("\n\tEscoja la opcion: ");
		scanf(" %c", &menu);
		switch (menu) {
			case '1':
				ejecutarPrograma();
				break;
			case '2':
				printf("\t**Termino la ejecución del programa de conjuntos.**");
				printf("\n");
				printf("\n");
				break;
			case '\n':
			case '\t':
			case ' ':
			default:
				printf("\t**Esta opcion no es valida. Intentelo de nuevo.**");
				printf("\n");
				printf("\n");
				break;
		}
	}
	return 0;
}

// Inicia desarrollo de funciones

void ejecutarPrograma(void) {
	printf("\n\n");
	printf("\n\t----------------");
	printf("\n\t|  Conjunto A  |");
	printf("\n\t----------------");
	printf("\n\tIntroduzca la cardinalidad de A: ");
	int cardinalidadA;
	cardinalidadA = leerCardinalidad();
	char conjuntoA[cardinalidadA];
	leerElemento(cardinalidadA, conjuntoA);
	printf("\n\t∴ El conjunto A tiene los elementos: {");
	imprimirArreglo(cardinalidadA, conjuntoA);

	printf("\n\n");
	printf("\n\t----------------");
	printf("\n\t|  Conjunto B  |");
	printf("\n\t----------------");
	printf("\n\tIntroduzca la cardinalidad de B: ");
	int cardinalidadB;
	cardinalidadB = leerCardinalidad();
	char conjuntoB[cardinalidadB];
	leerElemento(cardinalidadB, conjuntoB);
	printf("\n\t∴ El conjunto B tiene los elementos: {");
	imprimirArreglo(cardinalidadB, conjuntoB);

	printf("\n\n");
	printf("\n\t----------------");
	printf("\n\t|   Universo   |");
	printf("\n\t----------------");
	int cardinalidadU;
	cardinalidadU = cardinalidadA + cardinalidadB;
	char conjuntoU[cardinalidadU];
	juntarDosArreglos(cardinalidadA, cardinalidadB, conjuntoA, conjuntoB, conjuntoU);
	cardinalidadU = eliminarRepetidos(cardinalidadU, conjuntoU);
	printf("\n\tEl Universo tiene los elementos de los conjuntos A y B: {");
	imprimirArreglo(cardinalidadU, conjuntoU);
	printf("\n");
	printf("\n\t¿Desea agregar mas elementos al Universo aparte de tener a los de A y B?");
	char menu = '0';
	while ( menu != '2' ) {
		printf("\n\t-------------------------");
		printf("\n\t|  1)  Si   |  2)  No   |");
		printf("\n\t-------------------------");
		printf("\n\tEscoja la opcion: ");
		scanf(" %c", &menu);
		switch (menu) {
			case '1':
				{
				printf("\n\tIntroduzca la cantidad de elementos que desea agregar: ");
				int cardinalidadUAB;
				cardinalidadUAB = leerCardinalidad();
				char conjuntoUAB[cardinalidadUAB];
				leerElemento(cardinalidadUAB, conjuntoUAB);
				int cardinalidadUU;
				cardinalidadUU = cardinalidadU + cardinalidadUAB;
				char conjuntoUU[cardinalidadUU];
				juntarDosArreglos(cardinalidadU, cardinalidadUAB, conjuntoU, conjuntoUAB, conjuntoUU);
				cardinalidadUU = eliminarRepetidos(cardinalidadUU, conjuntoUU);
				cardinalidadU = cardinalidadUU;
				strncpy(conjuntoU, conjuntoUU, cardinalidadUU);
				menu = '2';
				}
				break;
			case '\n':
			case '\t':
			case ' ':
			default:
				break;
		}
	}
	printf("\n");
	printf("\n\t∴ El Universo tiene los elementos: {");
	imprimirArreglo(cardinalidadU, conjuntoU);//But if the user didnt want to add more elements in the Universe it doesnt need to change

	char menuOp = '0';
	while ( menuOp != '6' ) {
		printf("\n\n\n");
		printf("\n\t-------------------------------------");
		printf("\n\t|        Menu de operaciones        |");
		printf("\n\t-------------------------------------");
		printf("\n\t|  1)  Unión                        |");
		printf("\n\t|  2)  Intersección                 |");
		printf("\n\t|  3)  Diferencia                   |");
		printf("\n\t|  4)  Complemento                  |");
		printf("\n\t|  5)  Potencia                     |");
		printf("\n\t|  6)  Salir al menu principal      |");
		printf("\n\t-------------------------------------");
		printf("\n\tEscoja la opcion: ");
		scanf(" %c", &menuOp);
		switch (menuOp) {
			case '1':
				printf("\n\n");
				printf("\n\t-----------");
				printf("\n\t|  Unión  |");
				printf("\n\t-----------");
				unionOp(cardinalidadA, cardinalidadB, cardinalidadU, conjuntoA, conjuntoB, conjuntoU);
				break;
			case '2':
				printf("\n\n");
				printf("\n\t------------------");
				printf("\n\t|  Intersección  |");
				printf("\n\t------------------");
				interseccionOp(cardinalidadA, cardinalidadB, cardinalidadU, conjuntoA, conjuntoB, conjuntoU);
				break;
			case '3':
				printf("\n\n");
				printf("\n\t----------------");
				printf("\n\t|  Diferencia  |");
				printf("\n\t----------------");
				diferenciaOp(cardinalidadA, cardinalidadB, cardinalidadU, conjuntoA, conjuntoB, conjuntoU);
				break;
			case '4':
				printf("\n\n");
				printf("\n\t-----------------");
				printf("\n\t|  Complemento  |");
				printf("\n\t-----------------");
				complementoOp(cardinalidadA, cardinalidadB, cardinalidadU, conjuntoA, conjuntoB, conjuntoU);
				break;
			case '5':
				printf("\n\n");
				printf("\n\t--------------");
				printf("\n\t|  Potencia  |");
				printf("\n\t--------------");
				//potenciaOp(cardinalidadA, cardinalidadB, cardinalidadU, conjuntoA, conjuntoB, conjuntoU);
				break;
			case '\n':
			case '\t':
			case ' ':
			default:
				break;
		}
	}
}// Termina la funcion para ejecutar el programa

int leerCardinalidad(void) {
	int cardinalidad;
	scanf("%d", &cardinalidad);
	return cardinalidad;
}// Termina la funcion para leer la cardinalidad

void leerElemento(int cardinalidad, char *conjunto) {
	printf("\n\tIntroduzca los elementos:\n");
	int i;
	for (i = 0; i < cardinalidad; i++) {
		printf("\t\tElemento %d: ", i + 1);
		scanf(" %c", &conjunto[i]);
	}
}// Termina la funcion para leer los elementos

void imprimirArreglo(int cardinalidad, char *conjunto) {
	if (cardinalidad == 0) {
		printf(" ø }");
	} else {
		int i;
		for (i = 0; i < cardinalidad; i++) {
			if (i < (cardinalidad - 1)) {
				if (conjunto[i] == '\0') {
					continue;
				}
				printf("%c, ", conjunto[i]);
			} else {
				printf("%c}", conjunto[i]);
			}
		}
	}
}// Termina la funcion para imprimir el conjunto

void juntarDosArreglos(int cardinalidadUno, int cardinalidadDos, char *conjuntoUno, char *conjuntoDos, char *conjuntoTres) {
	int i;
	int j;
	int k;

	i = 0;
	j = 0;
	k = 0;

	while (i < cardinalidadUno && j < cardinalidadDos) {
		if (conjuntoUno[i] <= conjuntoDos[j]) {
			conjuntoTres[k] = conjuntoUno[i];
			i++;
			k++;
		} else {
			conjuntoTres[k] = conjuntoDos[j];
			k++;
			j++;
		}
	}

	while (i < cardinalidadUno) {
		conjuntoTres[k] = conjuntoUno[i];
		i++;
		k++;
	}

	while (j < cardinalidadDos) {
		conjuntoTres[k] = conjuntoDos[j];
		k++;
		j++;
	}
}// Termina la funcion de juntar dos arreglos

int eliminarRepetidos(int cardinalidad, char *conjunto) {
	int i;
	int j;
	int k;

	for (i = 0; i < cardinalidad; i++) {
		for (j = i + 1; j < cardinalidad;) {
			if (conjunto[j] == conjunto[i]) {
				for (k = j; k < cardinalidad; k++) {
					conjunto[k] = conjunto[k + 1];
				}
				cardinalidad--;
			} else {
				j++;
			}
		}
	}
	return cardinalidad;
}// Termina la funcion para eleminar elementos repetidos en un arreglo

int eliminarNoRepetidos(int cardinalidad, char *conjunto, char *conjuntoFinal) {
	int i;
	int j;
	int cardinalidadFinal = 0;

	for (i = 0; i < cardinalidad; i++) {
		for (j = 0; j < cardinalidad; j++) {
			if (conjunto[i] == conjunto[j] && i != j) {
				conjuntoFinal[cardinalidadFinal] = conjunto[i];
				cardinalidadFinal++;
			}
		}
	}

	return cardinalidadFinal;
}// Termina la funcion para eleminar elementos no repetidos en un arreglo

void eliminarRepetidosSinPiedad(int cardinalidad, char *conjunto) {
	int i;
	int j;
	int cardinalidadFinal = 0;

	for (i = 0; i < cardinalidad; i++) {
		for (j = 0; j < cardinalidad; j++) {
			if (conjunto[i] == conjunto[j] && i != j) {
				conjunto[i] -= conjunto[i];
				conjunto[j] -= conjunto[j];
			}
		}
	}
}// Termina la funcion para eleminar elementos no repetidos en un arreglo

void unionOp(int cardinalidadA, int cardinalidadB, int cardinalidadU, char *conjuntoA, char *conjuntoB, char *conjuntoU) {
	char menu = '0';
	while ( menu != '3' ) {
		printf("\n\t-------------------------------------");
		printf("\n\t|         Menu de conjuntos         |");
		printf("\n\t-------------------------------------");
		printf("\n\t|  1)  A ∪ B                        |");
		printf("\n\t|  2)  A/B ∪ U                      |");
		printf("\n\t|  3)  Salir al Menu de operaciones |");
		printf("\n\t-------------------------------------");
		printf("\n\tEscoja la opcion: ");
		scanf(" %c", &menu);
		switch (menu) {
			case '1':
				printf("\n");
				printf("\n\t-------------------");
				printf("\n\t|      A ∪ B      |");
				printf("\n\t-------------------");
				{
					int cardinalidadResultado;
					cardinalidadResultado = cardinalidadA + cardinalidadB;
					char conjuntoResultado[cardinalidadResultado];
					juntarDosArreglos(cardinalidadA, cardinalidadB, conjuntoA, conjuntoB, conjuntoResultado);
					cardinalidadResultado = eliminarRepetidos(cardinalidadResultado, conjuntoResultado);
					printf("\n\t(A ∪ B) = {");
					imprimirArreglo(cardinalidadResultado, conjuntoResultado);
				}
				printf("\n\n");
				break;
			case '2':
				printf("\n");
				printf("\n\t-------------------");
				printf("\n\t|      A/B ∪ U      |");
				printf("\n\t-------------------");
				{
					int cardinalidadResultado;
					cardinalidadResultado = cardinalidadA + cardinalidadU;
					char conjuntoResultado[cardinalidadResultado];
					juntarDosArreglos(cardinalidadA, cardinalidadU, conjuntoA, conjuntoU, conjuntoResultado);
					cardinalidadResultado = eliminarRepetidos(cardinalidadResultado, conjuntoResultado);
					printf("\n\t(A ∪ U) = {");
					imprimirArreglo(cardinalidadResultado, conjuntoResultado);
				}
				printf("\n\n");
				break;
			case '\n':
			case '\t':
			case ' ':
			default:
				break;
		}
	}
}// Termina la funcion para ejecutar la operacion union

void interseccionOp(int cardinalidadA, int cardinalidadB, int cardinalidadU, char *conjuntoA, char *conjuntoB, char *conjuntoU) {
	char menu = '0';
	while ( menu != '4' ) {
		printf("\n\t-------------------------------------");
		printf("\n\t|         Menu de conjuntos         |");
		printf("\n\t-------------------------------------");
		printf("\n\t|  1)  A ∩ B                        |");
		printf("\n\t|  2)  A ∩ U                        |");
		printf("\n\t|  3)  B ∩ U                        |");
		printf("\n\t|  4)  Salir al Menu de operaciones |");
		printf("\n\t-------------------------------------");
		printf("\n\tEscoja la opcion: ");
		scanf(" %c", &menu);
		switch (menu) {
			case '1':
				printf("\n");
				printf("\n\t-------------------");
				printf("\n\t|      A ∩ B      |");
				printf("\n\t-------------------");
				{
					int cardinalidadResultado;
					cardinalidadResultado = cardinalidadA + cardinalidadB;
					char conjuntoResultado[cardinalidadResultado];
					juntarDosArreglos(cardinalidadA, cardinalidadB, conjuntoA, conjuntoB, conjuntoResultado);
					char conjuntoFinal[cardinalidadResultado];
					cardinalidadResultado = eliminarNoRepetidos(cardinalidadResultado, conjuntoResultado, conjuntoFinal);
					cardinalidadResultado = eliminarRepetidos(cardinalidadResultado, conjuntoFinal);
					printf("\n\t(A ∩ B) = {");
					imprimirArreglo(cardinalidadResultado, conjuntoFinal);
				}
				printf("\n\n");
				break;
			case '2':
				printf("\n");
				printf("\n\t-------------------");
				printf("\n\t|      A ∩ U      |");
				printf("\n\t-------------------");
				{
					int cardinalidadResultado;
					cardinalidadResultado = cardinalidadA + cardinalidadU;
					char conjuntoResultado[cardinalidadResultado];
					juntarDosArreglos(cardinalidadA, cardinalidadU, conjuntoA, conjuntoU, conjuntoResultado);
					char conjuntoFinal[cardinalidadResultado];
					cardinalidadResultado = eliminarNoRepetidos(cardinalidadResultado, conjuntoResultado, conjuntoFinal);
					cardinalidadResultado = eliminarRepetidos(cardinalidadResultado, conjuntoFinal);
					printf("\n\t(A ∩ U) = {");
					imprimirArreglo(cardinalidadResultado, conjuntoFinal);
				}
				printf("\n\n");
				break;
			case '3':
				printf("\n");
				printf("\n\t-------------------");
				printf("\n\t|      B ∩ U      |");
				printf("\n\t-------------------");
				{
					int cardinalidadResultado;
					cardinalidadResultado = cardinalidadB + cardinalidadU;
					char conjuntoResultado[cardinalidadResultado];
					juntarDosArreglos(cardinalidadB, cardinalidadU, conjuntoB, conjuntoU, conjuntoResultado);
					char conjuntoFinal[cardinalidadResultado];
					cardinalidadResultado = eliminarNoRepetidos(cardinalidadResultado, conjuntoResultado, conjuntoFinal);
					cardinalidadResultado = eliminarRepetidos(cardinalidadResultado, conjuntoFinal);
					printf("\n\t(B ∩ U) = {");
					imprimirArreglo(cardinalidadResultado, conjuntoFinal);
				}
				printf("\n\n");
				break;
			case '\n':
			case '\t':
			case ' ':
			default:
				break;
		}
	}
}// Termina la funcion para ejecutar la operacion interseccion

void diferenciaOp(int cardinalidadA, int cardinalidadB, int cardinalidadU, char *conjuntoA, char *conjuntoB, char *conjuntoU) {
	char menu = '0';
	while ( menu != '3' ) {
		printf("\n\t-------------------------------------");
		printf("\n\t|         Menu de conjuntos         |");
		printf("\n\t-------------------------------------");
		printf("\n\t|  1)  A - B                        |");
		printf("\n\t|  2)  B - A                        |");
		printf("\n\t|  3)  Salir al Menu de operaciones |");
		printf("\n\t-------------------------------------");
		printf("\n\tEscoja la opcion: ");
		scanf(" %c", &menu);
		switch (menu) {
			case '1':
				printf("\n");
				printf("\n\t-------------------");
				printf("\n\t|      A - B      |");
				printf("\n\t-------------------");
				{
					int cardinalidadTemporal;
					cardinalidadTemporal = cardinalidadA + cardinalidadB;
					char conjuntoTemporal[cardinalidadTemporal];
					juntarDosArreglos(cardinalidadA, cardinalidadB, conjuntoA, conjuntoB, conjuntoTemporal);
					char conjuntoInterseccion[cardinalidadTemporal];
					cardinalidadTemporal = eliminarNoRepetidos(cardinalidadTemporal, conjuntoTemporal, conjuntoInterseccion);
					cardinalidadTemporal = eliminarRepetidos(cardinalidadTemporal, conjuntoInterseccion);
					int cardinalidadTemporalDos;
					cardinalidadTemporalDos = cardinalidadA + cardinalidadTemporal;
					char conjuntoTemporalDos[cardinalidadTemporalDos];
					juntarDosArreglos(cardinalidadA, cardinalidadTemporal, conjuntoA, conjuntoInterseccion, conjuntoTemporalDos);
					int cardinalidadResultado = cardinalidadTemporalDos;
					char conjuntoResultado[cardinalidadResultado];
					eliminarRepetidosSinPiedad(cardinalidadTemporalDos, conjuntoTemporalDos);
					cardinalidadTemporalDos = eliminarRepetidos(cardinalidadTemporalDos, conjuntoTemporalDos);
					printf("\n\t(A - B) = {");
					imprimirArreglo(cardinalidadTemporalDos, conjuntoTemporalDos);
				}
				printf("\n\n");
				break;
			case '2':
				printf("\n");
				printf("\n\t-------------------");
				printf("\n\t|      B - A      |");
				printf("\n\t-------------------");
				{
					int cardinalidadTemporal;
					cardinalidadTemporal = cardinalidadB + cardinalidadA;
					char conjuntoTemporal[cardinalidadTemporal];
					juntarDosArreglos(cardinalidadB, cardinalidadA, conjuntoB, conjuntoA, conjuntoTemporal);
					char conjuntoInterseccion[cardinalidadTemporal];
					cardinalidadTemporal = eliminarNoRepetidos(cardinalidadTemporal, conjuntoTemporal, conjuntoInterseccion);
					cardinalidadTemporal = eliminarRepetidos(cardinalidadTemporal, conjuntoInterseccion);
					int cardinalidadTemporalDos;
					cardinalidadTemporalDos = cardinalidadB + cardinalidadTemporal;
					char conjuntoTemporalDos[cardinalidadTemporalDos];
					juntarDosArreglos(cardinalidadB, cardinalidadTemporal, conjuntoB, conjuntoInterseccion, conjuntoTemporalDos);
					int cardinalidadResultado = cardinalidadTemporalDos;
					char conjuntoResultado[cardinalidadResultado];
					eliminarRepetidosSinPiedad(cardinalidadTemporalDos, conjuntoTemporalDos);
					cardinalidadTemporalDos = eliminarRepetidos(cardinalidadTemporalDos, conjuntoTemporalDos);
					printf("\n\t(B - A) = {");
					imprimirArreglo(cardinalidadTemporalDos, conjuntoTemporalDos);
				}
				printf("\n\n");
				break;
			case '\n':
			case '\t':
			case ' ':
			default:
				break;
		}
	}
}// Termina la funcion para ejecutar la operacion diferencia

void complementoOp(int cardinalidadA, int cardinalidadB, int cardinalidadU, char *conjuntoA, char *conjuntoB, char *conjuntoU) {
	char menu = '0';
	while ( menu != '3' ) {
		printf("\n\t-------------------------------------");
		printf("\n\t|         Menu de conjuntos         |");
		printf("\n\t-------------------------------------");
		printf("\n\t|  1)  Complemento de A             |");
		printf("\n\t|  2)  Complemento de B             |");
		printf("\n\t|  3)  Salir al Menu de operaciones |");
		printf("\n\t-------------------------------------");
		printf("\n\tEscoja la opcion: ");
		scanf(" %c", &menu);
		switch (menu) {
			case '1':
				printf("\n");
				printf("\n\t-------------------");
				printf("\n\t|  Complemento A  |");
				printf("\n\t-------------------");
				{
					int cardinalidadTemporal;
					cardinalidadTemporal = cardinalidadU + cardinalidadA;
					char conjuntoTemporal[cardinalidadTemporal];
					juntarDosArreglos(cardinalidadU, cardinalidadA, conjuntoU, conjuntoA, conjuntoTemporal);
					cardinalidadTemporal = eliminarRepetidos(cardinalidadTemporal, conjuntoTemporal);
					int cardinalidadResultado;
					cardinalidadResultado = cardinalidadU + cardinalidadA;
					char conjuntoResultado[cardinalidadResultado];
					juntarDosArreglos(cardinalidadTemporal, cardinalidadA, conjuntoTemporal, conjuntoA, conjuntoResultado);
					eliminarRepetidosSinPiedad(cardinalidadResultado, conjuntoResultado);
					printf("\n\t(Complemento A) = {");
					imprimirArreglo(cardinalidadResultado, conjuntoResultado);
				}
				printf("\n\n");
				break;
			case '2':
				printf("\n");
				printf("\n\t-------------------");
				printf("\n\t|  Complemento B  |");
				printf("\n\t-------------------");
				{
					int cardinalidadTemporal;
					cardinalidadTemporal = cardinalidadU + cardinalidadB;
					char conjuntoTemporal[cardinalidadTemporal];
					juntarDosArreglos(cardinalidadU, cardinalidadB, conjuntoU, conjuntoB, conjuntoTemporal);
					cardinalidadTemporal = eliminarRepetidos(cardinalidadTemporal, conjuntoTemporal);
					int cardinalidadResultado;
					cardinalidadResultado = cardinalidadU + cardinalidadB;
					char conjuntoResultado[cardinalidadResultado];
					juntarDosArreglos(cardinalidadTemporal, cardinalidadB, conjuntoTemporal, conjuntoB, conjuntoResultado);
					eliminarRepetidosSinPiedad(cardinalidadResultado, conjuntoResultado);
					printf("\n\t(Complemento B) = {");
					imprimirArreglo(cardinalidadResultado, conjuntoResultado);
				}	
				printf("\n\n");
				break;
			case '\n':
			case '\t':
			case ' ':
			default:
				break;
		}
	}
}// Termina la funcion para ejecutar la operacion complemento


char *convertirBinario(int decimal, int cardinalidad) {
    int i = cardinalidad - 1;
    char bit;
    char *bits = malloc(sizeof(char)*cardinalidad);

    while(decimal > 0) {
        bit = decimal % 2;
        decimal /= 2;
        bits[i] = bit;
        i--;
    }

    return bits;
}

void imprimirBits(char *bits, int cardinalidad, char *conjunto) {
    int i;

    printf("\t{ ");
    for(i = 0; i < cardinalidad; i++) {
        if(bits[i]) {
            printf("%c", conjunto[i]);
        }
    }
    printf(" }\n");
}


/*char **hacerPotencia(char *conjunto) {
    int i;
    char *bits = NULL;
    char **conjuntoPotencia = NULL;
    int cardinalidad = strlen(conjunto);
    // get the number of elements in the power set
    int combPos = pow(2, cardinalidad);
    // Allocate the bigger set
    conjuntoPotencia = malloc(sizeof(char*)* combPos);

    for(i = combPos; i > 0; i--) {
        // allocate mmory for the subsets
        conjuntoPotencia[i] = malloc(sizeof(char)* cardinalidad);
        bits = convertirBinario(i, cardinalidad);
        imprimirBits(bits, cardinalidad, conjunto);
    }
    return conjuntoPotencia;
}


void potenciaOp(int cardinalidadA, int cardinalidadB, int cardinalidadU, char *conjuntoA, char *conjuntoB, char *conjuntoU) {
	char menu = '0';
	while ( menu != '4' ) {
		printf("\n\t-------------------------------------");
		printf("\n\t|         Menu de conjuntos         |");
		printf("\n\t-------------------------------------");
		printf("\n\t|  1)  Potencia A                   |");
		printf("\n\t|  2)  Potencia B                   |");
		printf("\n\t|  3)  Potencia Universo            |");
		printf("\n\t|  4)  Salir al Menu de operaciones |");
		printf("\n\t-------------------------------------");
		printf("\n\tEscoja la opcion: ");
		scanf(" %c", &menu);
		switch (menu) {
			case '1':
				printf("\n");
				printf("\n\t-------------------");
				printf("\n\t|    Potencia A   |");
				printf("\n\t-------------------");
				printf("\n\n");
				{
					char *bits = NULL;
    				int i;

    				int combPos = pow(2, cardinalidadA);

    				char **conjuntoPotencia = hacerPotencia(conjuntoA);

    				free(bits);
    				for(i = 0; i < combPos; i++) {
        				free(conjuntoPotencia[i]);
    				}

    				free(conjuntoPotencia);
				}
				break;
			case '2':
				printf("\n");
				printf("\n\t-------------------");
				printf("\n\t|    Potencia B   |");
				printf("\n\t-------------------");
				printf("\n\n");
				{
					char *bits = NULL;
    				int i;

    				int combPos = pow(2, cardinalidadB);

    				char **conjuntoPotencia = hacerPotencia(conjuntoB);

    				free(bits);
    				for(i = 0; i < combPos; i++) {
        				free(conjuntoPotencia[i]);
    				}

    				free(conjuntoPotencia);
				}
				break;
			case '3':
				printf("\n");
				printf("\n\t-------------------");
				printf("\n\t|Potencia Universo|");
				printf("\n\t-------------------");
				printf("\n\n");
				{
					char *bits = NULL;
    				int i;

    				int combPos = pow(2, cardinalidadU);

    				char **conjuntoPotencia = hacerPotencia(conjuntoU);

    				free(bits);
    				for(i = 0; i < combPos; i++) {
        				free(conjuntoPotencia[i]);
    				}

    				free(conjuntoPotencia);
				}
				break;
			case '\n':
			case '\t':
			case ' ':
			default:
				break;
		}
	}
}// Termina la funcion para ejecutar la operacion potencia

//Termina desarrollo de funciones*/