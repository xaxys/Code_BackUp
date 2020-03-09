#define _AFXDLL
#include <tchar.h>
#include <afx.h>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <io.h>
using namespace std;

inline char* AddExtension(const char* name, const char* extension) {
	char tmp[260];
	memset(tmp, 0, sizeof(tmp));
	strcpy(tmp, name);
	strcat(tmp, extension);
	return tmp;
}

int main() {
	char path[260];
	cin >> path;
	int start = clock();
	intptr_t handle;
	_finddata_t findData;

	handle = _findfirst(AddExtension(path, "\*.*"), &findData); // 查找目录中的第一个文件
	if (handle == -1) cout << "Failed to find first file" << endl;
	else {
		do {
			if (findData.attrib & _A_SUBDIR
				&& strcmp(findData.name, ".")
				&& strcmp(findData.name, "..")
				) {    // 是否是子目录并且不为"."或".."
				cout << "<DIR> " << findData.name << endl;
			}
			else {
				cout << findData.name << " " << findData.size << endl;
				char tmp[255];
				memset(tmp, 0, sizeof(tmp));
				strcpy(tmp, path);
				tmp[strlen(tmp)] = '\\';
				strcat(tmp, findData.name);
				//cout << "[INFO]" << CString(tmp) << " " << SetFileAttributes(CString(tmp), FILE_ATTRIBUTE_NORMAL) << endl;
			}
		} while (_findnext(handle, &findData) == 0);    // 查找目录中的下一个文件
	}

	_findclose(handle);    // 关闭搜索句柄w
	
	printf("Time: %.3lf s\n", double(clock() - start) / CLOCKS_PER_SEC);
}