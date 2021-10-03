#include <stdio.h>
#include <vector>
#include <string>
#include <Windows.h> // for GetTickCount
#include "GameObject.h"

std::string testName;
long beginTime;

LARGE_INTEGER HighPerformanceFreq;

void InitTime()
{
	QueryPerformanceFrequency(&HighPerformanceFreq);
}

long GetTime()
{
	LARGE_INTEGER nTime;
	BOOL queriedOK = QueryPerformanceCounter(&nTime);
	return (long)((nTime.QuadPart) * 1000 / HighPerformanceFreq.QuadPart);
}

void BeginTest(const std::string& name)
{
	testName = name;
	beginTime = GetTime();
}

void EndTest()
{
	int milliseconds = (int)(GetTime() - beginTime);
	char log[512];
	sprintf(log, "Run test %s %d ms\n", testName.c_str(), milliseconds);
	printf(log);
}

void main()
{
	InitTime();

	std::vector<GameObject*> gameObjects;

	for (int i = 0; i < 30000; i++)
		gameObjects.push_back(new GameObject());

	BeginTest("[UNITY++ CODE STYLE]");
	for (GameObject* obj : gameObjects)
		obj->Update();
	EndTest();


	for (GameObject* obj : gameObjects)
		obj->InitUnirx();

	BeginTest("[UNIRX++ CODE STYLE]");
	for (GameObject* obj : gameObjects)
		obj->UpdateUnirx();
	EndTest();

	for (GameObject* obj : gameObjects)
		delete obj;
}