#include<stdio.h>
#include<stdlib.h>//��׼�⺯��
#include<string.h>//�ַ�������ͷ�ļ�
#include<malloc.h>//�����ڴ溯��
#define LEN sizeof(struct plane)//����struct plane �Ĵ�С
#define NEN sizeof(struct people)//����struct people �Ĵ�С
#define MAX 10;
struct plane//����ṹ������
{
	char destination[12];//Ŀ�ĵ�
	char num[10];//���
	char time[12];//ʱ��
	char banhao[7];//�����
	int price;//Ʊ��
	int amount;//��Ʊ��
	
};

struct people//����ṹ������
{
	char name[10];//�ÿ�����
	char no[20];//���֤��
	char code[5];//�����
	char time[12];//����ʱ��
};
typedef struct people PEO;//����PEOΪ�ṹ��
typedef struct plane PLANE;//����PLANEΪ�ṹ��
PLANE a[100];//a[100]Ϊ����
PEO C;//CΪ����
void menu();//���˵�
void input();//���뺯��
void search();//��ѯ����
void preserve();//����Ʊ����
void planeadd();//׷�Ӻ���
void delplane();//ɾ������
//������
int main()
{
	system("cls");//����
	menu();//���˵�
	return 0;
}

//���˵�
void menu()
{
	char *menu[]={"\t**************��ӭ����ɻ���Ʊϵͳ**************",
	"\t                 a.���뺽��",
	"\t                 b.��ѯ����",
	"\t                 c.�˶�Ʊϵͳ",
	"\t                 d.׷�Ӻ���",
	"\t                 e.ɾ������",
	"\t                 f.�˳�",
	"\t************************************************"};//ָ�뺯��
	int i;//��ͨ����
	char NO;//��ͨ����
	int quit=0;//�����˳�---1�˳�
	do//do while ѭ��
	{	
		system("cls");
		for(i=0;i<9;i++)//���*menu
			printf("\n%s",menu[i]);
		printf("\n\t������������a,b,c,d,e��f: ");
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

//����
void input()
{
	int i,n;
	FILE *fp;//�ļ�ָ�����
	system("cls");
	if((fp=fopen("D:\\file.txt","w"))==NULL)//׷�ӷ�ʽ���ļ�
	{
		printf("error!\n");
		exit(0);//ֱ���˳�
	}
	printf("\n\t�����뺽������n: ");
	scanf("%d",&n);//10
	printf("\n\t�밴������ʾ���뺽����Ϣ�����վ���ϲ�\n");
	for(i=0;i<n;i++)
	{
		printf("\n\t�������յ㣺");
		scanf("%s",a[i].destination);
		printf("\n\t�����Σ�");
		scanf("%s",a[i].num);
		printf("\n\t�����뺽��ţ�");
		scanf("%s",a[i].banhao);
		printf("\n\tʱ�䣺");
		scanf("%s",a[i].time);
		printf("\n\tƱ�ۣ�");
		scanf("%d",&a[i].price);
		printf("\n\t��Ʊ����:");
		scanf("%d",&a[i].amount);
		fwrite(&a[i],LEN,1,fp);
	}
	fclose(fp);//�ر��ļ�
};

//Ѱ��
void search()
{
	int i,j=0,k=222;
	char str[12];
	FILE *fp;
	PLANE b[5];
	if((fp=fopen("D:\\file.txt","r"))==NULL)
	{
		printf("�Ҳ����ļ�!\n");
		exit(0);
	}
	printf("\n\t�����뺽��ţ�");
	scanf("%s",str);
	printf("�����ǣ�%s111\n",str);
	while(fread(&b[j],LEN,1,fp)!=0)//��ȡ���ݿ�----��
	{
		
		j++;
		for(i=0;i<j;i++){
			printf("������ǣ�%s111\n",b[i].num);
			printf("1�ǣ�%s111\n",b[i].destination);
			printf("2�ǣ�%s111\n",b[i].banhao);
			if(strcmp(b[i].num,str)==0)
			{
				printf("\n\t�ϲ���%s ����ţ�%s ʱ�䣺%s Ʊ�ۣ�%s ʣ��Ʊ����%s\n",b[i].destination,b[i].banhao,b[i].time,b[i].price,b[i].amount);
				k=i;
				break;
			}
			printf("�ж�����ˡ�����"); 
		}
	}
	if(k==222)	
		printf("\n\t�Բ���û������Ҫ�ĺ��ߡ�");
	fclose(fp);
	system("pause");//�ӳ����з���ϵͳ�����е��ã�ִ�����pause
};

//����Ʊ
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
	printf("\n\t�����뺽��ţ�");
	scanf("%s",str);
	while(fread(&preserve[i],LEN,1,fp)!=0)
	{
		if(strcmp(preserve[i].num,str)==0)
		{
			printf("\n\t�ϲ���%s ����ţ�%s ʱ�䣺%s �۸�%d ʣ��Ʊ����%d",preserve[i].destination,preserve[i].banhao,preserve[i].time,preserve[i].price,preserve[i].amount);
			k=i;
			i++;
		}
		fclose(fp);
		printf("\n\t�����붩��Ʊ����:0-��Ʊ 1-��Ʊ");
		scanf("%d",&m);
		if(m==0)
		{
			printf("\n\t�ϲ�%s ����ţ�%s ʱ�䣺%s �۸�%dԪ ʣ��Ʊ����%d",preserve[k].destination,preserve[k].banhao,preserve[k].time,preserve[k].price,preserve[k].amount);
			printf("\n\t�����뵥��Ʊ����n:");
			scanf("%d",&n);
			x=preserve[k].price*n;
			printf("\n\tӦ����%dԪ",x);
			preserve[k].amount=preserve[k].amount-n;
			printf("\n\t��Ʊ�ɹ���ף����;��죡");

		}
		if(m==1)
		{
			printf("\n\t����������Ʊ��n:");
			scanf("%d",&n);
			x=preserve[k].price*n;
			printf("\n\tӦ�˽�%dԪ",x);
			preserve[k].amount=preserve[k].amount+n;
			printf("\n\t��Ʊ�ɹ���");

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
//׷��
void planeadd()
{
	int x,k=1;
	PLANE planeadd;
	FILE *fp;

	printf("\n\t������������֤���룬����ţ��Լ�ʱ��\n");
	printf("\n\t���֤����:\n");
	scanf("%s",C.no);
	printf("\n\t�����:\n");
	scanf("%s",C.code);
	printf("\n\tʱ��:\n");
	scanf("%s",C.time);
	do
	{
	
		printf("\n\t�밴������ʾ��������������Ϣ��");	
		printf("\n\t�������յ㣺");	
		scanf("%s",&planeadd.destination);	
		printf("\n\t�����뺽��ţ�");	
		scanf("%d",&planeadd.banhao);	
		printf("\n\t������ʱ�䣺");
		scanf("%s",&planeadd.time);	
		printf("\n\t������۸�",&planeadd.price);
		printf("\n\t�������Ʊ������");	
		scanf("%d",&planeadd.amount);
		if((fp=fopen("D:\\file.txt","ab+"))==NULL)
		{
			printf("\n\t�ļ��д��ܴ򿪣�");
			exit(0);
		}
		fseek(fp,LEN,2);
		fwrite(&planeadd,LEN,1,fp);
		fclose(fp);
		printf("\n\t������Ϣ�ɹ�������");
		printf("\n\t�Ƿ�������Ӻ��ࣿ����������1����������0�������˵�.");
		scanf("%d",&x);
		if(x!=0 && x!=1)
		{	
			printf("\n\t����������������������0��1��");		
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
//ɾ��
void delplane()
{
	char str[12];
	FILE *fp;
	int total=0;
	int i=0;
	int del=0;
	PLANE delplane[10];
	printf("\n\t������������֤���룬����ţ��Լ�ʱ��\n");
	printf("\n\t���֤����:\n");
	scanf("%s",C.no);
	printf("\n\t�����:\n");
	scanf("%s",C.code);
	printf("\n\tʱ��:\n");
	scanf("%s",C.time);
	if((fp=fopen("D:\\file.txt","rb"))==NULL)
	{
		printf("\n\t�ļ��д����ܴ򿪣�");
		exit(0);

	}
	printf("\n\t������Ҫɾ���ĺ����:");
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
		printf("\n\t�ɹ�ɾ����Ϣ!!!");

	}
	if(del==0)
	{
		printf("\n\tϵͳ�в��氮Ҫɾ������Ϣ��");
		menu();
	}
	else
	{
		if((fp=fopen("D:\\file.txt","wb+"))==NULL)
		{
			printf("\n\t�ļ��д����ܴ򿪣�");
			exit(0);

		}
	}
	for(i=0;i<total;i++)
	{
		fwrite(&delplane[i],LEN,1,fp);
		fclose(fp);
	}
}

