//Generate fibonacci number given the nth term to be calculated.
//Recursive.

int fibo (int n) {
    
    if (n <= 1) {
        return n;       //fibonacci for both 0 and 1th term is 1.
    }
    else {
        return (fibo(n-1) + fibo(n-2));
    }

}

int main() {

}