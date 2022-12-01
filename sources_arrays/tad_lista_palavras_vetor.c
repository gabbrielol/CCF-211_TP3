#include "../headers_arrays/tad_lista_palavras_vetor.h"

void incializa_vetor_palavras(tipo_vetor_palavras *vetor, int tamanho) {
    vetor -> vetor_palavras = malloc(tamanho * sizeof(tipo_palavra));
}

void copia_lista_palavras(tipo_lista_palavras *lista_palavras, tipo_vetor_palavras *vetor, int tamanho) {
    int i; i = 0;
    apontador_lista_palavras aux_palavra_copia; aux_palavra_copia = lista_palavras -> primeiro_lista -> p_prox_lista;
    while (aux_palavra_copia != NULL) {
        while (i < tamanho) {
            vetor -> vetor_palavras[i] = aux_palavra_copia -> item_palavra;
            i++;
            break;
        }
        aux_palavra_copia = aux_palavra_copia -> p_prox_lista;
    }
}