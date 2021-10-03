#include <cstdlib>
#include <math.h>
#include <string>

#include "Behavior.h"
#include "GameObject.h"

#define M_PI 3.14159265358979323846

Behavior::Behavior(GameObject* go) :
	gameObject(go),
	state(0)
{
	state = rand() % 2;
}

Behavior::~Behavior()
{

}

void Behavior::Update()
{
	switch (state)
	{
	case 0:
		DoSomeThing0();
		break;
	case 1:
		DoSomeThing1();
		break;
	default:
		break;
	}
}

void Behavior::DoSomeThing0()
{
	double a = sin(M_PI);
	double b = cos(M_PI);
	double r = a * b;

	char result[512];
	char s[64];
	sprintf(s, "%f", r);

	const char* n = "RESULT";
	sprintf(result, "%s%s", n, s);
}

void Behavior::DoSomeThing1()
{
	double a = sin(M_PI);
	double b = cos(M_PI);
	double r = a * b;

	char result[512];
	char s[64];
	sprintf(s, "%f", r);

	const char* n = "RESULT";
	sprintf(result, "%s%s", n, s);
}

void Behavior::InitUnirx()
{
	gameObject->AsObserver()->AddTo(
		[&](GameObject* go)
		{
			return state == 0;
		},
		[](GameObject* go) {
			double a = sin(M_PI);
			double b = cos(M_PI);
			double r = a * b;

			char result[512];
			char s[64];
			sprintf(s, "%f", r);

			const char* n = "RESULT";
			sprintf(result, "%s%s", n, s);
		}, gameObject);


	gameObject->AsObserver()->AddTo(
		[&](GameObject* go)
		{
			return state == 1;
		},
		[](GameObject* go) {
			double a = sin(M_PI);
			double b = cos(M_PI);
			double r = a * b;

			char result[512];
			char s[64];
			sprintf(s, "%f", r);

			const char* n = "RESULT";
			sprintf(result, "%s%s", n, s);
		}, gameObject);
}