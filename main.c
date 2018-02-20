#include <stdio.h>
#include "XMLParser.h"

int main(int argc, const char **argv) {
	
	if (argc < 2) {
		printf("no parameters\n");
		return 1;
	}

	for (int i = 0; i < argc; i++) {
		const char *arg = argv[i];
	//	printf("\narg[%d]: %s", i, arg);
	}
	const char *xmlString = argv[1];//"<xml></xml>";
	parseXML(xmlString);
	printf("\n");
	return 0;
}
