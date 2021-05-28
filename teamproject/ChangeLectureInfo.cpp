#include <iostream>
#include <cstring>

#include "User.h"
#include "UserHandler.h"
#include "Lecture.h"
#include "LectureHandler.h"

enum choice { PRINTLECTURELIST = 1, CHANGELECTUREINFO, BACK };

void ChangeLectureInfo(user& prof, UserHandler& userhdl, LectureHandler& lecturehdl)
{
	int lecturecode;
	int choice;
	Lecture* changedLecture;

	do
	{
		cout << "------------------------------------------------" << endl;
		cout << "1. ���� ��� ���" << endl;
		cout << "2. ���� ���� ����" << endl;
		cout << "3. �ڷ� ����" << endl;
		cout << "����: ";
		cin >> choice;
		switch (choice)
		{
		case PRINTLECTURELIST:
			lecturehdl.showLectureByProfName(prof.get_name());
			break;
		case CHANGELECTUREINFO:
			cout << "------------------------------------------------" << endl;
			cout << "�ٲܰ����� ���� �ڵ带 �Է��ϼ���." << endl;
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
			break;
		case BACK:
			break;
		default:
			cout << "�߸��� �����Դϴ�." << endl;
			break;
		}
	} while (choice != BACK);
}
