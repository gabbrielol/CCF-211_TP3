#include "../headers/tad_sorting.h"

void bubble_sort(sorting_informations *information, new_dicionario *new_dicionario, int num_letra, int length) {
    int i, j;
    char *aux;
    clock_t start, end;
    start = clock();
    // Algoritimo Bubble Sort
    for (i = 0; i < length - 1; i++) {
        for (j = 1; j < length - i; j++) {
            information -> sort_com++;
            if (strcmp(new_dicionario -> alfabeto[num_letra].lista_palavras_vetor.vetor_palavras[j], 
            new_dicionario -> alfabeto[num_letra].lista_palavras_vetor.vetor_palavras[j - 1]) < 0) {
                strcpy(aux, new_dicionario -> alfabeto[num_letra].lista_palavras_vetor.vetor_palavras[j]);
                strcpy(new_dicionario -> alfabeto[num_letra].lista_palavras_vetor.vetor_palavras[j], 
                new_dicionario -> alfabeto[num_letra].lista_palavras_vetor.vetor_palavras[j - 1]);
                strcpy(new_dicionario -> alfabeto[num_letra].lista_palavras_vetor.vetor_palavras[j - 1], aux);
                information -> sort_mov++;
            }
        }
    }
    end = clock();
    information -> sort_time = ((double) (end - start)) / CLOCKS_PER_SEC;
    show_sorting_informations(information);
    set_next_informations(information);
}

void selection_sort(sorting_informations *information, new_dicionario *new_dicionario, int num_letra, int length) {
    int i, j;
    int min;
    char *aux;
    clock_t start, end;
    start = clock();
    // Algoritmo Selection Sort
    for (i = 0; i < length - 1; i++) {
        min = i;
        for (j = i + 1; j < length; j++) {
            information -> sort_com++;
            if (strcmp(new_dicionario -> alfabeto[num_letra].lista_palavras_vetor.vetor_palavras[j], 
            new_dicionario -> alfabeto[num_letra].lista_palavras_vetor.vetor_palavras[min]) < 0) {
                min = j;
            }
        }
        strcpy(aux, new_dicionario -> alfabeto[num_letra].lista_palavras_vetor.vetor_palavras[min]);
        strcpy(new_dicionario -> alfabeto[num_letra].lista_palavras_vetor.vetor_palavras[min],
        new_dicionario -> alfabeto[num_letra].lista_palavras_vetor.vetor_palavras[i]);
        strcpy(new_dicionario -> alfabeto[num_letra].lista_palavras_vetor.vetor_palavras[i], aux);
        information -> sort_mov++;
    }
    end = clock();
    information -> sort_time = ((double) (end - start)) / CLOCKS_PER_SEC;
    show_sorting_informations(information);
}

void insertion_sort(sorting_informations *information, new_dicionario *new_dicionario, int num_letra, int length) {
    int i, j;
    char *aux;
    clock_t start, end;
    start = clock();
    // Algoritmo Insertion Sort
    for (i = 0; i < length; i++) {
        strcpy(aux, new_dicionario -> alfabeto[num_letra].lista_palavras_vetor.vetor_palavras[i]);
        j = i - 1;
        if ((j >= 0) && (strcmp(aux, 
        new_dicionario -> alfabeto[num_letra].lista_palavras_vetor.vetor_palavras[j]) < 0)) {
            information -> sort_com++;
        }
        while ((j >= 0) && (strcmp(aux, 
        new_dicionario -> alfabeto[num_letra].lista_palavras_vetor.vetor_palavras[j]) < 0)) {
            strcpy(new_dicionario -> alfabeto[num_letra].lista_palavras_vetor.vetor_palavras[j + 1],
            new_dicionario -> alfabeto[num_letra].lista_palavras_vetor.vetor_palavras[j]);
            j--;
        }
        strcpy(new_dicionario -> alfabeto[num_letra].lista_palavras_vetor.vetor_palavras[j + 1], aux);
        information -> sort_mov++;
    }
    end = clock();
    information -> sort_time = ((double) (end - start)) / CLOCKS_PER_SEC;
    show_sorting_informations(information);
}

void shell_sort(sorting_informations *information, new_dicionario *new_dicionario, int num_letra, int length) {
    int i, j;
    int h; h = 1;
    char *aux;
    clock_t start, end;
    start = clock();
    // Algoritmo Shell Sort
    do {
        h = h * 3 + 1;
    } while (h < length);

    do {
        h = h/3;
        for (i = h; i < length; i++) {
            strcpy(aux, new_dicionario -> alfabeto[num_letra].lista_palavras_vetor.vetor_palavras[i]);
            j = i;
            while (strcmp(new_dicionario -> alfabeto[num_letra].lista_palavras_vetor.vetor_palavras[j - h], aux) > 0) {
                strcpy(new_dicionario -> alfabeto[num_letra].lista_palavras_vetor.vetor_palavras[j],
                new_dicionario -> alfabeto[num_letra].lista_palavras_vetor.vetor_palavras[j - h]);
                j -= h;
                if (j < h) {
                    break;
                }
            }
            strcpy(new_dicionario -> alfabeto[num_letra].lista_palavras_vetor.vetor_palavras[j], aux);
        }
    } while (h != 1);
    end = clock();
    information -> sort_time = ((double) (end - start)) / CLOCKS_PER_SEC;
    show_sorting_informations(information);
}

// Algoritmo Quick Sort - Sort - Partition - Swap
void quick_sort(sorting_informations *information, new_dicionario *new_dicionario, int num_letra, int length) {
    clock_t start, end;
    start = clock();
    // Função Quick Sort -> Sort -> Partition
    sort(information, &new_dicionario -> alfabeto[num_letra].lista_palavras_vetor, 0, length - 1);
    end = clock();
    information -> sort_time = ((double) (end - start)) / CLOCKS_PER_SEC;
    show_sorting_informations(information);
}

void sort(sorting_informations *information, tipo_vetor_palavras *vetor, int left, int right) {
    int i, j;
    partition(information, vetor, left, right, &i, &j);
    if (left < j) sort(information, vetor, left, j);
    if (i < right) sort(information, vetor, i, right);
}

void partition(sorting_informations *information, tipo_vetor_palavras *vetor, int left, int right, int *i, int *j) {
    *i = left; *j = right;
    char *pivot;
    char *aux;
    pivot = strdup(vetor -> vetor_palavras[(*i + *j) / 2]);
    do {
        while (strcmp(pivot, vetor -> vetor_palavras[*i]) > 0) (*i)++;
        while (strcmp(pivot, vetor -> vetor_palavras[*j]) < 0) (*j)--;
        printf("%d | %d\n", *i, *j);
        if (*i <= *j) {
            strcpy(aux, vetor -> vetor_palavras[*i]);
            strcpy(vetor -> vetor_palavras[*i], vetor -> vetor_palavras[*j]);
            strcpy(vetor -> vetor_palavras[*j], aux);
            (*i)++; (*j)--;
            information -> sort_mov++;
        }
    } while (*i <= *j);
}

// Algoritmo Heap Sort - Make - Remake
void heap_sort(sorting_informations *information, new_dicionario *new_dicionario, int num_letra, int *length) {
    int left, right;
    char *aux;
    make(information, &new_dicionario -> alfabeto[num_letra].lista_palavras_vetor, length);
    left = 1;
    right = *length;
    while (right > 1) {
        strcpy(aux, new_dicionario -> alfabeto[num_letra].lista_palavras_vetor.vetor_palavras[1]);
        strcpy(new_dicionario -> alfabeto[num_letra].lista_palavras_vetor.vetor_palavras[1],
        new_dicionario -> alfabeto[num_letra].lista_palavras_vetor.vetor_palavras[right]);
        strcpy(new_dicionario -> alfabeto[num_letra].lista_palavras_vetor.vetor_palavras[right], aux);
        right--;
        remake(information, &new_dicionario -> alfabeto[num_letra].lista_palavras_vetor, left, right);
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
    char *aux; strcpy(aux, vetor -> vetor_palavras[left]);
    while (j <= right) {
        if ((j < right) && (strcmp(vetor -> vetor_palavras[j], vetor -> vetor_palavras[j + 1]) < 0)) j++;
        if (strcmp(aux, vetor -> vetor_palavras[j]) >= 0) break;
        strcpy(vetor -> vetor_palavras[left], vetor -> vetor_palavras[j]);
        left = j;
        j = left * 2;
    }
    strcpy(vetor -> vetor_palavras[j], aux);
}

void set_new_informations(sorting_informations *information) {
    information -> sort_com = 0;
    information -> sort_mov = 0;
    information -> sort_time = 0;
    information -> t_sort_com = 0;
    information -> t_sort_mov = 0;
    information -> t_sort_time = 0;
}

void set_next_informations(sorting_informations *information) {
    information -> t_sort_com = information -> t_sort_com + information -> sort_com;
    information -> t_sort_mov = information -> t_sort_com + information -> sort_mov;
    information -> t_sort_time = information -> t_sort_com + information -> sort_time;
    information -> sort_com = 0;
    information -> sort_mov = 0;
    information -> sort_time = 0;
}

void show_sorting_informations(sorting_informations *information) {
    printf("\n-----------------------------------------------------------------\n");
    printf("Comparações: %d\n", information -> sort_com);
    printf("Movimentações: %d\n", information -> sort_mov);
    printf("Tempo: %lf\n", information -> sort_time);
    printf("-----------------------------------------------------------------\n");
    printf("Total de comparações: %d\n", information -> t_sort_com);
    printf("Total de movimentaçẽs: %d\n", information -> t_sort_mov);
    printf("Tempo total: %lf\n", information -> t_sort_time);
    printf("-----------------------------------------------------------------\n");
}