// Exercise 12: Small 2D N-body (planetary) simulation with velocity Verlet
// Tasks:
//   a) Explain the Vec2 and Particle structs and what operator overloading gives us.
//   b) Write pseudocode for accelerations() and verletStep(). Note the order of the operations!
//   c) Why is the total energy a useful check, and what do you expect it to do over time?
#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>

struct Vec2 {
    double x = 0.0, y = 0.0;
};
Vec2 operator+(Vec2 a, Vec2 b)   { return {a.x + b.x, a.y + b.y}; }
Vec2 operator-(Vec2 a, Vec2 b)   { return {a.x - b.x, a.y - b.y}; }
Vec2 operator*(double s, Vec2 a) { return {s * a.x, s * a.y}; }
double dot(Vec2 a, Vec2 b)       { return a.x * b.x + a.y * b.y; }

struct Particle {
    Vec2 pos, vel;
    double mass;
};

const double G = 1.0;
const double SOFTENING = 1e-3;

std::vector<Vec2> accelerations(const std::vector<Particle>& ps) {
    std::vector<Vec2> acc(ps.size());
    for (size_t i = 0; i < ps.size(); i++) {
        for (size_t j = 0; j < ps.size(); j++) {
            if (i == j) continue;
            Vec2 d = ps[j].pos - ps[i].pos;
            double r2 = dot(d, d) + SOFTENING * SOFTENING;
            double invR3 = 1.0 / (r2 * std::sqrt(r2));
            acc[i] = acc[i] + (G * ps[j].mass * invR3) * d;
        }
    }
    return acc;
}

double totalEnergy(const std::vector<Particle>& ps) {
    double E = 0.0;
    for (size_t i = 0; i < ps.size(); i++) {
        E += 0.5 * ps[i].mass * dot(ps[i].vel, ps[i].vel);
        for (size_t j = i + 1; j < ps.size(); j++) {
            Vec2 d = ps[j].pos - ps[i].pos;
            E -= G * ps[i].mass * ps[j].mass / std::sqrt(dot(d, d) + SOFTENING * SOFTENING);
        }
    }
    return E;
}

void verletStep(std::vector<Particle>& ps, std::vector<Vec2>& acc, double dt) {
    for (size_t i = 0; i < ps.size(); i++) ps[i].vel = ps[i].vel + (0.5 * dt) * acc[i];
    for (size_t i = 0; i < ps.size(); i++) ps[i].pos = ps[i].pos + dt * ps[i].vel;
    acc = accelerations(ps);
    for (size_t i = 0; i < ps.size(); i++) ps[i].vel = ps[i].vel + (0.5 * dt) * acc[i];
}

int main() {
    std::vector<Particle> ps = {
        {{0.0, 0.0},  {0.0, 0.0},  1000.0},    // heavy central body
        {{10.0, 0.0}, {0.0, 10.0}, 1.0},       // inner planet, circular orbit speed sqrt(G*M/r)
        {{0.0, 20.0}, {-std::sqrt(1000.0 / 20.0), 0.0}, 1.0}   // outer planet
    };

    const double dt = 0.01;
    const int nSteps = 20000;
    std::vector<Vec2> acc = accelerations(ps);
    const double E0 = totalEnergy(ps);

    std::cout << std::setprecision(8);
    for (int n = 0; n <= nSteps; n++) {
        if (n % 4000 == 0) {
            double E = totalEnergy(ps);
            std::cout << "t = " << std::setw(6) << n * dt
                      << "  relative energy drift = " << (E - E0) / std::fabs(E0) << "\n";
        }
        verletStep(ps, acc, dt);
    }
    return 0;
}
