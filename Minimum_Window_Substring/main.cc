#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;






string minWindow(string S, string T) {
	// Start typing your C/C++ solution below
	// DO NOT write int main() function
	int t_chars[256];
	int t_char_num = 0;
	memset(t_chars, 0, sizeof(t_chars));
	for (int i = 0; i < T.length(); ++i)
	{
		/* code */
		if (t_chars[T[i]] == 0)
		{
			/* code */
			t_char_num ++;
		}
		t_chars[T[i]] ++;
	}
	
	int s_chars[256];
	int s_char_num = 0;
	memset(s_chars, 0, sizeof(s_chars));

	int head = 0;
	int tail = 0;
	int min_head = 0;
	int min_tail = 1;
	int min = 100000;
	while (tail < S.length())
	{
		/* code */
		s_chars[S[tail]] ++;
		if (s_chars[S[tail]] == t_chars[S[tail]] && t_chars[S[tail]] != 0)
		{
			/* code */
			s_char_num ++;
		}
		if (t_chars[S[tail]] > 0 && s_chars[S[tail]] >= t_chars[S[tail]] && s_char_num == t_char_num)
		{
			/* code */
			while (s_chars[S[head]]-1 >= t_chars[S[head]]){
				s_chars[S[head]] --;
				if (t_chars[S[head]] != 0 && s_chars[S[head]] == 0)
				{
					/* code */
					s_char_num --;
				}
				head ++;
			}
			int w = tail-head+1;
			if (w < min)
			{
				/* code */
				min = w;
				min_head = head;
				min_tail = tail+1;
			}
		}
		tail ++;
	}

	if (min == 100000)
	{
		/* code */
		return  "";
	}
	else {
		return S.substr(min_head, min_tail - min_head);
	}
}


int main(int argc, char const *argv[])
{
	/* code */
	string S = "acbbaca";
	string T = "aba";
	cout <<minWindow(S, T) <<endl;
	return 0;
}