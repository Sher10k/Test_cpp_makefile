#include <iostream>
#include <Eigen/Eigen>
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include "Header/myclass.h"

using namespace std;
using namespace Eigen;
using namespace cv;

int main()
{
	cout << "Hello world!" << endl
	     << "123" << endl;
	Matrix4d M;
	M << 1, 0, 0, 0,
	     0, 1, 0, 0,
	     0, 0, 1, 0,
	     0, 0, 0, 1;
	cout << "M = " << endl << M << endl;

	int i = 42;
	cout << "i = " << i << endl;
	int *p = &i;
	int &r = i;
	cout << "*p = i = " << *p << endl;
	cout << "p = &i = " << p << endl;
	cout << "&i = " << &i << endl;
	cout << "r = i = " << r << endl;
	cout << "&r = p = &i = " << &r << endl;
	*p = *p * *p;
	cout << "*p * *p = " << *p << endl;



	return 0;
}
