
//Лабораторна робота №9
//lab_9.1_
//Переліки.Структури та об'єднання
//РІВЕНЬ А
#include <iostream>
#include <Windows.h>
#include <iomanip>
#include <string>


using namespace std;

#pragma pack(push, 1)

enum Speciality { IK, IT, KB, KI, PM };
string speciality_str[] = { "Інформаційно - комунікаційні системи та технології ",
                            "Інформаційні технології", "Комп'ютерна наука",
                            "Кібербезпека", "Право" };

struct Students
{
    string surname;
    int course;
    Speciality speciality;
    int grade_physics;
    int grade_math;
    int computer_science;

};

#pragma pack(pop)

void Create(Students* S, const int N);
int grade_dobre(Students* S, const int i, const int N);
void Print(Students* S, const int N);
double Percentage(Students* S, const int N);
void Print_1(Students* S, const int N);

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int N;
    cout << "Введіть кількість студентів: "; cin >> N;

    Students* S = new Students[N];

    Create(S, N);
    Print_1(S, N);
    Print(S, N);
    cout << "відсоток студентів, які мають 5 з фізики або 5 з математики : " << setprecision(2) << Percentage(S, N) << "%";

    return 0;
}
void Create(Students* S, const int N)
{
    for (int i = 0; i < N; i++)
    {
        int speciality;
        cout << "Номер студента: " << i + 1 << endl;
        cin.get();
        cin.sync();
        cout << "Прізвище студента: "; getline(cin, S[i].surname); cout << endl;
        cout << "Курс: "; cin >> S[i].course; cout << endl;
        cout << "Спеціальність(0 - Інформаційно - комунікаційні системи та технології, 1 - Інформаційні технології, 2 - Комп'ютерна наука";
        cout << "\n3 - Кібербезпека, 4 - Право): ";
        cin >> speciality;
        S[i].speciality = (Speciality)speciality;
        cout << "Оцінка з інформатики: "; cin >> S[i].computer_science; cout << endl;
        cout << "Оцінка з фізики: "; cin >> S[i].grade_physics; cout << endl;
        cout << "Оцінка з математики: "; cin >> S[i].grade_math; cout << endl;

        cout << endl;
    }

}
int grade_dobre(Students* S, const int i, const int N)
{
    int dobre = 4;
    int k = 0;
    if (S[i].grade_physics == dobre)
        k++;
    if (S[i].grade_math == dobre)
        k++;
    if (S[i].computer_science == dobre)
        k++;
    return k;
}
void Print_1(Students* S, const int N)
{
    cout << "=========================================================================================" << endl;
    cout << "|  №  |  Прізвище  |  курс  |  спеціальність  |  Фізика  |  Математика  |  Інформатика  |" << endl;
    cout << "-----------------------------------------------------------------------------------------" << endl;

    for (int i = 0; i < N; i++)
    {
        cout << "|" << setw(3) << i + 1 << setw(3);
        cout << "|" << setw(4) << S[i].surname << setw(4);
        cout << "|" << setw(6) << S[i].course << setw(6);
        cout << "|" << setw(6) << speciality_str[S[i].speciality] << setw(6);
        cout << "|" << setw(6) << S[i].grade_physics << setw(6);
        cout << "|" << setw(6) << S[i].grade_math << setw(6);
        cout << "|" << setw(6) << S[i].computer_science << setw(6) << "|" << endl;
    }
    cout << "=========================================================================================" << endl << endl;
}
void Print(Students* S, const int N)
{
    cout << fixed;
    cout << "=======================================" << endl;
    cout << "|  №  |  Прізвище  |  кількість добре  |" << endl;
    cout << "---------------------------------------" << endl;

   
        for (int i = 0; i < N; i++)
        {
            cout << "|" << setw(3) << i + 1 << setw(3);
            cout << "|" << setw(5) << S[i].surname << setw(4);
            cout << "|" << setw(9) << grade_dobre(S, i, N) << setw(10) << "|";
            cout << endl;
        }
    cout << "=====================================" << endl;
}
double Percentage(Students* S, const int N)
{
    int k = 0;
    for (int i = 0; i < N; i++)
        if (S[i].grade_physics == 5 || S[i].grade_math == 5)
            k++;
    return k / (N * 1.0) * 100;
}