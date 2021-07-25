#include <iostream>
#include <vector>
#include <string>
using namespace std;
int shuffle_time;
vector<int> shuffle_order;
vector<string> cards;
vector<string> const_string={"S","H","C","D"};
void initCards()
{
    string card;
    for(auto first_char:const_string)
    {
        for(int i=0;i<13;i++)
    {
        card=first_char+to_string(i+1);
        cards.push_back(card);
    }

    }
    cards.push_back("J1");
    cards.push_back("J2");
}
vector<string> shuffleCards()
{
    vector<string> res(54);
    for(int i=0;i<shuffle_time;i++)
    {
        for(int j=0;j<shuffle_order.size();j++)
        {
            res[shuffle_order[j]-1]=cards[j];
        }
        cards=res;
    }
    return res;
}
int main()
{
    initCards();
    cin >>shuffle_time;
    int num=0;
    for(int i=0;i<54;i++)
    {
        cin>>num;
        shuffle_order.push_back(num);
    }
    vector<string> res=shuffleCards();
    for(int i=0;i<53;i++)
    {
        cout<<res[i]<<" ";
    }
    cout<<res[53];
    return 0;
}