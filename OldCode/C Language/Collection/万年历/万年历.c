#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>



//judge函数用来判断输入日期是否正确，put函数为输出历表的函数
int judge(int year,int month,int day);
void put(int year,int week,int monthstart,int monthend);
//nianl是年历函数，yueli是月历函数，rili是日历函数，zhouli周历函数，now是显示当前时间的函数，ranging是推算两个日期差距的函数
void nianli(int year);
void yueli(int year,int month);
void rili(int year,int month,int day);
void zhouli(int year,int week);
void now();
void ranging(int year,int month,int day,int yearend,int monthend,int dayend);


int main()
{
	int year,month,day,weeks,judgement;
	int yearend,monthend,dayend;
	char choose='\0';
	for(;;)
	{
		system("cls");
		printf("\n\t\t\t  欢迎使用万年历!");
		printf("\n\t\t\tMade in Star-cluster\n\n");
		printf("\n\t\t\t      1.年历");
		printf("\n\t\t\t      2.月历");
		printf("\n\t\t\t      3.日历");
		printf("\n\t\t\t      4.周历");
		printf("\n\t\t\t      5.当前时间");
		printf("\n\t\t\t      6.日期测距");
		printf("\n\t\t\t      7.退出\n");
		printf("\n\n\t\t\t   请输入你的选择:");
		scanf("%d",&choose);
		switch(choose)
		{
		case 1:
			system("cls");
			printf("欢迎使用年历功能!请输入您要查询的年份：");
			scanf("%d",&year);
			if(year==0)
			{
				printf("没有公元0年!公元0年就是公元前1年，即-1年。\n");
				break;
			}
			else
				nianli(year);
			break;
		case 2:
			system("cls");
			printf("欢迎使用月历功能!请输入您要查询的年和月，用空格隔开：");
			scanf("%d %d",&year,&month);
			if(year==0)
			{
				printf("没有公元0年!公元0年就是公元前1年，即-1年。\n");
				break;
			}
			if(month>12||month<1)
				printf("月份输入错误!");
			else
				yueli(year,month);
			break;
		case 3:
			system("cls");
			printf("欢迎使用日历功能!\n请输入年、月、日并以空隔格开：");
			scanf("%d %d %d",&year,&month,&day);
			judgement=judge(year,month,day);
			if(judgement==1)
				break;
			else
			{
				system("cls");
				rili(year,month,day);
			}
			break;
		case 4:
			system("cls");
			printf("欢迎使用周历功能!请输入年份和周数：");
			scanf("%d %d",&year,&weeks);
			if(year==0)
			{
				printf("没有公元0年!公元0年就是公元前1年，即-1年。\n");
				break;
			}
			else
				if(weeks<1||weeks>54)
					printf("周数输入错误!");
				else
				{
					system("cls");
					zhouli(year,weeks);
				}
			break;
		case 5:
			system("cls");
			printf("\t\t\t   成功获取当前时间!");
			now();
			break;
		case 6:
			system("cls");
			printf("欢迎使用日期测距功能!请输入起始时间(年月日):");
			scanf("%d %d %d",&year,&month,&day);
			if(year==0)
			{
				printf("没有公元0年!公元0年就是公元前1年，即-1年。\n");
				break;
			}
			else
				judgement=judge(year,month,day);
			if(judgement==1)
			{
				judgement=0;
				break;
			}
			else
			{
				printf("请输入终止时间(年月日):");
				scanf("%d %d %d",&yearend,&monthend,&dayend);
				if(yearend==0)
				{
					printf("没有公元0年!公元0年就是公元前1年，即-1年。\n");
					break;
				}
				judgement=judge(yearend,monthend,dayend);
			}

			if(judgement==1)
			{
				judgement=0;
				break;
			}
			else
				if(year>yearend)
					printf("起始时间不能大于终止时间!\n");
				else
					ranging(year,month,day,yearend,monthend,dayend);
			break;
		case 7:
			printf("\t\t\t   确定要退出吗?(Y/N)");
			choose=getch();
			if(choose=='Y'||choose=='y')
				exit(0);
			else
				break;
		default:
			system("cls");
			printf("Error!Please input again.");

		}
		getch();
	}
	return 0;
}



//判断
int judge(int year,int month,int day)
{
	if(month>12||month<1)
	{
		printf("月份输入错误!\n");
		return 1;
	}
	if(month==1||month==3||month==5||month==7||month==8||month==10||month==12)
		if(day>31||day<1)
		{
			printf("日期输入错误!\n");
			return 1;
		}
	if(month==4||month==6||month==9||month==11)
		if(day>30||day<1)
		{
			printf("日期输入错误!\n");
			return 1;
		}				
	if(month==2)
	{
		if(year%4==0&&year%100!=0||year%400==0)
		{
			if(day>29||day<1)
			{
				printf("日期输入错误!\n");
				return 1;
			}		
		}
		else
			if(day>28||day<1)
			{
				printf("日期输入错误!\n");
				return 1;
			}
	}
	if(day>31||day<1)
	{
		printf("日期输入错误!\n");
		return 1;
	}
	return 0;
}



//输出
void put(int year,int week,int monthstart,int monthend)
{
	int i,j,day,record;
	record=year;
	if(year<0)
	{
		year++;
		for(;year<0;)
			year+=28;
	}
	for(i=monthstart;i<=monthend;i++)
	{
		if(i==1||i==3||i==5||i==7||i==8||i==10||i==12)
			day=31;
		if(i==4||i==6||i==9||i==11)
			day=30;
		if(i==2)
		{
			if(year%4==0&&year%100!=0||year%400==0)
				day=29;
			else
				day=28;
		}
		if(year%4==0&&year%100!=0||year%400==0)
			printf("\n\n 闰年 公元");
		else
			printf("\n\n 平年 公元");
		if(record<0)
			printf("前");
		if(record<0)
			printf("%d年  %d月\n",-1*record,i);
		else
			printf("%d年  %d月\n",year,i);
		printf("星期天   星期一   星期二   星期三   星期四   星期五   星期六\n");
		for(j=1,week%=7;j<=week;j++)
			printf("         ");
		for(j=1;j<=day;j++,week++)
		{
			printf("%-9d",j);
			if(week%7==6)
				printf("\n");
		}
		printf("\n\n");
	}
}



//年历
void nianli(int year)
{
	int gap=0,week=0,record;//record用来记录公元前的年份
	record=year;
	if(year<0)
	{
		year++;
		for(;year<0;)
			year+=28;
	}
	gap=year%28/4+1+year%28*365;
	if(year%28==0)
		--gap;
	gap%=7;
	week=(5+gap)%7;
	year=record;
	put(year,week,1,12);
}



//月历
void yueli(int year,int month)
{
	int i,gap=0,week=0,day=0,record;
	record=year;
	if(year<0)
	{
		year++;
		for(;year<0;)
			year+=28;
	}
	gap=year%28/4+1+year%28*365;
	if(year%28==0)
		--gap;
	gap%=7;
	week=(5+gap)%7;
	for(i=1;i<month;i++)
	{
		if(i==1||i==3||i==5||i==7||i==8||i==10||i==12)
			day+=31;
		if(i==4||i==6||i==9||i==11)
			day+=30;
		if(i==2)
		{
			if(year%4==0&&year%100!=0||year%400==0)
				day+=29;
			else
				day+=28;
		}
	}
	week=week+day%7;
	week%=7;
	year=record;
	put(year,week,month,month);
}



//日历
void rili(int year,int month,int day)
{
	int i,gap=0,week=0,record_week,weeks,record,record_day;
	printf("\n\n\n\t\t\t");
	record=year;
	record_day=day;
	if(year<0)
	{
		year++;
		for(;year<0;)
			year+=28;
	}
	gap=year%28/4+1+year%28*365;
	if(year%28==0)
		--gap;
	gap%=7;
	week=(5+gap)%7;
	record_week=week;
	for(i=1;i<month;i++)
	{
		if(i==1||i==3||i==5||i==7||i==8||i==10||i==12)
			day+=31;
		if(i==4||i==6||i==9||i==11)
			day+=30;
		if(i==2)
		{
			if(year%4==0&&year%100!=0||year%400==0)
				day+=29;
			else
				day+=28;
		}
	}
	day--;
	week=week+day%7;
	week%=7;
	day++;
	if(year%4==0&&year%100!=0||year%400==0)
		printf("\t闰年\n\t\t\t    公元");
	else
		printf("\t平年\n\t\t\t    公元");
	if(record<0)
		printf("前");
	if(record<0)
		printf("%-5d年\n\t\t\t      %-2d月 %-2d日\n",-1*record,month,record_day);
	else
		printf("%-5d年\n\t\t\t      %-2d月 %-2d日\n",year,month,record_day);
	if(week==0)
		week=7;

	if(day<=8-record_week)
		weeks=1;
	else
		if((day-8+record_week)%7!=0)
			weeks=(day-8+record_week)/7+2;
		else
			weeks=(day-8+record_week)/7+1;
	printf("\t\t\t    该年第%-3d天\n",day);
	printf("\t\t\t       第%-2d周\n",weeks);
	switch(week)
	{
	case 1:printf("\t\t\t       星期一");break;
	case 2:printf("\t\t\t       星期二");break;
	case 3:printf("\t\t\t       星期三");break;
	case 4:printf("\t\t\t       星期四");break;
	case 5:printf("\t\t\t       星期五");break;
	case 6:printf("\t\t\t       星期六");break;
	case 7:printf("\t\t\t       星期天");break;
	}

	//节日
	if(month==1&&record_day==1)
		printf("\n\t\t\t       元  旦");
	if(month==3&&record_day==8)
		printf("\n\t\t\t       妇女节");
	if(month==3&&record_day==12)
		printf("\n\t\t\t       植树节");
	if(month==5&&record_day==1)
		printf("\n\t\t\t       劳动节");
	if(month==5&&record_day==4)
		printf("\n\t\t\t       青年节");
	if(month==6&&record_day==1)
		printf("\n\t\t\t       儿童节");
	if(month==7&&record_day==1)
		printf("\n\t\t\t       建党节");
	if(year==1937&&month==7&&record_day==7)
		printf("\n\t\t\t     卢沟桥事变");
	if(year>1937&&month==7&&record_day==7)
		printf("\n\t\t\t  卢沟桥事变%d周年",year-1937);
	if(month==8&&record_day==1)
		printf("\n\t\t\t       建军节");
	if(month==9&&record_day==10)
		printf("\n\t\t\t       教师节");
	if(year==1931&&month==9&&record_day==18)
		printf("\n\t\t\t     九一八事变");
	if(year>1931&&month==9&&record_day==18)
		printf("\n\t\t\t  九一八事变%d周年",year-1931);
	if(month==10&&record_day==1)
		printf("\n\t\t\t       国庆节");
	if(month==11&&record_day==11)
		printf("\n\t\t\t       光棍节");
}



//周历
void zhouli(int year,int weeks)
{
	int i,gap=0,record,right,week=0,month=1,day,record_day;
	record=year;
	if(year<0)
	{
		year++;
		for(;year<0;)
			year+=28;
	}
	//判断周数是否存在
	if(year%4==0&&year%100!=0||year%400==0)
	{	
		if(day>366)
		{

			if(record<0)
				printf("公元前%d年没有第%d周哦!",-1*record,weeks);
			else
				printf("公元%d年没有第%d周哦!",year,weeks);
			right=0;
		}	
	}
	else
	{
		if(day>365)
		{
			if(record<0)
				printf("公元前%d年没有第%d周哦!",-1*record,weeks);
			else
				printf("公元%d年没有第%d周哦!",year,weeks);
			right=0;
		}
	}

	if(right!=0)
	{
		//判断该年份第一天是星期几
		gap=year%28/4+1+year%28*365;
		if(year%28==0)
			--gap;
		gap%=7;
		week=(5+gap)%7;
		if(week==0)
			week=7;

		//判断所求周数星期一是一年中第几天
		if(weeks==1)
			day=1;
		else
			day=7*weeks-week-5;
		record_day=day;

		//求月份和日期
		for(i=1;i<=12;++i,month=i)
		{
			if(i==1||i==3||i==5||i==7||i==8||i==10||i==12)
				if(day-31<1)
					break;
				else
					day-=31;
			if(i==4||i==6||i==9||i==11)
				if(day-30<1)
					break;
				else
					day-=30;
			if(i==2)
			{
				if(year%4==0&&year%100!=0||year%400==0)
				{
					if(day-29<1)
						break;
					else
						day-=29;
				}
				else
				{
					if(day-28<1)
						break;
					else
						day-=28;
				}
			}//判断月份的最后一个花括号
		}//循环的最后一个花括号

		//输出
		if(record<0)
			printf("\n公元前%d年第%d周:\n",-1*record,weeks);
		else
			printf("\n公元%d年第%d周:\n",year,weeks);
		switch((week+(record_day-1)%7)%7)
		{
		case 1:
			printf("星期一:");
			rili(record,month,day++);
		case 2:
			if((month==1||month==3||month==5||month==7||month==8||month==10||month==12)&&day>31)
			{
				day-=31;
				month++;
			}
			if((month==4||month==6||month==9||month==10)&&day>30)
			{
				day-=30;
				month++;
			}
			if(month==2)
				if(year%4==0&&year%100!=0||year%400==0)
				{
					if(day>29)
					{
						day-=29;
						month++;
					}		
				}
				else
					if(day>28)
					{
						day-=28;
						month++;
					}
			if(month>12)
				break;
			printf("\n星期二:");
			rili(record,month,day++);
		case 3:
			if((month==1||month==3||month==5||month==7||month==8||month==10||month==12)&&day>31)
			{
				day-=31;
				month++;
			}
			if((month==4||month==6||month==9||month==10)&&day>30)
			{
				day-=30;
				month++;
			}
			if(month==2)
				if(year%4==0&&year%100!=0||year%400==0)
				{
					if(day>29)
					{
						day-=29;
						month++;
					}		
				}
				else
					if(day>28)
					{
						day-=28;
						month++;
					}
			if(month>12)
				break;
			printf("\n星期三:");
			rili(record,month,day++);
		case 4:
			if((month==1||month==3||month==5||month==7||month==8||month==10||month==12)&&day>31)
			{
				day-=31;
				month++;
			}
			if((month==4||month==6||month==9||month==10)&&day>30)
			{
				day-=30;
				month++;
			}
			if(month==2)
				if(year%4==0&&year%100!=0||year%400==0)
				{
					if(day>29)
					{
						day-=29;
						month++;
					}		
				}
				else
					if(day>28)
					{
						day-=28;
						month++;
					}
			if(month>12)
				break;
			printf("\n星期四:");
			rili(record,month,day++);
		case 5:
			if((month==1||month==3||month==5||month==7||month==8||month==10||month==12)&&day>31)
			{
				day-=31;
				month++;
			}
			if((month==4||month==6||month==9||month==10)&&day>30)
			{
				day-=30;
				month++;
			}
			if(month==2)
				if(year%4==0&&year%100!=0||year%400==0)
				{
					if(day>29)
					{
						day-=29;
						month++;
					}		
				}
				else
					if(day>28)
					{
						day-=28;
						month++;
					}
			if(month>12)
				break;
			printf("\n星期五:");
			rili(record,month,day++);
		case 6:
			if((month==1||month==3||month==5||month==7||month==8||month==10||month==12)&&day>31)
			{
				day-=31;
				month++;
			}
			if((month==4||month==6||month==9||month==10)&&day>30)
			{
				day-=30;
				month++;
			}
			if(month==2)
				if(year%4==0&&year%100!=0||year%400==0)
				{
					if(day>29)
					{
						day-=29;
						month++;
					}		
				}
				else
					if(day>28)
					{
						day-=28;
						month++;
					}
			if(month>12)
				break;
			printf("\n星期六:");
			rili(record,month,day++);
		case 0:
			if((month==1||month==3||month==5||month==7||month==8||month==10||month==12)&&day>31)
			{
				day-=31;
				month++;
			}
			if((month==4||month==6||month==9||month==10)&&day>30)
			{
				day-=30;
				month++;
			}
			if(month==2)
				if(year%4==0&&year%100!=0||year%400==0)
				{
					if(day>29)
					{
						day-=29;
						month++;
					}		
				}
				else
					if(day>28)
					{
						day-=28;
						month++;
					}
			if(month>12)
				break;
			printf("\n星期天:");
			rili(record,month,day);
		}//switch的花括号
	}//所求周数存在时执行的这一段代码的花括号
}



//当前时间
void now()
{
	//获取时间
	time_t nowtime; 
	time( &nowtime );

	struct tm *timeinfo;  //定义时间结构体
	timeinfo = localtime( &nowtime );  //转化为当地时间

	int year, month, day, hour, min, sec;
	year = timeinfo->tm_year + 1900;   //从1900年开始计数，所以+1900
	month = timeinfo->tm_mon + 1;    //从0开始计数，所以+1
	day = timeinfo->tm_mday;
	hour = timeinfo->tm_hour;
	min = timeinfo->tm_min;
	sec = timeinfo->tm_sec;
	
	printf("\n\n\t\t\t  %d %d %d %d:%d:%d\n", year, month, day, hour, min, sec);
	rili(year,month,day);
}



//推算时间差距
void ranging(int year,int month,int day,int yearend,int monthend,int dayend)
{
	int year1,month1,day1,yearend1,monthend1,dayend1;
	int i,j,range=0;
	year1=year,month1=month,day1=day,yearend1=yearend,monthend1=monthend,dayend1=dayend;
	if(year<0)
		year++;
	if(yearend<0)
		yearend++;
	for(;year<0||yearend<0;)
		year+=28,yearend+=28;
	for(;year<yearend;year++)
		if(year%4==0&&year%100!=0||year%400==0)
			range+=366;
		else
			range+=365;
	for(i=1;i<month;i++)
	{
		if(i==1||i==3||i==5||i==7||i==8||i==10)
			day+=31;
		if(i==4||i==6||i==9||i==11)
			day+=30;
		if(i==2)
		{
			if(year%4==0&&year%100!=0||year%400==0)
				day+=29;
			else
				day+=28;
		}
	}
	for(i=1;i<monthend;i++)
	{
		if(i==1||i==3||i==5||i==7||i==8||i==10)
			dayend+=31;
		if(i==4||i==6||i==9||i==11)
			dayend+=30;
		if(i==2)
		{
			if(year%4==0&&year%100!=0||year%400==0)
				dayend+=29;
			else
				dayend+=28;
		}
	}
	range=range-day+dayend;
	printf("%d年%d月%d日到%d年%d月%d日的时间差距为%d，时间长度为%d。\n",year1,month1,day1,yearend1,monthend1,dayend1,range,range+1);
}