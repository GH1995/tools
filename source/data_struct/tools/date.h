/*
	只实现了前置++
*/\r/\r/g

class date {
public:
	int year;
	int month;
	int day;

	date(int y, int m, int d) : year(y), month(m), day(d) {};

	bool isyear(int year)
	{
		return year % 100 != 0 && year % 4 == 0 || year % 400 == 0;
	}

	date& operator ++ ()
	{
		day++;
		if (day > dayofmonth[isyear(year)][month])
		{
			day = 1;
			month++;
		}

		if (month > 12)
		{
			month = 1;
			year++;
		}

		return *this;
	}
	virtual ~date() {}
};

int dayofmonth[2][13] = {
	0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31,
	0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
};
