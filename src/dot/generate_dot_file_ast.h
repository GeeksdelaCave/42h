#ifndef GENERATE_DOT_FILE_AST_H
#define GENERATE_DOT_FILE_AST_H
void print_simple_command(struct s_simple_cmd *simple_cmd, FILE *filen );
void print_command_ast(struct s_node_command *cmd, FILE *file);
void print_pipeline_to_command_ast(struct s_node_pipeline *pipeline, FILE *file);
void print_and_or_to_pipeline(struct s_node_and_or *and_or, FILE *file);
void print_list_to_and_or(struct s_node_list *list, FILE *file);
void my_print_ast(struct parser_s *p);
void print_compound_list(struct s_do_group *dogroup, FILE *file);
void print_while_command(struct s_node_while *s_while, FILE *file);
void print_until_command(struct s_node_until *s_until, FILE *file);
void print_if_command(struct s_node_if *s_if, FILE *file);
void print_else_command(struct s_node_else *s_else, FILE *file);
#endif
