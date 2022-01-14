
#include <iostream>

void ToUpper(const char* _Left, char* _Right)
{
	int i = 0;
	for (i = 0; _Left[i] != 0; i += 1)
	{
		if (97 <= _Left[i] && _Left[i] <= 122)
		{
			_Right[i] = _Left[i] - 32;
		}
		else
		{
			_Right[i] = _Left[i];
		}
	}
	_Right[i] = 0; // 문장 끝 삽입
}

int main()
{
	char Text[100];
	ToUpper("12abCcEee", Text);
	//      "12ABCCEEE"
	printf_s(Text);
}
