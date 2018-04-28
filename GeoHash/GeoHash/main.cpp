
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include"LocationBean.h"
#include"Neighbourhoods.h"
using namespace std;

void main()
{
	//LocationBean bean = LocationBean("myname", "myaddress", 121.443469, 31.22246);
	
	/* �ҵ�λ�� */
	LocationBean bean = LocationBean("myname", "myaddress", 121.5315824747, 38.8801635622);
	cout << "name:\t\t" << bean.name << endl;
	cout << "address:\t" << bean.address << endl;
	cout << "longitude:\t" << bean.longitude << endl;
	cout << "latitude:\t" << bean.latitude << endl;
	cout << "GeoHash:\t" << bean.geohash << endl;
	Neighbourhoods eightNei(bean, 6);
	cout << "8����" << endl;
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
			cout << eightNei.beanThreeByThree[i][j].geohash << ' ';
		cout << endl;
	}

	/* ��ȡ�ļ�(POI: Point Of Interest��Ȥ��)  */
	ifstream infile;
	infile.open("DB.txt");
	int sizeOfDB = 1988;
	vector<vector<string> > DataBase(sizeOfDB, vector<string>(4));	/* ��������ַ����γ�ȡ�geohashֵ */
	string s;
	int i = 0;
	for (int i = 0; i < sizeOfDB; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			getline(infile, s);
			DataBase[i][j] = s;
		}
		getline(infile, s);
		getline(infile, s);
	}
	infile.close();

	/* ��ȡҪƥ���GeoHashǰ׺������ȡǰ6λ */
	vector<vector<string> > subStr(3, vector<string>(3));
	cout << "����ƥ���ǰ׺��" << endl;
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			subStr[i][j] = eightNei.beanThreeByThree[i][j].geohash.substr(0, 6);
			cout << subStr[i][j] << ' ';
		}
	}
	cout << endl;

	/* �����ݿ���9�������������ǰ׺ƥ�䣬����ȡǰ6λ */
	string dbSubStr;
	bool flag;
	int hitNums = 0;
	for (int i = 0; i < sizeOfDB; ++i)
	{
		dbSubStr = DataBase[i][3].substr(0, 6);
		flag = false;
		for (int m = 0; m < 3; ++m)
		{
			for (int n = 0; n < 3; ++n)
			{
				if (dbSubStr == subStr[m][n])
				{
					for (int j = 0; j < 4; ++j)
						cout << DataBase[i][j] << ' ';
					cout << endl;
					++hitNums;
					flag = true;
					break;
				}
			}
			if (flag == true)
				break;
		}
	}
	cout << "\n��Χ�Ĳ���������" << hitNums << endl;
	system("pause");
	return;
}
