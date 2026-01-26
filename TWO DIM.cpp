#include <iostream>
#include <iomanip>
using namespace std;

void computeTotals(double prices[][4], double totals[], int buyers);

int main()
{
    const int buyers = 5;
    const int items  = 4;
    double prices[buyers][items];
    double totals[buyers];
    cout << "Enter four item prices for each buyer\n\n";
    for (int i = 0; i < buyers; i++) {
        cout << "Buyer #" << i + 1 << endl;
        for (int j = 0; j < items; j++) {
            cin >> prices[i][j];
        }
        cout << endl;
    }
    computeTotals(prices, totals, buyers);
    cout << fixed << setprecision(2);
    cout << setw(10) << "Buyer"
         << setw(12) << "Item 1"
         << setw(12) << "Item 2"
         << setw(12) << "Item 3"
         << setw(12) << "Item 4"
         << setw(15) << "Total Price" << endl;
    double grandTotal = 0;
    for (int i = 0; i < buyers; i++) {
        cout << setw(10) << "Buyer #" << i + 1;
        for (int j = 0; j < items; j++) {
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
    const int items = 4;
    for (int i = 0; i < buyers; i++) {
        totals[i] = 0;
        for (int j = 0; j < items; j++) {
            totals[i] += prices[i][j];
        }
    }
}
