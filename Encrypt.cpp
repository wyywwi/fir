int Encrypt()
{
	printf("Start Encrypt\n");
	printf("Loading...\n\n\n");
	//��������
	char psw_after[1000];
	int length;
	int mod=0;
	while(mod==0)
	{
		seed=rand();
	    //ȡ����ģ
	    length=strlen(password);
	    mod=seed%length;	
	}
    //��λ��Ӧ
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
	//��Ӧ���
	//����ASCII��СֵΪ0
	for(int i=0;i<length;i++)
	{
		psw_after[i]-=32;
		password[i]-=32;
	}
	//��ӳ���2���������Ϊ�����������������~��
	char psw_done;
	pritnf("After encrypt,your password is...\n\n");
	printf("%s",title);//���title 
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
	//�������
	printf("{%d}",seed); 
	printf("\nEncryption is completed\n");
	printf("************************************************\n");
	printf("Press any key to back to select\n\n");
	return 0;
}
