// �ж�һ�ַ������Ƿ��ʻ���
int func(char* p)
{
	if(p==NULL) return -1;	// ��ֵ����-1
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