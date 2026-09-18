#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

class Workout {
public:
    Workout(const std::string& exercise, int sets, int reps)
        : exercise(exercise), sets(sets), reps(reps) {}

    const std::string& getExercise() const {
        return exercise;
    }

    int getSets() const {
        return sets;
    }

    int getReps() const {
        return reps;
    }

private:
    std::string exercise;
    int sets;
    int reps;
};

class TrainingPlan {
public:
    void addWorkout(const std::string& exercise, int sets, int reps) {
        workouts.emplace_back(exercise, sets, reps);
    }

    void printPlan() const {
        std::cout << "Training Plan\n";
        std::cout << "=============\n";

        for (const auto& workout : workouts) {
            std::cout << std::left << std::setw(18)
                      << workout.getExercise()
                      << " Sets: " << workout.getSets()
                      << " Reps: " << workout.getReps()
                      << std::endl;
        }
    }

private:
    std::vector<Workout> workouts;
};

int main() {
    TrainingPlan plan;

    plan.addWorkout("Push Ups", 4, 15);
    plan.addWorkout("Pull Ups", 3, 10);
    plan.addWorkout("Squats", 5, 12);
    plan.addWorkout("Plank", 3, 60);

    plan.printPlan();

    return 0;
}
