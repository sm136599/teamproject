#include <iostream>
#include <cstring>

#include "User.h"
#include "UserHandler.h"
#include "Lecture.h"
#include "LectureHandler.h"


void ChangeLectureInfo(user& prof, UserHandler& userhdl, LectureHandler& lecturehdl)
{
	int lecturecode;
	Lecture* changedLecture;
	lecturehdl.showAllLecture();
	cout << "------------------------------------------------" << endl;
	cout << "바꿀강의의 강의코를 입력하세요." << endl;
	cout << "강의 코드: ";
	cin >> lecturecode;
	
	changedLecture = lecturehdl.findLecture(lecturecode);

	lecturehdl.changeLectureInfo(*changedLecture);
}
