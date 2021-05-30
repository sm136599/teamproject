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
		cout << "-------------------" << endl;
		cout << "1. 강의 목록 출력" << endl;
		cout << "2. 강의 정보 변경" << endl;
		cout << "3. 뒤로 가기" << endl;
		cout << "선택: ";
		cin >> choice;
		switch (choice)
		{
		case PRINTLECTURELIST:
			system("cls");
			lecturehdl.showLectureByProfName(prof.get_name());
			break;
		case CHANGELECTUREINFO:
			cout << "------------------------------------" << endl;
			cout << "바꿀강의의 강의 코드를 입력하세요." << endl;
			cout << "강의 코드: ";
			cin >> lecturecode;

			system("cls");
			try
			{
				if (lecturecode <= 0 || (lecturecode > lecturehdl.getLectureCount()))	// lecturecode에 음수, 개설된 강의 수보다 많은 수, 문자, 특수문자 가 입력되면 false
					throw lecturecode;
				else if (strcmp(prof.get_name(), lecturehdl.findLecture(lecturecode)->GetLecturer()))	// 자기 자신의 강의만 변경하기 위한 검사
					throw prof.get_name();

				changedLecture = lecturehdl.findLecture(lecturecode);
				lecturehdl.changeLectureInfo(*changedLecture);
			}
			catch (int nlecturecode)
			{
				cout << "잘못된 강의 코드 입니다." << endl;
			}
			catch (char* profname)
			{
				cout << "자신의 강의만 변경할 수 있습니다." << endl;
			}
			break;
		case BACK:
			break;
		default:
			cout << "잘못된 선택입니다." << endl;
			break;
		}
	} while (choice != BACK);
}
