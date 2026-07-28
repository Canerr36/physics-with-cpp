#pragma once
#ifndef IKIBOYUTTACARPISMA_H
#define IKIBOYUTTACARPISMA_H


class IkiBoyuttaCarpisma {
public:
	void run();

private:
	double esnekCarpismaV1(double v1, double m1, double v2, double m2);
	double esnekCarpismaV2(double v1, double m1, double v2, double m2);
	double esnekOlmayanCarpisma(double v1, double m1, double v2, double m2);
};



#endif // !IkiBOYUTTACARPISMA_H