#include <iostream>
#include <locale.h>
#include <cmath>

using namespace std;

void geo23(); //Декларування функції типу void(задача geo23)

void task18();//Декларування функції типу void(задача Solve18)

void task26();//Декларування функції типу void(задача Solve26)

int main()
{
	setlocale(LC_ALL, "ukrainian");

		int choice = 0; //Декларування змінної задля choice

		while (true && choice !=4){
			setlocale(LC_ALL, "ukrainian");
			cout.clear();
			cout << "Виберiть яку з цих задач будете вирiшувати: "
				"\n1. Геометрія22"
				"\n2. Задача19"
				"\n3. Задача27"
				"\n4. Вийти з програми" << endl;

			cin >> choice;

			switch (choice)
			{
				case 1:
				{
					// Geo17
					geo23();
					break;
				}
				case 2:
				{
					// Задача18
					task18();
					break;
				}
				case 3:
				{
					// Задача26
					task26();
					break;
				}
				case 4:
				{
					cout << "Програма завершена";
					break;
				}
				default:
				{
					cout << "Такого варiанту немає\n";
					break;
				}
			}
		}
}

void geo23() { // Функція типу void, що не повертає значень
	float x, y, r; // Декларування змінних типу float
	bool ar1, ar2; // Декларування змінних типу bool
	int n, counter = 0;

	cout << "Кількість разів: ";
	cin >> n;

		cout << "Уведiть радiус кола: ";
		std::cin >> r;

		for (int i = 1; i <= n; i++)
		{

			if (r > 0)
			{
				cout << "Уведiть точку за кординатою х : ";
				cin >> x;
				cout << "Уведiть точку за кординатою y : ";
				cin >> y;

				ar1 = pow(x,2) + pow(y,2) < pow(r,2) && y>0 && x>0 && y>x; //Рівняння першої фігури(верхньої)
				ar2 = pow(x, 2) + pow(y, 2) > pow(r, 2) && x<0 && y<0 && y<x && y>-2 * r; //Рівняння другої фігури(нижньої)

				if (ar1 || ar2) {
					counter++;
				}
			}
			else {
				cout << "Радіус не може бути від'ємним" << endl;
			}
		}
		cout << "Кількість вдалих спроб: " << counter;
}

void task18()
{
	int k = 1,n; 
	const double pi = 3.14;
	double x;

	cout << "Введіть х: ";
	cin >> x;

	cout << "Кількість циклів n: ";
	cin >> n; 

	
	double sum = 0;	
	cout.precision(15);
	if (!cin || n < 0)
	{
		cout << "Неправильне введення даних" << endl;
	}
	else 
	{
		if (n == 1) {
			cout << x;
		}
		else {
			double result = x;
			double top = 1.0, bot = 1.0;
			for (k; k <= n; k++)
			{
				int temp = (2 * k + 1);
				
				top *= ((2 * k) - 1);
				bot *= (2 * k);
				double powing = pow(x, temp) / temp;
				result += ((top / bot) * powing);

				cout << result << endl;
			}	
		}
	}
}

void task26()
{
	int k = 0, n;
	const double pi = 3.14, e = 1;
	double x, g = 1E+5;


	cout << "Введіть х: ";
	cin >> x;

	cout << "Діапазон суми ряду: ";
	cin >> g;

	double sum = 0;

	do
	{
		k++;
			int count = 0;

			double part1 = pow(-1,k)*pow((3*x-1),k-1);
			double part2 = pow((sqrt(k)*x),3);

			double solving = part1 / part2;

			sum += solving;
			solving = 0;

			count = k % 4;
			cout << "Solve: " << sum << endl;

			if (count == 3) {
				cout << "Сума ряду: " << sum << endl;
			}
	} while (sum < g);
}