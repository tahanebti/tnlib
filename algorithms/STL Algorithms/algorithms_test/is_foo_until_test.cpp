    std::vector<int> numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    std::cout << "Current State     ";
    for(auto& i : numbers)    std::cout << i << " ";    
    std::cout << std::endl;  

    // is_sorted_until
    // More @ https://e...content-available-to-author-only...e.com/w/cpp/algorithm/is_sorted_until
    auto sorted = std::is_sorted_until(numbers.begin(), numbers.end());
    if(sorted != numbers.end()) std::cout << "Is sorted until " << *sorted << std::endl;
    else                        std::cout << "Is sorted until the end" << std::endl;

    // is_heap_until
    // More @ https://e...content-available-to-author-only...e.com/w/cpp/algorithm/is_heap_until
    auto heap = std::is_heap_until(numbers.begin(), numbers.end());
    if(heap != numbers.end())   std::cout << "Is heap until " << *heap << std::endl;
    else                        std::cout << "Is heap until the end" << std::endl;