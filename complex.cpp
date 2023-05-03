#include <iostream>
using namespace std;
template< class Q>
class consnum
{
private:
	Q num1, num2;
public:
	consnum() {
		num1 = 0;
		num2 = 0;
	}
	consnum(const consnum& obj)
	{
		num1 = obj.num1;
		num2 = obj.num2;
	}
	void setnum1(Q n) {
		num1 = n;
	}
	void setnum2(Q n) {
		num2 = n;
	}
	Q getnum1() {
		return num1;
	}
	Q getnum2() {
		return num2;
	}
	char* ISA() {
		return "comblex";
	}
	friend ostream& operator << (ostream& out, consnum& R)
	{

		out << R.getnum1() << "+" << R.getnum2() << "i" << endl;

		return out;
	}

	friend istream& operator >> (istream& in, consnum& R)
	{
		double real, imag;

		cout << "Enter the Real  part of Number: ";
		cin >> real;
		R.setnum1(real);
		cout << "Enter the imaginary  part of Number: ";
		cin >> imag;
		R.setnum2(imag);

		return in;
	}

	consnum& operator = (  consnum& R)
	{
		if (this != &R)
		{
			setnum2(R.getnum2());
			setnum1(R.getnum1());
		}

		return *this;

	}

	consnum operator +(consnum& R)
	{
		consnum T;

		T.setnum2(this->getnum2() + R.getnum2());
		T.setnum1(this->getnum1() + R.getnum1());
		return T;
	}

	consnum operator +=(consnum R)
	{
		*this = *this + R;

		return *this;
	}

	consnum operator -(consnum& R)
	{
		consnum T;

		T.setnum2(this->getnum2() - R.getnum2());
		T.setnum1(this->getnum1() - R.getnum1());
		return T;
	}

	consnum operator -=(consnum R)
	{
		*this = *this - R;
		return *this;
	}

	bool operator == (consnum& R)
	{
		if (this->getnum1() == R.getnum1() && this->getnum2() == R.getnum2())
			return  true;
		else
			return false;
	}

	bool operator != (consnum& R)
	{
		return !(*this == R);
	}

	consnum operator *(consnum& R)
	{
		consnum T;

		T.setnum1(this->getnum1() * R.getnum1());
		T.setnum2((this->getnum1() * R.getnum2()) + (this->getnum2() * R.getnum1()) + (this->getnum2() * R.getnum2()));

		return T;
	}

	consnum operator *=(consnum R)
	{
		*this = *this * R;

		return *this;
	}

	consnum operator /(consnum& R)
	{
		consnum R;

		R.setnum1((this->getnum1() * R.getnum1() + this->getnum2() * R.getnum2()) / (R.getnum1() * R.getnum1() + R.getnum2() * R.getnum2()));
		R.setnum2((this->getnum2() * R.getnum1() + this->getnum1() * R.getnum2()) / (R.getnum1() * R.getnum1() + R.getnum2() * R.getnum2()));
		return R;
	}

	consnum operator /=(consnum R)
	{
		*this = *this / R;

		return *this;
	}

	bool operator > (consnum& R)
	{
		if (this->getnum1() > R.getnum1())
			return true;
		else if (this->getnum1() == R.getnum1())
		{
			if (this->getnum2() > R.getnum2())
				return true;
			else
				return false;
		}
		else
			return false;
	}

	bool operator >= (consnum& R)
	{
		if (this->getnum1() >= R.getnum1())
		{
			if (this->getnum2() >= R.getnum2())
				return true;
			else
				return false;
		}
		else
			return false;
	}

	bool operator < (consnum& R)
	{
		if (this->getnum1() < R.getnum1())
			return true;
		else if (this->getnum1() == R.getnum1())
		{
			if (this->getnum2() < R.getnum2())
				return true;
			else
				return false;
		}
		else
			return false;
	}

	bool operator <= (consnum& R)
	{
		if (this->getnum1() <= R.getnum1())
		{
			if (this->getnum2() <= R.getnum2())
				return true;
			else
				return false;
		}
		else
			return false;
	}

	~consnum() {}


};
int main(void) {
	consnum<double> A[8];
	consnum<double>* B = A;
	double n1, n2;
	//ensert complex number 
	for (int i = 0; i < 8; i++) {
		cout << i + 1 << "- enter the number:";
		cin >> n1;
		cout << "enter the number:";
		cin >> n2;
		B[i].setnum1(n1);
		B[i].setnum2(n2);
	}
	// sort arry
	for (int i = 0; i < 8; i++)
		for (int j = i + 1; j < 8; j++)
			if (A[i] > A[j])
			{
				consnum<double> temp;
				temp = B[j];
				B[j] = B[i];
				B[i] = temp;
			}
	cout << "======================================================================\n";
	for (int i = 0; i < 8; i++) {
		cout << i + 1 << ")";
		cout << B[i].getnum1() << "+" << B[i].getnum2() << "i" << '\n';
	}
	//search
	cout << "================================================================================\n";
	consnum<double> S;
	cout << "enter coplex number:\n";
	cin >> n1 >> n2;
	S.setnum1(n1);
	S.setnum2(n2);
	int i = 0;
	for (; i < 8; i++) {
		if (B[i].getnum1() == S.getnum1() && B[i].getnum2() == S.getnum2()) {
			cout << "The complex number exist\n";
			break;
		}
	}
	if (i == 8)
		cout << "The complex number does not exist\n";
		return 0;
}