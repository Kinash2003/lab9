// 9.1-B
#include <iostream>
#include <iomanip>
#include <string>
#include <Windows.h> 

using namespace std;

enum Special { КН, ІФ, МЕ, ФІ, ТН };

string s_special[] = { "Інформаційно - комунікаційні системи та технології ",
							"Інформаційні технології", "Комп'ютерна наука",
							"Кібербезпека", "Право" };


struct student
{
	string prizv;
	int kurs;
	Special specialization;
	int phisuka;
	int matematic;
	union
	{
		int programing;
		int chuslo_metod;
		int pedahohica;
	};
};

void Create(student* s, const int kilkist);
void Print(student* s, const int kilkist);
double find_prozent(student* s, const int kilkist);
int find_studend(student* s, const int kilkist);

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int kil_student;
	cout << "Введіть кількість студентів: "; cin >> kil_student;
	cout << endl;
	student* s = new student[kil_student];

	Create(s, kil_student);
	cout << endl;
	Print(s, kil_student);
	cout << endl;

	cout << "відсоток студентів, які мають 5 з фізики або 5 з математики :  " << setprecision(2) << find_prozent(s, kil_student) << "%" << endl << endl;

	cout << "кількість добре: " << endl;
	if (find_studend(s, kil_student));
	else
		cout << "кількість добре: " << endl << endl;

	delete[] s;
}

void Create(student* s, const int kilkist)
{
	int kurs, special;
	for (int i = 0; i < kilkist; i++)
	{
		cout << "студент № " << i + 1 << endl;

		cin.get();
		cin.sync();

		cout << "  прізвище: "; getline(cin, s[i].prizv);
		cout << "  курс: "; cin >> s[i].kurs;
		cout << "  спеціальність :0 - Інформаційно - комунікаційні системи та технології, 1 - Інформаційні технології, 2 - Комп'ютерна наука,3 - Кібербезпека, 4 - Право:"; cin >> special;
		s[i].specialization = (Special)special;
		cout << "  оцінка з фізики: "; cin >> s[i].phisuka;
		cout << "  оцінка з математики: "; cin >> s[i].matematic;
		switch (special)
		{
		case 0:
			cout << "  оцінка з програмування: "; cin >> s[i].programing;
			break;
		case 1:
			cout << "  оцінка з чисельних методів: "; cin >> s[i].chuslo_metod;
			break;
		case 2:
		case 3:
		case 4:
			cout << "  оцінка з педагогіки: "; cin >> s[i].pedahohica;
			break;
		default:
			cout << "Ви ввели помилкове значення! " << endl;
		}
		cout << endl;
	}
}

void Print(student* s, const int kilkist)
{
	cout << "============================================================================================================================"
		<< endl;
	cout << "| №  | Прізвище     | Курс | Спеціальність           | Фізика | Математика  | Програмування | Чисельні методи | Педагогіка |"
		<< endl;
	cout << "----------------------------------------------------------------------------------------------------------------------------" << endl;
	for (int i = 0; i < kilkist; i++)
	{
		cout << "| " << setw(2) << right << i + 1 << " "
			<< "| " << setw(13) << left << s[i].prizv
			<< "| " << setw(3) << right << s[i].kurs << "  "
			<< "| " << setw(23) << left << s_special[s[i].specialization] << " "
			<< "| " << setw(4) << right << s[i].phisuka << "   "
			<< "| " << setw(6) << right << s[i].matematic << "      ";
		switch (s[i].specialization)
		{
		case 0:
			cout << "| " << setw(7) << right << s[i].programing << "       |" << setw(18) << "|" << setw(13) << "|" << endl;
			break;
		case 1:
			cout << "| " << setw(15) << "|" << setw(10) << right << s[i].chuslo_metod << "       |" << setw(13) << "|" << endl;
			break;
		case 2:
		case 3:
		case 4:
			cout << "| " << setw(15) << "|" << setw(18) << "|" << right << setw(7) << s[i].pedahohica << "     |" << endl;
			break;
		}
	}
	cout << "============================================================================================================================" << endl;
}

double find_prozent(student* s, const int kilkist)
{
	int k = 0;
	for (int i = 0; i < kilkist; i++)
	{
		if (s[i].phisuka == 5 || s[i].matematic == 5)
			k++;
	}
	return k / (kilkist * 1.0) * 100;
}

int find_studend(student* s, const int kilkist)
{
	int l = 0;
	for (int i = 0; i < kilkist; i++)
		if (s[i].phisuka == 4 || s[i].matematic == 4 ||s[i].programing == 4 && s[i].chuslo_metod == 4 || s[i].pedahohica || 4)
		{
			cout << "№ " << i + 1 << " " << s[i].prizv << "-Dobre- " << s[i].phisuka << "-" <<s[i].matematic << endl;
			l = 1;
		}

	return l;
}
