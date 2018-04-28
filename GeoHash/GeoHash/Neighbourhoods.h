/********************
Function:	8�����GeoHashֵ
			�����ϡ��¡����ҡ����ϡ����¡����ϡ�����
Inputs:		�������ӵ���Ϣ��ȡ��geohashֵ��ǰnumsλ�����ڽ�����
Return:		8���ڽ������GeoHashֵ
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
	vector<vector<LocationBean> > beanThreeByThree;			/* �������������ݴ���3*3���飬���ڵ��� */
private:
	LocationBean upperLeftBean, upperBean, upperRightBean;	/* ���ϡ��ϡ�����*/
	LocationBean leftBean, centerBean, rightBean;			/*  �� ���С� �� */
	LocationBean lowerLeftBean, lowerBean, lowerRightBean;	/* ���¡��¡�����*/
};

Neighbourhoods::Neighbourhoods(LocationBean bean, int nums)
{
	/* 1��Base32����5λ�����ƣ�nums��Base32����nums*5���������룬����γ�ȸ�ռһ�� */
	double numsDec = pow(2, nums * 5 / 2);	/* ת��Ϊ��������󾭶ȡ�γ�Ȼ��ֵ����� */
	double lngOffset = 360 / numsDec;		/* ����ƫ���� */
	double latOffset = 180 / numsDec;		/* γ��ƫ���� */

	/* ����û���жϼ���ƫ�������Ƿ񳬳�Լ���������180�ȵ� */
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
