#include "../parser/grammar.h"
#include "generate_dot_file_ast.h"
#include <stdio.h>
#include <stdlib.h>
int P_CHILD =  0;
int AND_CHILD =  0;
int C_CHILD =  0;
int S_CHILD = 0;
int SH_CHILD = 0;
void print_simple_command(struct s_simple_cmd *simple_cmd, FILE *file)
{
  //FILE *file = fopen("../ast.dot", "w+");
  for (int i = 0; i < simple_cmd->child; i++)
  {
    if (simple_cmd->child_node[i].type == ASSIGN)
    {
      fprintf(file,  "    %s_child_%d -> \"%s = %s\";\n", "C", C_CHILD,
	      simple_cmd->child_node[i].struct_type->assign->id,
	      simple_cmd->child_node[i].struct_type->assign->num); 
      S_CHILD++;
    }
    else {
      fprintf(file,  "    %s_child_%d -> \"%s REDIR %s\";\n", "C", C_CHILD,
	      simple_cmd->child_node[i].struct_type->redirection->number,
	      simple_cmd->child_node[i].struct_type->redirection->word);
      S_CHILD++;
    }
  }
}
void print_while_command(struct s_node_while *while, FILE *file)
{
  
}
/*
void print_shell_command(struct s_shell_cmd *shell_cmd, FILE *file)
{
  //FILE *file = fopen("../ast.dot", "w+");
  for (int i = 0; i < simple_cmd->child; i++)
  {
    fprintf(file,  "    %s_child_%d -> %d%d;\n", "C", C_CHILD, simple_cmd->child_node[i].type, S_CHILD); 
    S_CHILD++;
  }
}
*/
void print_command_ast(struct s_node_command *cmd, FILE *file)
{
  if (cmd->type == SIMPLECOMMAND)
  {
    print_simple_command(cmd->struct_type->simple_c, file);
  }
  if (cmd->type == WHILE)
  {
    print_shell_command(cmd->struct_type->node_while, file);
  }
}
void print_pipeline_to_command_ast(struct s_node_pipeline *pipeline, FILE *file)
{
  for (int i = 0; i < pipeline->child; i++)
  {
    printf("%d test \n", i);
    fprintf(file,  "    %s_child_%d -> %s_child_%d;\n", "P",P_CHILD ,"C", C_CHILD);
    print_command_ast(&pipeline->commands[i], file);
    C_CHILD++;
  }
}
void print_and_or_to_pipeline(struct s_node_and_or *and_or, FILE *file)
{
  for (int i = 0; i < and_or->child; i++)
  {
    fprintf(file,  "    %s_child_%d -> %s_child_%d;\n", "AND_OR",AND_CHILD, "P", P_CHILD);
    print_pipeline_to_command_ast(&and_or->pipelines[i], file);
    P_CHILD++;
  }
  //fprintf(file, "}\n");
}
void print_compound_list(struct s_do_group *dogroup, FILE *file)
{
  fprintf(file, "digraph AST {\n");
  fprintf(file, "    node [fontname=\"Arial\"];\n");
  printf("nb fils : %d \n", dogroup->cpd->child);
  for (int i = 0; i < dogroup->cpd->child; i++)
  {
    fprintf(file,  "    %s -> %s_child_%d;\n", "ComPoundLIst", "AND_OR", AND_CHILD);
    print_and_or_to_pipeline(&dogroup->cpd->and_or[i], file);
    AND_CHILD++;
  }
  fprintf(file, "}\n");
}
void print_list_to_and_or(struct s_node_list *list, FILE *file)
{
  for (int i = 0; i < list->child; i++)
  {
    fprintf(file,  "    %d -> %d_child_%d;\n", list->type, list->and_or[i].type, AND_CHILD);
    print_and_or_to_pipeline(&list->and_or[i], file);
    AND_CHILD++;
  }
}
void my_print_ast(struct parser_s *p)
{
  FILE *file = fopen("../ast.dot", "w+");
  
  fprintf(file, "digraph AST {\n");
  fprintf(file, "    node [fontname=\"Arial\"];\n");
  fprintf(file,"JE REGARDE\n");
  if (!p->nodes)
  {
    // return 1;
  }
  else
  {
    print_list_to_and_or(p->nodes->node->list, file);
  }
}
