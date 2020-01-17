#include <string>
#include <locale>
#include <windows.h>
#include <iostream>
#include <cmath>

using namespace std;
//  Проверка на ввод только числа 
bool g_flag = true;
string g_str = "";

int enterOnlyNum()
{
	int numint=1;
	while (g_flag)
	{
		g_flag = false;
		cout << endl;
		cout << "Введите только цифры: ";
		getline(cin, g_str);
		for (int i = 0; i < g_str.size(); i++)
		{
			if (g_str.at(i) == '-')
			{
				numint = -1;
				g_str.erase(i, 1);
			}
			if (!iswdigit(g_str.at(i))) // если есть что то кроме цифр 
			{
				g_flag = true;
			};
		}
		if (g_str.empty() or g_flag ) // если строка пустая или есть что то кроме цифр
		{
			g_flag = true;
			cout << "Не может быть: символом, пустой строкой. Повторите ввод.";
		};

	}
	g_flag = true;
	numint *= atoi(g_str.c_str());
	return numint; 
}
int enterOnlyNumMoreAndEqualZero()    ////  Проверка на ввод только числа >= 0
{
	int numint = 1;
	while (g_flag)
	{
		g_flag = false;
		cout << endl;
		cout << "Введите только цифры: ";
		getline(cin, g_str);
		for (int i = 0; i < g_str.size(); i++)
		{
			
			if (!iswdigit(g_str.at(i))) // если есть что то кроме цифр 
			{
				g_flag = true;
			};
		}
		if (g_str.empty() or g_flag) // если строка пустая или есть что то кроме цифр 
		{
			g_flag = true;
			cout << "Не может быть: символом, пустой строкой, меньше 0. Повторите ввод.";
		};

	}
	g_flag = true;
	numint *= atoi(g_str.c_str());
	return numint;
}

void aboutMe()   // Информация о студенте
{   
	cout << endl;
	cout << "| Меркулов Артем Андреевич      |\n"
	        "| Группа: М3О-235Б-18           |\n"
		    "| КАЛЬКУЛЯТОР КОМПЛЕКСНЫХ ЧИСЕЛ |\n"
	        "|_______________________________|\n" ;
}
class complex // Класс комплекного числа
{
private:
	double re, im;
public:
	complex() { re = 0; im = 0; }
	complex(double r, double i) { re = r; im = i; }
	complex(const complex &ob) { re = ob.re; im = ob.im; };
	double getRe();
	double getIm();
	complex& operator = (complex);
	complex operator + (complex);
	complex operator - (complex);
	complex operator * (complex);
	complex operator / (complex);
	complex& operator += (complex);
	complex& operator -= (complex);
	complex& operator *= (complex);
	complex& operator /=(complex);
	friend istream& operator >>(istream&, complex&);
	friend ostream& operator << (ostream&, const complex&);
	bool operator == (complex& com);
	bool operator != (complex& com);
	bool operator > (complex& com);
	bool operator < (complex& com);

};

bool complex:: operator > (complex& com)
{
	if (this->re > com.re)
		return 1;
	else if (this->re == com.re && this->im > com.im)
		return 1;
	else
		return 0;
}

bool complex ::operator < (complex& com)
{
	if (this->re < com.re)
		return 1;
	else if (this->re == com.re && this->im < com.im)
		return 1;
	else
		return 0;

}

bool complex::operator != (complex& com)
{
	if (this->re != com.re || this->im != com.im)
		return 1;
	else
		return 0;
}

bool complex::operator==(complex& com)
{
	if (this->re == com.re && this->im == com.im)
		return 1;
	else
		return 0;
}



complex complex::operator*(complex com)
{
	double i, j;
	i = re * com.re - im * com.im;
	j = re * com.im + com.re * im;
	re = i;
	im = j;
	return *this;
}

complex complex::operator/(complex com)
{
	double i, j, k;
	k = com.re * com.re + com.im * com.im;
	i = (re * com.re + im * com.im) / k;
	j = (com.re * im - re * com.im) / k;
	re = i;
	im = j;
	return *this;
}

double complex::getRe()
{
	return re;
}

double complex::getIm()
{
	return im;
}

complex& complex::operator =(complex com)
{
	this->re = com.re;
	this->im = com.im;
	return *this;
}

complex complex::operator+(complex com)
{
	this->re = this->re + com.re;
	this->im = this->im + com.im;
	return *this;
}

complex complex::operator-(complex com)
{
	this->re = this->re - com.re;
	this->im = this->im - com.im;
	return *this;
}


ostream& operator << (ostream& out, const complex& com)
{
	if (com.im < 0)
		out << com.re << "-" << com.im * -1 << "i\n";
	else
		out << com.re << "+" << com.im << "i\n";
	return out;
}

istream& operator >> (istream& in, complex& com)
{
	int num;
	cout << "Введите действительную часть комплексного числа ";
	num = enterOnlyNum();
	com.re=num;
	cout << "Введите мнимую часть комплексного числа ";
	num = enterOnlyNum();
    com.im=num;
	return in;
}

complex& complex::operator+=(complex a)
{
	re += a.re;
	im += a.im;
	return *this;
}

complex& complex::operator-=(complex a)
{
	re -= a.re;
	im -= a.im;
	return *this;
}

complex& complex::operator*=(complex a)
{
	re *= a.re;
	im *= a.im;
	return *this;
}

complex& complex::operator/=(complex a)
{
	re /= a.re;
	im /= a.im;
	return *this;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int menu;
	double module;
	complex c1, c2, result;
	do//Меню
	{
		aboutMe();
		cout<<"0 - Выход из программы\n" 
			"1 - Cложение двух комплексных чисел\n" 
			"2 - Вычитание двух комплексных чисел\n" 
			"3 - Умножение двух комплексных чисел\n" 
			"4 - Деление двух комплексных чисел\n" 
			"5 - Модуль комплексного числа\n"
			"6 - Сравнение двух комплексных чисел\n"
			
			"Введите пункт меню: ";

		menu = enterOnlyNumMoreAndEqualZero();
		while (menu < 0 || menu > 6)
		{
			cout<< "Пункт меню должен быть больше от 0 до 6.\n"
				"Введите данные заново: ";
			menu = enterOnlyNumMoreAndEqualZero();
		}

		switch (menu)
		{
		case 1:
			cout << "Введите первое комплексное число:\n";
			cin >> c1;
			cout << "Введите второе комплексное число:\n";
			cin >> c2;
			result = c1 + c2;
			cout <<"Сложение. Ответ: "<< result << endl;
			break;
		case 2:
			cout << "Введите первое комплексное число:\n";
			cin >> c1;
			cout << "Введите второе комплексное число:\n";
			cin >> c2;
			result = c1 - c2;
			cout << "Вычитание. Ответ: " << result << endl;
			break;
		case 3:
			cout << "Введите первое комплексное число:\n";
			cin >> c1;
			cout << "Введите второе комплексное число:\n";
			cin >> c2;
			result = c1 * c2;
			cout << "Умножение. Ответ: " << result << endl;
			break;
		case 4:
			cout << "Введите первое комплексное число:\n";
			cin >> c1;
			cout << "Введите второе комплексное число:\n";
			cin >> c2; 
			if ((pow(c2.getRe(),2)+ pow(c2.getIm(),2)) == 0) cout << "Невозможно выполнить операцию деления. "
				"Действительная и мнимая часть второго КЧ числа равна 0";
			else 
			{
				result = c1 / c2;
				cout << "Деление. Ответ: " << result << endl;
			}
			break;
		case 5:
			cout << "Введите комплексное число:\n";
			cin >> c1;
			module = sqrt(pow(c1.getRe(), 2) + pow(c1.getIm(), 2));
			cout << "Модуль. Ответ: " << module << endl;
			
			break;
		case 6:
			cout << "Введите первое комплексное число:\n";
			cin >> c1;
			cout << "Введите второе комплексное число:\n";
			cin >> c2;
			if (c1 > c2) cout << "Первое комплексное число больше второго";
			if (c1 < c2) cout << "Первое комплексное число меньше второго";
			if (c1 == c2) cout << "Комплексные числа равны";
			break;
		}

	} while (menu != 0);
	cout << "Выход\n";
	system("pause");
	return 0;
}