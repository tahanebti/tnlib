 // std::remove_copy: removes 'value' and copies elements to destination
    // More @ https://e...content-available-to-author-only...e.com/w/cpp/algorithm/remove_copy
    std::vector<int> numbers = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    std::cout << "Current State         ";  
    for(auto& i : numbers)    std::cout << i << " ";    
    std::cout << std::endl;

    std::vector<int> cpy;
    std::remove_copy(numbers.begin(), numbers.end(), std::back_inserter(cpy), 5);

    std::cout << "Current State         ";  
    for(auto& i : cpy)    std::cout << i << " ";    
    std::cout << std::endl;

    // std::unique_copy
    // More @ 

    // std::reverse_copy
    // More @ 

    // std::rotate_copy
    // More @ 

    // std::replace_copy
    // More @ 

    // std::partition_copy
    // More @ 

    // std::partial_sort_copy
    // More @ 