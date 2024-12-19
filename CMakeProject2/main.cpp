#include "Person.h"

int main() {
    setlocale(LC_ALL, "RU");

    std::ifstream inputFile("C:/Users/stank/Desktop/input.txt");
    std::ofstream outputFile("C:/Users/stank/Desktop/output.txt");

    if (!inputFile.is_open() || !outputFile.is_open()) {
        std::cerr << "Ошибка открытия файлов." << std::endl;
        return 1;
    }

    std::vector<int> intArr;
    std::string line;
    std::getline(inputFile, line);

    std::stringstream ss(line);
    int num;
    while (ss >> num) {
        intArr.push_back(num);
    }


    std::vector<Person> people;
    while (std::getline(inputFile, line)) {
        std::stringstream ss2(line);
        std::string name;
        int age;
        if (ss2 >> name >> age) {
            people.push_back(Person(name, age));
        }
    }

    quickSort(intArr, 0, intArr.size() - 1);
    quickSort(people, 0, people.size() - 1);

    outputFile << "Sorted integers: ";
    for (int n : intArr) {
        outputFile << n << " ";
    }
    outputFile << std::endl;

    outputFile << "Sorted persons: ";
    if (!people.empty()) {
        for (const auto& person : people) {
            outputFile << person.name << " (" << person.age << ") ";
        }
    }
    else {
        outputFile << "No persons found.";
    }
    outputFile << std::endl;

    inputFile.close();
    outputFile.close();
    return 0;
}