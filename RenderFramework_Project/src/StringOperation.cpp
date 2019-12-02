#include "StringOperation.h"
#pragma warning( disable : 5045 )
char* copyString(const char* str)
{
	char* ret = new char[strlen(str) + 1];
	memcpy(ret, str, strlen(str) * sizeof(char));
	ret[strlen(str)] = '\0';
	return ret;
}
char* AddString(const char* str1, const char* str2)
{
	unsigned int totalLength = strlen(str1) + strlen(str2) + 1;
	char* ret = new char[totalLength];
	for (unsigned int i = 0; i < strlen(str1); i++) {
		ret[i] = str1[i];
	}
	for (unsigned int i = 0; i < strlen(str2); i++) {
		ret[i + strlen(str1)] = str2[i];
	}
	ret[totalLength - 1] = '\0';
	/*strcpy_s(ret, strlen(ret), str1);
	strcat_s(ret, strlen(ret) + strlen(str2) + 1, str2);*/
	return ret;
}
char* RemoveExt(const char* str)
{
	unsigned int strLen = strlen(str);
	char* ret = nullptr;
	unsigned int modelNameLength = 0;
	for (int i = (int)(strLen - 1); i >= 0; i--) {
		if (str[i] == '.') {
			modelNameLength = (unsigned int)i;
			break;
		}
	}
	assert(modelNameLength >= 1);
	ret = new char[modelNameLength + (unsigned int)1];
	for (unsigned int i = 0; i < modelNameLength; i++) {
		ret[i] = str[i];
	}
	ret[modelNameLength] = '\0';
	return ret;
}
char* Substring(const char* str, unsigned int start, unsigned int end)
{
	unsigned int retLen = end - start + 1;
	char* ret = new char[retLen + 1];
	for (unsigned int i = 1; i < strlen(str); i++) {
		ret[i - 1] = str[i];
	}
	ret[retLen] = '\0';
	return ret;
}