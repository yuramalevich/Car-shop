#include<iostream>
#include<string>

using namespace std;

class Car {
private:
	char* car_make, * car_model;
	int* year, * car_mileage, * stock;
public:
	float price;
	Car() {
		car_make = new char[20];
		car_model = new char[20];
		year = new int;
		price = 0.0;
		car_mileage = new int;
		stock = new int;
	}
	~Car()
	{
		delete car_make, car_model, price, year, car_mileage, stock;
	}
	void Setdata();
	void Getdata();
	int search(char[], char[]);
};

void Car::Setdata() {
	cin.ignore();
	cout << "Enter car make: "; cin.getline(car_make, 20); // марка автомобиля
	cout << "Enter car model: "; cin.getline(car_model, 20);// модель автомобиля
	cout << "Enter the year of manufacture of the car: "; cin >> *year; //год выпуска автомобиля
	cout << "Enter Price: "; cin >> price; // цена автомобиля
	cout << "Enter car mileage: "; cin >> *car_mileage; // пробег автомобиля
	cout << "Enter Stock Position: "; cin >> *stock; // позиция автомобиля (его наличие)
}

void Car::Getdata() {
	cout << "Car make: " << car_make;
	cout << "\nCar model: " << car_model;
	cout << "\nThe year of manufacture of the car: " << *year;
	cout << "\nCar price: " << price;
	cout << "\nCar mileage: " << *car_mileage;
	cout << "\nCar position: " << *stock;
}
int Car::search(char tbuy[20], char abuy[20]) {
	if (strcmp(tbuy, car_make) == 0 && strcmp(abuy, car_model) == 0)
		return 1;
	else return 0;

}
int main()
{
	char detail_make[20], detail_model[20];
	Car* Cars[20];
	int counter = 0;
	while (true) {
		int choice, number = 1;
		float user_price;
		cout << "\n\n\t\tMENU"
			<< "\n1. Entry of Car"
			<< "\n2. Buy Car"
			<< "\n3. Search For Car"
			<< "\n4. Edit Details Of Car"
			<< "\n5. Exit"
			<< "\n\nEnter your Choice: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			Cars[counter] = new Car;
			Cars[counter]->Setdata();
			counter++;
			break;
		case 2:
			cout << "Enter a price for the car: "; cin >> user_price;
			for (int i = 0; i < counter; i++)
			{
				if (Cars[i]->price <= user_price)
				{
					Cars[i]->Getdata();
				}
			}
			break;
		case 3:
			for (int i = 0; i < counter; i++)
			{
				cout << "Car number" << number << endl;
				Cars[i]->Getdata();
			}
			break;
		case 4:
			cin.ignore();
			cout << "Enter car make"; cin.getline(detail_make, 20);
			cout << "Enter car model"; cin.getline(detail_model, 20);
			for (int i = 0; i < counter; i++)
			{
				if (Cars[i]->search(detail_make, detail_model)) {
					cout << "\nCar Found Successfully\n"
						<< "Information about this car:\n";
					Cars[i]->Getdata();
					cout << "Add details to the description of the car: " << endl;
					Cars[i]->Setdata();
				}
			}
		case 5:
			exit(0);
		}
	}

	return 0;
}