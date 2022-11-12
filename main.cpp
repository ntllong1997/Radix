#include "radix.hpp"

int main(int argc, char **argv) {
  int base = stoi(argv[1]);
  for (int i = 1; i <= 4; i++) {
    struct timespec start, stop;
    unsigned int accum[10], sum = 0;

    int size = pow(10, i);
    cout << "Radix Sort: base = " << base << " size = " << size << endl;
    vector<int> arr = genRandomNum(size);
    vector<string> unsorted = toString(arr, base);
    vector<string> sorted = unsorted;

    for (int i = 0; i < 10; i++) {
      if (clock_gettime(CLOCK_REALTIME, &start) == -1) {
        perror("clock gettime");
        exit(EXIT_FAILURE);
      }

      MSD(sorted, 0, base);

      if (clock_gettime(CLOCK_REALTIME, &stop) == -1) {
        perror("clock gettime");
        exit(EXIT_FAILURE);
      }
      accum[i] = (stop.tv_sec - start.tv_sec) + (stop.tv_nsec - start.tv_nsec);
    }
    if (size <= 10) {
      cout << "Unsorted: ";
      print(unsorted);
      cout << "Sorted: ";
      print(sorted);
    }
    for (int i = 0; i < 10; i++) {
      cout << "Pass " << i + 1 << ":\t\t" << accum[i] << "\t\tnanosecondes"
           << endl;
      sum = sum + accum[i];
    }
    cout << "Average:\t" << sum/10 << "\t\tnanosecondes"
           << endl;
  }
}
