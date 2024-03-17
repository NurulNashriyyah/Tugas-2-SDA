# 2208107010030_Simple_Sorting
File C ini dibuat untuk memenuhi tugas 2 mata kuliah Struktur Data dan Algoritma.
File ini berisi penyelesaian kasus untuk melakukan generating bilangan secara acak,
lalu melakukan pengurutan menggunakan algoritma bubble sort, selection sort, dan insertion sort.
Output dari kode program ini adalah hasil evaluasi berbentu tabel yang terdiri dari
kolom jenis algoritma, jumlah bilangan dan waktu eksekusi (ms).

## Persyaratan Menjalankan Kode
1. Compiler C
2. Terminal

## Cara Menjalankan Program
1. Buka Terminal
2. Ubah direktori ke lokasi file C

   cd _direktori file c_
3. Kompilasi kode program

   gcc 2208107010030_Simple_Sorting -o _nama_program_
4. Jalankan program
   
   ./_nama_program_
5. Program berhasil dijalankan

## Fungsi dalam Program
1. bubbleSort(int arr[], int n)

   Fungsi ini digunakan untuk mengurutkan array arr dengan ukuran n menggunakan algoritma bubble ort.
2. selectionSort(int arr[], int n)

   Fungsi ini digunakan untuk mengurutkan array arr dengan ukuran n menggunakan algoritma selection sort.
3. insertionSort(int arr[], int n)

   Fungsi ini digunakan untuk mengurutkan array arr dengan ukuran n menggunakan algoritma insertion sort.
4. saveToFile(char *filename, int arr[], int n, char *title)

   Fungsi ini digunakan untuk menyimpan array arr dengan dengan jumlah bilangan n dan judul title ke dalam file filename.
5. main()

    Merupakan fungsi utama yang digunakan untuk membuat tabel yang mempunyai kolom jenis algoritma, jumlah bilangan, dan waktu eksekusi (ms). Fungsi ini juga tempat membuat bilangan acak yang disimpan dalam array arr, dan dalam file filename. Fungsi ini juga memanggil berbagai fungsi algoritma pengurutan untuk mengurutkan array dari 100000 hingga MAX dan menyimpan bilangan terurut ke dalam file filename, juga menampilkan waktu yang dibutuhkan untuk mengurutkan dalam bentuk tabel.
