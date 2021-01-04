// ������ 1 (5 ���.): ������� �� �������, ������� ���� � � ������ � �� ������ ������.

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
		// ��������� ������
		lea     eax, vvod1
		; ������� � ���������� eax ����� �� vvod1
		push    eax
		; ������� � ���� ���������� eax, ����� ����� �������
		call    printf
		; ������ vvod1
		add     esp, 4
		; ������ ����

		mov     eax, N
		; ������� �������� �� eax � N
		push    eax
		lea     eax, str1
		push    eax
		call    gets_s
		; ������ ������ str1
		add     esp, 8

		lea     eax, vvod2
		push    eax
		call    printf
		; ������ vvod2
		add     esp, 4

		mov     eax, N
		push    eax
		lea     eax, str2
		push    eax
		call    gets_s
		; ������ ������ str2
		add     esp, 8

		lea     edx, str2
		; �������� ����� ������ str1
		lea     ebx, str1
		; �������� ����� ������ str2

		xor eax, eax
		; ������� eax
		xor edi, edi
		; � ���������� edi ����������� ���������� ��������� ���������

		START :
		; ������� ����
			xor esi, esi
			; ���������� esi - ��� ������� �������
			mov     cl, [ebx][eax]
			; ������� � cl ������ ������ ������ �������
			inc     eax
			; ���������� �������(������ ������� � str1)
			cmp     cl, 0
			; �������� ����� �� ������
			je      NEW_RES
			; ���� ������ �����������, �� ����� ����� ����������


		START2 :
		; ���������� ������ �� str1 � ������ �������� str2

			mov ch, [edx][esi]
			; �������� � ch ��������� ������ ������ str2
			cmp     ch, 0
			; �������� ����� �� ������
			je      END
			; ���� ������ ���������, �� ����� ��������� �������� ��������,
			; ��� ������ ����� ������ ���������� �� �������� �������� ������� str1


			cmp     cl, ch
			; ���������� �������
			je      FND
			; ���� ������� �������, �� ��������, ��� �����
			inc     esi
			; ���� ���, �� ���������� ������� �������
			jmp     START2
			; ����� �������� ��������� ������ ������ str2

		END :
			jmp START
			; ���������� � ������� ����

		FND :
			mov[res][edi], cl
			; ������� � ������ res ��������� ������
			inc     edi
			; ���������� ������� ��������� ��������
			jmp		START
			; ��������� � ������� ����


		NEW_RES :
			cmp     edi, 0
			; �������� �� ��������� �������
			je   DIFF_STR

			mov[res][edi], 0
			; �������� 0 ��� ����� ������
			jmp     PRNT

		DIFF_STR :
			lea     eax, sd
			push    eax
			call    printf
			; ������, ��� ���������� ���
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

/*���������� ���������� ������:
1)Input first string
����
Input second string
����
��
2)Input first string
figb
Input second string
bkgl
gb
3)Input first string
���
Input second string
����
Strings are different
4)Input first string
gjdo
Input second string
bkvr
Strings are different
*/
