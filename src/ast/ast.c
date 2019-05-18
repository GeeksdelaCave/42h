/**
 ** \file  ast.c
 */
#include "ast.h"
/**
 ** \brief Initialization of node
 **
 ** \return a new struct list node
 */
struct list_node_s *init_list_node()
{
    struct list_node_s *new_list = malloc(sizeof(struct list_node_s));
    if (new_list == NULL)
    {
        return NULL;
    }
    new_list->type = -1;
    new_list->node = malloc(sizeof(union all_grammar));
    new_list->next = NULL;
    new_list->prev = NULL;
    return new_list;
}
/**
 ** \brief free of node list
 **
 ** \param list_nodes (lnodes) struct list_nodes_s
 ** 
 */
void free_list_node(struct list_node_s *lnodes)
{
    struct list_node_s *prev_node = lnodes;
    while (lnodes)
    {
        prev_node = lnodes;
        lnodes = lnodes->next;
        free(prev_node);
    }
}
/**
 ** \brief list of node store
 **
 ** \param list_nodes (lnodes) struct list_nodes_s
 ** 
 ** \param union all_grammar *s_node
 **
 ** \param enum type_grammar type
 */
void list_node_store(struct list_node_s *list_node, union all_grammar *s_node,
enum type_grammar type)
{
    for (; list_node->next; list_node = list_node->next);
    list_node->next = init_list_node();
    list_node->type = type;  
    list_node->node = s_node;
    list_node->next->prev = list_node;
}
/**
 ** \brief list_node_lookup : find and get the node 
 **
 ** \param list_nodes (lnodes) struct list_nodes_s
 ** 
 ** \param enum type_grammar type
 **
 ** \return a struct list_node_s
 */
struct list_node_s *list_node_lookup(struct list_node_s *list_node, 
enum type_grammar type)
{
    for (; list_node->next; list_node = list_node->next)
    {
        if (list_node->type == type)
        {
            return list_node; 
        }
    }
    return NULL;
}
/**
 ** \brief list_type_lookup
 **
 ** \param list_nodes (lnodes) struct list_nodes_s
 ** 
 ** \param enum type_grammar type
 **
 ** \return a enum type_grammar
 */
enum type_grammar list_type_lookup(struct list_node_s *list_node,
enum type_grammar type)
{
    for (; list_node->next; list_node = list_node->next)
    {
        if (list_node->type == type)
        {
            return type; 
        }
    }
    return -1;
}
/**
 ** \brief lookup_last : find and get the last node of the type : type 
 **
 ** \param list_nodes (lnodes) struct list_nodes_s
 ** 
 ** \param enum type_grammar type
 **
 ** \return struct list_node_s
 */
struct list_node_s *lookup_last(struct list_node_s *list_node, enum type_grammar type)
{
    struct list_node_s *last = NULL; 
    for (; list_node->next; list_node = list_node->next)
    {
        if (list_node->type == type)
        {
            last = list_node; 
        }
    }
    return last;
}
/**
 ** \brief eat_list_node
 **
 ** \param struct parser_s *p
 ** 
 ** \param enum type_grammar type
 **
 */
void eat_list_node(struct parser_s *p, enum type_grammar type)
{
    struct list_node_s *pnode = list_node_lookup(p->nodes, type);
    if (pnode->next != NULL && pnode->prev != NULL)
    {
        pnode->prev->next = pnode->next;
        pnode->next->prev = pnode->prev;
        free(pnode);
    }
    else if (pnode->next != NULL)
    {
        p->nodes = pnode->next;
        pnode->next->prev = NULL;
        free(pnode);
    }
    else if (pnode->prev != NULL)
    {
        pnode->prev->next = NULL;
        free(pnode);
    }
    else
    {
        free(pnode);
    }   
}
/**
 ** \brief eat_list_last
 **
 ** \param struct parser_s *p
 ** 
 ** \param enum type_grammar type
 **
 */
void eat_list_last(struct parser_s *p, enum type_grammar type)
{
    struct list_node_s *pnode = lookup_last(p->nodes, type);
    if (pnode->next != NULL && pnode->prev != NULL)
    {
        pnode->prev->next = pnode->next;
        pnode->next->prev = pnode->prev;
        free(pnode);
    }
    else if (pnode->next != NULL)
    {
        p->nodes = pnode->next;
        pnode->next->prev = NULL;
        free(pnode);
    }
    else if (pnode->prev != NULL)
    {
        pnode->prev->next = NULL;
        free(pnode);
    }
    else
    {
        free(pnode);
    }   
}
/**
 ** \brief ast_check_node : check node and get if true
 **
 ** \param struct parser_s *p
 ** 
 ** \param enum type_grammar type
 **
 ** \return a struct list_node_s
 */
struct list_node_s *ast_check_node(struct parser_s *p, enum type_grammar type)
{
    struct list_node_s *pnode = list_node_lookup(p->nodes, type);
    if (!pnode){
        return NULL;
    }
    eat_list_node(p, type);
    return pnode;
}
/**
 ** \brief ast_check_last
 **
 ** \param struct parser_s *p
 ** 
 ** \param enum type_grammar type
 **
 ** \return a struct list_node_s
 */
struct list_node_s *ast_check_last(struct parser_s *p, enum type_grammar type)
{
    struct list_node_s *pnode = lookup_last(p->nodes, type);
    if (!pnode){
        return NULL;
    }
    eat_list_last(p, type);
    return pnode;
}
/**
 ** \brief ast_check_sym : check sym and get if true
 **
 ** \param struct parser_s *p
 ** 
 ** \param enum type_grammar type
 **
 ** \return a int 
 */
int ast_check_sym(struct parser_s *p, enum type_grammar type)
{
    struct list_node_s *pnode = list_node_lookup(p->nodes, type);
    if (!pnode){
        return 0;
    }
    eat_list_node(p, type);
    return 1;
}
/**
 ** \brief print a node 
 **
 ** \param struct list_node_s *node
 ** 
 ** \param enum type_grammar type
 **
 ** \return a int 
 */
void print_node(struct list_node_s *node)
{
    for(; node; node = node->next)
    {
        printf("TYPE : %d ", node->type);
        if (node->prev)
            printf("LE PREV : %d\n", node->prev->type);
        else
            printf("\n");    
    }
    printf("\n");
}