#include "../parser/grammar.h"
#include "generate_dot_file_ast.h"
#include <stdio.h>
void print_simple_command(struct s_simple_cmd *simple_cmd, FILE *file)
{
  //FILE *file = fopen("../ast.dot", "w+");
  fprintf(file, "digraph AST {\n");
  fprintf(file, "    node [fontname=\"Arial\"];\n");
  for (int i = 0; i < simple_cmd->child; i++)
  {
    fprintf(file,  "    %d -> %d;\n", simple_cmd->type, simple_cmd->child_node[i].type); 
  }
  fprintf(file, "}\n");
}
void print_command_ast(struct s_node_command *cmd, FILE *file)
{
  if (cmd->type == SIMPLECOMMAND)
  {
    print_simple_command(cmd->struct_type->simple_c, file);
  }
}
void print_pipeline_to_command_ast(struct s_node_pipeline *pipeline, FILE *file)
{
  for (int i = 0; pipeline->child; i++)
  {
     fprintf(file,  "    %s -> %d;\n", "P", pipeline->commands[i].type);
     print_command_ast(&pipeline->commands[i], file);
   }
}
void print_and_or_to_pipeline(struct s_node_and_or *and_or, FILE *file)
{
  for (int i = 0; and_or->child; i++)
  {
    fprintf(file,  "    %d -> %d;\n", and_or->type, and_or->pipeline[i].type);
    print_pipeline_to_command_ast(&and_or->pipeline[i], file);
  }
}
void print_list_to_and_or(struct s_node_list *list, FILE *file)
{
  for (int i = 0; i < list->child; i++)
  {
    fprintf(file,  "    %d -> %d;\n", list->type, list->and_or[i].type);
    print_and_or_to_pipeline(&list->and_or[i], file);
  }
}
void my_print_ast(struct parser_s *p)
{
  FILE *file = fopen("../ast.dot", "w+");
  fprintf(file, "digraph AST {\n");
  fprintf(file, "    node [fontname=\"Arial\"];\n");
  if (!p->nodes)
  {
    // return 1;
  }
  else
  {
    print_list_to_and_or(p->nodes->node->list, file);
  }
}
