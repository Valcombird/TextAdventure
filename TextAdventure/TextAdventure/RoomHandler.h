#pragma once
#include <string>
class RoomHandler
{
public:
	RoomHandler();
	~RoomHandler();
	void search(int i);
	void moveOn(int i);
	void room();
	std::string theAnswer;
	std::string& answerRef = theAnswer;
	//void roomOptions();
};

