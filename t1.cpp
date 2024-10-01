#include <iostream>
#include <string>
#include <algorithm> // for using transform
#include <cctype>    // for using toupper
#include <bitset>    // for convert to biner
#include <cmath>
#include <iomanip> // Untuk setfill dan setw

using namespace std;

string DATACHAR = "0123456789 abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

// Deklarasi tiap fungsi tampilan
void scytaleView();
void vigenereCipherView();
void vernamCipherView();
void sraCipherView();
void superEnkripsiView();

// Deklarasi tiap fungsi algoritma
string scytaleAlgorithm(int status, int key, string data);
string caesarCipher(int status, string kunci, string data);
string vernamCipher(string data, string key);
string generateRandomKey(int length);
int gcd(int a, int b);
long long modExp(long long base, long long exp, long long mod);
long long encryptChar(char ch, long long e, long long n);
char decryptChar(long long cipher, long long d, long long n);
string sraEncryptAlgorithm(string data, int e, int n);

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
        cout << "| 3. VERNAM Cipher             |\n";
        cout << "| 4. SRA Cipher                |\n";
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
            sraCipherView();
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

void vernamCipherView()
{
    system("cls");
    int pilihan;
    string data;
    string kunci;

    cout << "+=====================+\n";
    cout << "|    VERNAM CIPHER    |\n";
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
        kunci = generateRandomKey(data.length());

        cout << "Kunci hasil genarate : " << kunci << endl;
        cout << "Hasil enkripsi : " << vernamCipher(data, kunci) << endl;
    }
    else if (pilihan == 2)
    {
        cout << "Masukkan data yang ingin di-dekripsi : ";
        getline(cin, data);
        cout << "Masukkan kunci dekripsi : ";
        getline(cin, kunci);

        cout << "Hasil dekripsi : " << vernamCipher(data, kunci) << endl;
    }
    else
    {
        cout << "Keluar dari Vernam Cipher.\n";
    }
}

void sraCipherView()
{
    system("cls");
    int pilihan;
    int prima1, prima2;
    string data;

    cout << "+=====================+\n";
    cout << "|         SRA         |\n";
    cout << "+=====================+\n";
    cout << "| 1. Enkripsi Data    |\n";
    cout << "| 2. Dekripsi Data    |\n";
    cout << "+=====================+\n";
    cout << "  Pilih Menu : ";
    cin >> pilihan;
    system("cls");

    if (pilihan == 1)
    {
        cout << "Masukkan bilangan prima p: ";
        cin >> prima1;
        cout << "Masukkan bilangan prima q: ";
        cin >> prima2;
        cin.ignore();

        // Langkah 2: Hitung n dan phi(n)
        long long n = prima1 * prima2;

        // 3. Hitung totient: φ(n) = (p-1)*(q-1)
        long long phi = (prima1 - 1) * (prima2 - 1);

        // 4. Pilih e (public key) yang relatif prima dengan φ(n)
        long long e = 17; // Public key
        // Pastikan gcd(e, phi) = 1
        while (gcd(e, phi) != 1)
        {
            e++;
        }

        // 5. Hitung d (private key) dengan d ≡ e^(-1) mod φ(n)
        long long d = 0;
        long long k = 1;
        // Temukan d sedemikian rupa sehingga (d * e) % phi == 1
        while ((1 + k * phi) % e != 0)
        {
            k++;
        }
        d = (1 + k * phi) / e;

        cout << "Public Key (e, n): (" << e << ", " << n << ")\n";
        cout << "Private Key (d, n): (" << d << ", " << n << ")\n";

        // Input pesan yang ingin dienkripsi
        string message;
        cout << "Masukkan pesan: ";
        getline(cin, message);

        // Enkripsi setiap karakter dalam pesan
        cout << "Hasil Enkripsi: " << sraEncryptAlgorithm(message, e, n);
        cout << endl;
    }
    else if (pilihan == 2)
    {
        int n, d, blockCount;
        cout << "Masukkan nilai n dan d untuk proses dekripsi." << endl;
        cout << "Masukkan nilai n: ";
        cin >> n;
        cin.ignore();
        cout << "Masukkan nilai d: ";
        cin >> d;
        cin.ignore();
        cout << "Masukkan total block: ";
        cin >> blockCount;
        cin.ignore();

        cout << "Masukkan cipherteks untuk didekripsi (masukkan blok-blok angka): " << endl;
        int cipherBlock; // Menyimpan hasil dekripsi
        string decryptedMessage = "";
        for (int i = 0; i < blockCount; i++)
        {
            cin >> cipherBlock;
            decryptedMessage += decryptChar(cipherBlock, d, n); // Dekripsi
        }
        cout << endl;

        // Konversi angka hasil dekripsi menjadi string
        cout << "Pesan setelah dekripsi: " << decryptedMessage << endl;
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
        int scytaleKey, prima1, prima2;
        string caesarKey, vernamKey;

        cout << "Masukkan data yang ingin di-enkripsi : ";
        getline(cin, data);

        cout << "Masukkan kunci scytale : ";
        cin >> scytaleKey;
        cin.ignore();
        data = scytaleAlgorithm(1, scytaleKey, data);

        cout << "Masukkan kunci caesar : ";
        getline(cin, caesarKey);
        data = caesarCipher(1, caesarKey, data);

        vernamKey = generateRandomKey(data.length());
        cout << "Vernam key = " << vernamKey << endl;
        data = vernamCipher(vernamKey, data);

        // Mulai SRA
        cout << "Masukkan bilangan prima p: ";
        cin >> prima1;
        cout << "Masukkan bilangan prima q: ";
        cin >> prima2;
        cin.ignore();

        // Langkah 2: Hitung n dan phi(n)
        long long n = prima1 * prima2;

        // 3. Hitung totient: φ(n) = (p-1)*(q-1)
        long long phi = (prima1 - 1) * (prima2 - 1);

        // 4. Pilih e (public key) yang relatif prima dengan φ(n)
        long long e = 17; // Public key
        // Pastikan gcd(e, phi) = 1
        while (gcd(e, phi) != 1)
        {
            e++;
        }

        // 5. Hitung d (private key) dengan d ≡ e^(-1) mod φ(n)
        long long d = 0;
        long long k = 1;
        // Temukan d sedemikian rupa sehingga (d * e) % phi == 1
        while ((1 + k * phi) % e != 0)
        {
            k++;
        }
        d = (1 + k * phi) / e;

        cout << "Public Key (e, n): (" << e << ", " << n << ")\n";
        cout << "Private Key (d, n): (" << d << ", " << n << ")\n";
        data = sraEncryptAlgorithm(data, e, n);

        cout << "\nHasil enkripsi : " << data << endl;
    }
    else if (pilihan == 2)
    {
        int n, d, blockCount;
        string vernamKey, caesarKey;
        int scytaleKey;

        cout << "Masukkan nilai n dan d untuk proses dekripsi." << endl;
        cout << "Masukkan nilai n: ";
        cin >> n;
        cin.ignore();
        cout << "Masukkan nilai d: ";
        cin >> d;
        cin.ignore();
        cout << "Masukkan total block: ";
        cin >> blockCount;
        cin.ignore();

        cout << "Masukkan cipherteks untuk didekripsi (masukkan blok-blok angka): " << endl;
        int cipherBlock;
        for (int i = 0; i < blockCount; i++)
        {
            cin >> cipherBlock;
            data += decryptChar(cipherBlock, d, n); // Dekripsi
        }
        cin.ignore();

        cout << "Masukkan kunci vernam = ";
        getline(cin, vernamKey);
        data = vernamCipher(data, vernamKey);

        cout << "Masukkan kunci caesar = ";
        getline(cin, caesarKey);
        data = caesarCipher(2, caesarKey, data);

        cout << "Masukkan kunci scytale = ";
        cin >> scytaleKey;
        data = scytaleAlgorithm(2, scytaleKey, data);

        cout << "\nHasil dekripsi : " << data << endl;
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
    if (kunci.length() > data.length())
    {
        cout << "Panjang key harus kurang dari jumlah karakter data!";
        return "ERROR!!!";
    }

    string value = "";
    int indexKey = 0;
    int awalBesar = 65;
    int awalKecil = 97;
    int awal;

    // transform(data.begin(), data.end(), data.begin(), ::toupper);
    transform(kunci.begin(), kunci.end(), kunci.begin(), ::toupper);
    int lengthKey = kunci.length();

    if (status == 1)
    {
        for (int i = 0; i < data.length(); i++)
        {
            if (data[i] == ' ')
            {
                value = value + ' ';
                continue;
            }
            indexKey = indexKey == lengthKey ? 0 : indexKey;
            awal = isupper(data[i]) ? awalBesar : awalKecil;

            value = value + char((((int(data[i]) - awal) + (int(kunci[indexKey]) - awalBesar)) % 26) + awal);
            indexKey++;
        }
    }
    else
    {
        for (int i = 0; i < data.length(); i++)
        {
            if (data[i] == ' ')
            {
                value = value + ' ';
                continue;
            }
            indexKey = indexKey == lengthKey ? 0 : indexKey;
            awal = isupper(data[i]) ? awalBesar : awalKecil;

            value = value + char(((int(data[i]) - awal) - (int(kunci[indexKey]) - awalBesar) + 26) % 26 + awal);
            indexKey++;
        }
    }
    return value;
}

string generateRandomKey(int length)
{
    string key = "";
    for (int i = 0; i < length; i++)
    {
        if (rand() % 2) // Jika angka 1
        {
            key += 'A' + rand() % 26; // Menghasilkan huruf kapital antara 'A' dan 'Z'
        }
        else
        {
            key += 'a' + rand() % 26; // Menghasilkan huruf kecil antara 'a' dan 'z'
        }
    }

    return key;
}

string vernamCipher(string data, string key)
{
    string value = "";

    // int indexChar;
    if (data.length() != key.length())
    {
        cout << "Panjang data dengan panjang kunci tidak sama, mohon cek kembali.\n";
        return "";
    }
    else if (data.empty())
    {
        cout << "Data tidak boleh kosong.\n";
        return "";
    }

    for (int i = 0; i < data.length(); i++)
    {
        value += DATACHAR[DATACHAR.find(data[i]) ^ DATACHAR.find(key[i])];
    }
    return value;
}

// SRA FUNCTION
// Fungsi untuk menghitung GCD (Greatest Common Divisor)
int gcd(int a, int h)
{
    while (1)
    {
        int temp = a % h;
        if (temp == 0)
            return h;
        a = h;
        h = temp;
    }
}

// Fungsi untuk melakukan eksponen modular
long long modExp(long long base, long long exp, long long mod)
{
    long long result = 1;
    while (exp > 0)
    {
        if (exp % 2 == 1) // Jika eksponen ganjil
            result = (result * base) % mod;
        base = (base * base) % mod;
        exp = exp / 2;
    }
    return result;
}

// Fungsi untuk mengenkripsi pesan
long long encryptChar(char ch, long long e, long long n)
{
    long long m = (int)ch;  // Konversi karakter menjadi ASCII
    return modExp(m, e, n); // Enkripsi: c = (m^e) % n
}

// Fungsi untuk mendekripsi pesan
char decryptChar(long long cipher, long long d, long long n)
{
    long long m = modExp(cipher, d, n); // Dekripsi: m = (c^d) % n
    return (char)m;                     // Konversi angka kembali ke karakter
}

string sraEncryptAlgorithm(string data, int e, int n)
{
    string value = "";
    for (int i = 0; i < data.length(); i++)
    {
        value += to_string(encryptChar(data[i], e, n));
        value += " ";
    }
    return value;
}
/*-------------------- Akhir Fungsi Untuk Algoritma  --------------------*/