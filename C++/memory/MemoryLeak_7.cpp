
// 将D:\tmp文件夹下的所有文件的内容全部放到用malloc分配的内存中
// 测试是否有内存泄露

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <io.h>

#ifdef _DEBUG
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#endif

struct FB
{
	char fn[256];
	size_t fl;
	char *b;
	struct FB *next;
	struct FB *prev;
}*fh, *fb, *ft;

char ln[256] = {0};
char fpn[256] = {0};
FILE *af = NULL;
FILE *f = NULL;
int L, n;

int main()
{
#ifdef _DEBUG
	// 设置malloc使用Debug版的malloc,当malloc之后没有free就会报内存泄露
	_CrtSetDbgFlag(_CRTDBG_LEAK_CHECK_DF | _CRTDBG_ALLOC_MEM_DF);
	_CrtDumpMemoryLeaks();
#endif

	// 将D:\\tmp\\*.*所有文件的文件名输出到D:\\allfn.txt文件中
	// 然后读文件D:\\allfn.txt遍历每一个文件，做相应的操作
	system("dir /b /a-d D:\\tmp\\*.* > D:\\allfn.txt");
	af = fopen("D:\\allfn.txt", "r");
	if (NULL == af)
	{
		printf("Can not open file D:\\allfn.txt\n");
		return 1;
	}

	fh = NULL;
	fb = NULL;
	n = 0;

	while (1)
	{
		if (NULL == fgets(ln, 256, af))
			break;
		L = strlen(ln);
		if ('\n' == ln[L - 1])
			ln[L - 1] = '\0';

		strcpy(fpn, "D:\\tmp\\");
		strcat(fpn, ln);
		ft = (struct FB *)malloc(sizeof(struct FB));
		if (NULL == ft)
		{
			printf("Can not malloc ft!\n");
			fclose(af);
			return 2;	// 之前的malloc在main退出后由操作系统自动free
		}

		printf("ft[%d] == %p\n", n, ft);
		strcpy(ft->fn, fpn);
		f = fopen(fpn, "rb");
		if (NULL == f)
		{
			printf("Can not open file %s\n", fpn);
			fclose(af);
			return 3;	// 之前的malloc在main退出后由操作系统自动free
		}

		// fileno()通过文件指针，返回文件标识符
		// _filelength通过文件标识符获取文件字节长度
		ft->fl = _filelength(fileno(f));
		ft->b = (char *)malloc(ft->fl);
		if (NULL == ft->b)
		{
			printf("Can not malloc ft->b\n");
			fclose(f);
			fclose(af);
			return 4;	// 之前的malloc在main退出后由操作系统自动free
		}

		printf("ft[%d]->b = %p\n", n, ft->b);
		if (ft->fl != fread(ft->b, 1, ft->fl, f))
		{
			printf("fread error\n");
			fclose(f);
			fclose(af);
			return 5;	// 之前的malloc在main退出后由操作系统自动free
		}
		fclose(f);
		ft->next = NULL;

		if (NULL == fh)
		{
			ft->prev = NULL;
			fh = ft;
		}
		else
		{
			fb->next = ft;
			ft->prev = fb;
		}
		fb = ft;
		n++;
	}

	fclose(af);
	printf("---------list---------\n");
	for (ft = fh; ft != NULL; ft = ft->next)
	{
		printf("%8d %s\n", ft->fl, ft->fn);
		if (NULL != ft)
			fb = ft;
	}
	printf("-----free-----------\n");
	n--;
	if (NULL != fh)
	{
		for (ft = fb->prev; ft != NULL; ft = ft->prev)
		{
			if (NULL != ft->next->b)
			{
				printf("ft[%d]->b = %p\n", n, ft->next->b);
				free(ft->next->b);
			}
			if (NULL != ft->next)
			{
				printf("ft[%d] = %p\n", n, ft->next);
				free(ft->next);
			}
			n--;
		}

		if (NULL != fh->b)
		{
			printf("ft[0]->b = %p\n", fh->b);
			free(fh->b);
		}

		printf("ft[0] = %p\n", fh);
		free(fh);
	}

	getchar();
	return 0;
}