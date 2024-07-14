#include "s21_grep.h"

t_flag *init_flags(char *inf_flags) {
  t_flag *flags = extended_realloc(NULL, sizeof(t_flag) * NUM_FLAGS);
  for (int i = 0; i < NUM_FLAGS; i++) {
    (*(flags + i)).flag = *(inf_flags + i);
    (*(flags + i)).is_exist = false;
  }
  return flags;
}

void free_grep(t_grep *information, t_flag **flags) {
  free((*information).templates);
  free(*flags);
  for (size_t i = 0; i < information->num_filenames; i++)
    free(*((*information).filenames + i));
  free((*information).filenames);
}

int main(int argc, char **argv) {
  if (argc == 1) return 0;
  t_grep information = {0};
  t_flag *flags = init_flags("eivclnhsfo");
  parse_options(argc, argv, &flags, &information);
  process_files(flags, information);
  free_grep(&information, &flags);
  return 0;
}
