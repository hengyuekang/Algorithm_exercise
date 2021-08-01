#include<iostream>
#include<string>
#include<climits>
using namespace std;
int N;
int main()
{
    string f_name="Absent";
    string m_name(f_name);
    string f_id,m_id;
    int f_grade=-1;
    int m_grade=INT_MAX;
    cin>>N;
    for(int i=0; i<N;i++)
    {
        string name,gender,id;
        int grade;
        cin>>name>>gender>>id>>grade;
        if(gender=="M")
        {
            if(grade<m_grade)
            {
                m_name=name;
                m_id=id;
                m_grade=grade;
            }
        }
        else
        {
            if(grade>f_grade)
            {
                f_name=name;
                f_id=id;
                f_grade=grade;
            }
        }
    }
    if(f_name=="Absent")
    {
        cout<<f_name<<"\n";
        cout<<m_name<<" "<<m_id<<"\n";
        cout<<"NA";
    }
    else if(m_name=="Absent")
    {
        cout<<f_name<<" "<<f_id<<"\n";
        cout<<m_name<<"\n";
        cout<<"NA";
    }
    else
    {
        cout<<f_name<<" "<<f_id<<endl;
        cout<<m_name<<" "<<m_id<<endl;
        cout<<f_grade-m_grade;
    }
    return 0;
}