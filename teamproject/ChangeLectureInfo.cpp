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
	lecturehdl.showLectureByProfName(prof.get_name());
	cout << "------------------------------------------------" << endl;
	cout << "�ٲܰ����� �����ڸ� �Է��ϼ���." << endl;
	cout << "���� �ڵ�: ";
	cin >> lecturecode;
	
	try
	{
		if (lecturecode <= 0 || (lecturecode > lecturehdl.getLectureCount()))	// lecturecode�� ����, ������ ���� ������ ���� ��, ����, Ư������ �� �ԷµǸ� false
			throw lecturecode;
		else if (strcmp(prof.get_name(), lecturehdl.findLecture(lecturecode)->GetLecturer()))	// �ڱ� �ڽ��� ���Ǹ� �����ϱ� ���� �˻�
			throw prof.get_name();

		changedLecture = lecturehdl.findLecture(lecturecode);
		lecturehdl.changeLectureInfo(*changedLecture);
	}
	catch (int nlecturecode)
	{
		cout << "�߸��� ���� �ڵ� �Դϴ�." << endl;
	}
	catch (char* profname)
	{
		cout << "�ڽ��� ���Ǹ� ������ �� �ֽ��ϴ�." << endl;
	}

}
