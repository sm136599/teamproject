#define MAXLIMITED 200

#include <iostream>
#include <cstring>
#include "Lecture.h"

using namespace std;


Lecture::Lecture(const char* name, const char* lecturer, const char* room, int code, char* time, int limited)
	: lectureCode(code), limitedNum(limited), studentCnt(0)
{
	for (int i = 0;i < MAXLIMITED;i++)
	{
		student[i] = 0;
	}
	this->lectureTime = new char[strlen(time) + 1];
	this->lectureName = new char[strlen(name) + 1];
	this->lecturer = new char[strlen(lecturer) + 1];
	this->lectureRoom = new char[strlen(room) + 1];
	strcpy(this->lectureTime, time);
	strcpy(this->lectureName, name);
	strcpy(this->lecturer, lecturer);
	strcpy(this->lectureRoom, room);
}

Lecture::Lecture(Lecture& ref)
	: lectureCode(ref.lectureCode), limitedNum(ref.limitedNum), studentCnt(ref.studentCnt)
{
	for (int i = 0;i < MAXLIMITED;i++)
	{
		student[i] = ref.student[i];
	}
	this->lectureTime = new char[strlen(ref.lectureTime) + 1];
	this->lectureName = new char[strlen(ref.lectureName) + 1];
	this->lecturer = new char[strlen(ref.lecturer) + 1];
	this->lectureRoom = new char[strlen(ref.lectureRoom) + 1];
	strcpy(this->lectureTime, ref.lectureTime);
	strcpy(this->lectureName, ref.lectureName);
	strcpy(this->lecturer, ref.lecturer);
	strcpy(this->lectureRoom, ref.lectureRoom);
}

char* Lecture::GetLectureName() const
{
	return lectureName;
}

int Lecture::GetLectureCode() const
{
	return lectureCode;
}

char* Lecture::GetLecturer() const
{
	return lecturer;
}

int* Lecture::GetStudentID()
{
	return student;
}

int Lecture::GetStudentCnt() const
{
	return studentCnt;
}

void Lecture::ChangeLectureTime(char* changedtime)
{
	delete[]lectureTime;
	this->lectureTime = new char[strlen(changedtime) + 1];
	strcpy(this->lectureTime, changedtime);
}
void Lecture::ChangeLectureCode(int changedcode)
{
	lectureCode = changedcode;
}
void Lecture::ChangeLimitedNum(int changedlimited)
{
	limitedNum = changedlimited;
}
void Lecture::ChangeLectureName(char* changedname)
{
	delete[]lectureName;
	this->lectureName = new char[strlen(changedname) + 1];
	strcpy(this->lectureName, changedname);
}
void Lecture::ChangeLecturer(char* changedlecturer)
{
	delete[]lecturer;
	this->lecturer = new char[strlen(changedlecturer) + 1];
	strcpy(this->lecturer, changedlecturer);
}
void Lecture::ChangeLectureRoom(char* changedroom)
{
	delete[]lectureRoom;
	this->lectureRoom = new char[strlen(changedroom) + 1];
	strcpy(this->lectureRoom, changedroom);
}

bool Lecture::AddStudent(int studentId)
{
	if (studentCnt >= limitedNum)
	{
		cout << "수강인원이 꽉 찼습니다." << endl;
		return false;
	}
	else
	{
		student[studentCnt++] = studentId;
		return true;
	}
}

void Lecture::LectureAllInfoPrint() const
{
	cout << "--------------------------" << endl;
	cout << "강의코드: " << lectureCode << endl;
	cout << "강의명: " << lectureName << endl;
	cout << "강의시간: " << lectureTime << endl;
	cout << "제한인원: " << studentCnt << "/" << limitedNum << endl;
	cout << "교수명: " << lecturer << endl;
	cout << "강의실: " << lectureRoom << endl;
	cout << "--------------------------" << endl;
}

Lecture::~Lecture()
{
	delete[]lectureName;
	delete[]lecturer;
	delete[]lectureRoom;
}