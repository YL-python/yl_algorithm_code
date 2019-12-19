#include<stdio.h>
#include<stdlib.h>//标准库函数
#include<string.h>//字符串处理头文件
#include<malloc.h>//分配内存函数
#define LEN sizeof(struct plane)//定义struct plane 的大小
#define NEN sizeof(struct people)//定义struct people 的大小
#define MAX 10;
struct plane//定义结构体数组
{
	char destination[12];//目的地
	char num[10];//班次
	char time[12];//时间
	char banhao[7];//航班号
	int price;//票价
	int amount;//总票数
	
};

struct people//定义结构体数组
{
	char name[10];//旅客名字
	char no[20];//身份证号
	char code[5];//航班号
	char time[12];//出发时间
};
typedef struct people PEO;//定义PEO为结构体
typedef struct plane PLANE;//定义PLANE为结构体
PLANE a[100];//a[100]为变量
PEO C;//C为变量
void menu();//主菜单
void input();//输入函数
void search();//查询函数
void preserve();//订退票函数
void planeadd();//追加函数
void delplane();//删除函数
//主函数
int main()
{
	system("cls");//清屏
	menu();//主菜单
	return 0;
}

//主菜单
void menu()
{
	char *menu[]={"\t**************欢迎进入飞机订票系统**************",
	"\t                 a.输入航线",
	"\t                 b.查询航线",
	"\t                 c.退订票系统",
	"\t                 d.追加航线",
	"\t                 e.删除航线",
	"\t                 f.退出",
	"\t************************************************"};//指针函数
	int i;//普通变量
	char NO;//普通变量
	int quit=0;//控制退出---1退出
	do//do while 循环
	{	
		system("cls");
		for(i=0;i<9;i++)//输出*menu
			printf("\n%s",menu[i]);
		printf("\n\t请输入服务代码a,b,c,d,e或f: ");
		NO=getchar();
		switch(NO)
		{
		case 'a':input();
			break;
		case 'b':search();
			break;
		case 'c':preserve();
			break;
		case 'd':planeadd();
			break;
		case 'e':delplane();
			break;
		case 'f':quit=1;
			break;
		}
	}
	while(!quit);
};

//输入
void input()
{
	int i,n;
	FILE *fp;//文件指针变量
	system("cls");
	if((fp=fopen("D:\\file.txt","w"))==NULL)//追加方式打开文件
	{
		printf("error!\n");
		exit(0);//直接退出
	}
	printf("\n\t请输入航班总数n: ");
	scanf("%d",&n);//10
	printf("\n\t请按下面提示输入航班信息：起点站：南昌\n");
	for(i=0;i<n;i++)
	{
		printf("\n\t请输入终点：");
		scanf("%s",a[i].destination);
		printf("\n\t航班班次：");
		scanf("%s",a[i].num);
		printf("\n\t请输入航班号：");
		scanf("%s",a[i].banhao);
		printf("\n\t时间：");
		scanf("%s",a[i].time);
		printf("\n\t票价：");
		scanf("%d",&a[i].price);
		printf("\n\t机票总数:");
		scanf("%d",&a[i].amount);
		fwrite(&a[i],LEN,1,fp);
	}
	fclose(fp);//关闭文件
};

//寻找
void search()
{
	int i,j=0,k=222;
	char str[12];
	FILE *fp;
	PLANE b[5];
	if((fp=fopen("D:\\file.txt","r"))==NULL)
	{
		printf("找不到文件!\n");
		exit(0);
	}
	printf("\n\t请输入航班号：");
	scanf("%s",str);
	printf("输入是：%s111\n",str);
	while(fread(&b[j],LEN,1,fp)!=0)//读取数据块----？
	{
		
		j++;
		for(i=0;i<j;i++){
			printf("航班号是：%s111\n",b[i].num);
			printf("1是：%s111\n",b[i].destination);
			printf("2是：%s111\n",b[i].banhao);
			if(strcmp(b[i].num,str)==0)
			{
				printf("\n\t南昌至%s 航班号：%s 时间：%s 票价：%s 剩余票数：%s\n",b[i].destination,b[i].banhao,b[i].time,b[i].price,b[i].amount);
				k=i;
				break;
			}
			printf("判断完成了。。。"); 
		}
	}
	if(k==222)	
		printf("\n\t对不起，没有您需要的航线。");
	fclose(fp);
	system("pause");//从程序中发起系统命令行调用，执行命令：pause
};

//定退票
void preserve()
{
	int a=0,i=0,k,m,n,x;
	char str[12];
	PLANE preserve[10];
	FILE *fp;
	if((fp=fopen("D:\\file.txt","r"))==NULL)
	{
		printf("error!\n");
		exit(0);
	}
	printf("\n\t请输入航班号：");
	scanf("%s",str);
	while(fread(&preserve[i],LEN,1,fp)!=0)
	{
		if(strcmp(preserve[i].num,str)==0)
		{
			printf("\n\t南昌至%s 航班号：%s 时间：%s 价格：%d 剩余票数：%d",preserve[i].destination,preserve[i].banhao,preserve[i].time,preserve[i].price,preserve[i].amount);
			k=i;
			i++;
		}
		fclose(fp);
		printf("\n\t请输入订退票代码:0-订票 1-退票");
		scanf("%d",&m);
		if(m==0)
		{
			printf("\n\t南昌%s 航班号：%s 时间：%s 价格：%d元 剩余票数：%d",preserve[k].destination,preserve[k].banhao,preserve[k].time,preserve[k].price,preserve[k].amount);
			printf("\n\t请输入单订票总数n:");
			scanf("%d",&n);
			x=preserve[k].price*n;
			printf("\n\t应付款%d元",x);
			preserve[k].amount=preserve[k].amount-n;
			printf("\n\t订票成功！祝您旅途愉快！");

		}
		if(m==1)
		{
			printf("\n\t请输入欲退票数n:");
			scanf("%d",&n);
			x=preserve[k].price*n;
			printf("\n\t应退金额：%d元",x);
			preserve[k].amount=preserve[k].amount+n;
			printf("\n\t退票成功！");

		}
		fp=fopen("D:\\file.txt","wb");
		for(i=0;i<=k;i++)
		{
			fwrite(&preserve[i],LEN,1,fp);
			fclose(fp);
			system("pause");

		}

	}
};
//追加
void planeadd()
{
	int x,k=1;
	PLANE planeadd;
	FILE *fp;

	printf("\n\t请输入你的身份证号码，航班号，以及时间\n");
	printf("\n\t身份证号码:\n");
	scanf("%s",C.no);
	printf("\n\t航班号:\n");
	scanf("%s",C.code);
	printf("\n\t时间:\n");
	scanf("%s",C.time);
	do
	{
	
		printf("\n\t请按下面提示输入新增航班信息：");	
		printf("\n\t请输入终点：");	
		scanf("%s",&planeadd.destination);	
		printf("\n\t请输入航班号：");	
		scanf("%d",&planeadd.banhao);	
		printf("\n\t请输入时间：");
		scanf("%s",&planeadd.time);	
		printf("\n\t请输入价格：",&planeadd.price);
		printf("\n\t请输入机票总数：");	
		scanf("%d",&planeadd.amount);
		if((fp=fopen("D:\\file.txt","ab+"))==NULL)
		{
			printf("\n\t文件有错不能打开！");
			exit(0);
		}
		fseek(fp,LEN,2);
		fwrite(&planeadd,LEN,1,fp);
		fclose(fp);
		printf("\n\t增加信息成功！！！");
		printf("\n\t是否继续增加航班？继续请输入1，否则输入0返回主菜单.");
		scanf("%d",&x);
		if(x!=0 && x!=1)
		{	
			printf("\n\t您的输入有误，请重新输入0或1！");		
			scanf("%d",&x);
		}
		else if(x==0)
		{
			menu();
			k=0;
		}
		else
		{
			k=1;
		} 
	}
	while(k);
};
//删除
void delplane()
{
	char str[12];
	FILE *fp;
	int total=0;
	int i=0;
	int del=0;
	PLANE delplane[10];
	printf("\n\t请输入你的身份证号码，航班号，以及时间\n");
	printf("\n\t身份证号码:\n");
	scanf("%s",C.no);
	printf("\n\t航班号:\n");
	scanf("%s",C.code);
	printf("\n\t时间:\n");
	scanf("%s",C.time);
	if((fp=fopen("D:\\file.txt","rb"))==NULL)
	{
		printf("\n\t文件有错误不能打开！");
		exit(0);

	}
	printf("\n\t请输入要删除的航班号:");
	scanf("%s",str);
	while(fread(&delplane[total],LEN,1,fp))
		total++;
	for(i=0;i<total;i++)
		if(strcmp(delplane[i].num,str)==0)
			break;
	for(;i<total;i++)
	{

		delplane[i]=delplane[i+1];
		total=total-1;
		del=1;
		printf("\n\t成功删除信息!!!");

	}
	if(del==0)
	{
		printf("\n\t系统中不存爱要删除的信息！");
		menu();
	}
	else
	{
		if((fp=fopen("D:\\file.txt","wb+"))==NULL)
		{
			printf("\n\t文件有错误不能打开！");
			exit(0);

		}
	}
	for(i=0;i<total;i++)
	{
		fwrite(&delplane[i],LEN,1,fp);
		fclose(fp);
	}
}

