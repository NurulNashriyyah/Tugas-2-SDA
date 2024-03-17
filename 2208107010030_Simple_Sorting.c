#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 1000000

void bubbleSort(int arr[], int n)
{
    int i, j, temp;
    int swapped;
    for (i = 0; i < n - 1; i++)
    {
        swapped = 0;
        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = 1;
            }
        }
        // Jika tidak ada elemen yang ditukar dalam loop, maka array sudah diurutkan
        if (swapped == 0)
            break;
    }
}

void selectionSort(int arr[], int n)
{
    int i, j, min_idx, temp;
    for (i = 0; i < n - 1; i++)
    {                // Ulangi (size - 1) kali
        min_idx = i; // Setel elemen yang belum diurutkan pertama sebagai minimum
        for (j = i + 1; j < n; j++)
        { // Untuk setiap elemen yang belum diurutkan
            if (arr[j] < arr[min_idx])
            {                // Jika elemen < minimum saat ini
                min_idx = j; // Setel elemen sebagai minimum baru
            }
        }
        // Tukar minimum dengan posisi yang belum diurutkan pertama
        temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}

void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {                 // Untuk setiap elemen yang belum diurutkan
        key = arr[i]; // 'Ekstrak' elemen X
        j = i - 1;
        // Jika elemen saat ini > X, pindahkan elemen yang sudah diurutkan ke kanan sebanyak 1
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        // Sisipkan X di sini
        arr[j + 1] = key;
    }
}
void saveToFile(char* filename, int arr[], int n)
{
    FILE *fp;
    fp = fopen(filename, "w");
    if (fp == NULL)
    {
        printf("Gagal membuka file.\n");
        exit(1);
    }
    for (int i = 0; i < n; i++)
    {
        fprintf(fp, "%d\n", arr[i]);
    }
    fclose(fp);
}

int main()
{
    int arr[MAX], n = MAX, i;
    clock_t start, end;
    double cpu_time_used;
    char filename[20];

    printf("| %-15s | %-16s | %-20s |\n", "Jenis Algoritma", "Jumlah Bilangan", "Waktu Eksekusi (ms)");
    printf("|-----------------|------------------|----------------------|\n");

    for (int size = 100000; size <= MAX; size += 100000)
    {
        // Menghasilkan bilangan acak
        for (i = 0; i < size; i++)
        {
            arr[i] = rand();
        }

        // Menyimpan bilangan yang belum terurut
        sprintf(filename, "unsorted_%dk.txt", size / 1000);
        saveToFile(filename, arr, size);

        // Mengurutkan bilangan dengan bubble sort dan mencatat waktu eksekusi
        start = clock();
        bubbleSort(arr, size);
        end = clock();
        cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
        printf("| %-15s | %15dk | %20.2f |\n", "Bubble Sort", size / 1000, cpu_time_used * 1000);
    }

    for (int size = 100000; size <= MAX; size += 100000)
    {
        // Menghasilkan bilangan acak
        for (i = 0; i < size; i++)
        {
            arr[i] = rand();
        }

        // Mengurutkan bilangan dengan selection sort dan mencatat waktu eksekusi
        start = clock();
        selectionSort(arr, size);
        end = clock();
        cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
        printf("| %-15s | %15dk | %20.2f |\n", "Selection Sort", size / 1000, cpu_time_used * 1000);
    }

    for (int size = 100000; size <= MAX; size += 100000)
    {
        // Menghasilkan bilangan acak
        for (i = 0; i < size; i++)
        {
            arr[i] = rand();
        }

        // Mengurutkan bilangan dengan insertion sort dan mencatat waktu eksekusi
        start = clock();
        insertionSort(arr, size);
        end = clock();
        cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
        printf("| %-15s | %15dk | %20.2f |\n", "Insertion Sort", size / 1000, cpu_time_used * 1000);

        // Menyimpan bilangan yang sudah terurut
        sprintf(filename, "sorted_%dk.txt", size / 1000);
        saveToFile(filename, arr, size);
    }

    return 0;
}
