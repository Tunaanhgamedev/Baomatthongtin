#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

int main()
{
    // 1. Nhap ban ro va so cot
    cout << "Nhap chuoi ban ro: ";
    string plaintext;
    getline(cin, plaintext);

    cout << "Nhap so cot: ";
    int cols;
    cin >> cols;

    // 2. Tinh so hang
    int len = plaintext.size();
    int rows = (len + cols - 1) / cols;

    // 3. Tao ma tran rong
    vector<vector<char>> matrix(rows, vector<char>(cols, 'X'));

    // 4. Dien chuoi
    int index = 0;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (index < len)
            {
                matrix[i][j] = plaintext[index++];
            }
        }
    }

    // 5. In ma tran
    cout << "Ma tran ban ro:\n";
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << setw(3) << matrix[i][j];
        }
        cout << "\n";
    }

    // 6. sap xep ma tran
    string ciphertext = "";
    for (int j = 0; j < cols; j++)
    {
        for (int i = 0; i < rows; i++)
        {
            if (matrix[i][j] != '*')
            {
                ciphertext.push_back(matrix[i][j]);
            }
        }
    }

    cout << "Ban ma: " << ciphertext << endl;
    return 0;
}
