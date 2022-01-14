
#include <iostream>

int CountLen(const char* _String) // Char 크기 계산
{
	int Len = 0;
	for (int i = 0; _String[i] != 0; i += 1)
	{
		Len += 1;
	}
	return Len;
}

void Rervers(const char* _Sorce, char* _Result)
{
	int StrLen = CountLen(_Sorce);
	int index = 0;

	for (int i = StrLen - 1; i >= 0; i -= 1)
	{
		_Result[index] = _Sorce[i];
		index += 1;
	}

}

int main()
{
	char Text[100] = { };
	Rervers("0123456789", Text);
	printf_s(Text);

}
