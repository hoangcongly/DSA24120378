#include <iostream>
#include <fstream>
#include <cmath>
#include <cstring>
#include <time.h>
#include <chrono>
using namespace std;

template <class T>
void HoanVi(T& a, T& b) {
    T x = a;
    a = b;
    b = x;
}
void selection_Sort(int* a, int n, long long& count);
void insertion_Sort(int* a, int n, long long& count);
void bubble_Sort(int* a, int n, long long& count);
void shaker_Sort(int* a, int n, long long& count);
void shell_Sort(int* a, int n, long long& count);
void heapify(int* a, int n, int i, long long& count);
void heap_Sort(int* a, int n, long long& count);
void merge(int* a, int left, int mid, int right, long long& count);
void merge_Sort(int* a, int left, int right, long long& count);
int partition(int* a, int low, int high, long long& count);
void quick_Sort(int* a, int low, int high, long long& count);
void counting_Sort(int* a, int n, int maxval, long long& count);
int getMax(int* a, int n, long long& count);
void countingSort_Digit(int* a, int n, int exp, long long& count);
void radix_Sort(int* a, int n, long long& count);
void flashSort(int* arr, int n, long long& count);
void readData(const char* filepath, int*& a, int& n);
void writeData(const char* filepath, int* a, int n);

int main(int argc, char* argv[]) {
    if (argc != 7 || strcmp(argv[1], "-a") != 0 || strcmp(argv[3], "-i") != 0 || strcmp(argv[5], "-o") != 0) {
        cout << "Sai cu phap. Dung: program.exe -a <ten-thuat-toan> -i <input.txt> -o <output.txt>\n";
        return 1;
    }

    char* algorithm = argv[2];
    char* inputFile = argv[4];
    char* outputFile = argv[6];
    int n;
    int* a = nullptr;
    readData(inputFile, a, n);

    chrono::duration<double> duration;
    if (strcmp(algorithm, "selection-sort") == 0) {
        long long count = 0;
        auto start = chrono::high_resolution_clock::now();
        selection_Sort(a, n, count);
        auto end = chrono::high_resolution_clock::now();
        duration = end - start;
        cout << "Time: " << duration.count() * 1000 << " ms." << endl;
        cout << "Tong so phep so sanh: " << count << endl;
    }
    else if (strcmp(algorithm, "insertion-sort") == 0) {
        long long count = 0;
        auto start = chrono::high_resolution_clock::now();
        insertion_Sort(a, n, count);
        auto end = chrono::high_resolution_clock::now();
        duration = end - start;
        cout << "Time: " << duration.count() * 1000 << " ms." << endl;
        cout << "Tong so phep so sanh: " << count << endl;
    }
    else if (strcmp(algorithm, "bubble-sort") == 0) {
        long long count = 0;
        auto start = chrono::high_resolution_clock::now();
        bubble_Sort(a, n, count);
        auto end = chrono::high_resolution_clock::now();
        duration = end - start;
        cout << "Time: " << duration.count() * 1000 << " ms." << endl;
        cout << "Tong so phep so sanh: " << count << endl;
    }
    else if (strcmp(algorithm, "shaker-sort") == 0) {
        long long count = 0;
        auto start = chrono::high_resolution_clock::now();
        shaker_Sort(a, n, count);
        auto end = chrono::high_resolution_clock::now();
        duration = end - start;
        cout << "Time: " << duration.count() * 1000 << " ms." << endl;
        cout << "Tong so phep so sanh: " << count << endl;
    }
    else if (strcmp(algorithm, "shell-sort") == 0) {
        long long count = 0;
        auto start = chrono::high_resolution_clock::now();
        shell_Sort(a, n, count);
        auto end = chrono::high_resolution_clock::now();
        duration = end - start;
        cout << "Time: " << duration.count() * 1000 << " ms." << endl;
        cout << "Tong so phep so sanh: " << count << endl;
    }
    else if (strcmp(algorithm, "heap-sort") == 0) {
        long long count = 0;
        auto start = chrono::high_resolution_clock::now();
        heap_Sort(a, n, count);
        auto end = chrono::high_resolution_clock::now();
        duration = end - start;
        cout << "Time: " << duration.count() * 1000 << " ms." << endl;
        cout << "Tong so phep so sanh: " << count << endl;
    }
    else if (strcmp(algorithm, "merge-sort") == 0) {
        long long count = 0;
        auto start = chrono::high_resolution_clock::now();
        merge_Sort(a, 0, n - 1, count);
        auto end = chrono::high_resolution_clock::now();
        duration = end - start;
        cout << "Time: " << duration.count() * 1000 << " ms." << endl;
        cout << "Tong so phep so sanh: " << count << endl;
    }
    else if (strcmp(algorithm, "quick-sort") == 0) {
        long long count = 0;
        auto start = chrono::high_resolution_clock::now();
        quick_Sort(a, 0, n - 1, count);
        auto end = chrono::high_resolution_clock::now();
        duration = end - start;
        cout << "Time: " << duration.count() * 1000 << " ms." << endl;
        cout << "Tong so phep so sanh: " << count << endl;
    }
    else if (strcmp(algorithm, "counting-sort") == 0) {
        long long count = 0;
        auto start = chrono::high_resolution_clock::now();
        counting_Sort(a, n, getMax(a, n, count), count);
        auto end = chrono::high_resolution_clock::now();
        duration = end - start;
        cout << "Time: " << duration.count() * 1000 << " ms." << endl;
        cout << "Tong so phep so sanh: " << count << endl;
    }
    else if (strcmp(algorithm, "radix-sort") == 0) {
        long long count = 0;
        auto start = chrono::high_resolution_clock::now();
        radix_Sort(a, n, count);
        auto end = chrono::high_resolution_clock::now();
        duration = end - start;
        cout << "Time: " << duration.count() * 1000 << " ms." << endl;
        cout << "Tong so phep so sanh: " << count << endl;
    }
    else if (strcmp(algorithm, "flash-sort") == 0) {
        long long count = 0;
        auto start = chrono::high_resolution_clock::now();
        flashSort(a, n, count);
        auto end = chrono::high_resolution_clock::now();
        duration = end - start;
        cout << "Time: " << duration.count() * 1000 << " ms." << endl;
        cout << "Tong so phep so sanh: " << count << endl;
    }
    else {
        cout << "Thuat toan khong hop le.\n";
        delete[] a;
        return 1;
    }



    writeData("output.txt", a, n);
    cout << "Thuat toan: " << algorithm << "\n";
    cout << "So luong phan tu: " << n << "\n";
    delete[] a;
    return 0;
}


void selection_Sort(int* a, int n, long long& count)
{

    for (int i = 0; i < n; i++)
    {
        count++;
        int min = i;
        for (int j = i + 1; j < n; j++)
        {
            count += 2;
            if (a[j] < a[min]) min = j;
        }
        HoanVi(a[i], a[min]);
    }
    count += 2;
}
void insertion_Sort(int* a, int n, long long& count)
{
    for (int i = 1; i < n; i++)
    {
        count++;
        int key = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > key)
        {
            count += 2;
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
        count++;
    }
    count++;
}
void bubble_Sort(int* a, int n, long long& count)
{
    for (int i = 0; i < n - 1; i++)
    {
        count++;
        for (int j = 0; j < n - i - 1; j++) {
            count += 2;
            if (a[j] > a[j + 1]) {
                HoanVi(a[j], a[j + 1]);
            }
        }
        count++;
    }
    count++;
}
void shaker_Sort(int* a, int n, long long& count)
{
    int left = 0;
    int right = n - 1;
    while (left < right)
    {
        count++;
        for (int i = left; i < right; i++)
        {
            count += 2;
            if (a[i] > a[i + 1])
            {
                HoanVi(a[i], a[i + 1]);
            }
        }
        count++;
        right--;
        for (int i = right; i > left; i--)
        {
            count += 2;
            if (a[i - 1] > a[i])
            {
                HoanVi(a[i], a[i - 1]);
            }
        }
        count++;
        left++;
    }
    count++;
}
void shell_Sort(int* a, int n, long long& count)
{
    for (int gap = n / 2; gap > 0; gap /= 2)
    {
        count++;
        for (int i = gap; i < n; i++)
        {
            count++;
            int temp = a[i];
            int j = i;

            while (j >= gap && a[j - gap] > temp)
            {
                count += 2;
                a[j] = a[j - gap];
                j -= gap;
            }
            a[j] = temp;
            count++;
        }
        count++;
    }
    count++;
}

void heapify(int* a, int n, int i, long long& count)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && a[left] > a[largest])
    {
        largest = left;
        count += 2;
    }
    if (right < n && a[right] > a[largest])
    {
        largest = right;
        count += 2;
    }
    if (largest != i)
    {
        count++;
        HoanVi(a[largest], a[i]);
        heapify(a, n, largest, count);
    }
}

void heap_Sort(int* a, int n, long long& count)
{
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        count++;
        heapify(a, n, i, count);
    }
    count++;
    for (int i = n - 1; i > 0; i--)
    {
        count++;
        HoanVi(a[0], a[i]);
        heapify(a, i, 0, count);
    }
    count++;
}

void merge(int* a, int left, int mid, int right, long long& count)
{
    int i = left;
    int j = mid + 1;
    int k = 0;
    int* temp = new int[right - left + 1];
    while (i <= mid && j <= right)
    {
        count += 3;
        if (a[i] <= a[j])
        {
            temp[k++] = a[i++];
        }
        else
        {
            temp[k++] = a[j++];
        }
    }
    count++;

    while (i <= mid)
    {
        count++;
        temp[k++] = a[i++];
    }
    count++;

    while (j <= right)
    {
        count++;
        temp[k++] = a[j++];
    }
    count++;

    for (int i = 0; i < right - left + 1; i++)
    {
        count++;
        a[left + i] = temp[i];
    }
    count++;
    delete[]temp;
}
void merge_Sort(int* a, int left, int right, long long& count)
{
    if (left < right)
    {
        count++;
        int mid = left + (right - left) / 2;
        merge_Sort(a, left, mid, count);
        merge_Sort(a, mid + 1, right, count);
        merge(a, left, mid, right, count);
    }
}
int partition(int* a, int low, int high, long long& count)
{
    int random = low + rand() % (high - low + 1);
    HoanVi(a[random], a[high]);

    int pivot = a[high];
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        count += 2;
        if (a[j] < pivot)
        {
            i++;
            HoanVi(a[i], a[j]);
        }
    }

    count++;
    HoanVi(a[i + 1], a[high]);
    return i + 1;
}
void quick_Sort(int* a, int low, int high, long long& count)
{
    if (low < high)
    {
        count++;
        int pivot = partition(a, low, high, count);
        quick_Sort(a, low, pivot - 1, count);
        quick_Sort(a, pivot + 1, high, count);
    }
}

void counting_Sort(int* a, int n, int maxval, long long& count)
{
    int* temp = new int[maxval + 1]();
    int* output = new int[n];

    for (int i = 0; i < n; i++)
    {
        count++;
        temp[a[i]]++;
    }
    count++;

    for (int i = 1; i <= maxval; i++)
    {
        count++;
        temp[i] += temp[i - 1];
    }
    count++;

    for (int i = n - 1; i >= 0; i--)
    {
        count++;
        output[temp[a[i]] - 1] = a[i];
        temp[a[i]]--;
    }
    count++;

    for (int i = 0; i < n; i++)
    {
        count++;
        a[i] = output[i];
    }
    count++;

    delete[] temp;
    delete[] output;
}


int getMax(int* a, int n, long long& countcmp) {
    int max = a[0];
    for (int i = 0;i < n;i++) {
        countcmp += 2;
        if (a[i] > max) max = a[i];
    }
    countcmp++;
    return max;
}

void countingSort_Digit(int* a, int n, int exp, long long& countcmp)
{
    int* output = new int[n];
    int count[10] = { 0 };

    for (int i = 0; i < n; i++)
    {
        count[(a[i] / exp) % 10]++;
        countcmp++;
    }
    countcmp++;

    for (int i = 1; i < 10; i++)
    {
        count[i] += count[i - 1];
        countcmp++;
    }
    countcmp++;

    for (int i = n - 1; i >= 0; i--)
    {
        countcmp++;
        int digit = (a[i] / exp) % 10;
        output[--count[digit]] = a[i];
        countcmp++;
    }
    countcmp++;

    for (int i = 0; i < n; i++)
    {
        a[i] = output[i];
        countcmp++;
    }
    countcmp++;

    delete[] output;
}
void radix_Sort(int* a, int n, long long& count)
{
    int maxVal = getMax(a, n, count);

    for (int exp = 1; maxVal / exp > 0; exp *= 10)
    {
        count++;
        countingSort_Digit(a, n, exp, count);
    }
}


void flashSort(int* a, int n, long long& count) {
    int minVal = a[0], maxVal = a[0];
    count += 2;

    for (int i = 1; i < n; i++) {
        count++;
        if (a[i] < minVal) {
            minVal = a[i];
            count++;
        }
        if (a[i] > maxVal) {
            maxVal = a[i];
            count++;
        }
    }
    count++;

    if (minVal == maxVal) {
        count++;
        return;
    }

    int bucketCount = int(0.1 * n);
    count++;

    if (bucketCount <= 1) {
        bucketCount = 2;
        count++;
    }

    int* bucket = new int[bucketCount]();
    for (int i = 0; i < n; i++) {
        count++;
        int i2 = int((bucketCount - 1) * (a[i] - minVal) / (maxVal - minVal));
        count++;
        bucket[i2]++;
    }
    count++;

    for (int i = 1; i < bucketCount; i++) {
        count++;
        bucket[i] += bucket[i - 1];
        count++;
    }
    count++;

    int* temp = new int[n];
    for (int i = n - 1; i >= 0; i--) {
        count++;
        int i2 = int((bucketCount - 1) * (a[i] - minVal) / (maxVal - minVal));
        count++;
        int pos = --bucket[i2];
        count++;
        temp[pos] = a[i];
        count++;
    }
    count++;

    for (int i = 0; i < n; i++) {
        count++;
        a[i] = temp[i];
        count++;
    }
    count++;

    for (int i = 0; i < bucketCount; i++) {
        int start = (i == 0) ? 0 : bucket[i - 1];
        int end = bucket[i];
        count += 2;
        if (end - start > 1) {
            count++;
            insertion_Sort(a + start, end - start, count);
        }
    }
    count++;

    delete[] bucket;
    delete[] temp;
}

void writeData(const char* filepath, int* a, int n)
{
    ofstream fout(filepath);
    if (!fout)
    {
        cout << "Khong the mo file\n";
        return;
    }
    fout << n << endl;
    for (int i = 0; i < n; i++)
    {
        fout << a[i] << "\t";
    }
    fout << endl;
    fout.close();
}
void readData(const char* filepath, int*& a, int& n)
{
    ifstream fin(filepath);
    if (!fin)
    {
        cout << "Khong the mo file\n";
        return;
    }
    fin >> n;
    a = new int[n];
    for (int i = 0; i < n; i++)
    {
        fin >> a[i];
    }
    fin.close();
}
