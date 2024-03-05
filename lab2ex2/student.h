

#define STUDENT_H
#ifndef STUDENT_H
#include<string>


class Student {
public:
    // Constructor
    Student(const std::string& name);

    // Metode pentru setarea ?i ob?inerea numelui
    void setName(const std::string& name);
    std::string getName() const;

    // Metode pentru setarea ?i ob?inerea notelor
    void setMathGrade(float grade);
    float getMathGrade() const;
    void setEnglishGrade(float grade);
    float getEnglishGrade() const;
    void setHistoryGrade(float grade);
    float getHistoryGrade() const;

    // Metod? pentru ob?inerea notei medii
    float getAverageGrade() const;

private:
    std::string name_;
    float mathGrade_;
    float englishGrade_;
    float historyGrade_;
};

#endif // STUDENT_H