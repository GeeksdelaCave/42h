#ifndef PARSER_READ_H
#define PARSER_READ_H
int parser_readchar(struct parser_s *p, char c);
int parser_readtext(struct parser_s *p, char *text);
int parser_readrange(struct parser_s *p, char begin, char end);
int parser_readinset(struct parser_s *p, char *set);
int parser_readoutset(struct parser_s *p, char *set);
int parser_readalpha(struct parser_s *p);
int parser_readnum(struct parser_s *p);
int parser_var(struct parser_s *p);
int parser_readidentifier(struct parser_s *p);
int parser_readinteger(struct parser_s *p);
#endif
