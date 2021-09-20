#include<cstdio>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<ctime>
#include<conio.h>
char type;
int seed;
char title[1000]={'\0'};
char password[1000]={'\0'};
int p1=0;
//For all the functions
	// 0 means back to select
	// 1 means back to reinput
	// 2 means all right
int Encrypt_input()
{
	for(int i=0;i<1000;i++)
	{
		title[i]='\0';
		password[i]='\0';
	}
	// 0 means back to select
	// 1 means back to reinput
	// 2 means input right
	int temp_0=0;
		printf("Let's Encrypt it\n"); 
		printf("Please input your password\n");
		printf("The Format is \" [title]password \"\n");
		printf("If you want to go back please press B\n");
		//输入标题 
		while((title[temp_0]=getchar())!=']')
		{
			if(title[0]=='\n')
			{
				continue;
			}
			else if(title[0]=='b'||title[0]=='B')
			{
				getchar();
				printf("Back and select\n");
				printf("\n************************************************\n\n");
								
				//返回选择	
				return 0;
			
			}
			else if(title[0]!='[')
			{
				scanf("%s",title);//消去剩下内容 
				printf("Format Error:Please start with [\n");
				printf("Please enter your password once again\n");
				printf("\n************************************************\n\n");
		        
		        //返回输入
				return 1;
			}
			else if((title[temp_0]==-65&&title[temp_0-1]==-95)||(title[temp_0]==-66&&title[temp_0-1]==-95))//输入有误 
			{
				getchar();
				printf("Format Error: Please change 【 】 to []\n");
				printf("Please enter your password once again\n");
				printf("\n************************************************\n\n");
		        
		        //返回输入
				return 1;
			}
			temp_0++;
		}
		title[temp_0+1]='\0'; //除掉乱七八糟的其他东西 
		printf("Title is %s\n",title); 
		//标题输入结束
		//正文输入开始
		temp_0=0;
		while((password[temp_0]=getchar())!='{'&&password[temp_0]!='\n'&&password[temp_0]!=13)
		{
			temp_0++;
		} 
		password[temp_0]='\0';
		//正文输入结束
		getchar(); //获得并消'\n'
		printf("Password is \'%s\',right?\n",password);
		printf("Y or N\n");
		char temp_1;
	while((temp_1=getchar())=='\n'){}
	getchar();
	if(temp_1=='Y')
	{
		printf("Next: Encrypt it\n");
		printf("\n************************************************\n\n");
		return 2;
	}
	else if(temp_1=='N')
	{
		printf("Then: Go back and enter it again\n");
		printf("\n************************************************\n\n");
		return 1;
	}
	else
	{
		printf("Can not understand:Treat it as Y\n");
		printf("Next: Encrypt it\n");
		printf("\n************************************************\n\n");
		return 2;
	}
} 
int Encrypt()
{
	printf("Start Encrypt\n");
	printf("Loading...\n\n\n");
	//生成种子
	char psw_after[1000];
	int length;
	int mod=0;
	while(mod==0)
	{
		seed=rand();
	    //取长度模
	    length=strlen(password);
	    mod=seed%length;	
	}
    //移位对应
    char temp_0[1000];
	for(int i=0;i<mod;i++)
	{
		temp_0[i]=password[i];
	} 
	for(int i=0;i<length-mod;i++)
	{
		psw_after[i]=password[i+mod];
	}
	for(int i=length-mod;i<length;i++)
	{
		psw_after[i]=temp_0[i-length+mod];
	}
	//对应完成
	printf("psw_after is %s\n",psw_after);
	//减至ASCII最小值为0
	for(int i=0;i<length;i++)
	{
		psw_after[i]-=32;
		password[i]-=32;
		printf("password[i]=%d\n",password[i]);
	}
	//相加除以2，输出，若为奇数则下拉并输出‘~’
	char psw_done;
	printf("After encrypt,your password is...\n\n");
	printf("%s",title);//输出title 
	char temp_10086[1000];
	for(int i=0;i<length;i++)
	{
		int checker=0;
		int halfwords;
		halfwords=password[i]+psw_after[i];
		checker=halfwords%2;
		halfwords/=2;
		psw_done=halfwords;
        printf("%c",psw_done);
        temp_10086[i]=psw_done;
        if(checker!=0)
            printf("~");
	} 
	//输出种子
	printf("{%d}{%d}\n",seed,password[0]); 
	for(int i=0;i<length;i++)
	{
		printf("psw[%d]=%d\n",i,temp_10086[i]);
	}
	printf("\nEncryption is completed\n");
	printf("************************************************\n");
	printf("Press any key to back to select\n\n");
	return 0;
}
int Decrypt_input()
{
	for(int i=0;i<1000;i++)
	{
		title[i]='\0';
		password[i]='\0';
	}
	// 0 means back to select
	// 1 means back to reinput
	// 2 means input right
	int temp_0=0;
		printf("Let's Decrypt it\n"); 
		printf("Please input your password\n");
		printf("The Format is \" [title]password{seed}{p1} \"\n");
		printf("If you want to go back please press B\n");
		//输入标题 
		while((title[temp_0]=getchar())!=']')
		{
			if(title[0]=='\n')
			{
				continue;
			}
			else if(title[0]=='b'||title[0]=='B')
			{
				getchar();
				printf("Back and select\n");
				printf("\n************************************************\n\n");
								
				//返回选择	
				return 0;
			
			}
			else if(title[0]!='[')
			{
				scanf("%s",title);//消去剩下内容 
				printf("Format Error:Please start with [\n");
				printf("Please enter your password once again\n");
				printf("\n************************************************\n\n");
		        
		        //返回输入
				return 1;
			}
			else if((title[temp_0]==-65&&title[temp_0-1]==-95)||(title[temp_0]==-66&&title[temp_0-1]==-95))//输入有误 
			{
				getchar();
				printf("Format Error: Please change 【 】 to []\n");
				printf("Please enter your password once again\n");
				printf("\n************************************************\n\n");
		        
		        //返回输入
				return 1;
			}
			temp_0++;
		}
		title[temp_0+1]='\0'; //除掉乱七八糟的其他东西 
		printf("Title is %s\n",title); 
		//标题输入结束
		//正文输入开始
		temp_0=0;
		while((password[temp_0]=getchar())!='{'&&password[temp_0]!='\n'&&password[temp_0]!=13)
		{
			temp_0++;
		} 
		password[temp_0]='\0';
		//正文输入结束
		//种子输入开始
		scanf("%d",&seed);
		char temp_00=getchar();
		if(temp_00!='}')
		{
			scanf("%s",title);//title再循环会被重置：此处用于除去剩下内容 
			getchar();
			printf("Format Error 1: Please input seed in the format \" {seed}{p1} \" and put it right after your password\n");
			printf("Please enter your password once again\n");
			printf("\n************************************************\n\n");
	   
		    //返回输入
			return 1;
		} 
		getchar();//'{'
		scanf("%d",&p1);
		temp_00=getchar();
		if(temp_00!='}')
		{
			scanf("%s",title);//title再循环会被重置：此处用于除去剩下内容 
			getchar();
			printf("Format Error 2: Please input seed in the format \" {seed}{p1} \" and put it right after your password\n");
			printf("Please enter your password once again\n");
			printf("\n************************************************\n\n");
	   
		    //返回输入
			return 1;
		} 
		getchar();// \n 
		printf("Password is \'%s\', seed is %d, p1 is %d, right?\n",password,seed,p1);
		printf("Y or N\n");
		char temp_1;
	while((temp_1=getchar())=='\n'){}
	getchar();
	if(temp_1=='Y')
	{
		printf("Next: Decrypt it\n");
		printf("\n************************************************\n\n");
		return 2;
	}
	else if(temp_1=='N')
	{
		printf("Then: Go back and enter it again\n");
		printf("\n************************************************\n\n");
		return 1;
	}
	else
	{
		printf("Can not understand:Treat it as Y\n");
		printf("Next: Decrypt it\n");
		printf("\n************************************************\n\n");
		return 2;
	}
}
int Decrypt()
{
	printf("Start Decrypt\n");
	printf("Loading...\n\n\n");
	int psw_plus[1000];
	int psw_pluslong[1000];
	int psw_fir[1000];
	int psw_long[1000];
	int counter=0;
	char psw[1000];
	//录入相加后数组 
	for(int i=0;i<strlen(password);i++)
	{
		if(password[i]!='~')
		{
			if(password[i+1]=='~')
			{
				int temp=password[i]*2+1;
				psw_plus[counter]=temp;
				printf("1  pswplus[%d]=%d %d %d password[%d]=%d\n",counter,psw_plus[counter],password[i]*2+1,temp,i,password[i]);
				counter++;
			}
			else
			{
				int temp=password[i]*2;
				psw_plus[counter]=temp;
				printf("2  pswplus[%d]=%d %d %d password[%d]=%d\n",counter,psw_plus[counter],password[i]*2,temp,i,password[i]);
				counter++;
			}
		}
		else
		{
			continue;
		}
	}
	for(int i=0;i<counter;i++)
	{
		printf("%d ",psw_plus[i]);
	}
	printf("\n");
	printf("counter=%d\n",counter);
	//相加后数组加长（便于操作）
	for(int i=0;i<counter;i++)
	{
		psw_pluslong[i]=psw_plus[i];
		printf("psw_pluslong[%d]=%d\n",i,psw_pluslong[i]);
	} 
	for(int i=counter;i<2*counter;i++)
	{
		psw_pluslong[i]=psw_plus[i-counter];
		printf("psw_pluslong[%d]=%d\n",i,psw_pluslong[i]);
	}
	//拆出原密码
	int psw_len=counter;
	printf("psw_len=%d\n",psw_len);
	psw_long[0]=p1;
	printf("psw_long[0]=%d\n",psw_long[0]);
	for(int i=0;i<psw_len;i++)
	{
		printf("%d\n",i);
		psw_long[i+seed%counter]=psw_pluslong[i]-psw_long[i];
		printf("psw_long[%d]=%d\n",i+seed%counter,psw_long[i+seed%counter]);
	} 
	for(int i=1;i<seed%counter;i++)
	{
		
	}
	//恢复原长度,加回32 
	for(int i=0;i<psw_len;i++)
	{
		psw_fir[i]=psw_long[i]+32;
	} 
	for(int i=0;i<psw_len;i++)
	{
		psw[i]=psw_fir[i];
	}
	psw[psw_len]='\0';
	printf("After Decrypt,your password is...\n\n");
	printf("%s%s",title,psw);
	printf("\nDecryption is completed\n");
	printf("************************************************\n");
	printf("Press any key to back to select\n\n");
	return 0;
}
int main()
{
	srand((unsigned)time(NULL));
	
start:
	//goto语句点 
	//预备阶段 
	printf("Welcome to MpAsW v1.00\n");
	printf("Please select the service you need\n");
	printf("\n************************************************\n\n");
	
	
	//选择阶段 
select:
	//goto语句点 
	
	printf("\nSelect Start\n");
	printf("Encrypt Or Decrypt?\n");
	printf("Please Press E Or D\n");
	printf("\n************************************************\n\n");
	while((type=getchar())=='\n'){}
	getchar(); 
	printf("Get it: %c\n",type);
	if(type=='E'||type=='e')
	{
		//输入语句 
		int checker_0=0;
		while(checker_0!=2)
		{
			checker_0=Encrypt_input();
			if(checker_0==0)//重新选择 
			    goto select;
			else if(checker_0==1)//重新输入 
			    continue;
			else if(checker_0==2)
			    break;
			else
			{
				printf("System Error:Press any key to restart the program\n");
				printf("\n************************************************\n");
				printf("\n************************************************\n");
				printf("\n************************************************\n\n");
				getch();
				goto start; 
			}
		} 
		//checker_0=2:正常执行，下一步加密 
		//加密
		checker_0=Encrypt();
		if(checker_0==0)
		    goto select;
		else
		{
			printf("System Error:Press any key to restart the program\n");
			printf("\n************************************************\n");
			printf("\n************************************************\n");
			printf("\n************************************************\n\n");
			getchar();
			getch();
			goto start; 
		} 
	}
	else if(type=='D'||type=='d')
	{
		int checker_0=0;
        while(checker_0!=2)
		{
			checker_0=Decrypt_input();
			if(checker_0==0)//重新选择 
			    goto select;
			else if(checker_0==1)//重新输入 
			    continue;
			else if(checker_0==2)
			    break;
			else
			{
				printf("System Error:Press any key to restart the program\n");
				printf("\n************************************************\n");
				printf("\n************************************************\n");
				printf("\n************************************************\n\n");
				getch();
				goto start; 
			}
		} 
		//checker_0=2:正常执行，下一步解密 
		checker_0=Decrypt();
		if(checker_0==0)
		    goto select;
		else
		{
			printf("System Error:Press any key to restart the program\n");
			printf("\n************************************************\n");
			printf("\n************************************************\n");
			printf("\n************************************************\n\n");
			getchar();
			getch();
			goto start; 
		} 
	}
} 
