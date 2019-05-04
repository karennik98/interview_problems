#include "Duplicate.h"

Duplicate::Duplicate(std::string file_name)
{
	m_stream.open(file_name);
}

void Duplicate::open(std::string file_name)
{
	if (!m_stream.is_open())
	{
		m_stream.open(file_name);
		fill_table();
	}
	else
	{
		fill_table();
	}
}

bool Duplicate::is_english_font(char ch)
{
    size_t ascii_value = static_cast<int>(ch);
    return ((ascii_value > 64 && ascii_value < 91)  || (ascii_value > 96 && ascii_value < 123 ));
}

void Duplicate::fill_table()
{
	std::string str;
	while (!m_stream.eof())
	{
		m_stream >> str;
        if(!is_english_font(str[str.size()-1]))
        {
            str.erase(str.size()-1, 1);
        }
		if (m_data.find(str) != m_data.end())
		{
			m_data[str]++;
		}
		else
		{
			m_data[str] = 1;
		}
	}
}

std::vector<std::string> Duplicate::find_dublicate()
{
	std::map<std::string, size_t>::iterator iter;
	std::vector<std::string> duplicate_words;
	for (iter = m_data.begin(); iter != m_data.end(); iter++)
	{
		if (iter->second > 1)
		{
			duplicate_words.push_back(iter->first);
		}
	}
	return duplicate_words;
}

size_t Duplicate::count()
{
	size_t count = 0;
	std::map<std::string, size_t>::iterator iter;
	for (iter = m_data.begin(); iter != m_data.end(); iter++)
	{
		if (iter->second > 1)
		{
			count++;
		}
	}
	return count;
}
