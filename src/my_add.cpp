/**
 * @brief Adds two integers.
 *
 * This function takes two integers and returns their sum.
 *
 * @param a The first integer.
 * @param b The second integer.
 * @return The sum of a and b.
 */

int add(int a, int b){
    return a + b;
}

int slow_add(int a, int b){
    int ans = a;
    for (int j = 0; j < b; ++j){
        ans++;
    }
    return ans;
}