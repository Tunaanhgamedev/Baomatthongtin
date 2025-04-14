#include <iostream>

using namespace std;
string alphabet = "abcdefghijklmnopqrstuvwxyz";

int position(char ch)
{
    int p;
    if (ch >= 'a' && ch <= 'z')
    {
        p = ch - 'a';
    }
    else if (ch >= 'A' && ch <= 'Z')
    {
        p = ch - 'A';
    }
    return p;
}
string CeasarEncryption(string input, int k)
{
    string cipher = "";

    // Traverse text
    for (char ch : input)
    {
        int p = position(ch);
        int c = (p + k) % 26;
        cipher += alphabet[c];
    }
    return cipher;
}

string CeasarDecryption(string input, int k)
{
    string plaintext = "";

    // Traverse text
    for (char ch : input)
    {
        int c = position(ch);
        int p = (c - k + 26) % 26;
        plaintext += alphabet[p];
    }
    return plaintext;
}
int main()
{
    string plaintext;
    cout << "plaintext: ";
    cin >> plaintext;
    int k;
    cout << "key = ";
    cin >> k;
    string cipher = CeasarEncryption(plaintext, k);
    cout << "\nCiphertext: " << cipher;
    cout << "\nDecrypting: " << CeasarDecryption(plaintext, k);
}