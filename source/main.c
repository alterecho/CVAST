#include <stdio.h>
#include "XMLParser.h"



void XMLParserBeganTag(const char *);
void XMLParserEndedTag(const char *);
void XMLParserParsedContent(const char *);

int main(int argc, const char **argv) {
	
	if (argc < 2) {
		printf("no parameters\n");
		//return 1;
	}

	for (int i = 0; i < argc; i++) {
		const char *arg = argv[i];
	//	printf("\narg[%d]: %s", i, arg);
	}
//	const char *xmlString = argv[1];//	
	const char *xmlString = "<xml>here lies the content!</xml>";

	XMLParserListener listener;
	listener.beganTag = &XMLParserBeganTag;
        listener.endedTag = &XMLParserEndedTag;
	listener.parsedContent = &XMLParserParsedContent;	

	parseXML(xmlString, &listener);
	printf("\n");
	return 0;
}




/* XMLParser */

void XMLParserBeganTag(const char *tag) {
	printf("\nbeganTag: %s", tag);
}

void XMLParserEndedTag(const char *tag) {
	printf("\nendedTag: %s", tag);
}

void XMLParserParsedContent(const char *contentString) {
	printf("\nparsedContent:\n%s", contentString);
}


