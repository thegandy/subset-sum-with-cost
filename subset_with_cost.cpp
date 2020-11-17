#include <iostream>
#include <vector>
#include <iterator>

struct node {
    unsigned value;
    unsigned cost;
};

void backtrace(unsigned** matrix, std::vector<node>& node_vector, int i, unsigned sum, std::vector<node>& result)
{
    if (i == 0 && sum != 0 && matrix[0][sum] != (unsigned)-1) {
        result.push_back(node_vector[i]);
        node_vector[i].cost++;
        return;
    }

    if (sum == 0) {
        return;
    }

    bool go_up = (matrix[i - 1][sum] != (unsigned)-1) ? (matrix[i][sum] == matrix[i - 1][sum]) : false;

    if (go_up) {
        backtrace(matrix, node_vector, i - 1, sum, result);
    } else {
        result.push_back(node_vector[i]);
        node_vector[i].cost++;
        backtrace(matrix, node_vector, i - 1, sum - node_vector[i].value, result);
    }
}

std::vector<node> do_the_algorithm(std::vector<node>& node_vector, unsigned sum)
{
    int n = node_vector.size();

    if (n == 0) {
        return {};
    }

    unsigned** matrix = new unsigned*[n];

    for (auto i = 0; i < n; i++) {
        matrix[i] = new unsigned[n + 1];
        matrix[i][0] = node_vector[i].cost;
        for (uint32_t j = 1; j < sum + 1; j++) {
            matrix[i][j] = (unsigned)-1;
        }
    }

    if (node_vector[0].value <= sum) {
        matrix[0][node_vector[0].value] = node_vector[0].cost;
    }

    for (auto i = 1; i < n; i++) {
        for (uint32_t j = 1; j < sum + 1; j++) {
            if (j == node_vector[i].value) {
                if (matrix[i - 1][j] != (unsigned)-1) {
                    matrix[i][j] = std::min(node_vector[i].cost, matrix[i - 1][j]);
                } else {
                    matrix[i][j] = node_vector[i].cost;
                }
            } else if (node_vector[i].value < j) {
                if (matrix[i - 1][j] != (unsigned)-1 && matrix[i - 1][j - node_vector[i].value] != (unsigned)-1) {
                    matrix[i][j] = std::min(matrix[i - 1][j - node_vector[i].value] + node_vector[i].cost, matrix[i - 1][j]);
                } else if (matrix[i - 1][j] != (unsigned)-1) {
                    matrix[i][j] = matrix[i - 1][j];
                } else if (matrix[i - 1][j - node_vector[i].value] != (unsigned)-1) {
                    matrix[i][j] = matrix[i - 1][j - node_vector[i].value] + node_vector[i].cost;
                } else {
                    matrix[i][j] = (unsigned)-1;
                }
            } else {
                matrix[i][j] = matrix[i - 1][j];
            }
        }
    }

    if (matrix[n - 1][sum] == (unsigned)-1) {
        for (int i = sum; i >= 0; i--) {
            if (matrix[n - 1][i] != (unsigned)-1) {
                sum = i;
                break;
            }
        }
    }

    std::vector<node> results;
    backtrace(matrix, node_vector, n - 1, sum, results);

    return results;
}

void print_vec(const std::vector<node>& node_vector)
{
    for (auto node : node_vector) {
        std::cout << "[" << node.value << ", " << node.cost << "] ";
    }
    std::cout << std::endl;
}

int main()
{
    std::vector<node> node_vector = {{1, 0}, {1, 0}, {2, 0}, {3, 0}};
	unsigned sum = 5;
	std::vector<node> results = do_the_algorithm(node_vector, sum);
	print_vec(results);
	print_vec(node_vector);
	
	return 0;
}