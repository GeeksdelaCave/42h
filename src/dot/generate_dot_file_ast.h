/**
 ** \file  generate_dot_file_ast.h
 */
#ifndef GENERATE_DOT_FILE_AST_H
#define GENERATE_DOT_FILE_AST_H
/**
 ** \fn void print_simple_command(struct s_simple_cmd *simple_cmd, FILE *filen )
 */
void print_simple_command(struct s_simple_cmd *simple_cmd, FILE *filen );
/**
 ** \fn void print_command_ast(struct s_node_command *cmd, FILE *file)
 */
void print_command_ast(struct s_node_command *cmd, FILE *file);
/**
 ** \fn void print_pipeline_to_command_ast(struct s_node_pipeline *pipeline,
 ** FILE *file);
 */
void print_pipeline_to_command_ast(struct s_node_pipeline *pipeline,
				   FILE *file);
/**
 ** \fn void print_and_or_to_pipeline(struct s_node_and_or *and_or, FILE *file);
 */
void print_and_or_to_pipeline(struct s_node_and_or *and_or, FILE *file);
/**
 ** \fn void print_list_to_and_or(struct s_node_list *list, FILE *file);
 */
void print_list_to_and_or(struct s_node_list *list, FILE *file);
/**
 ** \fn void my_print_ast(struct parser_s *p);
 */
void my_print_ast(struct parser_s *p);
/**
 ** \fn void print_compound_list(struct s_do_group *dogroup, FILE *file);
 */
void print_compound_list(struct s_do_group *dogroup, FILE *file);
/**
 ** \fn void print_while_command(struct s_node_while *s_while, FILE *file);
 */
void print_while_command(struct s_node_while *s_while, FILE *file);
/**
 ** \fn void print_until_command(struct s_node_until *s_until, FILE *file);
 */
void print_until_command(struct s_node_until *s_until, FILE *file);
/**
 ** \fn void print_if_command(struct s_node_if *s_if, FILE *file);
 */
void print_if_command(struct s_node_if *s_if, FILE *file);
/**
 ** \fn void print_else_command(struct s_node_else *s_else, FILE *file);
 */
void print_else_command(struct s_node_else *s_else, FILE *file);
#endif
