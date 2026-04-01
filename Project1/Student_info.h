#pragma once
// Student_info.h

#ifndef GUARD_Student_info_h
#define GUARD_Student_info_h

#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 구조체
struct Student_info
{
	// 속성
	string name;
	double midterm, final;
	vector<double> homework;
};
// 함수 원형 정의
bool compare(const Student_info&, const Student_info&); // 이름 비교하기
istream& read(istream&, Student_info&); // 한 학생의 정보 읽기
istream& read_hw(istream&, vector<double>&); // 모든 과제 점수 읽기

#endif
