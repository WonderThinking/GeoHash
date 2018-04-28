/********************
Function:	定义种子位置信息
Inputs:		默认构造函数没有数据传入，只用于定义此类型种子，之后还需调用带参数的构造函数计算geohash值
			只有经纬度的构造函数，用于计算8邻域
			全参数的构造函数，用于存已知信息的位置,输入地理信息包括:名字、地址、经度、纬度
Return:		Base32码
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
	string name;		/* 名字 */
	string address;		/* 地址 */
	double longitude;	/* 经度 */
	double latitude;	/* 纬度 */
	string geohash;		/* 编码后的GeoHash码 8位字符*/
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
	
	/* 先把经纬度转为01序列的GeoHash码，再转为Base32码 */
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
