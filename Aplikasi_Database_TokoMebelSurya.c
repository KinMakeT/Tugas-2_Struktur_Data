#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Barang
{
    char kode[10];
    char nama_barang[50];
    char bahan[50];
    int jml;
    float harga;

};

void input_stock(struct Barang **inventory, int *n)
{
    printf("\n\t\t\t ... INPUT BARANG ... \n");

    printf("Banyaknya barang yang akan anda masukkan : ");
    int add_items;
    scanf("%d", &add_items);

    // Mengalokasikan memori untuk array yang baru
    struct Barang *temp = realloc(*inventory, (*n + add_items) * sizeof(struct Barang));
    if (temp == NULL)
    {
        printf("Error dalam alokasi memori\n");
        return;
    }
    *inventory = temp;

    // Memasukkan data barang baru
    for (int i = *n; i < *n + add_items; i++)
    {
        printf(":: Kode Barang          : [%d] : ", i + 1);
        scanf("%s", (*inventory)[i].kode);
        printf(":: Nama Barang          : [%d] : ", i + 1);
        scanf("%s", (*inventory)[i].nama_barang);
        printf(":: Bahan Dasar          : [%d] : ", i + 1);
        scanf("%s", (*inventory)[i].bahan);
        printf(":: Jumlah               : [%d] : ", i + 1);
        scanf("%d", &(*inventory)[i].jml);
        printf(":: Harga Per Unit       : [%d] : ", i + 1);
        scanf("%f", &(*inventory)[i].harga);

        printf("\n");
    }

    printf("Data berhasil dimasukan :)");

    // Memperbarui jumlah barang
    *n += add_items;

    printf("\n");
}

void view_stock(struct Barang *inventory, int n)
{
    if (n == 0)
    {
        printf("Data barang kosong.\n");
        return;
    }

    printf("\t\t\t ... PERSEDIAAN BARANG ...\n");

    printf("\n===================================================================================\n");
    printf("|| %-3s | %-12s | %-11s | %-11s | %-6s | %-12s ||\n", "Data Ke-", "Kode Barang", "Nama Barang", "Bahan Dasar", "Jumlah", "Harga Per Unit");
    printf("===================================================================================\n");

    for (int i = 0; i < n; i++)
    {
        printf("|| %-8d | %-12s | %-11s | %-11s | %-6d | Rp %-12.2f ||\n", i + 1, inventory[i].kode, inventory[i].nama_barang, inventory[i].bahan, inventory[i].jml, inventory[i].harga);
    }

    printf("=================================================================================\n");
}

void main()
{
    // inisiasi variable yang akan digunakan nanti
    int pil;
    int n = 0;
    struct Barang *iventory = NULL;

do
{
    // Program menu
    printf("\n +------------------------------------------------------------------------------+\n");
        printf("\n\t\t\t       DATABASE TOKO MEBEL SURYA \n");
        printf("\n +------------------------------------------------------------------------------+\n");
        printf(" |                      1. Input Barang                                         |\n");
        printf(" |                      2. Lihat Stock Barang                                   |\n");
        printf(" |                      3. Exit                                                 |\n");
        printf(" |                                                                              |\n");
        printf(" |                    Created by I Putu Prabha Nugraha                          |\n");
        printf(" |                                                                              |\n");
        printf(" |                   Pilih [1, 2, 3] : ");
        scanf("%d", &pil);
        printf(" |                                                                              |\n");
        printf(" |                                                                              |\n");
        printf(" ********************************************************************************\n");

        // yang ditentukan oleh input user
        switch (pil)
        {
        case 1:
            system("cls");
            input_stock(&iventory, &n); 
            break;

        case 2:
            system("cls");
            view_stock(iventory, n);
            break;

        case 3:
            printf("Terimakasih telah menggunakan aplikasi ini");
            break;
        
        default:
            system("cls");
            printf("Mohon masukan sesuai pilihan yang tesedia");
            break;
        }

} while (pil != 3);

 // membersihkan memori sebelum keluar dari program
    free(iventory);

}