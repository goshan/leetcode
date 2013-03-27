#include <iostream>
#include <vector>
using namespace std;


struct node
{
	/* data */
	int row;
	int col;
};

void init_board(vector<vector<char> > &board, vector<struct node> &open){
	for (int i = 0; i < board.size(); ++i)
	{
		/* code */
		for (int j=0; j<board[i].size(); j++){
			if ((i == 0 || i == board.size()-1 || j == 0 || j == board[i].size()-1) && board[i][j] == 'O')
			{
				/* code */
				board[i][j] = 'F';
				struct node n;
				n.row = i;
				n.col = j;
				open.push_back(n);
			}
		}
	}
}


void check_surround(vector<vector<char> > &board, vector<struct node> &open){
	struct node n = open.back();
	open.pop_back();
	int row = n.row;
	int col = n.col;
	if (row-1 > 0 && row-1 < board.size()-1 && col > 0 && col < board[0].size()-1 && board[row-1][col] == 'O')
	{
		/* code */
		board[row-1][col] = 'F';
		struct node temp;
		temp.row = row-1;
		temp.col = col;
		open.push_back(temp);
	}
	if (row+1 > 0 && row+1 < board.size()-1 && col > 0 && col < board[0].size()-1 && board[row+1][col] == 'O')
	{
		/* code */
		board[row+1][col] = 'F';
		struct node temp;
		temp.row = row+1;
		temp.col = col;
		open.push_back(temp);
	}
	if (row > 0 && row < board.size()-1 && col-1 > 0 && col-1 < board[0].size()-1 && board[row][col-1] == 'O')
	{
		/* code */
		board[row][col-1] = 'F';
		struct node temp;
		temp.row = row;
		temp.col = col-1;
		open.push_back(temp);
	}
	if (row > 0 && row < board.size()-1 && col+1 > 0 && col+1 < board[0].size()-1 && board[row][col+1] == 'O')
	{
		/* code */
		board[row][col+1] = 'F';
		struct node temp;
		temp.row = row;
		temp.col = col+1;
		open.push_back(temp);
	}
}


void flip(vector<vector<char> > &board){
	for (int i = 0; i < board.size(); ++i)
	{
		/* code */
		for (int j = 0; j < board[i].size(); ++j)
		{
			/* code */
			if (board[i][j] == 'O')
			{
				/* code */
				board[i][j] = 'X';
			}
			else if (board[i][j] == 'F')
			{
				/* code */
				board[i][j] = 'O';
			}
		}
	}
}

void solve(vector<vector<char> > &board) {
	// Start typing your C/C++ solution below
	// DO NOT write int main() function
	if (board.size() <= 2)
    {
    	/* code */
    	return;
    }
	
	vector<struct node> open;
	init_board(board, open);
	while(open.size() != 0){
		check_surround(board, open);
	}
	flip(board);
}

int main(){
	int n, m;
	cin >>n >>m;
	vector<vector<char> > board(n, vector<char> (m));
	for (int i = 0; i < n; ++i)
	{
		/* code */
		for (int j=0; j<m; j++){
			cin >>board[i][j];
		}
	}
	solve(board);
	for (int i = 0; i < n; ++i)
	{
		/* code */
		for (int j=0; j<m; j++){
			cout <<board[i][j] <<" ";
		}
		cout <<endl;
	}
	return 0;
} 