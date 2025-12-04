//Bioskop USU

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int interpolationSearch(int arr[], int n, int x) {
    int low = 0, high = n - 1;

    while (low <= high && x >= arr[low] && x <= arr[high]) {
        if (low == high) {
            if (arr[low] == x) return low;
            return -1;
        }

        int pos = low + ( (double)(high - low) * (x - arr[low]) / (arr[high] - arr[low]) );

        if (arr[pos] == x)
            return pos;
        else if (arr[pos] < x)
            low = pos + 1;
        else
            high = pos - 1;
    }

    return -1; 
}

int main () {
  int n;
  cin >> n;

  int arr[n];
  for (int i = 0; i < n; i++) {
      cin >> arr[i];
  }

  int cari;
  cin >> cari;

  cout << "Mencari Kursi No: " << cari << endl;

  int index = interpolationSearch(arr, n, cari);

  if (index != -1) {
      cout << "Status: TERSEDIA" << endl;
      cout << "Detail: Ditemukan pada index [" << index << "]" << endl;
  } else {
      cout << "Status: TIDAK TERSEDIA" << endl;

      int closest = arr[0];
      int minDiff = abs(arr[0] - cari);

      for (int i = 1; i < n; i++) {
          int diff = abs(arr[i] - cari);
           if (diff < minDiff) {
            minDiff = diff;
            closest = arr[i];
          }
        }

      cout << "Opsi: Kursi terdekat yang tersedia adalah No. " << closest << endl;
    }

    return 0;
}