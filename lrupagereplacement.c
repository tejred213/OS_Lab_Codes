#include <stdio.h>

int counter = 0;

void accept(int arr[20], int n) {
  printf("\n\nEnter the Complete String first\n");
  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }
}

int in_frame(int arr[20], int n) {
  for (int i = 0; i < n; i++) {
    arr[i] = -1;
  }
}

// WILL CHECK WHETHER FRAME IS INTIALLY EMPTY OR NOT
int frame_check(int arr[10], int frame_size) {
  for (int i = 0; i < frame_size; i++) {
    if (arr[i] == -1) {
      return i;
    }
  }
}

// WILL CHECK WHTEHER FRAME IS EMPTY OR NOT
// IF EMPTY THEN RETURN THE FIRST POSITION
int frame_empty(int frame_arr[20], int frame_size) {
  int count = -1;
  for (int i = 0; i < frame_size; i++) {
    if (frame_arr[i] == -1) {
      count = i;
      break;
    }
  }
  return count;
}

int page_absent(int frame[20], int frame_size, int page_value, int priority[20],
                int frame_arr[20]) {
  int count = -1;
  for (int i = 0; i < frame_size; i++) {
    // PAGE FOUND
    if (frame[i] == page_value) {
      count = 1;
      priority[i] = counter;
      counter++;
      break;
    }
  }
  if (count == 1) {
    // PRESENT

    return 0;
  } else {
    return 1;
  }
}

int main() {
  int refer_string[20];
  int n, frame_size;
  int frame_arr[20];
  int priority[20];
  int pagefault = 0;
  int index = 0; // POINTER TO THE FRAME WHICH NEEDS TO BE REPLACED

  printf("Enter the number of elements you want in Reference String\n");
  scanf("%d", &n);
  accept(refer_string, n);

  printf("Enter the Frame Size\n");
  scanf("%d", &frame_size);
  in_frame(frame_arr, frame_size);

  for (int i = 0; i < n; i++) {
    // CURRENT PAGE VALUE
    int page_value = refer_string[i];

    // TO CHECK WHETHER A PAGE IS PRESENT
    int k = page_absent(frame_arr, frame_size, page_value, priority, frame_arr);

    if (k == 1) // PAGE ABSENT
    {
      pagefault++;

      // CASE-01: IF FRAME IS EMPTY THEN DIRECTLY REPLACE THE PAGE
      int j = frame_empty(frame_arr, frame_size);

      if (j >= 0) {
        frame_arr[j] = refer_string[i];
        priority[j] = counter;
        counter++;
      }

      // CASE-02: IF FRAME NOT EMPTY, THEN REPLACING PREVIOUS FRAMES
      else {
        printf("\n");

        int min = priority[0];
        for (int l = 1; l < frame_size; l++) {
          if (priority[l] < min) {
            index = l;
            min = priority[l];
          }
        }
        frame_arr[index] = refer_string[i];
      }
    }
  }
  printf("Total Page Fault = %d\n", (pagefault - 1));

  return 0;
}