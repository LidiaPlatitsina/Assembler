//������ �������
//���������� ������� ����������� � ��� �������
//��������� �������� ������� f, ������� ������� � �������, � ����� x,
//��������� ���������� � ��� �������.������������ ��������� �� ��� ���, ����
//����� ���� ���� �� ����� ������, �� ������, ��������� ��������� epsilon
//5. exp(x)
#include <iostream>

double f(double input_x, double input_epsilon = 1e-5)
{
	__asm
	{
		fld1
		; 4 - Sum, / �������� � ���� ������ /
		fld     input_epsilon
		; 3 - input_epsilon, / �������� epsilon /
		fld     input_x
		; 2 - x, / �������� x /
		fld1
		; 1 - i, / �������� 1 /
		fld     st(1)
		; 0 - Xi

		START:
		fadd    st(4), st(0)
			; ��� ������ ������ : Sum += Xi
			fld1
			; ��� ������ ������ : st(0) = 1, st(2) = i
			faddp   st(2), st(0)
			; ��������� i � �������� ������� �����, ������� ���� 1
			fmul    st(0), st(2)
			; ��� ������ ������ : Xi * = x
			fdiv    st(0), st(1)
			; ��� ������ ������ : Xi /= i
			fld     st(0)
			; Xi
			fabs
			; ��� ������ ������ : ������ Xi
			fcomip  st(0), st(4)
			; ��� ������ ������ : while (abs(Xi) > epsilon), / ���������� � ������ ������� /
			jnbe START

			fstp st(0)
			; ���������� i
			fstp st(0)
			; ���������� x
			fstp st(0)
			; ���������� epsilon
			fstp st(0)
			; ���������� Sum, � ��������� ��� ������ �������
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

/*���������� ���������: 
1)Input your x: 0
Result is: 1
2)Input your x: -1
Result is: 0.367882
3)Input your x: 1
Result is: 2.71828
4)Input your x: 100
Result is: 2.68812e+43
*/