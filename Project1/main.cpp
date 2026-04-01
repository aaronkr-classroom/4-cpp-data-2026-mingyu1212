// main.cpp

// 중간고사, 기말고사, 그리고 과제 점수 몇 개를 받고
// 마지막 평균 결과 점수를 계산하기
// Input midterm, final and some HW score,
// calculate average result score

#include <algorithm> // sort()
#include <ios>
#include <iostream>
#include <iomanip> // setprecision()
#include <string>
#include <stdexcept> // istream& 위해서
#include <vector>
#include "Student_info.h"
#include "grade.h"

using namespace std;

typedef vector<double>::size_type vec_sz;
typedef vector<Student_info>::size_type si_sz;

// 함수 원형 정의문
double median(vector<double>);

int main(void)
{
	// NEW 구조 자료형 선언
	vector<Student_info> students;
	Student_info record;
	string::size_type maxlen = 0;

	// 프로그램 설명하기
	cout << "For every student, enter: " << endl <<
		"Name Midterm Final HW1 HW2... " << endl;

	while (read(cin, record)) {
		maxlen = max(maxlen, record.name.size());
		students.push_back(record);
	}

	// 학생 정보를 알파벳순으로 정렬
	sort(students.begin(), students.end(), compare);

	// 모든 학생의 결과를 출력
	for (si_sz i = 0; i != students.size(); ++i) {
		// 이름과 오른쪽 공백을 포함하여 maxlen + 1개의 문자를 출력
		cout << students[i].name <<
			string(maxlen + 1 - students[i].name.size(), ' ');

		// 최종 점수를 계산하여 출력
		try {
			double final_grade = grade(students[i]); // NEW Calc Func - grade()
			streamsize prec = cout.precision();
			cout <<  setprecision(3) << final_grade << 
				setprecision(prec) << endl;
		}
		catch(domain_error e) {
			cout << e.what();
		}
		cout << endl;
	}

	// NEW Function read_hw()
	read_hw(cin, homework); // 사실 객체 필요해서 참조로 보냄

	// 종합 점수를 계산해 생성 Calculate comprehensive score and create
	double final_grade = 0; // NEW Calc Func - grade()
	streamsize prec = cout.precision();
	cout << "Final grade: " << setprecision(3) <<
		final_grade << setprecision(prec) << endl;

	return 0;
}
// 입력 스트림에서 과제 점수를 읽어서 vector<double>에 넣음
istream& read_hw(istream& in, vector<double>& hw)
{
	if (in)
	{
		// 이전 내용을 제거
		hw.clear();

		// 과제 점수를 읽음
		double x;

		while (in >> x)
		{
			hw.push_back(x);
		}
		
		// 다음 학생의 점수 입력 작업을 고려해 스트림을 지움
		in.clear();
	}
	return in;
}

// 중간고사 점수, 기말고사 점수, 과제 점수의 벡터로 학생의 종합
// 점수를 구함. 이 함수는 인수를 복사하지 않고 median 함수가
// 해당 작업을 실행
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

// vector<double>의 중앙값을 구함
// 함수를 호출하면 인수로 제공된 벡터를 통째로 복사
double median(vector<double> vec)
{
	vec_sz size = vec.size();
	
	if(size==0)
	{
		throw domain_error("Median of empty vector!");
		return 1;
	}

	sort(vec.begin(), vec.end());
	vec_sz mid = size / 2;
	return size % 2 == 0 // 조건
		? (vec[mid] + vec[mid - 1]) / 2 // 참일 때 반환
		: vec[mid]; // 거짓일 때 반환
}
