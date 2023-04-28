#include "list.h"
#include "Pair.h"
#include <iostream>
#include <ctime>
using namespace std;


int main() 
{
	setlocale(LC_ALL, "ru");
	Pair p1(1, 3.25);
	List<Pair> a(3, p1);
	cout << "Ваш список: " << a << endl;
	cout << "a.front(): " << a.front() << endl;
	cout << "Создайте свой список" << endl;
	cin >> a;
	cout << a << endl;
	List<Pair> b(a);
	cout << "Список a был скопирован в список b\n";
	cout << b << endl;
	List<Pair> c = a * b;
	cout << "Умножение элементов одного списка на элементы из другого: " << c << endl;
	Pair num;
	cout << "Введите пару чисел (второе число дробное)" << endl; 
	cin >> num;
	b.pushback(num);
	b.popfront();
	cout << "Из созданного вами списка была удалена первая пара и добавлена последняя введённая\n";
	for (Iterator<Pair> iter = b.first(); iter != b.last(); ++iter) cout << *iter << '\n';
	return 0;
}