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
				getchar();
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
			printf("Format Error: Please input seed in the format \" {seed} \"\n");
			printf("Please enter your password once again\n");
			printf("\n************************************************\n\n");
	   
		    //返回输入
			return 1;
		} 
		getchar();// \n 
		printf("Password is \'%s\', seed is %d, right?\n",password,seed);
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
