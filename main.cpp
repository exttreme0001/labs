#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;
int main() {
	int n(0), maxel(0), koord1(0), koord2(0);
	cout << "vvedite n ne bolee 10";
	cin >> n;
	if (n > 10)
	{
		cout << "vvedite needable n";
	}
	else {

		vector <vector <int>> v3(n);
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				if (i == j) { v3[i].push_back(1); }
				else
					v3[i].push_back(rand() % 1000);
			}
		}// for1 end
		for (int i = 0; i < n; ++i) {
			cout << endl;
			for (int j = 0; j < n; ++j) {
				cout << v3[i][j] << '\t';
			}

		}


		for (int i = 0; i < n; i++)
		{
			int ibordup(-1), iborddown(1);
			if (i == 0) { ibordup = 0; }
			if (i == n - 1) { iborddown = 0; }
			for (int j = 0; j < n; j++)
			{
				bool isLocalMaxima = true;
				int counter = 0;
				int jbordleft(-1), jbordright(1);

				if (j == 0) { jbordleft = 0; }
				if (j == n - 1) { jbordright = 0; }

				//  check neighbors
				for (ibordup; ibordup <= iborddown; ibordup++)
				{
					for (jbordleft; jbordleft <= jbordright; jbordleft++)
					{
						if (v3[i + ibordup][j + jbordleft] > v3[i][j])
						{
							// this is not loc max
							isLocalMaxima = false;
							counter++;
							break;
						}


					}
					if (!isLocalMaxima)
						break;
				}

				// if it is loc max
				if (isLocalMaxima && counter == 0 && maxel < v3[i][j])
				{
					maxel = v3[i][j];
					koord1 = i;
					koord2 = j;
					// std::cout << endl << "Local maximum found at position (" << i << ", " << j << "): " << v3[i][j] ; //cout all local max.
				}

			}
		}

		std::cout << endl << "Local maximum is (" << koord1 << ", " << koord2 << "): " << maxel;



		// point 1
		long long proizv(1);
		for (int p = 0; p < n; p++)
		{
			for (int l = 0; l < n ; l++)
			{
				if (p == l) { continue; }
				else
					if (p != l && l < p) {
						proizv = proizv * v3[p][n-1-l];
					}
			}
		}
		std::cout << endl << proizv;
		//point 2
	}
}
