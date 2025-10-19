  #include <stdio.h>
    #include <stdlib.h>

    struct Canzone {
        char *nome;
        char *artista;
        int tempo;
    };

    void Rialloca(struct Canzone **libreria, int *dimensione) {
        *dimensione *= 2;
        *libreria = realloc(*libreria, *dimensione * sizeof(struct Canzone));
    }

    int main(void) {
        struct Canzone *libreria = malloc(sizeof(struct Canzone) * 10);
        int i = 0;
        int dimensione = 10;

        while (1) {
            int scelta;
            printf("Scegli un'opzione: \n 1- Aggiungi Canzone \n 2- Visualizza Libreria \n 3- Esci \n");
            scanf("%d", &scelta);

            switch (scelta) {
                case 1:
                    printf("inserire nome: ");
                    libreria[i].nome = malloc(20 * sizeof(char));
                    scanf("%49s", libreria[i].nome);

                    printf("inserire artista: ");
                    libreria[i].artista = malloc(20 * sizeof(char));
                    scanf("%49s", libreria[i].artista);

                    printf("inserire durata \n");
                    scanf("%d", &libreria[i].tempo);

                    i++;
                    if (i >= dimensione) Rialloca(&libreria, &dimensione);
                    break;
                case 2:
                    if (i == 0) {
                        printf("Libreria vuota!\m");
                        break;
                    }

                    for (int j = 0; j < i; j++) {
                        struct Canzone canzone = libreria[j];

                        printf("nome: %s \n", canzone.nome );
                        printf("artista: %s \n", canzone.artista);
                        printf("durata: %d  \n", canzone.tempo);
                        printf("\n");
                    }
                    break;
                case 3:
                    for (int j = 0; j < i; j++) {
                        free(libreria[j].nome);
                        free(libreria[j].artista);
                    }
                    free(libreria);
                    return 0;
                    break;
                default:
                    break;
            }
        }
    }