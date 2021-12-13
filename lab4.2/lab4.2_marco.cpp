#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <algorithm>
using namespace std;

int show_tasks();
string file_format(string file_path_full);
string file_name(string file_path_full);
string file_path(string file_path_full);
string file_name_change(string file_path_full, string file_new_name);
bool file_copy(string file_path_full);
char file_disk(string file_path_full);

int main()
{
	setlocale(LC_ALL, "rus");
	string input_line = "";
	string f_name = "";
	while (true)
	{
		switch (show_tasks())
		{
		case 0:
			return 0;
			break;

		case 1:
			system("cls");
			cout << "Enter your filepath: ";
			cin >> input_line;
			cout << "File format: " << file_format(input_line) << endl;
			system("pause");
			system("cls");
			break;

		case 2:
			system("cls");
			cout << "Enter your filepath: ";
			cin >> input_line;
			cout << "File name: " << file_name(input_line) << endl;
			system("pause");
			system("cls");
			break;

		case 3:
			system("cls");
			cout << "Enter your filepath: ";
			cin >> input_line;
			cout << "Your path: " << file_path(input_line) << endl;
			system("pause");
			system("cls");
			break;
		case 4:
			system("cls");
			cout << "Enter your filepath: ";
			cin >> input_line;
			cout << "Your disk is " << file_disk(input_line) << ":" << endl;
			system("pause");
			system("cls");
			break;
		case 5:
			system("cls");
			cout << "Enter your filepath: ";
			cin >> input_line;
			cout << "Enter new file name: ";
			cin >> f_name;
			cout << "New file name: " << file_name_change(input_line, f_name) << endl;
			system("pause");
			system("cls");
			break;
		case 6:
			system("cls");
			cout << "Enter your filepath: ";
			cin >> input_line;
			if (file_copy(input_line))
				cout << "Success." << endl;
			else
				cout << "Cannot open." << endl;
			system("pause");
			system("cls");
			break;
		}
	}
	return 0;
}

bool file_copy(string file_path_full)
{
	string buffer;
	ofstream fblank;
	fblank.open(file_path_full);
	if (!fblank.is_open())
	{
		return false;
	}
	else
	{
		fblank << "test string\n";
		cout << "Blank file is created.\n";
		fblank.close();
	}

	ifstream source_file;
	source_file.open(file_path_full);
	string new_file_path = file_path(file_path_full) + file_name(file_path_full) + "_copy" + file_format(file_path_full);

	ofstream fout;
	fout.open(new_file_path);
	for (source_file >> buffer; !source_file.eof(); source_file >> buffer)
	{
		fout << buffer;
		fout << " ";
	}
	fout.close();
	return true;
}

int show_tasks()
{
	int c;
	system("cls");
	cout << "Task 1), file format output.\n"; //done
	cout << "Task 2), file name output.\n";	  //done
	cout << "Task 3), file path output.\n";	  //done
	cout << "Task 4), file disk output.\n";	  //done
	cout << "Task 5), file rename.\n";		  //done
	cout << "Task 6), file copy.\n";		  //done
	cout << "Task 0), exit.\n";				  //done
	cout << "Choose option: ";
	cin >> c;
	return c;
}

string file_format(string file_path_full)
{
	string f_format = "";
	bool f_format_check = false;
	for (int i = 0; i < file_path_full.length(); i++)
	{
		if (file_path_full[i] == '.' and f_format_check == false)
		{
			f_format_check = true;
		}
		if (f_format_check)
		{
			f_format += file_path_full[i];
		}
	}
	return f_format;
}

string file_name(string file_path_full)
{
	string f_name = "";
	int i = 0;
	while (file_path_full[i] != '.')
	{
		i++;
	}
	while (file_path_full[i] != '/')
	{
		i--;
	}
	i++;
	while (file_path_full[i] != '.')
	{
		f_name += file_path_full[i];
		i++;
	}
	return f_name;
}

string file_path(string file_path_full)
{
	string f_path = "";
	int i = 0;
	while (file_path_full[i] != '.')
	{
		i++;
	}
	while (file_path_full[i] != '/')
	{
		i--;
	}
	for (int j = 0; j < i; j++)
	{
		f_path += file_path_full[j];
	}
	f_path += "/";
	return f_path;
}
char file_disk(string file_path_full)
{
	return file_path_full[0];
}

string file_name_change(string file_path_full, string file_new_name)
{
	string f_name = "";
	int i = 0;
	while (file_path_full[i] != '.')
	{
		i++;
	}
	while (file_path_full[i] != '/')
	{
		i--;
	}
	i++;
	while (file_path_full[i] != '.')
	{
		f_name += file_path_full[i];
		i++;
	}
	file_path_full.replace(file_path_full.find(f_name), f_name.length(), file_new_name);
	return file_path_full;
}