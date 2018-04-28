/********************
Function:	��������λ����Ϣ
Inputs:		Ĭ�Ϲ��캯��û�����ݴ��룬ֻ���ڶ�����������ӣ�֮������ô������Ĺ��캯������geohashֵ
			ֻ�о�γ�ȵĹ��캯�������ڼ���8����
			ȫ�����Ĺ��캯�������ڴ���֪��Ϣ��λ��,���������Ϣ����:���֡���ַ�����ȡ�γ��
Return:		Base32��
*********************/

#ifndef LocationBean_H
#define LocationBean_H

#include<iostream>
#include"GeoHash.h"
#include"Base32.h"
using namespace std;

class LocationBean
{
public:
	string name;		/* ���� */
	string address;		/* ��ַ */
	double longitude;	/* ���� */
	double latitude;	/* γ�� */
	string geohash;		/* ������GeoHash�� 8λ�ַ�*/
public:
	LocationBean();
	LocationBean(double locationLng, double locationLat);
	LocationBean(string locationName, string locationAddr, double locationLng, double locationLat);
};

LocationBean::LocationBean()
{
	name = "";
	address = "";
	longitude = 0;
	latitude = 0;
	geohash = "";
}

LocationBean::LocationBean(double locationLng, double locationLat)
{
	name = "";
	address = "";
	longitude = locationLng;
	latitude = locationLat;
	
	/* �ȰѾ�γ��תΪ01���е�GeoHash�룬��תΪBase32�� */
	string binStr = GeoHash().getGeoHash(longitude, latitude);
	geohash = Base32().Base32Encode(binStr);
	// cout << longitude << ' ' << latitude << ' ' << geohash << endl;
}

LocationBean::LocationBean(string locationName, string locationAddr, double locationLng, double locationLat)
{
	name = locationName;
	address = locationAddr;
	longitude = locationLng;
	latitude = locationLat;

	string binStr = GeoHash().getGeoHash(longitude, latitude);
	geohash = Base32().Base32Encode(binStr);
}

#endif // !LocationBean_H
