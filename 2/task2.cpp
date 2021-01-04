//Второе задание
//Вычисление функции разложением в ряд Тейлора
//Вычислить значение функции f, которая указана в задании, в точке x,
//используя разложение в ряд Тейлора.Суммирование выполнять до тех пор, пока
//общий член ряда не будет меньше, по модулю, заданного параметра epsilon
//5. exp(x)
#include <iostream>

double f(double input_x, double input_epsilon = 1e-5)
{
	__asm
	{
		fld1
		; 4 - Sum, / загружаю в стэк едиицу /
		fld     input_epsilon
		; 3 - input_epsilon, / загружаю epsilon /
		fld     input_x
		; 2 - x, / загружаю x /
		fld1
		; 1 - i, / загружаю 1 /
		fld     st(1)
		; 0 - Xi

		START:
		fadd    st(4), st(0)
			; это строка значит : Sum += Xi
			fld1
			; это строка значит : st(0) = 1, st(2) = i
			faddp   st(2), st(0)
			; увеличили i и поменяли вершину стека, которая была 1
			fmul    st(0), st(2)
			; это строка значит : Xi * = x
			fdiv    st(0), st(1)
			; это строка значит : Xi /= i
			fld     st(0)
			; Xi
			fabs
			; это строка значит : модуль Xi
			fcomip  st(0), st(4)
			; это строка значит : while (abs(Xi) > epsilon), / сравниваем и меняем вершину /
			jnbe START

			fstp st(0)
			; выталкиваю i
			fstp st(0)
			; выталкиваю x
			fstp st(0)
			; выталкиваю epsilon
			fstp st(0)
			; выталкиваю Sum, и выводится при вызове функции
	}
}

int main()
{
	std::cout << "Input your x: ";

	double x;

	std::cin >> x;
	std::cout << "Result is: " << f(x) << std::endl;

	return 0;
}

/*Результаты выполения: 
1)Input your x: 0
Result is: 1
2)Input your x: -1
Result is: 0.367882
3)Input your x: 1
Result is: 2.71828
4)Input your x: 100
Result is: 2.68812e+43
*/