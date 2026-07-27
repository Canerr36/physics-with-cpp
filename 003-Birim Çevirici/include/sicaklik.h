#pragma once
#ifndef SICAKLIK_H
#define SICAKLIK_H


class Sicaklik {
public:
	void run();

private:
    double celsiusToFahrenheit(double celsius);
    double fahrenheitToCelsius(double fahrenheit);
    double celsiusToKelvin(double celsius);
    double kelvinToCelsius(double kelvin);
};



#endif // !SICAKLIK_H
