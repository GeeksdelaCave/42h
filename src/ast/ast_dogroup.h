/**
 ** \file ast_dogroup.h
 ** \brief Declaration file ast do group
 */
#ifndef AST_DOGROUP_H
#define AST_DOGROUP_H
 /**
 ** \def struct s_do_group *init_dogroup()
 */
struct s_do_group *init_dogroup();
/**
 ** \def int find_coump(struct parser_s *p, struct s_do_group *dogroup)
 */
int find_coump(struct parser_s *p, struct s_do_group *dogroup);
#endif