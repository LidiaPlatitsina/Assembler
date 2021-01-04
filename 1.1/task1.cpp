// «адача 1 (5 вар.): указать те символы, которые есть и в первой и во второй строке.

#include <iostream>

int main()
{
	const int N = 255;
	char res[N];
	char vvod1[] = "Input first string\n";
	char vvod2[] = "Input second string\n";
	char sd[] = "Strings are different";
	char str1[N];
	char str2[N];
	__asm
	{
		// считываем строки
		lea     eax, vvod1
		; помещаю в переменную eax адрес на vvod1
		push    eax
		; помещаю в стек переменную eax, чтобы потом вывести
		call    printf
		; вывожу vvod1
		add     esp, 4
		; очищаю стек

		mov     eax, N
		; копирую значени€ из eax в N
		push    eax
		lea     eax, str1
		push    eax
		call    gets_s
		; считаю строку str1
		add     esp, 8

		lea     eax, vvod2
		push    eax
		call    printf
		; вывожу vvod2
		add     esp, 4

		mov     eax, N
		push    eax
		lea     eax, str2
		push    eax
		call    gets_s
		; считаю строку str2
		add     esp, 8

		lea     edx, str2
		; сохран€ю адрес строки str1
		lea     ebx, str1
		; сохран€ю адрес строки str2

		xor eax, eax
		; обнул€ю eax
		xor edi, edi
		; в переменной edi сохран€етс€ количество совпавших элементов

		START :
		; главный цикл
			xor esi, esi
			; переменна€ esi - это текущий счЄтчик
			mov     cl, [ebx][eax]
			; помещаю в cl первый символ первой строчки
			inc     eax
			; увеличиваю счетчик(индекс символа в str1)
			cmp     cl, 0
			; провер€ю конец ли строки
			je      NEW_RES
			; если строка закончилась, то будет вывод результата


		START2 :
		; ставниваем символ из str1 с каждым символом str2

			mov ch, [edx][esi]
			; положила в ch следующий символ строки str2
			cmp     ch, 0
			; провер€ю конец ли строки
			je      END
			; если строка кончилась, то будет обнуление текущего счетчика,
			; дл€ такого чтобы дальше сравнивать со следущим символом стороки str1


			cmp     cl, ch
			; сравниваем символы
			je      FND
			; если символы совпали, то сообщаем, что нашли
			inc     esi
			; если нет, то увеличиваю текущий счетчик
			jmp     START2
			; далее провер€ю следующий символ строки str2

		END :
			jmp START
			; возращаюсь в главный цикл

		FND :
			mov[res][edi], cl
			; помещаю в строку res совпавший символ
			inc     edi
			; увеличиваю счетчик совпавших символов
			jmp		START
			; переходим в главный цикл


		NEW_RES :
			cmp     edi, 0
			; проверка на совпавшие символы
			je   DIFF_STR

			mov[res][edi], 0
			; добавл€ю 0 как конец строки
			jmp     PRNT

		DIFF_STR :
			lea     eax, sd
			push    eax
			call    printf
			; вывожу, что совпадений нет
			add     esp, 4
			jmp     EXT


		PRNT :
			lea     eax, res
			push    eax
			call    printf
			add     esp, 4
		EXT :
	}
	return 0;
}

/*–езультаты выполнени€ работы:
1)Input first string
мама
Input second string
папа
аа
2)Input first string
figb
Input second string
bkgl
gb
3)Input first string
кот
Input second string
мышь
Strings are different
4)Input first string
gjdo
Input second string
bkvr
Strings are different
*/
