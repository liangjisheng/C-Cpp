// 判断一字符串事是否问回文
int func(char* p)
{
	if(p==NULL) return -1;	// 空值返回-1
	else {
		int len=strlen(p)-1;
		char *q=p+len;
		while(p<q) {
			if((*p++) != (*q--))
				return 0;
		}
		return 1;
	}
}