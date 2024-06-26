#include "../tests.h"

START_TEST(strncmp_test_1) {
  char str1[] = "Hello!";
  char str2[] = "Hello!";
  ck_assert_int_eq(s21_strncmp(str1, str2, 7) == 0,
                   strncmp(str1, str2, 7) == 0);
}
END_TEST

START_TEST(strncmp_test_2) {
  char str1[6] = "";
  char str2[6] = "world";
  ck_assert_int_eq(s21_strncmp(str1, str2, 6) < 0, strncmp(str1, str2, 6) < 0);
}
END_TEST

START_TEST(strncmp_test_3) {
  char str1[6] = "world";
  char str2[6] = "";
  ck_assert_int_eq(s21_strncmp(str1, str2, 6) > 0, strncmp(str1, str2, 6) > 0);
}
END_TEST

START_TEST(strncmp_test_4) {
  char str1[6] = "world";
  char str2[6] = "worry";
  ck_assert_int_eq(s21_strncmp(str1, str2, 2) == 0,
                   strncmp(str1, str2, 2) == 0);
}
END_TEST

START_TEST(strncmp_test_5) {
  char str1[] = "Hello";
  char str2[] = "HellO";
  ck_assert_int_eq(s21_strncmp(str1, str2, 6) > 0, strncmp(str1, str2, 6) > 0);
}
END_TEST

START_TEST(strncmp_test_6) {
  char str1[] = "HellO";
  char str2[] = "Hello";
  ck_assert_int_eq(s21_strncmp(str1, str2, 6) < 0, strncmp(str1, str2, 6) < 0);
}
END_TEST

START_TEST(strncmp_test_7) {
  char str1[] = "Hello";
  char str2[] = "Hello world";
  ck_assert_int_eq(s21_strncmp(str1, str2, 6) > 0, strncmp(str1, str2, 6) > 0);
}
END_TEST

START_TEST(strncmp_test_8) {
  char str1[] = "Hello world";
  char str2[] = "Hello";
  ck_assert_int_eq(s21_strncmp(str1, str2, 6) < 0, strncmp(str1, str2, 6) < 0);
}
END_TEST

TCase *s21_strncmp_test(void) {
  TCase *tcase = tcase_create(TCASE_NAME);

  tcase_add_test(tcase, strncmp_test_1);
  tcase_add_test(tcase, strncmp_test_2);
  tcase_add_test(tcase, strncmp_test_3);
  tcase_add_test(tcase, strncmp_test_4);
  tcase_add_test(tcase, strncmp_test_5);
  tcase_add_test(tcase, strncmp_test_6);
  tcase_add_test(tcase, strncmp_test_7);
  tcase_add_test(tcase, strncmp_test_8);

  return tcase;
}