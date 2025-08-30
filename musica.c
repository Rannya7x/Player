#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "musica.h"

struct musica {
    char nome[60];
    char genero[30];
    int duracao;
    char album[60];
    char cantor[60];
    int ano;
};

t_musica* musica_criar() {
    // Implemente o seu código aqui
    return NULL;
}

void musica_imprimir(void* p) {
    // Implemente o seu código aqui
}

int musica_cmp_nome(void* carga, void* chave) {
    // Implemente o seu código aqui
}

void musica_destruir(void* p) {
    // Implemente o seu código aqui
}
