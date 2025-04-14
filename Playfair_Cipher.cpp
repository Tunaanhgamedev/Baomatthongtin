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
string CreateMatrixKey(string key)
{
    string MatrixKey;
    int flag[26];
    for (int i = 0; i < 26; i++)
    {
        flag[i] = 0;
    }
    for (char c : key)
    {
        int p = position(c);
        if (!flag[p])
        {
            MatrixKey += c;
            flag[p] = 1;
        }
    }
    if (flag[position('i')])
        flag[position('j')] = 1;
    else if (flag[position('j')])
        flag[position('i')] = 1;
    else
        flag[position('j')] = 1;
    for (int i = 0; i < 26; i++)
    {
        if (flag[i] == 0)
        {
            MatrixKey += alphabet[i];
        }
    }
    return MatrixKey;
}
string Split(string input)
{
    string plaintext = "";
    int len = input.length();
    int i = 0;
    while (i < len)
    {
        if (input[i] == input[i + 1])
        {
            plaintext += input[i];
            plaintext += 'x';
            i += 1;
        }
        else
        {
            plaintext += input[i];
            if (i + 1 < len)
            {
                plaintext += input[i + 1];
            }
            i += 2;
        }
    }
    if (plaintext.length() % 2)
        plaintext += 'x';
    return plaintext;
}

int *CreateIndex(string matrixKey)
{
    int *index = new int[26];
    for (int i = 0; i < 25; i++)
    {
        int pos = position(matrixKey[i]);
        index[pos] = i;
    }
    index[position('j')] = index[position('i')];
    return index;
}

string PlayfairEncryption(string input, string key)
{
    string plaintext = Split(input);
    cout << "\nPlaintext after Split: " << plaintext << " " << plaintext.length();
    string ciphertext = "";
    string matrixKey = CreateMatrixKey(key);
    int *index = CreateIndex(matrixKey);
    for (int i = 0; i <= input.length(); i += 2)
    {
        int p1 = index[position(plaintext[i])];
        int p2 = index[position(plaintext[i + 1])];
        int row1 = p1 / 5, col1 = p1 % 5;
        int row2 = p2 / 5, col2 = p2 % 5;
        int c1, c2;
        if (row1 == row2)
        {
            col1 = (col1 + 1) % 5;
            col2 = (col2 + 1) % 5;
            c1 = row1 * 5 + col1;
            c2 = row2 * 5 + col2;
        }
        else if (col1 == col2)
        {
            row1 = (row1 + 1) % 5;
            row2 = (row2 + 1) % 5;
            c1 = row1 * 5 + col1;
            c2 = row2 * 5 + col2;
        }
        else
        {
            c1 = row1 * 5 + col2;
            c2 = row2 * 5 + col1;
        }
        ciphertext += matrixKey[c1];
        ciphertext += matrixKey[c2];
    }
    return ciphertext;
}
string PlayfairDecryption(string input, string key)
{
    string plaintext = "";
    string matrixKey = CreateMatrixKey(key);
    int *index = CreateIndex(matrixKey);
    for (int i = 0; i < input.length(); i += 2)
    {
        int p1 = index[position(input[i])];
        int p2 = index[position(input[i + 1])];
        int row1 = p1 / 5, col1 = p1 % 5;
        int row2 = p2 / 5, col2 = p2 % 5;
        int c1, c2;
        if (row1 == row2)
        {
            col1 = (col1 - 1 + 5) % 5;
            col2 = (col2 - 1 + 5) % 5;
            c1 = row1 * 5 + col1;
            c2 = row2 * 5 + col2;
        }
        else if (col1 == col2)
        {
            row1 = (row1 - 1 + 5) % 5;
            row2 = (row2 - 1 + 5) % 5;
            c1 = row1 * 5 + col1;
            c2 = row2 * 5 + col2;
        }
        else
        {
            c1 = row1 * 5 + col2;
            c2 = row2 * 5 + col1;
        }
        plaintext += matrixKey[c1];
        plaintext += matrixKey[c2];
    }
    return plaintext;
}
int main()
{
    string key;
    cout << "key = ";
    cin >> key;
    string plaintext;
    cout << "plaintext: ";
    cin >> plaintext;
    cout << "\nkey: " << key << " " << key.length();
    cout << "\nplaintext: " << plaintext << " " << plaintext.length();
    cout << "\nmatrixKey: " << CreateMatrixKey(key);
    string cipher = PlayfairEncryption(plaintext, key);
    cout << "\nCiphertext: " << cipher << " " << cipher.length();
    cout << "\nDecrypting: " << PlayfairDecryption(cipher, key) << " " << PlayfairDecryption(cipher, key).length();
}