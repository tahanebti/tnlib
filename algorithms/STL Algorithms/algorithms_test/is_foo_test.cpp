std::vector<int> numbers = {1, 3, 5, 7, 2, 4, 6, 8, 9, 10};

    // is_sorted - checks if container is sorted or not 
    // More @ https://e...content-available-to-author-only...e.com/w/cpp/algorithm/is_sorted
    bool is_sorted =  std::is_sorted(numbers.begin(), numbers.end()); 
    std::cout << "Is sorted?                " << is_sorted << std::endl;

    std::sort(numbers.begin(), numbers.end());
    is_sorted = std::is_sorted(numbers.begin(), numbers.end());
    std::cout << "Is sorted?                " << is_sorted << std::endl;

    // is_heap - checks if container is a heap (BFS of Heap)
    // More @ https://e...content-available-to-author-only...e.com/w/cpp/algorithm/is_heap
    bool is_heap = std::is_heap(numbers.begin(), numbers.end());
    std::cout << "Is heap?                  " << is_heap << std::endl;

    std::make_heap(numbers.begin(), numbers.end());
    is_heap = std::is_heap(numbers.begin(), numbers.end());
    std::cout << "Is heap?                  " << is_heap << std::endl;

    // is_partitioned - returns true if all elements satisfy the predicate
    // More @ https://e...content-available-to-author-only...e.com/w/cpp/algorithm/is_partitioned
    bool is_partitioned = std::is_partitioned(numbers.begin(), numbers.end(), [](int i){    return i > 0;   });
    std::cout << "Predicate: is positive?   " << is_partitioned << std::endl;