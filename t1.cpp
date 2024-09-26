#include <iostream>

using namespace std;

int main()
{
    int pilihan;
    do
    {
        system("cls");
        cout << "+=========================+\n";
        cout << "| 1. Cipher Subtitusi     |\n";
        cout << "| 2. Vigenere Cipher      |\n";
        cout << "| 3. Enkripsi Modern 1    |\n";
        cout << "| 4. Enkripsi Modern 2    |\n";
        cout << "| 5. Super Enkripsi       |\n";
        cout << "+=========================+\n";
        cout << "  Pilih Menu : ";
        cin >> pilihan;
        system("cls");
        if (pilihan == 1)
        {
            cout << "Anda memilih Cipher Subtitusi\n";
            system("pause");
        }
        else if (pilihan == 2)
        {
            cout << "Anda memilih Vigenere Cipher\n";
            system("pause");
        }
        else if (pilihan == 3)
        {
            cout << "Anda memilih Enkripsi Modern 1\n";
            system("pause");
        }
        else if (pilihan == 4)
        {
            cout << "Anda memilih Enkripsi Modern 2\n";
            system("pause");
        }
        else if (pilihan == 5)
        {
            cout << "Anda memilih Super Enkripsi\n";
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