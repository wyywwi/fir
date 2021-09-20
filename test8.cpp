#include<cstdio>
#include<cstring>
int main(){
	char ss[100];
    char aa[100];
    scanf("%s",ss);
    scanf("%s",aa);
    char b;
    for(int i=0;i<5;i++)
    {
    	int temp;
    	temp=ss[i]+aa[i];
    	int checker=temp%2;
    	temp/=2;
    	b=temp;
    	printf("%c",b);
    	if(checker!=0)
    	    printf("~");
	}
	return 0;
}
