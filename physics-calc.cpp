#include <cmath>
#include <iostream>

using namespace std;

const double speed_of_light{299792458};
const double pi{3.14159};
const double gravity{9.80665};

double input_prompt(string prompt) {
  double x{};
  cout << prompt;
  cin >> x;

  return x;
}

double gravitational_potential_energy(double potential_energy, double mass, double gravitational_acceleration, double height){
    if (potential_energy == -1){
        cout << "The potential energy is: ";
        return mass * gravitational_acceleration * height;
    } else if (mass == -1){
        cout << "The mass is: ";
        return ((potential_energy) / (gravitational_acceleration * height));
    } else if (gravitational_acceleration == -1){
        cout << "The gravitational acceleration is: ";
        return ((potential_energy) / (mass * height));
    } else if (height == -1){
        cout << "The height is: ";
        return ((potential_energy) / (mass * gravitational_acceleration));
    } else {
        cout << "Error: All values are known. Please try again.";
        return 1;
    }
    return 0;
}

double kinetic_energy_formula(double kinetic_energy, double mass, double velocity){
    if (kinetic_energy == -1){
        cout << "The kinetic energy is: ";
        return (0.5 * mass * (pow(velocity, 2)));
    } else if (mass == -1){
        cout << "The mass is: ";
        return ((2 * kinetic_energy
                / (pow(velocity, 2))));
    } else if (velocity == -1){
        cout << "The velocity is: ";
        return (sqrt((2 * kinetic_energy) / mass));
    } else {
        cout << "Error: All values are known. Please try again.\n";
        return 1;
    }
    return 0;
}

double newtons_second_law(double force, double mass, double acceleration){
    if (force == -1){
        cout << "The force is: ";
        return (mass * acceleration);
    } else if (mass == -1){
        cout << "The mass is: ";
        return (force / acceleration);
    } else if (acceleration == -1){
        cout << "The acceleration is: ";
        return (force / mass);
    } else {
        cout << "Error: All values are known. Please try again.\n";
        return 1;
    }
    return 0;
}

double pendulum_formula(double pendulum_period, double pendulum_length,
                        double acceleration_of_gravity) {
  if (pendulum_period == -1) {
    cout << "The pendulum period is: ";
    return (2 * pi * sqrt(pendulum_length / acceleration_of_gravity));
  } else if (pendulum_length == -1) {
    cout << "The pendulum length is: ";
    return ((pow(pendulum_period, 2) * acceleration_of_gravity) /
            (4 * pow(pi, 2)));
  } else if (acceleration_of_gravity == -1) {
    cout << "The acceleration of gravity is: ";
    return (4 * pow(pi, 2) * pendulum_length) / (pow(pendulum_period, 2));
  } else {
    cout << "Error: All values are known. Please try again.\n";
    return 1;
  }

  return 0;
}

double refractive_index_formula(double v) {
  double n{};
  n = speed_of_light / v;
  return n;
}

double power_formula(double power, double work, double time) {
  if (power == -1) {
    cout << "The power is: ";
    return work / time;
  } else if (work == -1) {
    cout << "The work is: ";
    return power * time;
  } else if (time == -1) {
    cout << "The time is: ";
    return work / power;
  } else {
    cout << "Error: All values are known. Please try again.\n";
    return 1;
  }
  return 0;
}

int main() {
  int choose_formula{};
  cout << "Which formula do you want to use?\n"
       << "(1) Refractive Index Formula\n"
       << "(2) Power Formula\n"
       << "(3) Pendulum Formula\n"
       << "(4) Newtons Second Law\n"
       << "(5) Kinetic Energy\n"
       << "(6) Gravitational Potential Energy\n"
       << "Enter number: ";
  cin >> choose_formula;

  switch (choose_formula) {
    case 1: {
      double speed_light_medium =
          input_prompt("Enter the speed of light in the medium: ");

      cout << "Answer is: " << refractive_index_formula(speed_light_medium);
      break;
    }
    case 2: {
      double power = input_prompt("Enter power (enter -1 if unknown): ");
      double work = input_prompt("Enter work (enter -1 if unknown): ");
      double time = input_prompt("Enter time (enter -1 if unknown): ");

      cout << power_formula(power, work, time);
      break;
    }
    case 3: {
      double pendulum_period =
          input_prompt("Enter pendulum period (enter -1 if unknown): ");
      double pendulum_length =
          input_prompt("Enter pendulum length (enter -1 if unknown): ");
      double acceleration_of_gravity = input_prompt(
          "Enter acceleration of gravity (enter -1 if unknown, Earth is "
          "9.81): ");

      cout << pendulum_formula(pendulum_period, pendulum_length,
                               acceleration_of_gravity);
      break;
    }
    case 4: {
        double force = input_prompt("Enter force in Newtons (enter -1 if unknown): ");
        double mass = input_prompt("Enter mass in kg (enter -1 if unknown): ");
        double acceleration = input_prompt("Enter acceleration in m/s^2 (enter -1 if unknown): ");
        
        cout << newtons_second_law(force, mass, acceleration);
        break;
    }
    case 5: {
        double kinetic_energy = input_prompt("Enter kinetic energy in Joules (enter -1 if unknown): ");
        double mass = input_prompt("Enter mass in kg (enter -1 if unknown): ");
        double velocity = input_prompt("Enter velocity in m/s (enter -1 if unknown): ");
        
        cout << kinetic_energy_formula(kinetic_energy, mass, velocity);
        break;
    }
    case 6: {
        double potential_energy = input_prompt("Enter potential energy in Joules (enter -1 if unknown): ");
        double mass = input_prompt("Enter mass in kg (enter -1 if unknown): ");
        double gravitational_acceleration = input_prompt("Enter gravitational acceleration in m/s^2 (enter -1 if unknown, Earth is 9.81): ");
        double height = input_prompt("Enter height in meters (enter -1 if unknown): ");
        
        cout << gravitational_potential_energy(potential_energy, mass, gravitational_acceleration, height);
        break;
    }
    default: {
      cout << "Error: Please input a valid number.";
      break;
    }
  }
  return 0;
}