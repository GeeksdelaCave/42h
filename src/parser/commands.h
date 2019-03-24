#ifndef COMMANDS_H
#define COMMANDS_H
int read_word(struct parser_s *p);
int read_do_group(struct parser_s *p);
int read_compound_list(struct parser_s *p);
int read_case_clause(struct parser_s *p);
int read_case_item(struct parser_s *p);
int read_spacing(struct parser_s *p);
int read_EndOfLine(struct parser_s *p);
int read_spaces(struct parser_s *p);
int read_word_in_for(struct parser_s *p);
#endif
