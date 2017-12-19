/***********************************************************************************
*1.10λ��ί�ܶ�20λѡ�ֽ��д򿪷֣�Ҫ�и��ڼ���ѡ�ִ�ֵ���ʾ��Ϣ���磺����1��ѡ�ִ�֣�
*������������ʾ����2��ѡ�ִ�֣����������ƣ�ֱ��20λѡ�ִ����ϡ�
*2.10λ��ί��ÿλѡ�ֵĴ���ܰ��մӵͷֵ��߷ֵ�����
*3.ȥ��10λ��ί��ֵ�һ����ͷ֡�һ����߷ֺ����ÿλѡ�ֵ�ƽ���÷֡�
*4.��ÿλѡ�ֵ�ƽ���ְ��Ӹߵ��͵�˳�������������ʱҪ��ѡ�ֱ������÷�һ����С�
*5.������ѡ�ֱ��˳�����ѡ�ֱ�ż����Ӧ�ɼ�����ѡ�ֱ�š�ѡ�ֵ÷��������ѡ�ֵ�һ���������Ƚ���
*************************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#pragma warning(disable:4996)

float sum = 0.0;

#define RATER 10     //��ί����
#define COMPETITOR 10//ѡ������
struct player
{
	int No;                 //ѡ�ֵı��
	char name[COMPETITOR];  //ѡ�ֵ�����
	int score[RATER];       //ÿλ��ί��ѡ�ֵĴ��
	float averscore;          //ÿλѡ�ֵ�ƽ����
};
struct player pla[COMPETITOR];

int arr1[COMPETITOR][RATER];
float arr2[COMPETITOR];
//10λѡ�ֵĽṹ��ָ�����飬���ִӸߵ�������
struct player *players[COMPETITOR];

/**********************************��ӭ����*****************************************/
void welcome(void)
{
	printf("========welcome to the judges scoring system========\n");//�⣺��ӭ������ί���ģ��ϵͳ
	printf("        �� 0�� �� ϵ ͳ                  \n");
	printf("        �� 1 �� �� �� ��;               \n");
	printf("        �� 2���¼��ɼ�;                \n");
	printf("        �� 3��������ĳɼ�;            \n");
	printf("        �� 4�ó�ÿλѡ�ֵ�ƽ���ɼ�;       \n");
	printf("        �� 5��ӡ����ѡ������;            \n");
	printf("        �� 6��ӡ��ѡ��;                \n");
}
/**************************************���벿��***************************************/
void input(void)
{

	srand(time(NULL));//���������ͬ��

	printf("  ========��%d��ѡ����Ϣ========\n", COMPETITOR);

	for (int i = 0; i < COMPETITOR; i++)
	{
		printf("     =====����%dλѡ�ִ��=====\n", i + 1);
		printf("     ��ѡ�ֵı�ţ� ");
		scanf("%d", &pla[i].No);
		printf("     ��ѡ�ֵ������� ");
		scanf("%s", &pla[i].name);

		for (int j = 0; j < RATER; j++)
		{
			printf("==��%dλ��ί����ѡ�ֵĴ��==\n", j + 1);
			pla[i].score[j] = rand() % 100;
			printf("           %d��\n", pla[i].score[j]);
			arr1[i][j] = pla[i].score[j];

		}
		printf("\n\n");
	}
}
/********************************�������********************************************/
void output(void)
{
	printf(">>>>>>>>>>>>=====���ֻ��ܱ�=====<<<<<<<<<<<<\n\n");
	printf("���\t�� ��");
	for (int i = 0; i < RATER; i++)
		printf("\t��%dλ��ί", i + 1);
	printf("\n");
	for (int k = 0; k < COMPETITOR; k++)
	{
		printf("%4d\t%4s", pla[k].No, pla[k].name);
		for (int j = 0; j < RATER; j++)
			printf("\t%d\t", pla[k].score[j]);
		printf("\n");
	}

}
/************************************����ί�Ĵ������**************************************************/

void persort(void)
{
	for (int k = 0; k < COMPETITOR; k++)
	{
		//ð������
		int temp = 0;
		//����
		//���ѭ����������һ���߼���
		for (int i = 0; i<RATER - 1; i++)
		{
			//�ڲ�ѭ������ʼ����Ƚϣ��������
			//ǰһ�����Ⱥ�һ�������򽻻�
			for (int j = 0; j<RATER - 1 - i; j++)
			{
				if (pla[k].score[j]>pla[k].score[j + 1])
				{
					//��λ
					temp = pla[k].score[j];
					pla[k].score[j] = pla[k].score[j + 1];
					pla[k].score[j + 1] = temp;
				}
			}
		}
	}
	printf("\n>>>==��ί��ÿλѡ�ֵĴ���ܰ��մӵͷֵ��߷ֵ�����==<<<\n");
	for (int k = 0; k < COMPETITOR; k++)
	{
		printf("%4d\t%4s", pla[k].No, pla[k].name);
		for (int j = 0; j < RATER; j++)
			printf("\t%d\t", pla[k].score[j]);
		printf("\n");
	}
}

/*********************************��������***********************************************/
void filter(int arr1[COMPETITOR][RATER])
{
	for (int k = 0; k < COMPETITOR; k++)
	{
		for (int j = 0; j < RATER; j++)
		{
			arr1[k][0] = 0;             //ȥ����ͷ�
			arr1[k][RATER - 1] = 0;     //ȥ����߷�
			sum += (float)arr1[k][j];
		}

		pla[k].averscore = sum / (float)(RATER - 2);
		sum = 0;
		arr2[k] = pla[k].averscore;


	}
	for (int i = 0; i < COMPETITOR; i++)
	{
		printf("\n%.2f\n", arr2[i]);
	}
}

/*********************************��ƽ��������***********************************************/
void sort(void)
{
	//��ʼ��������players�ĸ�����Ա�ֱ�������pla�ĸ�����Ա��ָ��
	for (int i = 0; i < COMPETITOR; ++i)
	{
		players[i] = &pla[i];
	}
	//ð������
	struct player temp = NULL;
	//����
	//���ѭ����������һ���߼���
	for (int i = 0; i < COMPETITOR - 1; i++)
	{
		//�ڲ�ѭ������ʼ����Ƚϣ��������
		//ǰһ�����Ⱥ�һ����С���򽻻�
		for (int j = 0; j<COMPETITOR - 1 - i; j++)
		{
			if (players[j]->averscore < players[j + 1]->averscore)
			{
				//��λ
				temp = players[j];
				players[j] = players[j + 1];
				players[j + 1] = temp;
			}
		}

	}
	for (int i = 0; i < COMPETITOR; i++)
	{
		printf("\nnumber is %d, core is %.2f\n", players[i]->No, players[i]->averscore);
	}

}
/***********************************��ӡ��ѡ��******************************************************/
void theEnd(void)
{
	for (int i = 0; i < 3; i++)
	{
		printf("\n%d�Ƚ��ǣ�number is %d, core is %.2f\n", (i + 1), players[i]->No, players[i]->averscore);
	}
	printf("\t\tthank you for using this program, the program was zhongnianhong production.\n");
}


int main(void)
{
	welcome();
	while (1)
	{
		printf("please enter an integer:\n");
		char ch;
		ch = getchar();
		switch (ch)
		{
		case '0':
			exit(0);
			break;
		case '1':
			input();
			break;
		case '2':
			output();
			break;
		case '3':
			persort();
			break;
		case '4':
			filter(arr1);
			break;
		case '5':
			sort();
			break;
		case '6':
			theEnd();
			break;
		default:
			break;
		}
	}
	return 0;
}
