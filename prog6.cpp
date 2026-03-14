#include <iostream>
using namespace std;

// base car class
class Car {
protected:
	bool state_on; // on/off state
	int VIN; // vehicle id

public:
	Car() {}; // default constructor

	// set vin and default state
	Car(int in_VIN) {
		VIN = in_VIN;
		state_on = false;
	}

	virtual void turnOn(void) {};
	virtual void turnOff(void) {};
	virtual void printDetails(void) {};
};

// internal combustion car
class InternalCombustionCar : public Car {
private:
	int cylinderCount; // engine cylinders

public:
	InternalCombustionCar(int in_VIN, int in_cylinderCount) : Car(in_VIN) {
		cylinderCount = in_cylinderCount;
	}

	void turnOn(void) {
		state_on = true;
		cout << "IC Car on!" << endl;
	}

	void turnOff(void) {
		state_on = false;
		cout << "IC Car off!" << endl;
	}

	// print ic car info
	void printDetails(void) {
		cout << "IC car" << endl;
		cout << "--VIN: " << VIN << endl;

		cout << "--State: ";
		if (state_on == true) {
			cout << "ON" << endl;
		} else {
			cout << "OFF" << endl;
		}

		cout << "--Cylinder Count: " << cylinderCount << endl;
	}
};

// electric car
class ElectricCar : public Car {
public:
	ElectricCar(int in_VIN) : Car(in_VIN) {}

	void turnOn(void) {
		state_on = true;
		cout << "E Car on!" << endl;
	}

	void turnOff(void) {
		state_on = false;
		cout << "E Car off!" << endl;
	}

	// print electric car info
	void printDetails(void) {
		cout << "E car" << endl;
		cout << "--VIN: " << VIN << endl;

		cout << "--State: ";
		if (state_on == true) {
			cout << "ON" << endl;
		} else {
			cout << "OFF" << endl;
		}
	}
};

// soapbox car
class SoapBoxCar : public Car {
protected:
	bool has_brakes; // brake flag
	bool has_steering; // steering flag

public:
	SoapBoxCar(int in_VIN, bool in_has_brakes, bool in_has_steering, bool in_state_on) : Car(in_VIN) {
		has_brakes = in_has_brakes;
		has_steering = in_has_steering;
		state_on = in_state_on;
	}

	// print soapbox car info
	void printDetails(void) {
		cout << "SoapBoxCar" << endl;
		cout << "--VIN: " << VIN << endl;

		cout << "--State: ";
		if (state_on == true) {
			cout << "ON" << endl;
		} else {
			cout << "OFF" << endl;
		}

		cout << "--Has Brakes: ";
		if (has_brakes == true) {
			cout << "true" << endl;
		} else {
			cout << "false" << endl;
		}

		cout << "--Has Steering: ";
		if (has_steering == true) {
			cout << "true" << endl;
		} else {
			cout << "false" << endl;
		}
	}
};

int main() {

	// starter cars
	InternalCombustionCar myICCar(1234567890, 4);
	ElectricCar myECar(23476911);

	myICCar.turnOn();
	myICCar.printDetails();

	myECar.printDetails();

	// required soapbox cars
	SoapBoxCar soapBoxCar1(8, true, true, true);
	SoapBoxCar soapBoxCar2(9, false, false, true);
	SoapBoxCar soapBoxCar3(10, false, true, true);

	// print soapbox cars
	soapBoxCar1.printDetails();
	soapBoxCar2.printDetails();
	soapBoxCar3.printDetails();

	return 0;
}