// Lecture Ŭ���� �������

#ifndef __LECTURE_H__
#define __LECTURE_H__

#define MAXLIMITED 200

class Lecture
{
private:
	double lectureTime;				// ���ǽð�
	int lectureCode;				// �����ڵ�
	int limitedNum;					// �����ο�	
	int studentCnt;					// �л� ��
	int student[MAXLIMITED];		// �л�ID   
	char* lectureName;				// �����̸�
	char* lecturer;					// ��米����
	char* lectureRoom;				// ���ǽ�
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