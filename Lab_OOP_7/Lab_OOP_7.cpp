#include <iostream>
#include <process.h>
#include <string>
#include <string.h>

using namespace std;

class Time {
private:
	int hours;
	int minutes;
	int seconds;
public:
	Time() {
		hours = 0; minutes = 0; seconds = 0;
	}
	Time(int hour, int minute, int second)
	{
		hours = hour;
		minutes = minute;
		seconds = second;
	}
	void print() const {
		cout << "Время " << hours << ":" << minutes << ":" << seconds << endl;
	}
	void setTime()
	{
		cout << "Введите часы: ";
		cin >> hours;
		cout << "Введите минуты: ";
		cin >> minutes;
		cout << "Введите секунды: ";
		cin >> seconds;
	}

	Time operator+ (const Time other)
	{
		long s;
		s = (hours + other.hours) * 3600 + (minutes + other.minutes) * 60 + (seconds + other.seconds);
		hours = s / 3600;
		s -= hours * 3600;
		minutes = s / 60;
		s -= minutes * 60;
		seconds = s;
		return Time(hours, minutes, seconds);
	}

	Time operator++()
	{
		long s;
		s = hours * 3600 + minutes * 60 + seconds;
		s++;
		hours = s / 3600;
		s -= hours * 3600;
		minutes = s / 60;
		s -= minutes * 60;
		seconds = s;
		return Time(hours, minutes, seconds);
	}

	Time operator++(int value)
	{
		long s;
		s = hours * 3600 + minutes * 60 + seconds;
		s++;
		hours = s / 3600;
		s -= hours * 3600;
		minutes = s / 60;
		s -= minutes * 60;
		seconds = s;
		return Time(hours, minutes, seconds);
	}

	Time operator--()
	{
		long s;
		s = hours * 3600 + minutes * 60 + seconds;
		s--;
		hours = s / 3600;
		s -= hours * 3600;
		minutes = s / 60;
		s -= minutes * 60;
		seconds = s;
		return Time(hours, minutes, seconds);
	}

	Time operator--(int value)
	{
		long s;
		s = hours * 3600 + minutes * 60 + seconds;
		s--;
		hours = s / 3600;
		s -= hours * 3600;
		minutes = s / 60;
		s -= minutes * 60;
		seconds = s;
		return Time(hours, minutes, seconds);
	}

	Time operator-(const Time other)
	{
		long s;
		s = (hours - other.hours) * 3600 + (minutes - other.minutes) * 60 + (minutes - other.minutes);
		hours = s / 3600;
		s -= hours * 3600;
		minutes = s / 60;
		s -= minutes * 60;
		seconds = s;
		return Time(hours, minutes, seconds);
	}

	Time operator*(const double value)
	{
		long s;
		s = (hours * 3600 + minutes * 60 + seconds) * value;
		hours = s / 3600;
		s -= hours * 3600;
		minutes = s / 60;
		s -= minutes * 60;
		seconds = s;
		return Time(hours, minutes, seconds);
	}
};

class Fraction
{
private:
	int tnum;
	int tden;
	char slesh;
	void lowterms()
	{
		long den, num, temp, gcd;
		num = labs(tnum);
		den = labs(tden);
		if (den == 0)
		{
			cout << "Деление на ноль\n";
		}
		else if (num == 0)
		{
			num = 0;
			den = 1;
			return;
		}
		while (num != 0)
		{
			if (num < den)
			{
				temp = num;
				num = den;
				den = temp;
			}
			num -= den;
		}
		gcd = den;
		tnum /= gcd;
		tden /= gcd;
	}
public:
	Fraction()
	{
		tnum = 0;
		tden = 1;
	}
	Fraction(int a, int b)
	{
		tnum = a;
		tden = b;
		Fraction::lowterms();
	}
	void SetFracAvt(int a, int b)
	{
		tnum = a;
		tden = b;
		lowterms();
	}
	void GetPrintNoSpace()
	{
		cout << tnum << '/' << tden << ' ';
	}
	void GetPrintFraction()
	{
		cout << tnum << "/" << tden << endl;
	}
	void SetFraction()
	{
		cout << "Введите дробь вида a/b: ";
		cin >> tnum >> slesh >> tden;
		lowterms();
	}
	Fraction operator+(Fraction frac1)
	{
		tnum = frac1.tnum * tden + frac1.tden * tnum;
		tden = frac1.tden * tden;
		lowterms();
		return Fraction(tnum, tden);
	}
	Fraction operator-(Fraction frac1)
	{
		tnum = frac1.tnum * tden - frac1.tden * tnum;
		tden = frac1.tden * tden;
		lowterms();
		return Fraction(tnum, tden);
	}
	Fraction operator*(Fraction frac1)
	{
		tnum = frac1.tnum * tnum;
		tden = frac1.tden * tden;
		lowterms();
		return Fraction(tnum, tden);
	}
	Fraction operator/(Fraction frac1)
	{
		tnum = frac1.tnum * tden;
		tden = frac1.tden * tnum;
		lowterms();
		return Fraction(tnum, tden);
	}

	bool operator==(Fraction other)
	{
		return (other.tden == tden && other.tnum == tnum);
	}

	bool operator!=(Fraction other)
	{
		return !(other.tden == tden && other.tnum == tnum);
	}

	Fraction operator=(const Fraction value)
	{
		tden = value.tden;
		tnum = value.tnum;
		return Fraction(tnum, tden);
	}
};

class bMoney;

const int LIMIT = 100;
class safearray
{
private:
	int indextp, indexbt;
	int arr[LIMIT];
public:
	safearray(int i, int j): indexbt(i), indextp(j)
	{ }
	safearray(): indexbt(0), indextp(99)
	{ }
	void setGran()
	{
		cout << "Введите нижнюю границу: ";
		cin >> indexbt;
		cout << "Введите верхнюю границу: ";
		cin >> indextp;
	}
	int& operator[](int n)
	{
		if ((n < indexbt || n > indextp) || (indextp-indexbt+1) > LIMIT)
		{
			cout << "Ошибочный индекс!\n"; exit(1);
		}
		return arr[n%(indextp - indexbt +1)];
	}
	int getindexbt()
	{
		return indexbt;
	}
	int getindextp()
	{
		return indextp;
	}
};

class Polar
{
private:
	int angle, radius;
public:
	Polar(): angle(0), radius(0)
	{ }
	Polar(int angl, int rad): angle(angl), radius(rad)
	{ }

	void Print()
	{
		cout << "Полярные координаты: " << angle << " угол, " << radius << " полярный радиус\n";
	}

	void SetPolar()
	{
		cout << "Введите полярный угол: ";
		cin >> angle;
		cout << "Введите полярный радиус: ";
		cin >> radius;
	}

	Polar operator+(Polar x)
	{
		angle += x.angle;
		radius += x.radius;
		return Polar(angle, radius);
	}

	void operator+=(Polar x)
	{
		angle += x.angle;
		radius += x.radius;
	}
};

class sterling;

class sterling
{
private:
	long pound;
	int shilling, pence;
	char sim;
public:
	sterling() :pound(0), shilling(0), pence(0)
	{ }

	sterling(double news)
	{
		double sm = news * 100.0F;
		this->pound = sm / 100;
		sm -= pound * 100;
		sm *= 2.4F;
		this->shilling = sm / 12;
		sm -= shilling * 12;
		this->pence = sm;
	}

	sterling(long pound, int shilling, int pence)
	{
		this->pound = pound;
		this->shilling = shilling;
		this->pence = pence;
	}
	void getSterling()
	{
		cout << "Введите количество стерлингов в виде &*.**.**: ";
		cin >> sim >> pound >> sim >> shilling >> sim >> pence;
	}

	void putSterling()
	{
		cout << "&" << pound << "." << shilling << "." << pence << endl;
	}

	sterling operator+(sterling x)
	{
		return sterling(double(sterling(pound, shilling, pence)) + double(x));
	}

	sterling operator-(sterling x)
	{
		return sterling(double(sterling(pound, shilling, pence)) - double(x));
	}

	sterling operator*(double x)
	{
		return sterling(double(sterling(pound, shilling, pence)) * x);
	}

	sterling operator/(sterling x)
	{
		return sterling(double(sterling(pound, shilling, pence)) / double(x));
	}

	sterling operator/(double x)
	{
		return sterling(double(sterling(pound, shilling, pence)) / x);
	}

	operator double() const
	{
		double ster = 0;
		ster = (pound * 12 * 20 + shilling * 12 + pence) / 2.4 / 100.0F;
		return ster;
	}

	sterling operator=(bMoney money);
};

class bMoney {
private:
	long double money;
	string ldtoms()
	{
		string preob = to_string((long)(money * 100));
		string preob_1 = "";
		int len = preob.length(), count = 0, three = 0;
		for (int i = len - 1; i >= 0; i--)
		{
			if (three == 3)
			{
				preob_1 = " " + preob_1;
			}
			preob_1 = preob[i] + preob_1;
			count += 1;
			three += 1;
			if (count == 2)
			{
				preob_1 = "." + preob_1;
				three = 0;
			}
		}
		preob_1 = "$" + preob_1;
		return preob_1;

	}
	long double mstold(string String)
	{
		long double preobraz;
		string str = String;
		int len = str.length(), x = str.find(' ');
		while (x < str.size())
		{
			str.replace(x, 1, "");
			x = str.find(' ');
		}
		x = str.find('$');
		str.replace(x, 1, "");
		x = str.find('.');
		str.replace(x, 1, "");
		preobraz = stold(str) / 100;
		return preobraz;

	}
	bMoney(long double val) : money(val)
	{ }
public:
	bMoney()
	{
		money = 0.0;
	}
	bMoney(char bMon[])
	{
		money = mstold(bMon);
	}
	bMoney(double money)
	{
		this->money = money;
	}
	void obnulytor()
	{
		money = 0.0;
	}
	void getmoney()
	{
		string S;
		cout << "Введите сумму денег(в долларах): ";
		cin.get();
		getline(cin, S);
		money = mstold(S);
	}
	void putmoney()
	{
		cout << "Общая сумма долларов: " << ldtoms() << endl;
	}
	double get()
	{
		return money;
	}
	bMoney operator+(const bMoney other)
	{
		money += other.money;
		return bMoney(money);
	}

	bMoney operator-(const bMoney other)
	{
		money -= other.money;
		return bMoney(money);
	}

	bMoney operator*(const long double other)
	{
		money *= other;
		return bMoney(money);
	}

	long double operator/(const bMoney other)
	{
		return long double(money / other.money);
	}

	bMoney operator/(const long double other)
	{
		money /= other;
		cout << money;
		long int s = round(money * 100.0);
		money = long double(s) / 100.0;
		return bMoney(money);
	}

	bMoney operator=(const bMoney val)
	{
		money = val.money;
		return bMoney(money);
	}
	void getMonSt()
	{
		cout << "Введите сумму долларов: ";
		cin >> money;
	}
	bMoney operator=(sterling s);
};

bMoney bMoney::operator=(sterling s)
{
	double money;
	money = double(s) * 50.00F;
	this->money = money;
	return bMoney(this->money);
}

sterling sterling::operator=(bMoney money)
{
	double rzn = money.get() / 50.00F;
	double sm = rzn * 100.0F;
	this->pound = sm / 100;
	sm -= pound * 100;
	sm *= 2.4F;
	this->shilling = sm / 12;
	sm -= shilling * 12;
	this->pence = sm;
	return sterling(this->pound, this->shilling, this->pence);
}

int main()
{
	setlocale(LC_ALL, "rus");
	bool end = true, find;
	int number;
	Time t1(1, 20, 30), t2(4, 33, 59), t3;
	double value;
	char sim;
	Fraction Frac, Frac1, Frac2;
	bMoney Mon1, Mon2, Mon;
	long double count, sm;
	safearray array1(20, 40);
	Polar Pol, Pol1, Pol2;
	string s;
	sterling ster, ster1, ster2;
	do
	{
		cout << "Введите номер задания: ";
		cin >> number;
		switch (number)
		{
		case 3:
			system("cls");
			t3 = t1 + t2;
			t3.print();
			break;
		case 5:
			system("cls");
			t1.setTime();
			t2.setTime();
			t3.setTime();
			t1++;
			t1.print();
			++t2;
			t2.print();
			t3--;
			t3.print();
			t2 = --t3;
			t2.print();
			break;
		case 6:
			system("cls");
			t1.setTime();
			cout << "Введите число, на которое хотите умножить: ";
			cin >> value;
			t1 = t1 * value;
			t1.print();
			t2.setTime();
			t1 = t2 - t1;
			t1.print();
			break;
		case 7:
			system("cls");
			find = true;
			do
			{
				cout << "Если хотите выйти из калькулятора, введите дробь вида 0/1: ";
				Frac1.SetFraction();
				if (Frac1 == Fraction(0, 1))
				{
					break;
				}
				cout << "Введите желаемую операцию: ";
				cin >> sim;
				Frac2.SetFraction();
				switch (sim)
				{
				case '+':
					Frac = Frac1 + Frac2;
					Frac.GetPrintFraction();
					break;
				case '-':
					Frac = Frac1 - Frac2;
					Frac.GetPrintFraction();
					break;
				case '*':
					Frac = Frac1 * Frac2;
					Frac.GetPrintFraction();
					break;
				case '/':
					Frac = Frac1 / Frac2;
					Frac.GetPrintFraction();
					break;
				default:
					cout << "Такой операции не реализовано!\n";
					break;
				}
			} while (find);
			break;
		case 8:
			system("cls");
			find = true;
			do
			{
				cout << "Введите первое значение вида $*** ***.**: ";
				Mon1.getmoney();
				cout << "Введите число с плавающей точкой: ";
				cin >> count;
				Mon2.getmoney();
				Mon = Mon1 + Mon2;
				Mon.putmoney();
				Mon = Mon1 - Mon2;
				Mon.putmoney();
				Mon = Mon1 * count;
				Mon.putmoney();
				sm = Mon1 / Mon2;
				cout << "Общая цена, деленная на цену за изделие: " << sm << endl;
				Mon = Mon1 / count;
				Mon.putmoney();
				cout << "Хотите продолжить ввод?(y/n) ";
				cin >> sim;
				(sim == 'y') ? find = true : find = false;
			} while (find);
			break;
		case 9:
			system("cls");
			count = 0;
			array1.setGran();
			for (int i = array1.getindexbt(); i <= array1.getindextp(); i++)
			{
				array1[i] = count;
				count++;
			}
			for (int i = array1.getindexbt(); i <= array1.getindextp(); i++)
			{
				cout << "Элемент массива " << i << " со значением " << array1[i] << endl;
			}
			cout << array1[array1.getindextp() + 1];
			break;
		case 10:
			system("cls");
			Pol1.SetPolar();
			Pol2.SetPolar();
			Pol = Pol1 + Pol2;
			Pol.Print();
			Pol += Pol2;
			Pol.Print();
			break;
		case 11:
			system("cls");
			find = true;
			do
			{
				ster1.getSterling();
				cout << "Введите операцию(*, /, +, -, d)\n";
				cin >> sim;
				switch (sim)
				{
				case '+':
					ster2.getSterling();
					ster = ster1 + ster2;
					cout << "Сумма стерлингов: ";
					ster.putSterling();
					break;
				case '-':
					ster2.getSterling();
					ster = ster1 - ster2;
					cout << "Разность стерлингов: " << ster << endl;
					break;
				case '*':
					cout << "Введите стерлинги в новом формате: ";
					cin >> value;
					ster = ster1 * value;
					cout << "Произведение стерлингов: " << ster << endl;
					break;
				case 'd':
					cout << "Введите стерлинге в новом формате: ";
					cin >> value;
					ster = ster1 / value;
					cout << "Частное стерлингов: " << ster << endl;
					break;
				case '/':
					ster2.getSterling();
					ster = ster1 / ster2;
					cout << "Частное стерлингов: " << ster << endl;
					break;
				default:
					cout << "Вы ввели не кореектные данные!\n";
					break;
				}
				cout << "Вы хотите продолжить?!(y/n)\n";
				cin >> sim;
				(sim == 'y') ? find = true : find = false;
			} while (find);
			break;
		case 12:
			system("cls");
			find = true;
			do
			{
				cout << "Что вы хотите ввести bMoney или sterling?(b/s)\n";
				cin >> sim;
				switch (sim)
				{
				case 'b':
					Mon1.getMonSt();
					ster = Mon1;
					ster.putSterling();
					break;
				case 's':
					ster.getSterling();
					Mon = ster;
					Mon.putmoney();
					break;
				default:
					cout << "Такой операции нет!\n";
					break;
				}
				cout << "Вы хотите продолжить?!(y/n)\n";
				cin >> sim;
				(sim == 'y') ? find = true : find = false;
			} while (find);
			break;
		default:
			end = false;
			cout << "Спасибо за проверку лабы!\n";
			break;
		}

	} while (end);
}

