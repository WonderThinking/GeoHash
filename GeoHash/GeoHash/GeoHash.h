/********************
Function:	GeoHash�㷨������γ������ת��ΪGeoHashֵ
Inputs:		��γ��
Return:		GeoHashֵ----40λ��0/1�ַ���
*********************/
#ifndef GeoHash_H
#define GeoHash_H

#include<iostream>
using namespace std;

class GeoHash
{
private:
	double MINLNG = -180;	/* ��С���� */
	double MAXLNG = 180;	/* ��󾭶� longitude */
	double MINLAT = -90;	/* ��Сγ�� */
	double MAXLAT = 90;		/* ���γ�� latitude */

	string lngHash;			/* ���ȵ�GeoHashֵ */
	string latHash;			/* γ�ȵ�GeoHashֵ */
	string binHash;			/* ��������ʽ��GeoHashֵ(�ϲ�lngHash��latHash) */
public:
	GeoHash();
	string getGeoHash(double longitude, double latitude);
private:
	void getGeoHash(double location, string &locationHash, double left, double right);	/* ��ȡ���Ȼ�γ�ȵ�GeoHashֵ*/
	void mergeGeoHash();	/* �����Ⱥ�γ�ȵ�GeoHashֵ�ϲ�,�Ⱦ�����γ�Ƚ���ϲ� */
};

/* ���캯�� */
GeoHash::GeoHash()
{
	lngHash = "";
	latHash = "";
	binHash = "";
}

/* �ɾ�γ�Ȼ�ȡGeoHashֵ */
string GeoHash::getGeoHash(double longitude, double latitude)
{
	getGeoHash(longitude, lngHash, MINLNG, MAXLNG);
	getGeoHash(latitude, latHash, MINLAT, MAXLAT);
	mergeGeoHash();
	return binHash;
}

/* ��ȡ���Ȼ�γ�ȵ�GeoHashֵ */
void GeoHash::getGeoHash(double location, string &locationHash, double left, double right)
{
	double mid;
	for (int i = 0; i < 20; ++i)
	{
		mid = (left + right) / 2;
		if (location < mid)
		{
			locationHash += '0';
			right = mid;
		}
		else
		{
			locationHash += '1';
			left = mid;
		}

	}
}

/* �����Ⱥ�γ�ȵ�GeoHashֵ����ϲ� �Ⱦ�����γ�� */
void GeoHash::mergeGeoHash()
{
	for (int i = 0; i < 20; ++i)
		binHash = binHash + lngHash[i] + latHash[i];
}

#endif // !GeoHash_H
