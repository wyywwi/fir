int Decrypt()
{
	printf("Start Decrypt\n");
	printf("Loading...\n\n\n");
	char psw_plus[1000];
	char psw_pluslong[1000];
	char psw_fir[1000];
	char psw_long[1000];
	int counter=0;
	//录入相加后数组 
	for(int i=0;i<strlen(password);i++)
	{
		if(password[i]!='~')
		{
			if(password[i+1]=='~')
			{
				psw_plus[counter]=password[i]*2+1;
				counter++;
			}
			else
			{
				psw_plus[counter]=password[i]*2;
				counter++;
			}
		}
	}
	//相加后数组加长（便于操作）
	for(int i=0;i<strlen(psw_plus);i++)
	{
		psw_pluslong[i]=psw_plus[i];
	} 
	for(int i=strlen(psw_plus);i<2*strlen(psw_plus);i++)
	{
		psw_pluslong[i]=psw_plus[i-strlen(psw_plus)];
	}
	//拆出原密码
	int psw_len=strlen(psw_plus);
	psw_long[0]=p1;
	for(int i=0;i<psw_len;i++)
	{
		psw_long[i+1]=psw_pluslong[i+1+seed]-psw_pluslong[i]+psw_long[i];
	} 
	//恢复原长度,加回32 
	for(itn i=0;i<psw_len;i++)
	{
		psw_fir[i]=psw_long[i]+32;
	} 
	psw_fir[psw_len+1]='\0';
	pritnf("After Decrypt,your password is...\n\n");
	printf("%s%s",title,psw_fir);
	printf("\nDecryption is completed\n");
	printf("************************************************\n");
	printf("Press any key to back to select\n\n");
	return 0;
}
