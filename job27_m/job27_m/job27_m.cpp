#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<stack>
#include<queue>
using namespace std;
//stack <char> opera;//����Ī�������ֹͣ��!! �Բ� Ӧ����int��
stack <int> opera;
stack <double> nums;
int map[5][5]={//�ֱ�Ϊ#�� + �� * / ij����Ҫ��ȥ�ı��Ѿ���ȥ��
	1,0,0,0,0, 			//����������ȼ�  �Ǵ���С����Ļ�����ջ
	1,0,0,0,0,   //С�Ļ���ô��  �ȼ���ǰ��Ķ���ֱ�����ڵ������
	1,0,0,0,0,			//��ջ���Ĵ�
	1,1,1,0,0,
	1,1,1,0,0,
};// �����ʱ��ֺ�
char instr[220];
//��һ������ĺ���
void getnext(bool &optype,int &value,int &ipx){//��������Ϊ�˴��Ĳ���ֵ���������ĵ�ַ���ı���
	//��������û�л������ �� ���ո��ַ� 
	if(ipx==0&&opera.empty()){//������ipx���д��� ��һ����Ȼ��0
		optype=true;
		value=0;
		return;
	}
	if(instr[ipx]==0){
		optype=true;
		value=0;
		return;
	}
	//if(instr[ipx]>'9'&&instr[ipx]<'0'){//������sb ����Ϊ�������Ķ���ô&&
	if(instr[ipx]>'9'||instr[ipx]<'0'){
		optype=true;
		if(instr[ipx]=='+')value=1;
		else if(instr[ipx]=='-')value=2;
		else if(instr[ipx]=='*')value=3;
		else if(instr[ipx]=='/')value=4;
		ipx+=2;//ֱ�������˿ո� �������һ���ַ��������������
		//���Բ��ÿ����Ƿ������һ���ַ�
		return;
	}
	if(instr[ipx]>='0'&&instr[ipx]<='9'){
		optype=false;
		int numstr=0;
		//for (;instr[ipx]!=' ';ipx++){//�����ٿ�����һ��û��ͷ�����
		for (;instr[ipx]!=' '&&instr[ipx]!=0;ipx++){
			numstr*=10;
			//numstr+=instr[ipx];���� û�м�ȥ�ַ���'0'
			numstr+=instr[ipx]-'0';
		}
		value=numstr;
		if(instr[ipx]!=0) ipx++;// ���������ֲ������һ����ô�����ո�
		return;//  ����Ļ� ��ֱ�ӷ���  �����ȴ���һ�ν��뺯�� �������
		// ������д���
	}
}
int main(){
	freopen("in.txt","r",stdin);

	//while (scanf("%s",instr)!=EOF){  ������� scanf�����ո�ͽ�ȡ
	//������Ҫ��ȡһ���У�������
	while(gets(instr)){
		//if(instr[0]=='0')break;��Ͳ����� ��һ��������Ҳ������0��
		while (!opera.empty()) opera.pop();
		while (!nums.empty()) nums.pop();
		if(instr[0]=='0'&&instr[1]==0) break;
		int idx=0;int value;bool optype;double res;
		while (1){
			getnext(optype,value,idx);
			if(optype==false){
				nums.push((double)value);
				//continue;
			}
			else {
				if (opera.empty()||map[value][opera.top()]==1){
					opera.push(value);
				}
				else {
					while(map[value][opera.top()]==0){
						int symboltmp=opera.top();
						opera.pop();
						double num1=nums.top();
						nums.pop();
						double num2=nums.top();
						nums.pop();
						switch(symboltmp){//ע����num2��ǰ��
						case 1: res= num1+num2;
							break;
						case 2: res= num2-num1;
							break;
						case 3: res= num1*num2;
							break;
						case 4: res=num2/num1;
							break;

						}
						nums.push(res);
					}
					opera.push(value);

				}
				//if(opera.size()==2&&opera.top()=='0'){//���򲻱���Ҳ�����Ҳ
				//Ҳ���ܿ����� ��Ϊ�����ܵ���'0
				//ֻ����Ϊ0
			}
			if(opera.size()==2&&opera.top()==0)
				//opera.pop();
				//opera.pop();
				break;
		}
		//printf("%.2lf\n",res);
		printf("%.2lf\n",nums.top());
	}
	return 0;
}






















//effect


















//effect
