// Lecture 클래스 헤더파일

#ifndef __LECTURE_H__
#define __LECTURE_H__

#define MAXLIMITED 200

class Lecture
{
private:
	double lectureTime;
	int lectureCode;
	int limitedNum;
	int studentCnt;
	(char*)* student[MAXLIMITED];
	char* lectureName;
	char* lecturer;
	char* lectureRoom;
public:
	Lecture(const char* name, const char* lecturer, const char* room, int code, double time, int limited);
	Lecture(Lecture& ref);
	char* GetLectureName() const;
	int GetLectureCode() const;
	char* GetLecturer() const;
	void ChangeLectureTime(double changedtime);
	void ChangeLectureCode(int changedcode);
	void ChangeLimitedNum(int changedlimited);
	void ChangeLectureName(char* changedname);
	void ChangeLecturer(char* changedlecturer);
	void ChangeLectureRoom(char* changedroom);
	void AddStudent(char* studentId);
	void LectureAllInfoPrint() const;
	~Lecture();
};

#endif