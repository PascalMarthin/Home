
#include <iostream>

void CharChange(char* _Text, char _Prev, char _Next)
{
	for (int i = 0; _Text[i] != 0; i += 1)
	{
		if (_Text[i] == _Prev)
		{
			_Text[i] = _Next;
		}
	}
}

int main()
{
	char Text[100] = "aa, bb, cc, dd";

	CharChange(Text, ',', '|');
	// aa| bb| cc| dd

	printf_s(Text);
}
