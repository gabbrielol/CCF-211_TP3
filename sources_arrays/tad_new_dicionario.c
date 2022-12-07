#include "../headers_arrays/tad_new_dicionario.h"

void incializa_vetor_palavras(tipo_vetor_palavras *vetor, int tamanho) {
    vetor -> vetor_palavras = malloc(tamanho * sizeof(tipo_palavra));
}
