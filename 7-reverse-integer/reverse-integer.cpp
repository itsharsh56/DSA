class Solution {
public:
    int reverse(int x) 
    {
        int m;
        long r=0;
        while(x!=0)
        {
            m=x%10;
            r=r*10+m;
            if((r>INT_MAX) || (r<INT_MIN))
            return 0;
            x=x/10;
            
        }
        return r;
    }
};