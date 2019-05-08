#include "../parser/grammar.h"
#include "generate_dot_file_ast.h"
#include <stdio.h>
#include <stdlib.h>
int P_CHILD =  0;
int AND_CHILD =  0;
int C_CHILD =  0;
int S_CHILD = 0;
int SH_CHILD = 0;
int C_WHILE = 0;
int C_IF = 0;
int C_CMP = 0;
char *Parent = "";
void print_simple_command(struct s_simple_cmd *simple_cmd, FILE *file)
{
  for (int i = 0; i < simple_cmd->child; i++)
  {
    if (simple_cmd->child_node[i].type == ASSIGN)
    {
      fprintf(file,  "    %s_child_%d -> \"%s = %s\";\n", "C", C_CHILD,
	  simple_cmd->child_node[i].struct_type->assign->id,
	  simple_cmd->child_node[i].struct_type->assign->num); 
      S_CHILD++;
    }
    else if (simple_cmd->child_node[i].type == REDIRECTION)
	{
      fprintf(file,  "    %s_child_%d -> \"%s REDIR %s\";\n", "C", C_CHILD,
	  simple_cmd->child_node[i].struct_type->redirection->number,
	  simple_cmd->child_node[i].struct_type->redirection->word);
      S_CHILD++;
    }
	else 
	{
	  fprintf(file,  "    %s_child_%d -> %s\";\n", "C", C_CHILD,
	  simple_cmd->child_node[i].struct_type->word->word);
      S_CHILD++;

	}  
}
}
void print_until_command(struct s_node_until *s_until, FILE *file)
{
	fprintf(file,  "    %s_child_%d -> Condition\n", "UNTIL", C_WHILE);
  	fprintf(file,  "    Condition -> \"%s_%d\"\n", "ComPoundLIst", C_CMP);
  for (int i = 0; i < s_until->condition->child; i++)
  {
    fprintf(file,  "    \"%s_%d\" -> %s_child_%d;\n", "ComPoundLIst",C_CMP, "AND_OR", 			  	AND_CHILD);    
	print_and_or_to_pipeline(&s_until->condition->and_or[i], file);
    AND_CHILD++;
  }
  C_CMP++;
  fprintf(file,  "    %s_child_%d -> Dogroup\n", "UNTIL", C_WHILE);
  fprintf(file,  "    Dogroup -> \"ComPoundLIst_%d\"\n", C_CMP);
  for (int i = 0; i < s_until->dogroup->child; i++)
  {
    fprintf(file,  "    %s_%d -> %s_child_%d;\n", "ComPoundLIst", C_CMP, "AND_OR", AND_CHILD);
    print_and_or_to_pipeline(&s_until->dogroup->and_or[i], file);
    AND_CHILD++;
  }
  C_WHILE++;
  C_CMP++;
}
void print_while_command(struct s_node_while *s_while, FILE *file)
{
  fprintf(file,  "    %s_child_%d -> Condition\n", "WHILE", C_WHILE);
  fprintf(file,  "    Condition -> \"%s_%d\"\n", "ComPoundLIst", C_CMP);
  for (int i = 0; i < s_while->condition->child; i++)
  {
    fprintf(file,  "    \"%s_%d\" -> %s_child_%d;\n", "ComPoundLIst",C_CMP, "AND_OR", AND_CHILD);    
	print_and_or_to_pipeline(&s_while->condition->and_or[i], file);
    AND_CHILD++;
  }

  C_CMP++;
  fprintf(file,  "    %s_child_%d -> Dogroup\n", "WHILE", C_WHILE);
  fprintf(file,  "    Dogroup -> \"ComPoundLIst_%d\"\n", C_CMP);
  for (int i = 0; i < s_while->dogroup->child; i++)
  {
    fprintf(file,  "    %s_%d -> %s_child_%d;\n", "ComPoundLIst", C_CMP, "AND_OR", AND_CHILD);
    print_and_or_to_pipeline(&s_while->dogroup->and_or[i], file);
    AND_CHILD++;
  }
  C_WHILE++;
  C_CMP++;
}
void print_else_command(struct s_node_else *s_else, FILE *file)
{
	if (s_else->else_body != NULL)
    {
     fprintf(file,  "    %s_child_%d -> ELSE_BODY\n", "IF", C_IF);
     fprintf(file,  "    ELSE_BODY -> \"ComPoundLIst_%d\"\n", C_CMP);
for (int i = 0; i < s_else->else_body->child; i++)
  {
	 fprintf(file,  "    %s_%d -> %s_child_%d;\n", "ComPoundLIst", C_CMP, "AND_OR", AND_CHILD);
     print_and_or_to_pipeline(&s_else->else_body->and_or[i], file);
     AND_CHILD++;
	}
}
   else
  {
	fprintf(file,  "    %s_child_%d -> ELIF_BODY\n", "IF", C_IF);
    fprintf(file,  "    ELIF_BODY -> \"ComPoundLIst_%d\"\n", C_CMP);
	for (int i = 0; i < s_else->elif_body->child; i++)
	{	
		fprintf(file,  "    %s_%d -> %s_child_%d;\n", "ComPoundLIst", C_CMP, "AND_OR", AND_CHILD);
    	print_and_or_to_pipeline(&s_else->elif_body->and_or[i], file);
		AND_CHILD++;  
	}
    fprintf(file,  "    %s_child_%d -> THEN_BODY\n", "IF", C_IF);
    fprintf(file,  "    THEN_BODY -> \"ComPoundLIst_%d\"\n", C_CMP);
	for (int i = 0; i < s_else->then_body->child; i++)
{	
	fprintf(file,  "    %s_%d -> %s_child_%d;\n", "ComPoundLIst", C_CMP, "AND_OR", AND_CHILD);
    print_and_or_to_pipeline(&s_else->then_body->and_or[i], file);
	AND_CHILD++; 
  }
}
}
void print_if_command(struct s_node_if *s_if, FILE *file)
{
   fprintf(file, "digraph AST {\n");
   fprintf(file, "    node [fontname=\"Arial\"];\n");
  fprintf(file,  "    %s_child_%d -> Condition\n", "IF", C_IF);
  fprintf(file,  "    Condition -> \"%s_%d\"\n", "ComPoundLIst", C_CMP);
  for (int i = 0; i < s_if->condition->child; i++)
  {
    fprintf(file,  "    \"%s_%d\" -> %s_child_%d;\n", "ComPoundLIst",C_CMP, "AND_OR", AND_CHILD);    
	print_and_or_to_pipeline(&s_if->condition->and_or[i], file);
    AND_CHILD++;
  }

  C_CMP++;
  fprintf(file,  "    %s_child_%d -> IF_BODY\n", "IF", C_IF);
  fprintf(file,  "    IF_BODY -> \"ComPoundLIst_%d\"\n", C_CMP);
  for (int i = 0; i < s_if->if_body->child; i++)
  {
    fprintf(file,  "    %s_%d -> %s_child_%d;\n", "ComPoundLIst", C_CMP, "AND_OR", AND_CHILD);
    print_and_or_to_pipeline(&s_if->if_body->and_or[i], file);
    AND_CHILD++;
  }

  //C_IF++;
  C_CMP++;
	if (s_if->else_body != NULL)
  {
    print_else_command(s_if->else_body, file);
  }
  C_IF++;
  C_CMP++;
fprintf(file, "}\n");
}
void print_command_ast(struct s_node_command *cmd, FILE *file)
{
  if (cmd->type == SIMPLECOMMAND)
  {
    print_simple_command(cmd->struct_type->simple_c, file);
  }
  if (cmd->type == WHILE)

  {
    print_while_command(cmd->struct_type->node_while, file);
  }
	if (cmd->type == UNTIL)
  {
    print_until_command(cmd->struct_type->node_until, file);
  }
	if (cmd->type == IF)
  {
	print_if_command(cmd->struct_type->node_if, file);
  }
}
void print_pipeline_to_command_ast(struct s_node_pipeline *pipeline, FILE *file)
{

  for (int i = 0; i < pipeline->child; i++)
  {
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
}
void print_compound_list(struct s_do_group *dogroup, FILE *file)
{
  for (int i = 0; i < dogroup->cpd->child; i++)
  {
    fprintf(file,  "    %s -> %s_child_%d;\n", "ComPoundLIst", "AND_OR", AND_CHILD);
    print_and_or_to_pipeline(&dogroup->cpd->and_or[i], file);
    AND_CHILD++;
  }
  C_CMP++;
}
void print_list_to_and_or(struct s_node_list *list, FILE *file)
{
  for (int i = 0; i < list->child; i++)
  {
    fprintf(file,  "    %d -> %d_child_%d;\n", 1, list->and_or[i].type, AND_CHILD);
    print_and_or_to_pipeline(&list->and_or[i], file);
    AND_CHILD++;
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
    //print_list_to_and_or(p->nodes->node->list, file);
	  
}
  fprintf(file, "}\n");
}
