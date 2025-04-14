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
string VigenereEncryption(string plaintext, string key)
{
    string cipher;
    int p, k, c;
    int m = key.length();
    for (int i = 0; i < plaintext.length(); i++)
    {
        p = position(plaintext[i]);
        k = position(key[i % m]);
        c = (p + k) % 26;
        cipher += alphabet[c];
    }
    return cipher;
}
string VigenereDecryption(string ciphertext, string key)
{
    string plaintext;
    int p, k, c;
    int m = key.length();
    for (int i = 0; i < ciphertext.length(); i++)
    {
        c = position(ciphertext[i]);
        k = position(key[i % m]);
        p = (c - k + 26) % 26;
        plaintext += alphabet[p];
    }
    return plaintext;
}
int main()
{
    string plaintext;
    cout << "plaintext: ";
    cin >> plaintext;
    string key;
    cout << "key = ";
    cin >> key;
    cout << "\nplaintext: " << plaintext << " " << plaintext.length();
    cout << "\nkey: " << key << " " << key.length();
    string cipher = VigenereEncryption(plaintext, key);
    cout << "\nCiphertext: " << cipher << " " << cipher.length();
    cout << "\nDecryptino: " << VigenereDecryption(cipher, key);
}