#include<stdio.h>
#include<string.h>
#include<iostream>

/* merges 2 sorted strings into the result character array such that 
 * the result is sorted */
int merge_strings(std::string str1, std::string str2, char result[])
{
	int index_1 = 0;
	int index_2 = 0;
	int index_result = 0;
	int size_str1 = str1.length();
	int size_str2 = str2.length();
	while(index_1 < size_str1 || index_2 < size_str2)
	{
		if(index_1 == size_str1)
		{
			result[index_result] = str2[index_2];
			index_2 ++;
		}
		else
		{
			if(index_2 == size_str2)
			{
				result[index_result] = str1[index_1];
				index_1 ++;
			}
			else
			{
				if (str1[index_1] < str2[index_2])
				{
					result[index_result] = str1[index_1];
					index_1 ++;
				}
				else
				{
					result[index_result] = str2[index_2];
					index_2 ++;
				}
			}
		}
		index_result ++;
	}
	result[size_str1 + size_str2] = '\0';
	return 0;
}	

/* recieves 2 sorted strings and merges them into a combined sorted string and  
 * prints the result
 * note: doesn't support white space in the input strings*/
int create_merged_string()
{
	std::string str1, str2;
	std::cout << "enter first sorted string" << std::endl;
	std::cin >> str1;
	std::cout << "enter second sorted string" << std::endl;
	std::cin >> str2;
	char result[str1.length() + str2.length() + 1];
	merge_strings(str1, str2, result);
	std::string str_result = result;
	std::cout << "the merged sorted string is:" << str_result << std::endl;
	return 0;
}

// calls create_merged_string()
int main()
{
	create_merged_string();
	return 0;
}
