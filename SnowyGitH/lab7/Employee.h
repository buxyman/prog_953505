#pragma once

typedef struct dateOfBirth
{
	int day;
	int month;
	int year;
}DateOfBirth;

typedef struct enrollmentDate
{
	int day;
	int month;
	int year;
}EnrollmentDate;

typedef struct education
{
	char* degree;
}Education;

typedef struct socialSecurityCard
{
	int cardNumber;
}SocialSecurityCard;

typedef struct passport
{
	int passportNumber;
	int issueDay;
	int issueMonth;
	int issueYear;
	int expiryDay;
	int expiryMonth;
	int expiryYear;
	char* nationality;
}Passport;

typedef struct notes
{
	char* encouragement;
	char* penalties;
}Notes;

typedef struct employee
{
	char* firstName; 
	char* lastName;
	DateOfBirth dateOfBirth;
	Passport passport;
	SocialSecurityCard socialSecurityCard;
	Education education;
	char* position;
	int salary;
	EnrollmentDate enrollmentDate;
	Notes notes;
	char* status;
}Employee;
