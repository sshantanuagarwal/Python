//adi_prakash
//27-1-2014
//crypt arithmatic
// artificial intelligence lab
#include "crypt.h"

int main(int argc, char *argv[])
{
    freopen("inp.txt","r",stdin);
    freopen("out.txt","w",stdout);
    char buff[PUZ_SIZE];
    char *pp[PUZ_SIZE];
    int len, s, i;

    usertime0 = usertime();
    srand((unsigned int)time(NULL));
    //putstr("type help for help\n");
    fflush(stdout);
    while (fgets(buff, PUZ_SIZE, stdin) != NULL) {
	if (*buff == '\n' || *buff == '#')
	    continue;
	len = parse(buff, pp);
	if (len == 0) {
	    putstr("Parse error\n");
	    continue;
	}
	if (strcmp(pp[0], "example") == 0 && pp[1] == NULL) {
	    s = (sizeof example / sizeof (char *));
	    i = rand() % s;
	    printf("Example %d/%d\n", i, s);
	    strcpy(buff, example[i]);
	    parse(buff, pp);
	    crypt(pp);
	} else if (len <= 2) {
	    command(pp[0], pp[1]);
	}
	else {
	    crypt(pp);
	}
	fflush(stdout);
    }
    quit();
}


void quit()
{
    if (unique) {
	printf("%d unique-solution puzzles found ", num_unique);
	printf("(%d puzzles examined)\n", num_tested);
    }
    printf("Total time = %ld msec.\n", usertime()-usertime0);
    exit(0);
}


int parse(char *q, char **pp)
{
    int len = 0;
    while (*q) {
	if (isspace(*q) || *q == '+' || *q == '=') {
	    *q++ = '\0';
	    continue;
	}
	if (isalnum(*q)) {
	    *pp++ = q;
	    ++len;
	    while (isalnum(*q))
		++q;
	    continue;
	}
	return 0;
    }
    *pp = NULL;
    return len;
}


void command(char *cmd, char *arg)
{
    if (strcmp(cmd, "help") == 0) {
	putstr("  SEND MORE MONEY : this is an example\n");
	putstr("  help            : show this message\n");
	putstr("  example         : show an example at random\n");
	putstr("  limit n         : show at most n solutions ");
	putstr("(0 means no-limit)\n");
	putstr("  quit            : quit\n");
    } else if (strcmp(cmd, "limit") == 0 && arg != NULL) {
	limit = atoi(arg);
    }
     else if (strcmp(cmd, "quit") == 0) {
	quit();
    } else {
	putstr("Unknown command\n");
    }
}


int crypt(char **pp)
{
    char *msg;
    int d;
    long t0 = usertime();

    ++num_tested;
    puzzle = pp;
    count = 0;
    for (d = 0; d < BASE; ++d)
	used[d] = NO;
    if (unique) {
	/* search only unique solution puzzle */
	if (setup() != NULL)
	    return NO;
	limit = 2;
	if (setjmp(jmpbuf) == 0) {
	    solve(puz, 0);
	    /* return after finding all solutions */
	    if (count == 1) {
		/* unique solution */
		++num_unique;
		memcpy(sel, sel_copy, sizeof(sel));
		show_puzzle(); putstr(" (");
		show_sol(); putstr(")\n");
	    }
	}
    } else {
	/* usual search */
	putstr("  "); show_puzzle(); putstr("\n");
    if ((msg = setup()) != NULL) {
	    printf("  Wrong input (%s)\n", msg);
	    return NO;
	}
	if (setjmp(jmpbuf) == 0) {
	    solve(puz, 0);
	    /* return after finding all solutions */
	    printf("  %d solution(s)", count);
	} else {
	    /* return by longjmp */
	    printf("  %d or more solution(s)", count);
	}
	printf(", %ld msec.\n", usertime()-t0);
    }
    return YES;
}


char *setup()
{
    int c, maxlen, min, max, k, i, j;
    char **pp, *p;

    /* initialize sel[] */
    for (c = 0; c < UCHAR_MAX; ++c)
	sel[c] = -2;
    for (c = '0'; c <= '9'; ++c)
	sel[c] = c - '0';
    /* check puzzle */
    pp = puzzle;
    if (*puzzle == NULL || *(puzzle+1) == NULL)
	return "too short";
    maxlen = 0;
    min = 0;
    max = 0;
    for (pp = puzzle; *(pp+1) != NULL; ++pp) {
	if (strlen(*pp) == 0)
	    return NO;
	maxlen = maxi(maxlen, strlen(*pp));
	min += min_value(*pp);
	max += max_value(*pp);
    }
    maxlen = maxi(maxlen, strlen(*pp));
    //if (maxi(min, min_value(*pp)) < mini(max, max_value(*pp)))
	//{
	//return "range error";
    //}
	k = 0;
    for (pp = puzzle; *pp != NULL; ++pp) {
	for (p = *pp; *p; ++p) {
	    if (isalpha(*p) && sel[(unsigned)*p] == -2) {
		sel[(unsigned)*p] = -1;
		++k;
	    }
	}
    }
    if (k > BASE)
	return "too many alphabets";
    /* initialize puz[]
       e.g. puz = "+D+E=Y+N+R=E+E+O=N+S+M=O=M"; */
    p = puz;
    for (i = 1; i <= maxlen; ++i) {
	for (pp = puzzle; *pp != NULL; ++pp) {
	    j = strlen(*pp) - i;
	    if (j < 0)
		continue;
	    if (*(pp+1) != NULL)
		*p++ = '+';
	    else
		*p++ = '=';
	    *p++ = *(*pp+j);
	    if (p >= puz + PUZ_SIZE)
		return "too long input";
	}
    }
    *p = '\0';
    /* initialize lower[]
       e.g. lower['S'] = 1; lower['M'] = 1; */
    for (c = 0; c < UCHAR_MAX; ++c) {
	lower[c] = 0;
    }
    for (pp = puzzle; *pp != NULL; ++pp)
	if (isalpha(**pp))
	    lower[**pp] = 1;
    return NULL;
}


int min_value(char *p)
{
    int min = 0;
    char *q;
    for (q = p; *q; ++q) {
	min *= BASE;
	if (isalpha(*q))
	    min += (q == p) ? 1 : 0;
	else if (isdigit(*q))
	    min += *q - '0';
    }
    return min;
}


int max_value(char *p)
{
    int max = 0;
    for (; *p; ++p) {
	max *= BASE;
	if (isalpha(*p))
	    max += BASE - 1;
	else if (isdigit(*p))
	    max += *p - '0';
    }
    return max;
}


int mini(int x, int y)
{
    return (x < y) ? x : y;
}


int maxi(int x, int y)
{
    return (x > y) ? x : y;
}


void solve(char *p, int s)
{
    register unsigned int c;
    register int d;

    if (*p == '\0' && s == 0) {
	/* solved */
	++count;
	if (unique) {
	    memcpy(sel_copy, sel, sizeof(sel));
	} else {
	    putstr("  "); show_sol(); putstr("\n");
	}
	if (limit > 0 && count >= limit)
	    longjmp(jmpbuf, 1);
	return;
    }
    c = *(p+1);
    switch (*p) {
    case '+':
	if (sel[c] >= 0) {
	    /* already selected */
	    solve(p+2, s+sel[c]);
	} else {
	    /* not selected yet */
	    for (d = lower[c]; d < BASE; ++d) {
		if (used[d])
		    continue;
		used[d] = YES; sel[c] = d;
		solve(p+2, s+d);
		used[d] = NO; sel[c] = -1;
	    }
	}
	break;
    case '=':
	d = mod(s, BASE);
	if (sel[c] >= 0) {
	    /* already selected */
	    if (sel[c] == d)
		solve(p+2, quot(s, BASE));
	} else {
	    /* not selected yet */
	    if (!used[d] && d >= lower[c]) {
		used[d] = YES; sel[c] = d;
		solve(p+2, quot(s, BASE));
		used[d] = NO; sel[c] = -1;
	    }
	}
	break;
    }
    return;
}


void show_puzzle()
{
    char **pp;
    for (pp = puzzle; *pp != NULL; ++pp) {
	if (*(pp+1) == NULL)
	    putstr("=");
	else if (pp > puzzle)
	    putstr("+");
	putstr(*pp);
    }
}


void show_sol()
{
    char **pp, *p;
    for (pp = puzzle; *pp != NULL; ++pp) {
	if (*(pp+1) == NULL)
	    putstr("=");
	else if (pp > puzzle)
	    putstr("+");
	for (p = *pp; *p; ++p)
	    printf("%d", sel[(unsigned)*p]);
    }
}


long usertime()
{
    return (1000.0 * clock() / CLOCKS_PER_SEC);
}


