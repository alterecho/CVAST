#include <string.h>
#include <stdio.h>
#include <stdlib.h>

enum EntityType {
	content = 0,
	startTag,
	endTag
};

void parseXML(const char *xmlString) {
	size_t length = strlen(xmlString);
	char c_prev = '0';
	char *string = NULL;
	enum EntityType entityType = content;
	size_t currentEntityCount = 0;
	for (int i = 0; i < length; i++) {
		const char c = xmlString[i];

		if (c == '<') {
			printf("\ncontent: %s\n", string);
			entityType = startTag;
			free(string);
			currentEntityCount = 0;
			string = NULL;
		} else if (c == '>') {
			if (entityType == endTag) {
				printf("\nendtag: %s\n", string);
			} else {
				printf("\nstarttag: %s\n", string);
			}
			
			entityType = content;
			free(string);
			string = NULL;
			currentEntityCount = 0;
		} else if (c == '/' && c_prev == '<') {
			entityType = endTag;
		} else {
			currentEntityCount++;
		
			size_t charCount_new = sizeof(char) * 2;
			if (string != NULL) {
				charCount_new = (strlen(string) + 2) * sizeof(char);
			}		
			string = (char *)realloc(string, charCount_new);
			string[charCount_new - 2] = c;
			string[charCount_new - 1] = '\0';
			
		}

		c_prev = c;
      	}
}	
