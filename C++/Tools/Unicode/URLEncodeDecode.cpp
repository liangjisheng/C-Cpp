// ANSI to URLEncode
string URLEncode(const string &sIn)
{
	string sOut = "";
	for( size_t ix = 0; ix < sIn.size(); ix++ )  
	{        
		unsigned char buf[4] = {0};
		if( isalnum( (unsigned char)sIn[ix] ) )         
			buf[0] = sIn[ix];  
		//else if ( isspace( (BYTE)sIn[ix] ) ) //貌似把空格编码成%20或者+都可以  
		//{  
		//    buf[0] = '+';  
		//}  
		else  
		{  
			buf[0] = '%';  
			buf[1] = toHex( (unsigned char)sIn[ix] >> 4 );  
			buf[2] = toHex( (unsigned char)sIn[ix] % 16);  
		}  
		sOut += (char *)buf;  
	}  
	return sOut;  
}

unsigned char toHex(const unsigned char &x)
{  
	return x > 9 ? x -10 + 'A': x + '0';  
}

// URLDecode to ANSI
string URLDecode(const string &sIn)
{  
	string sOut = "";
	for( size_t ix = 0; ix < sIn.size(); ix++ )
	{  
		unsigned char ch = 0;
		if(sIn[ix] == '%')
		{  
			ch = (fromHex(sIn[ix + 1]) << 4);
			ch |= fromHex(sIn[ix + 2]);
			ix += 2;
		}  
		else if(sIn[ix] == '+')
			ch = ' ';
		else  
			ch = sIn[ix];  

		sOut += (char)ch;  
	}  
	return sOut;
}

unsigned char fromHex(const unsigned char &x)
{  
	return isdigit(x) ? x - '0' : x - 'A' + 10;
}