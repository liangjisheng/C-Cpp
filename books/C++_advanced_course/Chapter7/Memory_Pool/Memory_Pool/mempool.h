
// �ڴ�����������Ʊ�׼��new/delete�ڴ������ƿ�����ɵ�����Ч�ʵ��µ������һ�ּ���
// ��C++�У����Ƶ���������С��ͬ�Ķ��󣬿����ڶѿռ���ɺܶ���Ƭ���Ӷ�ӡӰ�춯̬�ڴ�
// ������Ч�ʣ�ͬʱ������ͨ�õ��ڴ�������Ҫ���Ǻܶิ�ӵľ������(��Ӧ�����̻߳�����)
// ���Զ��㷨����Ч���Ż���������һЩ���ⳡ�ϣ�����һЩ�����������ܹ���һ���̶������
// �ڴ�����Ч��
// ������ڴ�ؼ���(Memory Pool)��������һ�����ڷ��������С��ͬ��С����ļ�����ͨ��
// �ü������Լ���ļӿ��ڴ����/�ͷŹ��̡���Ȼ������ض����������ڴ�أ������ڴ��
// һ������Ϊ��ģ�壬���ݲ�ͬ�Ķ���Ĵ�С����ʵ����
// ������ڴ�ص��ڲ��ṹ�������ģ�������һ���������ڴ�ռ�(Memory Block),�ÿռ�������
// һ�������Ķ���ÿ��������ͬһ��ָ����һ�������ָ��һ�𹹳�һ���ڴ�ڵ�(Memory Node)
// ���ڴ�ڵ�֮��ͨ��ָ���γ�һ�����������е�ÿһ���ڵ㶼��һ��ɹ�������ڴ�ռ�
// ĳ���ڴ�ڵ�һ�������ȥ���ͽ���������ȥ������һ���ͷ���ĳ���ڴ�ڵ�Ŀռ䣬�ֻὫ
// �ýڵ����¼��������ڴ�ڵ��������һ���ڴ���е������ڴ�ڵ��Ѿ�������ϣ�������
// ���������µĶ���ռ䣬����ڴ�����һ���ڴ�飬�Ա���ڴ���зָ���µ��ڴ�ڵ㡣
// �����ڴ����ģ���������������ݳ�Ա������������MemBlockSize(�ڴ��Ĵ�С)��ItemSize
// (����Ĵ�С)���Լ�����ָ�����pMemBlockHeader(ָ���ڴ������ĵ�һ���ڵ�)
// pFreeNodeHeader(ָ���ڴ�ڵ�����ĵ�һ���ڵ�)����ʼ����ָ���Ϊ�գ�
// һ���ṩ�˾����ڴ�ص�һ��ʵ�ַ���


// ObjectSize����ʵ������Ķ���Ĵ�С
// NumofObjects����ÿ���ڴ���������ɵĶ������
template<int ObjectSize, int NumofObjects = 20>
class MemPool
{
private:
	const int MemBlockSize;		// ÿ���ڴ��Ĵ�С
	const int ItemSize;			// ÿ���ڴ�ڵ�Ĵ�С
	struct _FreeNode
	{
		_FreeNode *pNext;
		char data[ObjectSize];
	};
	struct _MemBlock
	{
		_MemBlock *pNext;
		_FreeNode data[NumofObjects];
	};
	_MemBlock *pMemBlockHeader;
	_FreeNode *pFreeNodeHeader;
public:
	MemPool() : ItemSize(ObjectSize + sizeof(_FreeNode*)),
		MemBlockSize(sizeof(_MemBlock*) + NumofObjects * (ObjectSize + sizeof(_FreeNode*)))
	{
		pMemBlockHeader = NULL;
		pFreeNodeHeader = NULL;
	}
	~MemPool()
	{
		_MemBlock *ptr;
		while(pMemBlockHeader)
		{
			ptr = pMemBlockHeader;
			delete pMemBlockHeader;
			pMemBlockHeader = ptr;
		}
	}
	void* malloc();
	void free(void*);
};

// ���ض�������ԣ��ڴ�����ڴ��Ĵ�С�ǹ̶��ģ��ڴ�ڵ�Ĵ�СҲ�ǹ涨�ģ��ڴ��
// ������֮���ͱ�����Ϊ����ڴ�ڵ㣬ÿ��Node�Ĵ�СΪItemSize(����Ĵ�С����һ��ָ��)
// �տ�ʼʱ���еĽڵ㶼�����ɵģ����Ǳ���������
// ָ�����pMemBlockHeader�ǰ�����������ڴ��(Memory Block)����һ�������Ա�ͨ����
// �����ͷ�����������ڴ棬pFreeNodeHeader�������ǰ����е������ڴ�ڵ�(Free Node)��
// ��һ������pFreeNodeHeaderΪ�ձ����Ѿ�û�п��õ������ڴ�ڵ㣬���������µ��ڴ��

// ����������£��������ڴ�ڵ�����(pFreeNodeHeader)�ǿյ�����£�malloc����ֻ�Ǵ�
// ������ժ�������ڴ�ڵ������ͷһ���ڵ㣬Ȼ�������ͷָ���ƶ�����һ���ڵ���ȥ��
// ������ζ����Ҫһ���µ��ڴ��(Memory Block),���������Ҫ����������ڴ���и��
// ����ڴ�ڵ㣬�������Ǵ��������ڴ�ؼ�������Ҫ������������
template<int ObjectSize, int NumofObjects /* = 20*/>
void* MemPool<ObjectSize, NumofObjects>::malloc()
{
	if(pFreeNodeHeader == NULL)
	{
		_MemBlock *pNewBlock = new _MemBlock;
		pNewBlock->data[0].pNext = NULL;
		for(int i = 1; i < NumofObjects; ++i)
			pNewBlock->data[i].pNext = &pNewBlock->data[i - 1];
		pFreeNodeHeader = &pNewBlock->data[NumofObjects - 1];
		pNewBlock->pNext = pMemBlockHeader;
		pMemBlockHeader = pNewBlock;
	}
	void *pFreeNode = pFreeNodeHeader;
	pFreeNodeHeader = pFreeNodeHeader->pNext;
	return pFreeNode;
}

// �ͷŵĹ��̣�ֻҪ�ѱ��ͷŵĽڵ����²��뵽�����ڴ�ڵ�����Ŀ�ͷ���ɣ�����ͷŵ�
// �ڵ������һ������������Ľڵ㣬�ڴ�ؼ�������/�����ڴ���ٶȺܿ죬���ڴ�������
// ��������¸��Ӷ�ΪO(1),��Ҫ������pFreeNodeHeaderΪ��ʱ��Ҫ�����µ��ڴ�飬�ڴ�
// �ͷŹ��̵ĸ��Ӷ�ΪO(1)
template<int ObjectSize, int NumofObjects /* = 20*/>
void MemPool<ObjectSize, NumofObjects>::free(void* p)
{
	// �ͷ�pָ����ڴ�鲢�����������ͷ�p����ֻ�ǽ�pָ����ڴ������ڴ����
	// ���е��ڴ棬�´η�������ʱ�������ʹ�ø��ͷŵ�������ڴ�
	_FreeNode* pNode = (_FreeNode*)p;
	pNode->pNext = pFreeNodeHeader;
	pFreeNodeHeader = pNode;
}

// �����ڴ�ط����������������磺ֻ�ܵ��������������ռ䣬���������������
// �ڴ���е��ڴ��ĸ���ֻ��Խ��Խ�󣬲��ܼ�С�������кܶ�Ľ�����

