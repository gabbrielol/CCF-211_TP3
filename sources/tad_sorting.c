#include "../headers/tad_sorting.h"

void bubble_sort(sorting_informations *information, new_dicionario *new_dicionario, int length, int num_letra) {
    set_new_informations(information);
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
}

void selection_sort(sorting_informations *information, new_dicionario *new_dicionario, int length, int num_letra) {
    set_new_informations(information);
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

void insertion_sort(sorting_informations *information, new_dicionario *new_dicionario, int length, int num_letra) {
    set_new_informations(information);
    int i, j;
    char *aux;
    clock_t start, end;
    start = clock();
    // Algoritmo Insertion Sort
    for (i = 0; i < length; i++) {
        strcpy(aux, new_dicionario -> alfabeto[num_letra].lista_palavras_vetor.vetor_palavras[i]);
        j = i - 1;
        while ((j >= 0) && (strcmp(aux, 
        new_dicionario -> alfabeto[num_letra].lista_palavras_vetor.vetor_palavras[j]) < 0)) {
            strcpy(new_dicionario -> alfabeto[num_letra].lista_palavras_vetor.vetor_palavras[j + 1],
            new_dicionario -> alfabeto[num_letra].lista_palavras_vetor.vetor_palavras[j]);
            j--;
        }
        strcpy(new_dicionario -> alfabeto[num_letra].lista_palavras_vetor.vetor_palavras[j + 1], aux);
    }
    end = clock();
    information -> sort_time = ((double) (end - start)) / CLOCKS_PER_SEC;
    show_sorting_informations(information);
}

void shell_sort(sorting_informations *information, new_dicionario *new_dicionario, int length, int num_letra) {
    set_new_informations(information);
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

// Algoritmo Quick Sort - Sort / Partition / Quick Sort
void sort(int left, int right, new_dicionario *new_dicionario, int num_letra) {
   int i, j;
   partition(left, right, &i, &j, new_dicionario, num_letra);
   if (left < j) {
    sort(left, j, new_dicionario, num_letra);
   }
   if (i < right) {
    sort(i, right, new_dicionario, num_letra);
   }
}

void partition(int left, int right, int *i, int *j, new_dicionario *new_dicionario, int num_letra) {
    char *aux;
    char *pivot;
    strcpy(pivot, new_dicionario -> alfabeto[num_letra].lista_palavras_vetor.vetor_palavras[(*i + *j)/2]);
    *i = left;
    *j = right;
    do {
        while (strcmp(pivot, new_dicionario -> alfabeto[num_letra].lista_palavras_vetor.vetor_palavras[*i]) > 0) {
            (*i)++;
        }
        while (strcmp(pivot, new_dicionario -> alfabeto[num_letra].lista_palavras_vetor.vetor_palavras[*j]) < 0)
        {
            (*j)--;
        }
        if (*i <= *j) {
            strcpy(aux, new_dicionario -> alfabeto[num_letra].lista_palavras_vetor.vetor_palavras[*i]);
            strcpy(new_dicionario -> alfabeto[num_letra].lista_palavras_vetor.vetor_palavras[*i], 
            new_dicionario -> alfabeto[num_letra].lista_palavras_vetor.vetor_palavras[*j]);
            strcpy(new_dicionario -> alfabeto[num_letra].lista_palavras_vetor.vetor_palavras[*j], aux);
            (*i)++;
            (*j)--;
        }
    } while (*i <= *j);
}

void quick_sort(sorting_informations *information, new_dicionario *new_dicionario, int lenght, int num_letra) {
    set_new_informations(information);
    clock_t start, end;
    start = clock();
    sort(0, lenght - 1, new_dicionario, num_letra);
    end = clock();
    information -> sort_time = ((double) (end - start)) / CLOCKS_PER_SEC;
    show_sorting_informations(information);
}

// Algoritmo Heap Sort - Make / Remake / Heap Sort
void make(new_dicionario *new_dicionario, int length);
void remake(int left, int right, new_dicionario *new_dicionario);
void heap_sort(sorting_informations *information, new_dicionario *new_dicionario, int length);

void set_new_informations(sorting_informations *information) {
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
}