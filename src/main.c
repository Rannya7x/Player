#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/player.h"
#include "../include/musica.h"
#include "../include/playlist.h"

static void ler_linha(char* buf, size_t n) {
    if (fgets(buf, (int)n, stdin)) {
        size_t len = strlen(buf);
        if (len && buf[len - 1] == '\n')
            buf[len - 1] = 0;
    }
}

int main() {
    
    t_player* pl = player_criar();
    if (!pl) {
        puts("Falha ao criar player.");
        return 1;
    }
    int k;
    int opt = -1;
    char nome[64], genero[32], album[64], cantor[64];
    int duracao, ano;
    t_musica* musica;

    puts("=== Tocador de Musica ===");
    puts("0. Sair");
    puts("1. Adicionar musica na biblioteca");
    puts("2. Buscar musica na biblioteca");
    puts("3. Remover musica da biblioteca");
    puts("4. Inserir musica da biblioteca na playlist");
    puts("5. Remover musica da playlist");
    puts("6. Tocar playlist");
    puts("7. Tocar musica individual");
    puts("8. Tocar ultimas K musicas");
    puts("9. Exportar biblioteca");

    while (opt != 0) {
        printf("\nOpcao: ");
        if (scanf("%d%*c", &opt) != 1)
            break;
        switch (opt) {
        case 0:
            puts("Fechando player...");
            break;
        case 1:
            printf("Nome: ");
            ler_linha(nome, sizeof(nome));
            printf("Genero: ");
            ler_linha(genero, sizeof(genero));
            printf("Duracao (s): ");
            if (scanf("%d%*c", &duracao) != 1) {
                break;
            }
            printf("Album: ");
            ler_linha(album, sizeof(album));
            printf("Cantor: ");
            ler_linha(cantor, sizeof(cantor));
            printf("Ano: ");
            if (scanf("%d%*c", &ano) != 1) {
                break;
            }
            musica = musica_criar(nome, genero, duracao, album, cantor, ano);
            if(!musica) {
                break;
            }
            player_add_biblioteca(pl, musica);
            puts("Musica adicionada a biblioteca!");
            break;
        case 2:
            printf("Nome para buscar: ");
            ler_linha(nome, sizeof(nome));
            musica = player_buscar_biblioteca_por_nome(pl, nome);
            if(!musica) {
                break;
            }
            printf("Musica encontrada: ");
            musica_imprimir(musica);
            break;
        case 3:
            printf("Nome: ");
            ler_linha(nome, sizeof(nome));
            musica = player_remover_biblioteca_por_nome(pl, nome);
            if(musica) {
                break;
            }
            puts("Musica removida da biblioteca!");
            break;
        case 4:
            printf("Nome: ");
            ler_linha(nome, sizeof(nome));
            musica = player_buscar_biblioteca_por_nome(pl, nome);
            if(!musica) {
                break;
            }
            player_add_playlist(pl, musica);
            puts("Musica inserida na playlist!");
            break;
        case 5:
            printf("Nome: ");
            ler_linha(nome, sizeof(nome));
            musica = player_remover_playlist_por_nome(pl, nome);
            if(musica) {
                break;
            }
            puts("Musica removida da playlist!");
            break;
        case 6:
            puts("Tocando playlist...");
            player_tocar_playlist(pl);
            break;
        case 7:
            printf("Nome: ");
            ler_linha(nome, sizeof(nome));
            if(!nome) {
                break;
            }
            printf("Tocando musica: ");
            player_tocar_musica(pl, nome);
            break;
        case 8:
            printf("Quantidade: ");
            if(scanf("%d%*c", &k) != 1) {
                break;
            }
            player_tocar_ultimas_k_musicas(pl, k); 
            break;
        case 9:
            player_exportar_biblioteca(pl);
            break;
        default:
            puts("Opcao invalida.");
        }
    }
    
    player_destruir(pl);
    
    return 0;
}
