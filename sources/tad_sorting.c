#include "../headers/tad_sorting.h"

void bubble_sort(sorting_informations *information, tipo_dicionario *dicionario, new_dicionario *new_dicionario, int num_letra) {
    int length; length = retorna_numero_palavras(&dicionario -> alfabeto[num_letra].lista_palavras);
    if (length != 0) information -> lists++;
    int i, j;
    tipo_new_palavra aux;
    clock_t start, end;
    start = clock();
    // Algoritimo Bubble Sort
    for (i = 0; i < length - 1; i++) {
        for (j = 1; j < length - i; j++) {
            information -> sort_com++;
            if (strcmp(new_dicionario -> alfabeto[num_letra].lista_palavras_vetor.vetor_palavras[j].caracteres, 
            new_dicionario -> alfabeto[num_letra].lista_palavras_vetor.vetor_palavras[j - 1].caracteres) < 0) {
                aux = new_dicionario -> alfabeto[num_letra].lista_palavras_vetor.vetor_palavras[j];
                new_dicionario -> alfabeto[num_letra].lista_palavras_vetor.vetor_palavras[j] = 
                new_dicionario -> alfabeto[num_letra].lista_palavras_vetor.vetor_palavras[j - 1];
                new_dicionario -> alfabeto[num_letra].lista_palavras_vetor.vetor_palavras[j - 1] = aux;
                information -> sort_mov++;
            }
        }
    }
    end = clock();
    information -> sort_time = ((double) (end - start)) / CLOCKS_PER_SEC;
    set_next_informations(information);
    show_sorting_informations(information);
    reset_current_information(information);
}

// void selection_sort(sorting_informations *information, new_dicionario *new_dicionario, int num_letra, int length) {
//     int i, j;
//     int min;
//     char *aux;
//     clock_t start, end;
//     start = clock();
//     // Algoritmo Selection Sort
//     for (i = 0; i < length - 1; i++) {
//         min = i;
//         for (j = i + 1; j < length; j++) {
//             information -> sort_com++;
//             if (strcmp(new_dicionario -> alfabeto[num_letra].lista_palavras_vetor.vetor_palavras[j], 
//             new_dicionario -> alfabeto[num_letra].lista_palavras_vetor.vetor_palavras[min]) < 0) {
//                 min = j;
//             }
//         }
//         strcpy(aux, new_dicionario -> alfabeto[num_letra].lista_palavras_vetor.vetor_palavras[min]);
//         strcpy(new_dicionario -> alfabeto[num_letra].lista_palavras_vetor.vetor_palavras[min],
//         new_dicionario -> alfabeto[num_letra].lista_palavras_vetor.vetor_palavras[i]);
//         strcpy(new_dicionario -> alfabeto[num_letra].lista_palavras_vetor.vetor_palavras[i], aux);
//         information -> sort_mov++;
//     }
//     end = clock();
//     information -> sort_time = ((double) (end - start)) / CLOCKS_PER_SEC;
//     set_next_informations(information);
//     show_sorting_informations(information);
//     reset_current_information(information);
// }

// void insertion_sort(sorting_informations *information, new_dicionario *new_dicionario, int num_letra, int length) {
//     int i, j;
//     char *aux;
//     clock_t start, end;
//     start = clock();
//     // Algoritmo Insertion Sort
//     for (i = 0; i < length; i++) {
//         strcpy(aux, new_dicionario -> alfabeto[num_letra].lista_palavras_vetor.vetor_palavras[i]);
//         j = i - 1;
//         information -> sort_com++;
//         while ((j >= 0) && (strcmp(aux, 
//         new_dicionario -> alfabeto[num_letra].lista_palavras_vetor.vetor_palavras[j]) < 0)) {
//             strcpy(new_dicionario -> alfabeto[num_letra].lista_palavras_vetor.vetor_palavras[j + 1],
//             new_dicionario -> alfabeto[num_letra].lista_palavras_vetor.vetor_palavras[j]);
//             if (j != i - 1) information -> sort_com++;
//             j--;
//         }
//         strcpy(new_dicionario -> alfabeto[num_letra].lista_palavras_vetor.vetor_palavras[j + 1], aux);
//         information -> sort_mov++;
//     }
//     end = clock();
//     information -> sort_time = ((double) (end - start)) / CLOCKS_PER_SEC;
//     set_next_informations(information);
//     show_sorting_informations(information);
//     reset_current_information(information);
// }

// void shell_sort(sorting_informations *information, new_dicionario *new_dicionario, int num_letra, int length) {
//     int i, j;
//     int h; h = 1;
//     char *aux;
//     clock_t start, end;
//     start = clock();
//     // Algoritmo Shell Sort
//     do {
//         h = h * 3 + 1;
//     } while (h < length);
//     do {
//         h = h/3;
//         for (i = h; i < length; i++) {
//             strcpy(aux, new_dicionario -> alfabeto[num_letra].lista_palavras_vetor.vetor_palavras[i]);
//             j = i;
//             information -> sort_com++;
//             while (strcmp(new_dicionario -> alfabeto[num_letra].lista_palavras_vetor.vetor_palavras[j - h], aux) > 0) {
//                 strcpy(new_dicionario -> alfabeto[num_letra].lista_palavras_vetor.vetor_palavras[j],
//                 new_dicionario -> alfabeto[num_letra].lista_palavras_vetor.vetor_palavras[j - h]);
//                 if (j != i) information -> sort_com++;
//                 j -= h;
//                 if (j < h) {
//                     break;
//                 }
//             }
//             strcpy(new_dicionario -> alfabeto[num_letra].lista_palavras_vetor.vetor_palavras[j], aux);
//             information -> sort_mov++;
//         }
//     } while (h != 1);
//     end = clock();
//     information -> sort_time = ((double) (end - start)) / CLOCKS_PER_SEC;
//     set_next_informations(information);
//     show_sorting_informations(information);
//     reset_current_information(information);
// }

// Algoritmo Quick Sort - Sort - Partition - Swap
void quick_sort(sorting_informations *information, tipo_dicionario *dicionario, new_dicionario *new_dicionario, int num_letra) {
    int length; length = retorna_numero_palavras(&dicionario -> alfabeto[num_letra].lista_palavras);
    if (length != 0) {
        information -> lists++;
        clock_t start, end;
        start = clock();
        // Algoritmo Quick Sort -> Sort -> Partition
        sort(information, &new_dicionario -> alfabeto[num_letra].lista_palavras_vetor, 0, length - 1);
        end = clock();
        information -> sort_time = ((double) (end - start)) / CLOCKS_PER_SEC;
        set_next_informations(information);
        show_sorting_informations(information);
        reset_current_information(information);
    }
}
void sort(sorting_informations *information, tipo_vetor_palavras *vetor, int left, int right) {
    int i, j;
    partition(information, vetor, left, right, &i, &j);
    if (left < j) sort(information, vetor, left, j);
    if (i < right) sort(information, vetor, i, right);
}
void partition(sorting_informations *information, tipo_vetor_palavras *vetor, int left, int right, int *i, int *j) {
    *i = left; *j = right;
    tipo_new_palavra pivot;
    tipo_new_palavra aux;
    pivot = vetor -> vetor_palavras[(*i + *j) / 2];
    do {
        while (strcmp(pivot.caracteres, vetor -> vetor_palavras[*i].caracteres) > 0) (*i)++;
        while (strcmp(pivot.caracteres, vetor -> vetor_palavras[*j].caracteres) < 0) (*j)--;
        if (*i <= *j) {
            aux = vetor -> vetor_palavras[*i];
            vetor -> vetor_palavras[*i] = vetor -> vetor_palavras[*j];
            vetor -> vetor_palavras[*j] = aux;
            (*i)++; (*j)--;
            information -> sort_mov++;
        }
    } while (*i <= *j);
}

// // Algoritmo Heap Sort - Make - Remake
void heap_sort(sorting_informations *information, tipo_dicionario *dicionario, new_dicionario *new_dicionario, int num_letra) {
    int length; length = retorna_numero_palavras(&dicionario -> alfabeto[num_letra].lista_palavras);
    if (length != 0) {
        int left, right;
        tipo_new_palavra aux;
        clock_t start, end;
        start = clock();
        // Algoritmo Heap Sort -> Make -> Remake
        make(information, &new_dicionario -> alfabeto[num_letra].lista_palavras_vetor, &length);
        left = 1;
        right = length;
        while (right > 1) {
            aux = new_dicionario -> alfabeto[num_letra].lista_palavras_vetor.vetor_palavras[1];
            new_dicionario -> alfabeto[num_letra].lista_palavras_vetor.vetor_palavras[1] =
            new_dicionario -> alfabeto[num_letra].lista_palavras_vetor.vetor_palavras[right];
            new_dicionario -> alfabeto[num_letra].lista_palavras_vetor.vetor_palavras[right] = aux;
            information -> sort_mov++;
            right--;
            remake(information, &new_dicionario -> alfabeto[num_letra].lista_palavras_vetor, left, right);
        }
        end = clock();
        information -> sort_time = ((double) (end - start)) / CLOCKS_PER_SEC;
        set_next_informations(information);
        show_sorting_informations(information);
        reset_current_information(information);
    }
}
void make(sorting_informations *information, tipo_vetor_palavras *vetor, int *length) {
    int left;
    left = (*length / 2) + 1;
    while (left > 1) {
        left--;
        remake(information, vetor, left, *length);
    }
}
void remake(sorting_informations *information, tipo_vetor_palavras *vetor, int left, int right) {
    int j; j = left * 2;
    tipo_new_palavra aux; aux = vetor -> vetor_palavras[left];
    while (j <= right) {
        information -> sort_com++;
        if ((j < right) && (strcmp(vetor -> vetor_palavras[j].caracteres, vetor -> vetor_palavras[j + 1].caracteres) < 0)) j++;
        if (strcmp(aux.caracteres, vetor -> vetor_palavras[j].caracteres) >= 0) break;
        vetor -> vetor_palavras[left] = vetor -> vetor_palavras[j];
        left = j;
        j = left * 2;
    }
    vetor -> vetor_palavras[j] = aux;
}

void set_new_informations(sorting_informations *information) {
    information -> lists = 0;
    information -> sort_com = 0;
    information -> sort_mov = 0;
    information -> sort_time = 0;
    information -> t_sort_com = 0;
    information -> t_sort_mov = 0;
    information -> t_sort_time = 0;
    information -> md_sort_com = 0;
    information -> md_sort_mov = 0;
    information -> md_sort_time = 0;
}

void set_next_informations(sorting_informations *information) {
    information -> t_sort_com = information -> t_sort_com + information -> sort_com;
    information -> t_sort_mov = information -> t_sort_mov + information -> sort_mov;
    information -> t_sort_time = information -> t_sort_time + information -> sort_time;
}

void reset_current_information(sorting_informations *information) {    
    information -> sort_com = 0;
    information -> sort_mov = 0;
    information -> sort_time = 0;
}

void show_sorting_informations(sorting_informations *information) {
    printf("\n-----------------------------------------------------------------\n");
    printf("Comparações: %lf\n", information -> sort_com);
    printf("Movimentações: %lf\n", information -> sort_mov);
    printf("Tempo: %lf\n", information -> sort_time);
    printf("-----------------------------------------------------------------\n");
    printf("Total de listas de palavras: %lf\n", information -> lists);
    printf("Total de comparações: %lf\n", information -> t_sort_com);
    printf("Total de movimentaçẽs: %lf\n", information -> t_sort_mov);
    printf("Tempo total: %lf\n", information -> t_sort_time);
    printf("-----------------------------------------------------------------\n");
    printf("Média de comparações: %lf\n", information -> t_sort_com / information -> lists);
    printf("Média de movimentações %lf\n", information -> t_sort_mov / information -> lists);
    printf("Média de tempo: %lf\n", information -> t_sort_time / information -> lists);
    printf("-----------------------------------------------------------------\n");
}