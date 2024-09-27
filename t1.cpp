#include <iostream>
#include <string>
#include <algorithm> // for using transform
#include <cctype> // for using toupper

using namespace std;

// Deklarasi tiap fungsi tampilan
void scytaleView();
void vigenereCipherView();
void enkripsiModern1View();
void enkripsiModern2View();
void superEnkripsiView();

// Deklarasi tiap fungsi algoritma
string scytaleAlgorithm(int status, int key, string data);
string caesarCipher(int status, string kunci, string data);

int main()
{
    int pilihan;
    do
    {
        system("cls");
        cout << "+==============================+\n";
        cout << "| TUGAS KRIPTOGRAFI KELOMPOK 5 |\n";
        cout << "+==============================+\n";
        cout << "| 1. SCYTALE                   |\n";
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
            scytaleView();
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
void scytaleView()
{
    system("cls");
    int pilihan, kunci;
    string data;

    cout << "+===================+\n";
    cout << "|      SCYTALE      |\n";
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
        cout << "Masukkan kunci enkripsi : ";
        cin >> kunci;
        cout << "\nHasil enkripsi : " << scytaleAlgorithm(pilihan, kunci, data) << endl;
    }
    else if (pilihan == 2)
    {
        cout << "Masukkan data yang ingin di-dekripsi : ";
        getline(cin, data);
        cout << "Masukkan kunci dekripsi : ";
        cin >> kunci;
        cout << "\nHasil dekripsi : " << scytaleAlgorithm(pilihan, kunci, data) << endl;
    }
    else
    {
        cout << "Keluar dari Scytale.\n";
    }
}

void vigenereCipherView()
{
    system("cls");
    int pilihan;
    string data;
    string kunci;

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
        cout << "Masukkan kunci enkripsi : ";
        getline(cin, kunci);

        cout << "\nHasil enkripsi : " << caesarCipher(1, kunci, data) << endl;
    }
    else if (pilihan == 2)
    {
        cout << "Masukkan data yang ingin di-dekripsi : ";
        getline(cin, data);
        cout << "Masukkan kunci dekripsi : ";
        getline(cin, kunci);

        cout << "Hasil dekripsi : " << caesarCipher(2, kunci, data) << endl;
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
        cout << "Hasil dekripsi : " << data << endl;
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
        cout << "Hasil dekripsi : " << data << endl;
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
        cout << "Hasil enkripsi : " << data[10] << endl;
    }
    else if (pilihan == 2)
    {
        cout << "Masukkan data yang ingin di-dekripsi : ";
        getline(cin, data);
        cout << "Hasil dekripsi : " << data << endl;
    }
    else
    {
        cout << "Keluar dari Super Enkripsi.\n";
    }
}
/*-------------------- Akhir Fungsi Untuk Tampilan --------------------*/

/*-------------------- Awal Fungsi Untuk Algoritma  --------------------*/
string scytaleAlgorithm(int status, int key, string data)
{
    string value = "";
    int baris = data.length() % key != 0 ? (data.length() / key) + 1 : data.length() / key;
    int index = 0;

    if (key > data.length())
    {
        cout << "Panjang key harus kurang dari jumlah karakter data!";
        return "ERROR!!!";
    }

    if (status == 1) // STATUS UNTUK ENKRIPSI DATA (PPT 3 PAGE 31) => KALO BINGUNG, COMMENT COUTNYA DIBUKA AJA
    {
        string arrayData[baris][key];
        for (int i = 0; i < baris; i++)
        {
            for (int j = 0; j < key; j++)
            {
                arrayData[i][j] = index < data.length() ? data[index] : ' ';
                // cout << arrayData[i][j];
                index++;
            }
            // cout << "|\n";
        }

        for (int i = 0; i < key; i++) // PROSES ENKRIPSINYA
        {
            for (int j = 0; j < baris; j++)
            {
                value = value + (arrayData[j][i]);
            }
        }
    }
    else // STATUS UNTUK DEKRIPSI DATA
    {
        string arrayData[key][baris]; // BUAT RUMUSNYA (PPT 3 PAGE 32) => KALO BINGUNG, COMMENT COUTNYA DIBUKA AJA
        for (int i = 0; i < key; i++)
        {
            for (int j = 0; j < baris; j++)
            {
                arrayData[i][j] = data[index];
                // cout << arrayData[i][j];
                index++;
            }
            // cout << "|\n";
        }

        for (int i = 0; i < baris; i++) // PROSES DEKRIPSINYA
        {
            for (int j = 0; j < key; j++)
            {
                value = value + arrayData[j][i];
            }
        }
    }
    return value;
}

string caesarCipher(int status, string kunci, string data)
{
    if(kunci.length() > data.length())
    {
        cout << "Panjang key harus kurang dari jumlah karakter data!";
        return "ERROR!!!";
    }

    string value = "";
    int indexKey = 0;
    int awal = 65;
    
    transform(data.begin(), data.end(), data.begin(), ::toupper);
    transform(kunci.begin(), kunci.end(), kunci.begin(), ::toupper);
    int lengthKey = kunci.length();

    if(status == 1)
    {
        for(int i = 0; i < data.length(); i++)
        {
            if(data[i] == ' ')
            {
                value = value + ' ';
                continue;
            }
            indexKey = indexKey == lengthKey ? 0 : indexKey;
            value = value + char((((int(data[i]) - awal) + (int(kunci[indexKey]) - awal)) % 26) + awal);
            indexKey++;
        }
    }else
    {
        for(int i = 0; i < data.length(); i++)
        {
            if(data[i] == ' ')
            {
                value = value + ' ';
                continue;
            }
            indexKey = indexKey == lengthKey ? 0 : indexKey;
            value = value + char(
                (
                    (
                        (int(data[i]) - awal) + (int(kunci[indexKey]) - awal) > 26 ? abs((int(data[i]) - awal) + (int(kunci[indexKey]) - awal)) : (int(data[i]) - awal) + (int(kunci[indexKey]) - awal)
                    ) % 26 
                ) + awal
            );
            indexKey++;
        }
    }
    return value;
}
/*-------------------- Akhir Fungsi Untuk Algoritma  --------------------*/