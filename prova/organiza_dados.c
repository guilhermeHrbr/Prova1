#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    long long timestamp;
    char id_sensor[32];
    char valor[64];
} Leitura;

// Ordenação decrescente por timestamp
int comparar_desc(const void *a, const void *b) {
    long long ta = ((Leitura *)a)->timestamp;
    long long tb = ((Leitura *)b)->timestamp;
    return (tb > ta) - (tb < ta); // retorna negativo se tb > ta, ou seja, decrescente
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Uso: %s <arquivo_entrada>\n", argv[0]);
        return 1;
    }

    FILE *entrada = fopen(argv[1], "r");
    if (!entrada) {
        perror("Erro ao abrir o arquivo");
        return 1;
    }

    Leitura leituras[20000];
    int total = 0;

    // Lê o arquivo de entrada
    while (fscanf(entrada, "%lld %s %s", &leituras[total].timestamp, leituras[total].id_sensor, leituras[total].valor) == 3) {
        total++;
    }
    fclose(entrada);

    // Ordena em ordem decrescente
    qsort(leituras, total, sizeof(Leitura), comparar_desc);

    // Grava dados em arquivos separados por sensor
    for (int i = 0; i < total; i++) {
        char nome_arquivo[64];
        sprintf(nome_arquivo, "%s.txt", leituras[i].id_sensor);
        FILE *f = fopen(nome_arquivo, "a"); // "a" porque pode haver múltiplas leituras do mesmo sensor
        if (!f) {
            perror("Erro ao criar arquivo do sensor");
            continue;
        }
        fprintf(f, "%lld %s\n", leituras[i].timestamp, leituras[i].valor);
        fclose(f);
    }

    return 0;
}
