#include <iostream>
using namespace std;
void nhapmang(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "nhap gia tri a[" << i << "]= ";
        cin >> a[i];
    }
}
float TenHam(int a[], int n)
{
    float dem = 0, tong = 0;
    float tbc;
    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0)
        {
            dem++;
            if (a[i] % 2 != 0)
            {
                tong += a[i];
            }

        }
        tbc = (tong / dem);

    }
    return tbc;
}

int main()
{
    int a[10];
    int n;
    cout << "nhap chieu dai mang n= ";
    cin >> n;
    nhapmang(a, n);
    cout << endl;
    cout << TenHam(a, n);

    return 0;
}

