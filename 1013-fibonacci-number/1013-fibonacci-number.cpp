class Solution {
public:

   
   int *a = (int*) calloc(33, sizeof(int));
   int recurse(int n){
        if(a[n]!=0) return a[n];
         if(n==0) return 0;
        if(n==1) return 1;
        
        a[n]= fib(n-1)+fib(n-2);
        return a[n];
        

   }
    int fib(int n) {
       return recurse(n);
    }

};