// regard the same rank as two different rank when calculating ranks,e.g:1,2,3,3,5(4 people before last)
// second line:the weight of the mouses following the order from 0 to i-1
// third line:the order of competition,every number is the order of the mouses
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int NP,NG;
int main()
{
    cin>>NP>>NG;
    vector<pair<int,int>> mouses(NP);
    for(int i=0;i<NP;i++)
    {
        int weight;
        cin>>weight;
        mouses[i].first=weight;
    }
    queue<int> match;
    for(int i=0;i<NP;i++)
    {
        int order;
        cin>>order;
        match.push(order);
    }
    int num=NP;
    int group=0;
    // haven't determine the champion
    while(match.size()!=1)
    {
        if((num%NG)==0)
        {
            group=num/NG;
        }
        else
        {
            group=num/NG+1;
        }
        for(int i=0;i<group;i++)
        {
            int max_weight=match.front();
            for(int j=0;j<NG;j++)
            {
                // the number of group<NG,and current pos is beyond the match
                // num:current match size
                if((i*NG+j+1)>num)
                {
                    break;
                }
                if(mouses[match.front()].first>mouses[max_weight].first)
                {
                    max_weight=match.front();
                }

                mouses[match.front()].second=group+1;

                match.pop();

            }
            match.push(max_weight);
        }
        num=match.size();
    }
    mouses[match.front()].second=1;
    cout<<mouses[0].second;
    for(int i=1;i<NP;i++)
    {
        cout<<" "<<mouses[i].second;
    }
    return 0;
}
// slowly read the text to clear the purpose
// think twice,code once!!