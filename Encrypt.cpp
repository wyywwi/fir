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
	//减至ASCII最小值为0
	for(int i=0;i<length;i++)
	{
		psw_after[i]-=32;
		password[i]-=32;
	}
	//相加除以2，输出，若为奇数则下拉并输出‘~’
	char psw_done;
	pritnf("After encrypt,your password is...\n\n");
	printf("%s",title);//输出title 
	for(int i=0;i<length;i++)
	{
		int checker=0;
		int halfwords;
		halfwords=password[i]+psw_input[i];
		checker=halfwords%2;
		halfwords/=2;
		psw_done=halfwords;
        printf("%c",psw_done);
        if(checker!=0)
            printf("~");
	} 
	//输出种子
	printf("{%d}",seed); 
	printf("\nEncryption is completed\n");
	printf("************************************************\n");
	printf("Press any key to back to select\n\n");
	return 0;
}
