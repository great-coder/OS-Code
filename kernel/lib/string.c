/**
 * Copyright (c) 2018 M D
 * 
 * This software is released under the MIT License.
 * https://opensource.org/licenses/MIT
 */

#include "string.h"

/*
 * This array is designed for mapping upper and lower case letter
 * together for a case independent comparison.  The mappings are
 * based upon ascii character sequences.
 */
static const u_char charmap[] = {
    '\000',
    '\001',
    '\002',
    '\003',
    '\004',
    '\005',
    '\006',
    '\007',
    '\010',
    '\011',
    '\012',
    '\013',
    '\014',
    '\015',
    '\016',
    '\017',
    '\020',
    '\021',
    '\022',
    '\023',
    '\024',
    '\025',
    '\026',
    '\027',
    '\030',
    '\031',
    '\032',
    '\033',
    '\034',
    '\035',
    '\036',
    '\037',
    '\040',
    '\041',
    '\042',
    '\043',
    '\044',
    '\045',
    '\046',
    '\047',
    '\050',
    '\051',
    '\052',
    '\053',
    '\054',
    '\055',
    '\056',
    '\057',
    '\060',
    '\061',
    '\062',
    '\063',
    '\064',
    '\065',
    '\066',
    '\067',
    '\070',
    '\071',
    '\072',
    '\073',
    '\074',
    '\075',
    '\076',
    '\077',
    '\100',
    '\141',
    '\142',
    '\143',
    '\144',
    '\145',
    '\146',
    '\147',
    '\150',
    '\151',
    '\152',
    '\153',
    '\154',
    '\155',
    '\156',
    '\157',
    '\160',
    '\161',
    '\162',
    '\163',
    '\164',
    '\165',
    '\166',
    '\167',
    '\170',
    '\171',
    '\172',
    '\133',
    '\134',
    '\135',
    '\136',
    '\137',
    '\140',
    '\141',
    '\142',
    '\143',
    '\144',
    '\145',
    '\146',
    '\147',
    '\150',
    '\151',
    '\152',
    '\153',
    '\154',
    '\155',
    '\156',
    '\157',
    '\160',
    '\161',
    '\162',
    '\163',
    '\164',
    '\165',
    '\166',
    '\167',
    '\170',
    '\171',
    '\172',
    '\173',
    '\174',
    '\175',
    '\176',
    '\177',
    '\200',
    '\201',
    '\202',
    '\203',
    '\204',
    '\205',
    '\206',
    '\207',
    '\210',
    '\211',
    '\212',
    '\213',
    '\214',
    '\215',
    '\216',
    '\217',
    '\220',
    '\221',
    '\222',
    '\223',
    '\224',
    '\225',
    '\226',
    '\227',
    '\230',
    '\231',
    '\232',
    '\233',
    '\234',
    '\235',
    '\236',
    '\237',
    '\240',
    '\241',
    '\242',
    '\243',
    '\244',
    '\245',
    '\246',
    '\247',
    '\250',
    '\251',
    '\252',
    '\253',
    '\254',
    '\255',
    '\256',
    '\257',
    '\260',
    '\261',
    '\262',
    '\263',
    '\264',
    '\265',
    '\266',
    '\267',
    '\270',
    '\271',
    '\272',
    '\273',
    '\274',
    '\275',
    '\276',
    '\277',
    '\300',
    '\301',
    '\302',
    '\303',
    '\304',
    '\305',
    '\306',
    '\307',
    '\310',
    '\311',
    '\312',
    '\313',
    '\314',
    '\315',
    '\316',
    '\317',
    '\320',
    '\321',
    '\322',
    '\323',
    '\324',
    '\325',
    '\326',
    '\327',
    '\330',
    '\331',
    '\332',
    '\333',
    '\334',
    '\335',
    '\336',
    '\337',
    '\340',
    '\341',
    '\342',
    '\343',
    '\344',
    '\345',
    '\346',
    '\347',
    '\350',
    '\351',
    '\352',
    '\353',
    '\354',
    '\355',
    '\356',
    '\357',
    '\360',
    '\361',
    '\362',
    '\363',
    '\364',
    '\365',
    '\366',
    '\367',
    '\370',
    '\371',
    '\372',
    '\373',
    '\374',
    '\375',
    '\376',
    '\377',
};

void int_to_ascii(int n, char s[])
{
    int i, sign;
    if ((sign = n) < 0)
        n = -n;
    i = 0;
    do
    {
        s[i++] = n % 10 + '0';
    } while ((n /= 10) > 0);

    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';

    reverse(s);
}

int ascii_to_int(const char s[])
{
    int i = 0, sign = 1, number = 0;
    if (s[0] == '-')
    {
        sign = -1;
        i = 1;
    }
    else if (s[0] == '+')
    {
        i = 1;
    }
    for (; s[i]; i++)
    {
        if (s[i] > '0' && s[i] < '9')
            number = number * 10 + (s[i] - '0'); // or (string[i] - 48)
        else
            return (0);
    }
    return (sign * number);
}

void hex_to_ascii(int n, char str[])
{
    append(str, '0');
    append(str, 'x');
    char zeros = 0;

    int32_t tmp;
    int i;
    for (i = 28; i > 0; i -= 4)
    {
        tmp = (n >> i) & 0xF;
        if (tmp == 0 && zeros == 0)
            continue;
        zeros = 1;
        if (tmp > 0xA)
            append(str, tmp - 0xA + 'a');
        else
            append(str, tmp + '0');
    }

    tmp = n & 0xF;
    if (tmp >= 0xA)
        append(str, tmp - 0xA + 'a');
    else
        append(str, tmp + '0');
}

void reverse(char s[])
{
    int c, i, j;
    for (i = 0, j = strlen(s) - 1; i < j; i++, j--)
    {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}

int strlen(const char *str)
{
    const char *s;

    for (s = str; *s; ++s)
        ;
    return (s - str);
}

void append(char s[], char n)
{
    int len = strlen(s);
    s[len] = n;
    s[len + 1] = '\0';
}

void backspace(char s[])
{
    int len = strlen(s);
    if (len != 0)
    {
        s[len - 1] = '\0';
    }
}

int strcmp(const char *s1, const char *s2)
{
    while (*s1 == *s2++)
        if (*s1++ == 0)
            return (0);
    return (*(unsigned char *)s1 - *(unsigned char *)--s2);
}

int strcasecmp(const char *s1, const char *s2)
{
    const u_char *cm = charmap;
    const u_char *us1 = (const u_char *)s1;
    const u_char *us2 = (const u_char *)s2;

    while (cm[*us1] == cm[*us2++])
        if (*us1++ == '\0')
            return (0);
    return (cm[*us1] - cm[*--us2]);
}

int strncasecmp(const char *s1, const char *s2, size_t n)
{
    if (n != 0)
    {
        const u_char *cm = charmap;
        const u_char *us1 = (const u_char *)s1;
        const u_char *us2 = (const u_char *)s2;

        do
        {
            if (cm[*us1] != cm[*us2++])
                return (cm[*us1] - cm[*--us2]);
            if (*us1++ == '\0')
                break;
        } while (--n != 0);
    }
    return (0);
}

/*
 * Find the first occurrence of find in s.
 */
char *strstr(const char *s1, const char *s2)
{
    char c, sc;
    size_t len;

    if ((c = *s2++) != 0)
    {
        len = strlen(s2);
        do
        {
            do
            {
                if ((sc = *s1++) == 0)
                    return (NULL);
            } while (sc != c);
        } while (strncmp(s1, s2, len) != 0);
        s1--;
    }
    return ((char *)s1);
}

/*
 * Find the first occurrence of find in s, ignore case.
 */
// char *strcasestr(const char *s, const char *find)
// {
//     char c, sc;
//     size_t len;

//     if ((c = *find++) != 0)
//     {
//         c = (char)tolower((unsigned char)c);
//         len = strlen(find);
//         do
//         {
//             do
//             {
//                 if ((sc = *s++) == 0)
//                     return (NULL);
//             } while ((char)tolower((unsigned char)sc) != c);
//         } while (strncasecmp(s, find, len) != 0);
//         s--;
//     }
//     return ((char *)s);
// }

int strch(const char s[], const char ch)
{
    int i;
    for (i = 0; s[i] && s[i] != ch; i++)
    {
    }
    if (s[i])
    {
        return (i);
    }
    return (-1);
}

char *strchr(const char *p, int ch)
{
    for (;; ++p)
    {
        if (*p == ch)
            return ((char *)p);
        if (!*p)
            return ((char *)NULL);
    }
    /* NOTREACHED */
}

int strcrl(char *str, const char what, const char with)
{
    int i = 0;
    while (str[i] != 0)
    {
        if (str[i] == what)
            str[i] = with;
        i++;
    }
    return i;
}

int strcount(char str[], char c)
{
    int i = 0;
    while (*str--)
        if (*str == c)
            i++;
    return i;
}

int strsplit(char str[], char delim)
{
    int n = 0;
    int i = 0;
    while (str[i])
    {
        if (str[i] == delim)
        {
            str[i] = 0;
            n++;
        }
        i++;
    }
    n++;
    return n;
}

int str_begins_with(const char str[], const char with[])
{
    int j = strlen(with);
    int i = 0;
    int ret = 1;
    while (with[j] != 0)
    {
        if (str[i] != with[i])
        {
            ret = 0;
            break;
        }
        j--;
        i++;
    }
    return ret;
}

int str_backspace(char str[], char c)
{
    int i = strlen(str);
    i--;
    while (i)
    {
        i--;
        if (str[i] == c)
        {
            str[i + 1] = 0;
            return 1;
        }
    }
    return 0;
}

char *strcat(char *s, const char *append)
{
    char *save = s;

    for (; *s; ++s)
        ;
    while ((*s++ = *append++) != '\0')
        ;
    return (save);
}

char *strcpy(char *to, const char *from)
{
    char *save = to;

    for (; (*to = *from) != '\0'; ++from, ++to)
        ;
    return (save);
}

size_t strcspn(const char *s1, const char *s2)
{
    const char *p, *spanp;
    char c, sc;

    /*
	 * Stop as soon as we find any character from s2.  Note that there
	 * must be a NUL in s2; it suffices to stop when we find that, too.
	 */
    for (p = s1;;)
    {
        c = *p++;
        spanp = s2;
        do
        {
            if ((sc = *spanp++) == c)
                return (p - 1 - s1);
        } while (sc != 0);
    }
    /* NOTREACHED */
}

char *strdup(const char *str)
{
    size_t siz;
    char *copy;

    siz = strlen(str) + 1;
    if ((copy = malloc(siz)) == NULL)
        return (NULL);
    // (void)memcpy(copy, str, siz);
    return (copy);
}

size_t strlcat(char *dst, const char *src, size_t siz)
{
    char *d = dst;
    const char *s = src;
    size_t n = siz;
    size_t dlen;

    /* Find the end of dst and adjust bytes left but don't go past end */
    while (n-- != 0 && *d != '\0')
        d++;
    dlen = d - dst;
    n = siz - dlen;

    if (n == 0)
        return (dlen + strlen(s));
    while (*s != '\0')
    {
        if (n != 1)
        {
            *d++ = *s;
            n--;
        }
        s++;
    }
    *d = '\0';

    return (dlen + (s - src)); /* count does not include NUL */
}

size_t strlcpy(char *dst, const char *src, size_t siz)
{
    char *d = dst;
    const char *s = src;
    size_t n = siz;

    /* Copy as many bytes as will fit */
    if (n != 0)
    {
        while (--n != 0)
        {
            if ((*d++ = *s++) == '\0')
                break;
        }
    }

    /* Not enough room in dst, add NUL and traverse rest of src */
    if (n == 0)
    {
        if (siz != 0)
            *d = '\0'; /* NUL-terminate dst */
        while (*s++)
            ;
    }

    return (s - src - 1); /* count does not include NUL */
}

char *strncat(char *dst, const char *src, size_t n)
{
    if (n != 0)
    {
        char *d = dst;
        const char *s = src;

        while (*d != 0)
            d++;
        do
        {
            if ((*d = *s++) == 0)
                break;
            d++;
        } while (--n != 0);
        *d = 0;
    }
    return (dst);
}

int strncmp(const char *s1, const char *s2, size_t n)
{
    if (n == 0)
        return (0);
    do
    {
        if (*s1 != *s2++)
            return (*(unsigned char *)s1 - *(unsigned char *)--s2);
        if (*s1++ == 0)
            break;
    } while (--n != 0);
    return (0);
}

/*
 * Copy src to dst, truncating or null-padding to always copy n bytes.
 * Return dst.
 */
char *strncpy(char *dst, const char *src, size_t n)
{
    if (n != 0)
    {
        char *d = dst;
        const char *s = src;

        do
        {
            if ((*d++ = *s++) == 0)
            {
                /* NUL pad the remaining n-1 bytes */
                while (--n != 0)
                    *d++ = 0;
                break;
            }
        } while (--n != 0);
    }
    return (dst);
}

char *strndup(const char *s, size_t n)
{
    size_t slen = (size_t)strlen(s);
    char *copy;

    if (slen < n)
        n = slen;
    copy = malloc(n + 1);
    if (copy)
    {
        // memcpy(copy, s, n);
        copy[n] = 0;
    }
    return copy;
}

size_t strnlen(const char *str, size_t maxlen)
{
    // char *p = memchr(str, 0, maxlen);

    // if (p == NULL)
    //     return maxlen;
    // else
    //     return (p - str);
}

/*
 * Find the first occurrence in s1 of a character in s2 (excluding NUL).
 */
char *strpbrk(const char *s1, const char *s2)
{
    const char *scanp;
    int c, sc;

    while ((c = *s1++) != 0)
    {
        for (scanp = s2; (sc = *scanp++) != 0;)
            if (sc == c)
                return ((char *)(s1 - 1));
    }
    return (NULL);
}

char *strrchr(const char *p, int ch)
{
    char *save;

    for (save = NULL;; ++p)
    {
        if (*p == ch)
            save = (char *)p;
        if (!*p)
            return (save);
    }
    /* NOTREACHED */
}

/*
 * Get next token from string *stringp, where tokens are possibly-empty
 * strings separated by characters from delim.
 *
 * Writes NULs into the string at *stringp to end tokens.
 * delim need not remain constant from call to call.
 * On return, *stringp points past the last NUL written (if there might
 * be further tokens), or is NULL (if there are definitely no more tokens).
 *
 * If *stringp is NULL, strsep returns NULL.
 */
char *strsep(char **stringp, const char *delim)
{
    char *s;
    const char *spanp;
    int c, sc;
    char *tok;

    if ((s = *stringp) == NULL)
        return (NULL);
    for (tok = s;;)
    {
        c = *s++;
        spanp = delim;
        do
        {
            if ((sc = *spanp++) == c)
            {
                if (c == 0)
                    s = NULL;
                else
                    s[-1] = 0;
                *stringp = s;
                return (tok);
            }
        } while (sc != 0);
    }
    /* NOTREACHED */
}

/*
 * Span the string s2 (skip characters that are in s2).
 */
size_t strspn(const char *s1, const char *s2)
{
    const char *p = s1, *spanp;
    char c, sc;

    /*
	 * Skip any characters in s2, excluding the terminating \0.
	 */
cont:
    c = *p++;
    for (spanp = s2; (sc = *spanp++) != 0;)
        if (sc == c)
            goto cont;
    return (p - 1 - s1);
}

char *strtok_r(char *s, const char *delim, char **last)
{
    char *spanp;
    int c, sc;
    char *tok;

    if (s == NULL && (s = *last) == NULL)
        return (NULL);

    /*
	 * Skip (span) leading delimiters (s += strspn(s, delim), sort of).
	 */
cont:
    c = *s++;
    for (spanp = (char *)delim; (sc = *spanp++) != 0;)
    {
        if (c == sc)
            goto cont;
    }

    if (c == 0)
    { /* no non-delimiter characters */
        *last = NULL;
        return (NULL);
    }
    tok = s - 1;

    /*
	 * Scan token (scan for delimiters: s += strcspn(s, delim), sort of).
	 * Note that delim must have one NUL; we stop if we see that, too.
	 */
    for (;;)
    {
        c = *s++;
        spanp = (char *)delim;
        do
        {
            if ((sc = *spanp++) == c)
            {
                if (c == 0)
                    s = NULL;
                else
                    s[-1] = 0;
                *last = s;
                return (tok);
            }
        } while (sc != 0);
    }
    /* NOTREACHED */
}

char *strtok(char *s, const char *delim)
{
    static char *last;

    return strtok_r(s, delim, &last);
}

/*
 * Transform string s2 to string s1 using the current locale so that
 * strcmp of transformed strings yields the same result as strcoll.
 * Since Bionic really does not support locales, we assume we always use
 * the C locale.
 *
 * This function is provided to make libstdc++-v3 usable.
 */
size_t strxfrm(char *s1, const char *s2, size_t n)
{
    size_t len = strlen(s2) + 1;

    if (len < n)
        n = len;
    // memcpy(s1, s2, n);
    return len;
}
