#include <stdio.h>
#include <stdlib.h>
#include "player.h"
#include "playlist.h"
#include "listase.h"

struct player {
    t_lse* biblioteca;
    t_playlist* playlist;
    t_lse* historico;
};

t_player* player_criar() {
    // Implemente o seu código aqui
    return NULL;
}

void player_destruir(t_player* p) {
    // Implemente o seu código aqui
}

void player_add_biblioteca(t_player* p, void* m) {
    // Implemente o seu código aqui
}

void player_add_playlist(t_player* p, void* m) {
    // Implemente o seu código aqui
}

void* player_buscar_biblioteca_por_nome(t_player* p, const char* nome) {
    // Implemente o seu código aqui
    return NULL;
}

void* player_remover_biblioteca_por_nome(t_player* p, const char* nome) {
    // Implemente o seu código aqui
    return NULL;
}

void* player_remover_playlist_por_nome(t_player* p, const char* nome) {
    // Implemente o seu código aqui
    return NULL;
}

void player_tocar_playlist(t_player* p) {
    // Implemente o seu código aqui
}

void player_tocar_musica(t_player* p, const char* nome) {
    // Implemente o seu código aqui
}

void player_tocar_ultimas_k_musicas(t_player* p, int k) {
    // Implemente o seu código aqui
}

void player_exportar_biblioteca(t_player* p) {
    if (!p)
        return;

    freopen("musicas.txt", "w", stdout);

    // Implemente o seu código aqui

    puts("Salvo em musicas.txt");
    freopen("/dev/tty", "w", stdout);
}
