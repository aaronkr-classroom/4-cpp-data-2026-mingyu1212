// grade.cpp

#include <vector>
#include <stdexcept>
#include "Student_info.h"
#include "grade.h"
#include "median.h"

double grade(double mid, double fin, const vector<double>& hw)
{
	if (hw.size() == 0) { throw domain_error("No homework!"); }

	// return (mid * 0.2 + fin * 0.4 + (hw1 + hw2 + ...) / hw.size())
	// NEW grade() 함수
	return grade(mid, fin, median(hw));
}

// 계산하는 grade() 함수
double grade(double midterm, double final, double homework)
{
	return midterm * 0.2 + final * 0.4 + homework * 0.4;
}

// Student_info 계산 
double grade(const Student_info& s) {
	return grade(s.midterm, s.final, s.homework);
}
