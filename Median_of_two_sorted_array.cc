double findMedianSortedArrays(int A[], int m, int B[], int n) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    int index = 0;
    int a = 0;
    int b = 0;
    int last = 0;
    int current = 0;
    while (index <= (m+n)/2){
        last = current;
        if (a == m && b == n){
            return 0;
        }
        else if (a == m && b != n){
            current = B[b];
            b ++;
        }
        else if (a != m && b == n){
            current = A[a];
            a++;
        }
        else if (A[a] <= B[b]){
            current = A[a];
            a++;
        }
        else {
            current = B[b];
            b ++;
        }
        index ++;
    }
    return ((m+n)%2==0 ? (double)(current+last)/2 : current);
}