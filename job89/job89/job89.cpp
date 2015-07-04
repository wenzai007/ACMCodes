#include<stdio.h>
#include<string.h>
int ans[22]; //���滷��ÿһ�����������
bool hash[22]; //���֮ǰ�Ѿ������뻷�е���
int n;
int prime[] = {2,3,5,7,11,13,17,19,23,29,31,37,41}; //����,�����ж�һ�����Ƿ�Ϊ����������֮�в���,��Ϊ���벻����16���������͹��ɵ��������ڸ�������
bool judge(int x){ //�ж�һ�����Ƿ�Ϊ����
	for(int i = 0;i < 13;i ++){
		if(prime[i] == x) return true; //�����������в���,�����ҳɹ������Ϊ����
	}
	return false; //����������
}
void check(){ //�������ɻ��ݷ�ö�ٵõ��Ľ�
	if(judge(ans[n] + ans[1]) == false) return; //�ж����һ�������һ�����ĺ��Ƿ�Ϊ����,��������ֱ�ӷ���
	for(int i = 1;i <= n;i ++){ //�����,ע�����һ�����ֺ�û�пո�
		if(i != 1) printf(" ");
		printf("%d",ans[i]);
	}
	printf("\n");
}
void DFS(int num){ //�ݹ�ö��,numΪ��ǰ�Ѿ����뻷�е�����
	if(num > 1) //����������ִ���һ��ʱ
		if(judge(ans[num] + ans[num - 1]) == false) return; //�ж�����������ֵĺ��Ƿ�Ϊ����,�������򷵻ؼ���ö�ٵ�num����
	if(num == n){ //���Ѿ�������n����
		check(); //������
		return; //����,����ö����һ���
	}
	for(int i = 2;i <= n;i ++){ //����һ����
		if(hash[i] == false){ //��i��û�б����뻷��
			hash[i] = true; //���iΪ�Ѿ�ʹ��
			ans[num + 1] = i; //��������ַ���ans������
			DFS(num + 1); //�������Է�����һ����
			hash[i] = false; //�����ݻ�ö�ٸ�λ����ʱ,��i���±��Ϊδʹ��
		}
	}
}
int main(){
	int cas = 0; //��¼Case��
	while(scanf("%d",&n) != EOF){
		cas ++; //Case������
		for (int i = 0;i < 22;i ++) hash[i] = false; //��ʼ�������������Ϊδ��ʹ��
		ans[1] = 1; //��һ�����ֺ㶨Ϊ1
		printf("Case %d:\n",cas);//���Case��
		hash[1] = true; //���1��ʹ��
		DFS(1);//�������Է�����һ������
		printf("\n");//�������
	}
	return 0;
}


