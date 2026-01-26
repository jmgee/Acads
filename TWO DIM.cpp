#include <iostream>
#include <iomanip>
using namespace std;

void computeTotals(double prices[][4], double totals[], int buyers);

int main()
{
    const int BUYERS = 5;
    const int ITEMS  = 4;
    double prices[BUYERS][ITEMS];
    double totals[BUYERS];
    cout << "Enter four item prices for each buyer\n\n";
    for (int i = 0; i < BUYERS; i++) {
        cout << "Buyer #" << i + 1 << endl;
        for (int j = 0; j < ITEMS; j++) {
            cin >> prices[i][j];
        }
        cout << endl;
    }
    computeTotals(prices, totals, BUYERS);
    cout << fixed << setprecision(2);
    cout << setw(10) << "Buyer"
         << setw(12) << "Item 1"
         << setw(12) << "Item 2"
         << setw(12) << "Item 3"
         << setw(12) << "Item 4"
         << setw(15) << "Total Price" << endl;
    double grandTotal = 0;
    for (int i = 0; i < BUYERS; i++) {
        cout << setw(10) << "Buyer #" << i + 1;
        for (int j = 0; j < ITEMS; j++) {
            cout << setw(12) << prices[i][j];
        }
        cout << setw(15) << totals[i] << endl;
        grandTotal += totals[i];
    }
    cout << "\nTotal: " << grandTotal << endl;
    return 0;
}

void computeTotals(double prices[][4], double totals[], int buyers)
{
    const int ITEMS = 4;
    for (int i = 0; i < buyers; i++) {
        totals[i] = 0;
        for (int j = 0; j < ITEMS; j++) {
            totals[i] += prices[i][j];
        }
    }
}
