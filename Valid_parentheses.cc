bool isValid(string s) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    vector<char> bracket;
    for (int i=0; i<s.length(); i++){
        if (s[i] == '('){
            bracket.push_back(s[i]);
        }
        else if (s[i] == ')'){
            if (bracket.size() == 0 || bracket.back() != '('){
                return false;
            }
            bracket.pop_back();
        }
        else if (s[i] == '['){
            bracket.push_back(s[i]);
        }
        else if (s[i] == ']'){
            if (bracket.size() == 0 || bracket.back() != '['){
                return false;
            }
            bracket.pop_back();
        }
        else if (s[i] == '{'){
            bracket.push_back(s[i]);
        }
        else if (s[i] == '}'){
            if (bracket.size() == 0 || bracket.back() != '{'){
                return false;
            }
            bracket.pop_back();
        }
    }
    return bracket.size() == 0;
}