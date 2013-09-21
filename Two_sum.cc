vector<int> twoSum(vector<int> &numbers, int target) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    map<int, int> need;
    for (int i=0; i<numbers.size(); i++){
        if (numbers[i] <= target){
            if (need.count(numbers[i])){
                vector<int> res;
                res.push_back(need[numbers[i]]+1);
                res.push_back(i+1);
                return res;
            }
            else {
                need[target-numbers[i]] = i;
            }
        }
    }
    vector<int> res;
    return res;
}