#pragma once

#ifndef GLOBAL_FUNCTIONS_H_
#define GLOBAL_FUNCTIONS_H_

#include "student.h"

// Func?ii globale pentru compararea a dou? obiecte Student
int compareByName(const Student& s1, const Student& s2);
int compareByGrades(const Student& s1, const Student& s2);
int compareByAverage(const Student& s1, const Student& s2);

#endif // GLOBAL_FUNCTIONS_H_
