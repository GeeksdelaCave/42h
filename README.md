# 42sh

## Build (with CMake)

In order to compile with CMake, please run the following. You have to do it once
or more if a reset is needed.

* ``mkdir build``
* ``cd build``
* ``cmake ..``

At this time, you have a complete compilation folder in witch you can compile.
Run then the following to compile or recompile:

* ``make``: to compile. You can then run your 42sh with ``./42sh [...]``
* ``make check``: run test suit
* ``make doc``: generate documentation with Doxygen

## Tests

### Applicative test

To add a new test case in test suit, please open test_yaml.yml file and add at
the end:

```yaml
TEST-XX:
      desc: Summary
      ref: echo "Hello cat World"
      cmd: echo "Hello cat World"
```
      
Replace XX by the test number, (add +1 to the last one), give at ``desc:`` a
short explanation of the test, and then type the command that have to be typed
in ref for reference and in cmd for 42sh.

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