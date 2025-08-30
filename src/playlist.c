#include <stdlib.h>
#include "playlist.h"
#include "listase.h"
#include "musica.h"

struct playlist {
    t_lse* fila;
};

t_playlist* playlist_criar() {
    // Implemente o seu código aqui
    return NULL;
}

void playlist_destruir(t_playlist* pl) {
    // Implemente o seu código aqui
}

void playlist_inserir_final(t_playlist* pl, void* m) {
    // Implemente o seu código aqui
}

void* playlist_remover_inicio(t_playlist* pl) {
    // Implemente o seu código aqui
    return NULL;
}

void* playlist_buscar_por_nome(t_playlist* pl, const char* nome) {
    // Implemente o seu código aqui
    return NULL;
}

void* playlist_remover_por_nome(t_playlist* pl, const char* nome) {
    // Implemente o seu código aqui
    return NULL;
}

void playlist_tocar(t_playlist* pl) {
    // Implemente o seu código aqui
}

int playlist_tamanho(t_playlist* pl) {
    // Implemente o seu código aqui
}
