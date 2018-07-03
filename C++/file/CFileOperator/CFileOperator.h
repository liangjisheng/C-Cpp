
#ifndef __CFILEOPERATOR_H__
#define __CFILEOPERATOR_H__

#include <vector>

class CFileOperator
{
public:
	/**
	 * function: 判断文件是否存在
	 * param: strFilePath：文件路径
	 * return: TRUE:存在，FALSE不存在
	*/
	static BOOL IsFileExist(const CString& strFilePath);

	/**
	 * function: 判断文件是否存在,使用_access()
	 * param: filePath：文件路径
	 * return: true:存在，false不存在
	*/
	static bool IsFileExist_1(const char *filePath);

	/**
	 * function: 判读目录是否存在
	 * param: strDirPath：目录路径
	 * return: TRUE:存在，FALSE不存在
	*/
	static BOOL IsDirExist(const CString& strDirPath);

	/**
	 * function: 判断文件或文件夹是否存在
	 * param: strPath：路径
	 * return: TRUE:存在，FALSE不存在
	*/
	static BOOL IsPathExist(const CString& strPath);

	/**
	 * function: 判断文件或文件夹是否存在
	 * param: strPath：路径
	 * return: TRUE:存在，FALSE不存在
	*/
	static BOOL IsPathExist_1(const CString & strPath);

	/**
	 * function: C语言获取文件内容
	 * param: buffer：存放文件内容的缓冲区,filePath:文件路径
	 * return: 文件的字节长度
	*/
	static int GetFileContent(char **buffer, const char *filePath);

	/**
	 * function: 获取文件的字节长度
	 * param: filePath:文件路径
	 * return: 字节长度
	*/
	static int GetFileLength(const char *filePath);

	/**
	 * function: 将字符串写入临时文件，并获取临时文件名
	 * param: strContent：要写入的内容，strTmpFilePath：获取的临时文件名
	 * return: None
	*/
	static void WriteTmpFile(const CString &strContent, CString &strTmpFilePath);

	/**
	 * function: 将指定目录strDirPath下的指定后缀名strSuffixName的所有文件存到vecFileName里
	 * param:
	 * return: 所有找到的文件个数
	*/
	static int GetPointerFile(const CString& strDirPath, const CString& strSuffixName, 
		std::vector<CString>& vecFileName);

	/**
	 * function: 删除指定目录strDirPath下指定后缀名strSuffixName的所有文件
	 * param:
	 * return: 删除的文件个数
	*/
	static int DeletePointerFile(const CString& strDirPath, const CString& strSuffixName);

	/**
	 * function: 存储指定目录strDirPath下的所有文件和目录
	 * param:
	 * return: 所有目录项(文件和目录)的个数
	*/
	static int GetAllItems(const CString& strDirPath, std::vector<CString>& vecName);

	/**
	 * function: 存储指定目录strDirPath下的所有文件和目录
	 * param:
	 * return: 所有目录项(文件和目录)的个数
	*/
	static int GetAllItems_1(const CString& strDirPath, std::vector<CString>& vecName);

	/**
	 * function: 获取指定目录下strDirPath的所有目录
	 * param:
	 * return: 目录的个数
	*/
	static int GetAllDirs(const CString& strDirPath, std::vector<CString>& vecName);

	/**
	 * function: 获取指定目录strDirPath下的所有文件
	 * param:
	 * return: 文件的个数
	*/
	static int GetAllFile(const CString& strDirPath, std::vector<CString>& vecName);

	/**
	 * function: 删除指定目录(包括子目录及其所有文件)
	 * param: strDirPath:指定目录
	 *		  std::vector<CString>& vecName;删除目录项名
	 * return: 总共删除目录项(文件和目录)的个数
	*/
	static int DeleteAllItems(const CString& strDirPath, std::vector<CString>& vecName);

	/**
	 * function: 获取指定目录strDirPath下所有指定的文件夹名strPointerDir
	 * param:
	 * return: 目录项个数
	*/
	static int GetAllPointerDir(const CString& strDirPath, const CString& strPointerDir, 
		std::vector<CString>& vecName);

	// 目录项个数
	static int s_nItemsNum;
};

#endif  //__CFILEOPERATOR_H__