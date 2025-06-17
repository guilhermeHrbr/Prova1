#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

long long converter_para_timestamp(const char *data_hora) {
    struct tm t = {0};
    strptime(data_hora, "%Y-%m-%d %H:%M:%S", &t);
    return (long long)mktime(&t);
}

typedef struct {
    long long timestamp;
    char valor[64];
} Leitura;

long long abs_diff(long long a, long long b) {
    return a > b ? a - b : b - a;
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Uso: %s <sensor> <data_hora>\n", argv[0]);
        return 1;
    }

    char nome_arquivo[64];
    sprintf(nome_arquivo, "%s.txt", argv[1]);

    FILE *f = fopen(nome_arquivo, "r");
    if (!f) {
        printf("Arquivo do sensor não encontrado\n");
        return 1;
    }

    Leitura leituras[20000];
    int total = 0;
    while (fscanf(f, "%lld %s", &leituras[total].timestamp, leituras[total].valor) == 2) {
        total++;
    }
    fclose(f);

    long long alvo = converter_para_timestamp(argv[2]);

    // Busca binária em lista ordenada DECRESCENTEMENTE
    int inicio = 0, fim = total - 1, meio;
    int melhor = 0;
    while (inicio <= fim) {
        meio = (inicio + fim) / 2;
        if (abs_diff(leituras[meio].timestamp, alvo) < abs_diff(leituras[melhor].timestamp, alvo)) {
            melhor = meio;
        }

        // Inverte lógica porque a lista está em ordem decrescente
        if (leituras[meio].timestamp > alvo) {
            inicio = meio + 1;
        } else {
            fim = meio - 1;
        }
    }

    printf("%lld %s\n", leituras[melhor].timestamp, leituras[melhor].valor);
    return 0;
}
