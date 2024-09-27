#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    int a = (0 + 20) % 26;
    cout << a << endl;

    a = abs(20 - 20) % 26;
    cout << a << endl;
    return 0;
}
