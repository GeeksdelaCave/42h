/**
 ** \file ast.h
 ** \brief COMMAND_H declaration file
 */
#ifndef COMMANDS_H
#define COMMANDS_H
 /**
 ** \fn int read_word(struct parser_s *p)
 **/
int read_word(struct parser_s *p);
/**
 ** \fn int read_do_group(struct parser_s *p)
 **/
int read_do_group(struct parser_s *p);
/**
 ** \fn int read_compound_list(struct parser_s *p)
 **/
int read_compound_list(struct parser_s *p);
/**
 ** \fn int read_case_clause(struct parser_s *p)
 **/
int read_case_clause(struct parser_s *p);
/**
 ** \fn int read_case_item(struct parser_s *p)
 **/
int read_case_item(struct parser_s *p);
/**
 ** \fn int read_spacing(struct parser_s *p)
 **/
int read_spacing(struct parser_s *p);
/**
 ** \fn int read_EndOfLine(struct parser_s *p)
 **/
int read_EndOfLine(struct parser_s *p);
/**
 ** \fn int read_spaces(struct parser_s *p)
 **/
int read_spaces(struct parser_s *p);

#endif
