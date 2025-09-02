#ifndef PLAYER_H
#define PLAYER_H

typedef struct player t_player;

t_player* player_criar();
void player_destruir(t_player* p);
void player_add_biblioteca(t_player* p, void* m);
void player_add_playlist(t_player* p, void* m);
void* player_buscar_biblioteca_por_nome(t_player* p, const char* nome);
void* player_remover_biblioteca_por_nome(t_player* p, const char* nome);
void* player_remover_playlist_por_nome(t_player* p, const char* nome);
void player_tocar_playlist(t_player* p);
void player_tocar_musica(t_player* p, const char* nome);
void player_tocar_ultimas_k_musicas(t_player* p, int k);
void player_exportar_biblioteca(t_player* p);

#endif // PLAYER_H
