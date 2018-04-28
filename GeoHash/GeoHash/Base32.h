/********************
Function:	Base32����
			Base32������5λ�����������
Inputs:		GeoHashֵ----40��0/1�ַ���
Return:		8��Base32��
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
	string encodeStr;	/* �������ַ��� */
	char Base32Table[32] = { '0','1','2','3','4','5','6','7','8','9','b','c','d','e','f','g',
		'h','j','k','m','n','p','q','r','s','t','u','v','w','x','y','z' };	/* Base32����� */
};

/* ���캯�� */
Base32::Base32()
{
	encodeStr = "";
}

/* Base32����. 40��0/1�ַ���binHash,ÿ5λ��Ϊ1��Base32��,�������8��Base32��,��ΪencodeStr */
string Base32::Base32Encode(string binHash)
{
	if (binHash.empty())
		return encodeStr;
	int bin2dec;	/* ��binStr�е�ÿ5λ���������Ϊ1��ʮ������ */
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
