#include <iostream>
#include <string>
#include <algorithm> // for using transform
#include <cctype>    // for using toupper
#include <vector>
#include <cctype>
#include <ctime>

using namespace std;

void scytaleView();
void vigenereCipherView();
void vernamCipherView();
void enkripsiModern2View();
void superEnkripsiView();

string scytaleAlgorithm(int status, int key, string data);
string caesarCipher(int status, string kunci, string data);
string vernamCipher(int status, string key, string data, vector<int> &spacePositions);
string generateRandomKey(int length);
string removeSpacesAndStorePositions(const string &data, vector<int> &spacePositions);
string addSpacesBack(const string &data, const vector<int> &spacePositions);
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
        cout << "| 2. CAESAR Cipher             |\n";
        cout << "| 3. Vernam Cipher             |\n";
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
            vernamCipherView();
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
    cout << "|   CAESAR CIPHER   |\n";
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

void vernamCipherView() // Change here to match the declaration
{
    system("cls");
    int pilihan;
    string data;
    string key;
    vector<int> spacePositions;

    cout << "+=====================+\n";
    cout << "|  VERNAM CIPHER     |\n"; // Change header to reflect the correct cipher
    cout << "+=====================+\n";
    cout << "| 1. Enkripsi Data   |\n";
    cout << "| 2. Dekripsi Data   |\n";
    cout << "+=====================+\n";
    cout << "  Pilih Menu : ";
    cin >> pilihan;
    cin.ignore();
    system("cls");

    if (pilihan == 1)
    {
        cout << "Masukkan data yang ingin di-enkripsi : ";
        getline(cin, data);
        // Menghapus spasi dan menyimpan posisi
        data = removeSpacesAndStorePositions(data, spacePositions);
        // Menghasilkan kunci acak sesuai panjang data tanpa spasi
        key = generateRandomKey(data.length());
        cout << "Kunci yang dihasilkan: " << key << endl;
        cout << "Hasil enkripsi: " << vernamCipher(1, key, data, spacePositions) << endl;
    }
    else if (pilihan == 2)
    {
        cout << "Masukkan data yang ingin di-dekripsi : ";
        getline(cin, data);
        cout << "Masukkan kunci dekripsi : ";
        getline(cin, key);
        // Memastikan panjang kunci sama dengan data tanpa spasi
        cout << "Hasil dekripsi: " << vernamCipher(2, key, data, spacePositions) << endl;
    }
    else
    {
        cout << "Keluar dari Vernam Cipher.\n";
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
    int lenghtData = data.length();

    if (key > lenghtData)
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
                arrayData[i][j] = index < lenghtData ? data[index] : ' ';
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
    if (kunci.length() > data.length())
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
    int lenghtData = data.length();

    if (status == 1)
    {
        for (int i = 0; i < lenghtData; i++)
        {
            if (data[i] == ' ')
            {
                value = value + ' ';
                continue;
            }
            indexKey = indexKey == lengthKey ? 0 : indexKey;
            value = value + char((((int(data[i]) - awal) + (int(kunci[indexKey]) - awal)) % 26) + awal);
            indexKey++;
        }
    }
    else
    {
        for (int i = 0; i < lenghtData; i++)
        {
            if (data[i] == ' ')
            {
                value = value + ' ';
                continue;
            }
            indexKey = indexKey == lengthKey ? 0 : indexKey;
            value = value + char(
                                (
                                    (
                                        (int(data[i]) - awal) - (int(kunci[indexKey]) - awal) + 26) %
                                    26) +
                                awal);
            indexKey++;
            // value = value + char(
            //     (
            //         (
            //             (int(data[i]) - awal) + (int(kunci[indexKey]) - awal) > 26 ? abs((int(data[i]) - awal) + (int(kunci[indexKey]) - awal)) : (int(data[i]) - awal) + (int(kunci[indexKey]) - awal)
            //         ) % 26
            //     ) + awal
            // );
            // indexKey++;
        }
    }
    return value;
}
string removeSpacesAndStorePositions(const string &data, vector<int> &spacePositions)
{
    string result;
    for (size_t i = 0; i < data.length(); i++)
    {
        if (data[i] == ' ')
        {
            spacePositions.push_back(result.length()); // Simpan posisi spasi
        }
        else
        {
            result += data[i];
        }
    }
    return result;
}

// Fungsi untuk menambahkan kembali spasi
string addSpacesBack(const string &result, const vector<int> &spacePositions)
{
    string finalResult = result;
    for (size_t i = 0; i < spacePositions.size(); i++)
    {
        finalResult.insert(spacePositions[i] + i, " ");
    }
    return finalResult;
}

// Fungsi untuk menghasilkan kunci acak
string generateRandomKey(int length)
{
    string key;
    srand(static_cast<unsigned int>(time(0)));
    for (int i = 0; i < length; i++)
    {
        // Menghasilkan angka acak antara 0 dan 1
        int isUpperCase = rand() % 2; // 0 untuk huruf kecil, 1 untuk huruf kapital
        char randomChar;

        if (isUpperCase)
        {
            randomChar = 'A' + rand() % 26; // Menghasilkan huruf kapital antara 'A' dan 'Z'
        }
        else
        {
            randomChar = 'a' + rand() % 26; // Menghasilkan huruf kecil antara 'a' dan 'z'
        }

        key += randomChar; // Tambahkan karakter acak ke kunci
    }
    return key;
}
string vernamCipher(int status, string key, string data, vector<int> &spacePositions)
{
    string result = "";
    string dataWithoutSpaces;

    if (status == 1)
    { // Untuk Enkripsi
        dataWithoutSpaces = removeSpacesAndStorePositions(data, spacePositions);

        if (key.empty())
        {
            key = generateRandomKey(dataWithoutSpaces.length());
            cout << "Generated Key (Random): " << key << endl;
        }

        if (key.length() != dataWithoutSpaces.length())
        {
            cout << "panjang kunci harus sama dengan data!" << endl;
            return "ERROR!!!";
        }

        for (size_t i = 0; i < dataWithoutSpaces.length(); i++)
        {
            char xorChar = ((tolower(dataWithoutSpaces[i]) - 'a' + (tolower(key[i]) - 'a')) % 26 + 'a'); // Enkripsi
            result += xorChar;
        }
    }
    else if (status == 2)
    { // Untuk Dekripsi
        dataWithoutSpaces = removeSpacesAndStorePositions(data, spacePositions);

        if (key.length() != dataWithoutSpaces.length())
        {
            cout << "panjang kunci harus sama dengan data!" << endl;
            return "ERROR!!!";
        }

        for (size_t i = 0; i < dataWithoutSpaces.length(); i++)
        {
            char xorChar = ((tolower(dataWithoutSpaces[i]) - 'a' - (tolower(key[i]) - 'a') + 26) % 26 + 'a'); // Dekripsi

            if (isupper(dataWithoutSpaces[i]))
            {
                xorChar = toupper(xorChar);
            }
            result += xorChar;
        }
    }

    result = addSpacesBack(result, spacePositions); // Menambahkan kembali spasi ke hasil
    return result;
}
