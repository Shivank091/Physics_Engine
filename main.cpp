#include <iostream>
#include <vector>
using namespace std;
struct Body {
    float mass;
    float velocity;
    float radii;
    float pos;
};
ostream& operator<<(ostream& os, const Body& b) {
    os << "Body(mass=" << b.mass
       << ", velocity=" << b.velocity
       << ", radius=" << b.radii
       << ", pos=" << b.pos << ")";
    return os;
}
void change_velocity(Body& b, float step, float acc) {
    b.velocity += acc * step;
}
void boundary_balancer(Body& b, float boundary_b1, float boundary_b2) {
    b.pos >= boundary_b2 ? (b.velocity = -b.velocity, b.pos = boundary_b2) : b.velocity;
    b.pos <= boundary_b1 ? (b.velocity = -b.velocity, b.pos = boundary_b1) : b.velocity;
}
void changepos(Body& b, float time, float step, float force, float b1=0, float b2=10) {
    float acc = force / b.mass;
    float start = 0.0;
    while (start < time) {
        if ((time - start) < step) {
            step = time - start;
        }
        b.pos += (b.velocity) * (step);
        boundary_balancer(b, b1, b2);
        change_velocity(b, step, acc);
        start += step;
        cout << b.pos << ' ';
    }
}
int main() {
    cout << "Physics Engine start!\n";
    float b1, b2;
    float pos;
    cout << "Enter boundary values\n";
    cin >> b1 >> b2 ;
    int count;
    vector<Body> bodies;
    cout << "How many bodies would u like to create!\n";
    cin >> count;
    cout << "Enter time for which simulation runs,and force applied\n";
    float time,force;
    cin >> time>>force;
    for (int i = 0; i < count; i++) {
        float m, v, r, pos;
        cout << "Enter mass, velocity, radii, position of body in order\n";
        cin >> m >> v >> r >> pos;
        while (pos < b1 || pos > b2) {
            pos < b1 || pos > b2 ? (cout << "Position must be in range b1 and b2\n", cin >> pos, void()) : void();
        }
        cout<<"Simulation for Body"<<i+1<<":\n";
        Body b{m, v, r, pos};
        bodies.push_back(b);
    }
}