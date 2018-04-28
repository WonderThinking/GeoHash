/********************
Function:	GeoHash算法，将经纬度坐标转化为GeoHash值
Inputs:		经纬度
Return:		GeoHash值----40位的0/1字符串
*********************/
#ifndef GeoHash_H
#define GeoHash_H

#include<iostream>
using namespace std;

class GeoHash
{
private:
	double MINLNG = -180;	/* 最小经度 */
	double MAXLNG = 180;	/* 最大经度 longitude */
	double MINLAT = -90;	/* 最小纬度 */
	double MAXLAT = 90;		/* 最大纬度 latitude */

	string lngHash;			/* 经度的GeoHash值 */
	string latHash;			/* 纬度的GeoHash值 */
	string binHash;			/* 二进制形式的GeoHash值(合并lngHash、latHash) */
public:
	GeoHash();
	string getGeoHash(double longitude, double latitude);
private:
	void getGeoHash(double location, string &locationHash, double left, double right);	/* 获取经度或纬度的GeoHash值*/
	void mergeGeoHash();	/* 将经度和纬度的GeoHash值合并,先经度再纬度交错合并 */
};

/* 构造函数 */
GeoHash::GeoHash()
{
	lngHash = "";
	latHash = "";
	binHash = "";
}

/* 由经纬度获取GeoHash值 */
string GeoHash::getGeoHash(double longitude, double latitude)
{
	getGeoHash(longitude, lngHash, MINLNG, MAXLNG);
	getGeoHash(latitude, latHash, MINLAT, MAXLAT);
	mergeGeoHash();
	return binHash;
}

/* 获取经度或纬度的GeoHash值 */
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

/* 将经度和纬度的GeoHash值交错合并 先经度再纬度 */
void GeoHash::mergeGeoHash()
{
	for (int i = 0; i < 20; ++i)
		binHash = binHash + lngHash[i] + latHash[i];
}

#endif // !GeoHash_H
