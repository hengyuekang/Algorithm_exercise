#include<cstdio>
int main()
{
    float res=1;
    float max_bet=-1.0;
    int max_index=0;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            float bet=0.0;
            scanf("%f",&bet);
            if(bet>max_bet)
            {
                max_bet=bet;
                max_index=j;
            }
        }
        res*=max_bet;
        max_bet=-1.0;
        switch(max_index)
        {
            case 0:
            {
                printf("W ");
                break;
            }
            case 1:
            {
                printf("T ");
                break;
            }
            case 2:
            {
                printf("L ");
                break;
            }
            default:
                break;
        }
    }
    res=(res*0.65-1)*2;
    printf("%.2f",res);
    return 0;
}