#include <iostream>
#include <random>
using namespace std;


struct point {
	double x, y;
	void draw(int, int);
	void print();
	double dist_from_zero();
	int quarter();
	void mirror_zero();
};


int main() {
	point A;
	int n,pos=0;
	double max = 0;

	cout << "Enter the n-length of the array: ";
	cin >> n;
	point* t = new point[n];

	for (int i = 0; i < n; ++i) {
		t[i].draw(-10, 10);
		t[i].print();
		cout << endl;
		
	}
	max = t[0].dist_from_zero();
	for (int i = 1; i < n; ++i) {
		if (t[i].dist_from_zero()>max) {
			max = t[i].dist_from_zero();
			pos = i;
		}
	}
	cout <<endl<< "The farthest point is: ";
	t[pos].print();
	cout << " , it's distance is: " << max << endl;;
	cout << "Quarter: " << t[pos].quarter() << endl;
	cout << "Mirror point: ";
	t[pos].mirror_zero();
	cout << endl;

}

void point::draw(int tl,int dl) {
	random_device R;
	x = (tl - dl) * (1.0 * R() / R.max()) + dl; //Tu trzeba uwa¿aæ, aby nie wyjœc poza zakres - dlatego tak mno¿ymy to 1.0
	y = (tl - dl) * (1.0 * R() / R.max()) + dl; //Tu trzeba uwa¿aæ, aby nie wyjœc poza zakres - dlatego tak mno¿ymy to 1.0
}

void point::print() {
	cout << '(' << x << ',' << y << ')';
}

double point::dist_from_zero() {
	//cout << "Distance from zero point: " << sqrt(pow(x, 2) + pow(y, 2)) << endl;
	return sqrt(pow(x, 2) + pow(y, 2));
}
int point::quarter() {
	if (x > 0 && y > 0) {
		return 1;
	}
	else if (x < 0 && y>0) {
		return 2;
	}
	else if (x < 0 && y < 0) {
		return 3;
	}
	else if (x > 0 && y < 0) {
		return 4;
	}
	else {
		return 0;
	}
}

void point::mirror_zero() {
	double mx = -x;
	double my = -y;
	cout << "Mirrored point is: (" << mx << ',' << my << ')';
	
}