//XMLParser.h

enum EntityType {
	content = 0,
	startTag,
	endTag
};

struct XMLParserListener {
	void (* beganTag)(const char *);
	void (* endedTag)(const char *);
	void (* parsedContent)(const char *);
};

typedef struct XMLParserListener XMLParserListener;


void parseXML(const char *xmlString, XMLParserListener *listener);
