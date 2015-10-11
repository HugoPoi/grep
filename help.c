/*
 * help.c
 *
 *  Created on: 22 dec. 2012
 *      Author: Hugo
 */

#include <stdio.h>
#include <stdlib.h>

void print_help(){

	fprintf(stdout,"Usage: grep [OPTION]... PATTERN [FILE] ...\n\
Search for PATTERN in each FILE or standard input.\n\
Example: grep -i 'hello world' menu.h main.c\n\
\n\
Regexp selection and interpretation:\n\
  -f, --file=FILE           obtain PATTERN from FILE\n\
  -i, --ignore-case         ignore case distinctions\n\
  -z, --null-data           a data line ends in 0 byte, not newline\n\
  \n\
Miscellaneous:\n\
  -s, --no-messages         suppress error messages\n\
  -v, --invert-match        select non-matching lines\n\
  -V, --version             print version information and exit\n\
      --help                display this help and exit\n\
      \n\
Output control:\n\
  -m, --max-count=NUM       stop after NUM matches\n\
  -b, --byte-offset         print the byte offset with output lines\n\
  -n, --line-number         print line number with output lines\n\
  -H, --with-filename       print the filename for each match\n\
  -h, --no-filename         suppress the prefixing filename on output\n\
      --label=LABEL         print LABEL as filename for standard input\n\
  -q, --quiet, --silent     suppress all normal output\n\
      --binary-files=TYPE   assume that binary files are TYPE\n\
                            TYPE is 'binary', 'text', or 'without-match'\n\
  -d, --directories=ACTION  how to handle directories\n\
                            ACTION is 'read', 'recurse', or 'skip'\n\
  -R, -r, --recursive       equivalent to --directories=recurse\n\
  -c, --count               print only a count of matching lines per FILE\n\
 Context control:\n\
  -B, --before-context=NUM  print NUM lines of leading context\n\
  -A, --after-context=NUM   print NUM lines of trailing context\n\
  -C, --context=NUM         print NUM lines of output context\n\
  -NUM                      same as --context=NUM\n\
------------------------------------------------------\n\
Grep Projet C by Hugo Poissonnet, Sebastien Faro, Kenneth Damien Ango\n\
");

}
