#include "s21_cat.h"

void cat_print(FILE *file, flags *flag) {
  int currentSymb, previousSymb = 1, count = 1, firstLine = 1, tmp = 0;
  if (flag->n == 1 && flag->b == 1) {
    flag->n = 0;
  }
  while ((currentSymb = fgetc(file)) != EOF) {
    int skip = 0;
    if (flag->s == 1) {
      if (currentSymb == '\n') {
        skip = 1;
        tmp++;
      } else {
        tmp = 0;
      }
      if (tmp == 1 || tmp == 2) {
        skip = 0;
        currentSymb = '\n';
      }
    }
    if (flag->b == 1) {
      if ((previousSymb == '\n' && currentSymb != previousSymb) ||
          (firstLine && currentSymb != '\n')) {
        printf("%6d\t", count);
        firstLine = 0;
        count++;
      }
    }
    if (flag->n == 1) {
      if ((previousSymb == '\n' || firstLine) && skip == 0) {
        printf("%6d\t", count);
        firstLine = 0;
        count++;
      }
    }
    if (flag->e == 1 && skip == 0) {
      if (currentSymb == '\n') printf("$");
    }
    if (flag->t == 1) {
      if (currentSymb == '\t') {
        printf("^I");
        skip = 1;
      }
    }
    if (flag->v == 1) {
      if (currentSymb < 32 && currentSymb != 9 && currentSymb != 10) {
        printf("^%c", currentSymb + 64);

        skip = 1;
      } else if (currentSymb > 127 && currentSymb < 160) {
        printf("M-^%c", currentSymb - 64);
        skip = 1;
      } else if (currentSymb == 127) {
        printf("^%c", currentSymb - 64);
        skip = 1;
      }
    }
    previousSymb = currentSymb;
    if (skip != 1) {
      printf("%c", currentSymb);
    }
  }
}

void cat_file(int argc, char **argv, flags *flag) {
  int i;
  if (flag)
    i = flag->count + 1;
  else
    i = 1;
  if (flag->count == argc - 1) {
    cat_print(stdin, flag);
  }
  for (; i < argc; i++) {
    FILE *file = fopen(argv[i], "rb");
    if (file) {
      cat_print(file, flag);
      fclose(file);
    } else {
      fprintf(stderr, "s21_cat: %s: No such file or directory\n", argv[i]);
    }
  }
}

char parse_flags(int argc, char **argv, flags *flag) {
  for (int i = 1; i < argc; i++) {
    if (argv[i][0] == '-') {
      flag->count++;
      scanFlags(argv[i], flag);
      if (flag->count == 0) {
        return argv[i][1];
      }
    }
  }
  return 0;
}

void scanFlags(char *args, flags *flag) {
  int flagLen = strlen(args);
  for (int i = 1; i < flagLen; i++) {
    if (args[i] == 'n') {
      flag->n = true;
    } else if (args[i] == 'b') {
      flag->b = true;
    } else if (args[i] == 'e') {
      flag->e = true;
      flag->v = true;
    } else if (args[i] == 's') {
      flag->s = true;
    } else if (args[i] == 'v') {
      flag->v = true;
    } else if (args[i] == 't') {
      flag->t = true;
      flag->v = true;
    } else if (args[i] == 'E') {
      flag->e = true;
    } else if (args[i] == 'T') {
      flag->t = true;
    } else if (args[i] == '-') {
      printf("%s\n", args);
      if (!strcmp(args, "--number-nonblank")) {
        flag->b = 1;
      } else if (!strcmp(args, "--number")) {
        flag->n = 1;
      } else if (!strcmp(args, "--squeeze-blank")) {
        flag->s = 1;
      }
      break;
    } else {
      flag->count = 0;
    }
  }
}

int main(int argc, char **argv) {
  flags flag = {0};
  if (argc == 1) {
    cat_print(stdin, &flag);
  } else {
    if (argv[1][0] == '-') {
      char errFlag = parse_flags(argc, argv, &flag);
      if (!flag.count && optind) {
        printf("s21_cat: illegal option — «%c»\n", errFlag);
      } else {
        cat_file(argc, argv, &flag);
      }
    } else {
      cat_file(argc, argv, &flag);
    }
  }
  return 0;
}
