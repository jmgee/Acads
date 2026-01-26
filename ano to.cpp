#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int a[100];
    int n, i;
    cout << "Enter n: ";
    cin >> n;
    for (i = 0; i < n; i++) {
        cin >> a[i];
    }
    cout << left << setw(15) << "Odd numbers" << "Even numbers" << endl;
    int maxRows = n; 
    int oddIdx = 0, evenIdx = 0;
    int odd[100], even[100];
    for (i = 0; i < n; i++) {
        if (a[i] % 2 == 1)
            odd[oddIdx++] = a[i];
        else
            even[evenIdx++] = a[i];
    }
    for (i = 0; i < max(oddIdx, evenIdx); i++) {
        if (i < oddIdx)
            cout << left << setw(15) << odd[i];
        else
            cout << left << setw(15) << " ";

        if (i < evenIdx)
            cout << even[i];

        cout << endl;
    }
    return 0;
}
