#include <stdlib.h>
#include <assert.h>
#include "../include/playlist.h"
#include "../include/listase.h"
#include "../include/musica.h"

struct playlist {
    t_lse* fila;
};

t_playlist* playlist_criar() {
    t_playlist* nova = malloc(sizeof(t_playlist)); 
    assert(nova != NULL);
    nova->fila = lse_criar(musica_cmp_nome, musica_destruir, musica_imprimir);
    
    if(nova->fila == NULL) {
        free(nova);
        return NULL;
    }
    return nova;
}

void playlist_destruir(t_playlist* pl) {
    assert(pl != NULL);
    lse_destruir(pl->fila, NULL);
    pl->fila = NULL;
    free(pl);
}

void playlist_inserir_final(t_playlist* pl, void* m) {
    if(!pl || !m){ return; }
    lse_inserir_final(pl->fila, m);
}

void* playlist_remover_inicio(t_playlist* pl) {
    if(!pl){ return NULL; }

    return lse_remover_inicio(pl->fila);
}

void* playlist_buscar_por_nome(t_playlist* pl, const char* nome) {
    if(!pl || !nome){ return NULL; }
    return lse_buscar(pl->fila, (void*)nome, musica_cmp_nome);
}

void* playlist_remover_por_nome(t_playlist* pl, const char* nome) {
    if(!pl || !nome){ return NULL; }
    return lse_remover_por_nome(pl->fila, (void*)nome, musica_cmp_nome);
}

void playlist_tocar(t_playlist* pl) {
    if(!pl){ return; }
    lse_imprimir(pl->fila, musica_imprimir);
}

int playlist_tamanho(t_playlist* pl) {
    if(!pl){ return -1; } //lista vazia
    return lse_tamanho(pl->fila);
}
