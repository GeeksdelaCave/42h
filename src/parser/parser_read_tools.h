#ifndef PARSER_READ_TOOLS_H
#define PARSER_READ_TOOLS_H
int read_pipe(struct parser_s *p);
int read_excla(struct parser_s *p);
int read_symbole(struct parser_s *p, char* tag, char* type);
int read_virgule(struct parser_s *p);
int read_and(struct parser_s *p);
int read_Assign(struct parser_s *p);
int parser_eof(struct parser_s *p);
char parser_getchar(struct parser_s *p);
int parser_peekchar(struct parser_s *p, char c);
#endif