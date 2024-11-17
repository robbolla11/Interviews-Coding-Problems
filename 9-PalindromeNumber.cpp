class Solution {
public:
    bool isPalindrome(long long x) {
        if(x<0)
            return false;
        if(x==0)
            return true;

        long long copia = x;
        long long pal = 0;

        while (x > 0) 
        {
            pal = pal * 10 + x % 10;
            x /= 10;
        }

        return copia == pal;
    }
};
