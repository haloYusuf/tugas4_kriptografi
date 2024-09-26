#include <iostream>

using namespace std;

// Deklarasi tiap fungsi
void cipherSubtitusiView();
void vigenereCipherView();
void enkripsiModern1View();
void enkripsiModern2View();
void superEnkripsiView();

int main()
{
    int pilihan;
    do
    {
        system("cls");
        cout << "+==============================+\n";
        cout << "| TUGAS KRIPTOGRAFI KELOMPOK 5 |\n";
        cout << "+==============================+\n";
        cout << "| 1. Cipher Subtitusi          |\n";
        cout << "| 2. Vigenere Cipher           |\n";
        cout << "| 3. Enkripsi Modern 1         |\n";
        cout << "| 4. Enkripsi Modern 2         |\n";
        cout << "| 5. Super Enkripsi            |\n";
        cout << "+==============================+\n";

        cout << "  Pilih Menu : ";
        cin >> pilihan;
        system("cls");

        if (pilihan == 1)
        {
            cipherSubtitusiView();
            system("pause");
        }
        else if (pilihan == 2)
        {
            vigenereCipherView();
            system("pause");
        }
        else if (pilihan == 3)
        {
            enkripsiModern1View();
            system("pause");
        }
        else if (pilihan == 4)
        {
            enkripsiModern2View();
            system("pause");
        }
        else if (pilihan == 5)
        {
            superEnkripsiView();
            system("pause");
        }
        else
        {
            cout << "Thanks You ...\n";
            system("pause");
            break;
        }
    } while (true);
}

/*-------------------- Awal Fungsi Untuk Tampilan --------------------*/

void cipherSubtitusiView()
{
    system("cls");
    int pilihan;
    string data;

    cout << "+==================+\n";
    cout << "| CIPHER SUBTITUSI |\n";
    cout << "+==================+\n";
    cout << "| 1. Enkripsi Data |\n";
    cout << "| 2. Dekripsi Data |\n";
    cout << "+==================+\n";
    cout << "  Pilih Menu : ";
    cin >> pilihan;
    cin.ignore();
    system("cls");

    if (pilihan == 1)
    {
        cout << "Masukkan data yang ingin di-enkripsi : ";
        getline(cin, data);
        cout << "Hasil enkripsi : " << data << endl;
    }
    else if (pilihan == 2)
    {
        cout << "Masukkan data yang ingin di-dekripsi : ";
        getline(cin, data);
        cout << "Hasil enkripsi : " << data << endl;
    }
    else
    {
        cout << "Keluar dari Cipher Subtitusi.\n";
    }
}

void vigenereCipherView()
{
    system("cls");
    int pilihan;
    string data;

    cout << "+===================+\n";
    cout << "|  VIGENERE CIPHER  |\n";
    cout << "+===================+\n";
    cout << "| 1. Enkripsi Data  |\n";
    cout << "| 2. Dekripsi Data  |\n";
    cout << "+===================+\n";
    cout << "  Pilih Menu : ";
    cin >> pilihan;
    cin.ignore();
    system("cls");

    if (pilihan == 1)
    {
        cout << "Masukkan data yang ingin di-enkripsi : ";
        getline(cin, data);
        cout << "Hasil enkripsi : " << data << endl;
    }
    else if (pilihan == 2)
    {
        cout << "Masukkan data yang ingin di-dekripsi : ";
        getline(cin, data);
        cout << "Hasil enkripsi : " << data << endl;
    }
    else
    {
        cout << "Keluar dari Vigenere Cipher.\n";
    }
}

void enkripsiModern1View()
{
    system("cls");
    int pilihan;
    string data;

    cout << "+=====================+\n";
    cout << "|  ENKRIPSI MODERN 1  |\n";
    cout << "+=====================+\n";
    cout << "| 1. Enkripsi Data    |\n";
    cout << "| 2. Dekripsi Data    |\n";
    cout << "+=====================+\n";
    cout << "  Pilih Menu : ";
    cin >> pilihan;
    cin.ignore();
    system("cls");

    if (pilihan == 1)
    {
        cout << "Masukkan data yang ingin di-enkripsi : ";
        getline(cin, data);
        cout << "Hasil enkripsi : " << data << endl;
    }
    else if (pilihan == 2)
    {
        cout << "Masukkan data yang ingin di-dekripsi : ";
        getline(cin, data);
        cout << "Hasil enkripsi : " << data << endl;
    }
    else
    {
        cout << "Keluar dari Vigenere Cipher.\n";
    }
}

void enkripsiModern2View()
{
    system("cls");
    int pilihan;
    string data;

    cout << "+=====================+\n";
    cout << "|  ENKRIPSI MODERN 2  |\n";
    cout << "+=====================+\n";
    cout << "| 1. Enkripsi Data    |\n";
    cout << "| 2. Dekripsi Data    |\n";
    cout << "+=====================+\n";
    cout << "  Pilih Menu : ";
    cin >> pilihan;
    cin.ignore();
    system("cls");

    if (pilihan == 1)
    {
        cout << "Masukkan data yang ingin di-enkripsi : ";
        getline(cin, data);
        cout << "Hasil enkripsi : " << data << endl;
    }
    else if (pilihan == 2)
    {
        cout << "Masukkan data yang ingin di-dekripsi : ";
        getline(cin, data);
        cout << "Hasil enkripsi : " << data << endl;
    }
    else
    {
        cout << "Keluar dari Vigenere Cipher.\n";
    }
}

void superEnkripsiView()
{
    system("cls");
    int pilihan;
    string data;

    cout << "+==================+\n";
    cout << "|  SUPER ENKRIPSI  |\n";
    cout << "+==================+\n";
    cout << "| 1. Enkripsi Data |\n";
    cout << "| 2. Dekripsi Data |\n";
    cout << "+==================+\n";
    cout << "  Pilih Menu : ";
    cin >> pilihan;
    cin.ignore();
    system("cls");

    if (pilihan == 1)
    {
        cout << "Masukkan data yang ingin di-enkripsi : ";
        getline(cin, data);
        cout << "Hasil enkripsi : " << data << endl;
    }
    else if (pilihan == 2)
    {
        cout << "Masukkan data yang ingin di-dekripsi : ";
        getline(cin, data);
        cout << "Hasil enkripsi : " << data << endl;
    }
    else
    {
        cout << "Keluar dari Vigenere Cipher.\n";
    }
}

/*-------------------- Akhir Fungsi Untuk Tampilan --------------------*/

/*-------------------- Awal Fungsi Untuk Algoritma  --------------------*/

/*-------------------- Akhir Fungsi Untuk Algoritma  --------------------*/