
#include <iostream>

void Cut(const char* _Sorce, int _Start, int _End, char* _Result)
{
	int idx = 0;
	for (int i = _Start; i <= _End; i += 1)
	{
		_Result[idx] = _Sorce[i];
		idx += 1;
	}
}

int main()
{
	char Text[100] = { };
	Cut("0123456789", 2, 7, Text);
	printf_s(Text);
	// "234567"
}
