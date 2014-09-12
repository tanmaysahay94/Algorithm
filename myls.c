#define _GNU_SOURCE
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <signal.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/syscall.h>
#include <stdlib.h>
#include <stdio.h>

#define error_handling(msg) do {perror(msg); exit(EXIT_FAILURE);} while(0)
#define BUF_SIZE 1024*1024*5

struct directory_entry
{
	long dirInode;
	off_t offset;
	unsigned short dirLen;
	char dirName[];
};

void my_strcat(char *a, char *b)
{
	while (*a) a++;
	while (*a++ = *b++);
}

int my_strlen(char* string)
{
	char *copy = string;
	int len = 0;
	while (*copy)
	{
		copy++;
		len++;
	}
	return len;
}

int write_wrapper(char* string)
{
	int len = my_strlen(string);
	if (syscall(SYS_write, STDOUT_FILENO, string, len) != len)
	{
		syscall(SYS_write, STDERR_FILENO, "ERROR WHILE WRITING\n", 32);
		return -1;
	}
	return 0;
}

char* my_itoa(long long val, char* d, int base)
{
	char const digits[] = "0123456789ABCDEF";
	char *t = d;
	long long shift = val;
	if (val < 0)
	{
		*t++ = '-';
		val *= -1;
	}
	do
	{
		t++;
		shift /= base;
	} while(shift);
	*t = '\0';
	do
	{
		*--t = digits[val % base];
		val /= base;
	} while(val);
	return d;
}

void get_ugid(char* id, int flag)
{
	char fileToAccess[1000] = "";
	if (!flag)
		my_strcat(fileToAccess, "/etc/passwd");
	else
		my_strcat(fileToAccess, "/etc/group");
	int i, j, k, count;
	int colon[1000];
	int charCount, length = my_strlen(id);
	int fd, read_limit;
	char buffer[1025];
	char toReturn[100];
	fd = open(fileToAccess, O_RDONLY);
	if (fd == -1)
		error_handling("open");
	else
	{
		while (read(fd, &buffer, 1024) != 0)
		{
			read_limit = my_strlen(buffer) < 1024 ? my_strlen(buffer) : 1024;
			char line[1024];
			count = 0;
			int lineLen = 0;
			for (i = 0; i < read_limit; i++)
			{
				if (buffer[i] == '\n')
				{
					line[lineLen++] = '\0';
					lineLen = 0;
					for (j = 0; line[j]; j++)
						if (line[j] == ':')
							colon[count++] = j;
					for (j = 0; j < count; j++)
						if (colon[j + 1] - colon[j] == length + 1)
						{
							charCount = 0;
							for (k = colon[j] + 1; k < colon[j + 1]; k++)
								if (line[k] == *(id + k - colon[j] - 1))
									charCount++;
							if (charCount == length)
								break;
						}
					count = 0;
					if (charCount == length)
					{
						for (j = 0; line[j] != ':'; j++)
							toReturn[j] = line[j];
						toReturn[j] = '\0';
						write_wrapper(toReturn);
						return;
					}
				}
				else
					line[lineLen++] = buffer[i];
			}
		}
	}
}

void my_get_time(long long t)
{
	t += 5.5 * (3600);
	long long sec_in_day = 86400;
	long long sec_in_year = 86400 * 365;
	long long sec_in_leap = 86400 * 366;
	long long sec_in_four = 3 * sec_in_year + sec_in_leap;
	long long base_year = 1970;
	int day, is_leap = 0;
	int month[12] = {0};
	int hour = (t % 86400)/3600, min = ((t % 86400) % 3600) / 60;
	base_year += 4 * (t / sec_in_four);
	t %= sec_in_four;
	if (t > sec_in_year && t <= 2 * sec_in_year) 
	{
		base_year += 1;
		t -= sec_in_year;
	}
	else if (t > 2 * sec_in_year && t <= 2 * sec_in_year + sec_in_leap)
	{
		base_year += 2;
		is_leap = 1;
		t -= 2 * sec_in_year;
	} 
	else if (t > 2 * sec_in_year + sec_in_leap && t <= sec_in_four)
	{
		base_year += 3;
		t -= 2 * sec_in_year + sec_in_leap;
	}
	if (is_leap)
	{
		if (t <= 31 * sec_in_day)
		{
			month[0] = 1;
			day = t / sec_in_day + 1 * (t % sec_in_day != 0);
		}
		else if (t <= 60 * sec_in_day)
		{
			month[1] = 1;
			day = t / sec_in_day + 1 * (t % sec_in_day != 0);
			day -= 31;
		}
		else if (t <= 91 * sec_in_day)
		{
			month[2] = 1;
			day = t / sec_in_day + 1 * (t % sec_in_day != 0);
			day -= 60;
		}
		else if (t <= 121 * sec_in_day)
		{
			month[3] = 1;
			day = t / sec_in_day + 1 * (t % sec_in_day != 0);
			day -= 91;
		}
		else if (t <= 152 * sec_in_day)
		{
			month[4] = 1;
			day = t / sec_in_day + 1 * (t % sec_in_day != 0);
			day -= 121;
		}
		else if (t <= 182 * sec_in_day)
		{
			month[5] = 1;
			day = t / sec_in_day + 1 * (t % sec_in_day != 0);
			day -= 152;
		}
		else if (t <= 213 * sec_in_day)
		{
			month[6] = 1;
			day = t / sec_in_day + 1 * (t % sec_in_day != 0);
			day -= 182;
		}
		else if (t <= 244 * sec_in_day)
		{
			month[7] = 1;
			day = t / sec_in_day + 1 * (t % sec_in_day != 0);
			day -= 213;
		}
		else if (t <= 274 * sec_in_day)
		{
			month[8] = 1;
			day = t / sec_in_day + 1 * (t % sec_in_day != 0);
			day -= 244;
		}
		else if (t <= 305 * sec_in_day)
		{
			month[9] = 1;
			day = t / sec_in_day + 1 * (t % sec_in_day != 0);
			day -= 274;
		}
		else if (t <= 335 * sec_in_day)
		{
			month[10] = 1;
			day = t / sec_in_day + 1 * (t % sec_in_day != 0);
			day -= 305;
		}
		else
		{
			month[11] = 1;
			day = t / sec_in_day + 1 * (t % sec_in_day != 0);
			day -= 335;
		}
	}
	else
	{
		if (t <= 31 * sec_in_day)
		{
			month[0] = 1;
			day = t / sec_in_day + 1 * (t % sec_in_day != 0);
		}
		else if (t <= 59 * sec_in_day)
		{
			month[1] = 1;
			day = t / sec_in_day + 1 * (t % sec_in_day != 0);
			day -= 31;
		}
		else if (t <= 90 * sec_in_day)
		{
			month[2] = 1;
			day = t / sec_in_day + 1 * (t % sec_in_day != 0);
			day -= 59;
		}
		else if (t <= 120 * sec_in_day)
		{
			month[3] = 1;
			day = t / sec_in_day + 1 * (t % sec_in_day != 0);
			day -= 90;
		}
		else if (t <= 151 * sec_in_day)
		{
			month[4] = 1;
			day = t / sec_in_day + 1 * (t % sec_in_day != 0);
			day -= 120;
		}
		else if (t <= 181 * sec_in_day)
		{
			month[5] = 1;
			day = t / sec_in_day + 1 * (t % sec_in_day != 0);
			day -= 151;
		}
		else if (t <= 212 * sec_in_day)
		{
			month[6] = 1;
			day = t / sec_in_day + 1 * (t % sec_in_day != 0);
			day -= 181;
		}
		else if (t <= 243 * sec_in_day)
		{
			month[7] = 1;
			day = t / sec_in_day + 1 * (t % sec_in_day != 0);
			day -= 212;
		}
		else if (t <= 273 * sec_in_day)
		{
			month[8] = 1;
			day = t / sec_in_day + 1 * (t % sec_in_day != 0);
			day -= 243;
		}
		else if (t <= 304 * sec_in_day)
		{
			month[9] = 1;
			day = t / sec_in_day + 1 * (t % sec_in_day != 0);
			day -= 273;
		}
		else if (t <= 334 * sec_in_day)
		{
			month[10] = 1;
			day = t / sec_in_day + 1 * (t % sec_in_day != 0);
			day -= 304;
		}
		else
		{
			month[11] = 1;
			day = t / sec_in_day + 1 * (t % sec_in_day != 0);
			day -= 334;
		}
	}
	if (month[0]) write_wrapper("Jan");
	else if (month[1]) write_wrapper("Feb");
	else if (month[2]) write_wrapper("Mar");
	else if (month[3]) write_wrapper("Apr");
	else if (month[4]) write_wrapper("May");
	else if (month[5]) write_wrapper("Jun");
	else if (month[6]) write_wrapper("Jul");
	else if (month[7]) write_wrapper("Aug");
	else if (month[8]) write_wrapper("Sep");
	else if (month[9]) write_wrapper("Oct");
	else if (month[10]) write_wrapper("Nov");
	else write_wrapper("Dec");
	write_wrapper("  ");
	char toShow[10];
	write_wrapper(my_itoa((long long) day, toShow, 10));
	write_wrapper(" ");
	my_itoa((long long) hour, toShow, 10);
	if (my_strlen(toShow) == 1)
		write_wrapper("0");
	write_wrapper(toShow);
	write_wrapper(":");
	my_itoa((long long) min, toShow, 10);
	if (my_strlen(toShow) == 1)
		write_wrapper("0");
	write_wrapper(toShow);
	write_wrapper(" ");
}

void my_show_size(long long sz)
{
	long long kb = 1024;
	char magnitude[3] = "";
	long long decimal;
	if (sz > kb * kb *kb)
	{
		my_strcat(magnitude, "G");
		decimal = sz % (kb * kb * kb);
		sz /= (kb * kb * kb);
	}
	else if (sz > kb * kb)
	{
		my_strcat(magnitude, "M");
		decimal = sz % (kb * kb);
		sz /= (kb * kb);
	}
	else if (sz > kb)
	{
		my_strcat(magnitude, "K");
		decimal = sz % kb;
		sz /= kb;
	}
	while (decimal > 10)
		decimal /= 10;
	char printSize[100];
	char decimalPortion[100];
	my_itoa((long long) sz, printSize, 10);
	my_itoa((long long) decimal, decimalPortion, 10);
	write_wrapper(printSize);
	if (sz < 10)
	{
		write_wrapper(".");
		write_wrapper(decimalPortion);
	}
	write_wrapper(magnitude);
}

void list_flag(char *directory, int hidden, int human_readable)
{
	struct stat details;
	char toPrint[20];
	if (syscall(SYS_lstat, directory, &details) == -1)
		exit(EXIT_FAILURE);
	if (details.st_mode & S_IFMT == S_IFDIR)
		write_wrapper("d");
	else if (S_ISLNK(details.st_mode))
		write_wrapper("l");
	else
		write_wrapper("-");
	my_itoa((long long) details.st_mode, toPrint, 8);
	char status[10];
	int perm[3];
	int i, j, len = my_strlen(toPrint);
	for (i = len - 1; i >= len - 3; i--)
		perm[2 - (len - 1 - i)] = toPrint[i] - '0';
	for (i = 0; i < 3; i++)
	{
		if (perm[i] == 0)
		{
			status[3 * i] = '-';
			status[3 * i + 1] = '-';
			status[3 * i + 2] = '-';
		}
		else if (perm[i] == 1)
		{
			status[3 * i] = '-';
			status[3 * i + 1] = '-';
			status[3 * i + 2] = 'x';
		}
		else if (perm[i] == 2)
		{
			status[3 * i] = '-';
			status[3 * i + 1] = 'w';
			status[3 * i + 2] = '-';
		}
		else if (perm[i] == 3)
		{
			status[3 * i] = '-';
			status[3 * i + 1] = 'w';
			status[3 * i + 2] = 'x';
		}
		else if (perm[i] == 4)
		{
			status[3 * i] = 'r';
			status[3 * i + 1] = '-';
			status[3 * i + 2] = '-';
		}
		else if (perm[i] == 5)
		{
			status[3 * i] = 'r';
			status[3 * i + 1] = '-';
			status[3 * i + 2] = 'x';
		}
		else if (perm[i] == 6)
		{
			status[3 * i] = 'r';
			status[3 * i + 1] = 'w';
			status[3 * i + 2] = '-';
		}
		else if (perm[i] == 7)
		{
			status[3 * i] = 'r';
			status[3 * i + 1] = 'w';
			status[3 * i + 2] = 'x';
		}
	}
	double size;
	status[9] = '\0';
	write_wrapper(status);
	write_wrapper(" ");
	write_wrapper(my_itoa((long long) details.st_nlink, toPrint, 8));
	write_wrapper(" ");
	my_itoa((long long) details.st_uid, toPrint, 10);
	get_ugid(toPrint, 0);
	write_wrapper(" ");
//	my_itoa((long long) details.st_gid, toPrint, 10);
	get_ugid(toPrint, 0);
	write_wrapper(" ");
	if (!human_readable)
		write_wrapper(my_itoa((long long) details.st_size, toPrint, 10));
	else
		my_show_size(details.st_size);
	write_wrapper("    ");
	my_get_time(details.st_mtime);
	len = my_strlen(directory);
	for (i = len - 1; i >= 0; i--)
		if (directory[i] == '/')
			break;
	i++;
	directory += i;
	write_wrapper(directory);
	write_wrapper("\n");
}

void ls(char *directory, int list, int hidden, int human_readable)
{
	int fd, nread, bufferPosition;
	char buffer[BUF_SIZE], dirType;
	struct directory_entry *d;
	fd = open(directory, O_RDONLY | O_DIRECTORY);
	if (fd == -1)
		error_handling("open");
	while (1) 
	{
		nread = syscall(SYS_getdents, fd, buffer, BUF_SIZE);
		if (nread == -1)
			error_handling("getdents");
		if (nread == 0)
			break;
		for (bufferPosition = 0; bufferPosition < nread;) 
		{
			d = (struct directory_entry *) (buffer + bufferPosition);
			bufferPosition += d->dirLen;
			if( d->dirInode != 0)
			{
				if (!hidden && d->dirName[0] == '.')
					continue;
				if (!list)
				{
					write_wrapper((char *)d->dirName );
					write_wrapper("\n");
				}
				else
				{
					char argToPass[1000]="";
					int i = 0;
					char *t = directory;
					while (*t)
					{
						argToPass[i++] = *t;
						t++;
					}
					my_strcat(argToPass, d->dirName);
					list_flag(argToPass, hidden, human_readable);
				}
			}
		}
	}
	exit(EXIT_SUCCESS);
}

int check(char *dir)
{
	int absolute_path = 0;
	int len = my_strlen(dir);
	if (len < 4)
		absolute_path = 0;
	else
	{
		if (*(dir) == '/' && *(dir + 1) == 'h' && *(dir + 2) == 'o' && *(dir + 3) == 'm' && *(dir + 4) == 'e')
				absolute_path = 1;
		else if (*(dir) == 'h' && *(dir + 1) == 'o' && *(dir + 2) == 'm' && *(dir + 3) == 'e')
				absolute_path = 1;
	}
	return absolute_path;
}

int main(int argc, char** argv)
{
	int i, j, list, hidden, human_readable;
	int limit = argc < 4 ? argc : 3;
	char curr, *dir = ".";
	list = hidden = human_readable = 0;
	for (i = 1; i < limit; i++)
		if (argv[i][0] == '-')
			for (j = 0; argv[i][j]; j++)
			{
				curr = argv[i][j];
				if (!list) list = (curr == 'l');
				if (!hidden) hidden = (curr == 'a');
				if (!human_readable) human_readable = (curr == 'h');
			}
		else
			dir = argv[i];
	char cwd[1024];
	if (!check(dir))
	{
		getcwd(cwd, 1024);
		my_strcat(cwd, "/");
		my_strcat(cwd, dir);
		my_strcat(cwd, "/");
	}
	else
	{
		i = 0;
		cwd[i++] = '/';
		char *t = dir;
		while (*t)
		{
			cwd[i++] = *t;
			t++;
		}
		cwd[i++] = '/';
	}
	ls(cwd, list, hidden, human_readable);
	return 0;
}
