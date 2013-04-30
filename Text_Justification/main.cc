#include <iostream>
#include <string>
#include <vector>
using namespace std;




vector<string> gen_spaces(int spaces_sum, int spaces_num){
	if (spaces_num == 0)
	{
		/* code */
		spaces_num = 1;
	}
	int mod = spaces_sum%spaces_num;
	int basic = spaces_sum/spaces_num;
	vector<string> res;
	for (int i = 0; i < spaces_num; ++i)
	{
		/* code */
		int len = i < mod ? basic+1 : basic;
		string elem = "";
		for (int j=0; j<len; j++){
			elem += " ";
		}
		res.push_back(elem);
	}
	return res;
}

string combine_words_and_spaces(vector<string> &words, int start_index, int end_index, vector<string> &spaces){
	if (end_index-start_index == 1)
	{
		/* code */
		return words[start_index]+spaces[0];
	}
	string res = "";
	for (int i = start_index; i < end_index-1; ++i)
	{
		/* code */
		res += words[i]+spaces[i-start_index];
	}
	res += words[end_index-1];
	return res;
}

vector<string> fullJustify(vector<string> &words, int L) {
	// Start typing your C/C++ solution below
	// DO NOT write int main() function
	int current_sum = words[0].length();
	int start_index = 0;
	vector<string> res;
	for (int i = 1; i < words.size(); ++i)
	{
		/* code */
		current_sum += words[i].length()+1;
		if (current_sum > L)
		{
			/* code */
			//gen spaces
			int spaces_num = i-start_index-1;
			int spaces_sum = L-current_sum+words[i].length()+1+i-start_index-1;
			vector<string> spaces = gen_spaces(spaces_sum, spaces_num);
			//combine words and spaces
			string content = combine_words_and_spaces(words, start_index, i, spaces);
			res.push_back(content);
			start_index = i;
			current_sum = words[i].length();
		}
	}

	string content = "";
	for (int i = start_index; i < words.size(); ++i)
	{
		/* code */
		content += words[i]+" ";
	}
	content = content.substr(0, content.length()-1);
	string spaces = "";
	for (int i = 0; i < L-content.length(); ++i)
	{
		/* code */
		spaces += " ";
	}
	res.push_back(content+spaces);

	return res;
}


int main(int argc, char const *argv[])
{
	/* code */
	vector<string> words;
	words.push_back("This");
	words.push_back("is");
	words.push_back("an");
	words.push_back("example");
	words.push_back("of");
	words.push_back("text");
	words.push_back("justification.");
	vector<string> res = fullJustify(words, 16);
	for (int i = 0; i < res.size(); ++i)
	{
		/* code */
		cout <<res[i] <<"||" <<endl;
	}
	return 0;
}