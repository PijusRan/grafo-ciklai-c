main.exe: main.c node.h config.c config.h graph-cycles.c graph-cycles.h
	gcc main.c node.h config.c config.h graph-cycles.c graph-cycles.h -o main.exe