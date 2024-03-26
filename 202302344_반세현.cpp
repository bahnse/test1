이 코드는 수정이 필요해요
코드를 수정했어요
#include <iostream>
#include <string>
using namespace std;
이 부분이 이상해여
// 202301604 박승준 pull requests
class Vehicle {
protected:
	string Serial_number;
	string engine_type;

public:
	Vehicle(string serial, string engine) : Serial_number(serial), engine_type(engine) {}

	virtual void display_info() const {}
	virtual ~Vehicle() {}
};

class Gasoline : virtual public Vehicle {
protected:
	int oil_gauge;

public:
	Gasoline(string serial, string engine, int oil) : Vehicle(serial, engine), oil_gauge(oil) {} 
  main
	void display_info() override {
=======
	void display_info() const override {
  main
		cout << "차량 타입: Gasoline" << endl;
		cout << "시리얼 번호: " << Serial_number << endl;
		cout << "엔진 타입: " << engine_type << endl;
		cout << "기름 게이지: " << oil_gauge << endl;
	}

};

class Electric : virtual public Vehicle {
protected:
	int charged_gauge;

public:
	Electric(string serial, string engine, int charge) : Vehicle(serial, engine), charged_gauge(charge) {}

 main
	void display_info() override {
=======
	void display_info() const override {
 main
		cout << "차량 타입: Electric" << endl;
		cout << "시리얼 번호: " << Serial_number << endl;
		cout << "엔진 타입: " << engine_type << endl;
		cout << "충전 게이지: " << charged_gauge << endl;
	}

};

class Hybrid : public Gasoline, public Electric {
public:
    Hybrid(string serial, string engine, int oil, int charge)
        : Gasoline(serial, engine, oil), Electric(serial, engine, charge), Vehicle(serial, engine) {}

 main
    void display_info() override {
=======
    void display_info() const override {
 main
        cout << "차량 타입: Hybrid" << endl;
        cout << "시리얼 번호: " << Serial_number << endl;
        cout << "엔진 타입: " << engine_type << endl;
        cout << "기름 게이지: " << Gasoline::oil_gauge << endl;
        cout << "충전 게이지: " << Electric::charged_gauge << endl;
    }
};

int main() {
	Vehicle* v1 = new Gasoline("G123", "가솔린 엔진", 50);
	Vehicle* v2 = new Electric("E456", "전기 모터", 80);
	Vehicle* v3 = new Hybrid("H789", "하이브리드", 50, 80);

	v1->display_info();
	v2->display_info();
	v3->display_info();

	Hybrid* newHybrid1 = dynamic_cast<Hybrid*>(v1);
	if (newHybrid1) {
		cout << "하향 형변환 성공" << endl;
		newHybrid1->display_info();
	}
	else {
		cout << "하향 형변환 실패" << endl;
	}

	Hybrid* newHybrid = dynamic_cast<Hybrid*>(v3);
	if (newHybrid) {
		cout << "하향 형변환 성공" << endl;
		newHybrid->display_info();
	}
	else {
		cout << "하향 형변환 실패" << endl;
	}

	delete v1;
	delete v2;
	delete v3;

	return 0;

}
