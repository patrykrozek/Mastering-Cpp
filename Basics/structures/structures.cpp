#include<iostream>
using namespace std;


struct point {
	double x, y;
	void insert();
	void print();
	void move(double, double);
};



int main(){
	point A;
	A.insert();
	//cout << w << '\t' << &A << endl;
	//cout << '(' << A.x << ',' << w->y << ')' << endl;
	A.print();
	A.move(1, 1);
	A.print();
}

void point::insert() {
	//cout << "Obiekt insert ma adres: " << this << endl;
	cout << "Enter x and y: "<<endl;
	cin >> x >> y;
}

void point::print() {
	cout << '(' << x << ',' << y << ')' << endl;
}

void point::move(double x1,double y1) {
	x += x1;
	y += y1;
}