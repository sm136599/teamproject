// Lecture 클래스 헤더파일

#ifndef __LECTURE_H__
#define __LECTURE_H__

#define MAXLIMITED 200

class Lecture
{
private:
	int lectureCode;				// 강의코드
	int limitedNum;					// 제한인원	
	int studentCnt;					// 학생 수
	int student[MAXLIMITED];		// 학생ID
	char* lectureTime;				// 강의시간
	char* lectureName;				// 강의이름
	char* lecturer;					// 담당교수명
	char* lectureRoom;				// 강의실
public:
	Lecture(const char* name, const char* lecturer, const char* room, int code, char* time, int limited);
	Lecture(Lecture& ref);
	char* GetLectureName() const;					// 강의명 반환
	int GetLectureCode() const;						// 강의코드 반환
	char* GetLecturer() const;						// 교수명 반환
	int* GetStudentID();							// 학생 배열 반환
	int GetStudentCnt() const;
	void ChangeLectureTime(char* changedtime);		
	void ChangeLectureCode(int changedcode);
	void ChangeLimitedNum(int changedlimited);
	void ChangeLectureName(char* changedname);
	void ChangeLecturer(char* changedlecturer);
	void ChangeLectureRoom(char* changedroom);		// 정보 변경 
	bool AddStudent(int studentId);					// 학생추가 (학생이 수강신청할 때 불릴 함수) 제한인원을 넘기면 false반환 안넘기면 true 반환
	void LectureAllInfoPrint() const;				// 강의 정보 출력
	~Lecture();
};

#endif