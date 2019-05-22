/** \mainpage readme
# 42sh

## Git

### Commits norm

Commit messages must follow this syntax:

``git commit -m "[TAG1][TAG2] <commit message>"``

* ``[TAG1]`` can be one of those values:
    * [ADD] Adding new code, functionality, feature
    * [RM] Removing some portions of code, functionality, feature
    * [EDIT] Modifying documentation or details in code
    * [FIX] Fixing bugs

* ``[TAG2]`` can be one of those values:
    * [CORE] The main process of 42sh
    * [LEXER] Lexer stuff
    * [PARSER] Parser stuff
    * [FUNCTIONS] Grammar related functions
    * [UTILS] Utilities such as text manipulation, etc.
    * [DOC] Documentation changes
    * [GIT] For Git stuff (.gitignore, etc.)
    * [TESTS] Test relative stuff
    * [MISC] Other

Example :

``git commit -m "[ADD][GIT] First commit"``

## Doxygen
* command : enter in doc repository , you tape doxygen my_42sh_config
