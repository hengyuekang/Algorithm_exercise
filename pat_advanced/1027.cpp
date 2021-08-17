#include <cstdio>
char map[13]={'0', '1', '2', '3', '4', '5', '6', '7', '8', '9','A','B','C'};
int main()
{
    int r,g,b;
    scanf("%d%d%d",&r,&g,&b);
    printf("#%c%c",map[r/13],map[r%13]);
    printf("%c%c",map[g/13],map[g%13]);
    printf("%c%c",map[b/13],map[b%13]);
    return 0;
}