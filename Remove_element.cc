int removeElement(int A[], int n, int elem) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    int length = n;
    for (int i=0; i<length; i++){
        if (A[i] == elem){
            length --;
            int temp = A[i];
            A[i] = A[length];
            A[length] = temp;
            i--;
        }
    }
    return length;
}