/**
 ** \file PARSER_READ
 ** \brief Declaration file PARSER_READ_H
 */
#ifndef PARSER_READ_H
#define PARSER_READ_H
/**
 ** \fn int parser_readchar(struct parser_s *p, char c);
 */
int parser_readchar(struct parser_s *p, char c);
/**
 ** \fn int parser_readtext(struct parser_s *p, char *text);
 */
int parser_readtext(struct parser_s *p, char *text);
/**
 ** \fn int parser_readrange(struct parser_s *p, char begin, char end);
 */
int parser_readrange(struct parser_s *p, char begin, char end);
/**
 ** \fn int parser_readinset(struct parser_s *p, char *set);
 */
int parser_readinset(struct parser_s *p, char *set);
/**
 ** \fn int parser_readoutset(struct parser_s *p, char *set);
 */
int parser_readoutset(struct parser_s *p, char *set);
/**
 ** \fn int parser_readalpha(struct parser_s *p);
 */
int parser_readalpha(struct parser_s *p);
/**
 ** \fn int parser_readnum(struct parser_s *p);
 */
int parser_readnum(struct parser_s *p);
/**
 ** \fn nt parser_var(struct parser_s *p);
 */
int parser_var(struct parser_s *p);
/**
 ** \fn int parser_readidentifier(struct parser_s *p);
 */
int parser_readidentifier(struct parser_s *p);
/**
 ** \fn int parser_readinteger(struct parser_s *p);
 */
int parser_readinteger(struct parser_s *p);
#endif