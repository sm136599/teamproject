#define MAXLIMITED 200
#include <iostream>
#include <cstring>
#include "Lecture.h"

using namespace std;


Lecture::Lecture(const char* name, const char* lecturer, const char* room, int code, double time, int limited)
	: lectureCode(code), lectureTime(time), limitedNum(limited), studentCnt(0)
{
	for (int i = 0;i < MAXLIMITED;i++)
	{
		student[i] = new char[10];
		strcpy(student[i], "xxxxxxxxx");
	}
	this->lectureName = new char[strlen(name) + 1];
	this->lecturer = new char[strlen(lecturer) + 1];
	this->lectureRoom = new char[strlen(room) + 1];
	strcpy(this->lectureName, name);
	strcpy(this->lecturer, lecturer);
	strcpy(this->lectureRoom, room);
}

Lecture::Lecture(Lecture& ref)
	: lectureCode(ref.lectureCode), lectureTime(ref.lectureTime), limitedNum(ref.limitedNum), studentCnt(ref.studentCnt)
{
	for (int i = 0;i < MAXLIMITED;i++)
	{
		student[i] = new char[10];
		strcpy(this->student[i], ref.student[i]);
	}
	this->lectureName = new char[strlen(ref.lectureName) + 1];
	this->lecturer = new char[strlen(ref.lecturer) + 1];
	this->lectureRoom = new char[strlen(ref.lectureRoom) + 1];
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

void Lecture::ChangeLectureTime(double changedtime)
{
	lectureTime = changedtime;
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

void Lecture::AddStudent(char* studentId)
{
	if (studentCnt >= limitedNum)
	{
		cout << "¼ö°­ÀÎ¿øÀÌ ²Ë Ã¡½À´Ï´Ù." << endl;
		return;
	}
	else
	{
		student[studentCnt++] = studentId;
	}
}

void Lecture::LectureAllInfoPrint() const
{
	cout << lectureCode << endl;
	cout << lectureName << endl;
	cout << lectureTime << endl;
	cout << limitedNum << endl;
	cout << lecturer << endl;
	cout << lectureRoom << endl;
}



Lecture::~Lecture()
{
	for (int i = 0;i < MAXLIMITED;i++)
	{
		delete[] student[i];
	}
	delete[]lectureName;
	delete[]lecturer;
	delete[]lectureRoom;
}