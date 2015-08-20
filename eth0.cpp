#include <stdio.h>
int main()
{
	FILE *fp;
	char returnData[64];
	fp = popen("/sbin/ifconfig eth0", "r");

	while (fgets(returnData, 63, fp) != NULL)
	{
		if (returnData[0] == '\n') continue;
		char a[60], b[60];

		strcpy(a, strtok(returnData, " "));

		if (strcmp("inet", a!= 0) continue;


		strcpy(b, strtok(NULL, " "));
		printf("%s: %s\n", a, b);
	}

	pclose(fp);
}
