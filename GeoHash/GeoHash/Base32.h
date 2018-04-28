/********************
Function:	Base32编码
			Base32码是由5位二进制码组成
Inputs:		GeoHash值----40个0/1字符串
Return:		8个Base32码
*********************/

#ifndef Base32_H
#define Base32_H

#include<iostream>
#include<string>
using namespace std;

class Base32
{
public:
	Base32();
	string Base32Encode(string binStr);
private:
	string encodeStr;	/* 编码后的字符串 */
	char Base32Table[32] = { '0','1','2','3','4','5','6','7','8','9','b','c','d','e','f','g',
		'h','j','k','m','n','p','q','r','s','t','u','v','w','x','y','z' };	/* Base32编码表 */
};

/* 构造函数 */
Base32::Base32()
{
	encodeStr = "";
}

/* Base32编码. 40个0/1字符串binHash,每5位编为1个Base32码,最后生成8个Base32码,存为encodeStr */
string Base32::Base32Encode(string binHash)
{
	if (binHash.empty())
		return encodeStr;
	int bin2dec;	/* 将binStr中的每5位二进制码编为1个十进制数 */
	for (int k = 0; k < 8; ++k)
	{
		bin2dec = 0;
		for (int i = k * 5; i < (k + 1) * 5; ++i)
			bin2dec = bin2dec * 2 + (binHash[i] == '1' ? 1 : 0);
		encodeStr += Base32Table[bin2dec];
	}
	return encodeStr;
}

#endif // !Base32_H
