int mySqrt(int x) 
{
    long left = 0;
    long right = x;
    long ans = 0;

    while(left <= right)
    {
        long mid = (left + right) / 2;

        if(mid * mid == x)
            return mid;

        if(mid * mid < x)
        {
            ans = mid;
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    return ans;
}
