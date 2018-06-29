/************************************************************************/
/*
	函数功能: 将string中的指定字符(串)全部替换为新的字符(串)
	str:开始的字符串
	old_value:str中原来的字符串
	new_value:新的字符串
	返回string是为了支持链式操作,&不会调用对象的复制构造函数
*/
/************************************************************************/
std::string& replace_all(std::string &str, const std::string &old_value, 
	const std::string & new_value)
{
	while(true)
	{
		std::string::size_type pos(0);
		if((pos = str.find(old_value)) != std::string::npos)
			str.replace(pos, old_value.length(), new_value);
		else
			break;
	}
	return str;
}