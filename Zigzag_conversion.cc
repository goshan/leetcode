string convert(string s, int nRows) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function    
    if (nRows == 1){
        return s;
    }
    string res = "";
    int interval = nRows*2-2;
    for (int j=0; j<nRows; j++){
        for (int i=j; i<s.length(); i+=interval){
            res += s.substr(i, 1);
            if (j != 0 && j != nRows-1 && i+interval-2*j < s.length()){
                res += s.substr(i+interval-2*j, 1);
            }
        }
    }
    return res;
}