#include <iostream>
#include <vector>
using namespace std;





struct node {
	char con;
	int x;
	int y;
	node(char con, int x, int y) : con(con), x(x), y(y) {}
};


vector<node> gen_next(vector<vector<char> > &board, node &current){
	vector<node> res;
	int x = current.x;
	int y = current.y;
	if (x > 0 && board[x-1][y] != '-')
	{
		/* code */
		node temp(board[x-1][y], x-1, y);
		res.push_back(temp);
	}
	if (x < board.size()-1 && board[x+1][y] != '-')
	{
		/* code */
		node temp(board[x+1][y], x+1, y);
		res.push_back(temp);
	}
	if (y > 0 && board[x][y-1] != '-')
	{
		/* code */
		node temp(board[x][y-1], x, y-1);
		res.push_back(temp);
	}
	if (y < board[x].size()-1 && board[x][y+1] != '-')
	{
		/* code */
		node temp(board[x][y+1], x, y+1);
		res.push_back(temp);
	}
	return res;
}

bool try_next(vector<vector<char> > &board, vector<node> &next, string word){
	for (int i = 0; i < next.size(); ++i)
	{
		/* code */
		if (next[i].con == word[0])
		{
			/* code */
			board[next[i].x][next[i].y] = '-';
			vector<node> sub_next = gen_next(board, next[i]);
			if (word.length() == 1)
			{
				/* code */
				return true;
			}
			else if (try_next(board, sub_next, word.substr(1, word.length()-1)))
			{
				/* code */
				return true;
			}
			board[next[i].x][next[i].y] = next[i].con;
		}
	}
	return false;
}

bool exist(vector<vector<char> > &board, string word) {
	// Start typing your C/C++ solution below
	// DO NOT write int main() function
	if (word.empty())
	{
		/* code */
		return false;
	}
	vector<node> start;
	for (int i = 0; i < board.size(); ++i)
	{
		/* code */
		for (int j=0; j<board[i].size(); j++){
			if (board[i][j] == word[0])
			{
				/* code */
				node temp(board[i][j], i, j);
				start.push_back(temp);
			}
		}
	}
	return try_next(board, start, word);
}


int main(int argc, char const *argv[])
{
	/* code */
	vector<vector<char> > board;
	vector<char> elem1;
	elem1.push_back('A');
	elem1.push_back('B');
	elem1.push_back('C');
	elem1.push_back('E');
	vector<char> elem2;
	elem2.push_back('S');
	elem2.push_back('F');
	elem2.push_back('C');
	elem2.push_back('S');
	vector<char> elem3;
	elem3.push_back('A');
	elem3.push_back('D');
	elem3.push_back('E');
	elem3.push_back('E');
	board.push_back(elem1);
	board.push_back(elem2);
	board.push_back(elem3);
	string word = "ABCCED";
	cout <<exist(board, word) <<endl;
	return 0;
}