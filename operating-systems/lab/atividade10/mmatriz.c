#include <sys/timeb.h>
#include <time.h>
#include <stdio.h>
#include <pthread.h>

void multiplica (int t, int mA[][t], int mB[][t]) {
	printf("Function multiplica - tamanho das matrizes %ix%i\n",t,t);
	int c, d, k, sum = 0;
	int mAxB[t][t];
	struct timeb tp;
	ftime(&tp);
	char timeString[80];
	strftime(timeString, sizeof(timeString), "%H:%M:%S", localtime(&tp.time));
	printf("%s:%d\n", timeString, tp.millitm);

	for (c = 0; c < t; c++) {
		for (d = 0; d < t; d++) {
			for (k = 0; k < t; k++) {
				sum = sum + mA[c][k]*mB[k][d];
			}

			mAxB[c][d] = sum;

			sum = 0;
		}
	}

	ftime(&tp);

	strftime(timeString, sizeof(timeString), "%H:%M:%S", localtime(&tp.time));

	printf("Fim da multiplica: %s:%d\n", timeString, tp.millitm);

	printf("\n");

	int i = 0;
	for (c = 0; c < t; c++) {
		for (i = 0; i < t; ++i) {
			printf("%d\t", mAxB[c][i]);
		}

		printf("\n");
	}
} // multiplica

int main() {

	int t, c, d, k, sum = 0;
	int min = 0;
	int max = 10;

	struct timeb tp;

	// t = 543; // tamanho da matriz

	t = 2; // tamanho da matriz

	printf("Multiplicar matrizes quadradas - o valor de t (neste caso %i) deve ser 500 + os dois dígitos do meio do seu TIA\n",t);

	ftime(&tp);

	char timeString[80];

	strftime(timeString, sizeof(timeString), "%H:%M:%S", localtime(&tp.time));

	printf("Antes de chamar a multiplica: %s:%d\n", timeString, tp.millitm);

	int A[t][t], B[t][t], AxB[t][t];

	for (c = 0; c < t; c++) {
		for (d = 0; d < t; d++) {
			A[c][d] = min + (rand() % (int)(max - min + 1));
			B[c][d] = min + (rand() % (int)(max - min + 1));
		}
	}

	multiplica(t, A, B);

	ftime(&tp);

	strftime(timeString, sizeof(timeString), "%H:%M:%S", localtime(&tp.time));

	printf("Fim do programa principal: %s:%d\n", timeString, tp.millitm);

	return 0;
}
