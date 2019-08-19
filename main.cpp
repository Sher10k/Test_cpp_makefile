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

	int currVal = 0, val = 0;
	if ( cin >> currVal )
	{
		int cnt = 1;
		while ( cin >> val )
		{
			if ( val == currVal ) ++cnt;
			else 
			{
				cout << currVal << " occurs "
				     << cnt << " times" << endl;
				currVal = val;
				cnt = 1;
			}
		}
		cout << currVal << " occers "
		     << cnt << " times" << endl;
	}





	return 0;
}
