// Lecture Ŭ���� �������

#ifndef __LECTURE_H__
#define __LECTURE_H__

#define MAXLIMITED 200

class Lecture
{
private:
	int lectureCode;				// �����ڵ�
	int limitedNum;					// �����ο�	
	int studentCnt;					// �л� ��
	int student[MAXLIMITED];		// �л�ID
	char* lectureTime;				// ���ǽð�
	char* lectureName;				// �����̸�
	char* lecturer;					// ��米����
	char* lectureRoom;				// ���ǽ�
public:
	Lecture(const char* name, const char* lecturer, const char* room, int code, char* time, int limited);
	Lecture(Lecture& ref);
	char* GetLectureName() const;					// ���Ǹ� ��ȯ
	int GetLectureCode() const;						// �����ڵ� ��ȯ
	char* GetLecturer() const;						// ������ ��ȯ
	int* GetStudentID();							// �л� �迭 ��ȯ
	int GetStudentCnt() const;
	void ChangeLectureTime(char* changedtime);		
	void ChangeLectureCode(int changedcode);
	void ChangeLimitedNum(int changedlimited);
	void ChangeLectureName(char* changedname);
	void ChangeLecturer(char* changedlecturer);
	void ChangeLectureRoom(char* changedroom);		// ���� ���� 
	bool AddStudent(int studentId);					// �л��߰� (�л��� ������û�� �� �Ҹ� �Լ�) �����ο��� �ѱ�� false��ȯ �ȳѱ�� true ��ȯ
	void LectureAllInfoPrint() const;				// ���� ���� ���
	~Lecture();
};

#endif