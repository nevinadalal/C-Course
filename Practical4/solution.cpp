#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;

double *read_poly(size_t &size);
int find_degree(const double *const array_ptr, size_t size);
void print_poly(const double *const array_ptr, size_t size);
double evaluate_poly(const double *const coefficients, size_t size, double x);
double *sum_poly(const double *const ptr1, size_t size1, 
                 const double *const ptr2, size_t size2, size_t &degree);
double *multiply_poly(const double *const ptr1, size_t size1, 
                      const double *const ptr2, size_t size2, size_t &degree);

int main() {
    double *arr_ptr {nullptr};
    size_t size {};  // The number of coefficients in a polynomial
    arr_ptr = read_poly(size);
    print_poly(arr_ptr, size);
    cout << "=========================================\n\n";

    // Question 1
    double x {};
    cout << "At which point to evaluate the polynomial? ";
    cin >> x;
    cout<< "The result is " << evaluate_poly(arr_ptr, size, x) << endl;
    cout << "=========================================\n\n";

    // Question 2
    double *arr_ptr2 {nullptr};
    size_t size2 {};
    arr_ptr2 = read_poly(size2);
    print_poly(arr_ptr2, size2);
    cout << "=========================================\n\n";

    size_t degree_sum {};
    double *sum_poly_ptr {nullptr};
    sum_poly_ptr = sum_poly(arr_ptr, size, arr_ptr2, size2, degree_sum);
    cout << "The degree of the sum polynomial is " << degree_sum << endl;
    print_poly(sum_poly_ptr, degree_sum + 1);
    delete [] sum_poly_ptr;
    sum_poly_ptr = nullptr;
    cout << "=========================================\n\n";

    // Question 3
    size_t degree_product {};
    double *prod_poly_ptr {nullptr};
    prod_poly_ptr = multiply_poly(arr_ptr, size, arr_ptr2, size2, degree_product);
    cout << "The degree of the product polynomial is " << degree_product << endl;
    print_poly(prod_poly_ptr, degree_product + 1);
    delete [] prod_poly_ptr;
    prod_poly_ptr = nullptr;
    delete [] arr_ptr;
    arr_ptr = nullptr;
    delete [] arr_ptr2;
    arr_ptr2 = nullptr;

    return 0;
}

/*******************************************************************
This function expects:
    size - the size of an array of doubles. This argument is passed
           by reference and will be changed to the array size the
           user wants to have.
    The function reads doubles from the keyboard, dynamically
    creates an array in the heap consisting of those read elements, 
    and returns a pointer to the created array.
********************************************************************/
double *read_poly(size_t &size)
{
    long int degree {};
    do {
        cout << "Enter the degree of the polynomial: ";
        cin >> degree;
        if (degree < 0)
            cout << "The degree of the polynomial can't be negative.\n";
    } while (degree < 0);
    size = degree + 1; // To include the x^0

    double *array_ptr {nullptr};
    array_ptr = new double[size] {};
    for (size_t i{}; i<size; i++) {
        cout << "Coefficient of degree " << i << ": ";
        cin >> array_ptr[i];
    }
    return array_ptr;
}

/*******************************************************************
This function expects:
    array_ptr - a pointer to an array of doubles
    size - the number of doubles in the array
    The function returns the degree of the polynomial whose coefficients 
    are stored in the array to which array_ptr points.
********************************************************************/
int find_degree(const double *const array_ptr, size_t size)
{
    size_t highest_degree_idx {size};
    do {
        highest_degree_idx--;
    } while (array_ptr[highest_degree_idx] == 0 && highest_degree_idx > 0);
    return highest_degree_idx;
}

/*******************************************************************
This function expects:
    array_ptr - a pointer to an array of doubles
    size - the number of doubles in the array
    The function prints the polynomial whose coefficients are
    stored in the array to which array_ptr points.
********************************************************************/
void print_poly(const double *const array_ptr, size_t size)
{
    size_t highest_degree_idx {};
    highest_degree_idx = find_degree(array_ptr, size);

    cout << array_ptr[0];
    if (highest_degree_idx > 0) {
        cout << " + ";
        for (size_t i {1}; i < highest_degree_idx; i++) {
            if (array_ptr[i] != 0)
                cout << array_ptr[i] << "*x^" << i << " + ";
        }
        cout << array_ptr[highest_degree_idx] << "*x^" << highest_degree_idx;
    }
    cout << endl;
}

/*******************************************************************
This function expects:
    coefficients - a pointer to an array of doubles containing the
                   coefficients of a polynomial
    size - the number of doubles in the array
    x - the point at which the polynomial is evaluated
    The function returns the value of the polynomial at x.
********************************************************************/
double evaluate_poly(const double *const coefficients, size_t size, double x)
{
    double cumulative_sum {};
    double current_power_x = {1};
    for (size_t i{}; i < size; i++) {
        cumulative_sum += coefficients[i] * current_power_x;
        current_power_x *= x;
    }
    return cumulative_sum;
}

/*******************************************************************
This function expects:
    ptr1 - a pointer to the first array containing the coefficients of a polynomial
    size1 - size of the first array
    ptr2 - a pointer to the second array containing the coefficients of a polynomial
    size2 - size of the second array
    degree - passed-by-reference variable at which this function will store the 
             degree of the resulting polynomial (its size - 1)
    The function dynamically creates an array containing the coefficients
    of the sum of the two polynomials and returns a pointer to the array.
    Also, the function modifies the degree, which will be changed to the degree 
    of the sum of the polynomials (the number of coefficients - 1).
********************************************************************/
double *sum_poly(const double *const ptr1, size_t size1, const double *const ptr2, size_t size2, size_t &degree)
{
    size_t max_size {};
    size_t min_size {};
    const double *longer_array {nullptr};
    if (size1 >= size2) {
        max_size = size1;
        min_size = size2;
        longer_array = ptr1;
    }
    else {
        max_size = size2;
        min_size = size1;
        longer_array = ptr2;
    }

    double *result {nullptr};
    result = new double[max_size] {};
    for (size_t i{}; i < min_size; i++)
        result[i] = ptr1[i] + ptr2[i];
    for (size_t i{min_size}; i < max_size; i++)
        result[i] = longer_array[i];
    degree = find_degree(result, max_size);
    return result;
}

/*******************************************************************
This function expects:
    ptr1 - a pointer to the first array containing the coefficients of a polynomial
    size1 - size of the first array
    ptr2 - a pointer to the second array containing the coefficients of a polynomial
    size2 - size of the second array
    degree - passed-by-reference variable at which this function will store the 
             degree of the resulting polynomial (its size - 1)
    The function dynamically creates an array containing the coefficients
    of the product of the two polynomials and returns a pointer to the array.
    Also, the function modifies the degree, which will be changed to the degree 
    of the product of the polynomials (the number of coefficients - 1).
********************************************************************/
double *multiply_poly(const double *const ptr1, size_t size1, const double *const ptr2, size_t size2, size_t &degree)
{
    size_t degree1 {}, degree2 {};
    degree1 = find_degree(ptr1, size1);
    degree2 = find_degree(ptr2, size2);
    degree = degree1 + degree2;

    size_t product_array_size {degree + 1};
    double *result {nullptr};
    result = new double[product_array_size] {};
    for (size_t i{}; i<=degree1; i++) {
        if (ptr1[i] != 0) {   // Saving (degree2 + 1) unnecessary calculations
            for (size_t j{}; j<=degree2; j++)
                result[i + j] += ptr1[i] * ptr2[j];
        }
    }
    return result;
}