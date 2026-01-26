#include <iostream>
using namespace std;

void computeStudentAverages(const int grades[][3], int studentCount);

int main()
{
    const int students = 4;
    const int subs = 3;
    int grades[students][subs];
    cout << "Enter grades for 4 students in 3 subjects\n\n";
    for (int i = 0; i < students; i++) {
        cout << "Student " << i + 1 << endl;
        for (int j = 0; j < subs; j++) {
            cout << "  Subject " << j + 1 << ": ";
            cin >> grades[i][j];
        }
        cout << endl;
    }
    cout << "---------------------------------------------\n";
    cout << "Average of each Student\n";
    computeStudentAverages(grades, students);
    return 0;
}

void computeStudentAverages(const int grades[][3], int studentCount)
{
    const int subs = 3;
    for (int i = 0; i < studentCount; i++) {
        int total = 0;
        for (int j = 0; j < subs; j++) {
            total += grades[i][j];
        }
        double average = static_cast<double>(total) / subs;
        cout << "Student " << i + 1 << " - Average Grade: "
             << average << endl;
    }
}