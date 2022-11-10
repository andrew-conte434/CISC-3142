#include <iostream>
using namespace std;

class Rectangle {
	public:
		double length;
		double width;
		Rectangle(double x, double y){
			length = x;
			width = y;
		}
		void setLength(double x){length = x;}
		void setWidth(double x){width = x;}

		double getPerimeter(){return 2 * length + 2 * width;}
		double getArea(){return length * width;}
		void show(){
			cout<<"Length: " << length << endl;
			cout<<"Width: " << width << endl;
		}
		bool sameArea(Rectangle r2){
			if(this->getArea() == (r2.length * r2.width)){
				return true;
			} else {
				return false;
			}
		}
		
};

void printRectangle(Rectangle r){
	r.show();
	cout << "Perimeter: " << r.getPerimeter() << endl;
	cout << "Area: " << r.getArea() << endl;
}

void compareArea(Rectangle r1, Rectangle r2){
	if(r1.sameArea(r2) == true){
		cout << "The rectangles have the same area" << endl;
	} else {
		cout << "The rectangles do not have the same area" << endl;
	}
}

int main(){
	Rectangle r1 = Rectangle(5, 2.5);
	Rectangle r2 = Rectangle(5, 18.9);
	printRectangle(r1);
	cout << endl;
	printRectangle(r2);
	
	compareArea(r1, r2);
	cout << endl;

	r1.setLength(15);
	r1.setWidth(6.3);

	printRectangle(r1);
	cout<<endl;
	printRectangle(r2);

	compareArea(r1, r2);

	
	return 0;
}
