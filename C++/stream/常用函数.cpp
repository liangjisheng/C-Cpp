in_stream.get();
in_stream.get(char_variable);
in_stream.get(char_array,n);
in_stream.get(char_array,n,terminator);

in_stream.getline(char_array,n);
in_stream.getline(char_array,n,terminator);

in_stream.read(char_array,n);
in_stream.readsome(char_array,n);
in_stream.gcount();					//返回提取的字符个数
in_stream.peek();					//返回下一个读取的字符
in_stream.ignore(n,stopchar);
in_stream.putback(ch);
in_stream.unget(ch);				//将最近读到的字符返回到in_stream中
in_stream.seekg(n);
in_stream.seekg(offset,base);		//读指针移位
in_stream.tellg();					//读取读指针的位置
in_stream.sync();

out_stream<<experssion
out_stream.put(ch);
out_stream.write(char_array,n);
out_stream.seekp(n);
out_stream.seekp(offset_base);		//写指针移位
out_stream.tellp();					//读取写指针从位置
out_stream.flush();					//刷新out_stream

//文件
ios::trunc		//打开一个文件，并清除文件包含的任何内容
ios::ate		//打开文件，并将读取位置设置到文件末尾
ios::nocreate	//打开文件，且这个文件必须存在
ios::noreplace	//打开文件，且这个文件必须事先不存在
ios::badbit		//如果发生一个无法恢复的错误，为1，否则为0
ios::failbit	//如果发生一个可以恢复的错误，为1，否则为0
stream.setstate(sBit);//设置标志位为1
stream.good()	//good位被设置为1是，返回true
stream.fail();
stream.bad();
stream.eof();
stream.clear();

//cstring
strcat(s1,s2);
strncat(s1,s2,n);		//将s2中最多n个字符添加到s1中
strcpy(s1,s2);
strncpy(s1,s2,n);
strlen(s);
strcmp(s1,s2);
strncmp(s1,s2,n);
strchr(s,c);		//返回一个指向c在s中第一次出现的位置的指针，若没有，返回空
strrchr(s,c);		//返回c在s中最后出现的位置，若没有，返回空
strstr(s1,s2);		//返回s2在s1中第一次出现的位置，，若没有，返回空
strpbrk(s1,s2);		//返回指向在s1中第一次出现s2中任何字符的指针，，若没有，返回空
strspn(s1,s2);		//返回s1中在s2包含的任何字符的前面的字符个数
strcspn(s1,s2);		//返回s1中不包含在s2中的字符前面的字符个数

double atof(s);		//将字符串s分别转换成相应的double型，int型恶和long型
int atoi(s);
long atol(s);
