#pragma once

enum PRIORITY { LOW, MEDIUM, HIGH, MEGAHIGH };

template<class T>
class MyData
{
public:
	T value;
	MyData* next = nullptr;
	PRIORITY pri = LOW;

	MyData() {}
};