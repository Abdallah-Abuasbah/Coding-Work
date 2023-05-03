#include <iostream>
#include <math.h>
using namespace std;
class Polymorphism
{
public:
	/* ls represent lengthSide...*/
	double ls;
	virtual double getArea() = 0;
	virtual double getSurfaceArea() = 0;
	virtual double getVolume() = 0;
	virtual string isA() = 0;
	virtual void read() = 0;
	virtual void print() = 0;
};

class cube : public Polymorphism
{
public:
	/* The cube need side lengt so...*/
	double getArea()
	{
		/*the area formula = side ^ 2...*/
		return ls * ls;
	}
	double getSurfaceArea()
	{
		/* the surface area formula = 6 * side ^ 2...*/
		return 6 * ls * ls;
	}
	double getVolume()
	{
		/*the cube volume formula = side ^ 3...*/
		return ls * ls * ls;
	}
	string isA() /* function that return the object type() */
	{
		return "cube";
	}
	void print()
	{
		cout << "the side = " << ls << endl;
		cout << "  and the volume = " << getVolume();
		cout << "  and surface area = " << getSurfaceArea();
	}
	void read()
	{
		cout << "enter side length  for the cube: ";
		cin >> ls;
	}

}; /*cube is done...*/

class cone : public Polymorphism
{
private:
	/* The cone needs radius and height so...*/
	/* r represent radius and h represent height */
	double r;
	double h;

public:
	double getArea()
	{
		/*While the shape is a cone, the base will be a circle so area base = 3.14 * r^2 */
		return 3.14 * pow(r, 2);
	}
	double getSurfaceArea()
	{
		/*surface area = 3.14*r(r+sqrt(h^2+r^2))*/
		return 3.14 * r * (r * sqrt(pow(r, 2) + pow(h, 2)));
	}
	double getVolume()
	{
		/*volume of cone = 3.14*r^2 * h/3*/
		return (3.14 * r* r* h / 3.0);
	}
	string isA()
	{
		return "cone";
	}
	void read()
	{
		cout << "enter cone height: ";      cin >> h;
		cout << "enter cone radious: ";     cin >> r;
	}
	void print()
	{
		cout << "radious: " << r << endl;
		cout << "height = " << h << endl;
		cout << "volume = " << getVolume();
		cout << "  and surface area = " << getSurfaceArea();
	}

}; /*cone is done...*/

class pyramid : public Polymorphism
{
	/* The pyramid needs width, height and length so...*/
	/* l represent length, h represent height and w represent width*/
	double l;
	double h;
	double w;
public:
	double getArea()
	{
		/*area bace will be length * width...*/
		return l * w;
	}
	double getSurfaceArea()
	{
		double surfacearea = l * w + l * sqrt(pow(w / 2, 2) + pow(h, 2)) + w * sqrt(pow(l / 2, 2) + pow(h, 2));
		return surfacearea;
	}
	double getVolume()
	{
		/*the volume of pyramid = l*w*h/3 */
		return (l * w * h) / 3.0;
	}
	string isA()
	{
		return "pyramid";
	}
	void read()
	{
		cout << "enter pyramid length : ";
		cin >> l;
		cout << "enter pyramid width: ";
		cin >> w;
		cout << "enter pyramid height: ";
		cin >> h;
	}
	void print()
	{
		cout << "length = " << l << endl;
		cout << "Width = " << w << endl;
		cout << "height = " << h << endl;
		cout << "volume = " << getVolume() << "  surface area = " << getSurfaceArea();
	}

}; /*pyramid is done...*/

class cuboid : public Polymorphism
{
	/* The cuboid needs width, height and length so...*/
	/* l represent length, h represent height and w represent width*/

	double l;
	double h;
	double w;

public:
	double getArea()
	{
		/*area bace will be length * width...*/
		return l * w;
	}
	double getSurfaceArea()
	{
		return 2 * (w * l + h * l + h * w);
	}
	double getVolume()
	{
		/* the volume of cuboid = length*width*height...*/
		return (l * w * h);
	}
	string isA()
	{
		return "cuboid";
	}
	void read()
	{
		cout << "enter cuboid length : ";
		cin >> l;
		cout << "enter cuboid width: ";
		cin >> w;
		cout << "enter cuboid height: ";
		cin >> h;
	}
	void print()
	{
		cout << "length = " << l << endl;
		cout << "Width = " << w << endl;
		cout << "height = " << h << endl;
		cout << "volume = " << getVolume() << "  surface area = " << getSurfaceArea();
	}

}; /*cuboid is done...*/

class tetrahedron : public Polymorphism
{

public:
	double getArea()
	{
		/* base area formula = sqrt(3) * side^2 / 4 */
		return sqrt(3) * ls * ls / 4.0;
	}
	double getSurfaceArea()
	{
		/* surface area formula = sqrt(3) side^2 */
		return sqrt(3) * ls * ls;
	}
	double getVolume()
	{
		/*volume of tetrahedron formula = side^3 / (6 * sqrt(2)) */
		return (ls * ls * ls) / (6.0 * sqrt(2));
	}
	string isA()
	{
		return "tetrahedron";
	}
	void read()
	{
		cout << "enter length side tetrahedron: ";
		cin >> ls;
	}
	void print()
	{
		cout << "side = " << ls << endl;
		cout << "volume = " << getVolume();
	}

}; /*tetrahedron is done...*/

class Sphere : public Polymorphism
{

public:
	double getArea()
	{
		/*the sphere area is 0*/
		return 0;
	}
	double getSurfaceArea()
	{
		/*surface area formula = 4 * 3.14 * side^2 */
		return (4.0) * 3.14 * (ls * ls);
	}
	double getVolume()
	{
		/*volume of Sphere formula = (4/3) * 3.14 (ls * ls * ls) */
		return (4.0 / 3.0) * 3.14 * (ls * ls * ls);
	}
	string isA()
	{
		return "sphere";
	}
	void read()
	{
		cout << "enter radius side of the sphere: ";
		cin >> ls;
	}
	void print()
	{
		cout << "radius = " << ls << endl;
		cout << "volume = " << getVolume();
		cout << "  and surface area = " << getSurfaceArea();
	}

}; /*sphere is dlne...*/

class cylinder : public Polymorphism
{
	/* The cylinder needs radius and height*/
	/*h represent height and r represent radius*/
	double r;
	double h;

public:
	double getArea()
	{
		/*the base will bee circle so the area =3.14 * r ^ 2 */
		return 3.14 * r * r;
	}
	double getSurfaceArea()
	{
		/*the Surface Area formula = 2 * 3.14 * r (h + r) */
		return 2 * 3.14 * r * (h + r);
	}
	double getVolume()
	{
		/*the volume of cylinder formula = 3.14 * r^2 * h...*/
		return 3.14 * pow(r, 2) * h;
	}
	string isA()
	{
		return "cylinder";
	}
	void read()
	{
		cout << "enter radius of cylinder: ";
		cin >> r;
		cout << "enter height of cylinder: ";
		cin >> h;
	}
	void print()
	{
		cout << "radius = " << r << endl;
		cout << "height = " << h << endl;
		cout << "volume = " << getVolume();
		cout << "  and surface area = " << getSurfaceArea();
	}

}; /*cylinder is done...*/

int insertshape()
{
	int n = 0;
	do
	{
		cout << "enter 1 for cube\n";
		cout << "enter 2 for cone\n";
		cout << "enter 3 for pyramid\n";
		cout << "enter 4 for cuboid\n";
		cout << "enter 5 for tetrahedron\n";
		cout << "enter 6 for Sphere\n";
		cout << "enter 7 for cylinder\n";
		cout << "enter 0 to exit\n";
		cout << "\n enter your number: ";
		cin >> n;

		if (n < 0 || n > 7)
		{
			cout << "Wrong choice.\n";
		}
	} while (n < 0 || n > 7);

	return n;
}
int main()
{
	int cap = 0;
	Polymorphism* arr[10];

	for (int i = 0; i < 10; i++)
	{
		cout << "\n enter The details of The shape: " << (i + 1) << "\n";
		int n = insertshape();

		switch (n)
		{
		case 0:
			return 0;
		case 1:
			arr[i] = new cube();
			break;

		case 2:
			arr[i] = new cone();
			break;

		case 3:
			arr[i] = new pyramid();
			break;

		case 4:
			arr[i] = new cuboid();
			break;

		case 5:
			arr[i] = new tetrahedron();
			break;

		case 6:
			arr[i] = new Sphere();
			break;

		case 7:
			arr[i] = new cylinder();
			break;
		default:
			cout << "Wrong choice.\n";
			break;
		}

		arr[i]->read();
		cap++;
	}

	for (int i = 0; i < 10; i++)
	{
		for (int j = i + 1; j < 10; j++)
		{
			if (arr[i]->getVolume() > arr[j]->getVolume())
			{
				Polymorphism* temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}

	for (int i = 0; i < 10; i++)
	{
		cout << "Shape " << (i + 1) << ":\n";
		arr[i]->print();
		cout << endl;
	}
	cout << endl;

	double max = arr[0]->getVolume();
	double min = arr[0]->getVolume();
	for (int i = 1; i < 10; i++)
	{
		if (max < arr[i]->getVolume())
			max = arr[i]->getVolume();
		if (min > arr[i]->getVolume())
			min = arr[i]->getVolume();
	}
	cout << endl << endl;
	cout << "maximum volume = " << max << endl;
	cout << "minimum volume = " << min << endl << endl;

	//delete
	if (cap == 0)
		cout << "array is empty..." << endl;
	else
	{

		cap--;
		delete arr[cap];

	}
	for (int i = 0; i <cap; i++)
	{
		cout << "arr " << (i + 1) << ":\n";
		arr[i]->print();
		cout << endl;
	}
	cout << endl;
	 // add

	if (cap == 8)
		cout << "array is full..." << endl;
	else
	{
		int n = insertshape();

		switch (n)
		{
		case 0:
			return 0;
		case 1:
			arr[cap+1] = new cube();
			break;

		case 2:
			arr[cap + 1] = new cone();
			break;

		case 3:
			arr[cap + 1] = new pyramid();
			break;

		case 4:
			arr[cap + 1] = new cuboid();
			break;

		case 5:
			arr[cap + 1] = new tetrahedron();
			break;

		case 6:
			arr[cap + 1] = new Sphere();
			break;

		case 7:
			arr[cap + 1] = new cylinder();
			break;
		default:
			cout << "Wrong number.\n";
			break;
		}
		arr[cap + 1]->read();
		cap++;
	}

	for (int i = 0; i < cap; i++)
	{
		cout << "arr " << (i + 1) << ":\n";
		arr[i]->print();
		cout << endl;
	}
	cout << endl;



	return 0;
}