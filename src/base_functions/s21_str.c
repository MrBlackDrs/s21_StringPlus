#include "../s21_string.h"

char *s21_strchr(const char *str, int c) {
  const char *result = s21_NULL;
  for (s21_size_t i = 0; i <= s21_strlen(str); i++) {
    if (str[i] == c) {
      result = (str + i);
      break;
    }
  }
  return (char *)result;
}

s21_size_t s21_strcspn(const char *str1, const char *str2) {
  int res = INT_MAX;
  s21_size_t i = 0;
  while (i < s21_strlen(str1)) {
    s21_size_t j = 0;
    int tmp = 0, flag = 0;
    while (j < s21_strlen(str2)) {
      if (str1[i] == str2[j]) {
        flag = 1;
        tmp = i;
        break;
      }
      j++;
    }
    i++;
    if (tmp < res && flag) {
      res = tmp;
    }
  }
  return res == INT_MAX ? (int)s21_strlen(str1) : res;
}

s21_size_t s21_strlen(const char *str) {
  s21_size_t n = 0;
  if (str) {
    while (*str != '\0') {
      str++;
      n++;
    }
  }
  return n;
}

char *s21_strncat(char *dest, const char *src, s21_size_t n) {
  s21_size_t l = s21_strlen(dest);
  for (s21_size_t i = 0; i < n; i++, l++) {
    dest[l] = src[i];
  }
  dest[s21_strlen(dest)] = '\0';
  return dest;
}

int s21_strncmp(const char *str1, const char *str2, s21_size_t n) {
  int res = 0;
  s21_size_t i = 0;
  while (i < n) {
    if (str1[i] < str2[i]) {
      res = -(str2[i] - str1[i]);
    }
    if (str1[i] > str2[i]) {
      res = str1[i] - str2[i];
    }
    if (res != 0) {
      break;
    }
    i++;
  }
  return res;
}

char *s21_strncpy(char *dest, const char *src, s21_size_t n) {
  s21_memset(dest, '\0', n);

  for (s21_size_t i = 0; i < n && src[i]; i++) {
    dest[i] = src[i];
  }

  return dest;
}

char *s21_strpbrk(const char *str1, const char *str2) {
  const char *res = s21_NULL;
  for (s21_size_t i = 0; i < s21_strlen(str1); i++) {
    for (s21_size_t j = 0; j < s21_strlen(str2); j++) {
      if (str1[i] == str2[j]) {
        res = (str1 + i);
        break;
      }
    }
    if (res != s21_NULL) {
      break;
    }
  }
  return (char *)res;
}

char *s21_strrchr(const char *str, int c) {
  const char *res = s21_NULL;
  for (s21_size_t i = 0; i <= s21_strlen(str); i++) {
    if (str[i] == c) {
      res = (str + i);
    }
  }
  return (char *)res;
}

char *s21_strstr(const char *haystack, const char *needle) {
  unsigned int i = 0;
  int flag = 1;
  for (i = 0; haystack[i] != '\0' && flag == 1; i++) {
    flag = 0;
    for (unsigned int j = 0; needle[j] != '\0' && flag == 0; j++) {
      if ((haystack[i + j] == '\0') || (haystack[i + j] != needle[j])) {
        flag = 1;
      }
    }
  }
  i--;
  return flag ? s21_NULL : (char *)&haystack[i];
}

char *s21_strtok(char *str, const char *delim) {
  static char *final;
  register int ch;

  if (str == 0) {
    str = final;
  }
  do {
    if ((ch = *str++) == '\0') {
      str = 0;
      break;
    }
  } while (s21_strchr(delim, ch));
  if (str != 0) {
    --str;
    final = str + s21_strcspn(str, delim);
    if (*final != 0) {
      *final++ = 0;
    }
  }
  return str;
}