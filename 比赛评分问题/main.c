/***********************************************************************************
*1.10位评委能对20位选手进行打开分，要有给第几号选手打分的提示信息。如：给第1号选手打分：
*打完后接着有提示给第2号选手打分：…依此类推，直到20位选手打分完毕。
*2.10位评委对每位选手的打分能按照从低分到高分的排序。
*3.去掉10位评委打分的一个最低分、一个最高分后求出每位选手的平均得分。
*4.对每位选手的平均分按从高到低的顺序进行排序。排序时要求选手编号与其得分一起进行。
*5.按参赛选手编号顺序输出选手编号及其对应成绩；按选手编号、选手得分输出参赛选手的一、二、三等奖。
*************************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#pragma warning(disable:4996)

float sum = 0.0;

#define RATER 10     //评委人数
#define COMPETITOR 10//选手人数
struct player
{
	int No;                 //选手的编号
	char name[COMPETITOR];  //选手的姓名
	int score[RATER];       //每位评委给选手的打分
	float averscore;          //每位选手的平均分
};
struct player pla[COMPETITOR];

int arr1[COMPETITOR][RATER];
float arr2[COMPETITOR];
//10位选手的结构体指针数组，评分从高到底排序
struct player *players[COMPETITOR];

/**********************************欢迎界面*****************************************/
void welcome(void)
{
	printf("========welcome to the judges scoring system========\n");//意：欢迎来到评委打分模拟系统
	printf("        输 0退 出 系 统                  \n");
	printf("        输 1 进 入 打 分;               \n");
	printf("        输 2输出录入成绩;                \n");
	printf("        输 3输出排序后的成绩;            \n");
	printf("        输 4得出每位选手的平均成绩;       \n");
	printf("        输 5打印所有选手名次;            \n");
	printf("        输 6打印获奖选手;                \n");
}
/**************************************输入部分***************************************/
void input(void)
{

	srand(time(NULL));//避免产生相同数

	printf("  ========给%d个选手信息========\n", COMPETITOR);

	for (int i = 0; i < COMPETITOR; i++)
	{
		printf("     =====给第%d位选手打分=====\n", i + 1);
		printf("     该选手的编号： ");
		scanf("%d", &pla[i].No);
		printf("     该选手的姓名： ");
		scanf("%s", &pla[i].name);

		for (int j = 0; j < RATER; j++)
		{
			printf("==第%d位评委给该选手的打分==\n", j + 1);
			pla[i].score[j] = rand() % 100;
			printf("           %d分\n", pla[i].score[j]);
			arr1[i][j] = pla[i].score[j];

		}
		printf("\n\n");
	}
}
/********************************输出部分********************************************/
void output(void)
{
	printf(">>>>>>>>>>>>=====评分汇总表=====<<<<<<<<<<<<\n\n");
	printf("编号\t姓 名");
	for (int i = 0; i < RATER; i++)
		printf("\t第%d位评委", i + 1);
	printf("\n");
	for (int k = 0; k < COMPETITOR; k++)
	{
		printf("%4d\t%4s", pla[k].No, pla[k].name);
		for (int j = 0; j < RATER; j++)
			printf("\t%d\t", pla[k].score[j]);
		printf("\n");
	}

}
/************************************对评委的打分排序**************************************************/

void persort(void)
{
	for (int k = 0; k < COMPETITOR; k++)
	{
		//冒泡排序
		int temp = 0;
		//排序
		//外层循环，它决定一共走几趟
		for (int i = 0; i<RATER - 1; i++)
		{
			//内层循环，开始逐个比较，如果发现
			//前一个数比后一个数大，则交换
			for (int j = 0; j<RATER - 1 - i; j++)
			{
				if (pla[k].score[j]>pla[k].score[j + 1])
				{
					//换位
					temp = pla[k].score[j];
					pla[k].score[j] = pla[k].score[j + 1];
					pla[k].score[j + 1] = temp;
				}
			}
		}
	}
	printf("\n>>>==评委对每位选手的打分能按照从低分到高分的排序==<<<\n");
	for (int k = 0; k < COMPETITOR; k++)
	{
		printf("%4d\t%4s", pla[k].No, pla[k].name);
		for (int j = 0; j < RATER; j++)
			printf("\t%d\t", pla[k].score[j]);
		printf("\n");
	}
}

/*********************************过滤数据***********************************************/
void filter(int arr1[COMPETITOR][RATER])
{
	for (int k = 0; k < COMPETITOR; k++)
	{
		for (int j = 0; j < RATER; j++)
		{
			arr1[k][0] = 0;             //去掉最低分
			arr1[k][RATER - 1] = 0;     //去掉最高分
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

/*********************************对平均分排序***********************************************/
void sort(void)
{
	//初始化，数组players的各个成员分别存放数组pla的各个成员的指针
	for (int i = 0; i < COMPETITOR; ++i)
	{
		players[i] = &pla[i];
	}
	//冒泡排序
	struct player temp = NULL;
	//排序
	//外层循环，它决定一共走几趟
	for (int i = 0; i < COMPETITOR - 1; i++)
	{
		//内层循环，开始逐个比较，如果发现
		//前一个数比后一个数小，则交换
		for (int j = 0; j<COMPETITOR - 1 - i; j++)
		{
			if (players[j]->averscore < players[j + 1]->averscore)
			{
				//换位
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
/***********************************打印获奖选手******************************************************/
void theEnd(void)
{
	for (int i = 0; i < 3; i++)
	{
		printf("\n%d等奖是：number is %d, core is %.2f\n", (i + 1), players[i]->No, players[i]->averscore);
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
