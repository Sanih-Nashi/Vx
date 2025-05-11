#pragma once

#define MAX_INPUT 1024

#include <string>
#include <vector>

inline char* User;
inline char CWD[MAX_INPUT];

void InitTermianal();
void PrintPrompt();
void ReadInput(char* Input, const int& Length);
std::vector<std::string> Parse(char* Input);
void execute();
