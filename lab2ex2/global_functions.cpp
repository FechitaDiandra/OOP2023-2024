#include "global_functions.h"

int compareByName(const Student& s1, const Student& s2) {
    return s1.getName().compare(s2.getName());
}

int compareByGrades(const Student& s1, const Student& s2) {
    float avg1 = s1.getAverageGrade();
    float avg2 = s2.getAverageGrade();

    // Folosim o compara?ie direct? între medii
    if (avg1 == avg2)
        return 0;
    return (avg1 > avg2) ? 1 : -1;
}

int compareByAverage(const Student& s1, const Student& s2) {
    // Folosim o compara?ie direct? între medii
    if (s1.getAverageGrade() == s2.getAverageGrade())
        return 0;
    return (s1.getAverageGrade() > s2.getAverageGrade()) ? 1 : -1;
}
