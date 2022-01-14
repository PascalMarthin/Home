
#include <iostream>

int CountLen(const char* _String)							 // Char 크기 계산
{
	int Len = 0;
	for (int i = 0; _String[i] != 0; i += 1)
	{
		Len += 1;
	}
	return Len;
}

bool Match(const char* _Left, const char* _Right, int Len) // 일치 여부 검사
{
	for (int i = 0; i < Len; i += 1)
	{
		if (_Left[i] != _Right[i])
		{
			return false;
		}
	}
	return true;
}

void TextChange(char* _Text, const char* _Prev, const char* _Next)
{
	int PrevLen = CountLen(_Prev);				// Prev 길이
	int AnswerIdx = 0, _TextIdx = 0, StrIdx = 0;
	char Answer[100] = { 0, };					// 정답
	char Str[100] = { 0, };						// 판별용

	for (_TextIdx = 0, StrIdx = 0; _Text[_TextIdx] != 0 || Str[0] != 0; _TextIdx += 1, StrIdx += 1)
	{

		Str[StrIdx] = _Text[_TextIdx];
		if (StrIdx > PrevLen - 2)
		{
			if (!Match(Str, _Prev, PrevLen))			// 같은 단어가 아니다
			{
				Answer[AnswerIdx] = Str[0];				// 첫번째만 정답에 삽입
				AnswerIdx += 1;
				for (int k = 1; k <= PrevLen; k += 1)   // 한칸 앞으로 땡기기
				{
					Str[k - 1] = Str[k];
				}
				StrIdx -= 1;

			}
			else										// 같은 단어이다
			{
				for (int k = 0; _Next[k] != 0; k += 1, AnswerIdx += 1)
				{
					Answer[AnswerIdx] = _Next[k];		// 바꾸는 단어로 삽입
				}
				_TextIdx += PrevLen - 2;
				for (int k = 0; Str[k] != 0; k += 1)
				{
					Str[k] = 0;							// 초기화
				}
				StrIdx = -1;							// 증감식 이후에도 0으로 유지
			}
		}

	}

	for (int k = 0; k < 100; k += 1)        // 100은 Text의 최대 값을 넣은 상수임. 
	{										// 상수를 안넣는다면 if문으로 길이변수인
		_Text[k] = Answer[k];				//  AnswerIdx와 _TextIdx를 비교하면 됨
	}

}

int main()
{
	char Text[100] = "aa, bb, aa, bb aa aa aa aaaaaaa ccdffeds";
	TextChange(Text, "aa", "fff");
	// "fff, bb, fff, bb fff fff fff fffffffffa ccdffeds";
	// aa| bb| cc| dd
	printf_s(Text);
}
