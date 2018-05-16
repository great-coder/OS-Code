// Copyright (c) 2018 M D
//
// This software is released under the MIT License.
// https://opensource.org/licenses/MIT

#ifndef STR_H
#define STR_H

#include "type.h"

void int_to_ascii(int n, char str[]);
int ascii_to_int(const char s[]);
void hex_to_ascii(int n, char str[]);
int strcrl(char str[], const char what, const char with);
void reverse(char s[]);
int strlen(const char *str);
size_t strnlen(const char *str, size_t maxlen);
void backspace(char s[]);
void append(char s[], char n);
int strcmp(const char *s1, const char *s2);
int strncmp(const char *s1, const char *s2, size_t n);
int strcasecmp(const char *s1, const char *s2);
int strncasecmp(const char *s1, const char *s2, size_t n);
char *strstr(const char *s1, const char *s2);
char *strcasestr(const char *s, const char *find);
int strch(const char s[], const char ch);
char *strchr(const char *p, int ch);
char *strrchr(const char *p, int ch);
int strcount(char str[], char c);
int strsplit(char str[], char delim);
char *strsep(char **stringp, const char *delim);
int str_begins_with(const char str[], const char with[]);
int str_backspace(char str[], char c);
char *strcat(char *s, const char *append);
char *strncat(char *dst, const char *src, size_t n);
size_t strlcat(char *dst, const char *src, size_t siz);
char *strcpy(char *to, const char *from);
char *strncpy(char *dst, const char *src, size_t n);
size_t strlcpy(char *dst, const char *src, size_t siz);
size_t strspn(const char *s1, const char *s2);
size_t strcspn(const char *s1, const char *s2);
char *strdup(const char *str);
char *strndup(const char *s, size_t n);
char *strpbrk(const char *s1, const char *s2);
char *strtok(char *s, const char *delim);
size_t strxfrm(char *s1, const char *s2, size_t n);

#endif