// Lecture 클래스 헤더파일

#ifndef __LECTURE_H__
#define __LECTURE_H__

#define MAXLIMITED 200

class Lecture
{
private:
	double lectureTime;				// 강의시간
	int lectureCode;				// 강의코드
	int limitedNum;					// 제한인원	
	int studentCnt;					// 학생 수
	int student[MAXLIMITED];		// 학생ID   
	char* lectureName;				// 강의이름
	char* lecturer;					// 담당교수명
	char* lectureRoom;				// 강의실
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
	void AddStudent(int studentId);
	void LectureAllInfoPrint() const;
	~Lecture();
};

#endif