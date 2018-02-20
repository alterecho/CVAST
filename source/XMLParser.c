//XMLParser.c

#include "XMLParser.h"

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void parseXML(const char *xmlString, XMLParserListener *listener) {
	size_t length = strlen(xmlString);
	char c_prev = '0';
	char *string = NULL;
	enum EntityType entityType = content;
	size_t currentEntityCount = 0;
	for (int i = 0; i < length; i++) {
		const char c = xmlString[i];
		
		if (c == '<') {
			entityType = startTag;
			
			if (string != NULL) {
				listener->parsedContent(string);
			}

			free(string);
			currentEntityCount = 0;
			string = NULL;
		} else if (c == '>') {
			if (entityType == endTag) {
				if (string != NULL) {
					listener->endedTag(string);
				}
			} else {
				if (string != NULL) {
					listener->beganTag(string);
				}
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
