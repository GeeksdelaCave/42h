#ifndef RULES_H
#define RULES_H

int read_for(struct parser_s *p);
int read_if(struct parser_s *p);
int read_else(struct parser_s *p);
int read_until(struct parser_s *p);
int read_while(struct parser_s *p);
int read_case(struct parser_s *p);
int read_case_clause(struct parser_s *p);
int read_case_item(struct parser_s *p);
#endif