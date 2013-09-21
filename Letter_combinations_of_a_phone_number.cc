class Solution {
public:
    string getLetter(int number, int index){
        int offset = (number-2)*3+index;
        if (number > 7){
            offset += 1;
        }
        char c = 'a'+offset;
        stringstream ss;
        ss <<c;
        return ss.str();
    }
    void addLetter(vector<string> &res, const string &digits, string s, int num){
        if (num == digits.length()){
            res.push_back(s);
            return;
        }
        int size = digits[num]=='7' || digits[num]=='9' ? 4 : 3;
        for (int i=0; i<size; i++){
            s += getLetter(digits[num]-'0', i);
            addLetter(res, digits, s, num+1);
            s = s.substr(0, s.length()-1);
        }
        
    }

    vector<string> letterCombinations(string digits) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<string> res;
        string s = "";
        addLetter(res, digits, "", 0);
        return res;
    }
};