   std::vector<int> numbers = {1, 2, 3, 4, 5, 6, 7, 9, 10};

    std::cout << "Current State     ";
    for(auto& i : numbers)    std::cout << i << " ";    
    std::cout << std::endl;    

    // Partition - reorder the input so that elements satisfying the predicate are clustered at the beginning
    // More @ https://e...content-available-to-author-only...e.com/w/cpp/algorithm/partition
    auto it = std::partition(numbers.begin(), numbers.end(), [](int i){return i % 2 == 0;});

    std::cout << "After partition   ";
    for(auto& i : numbers)    std::cout << i << " ";    std::cout << std::endl;
    // Returned iterator points to first element that doesn't satisfy the predicate
    std::cout << "Returned iterator " << *it << std::endl;
    
    // Parititon point - return pointer to first element that doesn't satisfy the predicate partition point
    // This function doesn't modity the elements, only locates the pointer
    // More @ https://e...content-available-to-author-only...e.com/w/cpp/algorithm/partition_point
    auto p = std::partition_point(numbers.begin(), numbers.end(), [](int i){ return i % 2 == 0; });
    std::cout << "Partition pointer " << *p << std::endl;