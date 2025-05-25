// KDG CUSTOM

#include <sys/queue.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "def.h"

#include <ctype.h>

int
wordcount(struct buffer *b)
{
	int wc = 0;
	struct line *cline = b->b_headp;

	for (int i = 0; i < b->b_lines; i++) {
		if (cline->l_used >= 1) {
			char *sp = cline->l_text;
			for (int j = 0; j < cline->l_used; j++)
				wc += ((isalnum(sp[j]) || ispunct(sp[j])) &&
				    (isspace(sp[j+1]) || !isprint(sp[j+1]))) ? 1 : 0;
		}
		cline = cline->l_fp;
	}
	return wc;
}

