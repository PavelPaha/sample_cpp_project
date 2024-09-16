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