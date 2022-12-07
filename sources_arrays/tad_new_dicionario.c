#include "../headers_arrays/tad_new_dicionario.h"

void incializa_vetor_palavras(tipo_vetor_palavras *vetor, int tamanho) {
    vetor -> vetor_palavras = malloc(tamanho * sizeof(tipo_palavra));
}

void copia_lista_palavras(tipo_lista_palavras *lista_palavras, tipo_vetor_palavras *vetor) {
    printf("\n");
}

void inicializa_new_dicionario(new_dicionario *new_dicionario, tipo_dicionario *dicionario) {
    int i;
    int num_palavras;
    for (i = 0; i < 26; i++) {
        new_dicionario -> alfabeto[i].identificador_upper = 'A' + i;
        new_dicionario -> alfabeto[i].identificador_lower = 'a' + i;
        num_palavras = retorna_numero_palavras(&dicionario.alfabeto[num_letra].lista_palavras);
        incializa_vetor_palavras(&new_dicionario -> alfabeto[i].lista_palavras_vetor, num_palavras);
    }
}

void constroi_dicionario(new_dicionario *new_dicionario, tipo_dicionario *dicionario) {

}