// Math.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "Vector3.h"
#include <iostream>
using namespace math;
using namespace std;
int main()
{
	//Vector3 v = Vector3::Cross(Vector3::right, Vector3::up);
	auto v = Vector3::slerp(Vector3::up, Vector3::right, 0.1f);
	cout << v.x << "," << v.y << "," << v.z << endl;
    return 0;
}

