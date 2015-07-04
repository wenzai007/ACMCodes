#include<iostream>   
#include<string>   
#include<algorithm>   
#include<vector>   
#include<functional>   
using namespace std;  
typedef struct student  
{  
    string num;  
    int grade;  
    int final_rank;  
    int location_num;  
    int local_rank;  
    //注意以下这段的写法   
    bool operator > (const student& s)const  
    {  
        if(grade != s.grade)  
            return grade > s.grade;  
        else return num < s.num;  
    }  
}student;  
  
#define max 30000   
#define INF 0x6FFFFFFF   
vector<student> v;  
  
int main()  
{  
    int n,m;  
    int i,j;  
    cin>>n;  
    for(i=0; i<n; i++)  
    {  
        cin>>m;  
        vector<student> temp(m);  
        for(j=0; j<m; j++)  
        {  
            cin>>temp[j].num>>temp[j].grade;  
            temp[j].location_num = i+1;  
        }  
        sort(temp.begin(),temp.end(),greater<student>());  
        int nowGrade = INF;  
        int nowRank = 0;  
        for(j=0; j<m; j++)  
        {  
            ////   
            //cout<<temp[j].num<<"   "<<temp[j].location_num<<endl;   
            if(temp[j].grade == nowGrade)  
                temp[j].local_rank = nowRank;  
            else  
            {  
                temp[j].local_rank = j+1;  
                nowRank = j + 1;  
                nowGrade = temp[j].grade;  
            }  
            v.push_back(temp[j]);  
        }  
    }  
    // 处理global_rank   
    sort(v.begin(),v.end(),greater<student>());   //此处用到greater，头文件应该有#include<functional>   
    int nowGrade = INF;  
    int nowRank = 0;  
    cout<<v.size()<<endl;  
    for(i=0; i<v.size(); i++)  
    {  
        if(v[i].grade == nowGrade)  
            v[i].final_rank = nowRank;  
        else   
        {  
            nowRank = i+1;   
            v[i].final_rank = i+1;  
            nowGrade = v[i].grade;  
        }  
        cout<<v[i].num<<" "<<v[i].final_rank<<" "<<v[i].location_num<<" "<<v[i].local_rank<<endl;  
    }  
  
    return 0;  
}  
