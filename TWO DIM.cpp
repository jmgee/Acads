#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

void computeTotals(double prices[][4], double totals[], int buyers);
void saveToFile(double prices[][4], double totals[], int buyers);

int main()
{
    const int buyers = 5;
    const int items = 4;
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
    saveToFile(prices, totals, buyers);
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

void saveToFile(double prices[][4], double totals[], int buyers)
{
    ofstream file("purchase_summary.txt");
    file << fixed << setprecision(2);
    file << setw(10) << "Buyer"
         << setw(12) << "Item 1"
         << setw(12) << "Item 2"
         << setw(12) << "Item 3"
         << setw(12) << "Item 4"
         << setw(15) << "Total Price" << endl;
    double grandTotal = 0;
    for (int i = 0; i < buyers; i++) {
        file << setw(10) << "Buyer #" << i + 1;
        for (int j = 0; j < 4; j++) {
            file << setw(12) << prices[i][j];
        }
        file << setw(15) << totals[i] << endl;
        grandTotal += totals[i];
    }
    file << "\nTotal: " << grandTotal << endl;
    file.close();
}
