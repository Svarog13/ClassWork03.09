#include <iostream>
#include <Windows.h>

class Car {
protected:
    std::string brand;
    std::string color;
    int year;
    int speed;
    float volume;
    const int maxSpeed;

public:
    Car() : brand("no brand"), color("no color"), year(0), speed(0), volume(0), maxSpeed(220) {}
    Car(std::string b, std::string c, int y, float v) : brand(b), color(c), year(y), volume(v), maxSpeed(220) {}

    void setSpeed(int speed) {
        if (speed >= 0 && speed <= maxSpeed) {
            this->speed = speed;
        }
        else {
            std::cout << "Error speed" << std::endl;
        }
    }

    virtual void Drive() const {
        std::cout << "I'm a car and I can drive with " << speed << " km/h" << std::endl;
    }

    void Print() const {
        std::cout << "Brand: " << brand << std::endl;
        std::cout << "Colour: " << color << std::endl;
        std::cout << "Year of production: " << year << std::endl;
        std::cout << "Volume: " << volume << std::endl;
    }
};

class PoliceCar : public Car {
private:
    int sound;

public:
    PoliceCar() : sound(0) {}
    PoliceCar(std::string b, std::string c, int y, float v, int s) : Car(b, c, y, v), sound(s) {}

    void Drive() const override {
        std::cout << "I'm a police car and I can drive with " << speed << " km/h" << std::endl;
    }

    void Print() const override {
        Car::Print();
        std::cout << "Sound: " << sound << std::endl;
    }

    void BeepBeep() {
        Beep(sound, 700);
        Beep(sound + 200, 1000);
    }
};

class SportCar : public Car {
private:
    int turboBoost;

public:
    SportCar() : turboBoost(0) {}
    SportCar(std::string b, std::string c, int y, float v, int t) : Car(b, c, y, v), turboBoost(t) {}

    void Drive() const override {
        std::cout << "I'm a sports car and I can drive with " << speed << " km/h" << std::endl;
    }

    void Print() const override {
        Car::Print();
        std::cout << "Turbo: " << turboBoost << std::endl;
    }

    void TurboBoost() {
        std::cout << "Speed before acceleration: " << speed << std::endl;
        speed += turboBoost;
        std::cout << "Speed after acceleration: " << speed << std::endl;
    }
};

void TestDrive(Car& car) {
    car.setSpeed(60);
    car.Drive();
}

int main() {
    Car car("Audi", "black", 2013, 3.0);
    car.setSpeed(160);
    car.Drive();

    PoliceCar policeCar("Toyota", "white", 2016, 600, 1000);
    policeCar.setSpeed(70);
    policeCar.BeepBeep();
    policeCar.Drive();

    SportCar sport("Ferrari", "red", 1996, 5.0, 100);
    sport.setSpeed(150);
    sport.TurboBoost();
    sport.Drive();

    TestDrive(policeCar);
    TestDrive(car);
    TestDrive(sport);

    return 0;
}