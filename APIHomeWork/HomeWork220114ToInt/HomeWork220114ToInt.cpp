
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

int ToInt(const char* _Left)
{
	int StrLen = CountLen(_Left);
	int Zero = 1;
	int answer = 0;

	for (int i = 1; i < StrLen; i += 1)
	{
		Zero *= 10;
	}

	for (int i = 0; _Left[i] != 0; i += 1)
	{
		answer += (_Left[i] - 48) * Zero;
		Zero /= 10;
	}

	return answer;
}

int main()
{

	int Value = ToInt("15815");
	Value;

}
