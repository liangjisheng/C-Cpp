 // 判断一字符串是否为回文
int func(char* p)
{
	if(p==NULL) return 0;
	else {
		int length=0,i=0,judge=1;
		length=strlen(p);
		for(i=0;i<len/2;i++) {
			if(p[i]!=p[len-1-i])
			{ judge=0; break;}
		}
		if(judge==0) return 0;
		else return 1;
	}
}