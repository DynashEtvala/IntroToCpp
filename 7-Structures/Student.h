#pragma once

struct student
{
	int id;
	int course;
	int lastExam;
};

void printStudent(student stu);
void studentAnalytics(student stu[], int course);