//���ϵ�Դ����

#include <stdio.h>
int main () {
	int h;
	while (scanf ("%d",&h) != EOF) {
		int maxLine = h + (h - 1) * 2; //�������һ�а������ǺŸ���
		for (int i = 1;i <= h;i ++) { //�������ÿ����Ϣ
			for (int j = 1;j <= maxLine;j ++) { //�������ÿ�е��еĿո���Ǻ�
				if (j < maxLine - h - (i - 1) * 2 + 1) //����ո�
					printf(" ");
				else //����Ǻ�
					printf("*");
			}
			printf("\n"); //�������
		}
	}
	return 0;
}