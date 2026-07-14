class Solution {
public:
    bool isPowerOfTwo(int n) 
    {
        // if(n<=0){
        // return false;
        // }
        // for(long long i = 1 ; i<=n ;i = i*2){
        //     if (i == n){
        //      return true;
        //      }
        //  }
        //  return false;

        if(n > 0 && (n &(n - 1)) == 0)
        {
            return true ;
        }
        else
        {
            return false;
        }
    }
};