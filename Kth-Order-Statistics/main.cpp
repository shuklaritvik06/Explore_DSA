#include <iostream>
#include <vector>

class KthOrderStatistics {
private:
    std::vector<int> sequence;

public:
    KthOrderStatistics() { sequence.resize(0); }
    ~KthOrderStatistics() { sequence.clear(); };
    int partition(int low, int high) {
        int pivot = sequence[low];
        int i = low + 1;
        int j = high;
        while (true) {
            while (i <= j && sequence[i] <= pivot) i++;
            while (i <= j && sequence[j] >= pivot) j--;
            if (i <= j)
                std::swap(sequence[i], sequence[j]);
            else
                break;
        }
        std::swap(sequence[low], sequence[j]);
        return j;
    }

    int medianOfMedians(int low, int high) {
        std::vector<int> medians;
        int medians_size = medians.size();

        for (int i = low; i <= high; i += 5) {
            int subHigh = std::min(i + 4, high);
            for (int j = i + 1; j <= subHigh; j++) {
                int k = j;
                while (k > i && sequence[k - 1] > sequence[k]) {
                    std::swap(sequence[k], sequence[k - 1]);
                    k--;
                }
            }
            int medianIndex = i + (subHigh - i) / 2;
            medians.push_back(sequence[medianIndex]);
        }

        if (medians_size <= 5) {
            int k = low;
            for (int i = 1; i < medians_size; i++) {
                while (sequence[k] < medians[i]) k++;
            }
            return k;
        } else {
            return medianOfMedians(0, medians_size - 1);
        }
    }

    int quickSelect(int low, int high, int k) {
        int pivotPos = partition(low, high);

        if (pivotPos == k - 1)
            return sequence[pivotPos];
        else if (pivotPos > k - 1)
            return quickSelect(low, pivotPos - 1, k);
        else
            return quickSelect(pivotPos + 1, high, k);
    }

    void series(int number_of_terms, int first_term, int second_term) {
        sequence.resize(number_of_terms);
        sequence.at(0) = first_term;
        sequence.at(1) = second_term;
        for (int i = 2; i < number_of_terms; ++i) {
            sequence[i] =
                    ((sequence.at(i - 1) * 123) + sequence.at(i - 2) * 45) % (10004321);
        }
    }
};

int main() {
    KthOrderStatistics Kthorder;
    int n, k;
    int A0, A1;
    std::cin >> n >> k >> A0 >> A1;

    Kthorder.series(n, A0, A1);
    std::cout << Kthorder.quickSelect(0, n - 1, k);
    return 0;
}
