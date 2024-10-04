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
          "9.80665): ");

      cout << pendulum_formula(pendulum_period, pendulum_length,
                               acceleration_of_gravity);
      break;
    }
    default: {
      cout << "Error: Please input a valid number.";
      break;
    }
  }
  return 0;
}
