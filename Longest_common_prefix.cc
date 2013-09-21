string longestCommonPrefix(vector<string> &strs) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    if (strs.size() == 0){
        return "";
    }
    else if (strs.size() == 1){
        return strs[0];
    }
    vector<int> pointer(strs.size(), 0);
    int i = 0;
    while (1){
        for (int j=1; j<strs.size(); j++){
            if (i == strs[j].length() || i == strs[j-1].length() || strs[j][i] != strs[j-1][i]){
                return strs[0].substr(0, i);
            }
        }
        i ++;
    }
    return strs[0];
}