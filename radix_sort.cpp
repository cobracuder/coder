#include <bits/stdc++.h>
using namespace std;

void radixSortUint32(vector<uint32_t>& arr) {
    int n = arr.size();
    const int bitsPerPass = 8;
    const int totalBits = 32;
    const int bucketCount = 1 << bitsPerPass;
    const int mask = bucketCount - 1;

    vector<uint32_t> temp(n);
    vector<int> count(bucketCount);

    for (int bitOffset = 0; bitOffset < totalBits; bitOffset += bitsPerPass) {

        // Reset count
        fill(count.begin(), count.end(), 0);

        // Count frequency
        for (int i = 0; i < n; i++) {
            int digit = (arr[i] >> bitOffset) & mask;
            count[digit]++;
        }

        // Prefix sum → starting index
        int sum = 0;
        for (int i = 0; i < bucketCount; i++) {
            int c = count[i];
            count[i] = sum;
            sum += c;
        }

        // Stable placement (forward)
        for (int i = 0; i < n; i++) {
            int digit = (arr[i] >> bitOffset) & mask;
            temp[count[digit]++] = arr[i];
        }

        // Swap buffers
        arr.swap(temp);
    }
}

uint32_t encodeInt(int32_t x) {
    return static_cast<uint32_t>(x) ^ 0x80000000u;
}

int32_t decodeInt(uint32_t x) {
    return static_cast<int32_t>(x ^ 0x80000000u);
}

void radixSortInt32(vector<int32_t>& arr) {
    vector<uint32_t> temp(arr.size());

    // Encode
    for (int i = 0; i < arr.size(); i++) {
        temp[i] = encodeInt(arr[i]);
    }

    // Sort
    radixSortUint32(temp);

    // Decode
    for (int i = 0; i < arr.size(); i++) {
        arr[i] = decodeInt(temp[i]);
    }
}

uint32_t encodeFloat(float f) {
    uint32_t x;
    memcpy(&x, &f, sizeof(float));

    if (x & 0x80000000u) {
        return ~x;  // negative
    } else {
        return x ^ 0x80000000u;  // positive
    }
}

float decodeFloat(uint32_t x) {
    if (x & 0x80000000u) {
        x ^= 0x80000000u;
    } else {
        x = ~x;
    }

    float f;
    memcpy(&f, &x, sizeof(float));
    return f;
}

void radixSortFloat(vector<float>& arr) {
    vector<uint32_t> temp(arr.size());

    // Encode
    for (int i = 0; i < arr.size(); i++) {
        temp[i] = encodeFloat(arr[i]);
    }

    // Sort
    radixSortUint32(temp);

    // Decode
    for (int i = 0; i < arr.size(); i++) {
        arr[i] = decodeFloat(temp[i]);
    }
}

int main() {
    vector<int32_t> a = {5, -10, 3, -1, 0};
    radixSortInt32(a);

    for (auto x : a) cout << x << " ";
    cout << "\n";

    vector<float> b = {3.2, -1.5, 0.0, 7.1, -3.3};
    radixSortFloat(b);

    for (auto x : b) cout << x << " ";
}
