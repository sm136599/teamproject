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
	cout << "�ٲܰ����� �����ڸ� �Է��ϼ���." << endl;
	cout << "���� �ڵ�: ";
	cin >> lecturecode;
	
	changedLecture = lecturehdl.findLecture(lecturecode);

	lecturehdl.changeLectureInfo(*changedLecture);
}
