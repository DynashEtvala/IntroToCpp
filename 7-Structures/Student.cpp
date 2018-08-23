#include<iostream>
#include"Student.h"

void printStudent(student stu)
{
	std::cout << "Student ID: " << stu.id << std::endl;
	std::cout << "Enrolled Course: " << stu.course << std::endl;
	std::cout << "Last Exam Score: " << stu.lastExam << std::endl;
}

void studentAnalytics(student stu[], int size, int course)
{
	float avg = 0;
	for (int i = 0; i < size; i++)
	{
		avg += stu[i].lastExam;
	}
	avg /= size;
	std::cout << "Average Score: " << avg << std::endl;

	for (int i = 0; i < size; i++)
	{
		for (int j = i; j > 0 && stu[j - 1].lastExam > stu[j].lastExam; j--)
		{
			student hold = stu[j - 1];
			stu[j - 1] = stu[j];
			stu[j] = hold;
		}
	}
	std::cout << "Median Score: " << stu[size / 2].lastExam << std::endl;

	int stuInC = 0;
	for (int i = 0; i < size; i++)
	{
		if (stu[i].course == course)
		{
			stuInC++;
		}
	}
	std::cout << "Students In Course " << course << ": " << stuInC << std::endl;
}