#include "../tests.h"

START_TEST(strlen_test_1) {
  char str[] = "Hello!";
  ck_assert_int_eq(s21_strlen(str), strlen(str));
}
END_TEST

START_TEST(strlen_test_2) {
  char str[] = "";
  ck_assert_int_eq(s21_strlen(str), strlen(str));
}
END_TEST

START_TEST(strlen_test_3) {
  char str[] = "   ";
  ck_assert_int_eq(s21_strlen(str), strlen(str));
}
END_TEST

START_TEST(strlen_test_4) {
  char str[] = "123";
  ck_assert_int_eq(s21_strlen(str), strlen(str));
}
END_TEST

START_TEST(strlen_test_5) {
  char str[] = "Hello\0";
  ck_assert_int_eq(s21_strlen(str), strlen(str));
}
END_TEST

START_TEST(strlen_test_6) {
  char str[] = "Hello\n";
  ck_assert_int_eq(s21_strlen(str), strlen(str));
}
END_TEST

START_TEST(strlen_test_7) {
  char str[] = "Hello \0 World!";
  ck_assert_int_eq(s21_strlen(str), strlen(str));
}
END_TEST

START_TEST(strlen_test_8) {
  char str[] = "Hello!\\\0";
  ck_assert_int_eq(s21_strlen(str), strlen(str));
}
END_TEST

START_TEST(strlen_test_null) {
  char *str = s21_NULL;
  ck_assert_int_eq(s21_strlen(str), 0);
}
END_TEST

TCase *s21_strlen_test(void) {
  TCase *tcase = tcase_create(TCASE_NAME);

  tcase_add_test(tcase, strlen_test_1);
  tcase_add_test(tcase, strlen_test_2);
  tcase_add_test(tcase, strlen_test_3);
  tcase_add_test(tcase, strlen_test_4);
  tcase_add_test(tcase, strlen_test_5);
  tcase_add_test(tcase, strlen_test_6);
  tcase_add_test(tcase, strlen_test_7);
  tcase_add_test(tcase, strlen_test_8);
  tcase_add_test(tcase, strlen_test_null);

  return tcase;
}