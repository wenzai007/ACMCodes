#include<iostream>
#include <map>
#include <string>
using namespace std;
typedef struct tagStudentInfo{
	int nID;
	string strName;
}StudentInfo, *PStudentInfo; //ѧ����Ϣ
int main()
{
	int nSize;
	//��ѧ����Ϣӳ�����
	map<StudentInfo, int>mapStudent;
	map<StudentInfo, int>::iterator iter;
	StudentInfo studentInfo;
	studentInfo.nID = 1;
	studentInfo.strName="student_one";
	mapStudent.insert(pair<StudentInfo, int>(studentInfo, 90));
	studentInfo.nID = 2;
	studentInfo.strName = "student_two";
	mapStudent.insert(pair<StudentInfo, int>(studentInfo, 80));
	for (iter=mapStudent.begin(); iter!=mapStudent.end(); iter++)
		cout<<iter->first.nID<<endl<<iter->first.strName<<endl<<iter->second<<endl;
	return 0;
}