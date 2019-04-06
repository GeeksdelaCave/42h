#include "grammar.h" 
/*
  pipeline: ['!'] command ('|' ('\n')* command)*
*/
void print_pipeline(struct s_node_pipeline *pipeline)
{
    for(int i = 0; i < pipeline->child; i++)
    {
        //printf("%d -- EXCLA : %d\n", i+1,pipeline->commands[i].excla);
        //printf("%d -- PIPE : %d\n", i+1,pipeline->commands[i].pipe);
    }
}

int read_pipeline(struct parser_s *p)
{
  
  int tmp = p->cursor;
  if (ZeroOrOne(read_excla(p)) && ZeroOrMany(read_spaces(p)) &&
      read_command(p) && ZeroOrMany(read_spaces(p)) &&  
      ZeroOrMany(read_pipe(p) && ZeroOrMany(read_spaces(p)) && ZeroOrMany(parser_readchar(p, '\n')&& ZeroOrMany(read_spaces(p)))
		 && read_command(p)))
    {
        struct s_node_pipeline *pipeline = init_pipeline(p);
        print_node(p->nodes);
        while(find_command(p, pipeline));
        print_pipeline(pipeline);
        union all_grammar *grammar = malloc(sizeof(union all_grammar));
        grammar->pipeline = pipeline;
        list_node_store(p->nodes, grammar, PIPELINE);
        //printf("JE PASSE ICI ///////////////////////////\n");
        return 1;
    }
    p->cursor = tmp;
    //printf("AST PIPELINE FAIL \n");
    return 0;
}
