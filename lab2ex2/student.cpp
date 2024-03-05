#include "student.h"


Student::Student(const std::string& name)
    : name_(name), mathGrade_(0), englishGrade_(0), historyGrade_(0) {}

void Student::setName(const std::string& name) {
    name_ = name;
}

std::string Student::getName() const {
    return name_;
}

void Student::setMathGrade(float grade) {
    if (grade >= 1 && grade <= 10)
        mathGrade_ = grade;
}

float Student::getMathGrade() const {
    return mathGrade_;
}

void Student::setEnglishGrade(float grade) {
    if (grade >= 1 && grade <= 10)
        englishGrade_ = grade;
}

float Student::getEnglishGrade() const {
    return englishGrade_;
}

void Student::setHistoryGrade(float grade) {
    if (grade >= 1 && grade <= 10)
        historyGrade_ = grade;
}

float Student::getHistoryGrade() const {
    return historyGrade_;
}

float Student::getAverageGrade() const {
    // Verificăm dacă toate notele sunt setate
    if (mathGrade_ == 0 || englishGrade_ == 0 || historyGrade_ == 0) {
        return -1; // Sau altă valoare specială pentru a indica că media nu poate fi calculată
    }
    return (mathGrade_ + englishGrade_ + historyGrade_) / 3;
}
