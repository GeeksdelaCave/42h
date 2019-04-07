#ifndef PARSER_CAPTURE_H
#define PARSER_CAPTURE_H
void list_capt_store(struct list_capt_s *capture, 
const char *tag, struct capture_s *capt);
struct capture_s *list_capt_lookup(struct list_capt_s *captur, 
const char *tag);
void parser_eat_capture(struct parser_s *p);
bool parser_begin_capture(struct parser_s *p, const char *tag);
char *parser_get_capture(struct parser_s *p, const char *tag);
bool parser_end_capture(struct parser_s *p, const char *tag);
#endif