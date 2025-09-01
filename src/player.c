#include <stdio.h>
#include <stdlib.h>
#include "../include/playlist.h"
#include "../include/player.h"
#include "../include/musica.h"
#include "../include/listase.h"

struct player {
    t_lse* biblioteca;
    t_playlist* playlist;
    t_lse* historico;
};

t_player* player_criar() {
    t_player* novo = malloc(sizeof(t_player));
    if (!novo){
        return NULL;
    }
    novo->biblioteca = lse_criar(musica_cmp_nome, musica_destruir, musica_imprimir);
    if(!novo->biblioteca){
        free(novo);
        return NULL;
    }
    novo->playlist= playlist_criar();
    if(!novo->playlist){
        lse_destruir(novo->biblioteca, musica_destruir);
        free(novo);
        return NULL;
    }
    novo->historico = lse_criar(musica_cmp_nome, NULL, musica_imprimir);
    if(!novo->historico){
        playlist_destruir(novo->playlist);
        lse_destruir(novo->biblioteca, musica_destruir);
        free(novo);
        return NULL;
    }
    return novo;
}

void player_destruir(t_player* p) {
    if(!p){
        return;
    }
    lse_destruir(p->biblioteca, musica_destruir);
    playlist_destruir(p->playlist);
    lse_destruir(p->historico, NULL);
    free(p);
}

void player_add_biblioteca(t_player* p, void* m) {
    if(!p || !m){
        return;
    }
    lse_inserir_ordenado(p->biblioteca, m, musica_cmp_nome);
    lse_inserir_inicio(p->historico, m);
    puts("Musica adicionada a biblioteca!");
}

void player_add_playlist(t_player* p, void* m) {
    if(!p || !m){
        return;
    }
    playlist_inserir_final(p->playlist, m);
    puts("Musica inserida na playlist!");
}

void* player_buscar_biblioteca_por_nome(t_player* p, const char* nome) {
    if(!p || !nome){
        return NULL;
    }
    void* musica = lse_buscar(p->biblioteca, (void*)nome, musica_cmp_nome);
    if(!musica){
        return NULL;
    }
    printf("Musica encontrada: ");
    return musica;
}

void player_remover_biblioteca_por_nome(t_player* p, const char* nome) {
    if(!p || !nome){
        return;
    }
    void* musica = lse_remover_por_nome(p->biblioteca, (void*)nome, musica_cmp_nome);
    if(!musica){
        return;
    }
    musica_destruir(musica);
    puts("Musica removida da biblioteca!");
}

void* player_remover_playlist_por_nome(t_player* p, const char* nome) {
    if(!p || !nome){
        return NULL;
    }
    void* removido = playlist_remover_por_nome(p->playlist, nome);
    puts("Musica removida da playlist!");
    return removido;
}

void player_tocar_playlist(t_player* p) {
    if(!p){
        return;
    }
    puts("Tocando playlist...");
    playlist_tocar(p->playlist);
}

void player_tocar_musica(t_player* p, const char* nome) {
    if(!p || !nome){
        return;
    }
    void* musica = lse_buscar(p->biblioteca, (void*)nome, musica_cmp_nome);
    if(!musica){
        return;
    }
    printf("Tocando musica: ");
    musica_imprimir(musica);

}

void player_tocar_ultimas_k_musicas(t_player* p, int k) {
    if(!p || k <= 0){
        return;
    }
    if(p->historico == NULL){
        return;
    }
    int historico_tamanho = lse_tamanho(p->historico);
    if(k>historico_tamanho){
        k = historico_tamanho;
    }
    for(int posicao = 0; posicao < k; posicao++){
        t_musica* msc = lse_buscar(p->historico, (void*)(intptr_t)posicao, NULL);
        if(!msc){
            return;
        }
        musica_imprimir(msc);
    }
}

void player_exportar_biblioteca(t_player* p) {
    if (!p)
        return;

    freopen("musicas.txt", "w", stdout);

    lse_imprimir(p->biblioteca, musica_imprimir);
    
    freopen("/dev/tty", "w", stdout);
    puts("Salvo em musicas.txt");
}
