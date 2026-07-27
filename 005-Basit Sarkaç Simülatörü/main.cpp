#include <iostream>
#include <cmath>

#define PI 3.14159265

int main() {
    
    double L = 1.0;                 
    double g = 9.81;                
    double theta = 30.0 * PI / 180.0; 
    double omega = 0.0;             

    double dt = 0.01;   
    double t = 0.0;      

    // 3 saniye boyunca simüle et
    while (t <= 3.0) {
        // Açýsal ivme: a = -(g/L) * sin(theta)
        double alpha = -(g / L) * std::sin(theta);

        // Euler yöntemi: önce hýzý, sonra açýyý güncelle
        omega = omega + alpha * dt;
        theta = theta + omega * dt;

        
        if (int(t * 100) % 20 == 0) {
            std::cout << "t = " << t << " s,  aci = "
                << theta * 180.0 / PI << " derece\n";
        }

        t += dt;
    }

    return 0;
}