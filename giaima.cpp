#include <iostream>
#include <cstring>
using namespace std;

// Hàm mã hóa kiểu Caesar Cipher
void maHoaCaesar(char arr[], int k)
{
    for (int i = 0; arr[i] != '\0'; i++)
    {
        if (arr[i] >= 'A' && arr[i] <= 'Z')
        {
            arr[i] = ((arr[i] - 'A' + k) % 26) + 'A';
        }
        else if (arr[i] >= 'a' && arr[i] <= 'z')
        {
            arr[i] = ((arr[i] - 'a' + k) % 26) + 'a';
        }
        // Ký tự khác giữ nguyên
    }
}

// Hàm giải mã Caesar Cipher
void giaiMaCaesar(char arr[], int k)
{
    for (int i = 0; arr[i] != '\0'; i++)
    {
        if (arr[i] >= 'A' && arr[i] <= 'Z')
        {
            arr[i] = ((arr[i] - 'A' - k + 26) % 26) + 'A';
        }
        else if (arr[i] >= 'a' && arr[i] <= 'z')
        {
            arr[i] = ((arr[i] - 'a' - k + 26) % 26) + 'a';
        }
    }
}

// Hàm sắp xếp chuỗi (Bubble Sort)
void sapXepChuoi(char arr[])
{
    int n = strlen(arr);
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

int main()
{
    const int MAX = 100;
    char chuoi[MAX];
    int khoa;

    cout << "Nhap chuoi can xu ly: ";
    cin.getline(chuoi, MAX);

    cout << "Nhap khoa ma hoa (so nguyen): ";
    cin >> khoa;

    // Bước 1: Mã hóa chuỗi
    maHoaCaesar(chuoi, khoa);
    cout << "Chuoi sau khi ma hoa: " << chuoi << endl;

    // Bước 2: Sắp xếp chuỗi đã mã hóa
    sapXepChuoi(chuoi);
    cout << "Chuoi sau khi sap xep: " << chuoi << endl;

    // Bước 3: Giải mã chuỗi sau khi sắp xếp
    giaiMaCaesar(chuoi, khoa);
    cout << "Chuoi sau khi giai ma: " << chuoi << endl;

    return 0;
}
