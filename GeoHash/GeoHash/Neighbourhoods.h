/********************
Function:	8邻域的GeoHash值
			包括上、下、左、右、左上、左下、右上、右下
Inputs:		中心种子的信息及取其geohash值的前nums位构建邻接区域
Return:		8个邻接区域的GeoHash值
*********************/

#ifndef Neighbourhoods_H
#define Neighbourhoods_H

#include<iostream>
#include<vector>
#include"LocationBean.h"
using namespace std;

class Neighbourhoods
{
public:
	Neighbourhoods(LocationBean bean, int nums);
public:
	vector<vector<LocationBean> > beanThreeByThree;			/* 将下面三行数据存入3*3数组，便于调用 */
private:
	LocationBean upperLeftBean, upperBean, upperRightBean;	/* 左上、上、右上*/
	LocationBean leftBean, centerBean, rightBean;			/*  左 、中、 右 */
	LocationBean lowerLeftBean, lowerBean, lowerRightBean;	/* 左下、下、右下*/
};

Neighbourhoods::Neighbourhoods(LocationBean bean, int nums)
{
	/* 1个Base32码是5位二进制，nums个Base32码是nums*5个二进制码，经度纬度各占一半 */
	double numsDec = pow(2, nums * 5 / 2);	/* 转化为二进制码后经度、纬度划分的数量 */
	double lngOffset = 360 / numsDec;		/* 经度偏移量 */
	double latOffset = 180 / numsDec;		/* 纬度偏移量 */

	/* 下面没有判断加入偏移量后是否超出约束，如大于180度等 */
	centerBean = bean;
	
	upperLeftBean = LocationBean(bean.longitude - lngOffset, bean.latitude + latOffset);
	upperBean = LocationBean(bean.longitude, bean.latitude + latOffset);
	upperRightBean = LocationBean(bean.longitude + lngOffset, bean.latitude + latOffset);

	leftBean = LocationBean(bean.longitude - lngOffset, bean.latitude);
	rightBean = LocationBean(bean.longitude + lngOffset, bean.latitude);

	lowerLeftBean = LocationBean(bean.longitude - lngOffset, bean.latitude - latOffset);
	lowerBean = LocationBean(bean.longitude, bean.latitude - latOffset);
	lowerRightBean = LocationBean(bean.longitude + lngOffset, bean.latitude - latOffset);

	beanThreeByThree.resize(3);
	beanThreeByThree[0].push_back(upperLeftBean);
	beanThreeByThree[0].push_back(upperBean);
	beanThreeByThree[0].push_back(upperRightBean);
	beanThreeByThree[1].push_back(leftBean);
	beanThreeByThree[1].push_back(centerBean);
	beanThreeByThree[1].push_back(rightBean);
	beanThreeByThree[2].push_back(lowerLeftBean);
	beanThreeByThree[2].push_back(lowerBean);
	beanThreeByThree[2].push_back(lowerRightBean);
}

#endif // !Neighbourhoods_H
