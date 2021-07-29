#include<cstdio>
int main()
{
    int T,tcase=1;
    scanf("%d",&T);
    while(T--)
    {
        // -2^63~2^63-1
        long long a,b,c;
        scanf("%lld%lld%lld",&a,&b,&c);
        long long res=a+b;
        bool flag;
        // res:-2^63~-2
        if(a>0&&b>0&&res<0)flag=true;
        // res:0~2^63-1
        else if(a<0&&b<0&&res>=0)flag=false;
        else if(res>c)flag=true;
        else flag=false;
        if(flag)
        {
            printf("Case #%d: true\n",tcase++);
        }
        else
        {
            printf("Case #%d: false\n",tcase++);
        }
    }
    return 0;
}
// long long:64 bits
// some error in description