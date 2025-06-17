#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

long long converter_para_timestamp(const char *data_hora) {
    struct tm t = {0};
    strptime(data_hora, "%Y-%m-%dT%H:%M:%S", &t);
    return (long long)mktime(&t);
}

void gerar_valor(char *tipo, char *saida) {
    if (strcmp(tipo, "CONJ_Z") == 0) {
        sprintf(saida, "%d", rand() % 1000);
    } else if (strcmp(tipo, "CONJ_Q") == 0) {
        sprintf(saida, "%.2f", (float)rand() / (float)(RAND_MAX/1000.0));
    } else if (strcmp(tipo, "BINARIO") == 0) {
        sprintf(saida, "%s", rand() % 2 ? "true" : "false");
    } else if (strcmp(tipo, "TEXTO") == 0) {
        for (int i = 0; i < 8; i++)
            saida[i] = 'A' + rand() % 26;
        saida[8] = '\0';
    } else {
        strcpy(saida, "TIPO_INVALIDO");
    }
}

int main(int argc, char *argv[]) {
    if (argc < 5 || (argc - 3) % 2 != 0) {
        printf("Uso: %s <inicio> <fim> <sensor1>:<tipo1> <sensor2>:<tipo2> ...\n", argv[0]);
        printf("Tipos válidos: CONJ_Z, CONJ_Q, BINARIO, TEXTO\n");
        return 1;
    }

    long long inicio = converter_para_timestamp(argv[1]);
    long long fim = converter_para_timestamp(argv[2]);

    FILE *f = fopen("dados.txt", "w");
    if (!f) return 1;

    srand(time(NULL));
    for (int i = 3; i < argc; i++) {
        char *token = strtok(argv[i], ":");
        char sensor[32], tipo[16];
        strcpy(sensor, token);
        token = strtok(NULL, ":");
        if (token == NULL) continue;
        strcpy(tipo, token);

        for (int j = 0; j < 2000; j++) {
            long long timestamp = inicio + rand() % (fim - inicio);
            char valor[64];
            gerar_valor(tipo, valor);
            fprintf(f, "%lld %s %s\n", timestamp, sensor, valor);
        }
    }

    fclose(f);
    return 0;
}
