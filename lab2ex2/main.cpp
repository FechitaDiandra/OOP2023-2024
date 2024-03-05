#include <iostream>
#include "student.h"
#include "global_functions.h"

int main() {
    Student student1("Maria");
    Student student2("Florin");

    student1.setMathGrade(10);
    student1.setEnglishGrade(9);
    student1.setHistoryGrade(8);

    student2.setMathGrade(7);
    student2.setEnglishGrade(6);
    student2.setHistoryGrade(10);

    std::cout << "Numele studentului 1: " << student1.getName() << std::endl;
    std::cout << "Nota medie a studentului 1: " << student1.getAverageGrade() << std::endl;

    std::cout << "Numele studentului 2: " << student2.getName() << std::endl;
    std::cout << "Nota medie a studentului 2: " << student2.getAverageGrade() << std::endl;

    std::cout << "Comparare dupa nume: " << compareByName(student1, student2) << std::endl;
    std::cout << "Comparare dupa note: " << compareByGrades(student1, student2) << std::endl;
    std::cout << "Comparare dupa medie: " << compareByAverage(student1, student2) << std::endl;

    return 0;
}