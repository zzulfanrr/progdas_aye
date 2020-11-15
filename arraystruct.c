#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    system("clear");
    int i, jumlah_mahasiswa, menu;
    printf("===============================================================================\n");
    printf("===============================================================================\n");
    printf("===============================================================================\n");
    printf("*******************************************************************************\n");
    printf("*******************************************************************************\n");
    printf("******        ****               ****          ****               ****   ******\n");
    printf("******         *********   **********   *****************   **********   ******\n");
    printf("******   ***    ********   **********   *****************   **********   ******\n");
    printf("******   *  *   ********   **********          **********   **********   ******\n");
    printf("******   ***    ********   **********   *****************   **********   ******\n");
    printf("******         *********   **********   *****************   **********   ******\n");
    printf("******        **********   **********          **********   **********   ******\n");
    printf("*******************************************************************************\n");
    printf("*******************************************************************************\n");
    printf("===============================================================================\n");
    printf("============ APLIKASI PENDATAAN DATA MAHASISWA DAN MATA KULIAH ================\n");
    printf("===============================================================================\n");
    printf("Pilihan Menu :\n");
    printf("1.Pendataan Mahasiswa\n");
    printf("2.Pendataan Matakuliah\n");
    printf("0.Keluar dari Program\n");
    printf("Pilih Menu...\n");
    scanf("%d", &menu);
    if(menu == 1)
    {
        system("clear");
        printf("Masukkan banyak mahasiswa \n");
        scanf("%d", &jumlah_mahasiswa);
        struct
        {
            char nama[255];
            char alamat[255];
            char program_studi[255];
            unsigned int umur;
        }mahasiswa[jumlah_mahasiswa];

        for (i = 0; i < jumlah_mahasiswa; i++)
        {
            printf("DATA KE-%d \n", i+1);
            printf("Masukkan Nama ");
            scanf("%s", &mahasiswa[i].nama);
            printf("Masukkan Alamat ");
            scanf("%s", &mahasiswa[i].alamat);
            printf("Masukkan Prodi ");
            scanf("%s", &mahasiswa[i].program_studi);
            printf("Masukkan Umur ");
            scanf("%d", &mahasiswa[i].umur);
        }
        system("clear");
        printf("------------------------------------------------------------\n");
        printf("| NO |NAMA MAHASISWA|       ALAMAT      |PROGRAM STUDI|UMUR|\n");
        printf("------------------------------------------------------------\n");
        for (i = 0; i < jumlah_mahasiswa; i++)
        {
            printf("| %d  |%-14s|%-19s|%-13s|%-4d|\n", i+1, mahasiswa[i].nama, mahasiswa[i].alamat, mahasiswa[i].program_studi, mahasiswa[i].umur);
        }

        FILE *penunjuk_file;
        penunjuk_file = fopen("data.txt", "w");

        if (penunjuk_file == NULL)
        {
            printf("file tidak ada!!! \n");
            exit(1);
        }
        fputs("------------------------------------------------------------\n", penunjuk_file);
        fputs("| NO |NAMA MAHASISWA|       ALAMAT      |PROGRAM STUDI|UMUR|\n", penunjuk_file);
        fputs("------------------------------------------------------------\n", penunjuk_file);
        for(i = 0; i < jumlah_mahasiswa; i++)
        {
            //char raw_data[255];
            //int data = sprintf(raw_data, "| %d  |%-14s|%-19s|%-13s|%-4d|\n", i+1, mahasiswa[i].nama, mahasiswa[i].alamat, mahasiswa[i].program_studi, mahasiswa[i].umur);
            //fwrite(data, penunjuk_file);
            fprintf(penunjuk_file, "| %d  |%-14s|%-19s|%-13s|%-4d|\n", i+1, mahasiswa[i].nama, mahasiswa[i].alamat, mahasiswa[i].program_studi, mahasiswa[i].umur);
        }
        fputs("------------------------------------------------------------\n", penunjuk_file);
        printf("\nDATA BERHASIL DISIMPAN PADA data.txt");
        fclose(penunjuk_file);
    }
    else if(menu == 2)
    {
        printf("Program untuk menghitung matkul");
    }
    else
    {
        exit(0);
    }
    
    
    return 0;
}